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

pthread_mutex_t mymutex;

int j = 0;

struct thread_data{
    int id;
    int  n_op;
    pthread_mutex_t  *mutex;
    HashTable *ht;
};

void *n_operations(void *threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    
    pthread_mutex_lock(&my_data->mutex[3]);
        cout << my_data->id << " " << my_data->n_op << " op: " << j << endl;
        j++;
    pthread_mutex_unlock(&my_data->mutex[3]);
}


int main(int argc, char** argv) {
    
    int n_thread = atoi(argv[1]);
    int s_table = atoi(argv[2]);
    int n_block = atoi(argv[3]);
    int n_op = atoi(argv[4]);
    
    HashTable hash_t(8, 4);
    
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
    
    hash_t.PrintAll();
    
    /*
    pthread_mutex_t mutex_block[n_block];
    pthread_t threads[n_thread];
    struct thread_data td[n_thread];
    
    int op_per_thread = n_op/n_thread;
    int rest = n_op%n_thread;

    for(int i=0; i < n_block; i++)
    {
        pthread_mutex_init(&mutex_block[i], NULL);
    }
    
    for(int i=0; i < n_thread; i++)
    {
        td[i].id = i;
        td[i].mutex = mutex_block;
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
    */
    return 0;
}

