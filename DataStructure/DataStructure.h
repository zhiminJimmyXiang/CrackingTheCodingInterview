#ifndef _data_structure
#define _data_structure

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

typedef vector<vector<int> > MATRIX;

class String{
 public:
    static string positiveIntToString(int num);
};

class LinkedList{
 public:
    int value;
    LinkedList * next;
    static LinkedList* deleteNode(LinkedList *head, LinkedList *curr);
    
};


#endif
