#include "THashTableSomething.h"
#include "TBaseTable.cpp"


THashTableSomething::~THashTableSomething()
{
	for (int i = 0; i < 1000; i++) {
		if (Tab[i] != nullptr) { delete Tab[i]; }
	}
}

Data* THashTableSomething::find(const std::string key)  {
	int SearchHash = HashIt(key);
	if (Tab[SearchHash] == nullptr){
		for (int i = 0; i < 10; i++){
			SearchHash = (SearchHash + 7) % 1000;
			if (Tab[SearchHash] != nullptr)
				if (Tab[SearchHash]->key == key)
					return Tab[SearchHash];
		}
		return nullptr;
	}
	else {
		if (Tab[SearchHash]->key == key) { return Tab[SearchHash]; }
		else {
			for (int i = 0; i < 10; i++) {
				SearchHash = (SearchHash + 7) % 1000;
				if (Tab[SearchHash] != nullptr) {
					if (Tab[SearchHash]->key == key) { return Tab[SearchHash]; }
				}
			}
			return nullptr;
		}
	}
}

void THashTableSomething::insert(const Data& data)
{
	if (find(data.key) != nullptr) { throw exception(); }
	int InsertHash = HashIt(data.key);

	if (Tab[InsertHash] == nullptr) {
		Tab[InsertHash] = new Data;
		Tab[InsertHash]->key = data.key;
		Tab[InsertHash]->polinomString = data.polinomString;
		Tab[InsertHash]->_polinom = data._polinom;
		return;
	}
	else {
		if (Tab[InsertHash]->polinomString == data.polinomString) { throw exception(); }
		for (int i = 0; i < 10; i++) {
			InsertHash = (InsertHash + 7) % 1000;
			if (Tab[InsertHash] == nullptr){
				Tab[InsertHash] = new Data;
				Tab[InsertHash]->key = data.key;
				Tab[InsertHash]->polinomString = data.polinomString;
				Tab[InsertHash]->_polinom = data._polinom;

				return;
			}
			else { if (Tab[InsertHash]->polinomString == data.polinomString) { throw exception(); } }
				
		}

		throw exception();
	}

}

void THashTableSomething::deleteByKey(const string& key) {
	if (find(key) == nullptr) { throw exception(); }
	Data* p = find(key);
	int deleteHash = HashIt(p->key);
	delete Tab[deleteHash];
	Tab[deleteHash] = nullptr;
}

void THashTableSomething::print()
{
	cout << "\tХэш-таблица" << endl;
	for (int i = 0; i < 1000; i++)
		if (Tab[i] != nullptr) { cout << Tab[i]->key << ":\t" << Tab[i]->polinomString << endl; }
}
