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
#include <cstdint>
#include <inttypes.h>

#include "HashTable.h"

using namespace std;

pthread_mutex_t mymutex;

int j = 0;

void *n_operations(void* p)
{
    int num = (intptr_t)p;
    
    pthread_mutex_lock(&mymutex);
        cout << num << " op: " << j << endl;
        j++;
    pthread_mutex_unlock(&mymutex);
}


int main(int argc, char** argv) {
    
    int n_thread = atoi(argv[1]);
    int s_table = atoi(argv[2]);
    int n_block = atoi(argv[3]);
    int n_op = atoi(argv[4]);
    
    HashTable hash_t(s_table, n_block);
    pthread_mutex_t mutex_block[n_block];
    pthread_t threads[n_thread];
    
    int op_per_thread = n_op/n_thread;
    int rest = n_op%n_thread;

    for(int i=0; i < n_block; i++)
    {
        pthread_mutex_init(&mutex_block[i], NULL);
    }
    
    for(int i=0; i < n_thread; i++)
    {
        pthread_create(&threads[i], NULL, &n_operations,(void *)i);
    }
    
    for(int i=0; i < n_thread; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}

