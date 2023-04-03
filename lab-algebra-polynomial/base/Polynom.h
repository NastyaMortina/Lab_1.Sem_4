#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "List.h"
const int DEG_MAX = 10;

struct Monom
{
	double koef;
	int deg;
	string name;
	Monom(double _k = 1, int _d = 0)
	{
		koef = _k;
		deg = _d;
	}
	Monom(double _k, int _d, string _name)
	{
		koef = _k;
		deg = _d;
		name = _name;
	}
	Monom operator +(const Monom& mn)
	{
		if (this->deg != mn.deg)
			throw "incorrect addition";
		Monom tmp;
		tmp.koef = this->koef + mn.koef;
		tmp.deg = this->deg;
		tmp.name = this->name;
		return tmp;
	}
	Monom operator -(const Monom& mn)
	{
		if (this->deg != mn.deg)
			throw "incorrect subtraction";
		Monom tmp;
		tmp.koef = this->koef - mn.koef;
		tmp.deg = this->deg;
		tmp.name = this->name;
		return tmp;
	}
	Monom operator *(const Monom& mn)
	{
		Monom tmp;
		tmp.koef = this->koef * mn.koef;
		tmp.deg = this->deg + mn.deg;
		int a = tmp.deg / 100, b = (tmp.deg / 10) % 10, c = tmp.deg % 10;
		string _a, _b, _c;
		_a = to_string(a);
		_b = to_string(b);
		_c = to_string(c);
		string _name = "";
		if ((a != 0) && (a != 1))
			_name = _name + "x" + _a;
		if ((b != 0) && (b != 1))
			_name = _name + "y" + _b;
		if ((c != 0) && (c != 1))
			_name = _name + "z" + _c;
		if (a == 1)
			_name = _name + "x";
		if (b == 1)
			_name = _name + "y";
		if (c == 1)
			_name = _name + "z";
		tmp.name = _name;
		return tmp;
	}
	int getDegX()
	{
		return deg / 100;
	}
	int getDegY()
	{
		return (deg / 10) % 10;
	}
	int getDegZ()
	{
		return deg % 10;
	}
};

class Polynom
{
private:
	string prefix;
	List<Monom> polinom;

	bool IsSign(char op);
	bool IsVariable(char op);
	int GetDegree(char p);

public:
	Polynom(List<Monom> _polinom) {
		this->polinom = _polinom;
	}
	Polynom(string _str = "") :prefix(_str) {}
	Polynom(const Polynom& pl);
	void Convert();
	int CalculateInPoint(int _x, int _y, int _z);
	Polynom operator+(Polynom& pl);
	Polynom operator-(Polynom& pl);
	Polynom operator*(Polynom& pl);
	Polynom& operator*(const double& scal)
	{
		auto it = this->polinom.Begin();
		for (auto it = this->polinom.Begin(); it != this->polinom.End(); ++it)
		{
			it->data.koef = it->data.koef * (scal);
		}
		return *this;
	}
	Polynom& operator=(const Polynom& pl);
	//Polynom& operator=(Polynom other);
	friend ostream& operator<<(ostream& os, Polynom& pl);
	friend istream& operator>>(istream& is, Polynom& pl);
	bool operator == (const Polynom& pl)const;
	//void SaveInFile(Polynom& polinom1, Polynom& polinom2, Polynom& multiplication, Polynom& subtraction, Polynom& addition);
	//void SaveInFile(Polynom& polinom1, Polynom& polinom2, Polynom& multiplication, int calMultiplication,
	//Polynom& subtraction, int calSubtraction, Polynom& addition, int calAdditio, int _x, int _y, int _z);
	//void ReadFile();
	Polynom Sort();
	string GetPrefix();
	Polynom& IntegrateDX(Polynom& p1);
	Polynom& IntegrateDY(Polynom& p1);
	Polynom& IntegrateDZ(Polynom& p1);
	string nameNewMonom(int _deg);
	Polynom& DerivativeDX(Polynom& p1);
	Polynom& DerivativeDY(Polynom& p1);
	Polynom& DerivativeDZ(Polynom& p1);
	string CreateString();
};
#endif