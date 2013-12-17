#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"
#include "Entry.h"

using namespace std;

HashTable::HashTable(int tb_size, int block_size)
{
    this->table = new Entry[tb_size];
    this->table_size = tb_size;
    //cout << "Table size created. "<< endl;
}

int HashTable::Hash(string key)
{
    int hash = 0;
    int index;
    
    for(int i=0; i < key.length(); i++)
    {
        hash += key[i];
    }
    
    index = hash % table_size;
    
    return index;
}

int HashTable::Add(string key, int number)
{
    int index = this->Hash(key);
    
    this->table[index].SetKey(key);
    this->table[index].SetNumber(number);
    
    return 1;
}

int HashTable::Get(string key)
{
    int index = this->Hash(key);
    int number = this->table[index].GetNumber();
    
    if (number != 0) {
        return number;
    }
    
    return -1;
}