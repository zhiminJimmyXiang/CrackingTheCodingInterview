#include "Chapter3.h"

/* Problem 2
How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.
 */

void Problem_2::push(int a){
    stackElement.push_back(a);
    if(stackMin.empty() || stackMin.back()>=a)
	stackMin.push_back(a);
}

void Problem_2::pop(){
    if(stackMin.back()==stackElement.back())
	stackMin.pop_back();
    stackElement.pop_back();
}

int Problem_2::top(){
    if(stackElement.empty())
	return INT_MIN;
    return stackElement.back();
}

int Problem_2::getMin(){
    if(stackElement.empty())
	return INT_MIN;
    return stackMin.back();
}

/* Problem 3
Imagine a (literal) stack of plates. If the stack gets too high, it migh t topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.
pop () should behave identically to a single stack (that is, pop () should return the
same values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a
specific sub-stack.
*/
void SetOfStacks::push(int a){
    if(setOfStacks.empty()||setOfStacks.back().size()==capacity){
	setOfStacks.push_back(vector<int>(1, a));
    }
    else
	setOfStacks.back().push_back(a);
}

void SetOfStacks::pop(){
    if(setOfStacks.empty())
	return;
    if(setOfStacks.back().size()==1)
	setOfStacks.pop_back();
    else
	setOfStacks.back().pop_back();
}

int SetOfStacks::back(){
    if(setOfStacks.empty())
	return INT_MIN;
    return setOfStacks.back().back();
}

void SetOfStacks::popAt(int index){
    if(index>=setOfStacks.size() || index<0)
	return;
    if(index==setOfStacks.size()-1)
	pop();
    else{
	for(unsigned i=index; i<setOfStacks.size()-1; ++i){
	    setOfStacks[i][capacity-1]=setOfStacks[i+1][0];
	    for(unsigned j=1; j<setOfStacks[i+1].size(); ++j)
		setOfStacks[i+1][j-1]=setOfStacks[i+1][j];
	}
	pop();
    }
}

int SetOfStacks::getElement(int i, int j){
    if(i<0 || i>=setOfStacks.size() || j<0 || j>=setOfStacks[i].size())
	return INT_MIN;
    return setOfStacks[i][j];
}

/*Problem 4

In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
different sizes which can slide onto any tower. The puzzle starts with disks sorted
in ascending order of size from top to bottom (i.e., each disk sits on top of an even
larger one). You have the following constraints:
(T) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto the next rod.
(3) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first tower to the last using Stacks.

*/

void Chapter3::move(int n, int source, int target, int temp){
    if(n==1){
	cout<<"move the 1 plate from "<<source<<" to "<<target<<endl;
	return;
    }
    move(n-1, source, temp, target);
    cout<<"move the "<<n<<" plate from "<<source<<" to "<<target<<endl;
    move(n-1, temp, target, source);
}

void Chapter3::Problem_4(int n, int source, int target, int temp){
    move(n, source, target, temp);
}


/*Problem 5
Implement a MyQueue class which implements a queue using two stacks.
*/

void MyQueue::push_back(int a){
    stackInput.push_back(a);
}

void MyQueue::pop_front(){
    if(stackOutput.empty())
	transferLeft();
    if(!stackOutput.empty())
	stackOutput.pop_back();
}

int MyQueue::front(){
    if(stackOutput.empty())
	transferLeft();
    if(stackOutput.empty())
	return INT_MIN;
    return stackOutput.back();
}

void MyQueue::transferLeft(){
    while(!stackInput.empty()){
	int temp = stackInput.back();
	stackOutput.push_back(temp);
	stackInput.pop_back();
    }
}

/*Problem 6
Write a program to sort a stack in ascending order (with biggest items on top).
You may use at most one additional stack to hold items, but you may not copy the
elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
*/

void Chapter3::Problem_6(vector<int> &oriStack){
    if(oriStack.empty())
	return;
    int oriLen(oriStack.size()), currLen(0);
    vector<int> addStack;
    while(currLen<oriLen){
	int minVal = INT_MAX;
	while(oriStack.size()!=currLen){
	    minVal = (minVal<=oriStack.back()?minVal:oriStack.back());
	    addStack.push_back(oriStack.back());
	    oriStack.pop_back();
	}
	oriStack.push_back(minVal);
	++currLen;
	bool flag(false);
	while(!addStack.empty()){
	    if(addStack.back()>minVal || flag == true)
		oriStack.push_back(addStack.back());
	    else
		flag=true;
	    addStack.pop_back();
	}
    }
}

/*Problem 7
An animal shelter holds only dogs and cats, and operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may use the built-in L inkedL ist data structure
*/
void Problem_7::enqueue(Animal &a){
    a.time=count;
    ++count;
    if(a.type==1)
	dogQueue.push_back(a);
    else if(a.type==2)
	catQueue.push_back(a);
}

Animal Problem_7::dequeueAny(){
    if(catQueue.empty() && dogQueue.empty()){
	Animal nullAnimal;
	nullAnimal.type = 0;
	return nullAnimal;
    }
    int dogTime = (dogQueue.empty()?INT_MAX:dogQueue.front().time);
    int catTime = (catQueue.empty()?INT_MAX:catQueue.front().time);
    if(dogTime<catTime){
	Animal dog = dogQueue.front();
	dogQueue.pop_front();
	return dog;
    }
    else{
	Animal cat = catQueue.front();
	catQueue.pop_front();
	return cat;
    }
}

Animal Problem_7::dequeueDog(){
    if(dogQueue.empty()){
	Animal nullAnimal;
	nullAnimal.type=0;
	return nullAnimal;
    }
    Animal dog = dogQueue.front();
    dogQueue.pop_front();
    return dog;
}

Animal Problem_7::dequeueCat(){
    if(catQueue.empty()){
	Animal nullAnimal;
	nullAnimal.type=0;
	return nullAnimal;
    }
    Animal cat = catQueue.front();
    catQueue.pop_front();
    return cat;
}
