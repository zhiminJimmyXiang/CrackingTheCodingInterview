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

LinkedList* LinkedList::deleteNode(LinkedList *head, LinkedList *curr){
    if(head==NULL || curr==NULL)
	return NULL;
    if(head==curr){
	head = head->next;
	delete curr;
	return head;
    }
    LinkedList *pre = head;
    while(pre->next!=curr)
	pre = pre->next;
    pre->next = curr->next;
    delete curr;
    return head;
}
