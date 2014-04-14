#include "Chapter2.h"

bool Chapter2_test::Problem_1_test(){
    Chapter2 chapter2;
    LinkedList *input = NULL;
    //case 1
    LinkedList *result = chapter2.Problem_1_1(input);
    if(result!=NULL)
	return false;
    result = chapter2.Problem_1_2(input);
    if(result!=NULL)
	return false;
    //case 2
    int a[]={5,5,5,5,5,5,5};
    int len = 7;
    LinkedList *input2 = LinkedList::createList(a, a+len);
    LinkedList *result21 = chapter2.Problem_1_1(input2);
    if(!(result21->value==5 && result21->next==NULL)) 
	return false;
    LinkedList *result22 = chapter2.Problem_1_2(input2);
    if(!(result22->value==5 && result22->next==NULL))
	return false;
    //case 3
    int b[]={21,45,45,8,8,9,8,0,1,1,1,0,0,9,2,1,3,4,9,9,2,2,2,1,0};
    len = 25;
    LinkedList *input3 = LinkedList::createList(b, b+len);
    LinkedList *result31 = chapter2.Problem_1_1(input3);
    LinkedList *result32 = chapter2.Problem_1_2(input3);
    set<int> correctResultSet;
    for(int i=0; i<len; ++i)
	correctResultSet.insert(b[i]);
    set<int> output1Set;
    for(LinkedList* curr=result31; curr!=NULL; curr=curr->next){
	if(output1Set.find(curr->value)!=output1Set.end())
	    return false;
	output1Set.insert(curr->value);
    }
    set<int> output2Set;
    for(LinkedList* curr=result32; curr!=NULL; curr=curr->next){
	if(output2Set.find(curr->value)!=output2Set.end())
	    return false;
	output2Set.insert(curr->value);
    }
    set<int>::iterator iterCorrect = correctResultSet.begin();
    set<int>::iterator iterOutput1 = output1Set.begin();
    if(correctResultSet.size()!=output1Set.size())
	return false;
    while(iterCorrect!=correctResultSet.end()){
	if(*iterCorrect!=*iterOutput1)
	    return false;
	++iterCorrect;
	++iterOutput1;
    }

    iterCorrect = correctResultSet.begin();
    set<int>::iterator iterOutput2 = output2Set.begin();
    if(correctResultSet.size()!=output2Set.size())
	 return false;
    while(iterCorrect!=correctResultSet.end()){
	if(*iterCorrect!=*iterOutput2)
	    return false;
	++iterCorrect;
	++iterOutput2;
    }
    return true;

}
bool Chapter2_test::Problem_2_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input1=NULL;
    if(chapter2.Problem_2(input1, 6)!=NULL)
	return false;
    
    //case 2
    int a[]={1};
    LinkedList *input2 = LinkedList::createList(a, a+1);
    if(chapter2.Problem_2(input2, 4)!=NULL)
	return false;
    
    
    //case 3
    int b[]={1,2,3,4,5,6,7,8,9};
    LinkedList *input3 = LinkedList::createList(b, b+9);
    for(int i=1; i<=9; ++i){
	if(chapter2.Problem_2(input3,i)->value!=10-i)
	    return false;
    }
    return true;
}

bool Chapter2_test::Problem_3_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input1 = NULL;
    LinkedList *middle = NULL;
    chapter2.Problem_3(middle);
    if(input1!=NULL)
	return false;
    //case 2
    int b[]={1,2};
    LinkedList *input2 = LinkedList::createList(b, b+2);
    chapter2.Problem_3(input2);
    if(input2->value!=2 || input2->next!=NULL)
	return false;

    //case 3
    int c[]={1,2,3,4,5,6,7,8,9,10,11};
    LinkedList *input3 = LinkedList::createList(c, c+11);
    middle = input3;
    for(int i=0; i<5; ++i)
	middle = middle->next;
    chapter2.Problem_3(middle);
    int correctResult[]={1,2,3,4,5,7,8,9,10,11};
    int count = 0;
    for(LinkedList *curr = input3; curr!=NULL; curr=curr->next){
	if(curr->value!=correctResult[count])
	    return false;
	++count;
    }
    return true;
}

bool Chapter2_test::Problem_4_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input1 = NULL;
    if(chapter2.Problem_4(input1, 5)!=NULL)
	return false;
    //caes 2
    int a[]={1,8,11,2,9,10,14,7,11,15,14,22,3};
    LinkedList *input = LinkedList::createList(a, a+13);
    LinkedList *result = chapter2.Problem_4(input, 9);
    int count = 0;
    for(LinkedList *curr = result; curr!=NULL; curr=curr->next){
	if((count<5 && curr->value>=9)||(count>=5 && curr->value<9))
	    return false;
	++count;
    }
    return true;
}

bool Chapter2_test::Problem_5_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input1 = NULL;
    int a[]={1,2,3};
    LinkedList *input2 = LinkedList::createList(a, a+3);
    LinkedList *resultReverse = chapter2.Problem_5_reverse(input1, input2);
    if(resultReverse!=NULL)
	return false;
    LinkedList *resultForward = chapter2.Problem_5_forward(input1, input2);
    if(resultForward!=NULL)
	return false;
 
    //case 2
    int b[]={9,9,8,9,9};
    input1 = LinkedList::createList(b, b+5);
    int correctReverse[]={0,2,2,0,0,1};
    resultReverse = chapter2.Problem_5_reverse(input1, input2);
    int count = 0;
    for(LinkedList*curr = resultReverse; curr!=NULL; curr=curr->next){
	if(curr->value!=correctReverse[count])
	    return false;
	++count;
    }
    if(count<6)
	return false;

    int correctForward[]={1,0,0,0,2,2};
    resultForward = chapter2.Problem_5_forward(input1, input2);
    count = 0;
    for(LinkedList*curr = resultForward; curr!=NULL; curr=curr->next){
	if(curr->value!=correctForward[count])
	    return false;
	++count;
    }
    if(count<6)
	return false;
    return true;
}

bool Chapter2_test::Problem_6_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input = NULL;
    if(chapter2.Problem_6(input)!=NULL)
	return false;

    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
    vector<LinkedList*> iterArray;
    input = LinkedList::createList(a, a+12);
    for(LinkedList *curr = input; curr!=NULL; curr=curr->next)
	iterArray.push_back(curr);
    iterArray[iterArray.size()-1]->next = iterArray[2];
    if(chapter2.Problem_6(input)->value!=3){
	cout<<chapter2.Problem_6(input)->value<<endl;
	return false;
    }
    return true;
}

bool Chapter2_test::Problem_7_test(){
    Chapter2 chapter2;
    //case 1
    LinkedList *input = NULL;
    if(chapter2.Problem_7_reverse(input)==true)
	return false;
    if(chapter2.Problem_7_recursive(input)==true)
	return false;
    //case 2
    int a[]={1,2,3,4,4,3,2,1};
    input = LinkedList::createList(a, a+8);
    if(chapter2.Problem_7_reverse(input)==false)
	return false;
    if(chapter2.Problem_7_recursive(input)==false)
	return false;
    //case 3
    int b[]={1,2,3,4,3,2,1};
    input = LinkedList::createList(b, b+7);
    if(chapter2.Problem_7_reverse(input)==false)
	return false;
    if(chapter2.Problem_7_recursive(input)==false)
	return false;
    //case 4
    int c[]={1,2,3,4,2,1};
    input = LinkedList::createList(b, b+6);
    if(chapter2.Problem_7_reverse(input)==true)
	return false;
    if(chapter2.Problem_7_recursive(input)==true)
	return false;
    return true;
}

int main(){
    Chapter2_test testor;
    //--- Problem 1 test ---
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;

    //--- Problem 2 test ---
    if(!testor.Problem_2_test())
	cout<<"Test 2 Failed!!!!!"<<endl;
    else
	cout<<"Test 2 Passed!"<<endl;

    //--- Problem 3 test ---
    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;

    //--- Problem 4 test ---
    if(!testor.Problem_4_test())
	cout<<"Test 4 Failed!!!!!"<<endl;
    else
	cout<<"Test 4 Passed!"<<endl;

     //--- Problem 5 test ---
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;

    //--- Problem 6 test ---
    if(!testor.Problem_6_test())
	cout<<"Test 6 Failed!!!!!"<<endl;
    else
	cout<<"Test 6 Passed!"<<endl;

    //--- Problem 7 test ---
    if(!testor.Problem_7_test())
	cout<<"Test 7 Failed!!!!!"<<endl;
    else
	cout<<"Test 7 Passed!"<<endl;
    
    return 0;
}
