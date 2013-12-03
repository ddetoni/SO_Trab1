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
    hash_table hashObj(64, 8);
    
    index = hashObj.Add("Ivan", 5623);
    
    int number = hashObj.Get("Ivan");
    
    cout << "number = " << number << endl;
    
    return 0;
}

