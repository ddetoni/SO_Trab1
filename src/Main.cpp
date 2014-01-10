#include <cstdlib>
#include <iostream>
#include <string>
#include <pthread.h>
#include <time.h>

#include "HashTable.h"

using namespace std;

struct thread_data{
    int id;
    int  n_op;
    HashTable *ht;
};

string keys [50] = {"Ivan1", "Ivan2", "Ivan3", "Ivan4", "Ivan5", "Ivan6", "Ivan7", "Ivan8", "Ivan9", "Ivan10",  
                  "Douglas1", "Douglas2", "Douglas3", "Douglas4", "Douglas5", "Douglas6", "Douglas7", "Douglas8", "Douglas9", "Douglas10", 
                  "Joana1", "Joana2", "Joana3", "Joana4", "Joana5", "Joana6", "Joana7", "Joana8", "Joana9", "Joana10", 
                  "Mario1", "Mario2", "Mario3", "Mario4", "Mario5", "Mario6", "Mario7", "Mario8", "Mario9", "Mario10", 
                  "Mauricio1", "Mauricio2", "Mauricio3", "Mauricio4", "Mauricio5", "Mauricio6", "Mauricio7", "Mauricio8", "Mauricio9", "Mauricio10"};


void *n_operations(void *threadarg)
{
    struct thread_data *t_data;
    t_data = (struct thread_data *) threadarg;
    
    srand (time(NULL));
    
    for(int i=0; i < t_data->n_op; i++)
    {
        int op = rand() % 6;
        int k = rand() % 50;
        int value = rand() % 1000000;
        
        switch (op)
        {
            case 1: t_data->ht->Add(keys[k], value);
                break;
                
            case 2: t_data->ht->Get(keys[k]);
                break;

            case 3: t_data->ht->Set(keys[k], value);
                break;
                
            case 4: t_data->ht->Delete(keys[k]);
                break;
                
            case 5: t_data->ht->Print(keys[k]);
                break;
        }
    }
    
}


int main(int argc, char** argv) {
    
    int n_thread = atoi(argv[1]);
    int s_table = atoi(argv[2]);
    int n_block = atoi(argv[3]);
    int n_op = atoi(argv[4]);
    
    HashTable hash_t(s_table, n_block);
    
    pthread_t threads[n_thread];
    struct thread_data td[n_thread];
    
    int op_per_thread = n_op/n_thread;
    int rest = n_op%n_thread;
    
    for(int i=0; i < n_thread; i++)
    {
        td[i].id = i;
        td[i].ht = &hash_t;
        if(i == n_thread-1)
        {
            td[i].n_op = op_per_thread + rest;
        }else {
            td[i].n_op = op_per_thread;
        }
    }
    
    for(int i=0; i < n_thread; i++)
    {
        pthread_create(&threads[i], NULL, &n_operations,(void *) &td[i]);
    }
    
    
    for(int i=0; i < n_thread; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    hash_t.PrintAll();
    
    pthread_exit(NULL);
  
    return 0;
}

