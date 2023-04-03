#pragma once
#ifndef __HASHTABLIN_H__
#define __HASHTABLIN_H__

#include "BaseTable.h"

class HashTableSomething : public BaseTable 
{
    Data* Tab[1000];
public:
    HashTableSomething()
    {
        for (int i = 0; i < 1000; i++)
        {
            Tab[i] = nullptr;
        }
    }
    ~HashTableSomething();
    Data* find(const std::string key); 
    void insert(const Data& data);
    void deleteByKey(const string& key);
    void print();
    int HashIt(string key)
    {
        int Hash = 0;
        for (unsigned int i = 0; i < key.size(); i++) { Hash += (int)key[i]; }
        Hash *= key.size();
        return Hash % 1000;
    }
};

#endif