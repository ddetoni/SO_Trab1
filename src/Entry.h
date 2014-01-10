
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef ENTRY_H
#define	ENTRY_H

class Entry {
public:
    Entry();
    virtual ~Entry();
    void SetKey(string key);
    string GetKey();
    void SetNumber(int number);
    int GetNumber();
    void SetNext(Entry next);
    Entry GetNext();
    bool IsEmpty();
    
private:
    string key;
    int number;
};

#endif	/* ENTRY_H */

