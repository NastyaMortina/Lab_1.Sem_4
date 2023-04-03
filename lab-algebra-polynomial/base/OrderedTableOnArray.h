#pragma once

#ifndef __ORDEREDTABLEONARRAY_H__
#define __ORDEREDTABLEONARRAY__

#include <string>
#include <iostream>
#include "BaseTable.h"

using namespace std;

class OrderedTableOnArray : public BaseTable
{
	Data* Tab[1000];
	int size;
public:
	OrderedTableOnArray() :BaseTable() {
		for (int i = 0; i < 1000; i++) { Tab[i] = nullptr; }
		size = 0;
	}
	~OrderedTableOnArray();
	Data* find(const string key); 
	void insert(const Data& data);
	void deleteByKey(const string& key); 
	void print();
	int Compare(string k1, string k2);
};

#endif