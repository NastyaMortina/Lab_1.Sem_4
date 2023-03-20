#pragma once

#ifndef __HASH_TABLE_ON_LIST_H__
#define __HASH_TABLE_ON_LIST_H__
#include "TBaseTable.h"

using namespace std;

struct link
{
	Data data;
	link* pNext;
};

class THashTableOnList : public TBaseTable
{
	link* Tab[1000];
public:
	THashTableOnList() {	
		for (int i = 0; i < 1000; i++) { Tab[i] = nullptr; }
	} 
	~THashTableOnList();
	Data* find(const string key);
	void insert(const Data& data);
	void deleteByKey(const string& key); 
	void print();
};

#endif