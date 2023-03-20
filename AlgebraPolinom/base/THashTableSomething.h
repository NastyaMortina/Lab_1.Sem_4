#pragma once
#ifndef __HASHTABLIN_H__
#define __HASHTABLIN_H__

#include "TBaseTable.h"

class THashTableSomething : public TBaseTable 
{
    Data* Tab[1000]; 
public:
    THashTableSomething() 
    { 
        for (int i = 0; i < 1000; i++) 
        {   
            Tab[i] = nullptr; 
        }
    }
    ~THashTableSomething();
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