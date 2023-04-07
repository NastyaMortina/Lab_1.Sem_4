#include "Interface.h"
#include <iostream>
#include "Polynom.h"
#include <stdlib.h>

void printTableList(const string& str) 
{
	cout << str << endl;
	cout << " 1 - �������� ������� �� �������" << endl;
	cout << " 2 - �������� ������� �� ������" << endl;
	cout << " 3 - ������������� ������� �� �������" << endl;
	cout << " 4 - ���-������" << endl;
	cout << " 5 - ���-������� �� �������" << endl;
	cout << " 6 - ���-������� �� ������" << endl;
}

void Interface::tableSelection()
{
	int code = inputControl(1, 7, printTableList, " ");
	switch (code)
	{
		case 1:
		{
			Base = tables[0];
			tecName = namesOfTables[0];
			break;
		}
		case 2:
		{
			Base = tables[1];
			tecName = namesOfTables[1];
			break;
		}
		case 3:
		{
			Base = tables[2];
			tecName = namesOfTables[2];
			break;
		}
		case 4:
		{
			Base = tables[3];
			tecName = namesOfTables[3];
			break;
		}
		case 5:
		{
			Base = tables[4];
			tecName = namesOfTables[4];
			break;
		}
		case 6:
		{
			Base = tables[5];
			tecName = namesOfTables[5];
			break;
		}
		case 7:
		{
			exitApp();
			break;
		}
	}
}

int Interface::inputControl(int left_board, int right_board, void (*print)(const string&), const string& str)
{
	int number;
	bool flag = false;
	do
	{
		print(str);
		flag = false;
		cin >> number;
		system("cls");
		if ((number > right_board) || (number < left_board))
		{
			cout << "������ �����! ������� ��� ���!" << endl;
			flag = true;
		}
	} while (flag);
	return number;
}

void printPolynomOperation(const string& str)
{
	cout << " 1 - ��������� ������� � �����" << endl;
	cout << " 2 - ���������������� �� X" << endl;
	cout << " 3 - ���������������� �� Y" << endl;
	cout << " 4 - ���������������� �� Z" << endl;
	cout << " 5 - ������������������� �� X" << endl;
	cout << " 6 - ������������������� �� Y" << endl;
	cout << " 7 - ������������������� �� Z" << endl;
	cout << " 8 - �����" << endl;
}

void printMenuList(const string& str)
{
	cout << str << endl;
	cout << " 1 - �������� �������" << endl;
	cout << " 2 - ����� �������� � �������������� �������� ��� ���" << endl;
	cout << " 3 - ������ �������������� ���������" << endl;
	cout << " 4 - ������� ��� ��������" << endl;
	cout << " 5 - ������� �������" << endl;
	cout << " 6 - �������� ������� �� ���������" << endl;
	cout << " 7 - �����" << endl;
}

void Interface::menu()
{
	int code = -1;
	do
	{
		cout << "������� �������: " << tecName << endl;
		string str = "---------------------------����---------------------------\n  ��� ������ ������� ��������������� �������.\n";
		code = inputControl(1, 7, printMenuList, str);
		switch (code) 
		{
			case 1: addPolynom(); break; 
			case 2: searchAndMakeOperations(); break; 
			case 3: calculate(); break; 
			case 4: print(); break; 
			case 5: deleteByKey(); break; 
			case 6: tableSelection(); break; 
			case 7: exitApp(); break; 
		}

	} while (code != 7);
}

void Interface::exitApp()
{
	exit(0);
}

void Interface::countPolynomInPoint(Data data, int x, int y, int z)
{
	int a = -1;
	a = data._polynom.CalculateInPoint(x, y, z);
	cout << "������� � �����: " << a << endl;
}

string Interface::controlPolynom(const string& str)
{
	string res;
	int length = str.length();
	return str;
}

void keyRules()
{
	cout << "������� ����� ����� ��������" << endl;
	cout << "������� ���(����) ����� ������ ���������� �������." << endl;
	cout << "�� ������������ ���������� �����." << endl;
}

void polynomRules()
{
	cout << "������� ����� ��������" << endl;
	cout << "������������ ������� ����������� 9. " << endl;
	cout << "� �������� ���������� ����� ������� ������ x,y,x. " << endl;
}

void Interface::addPolynom()
{
	cout << "----------------------- 1.���������� �������� -----------------------" << endl;
	Data data;
	keyRules(); 
	polynomRules(); 
	try
	{
		cout << "������� ��� ��������: " << endl;
		cin.ignore();
		getline(cin, data.key);
		data.key = controlKey(data.key + " "); //�� �����������, �� � ��� ������� ���������
		cout << "������� ��� �������: " << endl;
		getline(cin, data.polynomString);
		data.polynomString = controlPolynom(data.polynomString);
		Polynom p(data.polynomString);
		data._polynom = p;
		for (int i = 0; i < 6; i++)
			tables[i]->insert(data);
	}
	catch (int code)
	{
		cout << "���-�� ����� �� ���." << endl;
	}
	cout << "��� ������ ������� ����� �������" << endl;
	_getch();
	system("cls"); 
}

void printExit(const string& str)
{
	cout << str << endl;
	cout << " 0 - ���" << endl;
	cout << " 1 - ��" << endl;
}

void Interface::searchAndMakeOperations()
{
	cout << "�������� �������, ������� ������ ������������" << endl;
	tableSelection();
	string key;
	string str = "--------------------2.����� � ��������--------------------";
	Data* data;
	while (1)
	{
		cout << str << endl;
		cout << "������� ���: " << endl;
		cin.ignore();
		getline(cin, key);
		data = Base->find(key);
		system("cls");
		if (data == nullptr) {
			cout << str << endl;
			cout << "������ �������� ���" << endl;
		}
		else {
			int code;
			string temp = str;
			int check;
			temp += "\n��� ��������: " + data->key + "\n��������� �������: " + data->polynomString;
			cout << temp << endl;
			cout << "������ �� �� ���������� �������� ��� ���� ���������?" << endl;
			cout << "������� 1 - �� ��� 0 - ���." << endl;
			cin >> check;
			if (check == 0) {
				system("cls");
				break;
			}
			if (check == 1)
			{
				Polynom polynom(data->polynomString);
				polynom.Convert();
				do {
					code = inputControl(1, 10, printPolynomOperation, " ");
					switch (code)
					{
						case 1:
						{
							int x, y, z;
							cout << "������� �������� �: " << endl;
							cin >> x;
							cout << "������� �������� y: " << endl;
							cin >> y;
							cout << "������� �������� z: " << endl;
							cin >> z;
							cout << "���������� �������." << endl;
							cout << polynom.CalculateInPoint(x, y, z) << endl;
							cout << polynom << endl;
							break;
						}
						case 2:
						{
							Polynom newP;
							newP.IntegrateDX(polynom);
							cout << "�������� �� X " << newP << endl;
							break;
						}
						case 3://Integral(d, y)
						{
							Polynom newP;
							newP.IntegrateDY(polynom);
							cout << "�������� �� Y " << newP << endl;
							break;
						}
						case 4: //Integral(d, z)
						{
							Polynom newP;
							newP.IntegrateDZ(polynom);
							cout << "�������� �� Z : " << newP << endl;
							break;
						}
						case 5:
						{
							Polynom newP;
							newP.DerivativeDX(polynom);
							cout << "����������� �� X: " << newP << endl;
							break;
						}
						case 6:
						{
							Polynom newP;
							newP.DerivativeDY(polynom);
							cout << "����������� �� Y: " << newP << endl;
							break;
						}
						case 7:
						{
							Polynom newP;
							newP.DerivativeDZ(polynom);
							cout << "����������� �� Z: " << newP << endl;
							break;
						}
					}
				} while (code != 8);
			}
		}
		cout << "����������� ���?" << endl;
		int code = inputControl(0, 1, printExit, "");
		if (code == 0) { break; }
		system("cls");
	}
}


string Interface::controlKey(const string& key) {
	string res;
	int count = 0;
	int length = key.length();
	for (int k = 0; k < length; k++) {
		if (key[k] != ' ') { //////// '\n\'
			if (key[k + 1] == ' ') { count++; }
			res += key[k];
			if ((key[k] < 'a') || (key[k] > 'z')) { throw exception(); }
		}
	}
	if (count != 1) { throw exception(); }
	return res;
}

void Interface::print()
{
	cout << "-------------------------4.�����--------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		tables[i]->print();
		cout << endl;
	}
	cout << "��� ������ ������� ����� �������" << endl;
	_getch();
	system("cls");
}

void Interface::deleteByKey()
{
	string key;
	cout << "------------------------5.��������------------------------" << endl;
	keyRules();
	try
	{
		cout << "������� ��� ��������: " << endl;
		cin.ignore();
		getline(cin, key);
		key = controlKey(key + " ");
		for (int i = 0; i < 6; i++)
			tables[i]->deleteByKey(key);
		cout << "�������� ������ �������" << endl;
	}
	catch (int code)
	{
		cout << "���-�� ����� �� ���. �������� �������� � ����� ������ �� ����������." << endl;
	}
	cout << "��� ������ ������� ����� �������" << endl;
	_getch();
	system("cls");
}

void Interface::calculate()
{
	string str = "-----------------------3.����������-----------------------\n�������� �����\n";
	int code = 0;
	string infix;
	calPol();
	system("cls");
}


void Interface::calPol()
{
	bool flag = true;
	string str;
	string key;
	string infix;
	Postfix post;
	while (flag)
	{
		flag = false;
		cout << "�������������� ��������� ������� � ��������� �������: " << endl;
		cout << " <���_��������> = <�������������� ���������>" << endl;
		cout << " ������: f = a + b, ��� f - ����� ��������� �� ���������." << endl;
		cout << "�������������� ��������� ������ ��������� ������ ��������� ��������: +,-,*" << endl;
		cout << "a,b,c,d - ����� ���������, ��������� � �������" << endl;
		cout << "������� �������������� ���������:" << endl;
		try
		{
			cin.clear();
			getline(cin, str);
			if (str == "!") {
				system("cls");
				return;
			}
			if (str.find('=') == string::npos) { throw "������������ ������"; }
			int k;
			for (k = 0; str[k] != '='; k++)
			{
				key += str[k];
			}
			key = controlKey(key + " ");
			int length = str.length();
			k++;
			for (; k < length; k++)
				infix += str[k];
			if (infix.find('/') != string::npos) { throw exception(); }
			Postfix p(infix);
			post = p;
		}
		catch (int i)
		{
			cin.clear();
			cout << "���������� ������ ��� ���" << endl;
			flag = true;
			cin.clear();
		}
		catch (const char* s)
		{
			cin.clear();
			cout << s << endl;
			cout << "���������� ������ ��� ���" << endl;
			flag = true;
			cin.clear();
		}
	}
	post.ToPostfix();
	try
	{
		Data res;
		res._polynom = post.NewPoly(*Base);
		res.key = key;
		res.polynomString = res._polynom.CreateString();
		for (int i = 0; i < 6; i++)
			tables[i]->insert(res);
	}
	catch (int i)
	{
		cout << "���-�� ����� �� ��� " << endl;
	}
	cout << "��� ������ ������� ����� �������" << endl;
	_getch();
	system("cls");
}