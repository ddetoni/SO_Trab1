/* 
 * File:   main.cpp
 * Author: douglas
 *
 * Created on 27 de Novembro de 2013, 21:20
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <pthread.h>

#include "HashTable.h"

using namespace std;

struct thread_data{
    int id;
    int  n_op;
    HashTable *ht;
};

void *n_operations(void *threadarg)
{
    struct thread_data *t_data;
    t_data = (struct thread_data *) threadarg;
    
    cout << "entrou n_op" << endl;
    t_data->ht->Add("Ivan", t_data->id);
    t_data->ht->Add("Maria", t_data->id);
    t_data->ht->Add("Carlos", t_data->id);
    t_data->ht->Add("Joselito", t_data->id);
    t_data->ht->Add("José", t_data->id);
    t_data->ht->Add("Simão", t_data->id);
    
}


int main(int argc, char** argv) {
    
    int n_thread = atoi(argv[1]);
    int s_table = atoi(argv[2]);
    int n_block = atoi(argv[3]);
    int n_op = atoi(argv[4]);
    
    HashTable hash_t(s_table, n_block);
    cout << hash_t.GetSize() << endl;
    /*
    hash_t.Add("Ivan", 123456);
    hash_t.Add("navI", 654321);
    hash_t.Add("Douglas", 100);
    hash_t.Add("Mario", 1200000000);
    hash_t.Add("Jacos", 12);
    hash_t.Add("Jairo", 10);
    hash_t.Add("Maria", 20);
    hash_t.Add("Lucas", 102);
    
    hash_t.Delete("navI");
    
    hash_t.Set("Mario", 123);
    */
    /*
    td.ht = &hash_t;
    td.id = 10;
    td.n_op = 20;
    
    pthread_create(&threads[0], NULL, &n_operations, (void *) &td);
    pthread_create(&threads[1], NULL, &n_operations, (void *) &td);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    hash_t.PrintAll();
    */
    
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
    cout << "aqui 1" << endl;
    for(int i=0; i < n_thread; i++)
    {
        pthread_create(&threads[i], NULL, &n_operations,(void *) &td[i]);
    }
    cout << "aqui 2" << endl;
    
    
    for(int i=0; i < n_thread; i++)
    {
        cout << "entrou join" << endl;
        pthread_join(threads[i], NULL);
    }
    cout << "aqui 3" << endl;
    
    hash_t.PrintAll();
    
    pthread_exit(NULL);

    
    return 0;
}

