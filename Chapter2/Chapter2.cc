#include "Chapter2.h"

/* Problem 1:
Write code to remove duplicates from an unsorted linked list
 */

// Version 1: Time O(n), Memory O(n)
LinkedList *Chapter2::Problem_1_1(LinkedList *head){
    if(head==NULL)
	return head;
    set<int> nodeSet;
    nodeSet.insert(head->value);
    LinkedList *curr = head->next;
    LinkedList *currPrev = head;
    while(curr!=NULL){
	LinkedList *currNext = curr->next;
	if(nodeSet.find(curr->value)!=nodeSet.end()){
	    head = LinkedList::deleteNode(head, currPrev, curr);
	}
	else{
	    nodeSet.insert(curr->value);
	    currPrev = curr;
	}
	curr = currNext;
    }
    return head;
}
// Version 2: Time O(n^2), Memory O(1)
LinkedList *Chapter2::Problem_1_2(LinkedList *head){
    if(head==NULL)
	return head;
    LinkedList *outerIter = head;
    while(outerIter!=NULL){
	LinkedList *innerIter = outerIter->next;
	LinkedList *innerIterPrev = outerIter;
	while(innerIter!=NULL){
	    LinkedList *innerIterNext = innerIter->next;
	    if(innerIter->value == outerIter->value){
		outerIter = LinkedList::deleteNode(outerIter, innerIterPrev, innerIter);
	    }
	    else{
		innerIterPrev = innerIter;
	    }
	    innerIter = innerIterNext;
	}
	outerIter = outerIter->next;
    }
    return head;
}

/*Problem 2
  Implement an algorithm to find the kth to last element of a singly linked list.
 */

LinkedList *Chapter2::Problem_2(LinkedList *head, int k){
    if(head==NULL)
	return NULL;
    LinkedList *first = head;
    LinkedList *second = head;
    int count = 1;
    while(second!=NULL){
	if(count<=k){
	    ++count;
	}
	else{
	    first = first->next;
	}
	second = second->next;
    }
    if(count<=k)
	return NULL;
    else
	return first;

}


/*Proble 3
  Implement an algorithm to delete a node in the middle of a singly linked list, given
only access to that node.
 */

void Chapter2::Problem_3(LinkedList *middle){
    if(middle==NULL || middle->next==NULL)
	return;
    LinkedList *currNode = middle->next;
    LinkedList *preNode = middle;
    preNode->value = currNode->value;
    while(currNode->next!=NULL){
	preNode = preNode->next;
	currNode = currNode->next;
	preNode->value = currNode->value;
    }
    preNode->next = NULL;
}

/*Problem 4
 Write code to partition a linked list around a value x, such that all nodes less than x
come before alt nodes greater than or equal to x.
*/

LinkedList * Chapter2::Problem_4(LinkedList *head, int x){
    if(head == NULL)
	return NULL;
    LinkedList *greaterBranchHead(NULL), *lessBranchHead(NULL), *greaterBranchTail(NULL), *lessBranchTail(NULL);
    LinkedList *curr(head);
    while(curr!=NULL){
	if(curr->value>=x){
	    if(greaterBranchHead==NULL){
		greaterBranchHead = curr;
		greaterBranchTail = curr;
	    }
	    else{
		greaterBranchTail->next = curr;
		greaterBranchTail = curr;
	    }
	}
	else{
	    if(lessBranchHead==NULL){
		lessBranchHead = curr;
		lessBranchTail = curr;
	    }
	    else{
		lessBranchTail->next = curr;
		lessBranchTail = curr;
	    }
	}
	curr = curr->next;
    }
    if(greaterBranchHead==NULL || lessBranchHead == NULL)
	return head;
    lessBranchTail->next = greaterBranchHead;
    greaterBranchTail->next = NULL;
    return lessBranchHead;
}

/*Problem 5
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
of the list. Write a function that adds the two numbers and returns the sum as a
linked list.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
 */

LinkedList *Chapter2::Problem_5_reverse(LinkedList *num1st, LinkedList *num2nd){
    if(num1st==NULL || num2nd==NULL)
	return NULL;
    int prev = 0;
    LinkedList *result = new LinkedList();
    LinkedList *tail = result;
    while(num1st!=NULL && num2nd!=NULL){
	int sum = prev+num1st->value+num2nd->value;
	tail->next = new LinkedList();
	tail->next->value = sum%10;
	prev = sum/10;
	tail = tail->next;
	num1st = num1st->next;
	num2nd = num2nd->next;
    }
    LinkedList *rest = (num1st==NULL?num2nd:num1st);
    while(rest!=NULL){
	int sum = prev+rest->value;
	tail->next = new LinkedList();
	tail->next->value = sum%10;
	prev = sum/10;
	tail = tail->next;
	rest = rest->next;
    }
    if(prev==1){
	tail->next = new LinkedList();
	tail->next->value = 1;
	tail = tail->next;
    }
    tail->next = NULL;
    return result->next;
}


int Chapter2::addDigit(LinkedList *&sumDigit, LinkedList *num1st, LinkedList *num2nd){
    if(num1st==NULL && num2nd==NULL){
	sumDigit = NULL;
	return 0;
    }
    sumDigit = new LinkedList();
    int currCarry = addDigit(sumDigit->next, num1st->next, num2nd->next);
    int sum = currCarry+num1st->value+num2nd->value;
    sumDigit->value = sum%10;
    return sum/10;
}


LinkedList *Chapter2::Problem_5_forward(LinkedList *num1st, LinkedList *num2nd){
    if(num1st==NULL || num2nd==NULL)
	return NULL;
    int size1st(0), size2nd(0);
    for(LinkedList *curr = num1st; curr!=NULL; curr=curr->next){
	++size1st;
    }
    for(LinkedList *curr = num2nd; curr!=NULL; curr=curr->next){
	++size2nd;
    }
    LinkedList *result;
    if(size1st>size2nd){
	for(int i=0; i<size1st-size2nd; ++i){
	    LinkedList *temp  = new LinkedList();
	    temp->value = 0;
	    temp->next = num2nd;
	    num2nd = temp;
	}
    }
    else{
	for(int i=0; i<size2nd - size1st; ++i){
	    LinkedList *temp = new LinkedList();
	    temp->value = 0;
	    temp->next = num1st;
	    num1st = temp;
	}
    }
    int curr = addDigit(result, num1st, num2nd);
    if(curr == 1){
	LinkedList *temp = new LinkedList();
	temp->value = 1;
	temp->next = result;
	result = temp;
    }
    return result;
}


/*Problem 6
Given a circular linked list, implement an algorithm which returns the node at the
beginning of the loop
*/

LinkedList *Chapter2::Problem_6(LinkedList *head){
    if(head==NULL || head->next == NULL)
	return NULL;
    LinkedList* slowIter(head), *quickIter(head);
    int flag = 0;
    while(quickIter!=NULL && (quickIter!=slowIter || flag==0)){
	flag = 1;
	slowIter = slowIter->next;
	if(quickIter->next!=NULL)
	    quickIter = quickIter->next->next;
	else
	    return NULL;
    }
    
    while(head!=slowIter){
	head = head->next;
	slowIter = slowIter->next;
    }
    return head;
}

/*Problem 7
 Implement a function to check if a linked list is a palindrome,
 */
//reverse and compare
bool Chapter2::Problem_7_reverse(LinkedList *head){
    if(head==NULL)
	return false;
    LinkedList *reverseList = NULL;
    for(LinkedList *curr = head; curr!=NULL; curr=curr->next){
	LinkedList *temp = new LinkedList();
	temp->value = curr->value;
	temp->next = reverseList;
	reverseList = temp;
    }
    LinkedList *currForward(head), *currReverse(reverseList);
    bool result = true;
    while(currForward!=NULL){
	if(currForward->value!=currReverse->value){
	    result=false;
	    break;
	}
	currForward = currForward->next;
	currReverse = currReverse->next;
    }
    currReverse = reverseList;
    while(currReverse!=NULL){
	LinkedList *temp = currReverse->next;
	delete currReverse;
	currReverse = temp;
    }
    return result;
}

//recursive 
bool Chapter2::recursivePalindrome(LinkedList *forward, LinkedList *&reverseNext, LinkedList *middleBefore, LinkedList *middleAfter){
    if(forward==middleBefore){
	reverseNext = middleAfter->next;
	return (middleBefore->value == middleAfter->value);
    }
    LinkedList *reverse;
    bool preResult = recursivePalindrome(forward->next, reverse, middleBefore, middleAfter);
    if(preResult){
	if(forward->value==reverse->value){
	    reverseNext = reverse->next;
	    return true;
	}
	else
	    return false;
    }
    else
	return false;
}

bool Chapter2::Problem_7_recursive(LinkedList *head){
    if(head==NULL)
	return false;
    LinkedList *slowIter(head), *quickIter(head->next);
    while(quickIter!=NULL && quickIter->next!=NULL){
	slowIter = slowIter->next;
	quickIter = quickIter->next->next;
    }
    LinkedList *middleBefore(slowIter);
    LinkedList *middleAfter = (quickIter==NULL?slowIter:slowIter->next);
    LinkedList *recursiveIter = NULL;
    return recursivePalindrome(head, recursiveIter, middleBefore, middleAfter);
}
