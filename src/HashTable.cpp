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

int HashTable::Add(string key, int number)
{
    int index = this->HashFunction(key);
    cout << index << endl;
    int last_index = index;
    
    while(!this->table[index].IsEmpty())
    {
        index++;
        
        if(index == last_index) {
            cout << "Add_Error: Hash table is full." << endl;
            return -1;
        }
        
        if(index > this->table_size-1) {
            index = 0;
        }
    }
    
    this->table[index].SetKey(key);
    this->table[index].SetNumber(number);
    
    return 1;
}

int HashTable::Get(string key)
{
    int index = this->HashFunction(key);
    int last_index = index;
    
    while(this->table[index].GetKey() != key)
    {
        index++;
        
        if(index == last_index) {
            cout << "Get_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > this->table_size-1) {
            index = 0;
        }
    }
    
    int number = this->table[index].GetNumber();
    return number;
}

int HashTable::Set(string key, int number)
{
    int index = this->HashFunction(key);
    int last_index = index;
    
    while(this->table[index].GetKey() != key && !this->table[index].IsEmpty())
    {
        index++;
        
        if(index == last_index) {
            cout << "Set_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > this->table_size-1) {
            index = 0;
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
    
    while(this->table[index].GetKey() != key)
    {
        index++;
        
        if(index == last_index) {
            cout << "Delete_Error: The key doesn't exist." << endl;
            return -1;
        }
        
        if(index > this->table_size-1) {
            index = 0;
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