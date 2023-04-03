#include "OrderedTableOnArray.h"


OrderedTableOnArray::~OrderedTableOnArray()
{
	for (int i = 0; i < 1000; i++)
		if (Tab[i] != nullptr)
			delete Tab[i];
}
Data* OrderedTableOnArray::find(const string key)
{
	int midd, left = 0, right = size - 1;
	while (left <= right)
	{
		midd = (left + right) / 2;
		if (Compare(Tab[midd]->key, key) == 0)
			return Tab[midd];
		if (Compare(Tab[midd]->key, key) < 0)
			left = midd + 1;
		if (Compare(Tab[midd]->key, key) > 0)
			right = midd - 1;
	}
	return nullptr;
}
void OrderedTableOnArray::insert(const Data& data)
{
	if (find(data.key) != nullptr) { throw 3; }
	string h = "";
	if (Tab[0] != nullptr)
		h = Tab[0]->key;
	int j = 0;
	while (j < size && (Compare(h, data.key) < 0))
	{
		j++;
		if (Tab[j] != nullptr)
			h = Tab[j]->key;
		else
			h = "";
	}
	if (Tab[j] == nullptr)
	{
		Tab[j] = new Data;
		Tab[j]->key = data.key;
		Tab[j]->_polynom = data._polynom;
		Tab[j]->polinomString = data.polinomString;
	}
	else
	{
		Tab[size] = new Data;
		for (int i = size; i > j; i--)
			Tab[i] = Tab[i - 1];
		Tab[j] = new Data;
		Tab[j]->key = data.key;
		Tab[j]->_polynom = data._polynom;
		Tab[j]->polinomString = data.polinomString;
	}
	size++;
	//throw exception();
}
void OrderedTableOnArray::deleteByKey(const string& key)
{
	if (find(key) == nullptr)
		throw exception();
	int midd, left = 0, right = size - 1;
	while (left <= right)
	{
		midd = (left + right) / 2;
		if (Compare(Tab[midd]->key, key) == 0)
		{
			delete Tab[midd];
			for (int i = midd; i < size; i++)
				Tab[i] = Tab[i + 1];
			size--;
			return;
		}
		if (Compare(Tab[midd]->key, key) < 0)
			left = midd + 1;
		if (Compare(Tab[midd]->key, key) > 0)
			right = midd - 1;
	}
}
void OrderedTableOnArray::print()
{
	int k = 0;
	string h;
	cout << "\tОтсортированная линейная таблица " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << Tab[i]->key << ":\t" << Tab[i]->_polynom << endl;
		k++;
	}
	if (k == 0)
		cout << "Empty" << endl;
}
int OrderedTableOnArray::Compare(string k1, string k2)
{
	string alf = "abcdefghijklmnopqrstuvwxyz";
	//string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int i = 0;
	int check1 = 0, check2 = 0;
	while (i < k1.length() && i < k2.length())
	{
		if (k1[i] == k2[i])
			i++;
		else
		{
			for (unsigned int k = 0; k < alf.length(); k++)
			{
				if (k1[i] == alf[k])//|| k1[i] == ALF[k])
				{
					check1 = k + 1;
					break;
				}
				if (k2[i] == alf[k])//|| k2[i] == ALF[k])
				{
					check2 = k + 1;
					break;
				}
			}
			if (check1 > 0)
				return -1;
			if (check2 > 0)
				return 1;
		}
	}
	if (i == k1.length()) {
		if (i == k2.length()) { return 0; }
		else { return -1; }
	}
	else { return 1; }
}