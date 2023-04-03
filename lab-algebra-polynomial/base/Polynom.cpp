#include "polynom.h"
#include "windows.h"

bool Polynom::IsSign(char op)
{
	if (op == '+' || op == '-')
		return true;
	else return false;
}

bool Polynom::IsVariable(char op)
{
	if (op == 'x' || op == 'y' | op == 'z')
		return true;
	else return false;
}

int Polynom::GetDegree(char p)
{
	if (int(p) > 49 && int(p) < 58) 
		return int(p - 48);
	else return 1;
}

Polynom::Polynom(const Polynom& pl)
{
	this->prefix = pl.prefix;
	this->polinom = pl.polinom;
}

void Polynom::Convert()
{
	cout << "Convert" << endl;
	int begin = 0;
	bool sign = true;
	Monom monom;
	string num;
	List<Monom>::iterator it;
	for (int i = 0; i < prefix.size(); i++)
	{
		monom = {};
		if (prefix[i] == '+')
		{
			sign = true;
			i++;
		}
		else if (prefix[i] == '-')
		{
			sign = false;
			i++;
		}
		if (!IsSign(prefix[i]) && !IsVariable(prefix[i]))
		{
			while (!IsVariable(prefix[i]) && i != prefix.size() && !IsSign(prefix[i]))
			{
				num += prefix[i];
				i++;
			}
			monom.koef = atof(num.c_str());
			num = "";
		}
		begin = i;
		if (IsVariable(prefix[i]))
		{
			int x = 0, y = 0, z = 0, sum;
			while (!IsSign(prefix[i]) && i != prefix.size())
			{
				switch (prefix[i])
				{
				case 'x':
				{
					x = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				case 'y':
				{
					y = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				case 'z':
				{
					z = GetDegree(prefix[i + 1]);
					i++;
					break;
				}
				default:
					i++;
				}
			}
			i--;
			sum = x * 100 + y * 10 + z;
			monom.name = prefix.substr(begin, i - begin + 1);
			monom.deg = sum;
			if (!sign)
				monom.koef = monom.koef * (-1);
		}
		if (polinom.IsEmpty())
		{
			polinom.PushBack(monom);
			continue;
		}
		for (it = polinom.Begin(); it != polinom.End(); ++it)
		{
			if (monom.deg == it->data.deg)
			{
				it->data.koef = it->data.koef + monom.koef;
				if (it->data.koef == 0)
					polinom.Erase(it);
				break;
			}
			if (monom.deg > it->data.deg)
			{
				polinom.Insert(it, monom);
				break;
			}
		}
		if (it == polinom.End())
			polinom.PushBack(monom);
	}
}

int Polynom::CalculateInPoint(int _x, int _y, int _z)
{
	int result = 0;
	for (auto it = polinom.Begin(); it != polinom.End(); ++it)
	{
		int x = it->data.deg / 100, y = (it->data.deg / 10) % 10, z = it->data.deg % 10;
		result += (pow(_x, x) * pow(_y, y) * pow(_z, z)) * it->data.koef;
	}
	return result;
}

Polynom Polynom::Sort()
{
	if (this->polinom.IsEmpty())
		throw "Polinom is empty";
	Polynom res;
	List<Monom>::iterator right, left, max;
	for (right = this->polinom.Begin(); right != this->polinom.End(); ++right)
	{
		max->data = right->data;
		for (left = right; left != this->polinom.End(); ++left)
		{
			if (right->data.deg < left->data.deg)
			{
				max->data = left->data;
				left->data = right->data;
				right->data = max->data;
			}
		}
	}
	return *this;
}

Polynom Polynom::operator+(Polynom& pl)
{
	if (this->polinom.IsEmpty() || pl.polinom.IsEmpty())
		throw "Polinom is empty";
	Polynom result;
	List<Monom>::iterator right, left;
	bool check = false;
	for (right = pl.polinom.Begin(); right != pl.polinom.End(); ++right)
	{
		check = false;
		for (left = this->polinom.Begin(); left != this->polinom.End(); ++left)
			if (right->data.deg == left->data.deg)
			{
				if ((left->data.koef + right->data.koef) != 0)
					result.polinom.PushBack(*(left)+*(right));
				check = true;
			}
		if (check == false)
			result.polinom.PushBack(*right);
	}
	check = false;
	for (left = this->polinom.Begin(); left != this->polinom.End(); ++left)
	{
		check = false;
		right = pl.polinom.Begin();
		for (right = pl.polinom.Begin(); right != pl.polinom.End(); ++right)
			if (left->data.deg == right->data.deg)
				check = true;
		if (check == false)
			result.polinom.PushBack(*left);
	}
	if (result.polinom.IsEmpty())
	{
		right = pl.polinom.Begin();
		right->data.koef = 0;
		right->data.name = "";
		right->data.deg = 0;
		result.polinom.PushBack(*right);
	}
	return result.Sort();
}

Polynom Polynom::operator-(Polynom& pl)
{
	if (this->polinom.IsEmpty() || pl.polinom.IsEmpty())
		throw "Polinom is empty";
	Polynom result;
	List<Monom>::iterator right, left;
	bool check = false;
	for (right = pl.polinom.Begin(); right != pl.polinom.End(); ++right)
	{
		check = false;
		for (left = this->polinom.Begin(); left != this->polinom.End(); ++left)
			if (right->data.deg == left->data.deg)
			{
				if ((left->data.koef - right->data.koef) != 0)
				{
					result.polinom.PushBack(*(left)-*(right));
				}
				check = true;
			}
		if (check == false)
		{
			int koef = right->data.koef;
			right->data.koef = (-1) * right->data.koef;
			result.polinom.PushBack(*right);
			right->data.koef = koef;
		}
	}
	check = false;
	for (left = this->polinom.Begin(); left != this->polinom.End(); ++left)
	{
		check = false;
		right = pl.polinom.Begin();
		for (right = pl.polinom.Begin(); right != pl.polinom.End(); ++right)
			if (left->data.deg == right->data.deg)
				check = true;
		if (check == false)
			result.polinom.PushBack(*left);
	}
	return result.Sort();
}

Polynom Polynom::operator*(Polynom& pl)
{
	if (this->polinom.IsEmpty() || pl.polinom.IsEmpty())
		throw "Polinom is empty";
	Polynom result;
	List<Monom>::iterator right, left;
	for (right = this->polinom.Begin(); right != this->polinom.End();)
	{
		for (left = pl.polinom.Begin(); left != this->polinom.End();)
		{
			if ((right->data.koef * left->data.koef) != 0)
				result.polinom.PushBack((*(right)) * (*(left)));
			++left;
		}
		++right;
	}
	while (left != pl.polinom.End())
	{
		result.polinom.PushBack(*left);
		++left;
	}
	return result.Sort();
}

Polynom& Polynom::operator=(const Polynom& pl)
{
	this->polinom = pl.polinom;
	this->prefix = pl.prefix;
	return *this;
}


bool Polynom::operator==(const Polynom& pl)const
{
	if (this->prefix == pl.prefix)
		return true;
	else return false;
}

ostream& operator<<(ostream& os, Polynom& pl)
{
	if (pl.polinom.IsEmpty()) {
		os << pl.prefix;
	}
	else
	{
		for (auto it = pl.polinom.Begin(); it != pl.polinom.End(); ++it)
		{
			if (it->data.deg != 0)
			{
				if (it != pl.polinom.Begin() && it->data.koef > 0)
					os << '+';
				if ((it->data.koef != 1) && (it->data.koef != -1))
				{
					os << it->data.koef;
					os << it->data.name;
				}
				if (it->data.koef == 1)
					os << it->data.name;
				if (it->data.koef == -1)
				{
					os << '-';
					os << it->data.name;
				}
			}
			else
			{
				if (it != pl.polinom.Begin() && it->data.koef > 0)
					os << '+';
				os << it->data.koef;
			}
		}
	}
	return os;
}

istream& operator>>(istream& is, Polynom& pl)
{
	for (auto it = pl.polinom.Begin(); it != pl.polinom.End(); ++it)
	{
		if ((it->data.koef != 1) && (it->data.name != "\0"))
		{
			is >> it->data.koef;
			is >> it->data.name;
		}
		if (it->data.name == "\0")
			is >> it->data.koef;
		if (it->data.koef == 1)
			is >> it->data.name;
	}
	return is;
}

//void Polynom::SaveInFile(Polynom& polinom1, Polynom& polinom2, Polynom& multiplication, Polynom& subtraction, Polynom& addition)
//{
//	ofstream out;
//	out.open("Polinom.txt");
//	if (out.is_open())
//	{
//		out << "Исходные полиномы:" << endl;
//		out << "F = " << polinom1 << endl;
//		out << "G = " << polinom2 << endl;
//		out << "Результаты исчислений:" << endl;
//		out << "F*G = " << multiplication << endl;
//		out << "F-G = " << subtraction << endl;
//		out << "F+G = " << addition << endl;
//	}
//	out.close();
//}

//void Polynom::SaveInFile(Polynom& polinom1, Polynom& polinom2, Polynom& multiplication,
//	int calMultiplication, Polynom& subtraction, int calSubtraction, Polynom& addition, int calAddition, int _x, int _y, int _z)
//{
//	ofstream out;
//	out.open("Polinom.txt");
//	if (out.is_open())
//	{
//		out << "Исходные полиномы:" << endl;
//		out << "F = " << polinom1 << endl;
//		out << "G = " << polinom2 << endl;
//		out << "Результаты исчислений:" << endl;
//		out << "F*G = " << multiplication << endl;
//		out << "F*G(" << _x << "," << _y << "," << _z << ") = " << calMultiplication << endl;
//		out << "F-G = " << subtraction << endl;
//		out << "F-G(" << _x << "," << _y << "," << _z << ") = " << calSubtraction << endl;
//		out << "F+G = " << addition << endl;
//		out << "F+G(" << _x << "," << _y << "," << _z << ") = " << calAddition << endl;
//	}
//	out.close();
//}

//void Polynom::ReadFile()
//{
//	string line;
//	ifstream in("Polinom.txt"); // окрываем файл для чтения
//	if (in.is_open())
//		while (getline(in, line))
//			cout << line << endl;
//	in.close();                // закрываем файл
//}

string Polynom::GetPrefix()
{
	return this->prefix;
}

Polynom& Polynom::IntegrateDX(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		cout << "Попали в IntegrateDX текущий result " << endl;
		int degMonom = it->data.deg + 100;
		int newDegX = degMonom / 100;
		double koefPolinom = it->data.koef;
		double newKoefPolinom = koefPolinom / newDegX;
		string nameMonom = p1.nameNewMonom(degMonom);
		cout << degMonom << " " << newKoefPolinom << endl;
		Monom newMonom(newKoefPolinom, degMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

Polynom& Polynom::IntegrateDY(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		cout << "Попали в IntegrateDY текущий result " << endl;
		int degMonom = it->data.deg + 10;
		int newDegY = (degMonom / 10) % 10;
		double koefPolinom = it->data.koef;
		double newKoefPolinom = koefPolinom / newDegY;
		string nameMonom = p1.nameNewMonom(degMonom);
		cout << degMonom << " " << newKoefPolinom << endl;
		Monom newMonom(newKoefPolinom, degMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

Polynom& Polynom::IntegrateDZ(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		cout << "Попали в IntegrateDZ текущий result " << endl;
		int degMonom = it->data.deg + 1;
		int newDegZ = degMonom % 10;
		double koefPolinom = it->data.koef;
		double newKoefPolinom = koefPolinom / newDegZ;
		string nameMonom = p1.nameNewMonom(degMonom);
		cout << degMonom << " " << newKoefPolinom << endl;
		Monom newMonom(newKoefPolinom, degMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

string Polynom::nameNewMonom(int _deg)
{
	int a = _deg / 100;
	int b = (_deg / 10) % 10;
	int c = _deg % 10;
	string _name = "";
	if ((a != 0) && (a != 1))
		_name = _name + "x" + to_string(a);
	if (a == 1)
		_name = _name + "x";
	if ((b != 0) && (b != 1))
		_name = _name + "y" + to_string(b);
	if (b == 1)
		_name = _name + "y";
	if ((c != 0) && (c != 1))
		_name = _name + "z" + to_string(c);
	if (c == 1)
		_name = _name + "z";
	return _name;
}

Polynom& Polynom::DerivativeDX(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		cout << "Попали в DerivativeDX текущий result " << endl;

		double newKoef = it->data.koef * (it->data.deg / 100);
		int newDegMonom = it->data.deg - 100; 

		string nameMonom = p1.nameNewMonom(newDegMonom);
		cout << newDegMonom << " " << newKoef << endl;
		Monom newMonom(newKoef, newDegMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

Polynom& Polynom::DerivativeDY(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		cout << "Попали в DerivativeDY текущий result " << endl;

		double newKoef = it->data.koef * ((it->data.deg / 10) % 10);
		int newDegMonom = it->data.deg - 10; 

		string nameMonom = p1.nameNewMonom(newDegMonom);
		cout << newDegMonom << " " << newKoef << endl;
		Monom newMonom(newKoef, newDegMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

Polynom& Polynom::DerivativeDZ(Polynom& p1)
{
	List <Monom> result;
	for (auto it = p1.polinom.Begin(); it != p1.polinom.End(); ++it)
	{
		double newKoef = it->data.koef * (it->data.deg % 10);
		int newDegMonom = it->data.deg - 1; 

		string nameMonom = p1.nameNewMonom(newDegMonom);
		cout << newDegMonom << " " << newKoef << endl;
		Monom newMonom(newKoef, newDegMonom, nameMonom);
		result.PushBack(newMonom);
	}
	this->polinom = result;
	return *this;
}

string Polynom::CreateString()
{
	string Result;
	int powX, powY, powZ;
	double mulMonom;

	auto it = this->polinom.Begin();
	if (it->pNext != nullptr)
	{
		powX = it->data.deg / 100;
		powY = (it->data.deg / 10) % 10;
		powZ = it->data.deg % 10;
		mulMonom = it->data.koef;

		if (mulMonom == -1)
			Result += '-';
		else
			if (mulMonom != 1)
				Result += to_string(mulMonom);

		if (powX)
			if (powX != 1)
				Result = Result + "x" + to_string(powX);
			else
				Result += 'x';

		if (powY)
			if (powY != 1)
				Result = Result + "y" + to_string(powY);
			else
				Result += 'y';

		if (powZ)
			if (powZ != 1)
				Result = Result + "z" + to_string(powZ);
			else
				Result += 'z';

		while (it->pNext != nullptr)
		{
			++it;

			powX = it->data.deg / 100;
			powY = (it->data.deg / 10) % 10;
			powZ = it->data.deg % 10;
			mulMonom = it->data.koef;

			if (mulMonom == -1)
				Result += '-';

			if (mulMonom > 0)
				Result += '+';

			if ((mulMonom != 1) && (mulMonom != -1))
				Result += to_string(mulMonom);

			if (powX)
				if (powX != 1)
					Result = Result + "x" + to_string(powX);
				else
					Result += 'x';

			if (powY)
				if (powY != 1)
					Result = Result + "y" + to_string(powY);
				else
					Result += 'y';

			if (powZ)
				if (powZ != 1)
					Result = Result + "z" + to_string(powZ);
				else
					Result += 'z';
		}
	}

	return Result;
}