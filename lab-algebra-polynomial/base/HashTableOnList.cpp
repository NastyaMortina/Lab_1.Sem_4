#include "HashTableOnList.h"
#include "BaseTable.cpp"

int HashIt(string key)
{
	int Hash = 0;
	for (unsigned int i = 0; i < key.size(); i++) { Hash += (int)key[i]; }
	Hash *= key.size();
	return Hash % 1000;
}

HashTableOnList::~HashTableOnList()
{
	for (int i = 0; i < 1000; i++)
		if (Tab[i] != nullptr)
			delete Tab[i];
}

Data* HashTableOnList::find(const string key)
{
	int hash = HashIt(key);
	if (Tab[hash] == nullptr)
		return nullptr;
	else
	{
		link* p = Tab[hash];

		while (p != nullptr)
		{
			if (p->data.key == key)
				return &p->data;
			p = p->pNext;
		}
	}
	return nullptr;
}

void HashTableOnList::insert(const Data& data)
{
	if (find(data.key) != nullptr)
		throw exception();
	int hash = HashIt(data.key);
	link* p = new link;
	p->pNext = nullptr;
	p->data = data;
	if (Tab[hash] == nullptr)
	{
		Tab[hash] = p;
		return;
	}
	else
	{
		link* pp = Tab[hash];
		while (pp->pNext != nullptr)
			pp = pp->pNext;
		pp->pNext = p;

		return;
	}
}

void HashTableOnList::deleteByKey(const string& key)
{
	if (find(key) == nullptr)
		throw exception();

	int hash = HashIt(key);
	link* p = Tab[hash];
	link* pp = p;
	if (p->data.key == key)
	{
		pp = p->pNext;
		delete p;
		Tab[hash] = pp;
		p = pp;

		return;
	}
	p = p->pNext;
	while (p->data.key != key)
	{
		if (p->data.key == key)
		{
			while (pp->pNext != p)
				pp = pp->pNext;
			pp->pNext = p->pNext;
			delete p;
			p = pp;

			return;
		}
		p = p->pNext;
	}
}

void HashTableOnList::print()
{
	int k = 0;
	link* p;
	std::cout << "\tХэш таблица на листе " << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		p = Tab[i];
		while (p != nullptr)
		{
			cout << p->data.key << ":\t" << p->data._polynom << endl;
			p = p->pNext;
			k++;
		}
	}
	if (k == 0) { cout << "Empty" << endl; }
}
