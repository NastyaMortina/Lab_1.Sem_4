#pragma once

#ifndef __HASH_TABLE_ON_LIST_H__
#define __HASH_TABLE_ON_LIST_H__
#include "BaseTable.h"

using namespace std;

struct link
{
	Data data;
	link* pNext;
};

class HashTableOnList : public BaseTable
{
	link* Tab[1000];
public:
	HashTableOnList() 
	{
		for (int i = 0; i < 1000; i++) { Tab[i] = nullptr; }
	}
	~HashTableOnList();
	Data* find(const string key);
	void insert(const Data& data);
	void deleteByKey(const string& key);
	void print();
};

#endif