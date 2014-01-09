#include <cstdlib>
#include <iostream>
#include <string>
#include <pthread.h>

#include "Entry.h"

using namespace std;

#ifndef HASH_TABLE_H
#define	HASH_TABLE_H

class HashTable {
    private:
        int table_size;
        int block_size;
        Entry* table;
        pthread_mutex_t *mutexes;
        int full_blocks[];
        
    public:
        
        HashTable(int tb_size, int block_size);
        int HashFunction(string key);
        int Add(string key, int number);
        int Get(string key);
        int Set(string key, int number);
        int Delete(string key);
        int Print(string key);
        int PrintAll();
        int GetIndexBlock(int index);
    
};


#endif	/* HASH_TABLE_H */

