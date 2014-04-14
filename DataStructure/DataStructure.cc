#include "DataStructure.h"

string String::positiveIntToString(int num){
    string result;
    while(num>0){
	int c = num%10;
	result = string(1, c+'0')+result;
	num/=10;
    }
    return (result.size()==0? string(1, '0'):result);
}

LinkedList* LinkedList::deleteNode(LinkedList *head, LinkedList *currPrev, LinkedList *curr){
    if(curr==head){
	head = curr->next;
	delete curr;
    }
    else{
	currPrev->next = curr->next;
	delete curr;
    }
    return head;
}

LinkedList *LinkedList::createList(int *begin, int *end){
    LinkedList *result  = new LinkedList();
    LinkedList *tail = result;
    tail->next = NULL;
    for(int *curr = begin; curr!=end; ++curr){
	tail->next = new LinkedList();
	tail->next->value = *curr;
	tail = tail->next;
    }
    LinkedList *temp = result->next;
    delete result;
    return temp;
}
