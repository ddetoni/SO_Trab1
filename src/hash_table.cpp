#include <cstdlib>
#include <iostream>
#include <string>

#include "hash_table.h"

using namespace std;

hash_table::hash_table(int tb_size, int block_size)
{
    table = new entry[tb_size];
    table_size = tb_size;
    //cout << "Table size created. "<< endl;
}

int hash_table::Hash(string key)
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

int hash_table::Add(string key, int number)
{
    int index = this->Hash(key);
    this->table[index] = {key, number};
    
    return 1;
}

int hash_table::Get(string key)
{
    int index = this->Hash(key);
    return this->table[index].number;
}