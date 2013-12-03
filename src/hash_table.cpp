#include <cstdlib>
#include <iostream>
#include <string>

#include "hash_table.h"

using namespace std;

hash_table::hash_table(int tb_size)
{
    table_size = tb_size;
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