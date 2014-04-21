#include "../DataStructure/DataStructure.h"

//class for problem 2
class Problem_2{
 private:
    vector<int> stackElement;
    vector<int> stackMin;
 public:
    void push(int a);
    void pop();
    int top();
    int getMin();
};

//class for problem 3
class SetOfStacks{
 private:
    vector<vector<int> > setOfStacks;
    int capacity;
 public:
    SetOfStacks(){capacity=5;};
    void push(int a);
    void pop();
    int back();
    void popAt(int index);
    int getElement(int i, int j);
};

//class for problem 5
class MyQueue{
 private:
    vector<int> stackInput;
    vector<int> stackOutput;
    void transferLeft();
 public:
    void push_back(int a);
    void pop_front();
    int front();
};

//class for Problem 7
class Animal{
 public:
    int id;
    int time; //the smaller, the earlier
    int type; //0: null, 1: dog, 2:cat
};
class Problem_7{
 private:
    list<Animal> catQueue; 
    list<Animal> dogQueue; 
 public:
    void enqueue(const Animal &a);
    Animal dequeueAny();
    Animal dequeueDog();
    Animal dequeueCat();
};

class Chapter3{
 private:
    void move(int n, int source, int target, int temp);
 public:
    Problem_2 problem_2;
    SetOfStacks problem_3;
    void Problem_4(int n, int source, int target, int temp);
    MyQueue problem_5;
    void Problem_6(vector<int> &oriStack);
    Problem_7 problem_7;
};


class Chapter3_test{
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
};

