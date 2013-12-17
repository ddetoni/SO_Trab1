/* 
 * File:   Entry.cpp
 * Author: douglas
 * 
 * Created on 17 de Dezembro de 2013, 15:07
 */

#include "Entry.h"

Entry::Entry() {
    this->key = "";
    this->number = 0;
}

Entry::~Entry() {
}

void Entry::SetKey(string key){
    this->key = key;
}

string Entry:: GetKey() {
    
    return this->key;
}

void Entry::SetNumber(int number){
    this->number = number;
}

int Entry::GetNumber(){
    return this->number;
}

