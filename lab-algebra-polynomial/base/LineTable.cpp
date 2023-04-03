#include "LineTable.h"
//LineTable (неупорядоченная таблица на массиве)
void LineTable::repacking() // перепаковка
{
	capacity += 1000;
	Data* temp = new Data[capacity];
	if (temp == nullptr)
	{
		throw 5;
	}
	for (int i = 0; i < size; i++)
	{
		temp[i] = dat[i];
	}
	delete[] dat;
	dat = temp;
}

void LineTable::deleteByKey(const string& key)
{
	if (size == 0)
	{
		throw exception();
	}
	Data* d = find(key);
	if (d != nullptr)
	{
		Data temp = dat[size - 1];
		dat[size - 1] = *d;
		*d = temp;
		size--;
	}
	else
		throw exception();
}

void LineTable::insert(const Data& d)
{
	if (size == capacity)
	{
		repacking();
	}
	if (find(d.key) == nullptr)
	{
		dat[size] = d;
		size++;
	}
	else
		throw exception();
}

Data* LineTable::find(const string key)
{
	for (int i = 0; i < size; i++)
	{
		if (dat[i].key == key)
		{
			return &dat[i];
		}
	}
	return nullptr;
}

void LineTable::print()
{
	std::cout << "\t Линейная на массиве " << std::endl;
	for (int i = 0; i < size; i++)
		cout << dat[i].key << ":\t" << dat[i].polinomString << endl;
	if (size == 0)
		cout << "Empty" << endl;
}

LineTable::~LineTable() { delete[] dat; }

