#include <cstdlib>
#include <iostream>
#include <string>

#include "Entry.h"

using namespace std;

#ifndef HASH_TABLE_H
#define	HASH_TABLE_H

class HashTable {
    private:
        int table_size;
        Entry* table;
        
    public:
        
        HashTable(int tb_size, int block_size);
        int HashFunction(string key);
        int Add(string key, int number);
        int Get(string key);
    
};


#endif	/* HASH_TABLE_H */

