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


int main(){
    Chapter2_test testor;
    //--- Problem 1 test ---
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;

    //--- Problem 2 test ---
    /*if(!testor.Problem_2_test())
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
	cout<<"Test 7 Passed!"<<endl;*/
    
    return 0;
}
