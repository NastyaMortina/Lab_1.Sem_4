#pragma once

#ifndef __UnorderedTableOnList_H__
#define __UnorderedTableOnList_H__

#include "BaseTable.h"

struct Link {
	Data data;
	Link* pNext;
};
 
class UnorderedTableOnList : public BaseTable
{
	Link* Head;
	int Amount; 
public:
	UnorderedTableOnList();
	~UnorderedTableOnList();
	Data* find(const std::string key); 
	void insert(const Data& data); 
	void deleteByKey(const std::string& key); 
	void print(); 
};
#endif