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
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <queue>
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
    static LinkedList* deleteNode(LinkedList *head, LinkedList *currPrev, LinkedList *curr);
    static LinkedList* createList(int *begin, int *end);
    
};

class BTree{
 public:
    int value;
    BTree *left;
    BTree *right;
    BTree(){value=0; left=NULL; right=NULL;};
};

class BTreeParent{
 public:
    int value;
    BTreeParent *left;
    BTreeParent *right;
    BTreeParent *parent;
    BTreeParent()  {value=0; left=NULL; right=NULL; parent=NULL;};
};

class Graph{
 public:
    vector<list<int> > graph;
} ;

class SuffixTreeNode{
 public:
    map<char, SuffixTreeNode *> childNodes;
};

class SuffixTree{
 public:
    SuffixTreeNode root;
    void insertString(const string &str);
    SuffixTree(const string &str);
    bool searchString(const string &str);
};

#endif
