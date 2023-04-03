#ifndef __LINETABLE_H__
#define __LINETABLE_H__

#include "BaseTable.h"
class LineTable : public BaseTable 
{
	Data* dat;
	int size; 
	int capacity; 
	void repacking(); 
public:
	LineTable() : BaseTable() 
	{
		capacity = 1000;
		size = 0;
		dat = new Data[capacity];
	}
	void deleteByKey(const string& key); 
	void insert(const Data& d); 
	Data* find(const string key); 
	void print();
	~LineTable();
};
#endif
