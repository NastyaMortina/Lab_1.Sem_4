#include "UnorderedTableOnList.h"
// реализация методов неупорядоченной таблицы на списках
UnorderedTableOnList::UnorderedTableOnList() : Head(nullptr), Amount(0)
{
}

UnorderedTableOnList::~UnorderedTableOnList()
{
	while ((Head != nullptr) && (Amount))
	{
		Link* p = Head;
		if (p->pNext != nullptr)
			Head = p->pNext;
		delete p;
		Amount--;
	}
}

Data* UnorderedTableOnList::find(const std::string k)
{
	if (Head == nullptr) { return nullptr; }

	Link* p = Head;

	if (k == p->data.key) {
		return &(p->data);
	}

	while (p->pNext != nullptr) {
		p = p->pNext;
		if (k == p->data.key)
			return &(p->data);
	}
	return nullptr;
}

void UnorderedTableOnList::insert(const Data& d)
{
	if (Head == nullptr) {
		Head = new Link;
		Head->data.key = d.key;
		Head->data._polynom = d._polynom;
		Head->data.polinomString = d.polinomString;
		Head->pNext = nullptr;
		Amount++;
		return;
	}

	if (find(d.key) != nullptr) { throw exception(); }

	Link* p = new Link;
	p->data.key = d.key;
	p->data._polynom = d._polynom;
	p->data.polinomString = d.polinomString;
	p->pNext = Head;
	Head = p;
	Amount++;
}

void UnorderedTableOnList::deleteByKey(const std::string& keySearch) {
	if (Head == nullptr) { throw exception(); }
	Link* newLink = Head;

	if (keySearch == newLink->data.key) {
		if (newLink->pNext != nullptr) {
			Head = newLink->pNext;
			delete newLink;
			return;
		}
		else {
			delete newLink;
			Head = nullptr;
			return;
		}
	}

	Link* newLink2;

	while (newLink->pNext != nullptr) {
		newLink2 = newLink;
		newLink = newLink->pNext;

		if (keySearch == newLink->data.key) {
			if (newLink->pNext != nullptr) {
				newLink2->pNext = newLink->pNext;
			}
			delete newLink;
			return;
		}
	}
	throw;
}

void UnorderedTableOnList::print()
{
	cout << "\tНеотсортированная таблица на листе " << endl;
	if (Head == nullptr) cout << "\tVOID\n";
	else
	{
		Link* p = Head;
		cout << p->data.key << ":\t" << p->data.polinomString << endl;

		while (p->pNext != nullptr)
		{
			p = p->pNext;
			cout << p->data.key << ":\t" << p->data.polinomString << endl;
		}
	}
}