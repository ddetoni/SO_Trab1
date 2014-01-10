#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>

#include "HashTable.h"
#include "Entry.h"

using namespace std;

HashTable::HashTable(int tb_size, int block_size)
{
    this->table = new Entry[tb_size];
    this->table_size = tb_size;
    this->block_size = block_size;
    
    this->mutexes = new pthread_mutex_t[block_size] {};
    
    for(int i=0; i < block_size; i++)
    {
        int rc = pthread_mutex_init(&this->mutexes[i], NULL);
        assert(rc == 0);
    }
    
    this->full_blocks = new int[block_size] {};
}

int HashTable::HashFunction(string key)
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

int HashTable::GetIndexBlock(int index)
{
    return index/(this->table_size/this->block_size);
}

int HashTable::Add(string key, int number)
{   
    int index = this->HashFunction(key);
    int last_index = index;
    int i_block = this->GetIndexBlock(index);
    
    pthread_mutex_lock(&this->mutexes[i_block]);

    if(this->full_blocks[i_block]==1) {
        cout << "Add_Error: Block is full." << endl;
        pthread_mutex_unlock(&this->mutexes[i_block]);
        return -1;
    }
    
    int count = 0;
    while(!this->table[index].IsEmpty())
        {
            index++;
            count++;
            
            if(count == this->table_size/this->block_size) {
                cout <<"Add_Error: Hash table or block is full." << endl;
                this->full_blocks[i_block] = 1;
                pthread_mutex_unlock(&this->mutexes[i_block]);
                return -1;
            }

            if(index > ((i_block+1)*this->block_size)-1) {
                index = i_block*this->block_size;
            }
        }
    
    
        this->table[index].SetKey(key);
        this->table[index].SetNumber(number);
    pthread_mutex_unlock(&this->mutexes[i_block]);

    return 1;
}

int HashTable::Get(string key)
{
    int index = this->HashFunction(key);
    int last_index = index;
    int i_block = this->GetIndexBlock(index);
    
    while(this->table[index].GetKey() != key)
    {
        index++;
        
        if(index == last_index) {
            cout << "Get_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > ((i_block+1)*this->block_size)-1) {
            index = i_block*this->block_size;
        }
    }
    
    int number = this->table[index].GetNumber();
    return number;
}

int HashTable::Set(string key, int number)
{
    int index = this->HashFunction(key);
    int last_index = index;
    int i_block = this->GetIndexBlock(index);
    
    while(this->table[index].GetKey() != key && !this->table[index].IsEmpty())
    {
        index++;
        
        if(index == last_index) {
            cout << "Set_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > ((i_block+1)*this->block_size)-1) {
            index = i_block*this->block_size;
        }
    }
    
    this->table[index].SetKey(key);
    this->table[index].SetNumber(number);
    
    return 1;
}

int HashTable::Delete(string key)
{
    int index = this->HashFunction(key);
    int last_index = index;
    int i_block = this->GetIndexBlock(index);
    
    while(this->table[index].GetKey() != key)
    {
        index++;
        
        if(index == last_index) {
            cout << "Delete_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > ((i_block+1)*this->block_size)-1) {
            index = i_block*this->block_size;
        }
    }
    
    this->table[index].SetKey("");
    this->table[index].SetNumber(0);
            
}

int HashTable::Print(string key)
{
    int number = this->Get(key);
    
    cout << number << endl;
}

int HashTable::PrintAll()
{   
    for(int i=0; i < this->table_size; i++)
    {
        if(!this->table[i].IsEmpty()){
            cout << this->table[i].GetKey() << ": " << this->table[i].GetNumber() << endl;
        } 
    }
}

int HashTable::GetSize(){
    return this->table_size;
}