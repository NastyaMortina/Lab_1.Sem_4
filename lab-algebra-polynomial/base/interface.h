#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "LineTable.h"
#include "UnorderedTableOnList.h"
#include "OrderedTableOnArray.h"
#include "SearchTreeTable.h"
#include "HashTableSomething.h"
#include "HashTableOnList.h"
#include <conio.h>
#include <iostream>
#include "Postfix.h"

class Interface 
{
	BaseTable* Base;
	BaseTable* tables[6];
	string namesOfTables[6] = { "Линейная таблица на массиве","Линейная таблица на списке","Упорядоченная таблица на массиве",
		"Таблица на поисковом дереве","Хеш-таблица с открытым перемешиванием (на массиве)","Хеш-таблица со списками (метод цепочек)" };
	string tecName;
public:
	Interface()
	{
		tables[0] = new LineTable();
		tables[1] = new UnorderedTableOnList();
		tables[2] = new OrderedTableOnArray();
		tables[3] = new SearchTreeTable();
		tables[4] = new HashTableSomething();
		tables[5] = new HashTableOnList();
		Base = tables[0];
		tecName = namesOfTables[0];
	}
	void countPolynomInPoint(Data data, int x, int y, int z);
	string controlPolynom(const string& str);
	int inputControl(int left_board, int right_board, void (*print)(const string&), const string& str);
	void tableSelection();
	void menu();
	void addPolinom();
	void searchAndMakeOperations(); 
	string controlKey(const string& key);
	void print();
	void deleteByKey();
	void calculate();
	void calPol();
	void exitApp();
};
#endif