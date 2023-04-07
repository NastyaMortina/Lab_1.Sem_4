#include "Interface.h"
#include <iostream>
#include "Polynom.h"
#include <stdlib.h>

void printTableList(const string& str) 
{
	cout << str << endl;
	cout << " 1 - Линейная таблица на массиве" << endl;
	cout << " 2 - Линейная таблица на списке" << endl;
	cout << " 3 - Упорядоченная таблица на массиве" << endl;
	cout << " 4 - Авл-дерево" << endl;
	cout << " 5 - Хеш-таблица на массиве" << endl;
	cout << " 6 - Хеш-таблица на списке" << endl;
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
			cout << "ОШИБКА ВВОДА! ВВЕДИТЕ ЕЩЕ РАЗ!" << endl;
			flag = true;
		}
	} while (flag);
	return number;
}

void printPolynomOperation(const string& str)
{
	cout << " 1 - Посчитать полином в точке" << endl;
	cout << " 2 - Проинтегрировать по X" << endl;
	cout << " 3 - Проинтегрировать по Y" << endl;
	cout << " 4 - Проинтегрировать по Z" << endl;
	cout << " 5 - Продифференцировать по X" << endl;
	cout << " 6 - Продифференцировать по Y" << endl;
	cout << " 7 - Продифференцировать по Z" << endl;
	cout << " 8 - Выход" << endl;
}

void printMenuList(const string& str)
{
	cout << str << endl;
	cout << " 1 - Добавить полином" << endl;
	cout << " 2 - Поиск полинома и арифметические операции над ним" << endl;
	cout << " 3 - Ввести арифметическое выражение" << endl;
	cout << " 4 - Вывести все полиномы" << endl;
	cout << " 5 - Удалить полином" << endl;
	cout << " 6 - Изменить таблицу по умолчанию" << endl;
	cout << " 7 - Выход" << endl;
}

void Interface::menu()
{
	int code = -1;
	do
	{
		cout << "Текущая таблица: " << tecName << endl;
		string str = "---------------------------Меню---------------------------\n  Для выбора введите соответствующую клавишу.\n";
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
	cout << "Подсчет в точке: " << a << endl;
}

string Interface::controlPolynom(const string& str)
{
	string res;
	int length = str.length();
	return str;
}

void keyRules()
{
	cout << "Правила ввода имени полинома" << endl;
	cout << "Вводить имя(ключ) можно только маленькими буквами." << endl;
	cout << "Не использовать построниие знаки." << endl;
}

void polynomRules()
{
	cout << "Правила ввода полинома" << endl;
	cout << "Максимальная степень неизвестных 9. " << endl;
	cout << "В качестве переменных можно вводить только x,y,x. " << endl;
}

void Interface::addPolynom()
{
	cout << "----------------------- 1.Добавление полинома -----------------------" << endl;
	Data data;
	keyRules(); 
	polynomRules(); 
	try
	{
		cout << "Введите имя полинома: " << endl;
		cin.ignore();
		getline(cin, data.key);
		data.key = controlKey(data.key + " "); //не реализовано, но в нем большой потенциал
		cout << "Введите сам полином: " << endl;
		getline(cin, data.polynomString);
		data.polynomString = controlPolynom(data.polynomString);
		Polynom p(data.polynomString);
		data._polynom = p;
		for (int i = 0; i < 6; i++)
			tables[i]->insert(data);
	}
	catch (int code)
	{
		cout << "Что-то пошло не так." << endl;
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls"); 
}

void printExit(const string& str)
{
	cout << str << endl;
	cout << " 0 - Нет" << endl;
	cout << " 1 - Да" << endl;
}

void Interface::searchAndMakeOperations()
{
	cout << "Выберите таблицу, которой хотите пользоваться" << endl;
	tableSelection();
	string key;
	string str = "--------------------2.Поиск и операции--------------------";
	Data* data;
	while (1)
	{
		cout << str << endl;
		cout << "Введите имя: " << endl;
		cin.ignore();
		getline(cin, key);
		data = Base->find(key);
		system("cls");
		if (data == nullptr) {
			cout << str << endl;
			cout << "Такого полинома нет" << endl;
		}
		else {
			int code;
			string temp = str;
			int check;
			temp += "\nИмя полинома: " + data->key + "\nНайденный полином: " + data->polynomString;
			cout << temp << endl;
			cout << "Хотите ли Вы произвести действия над этим полиномом?" << endl;
			cout << "Введите 1 - да или 0 - нет." << endl;
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
							cout << "Введите значение х: " << endl;
							cin >> x;
							cout << "Введите значение y: " << endl;
							cin >> y;
							cout << "Введите значение z: " << endl;
							cin >> z;
							cout << "Происходит подсчет." << endl;
							cout << polynom.CalculateInPoint(x, y, z) << endl;
							cout << polynom << endl;
							break;
						}
						case 2:
						{
							Polynom newP;
							newP.IntegrateDX(polynom);
							cout << "Интеграл по X " << newP << endl;
							break;
						}
						case 3://Integral(d, y)
						{
							Polynom newP;
							newP.IntegrateDY(polynom);
							cout << "Интеграл по Y " << newP << endl;
							break;
						}
						case 4: //Integral(d, z)
						{
							Polynom newP;
							newP.IntegrateDZ(polynom);
							cout << "Интеграл по Z : " << newP << endl;
							break;
						}
						case 5:
						{
							Polynom newP;
							newP.DerivativeDX(polynom);
							cout << "Производная по X: " << newP << endl;
							break;
						}
						case 6:
						{
							Polynom newP;
							newP.DerivativeDY(polynom);
							cout << "Производная по Y: " << newP << endl;
							break;
						}
						case 7:
						{
							Polynom newP;
							newP.DerivativeDZ(polynom);
							cout << "Производная по Z: " << newP << endl;
							break;
						}
					}
				} while (code != 8);
			}
		}
		cout << "Попробовать еще?" << endl;
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
	cout << "-------------------------4.Вывод--------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		tables[i]->print();
		cout << endl;
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::deleteByKey()
{
	string key;
	cout << "------------------------5.Удаление------------------------" << endl;
	keyRules();
	try
	{
		cout << "Введите имя полинома: " << endl;
		cin.ignore();
		getline(cin, key);
		key = controlKey(key + " ");
		for (int i = 0; i < 6; i++)
			tables[i]->deleteByKey(key);
		cout << "Удаление прошло успешно" << endl;
	}
	catch (int code)
	{
		cout << "Что-то пошло не так. Возможно полинома с таким ключом не существует." << endl;
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::calculate()
{
	string str = "-----------------------3.Вычисление-----------------------\nВыберите режим\n";
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
		cout << "Арифметическое выражение вводить в следующем формате: " << endl;
		cout << " <имя_полинома> = <арифметическое выражение>" << endl;
		cout << " Пример: f = a + b, где f - новое выражение из полиномов." << endl;
		cout << "Арифметическое выражение должно содержать только следующие операции: +,-,*" << endl;
		cout << "a,b,c,d - имена полиномов, имеющихся в таблице" << endl;
		cout << "Введите арифметическое выражение:" << endl;
		try
		{
			cin.clear();
			getline(cin, str);
			if (str == "!") {
				system("cls");
				return;
			}
			if (str.find('=') == string::npos) { throw "Некорректный формат"; }
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
			cout << "Попробуйте ввести еще раз" << endl;
			flag = true;
			cin.clear();
		}
		catch (const char* s)
		{
			cin.clear();
			cout << s << endl;
			cout << "Попробуйте ввести еще раз" << endl;
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
		cout << "Что-то пошло не так " << endl;
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}