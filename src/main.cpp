/* 
 * File:   main.cpp
 * Author: douglas
 *
 * Created on 27 de Novembro de 2013, 21:20
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "hash_table.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int index;
    hash_table hashObj(85);
    
    index = hashObj.Hash("Maria");
    
    cout << "index = " << index << endl;
    
    return 0;
}

