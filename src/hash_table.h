#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_TABLE_H
#define	HASH_TABLE_H

class hash_table {
    private:
        
        int table_size;
        
        struct entry{
            string key;
            int number;
            entry* next;
        };
        
        entry* table;
        
    public:
        
        hash_table(int tb_size, int block_size);
        int Hash(string key);
        int Add(string key, int number);
        int Get(string key);
    
};


#endif	/* HASH_TABLE_H */

