#ifndef __BASETABLE_H__
#define __BASETABLE_H__

#include <vector>
#include "Polynom.h"

struct Data
{
	std::string key;
	std::string polynomString;
	Polynom _polynom;
};

class BaseTable 
{
public:
	virtual Data* find(const std::string key) = 0;
	virtual void insert(const Data& data) = 0;
	virtual void deleteByKey(const std::string& key) = 0;
	virtual void print() = 0;
	virtual ~BaseTable() {}
};

#endif