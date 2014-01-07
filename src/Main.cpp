/* 
 * File:   main.cpp
 * Author: douglas
 *
 * Created on 27 de Novembro de 2013, 21:20
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int index;
    HashTable hashObj(8, 2);
    
    hashObj.Add("Ivan", 320);
    hashObj.Add("Douglas", 512);
    hashObj.Add("Carlos", 300);
    hashObj.Add("Almeida", 2015);
    hashObj.Add("José", 215);
    hashObj.Add("Maria", 153);
    hashObj.Add("Pedro", 105);
    hashObj.Add("João", 20);
    hashObj.Add("Joana", 123);
    
    int number = hashObj.Get("Joana");
    
    cout << "number = "<<number<< endl;
    
    return 0;
}

