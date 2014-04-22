#include "Chapter3.h"

bool Chapter3_test::Problem_2_test(){
    Chapter3 chapter3;
    
    int a[]={2,3,9,0,8,-1,3,3,-2,-3};
    int minVal[]={2,2,2,0,0,-1,-1,-1,-2,-3};
    for(int i=0; i<10; ++i){
	chapter3.problem_2.push(a[i]);
	if(chapter3.problem_2.top()!=a[i])
	    return false;
	if(chapter3.problem_2.getMin()!=minVal[i])
	    return false;
    }
    for(int i=9; i>=0; --i){
	if(chapter3.problem_2.top()!=a[i])
	    return false;
	if(chapter3.problem_2.getMin()!=minVal[i])
	    return false;
	chapter3.problem_2.pop();
    }
    return true;
}

bool Chapter3_test::Problem_3_test(){
    Chapter3 chapter3;
    //case 1
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for(unsigned i=0; i<16; ++i){
	chapter3.problem_3.push(a[i]);
    }
    for(int i=15; i>=0; --i){
	if(chapter3.problem_3.back()!=a[i])
	    return false;
	chapter3.problem_3.pop();
    }
    //case 2
    for(unsigned i=0; i<16; ++i)
	chapter3.problem_3.push(a[i]);
    int correctResult[]={5,6,7,8,9,10,11,12,13,14,15,16};
    for(unsigned i=0; i<12; ++i){
	if(chapter3.problem_3.getElement(0,4)!=correctResult[i])
	    return false;
	chapter3.problem_3.popAt(0);
    }
    return true;
}

// Hanoi tower, have to test manually
bool Chapter3_test::Problem_4_test(){
    Chapter3 chapter3;
    //case 1
    chapter3.Problem_4(3,1,3,2);
    cout<<endl;
    //case 2
    chapter3.Problem_4(5,1,3,2);
    cout<<endl;
    return true;
}

bool Chapter3_test::Problem_5_test(){
    Chapter3 chapter3;
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    for(unsigned i=0; i<13; ++i)
	chapter3.problem_5.push_back(a[i]);
    for(unsigned i=0; i<13; ++i){
	if(chapter3.problem_5.front()!=a[i])
	    return false;
	chapter3.problem_5.pop_front();
    }
    return true;
    
}

int main(){
    Chapter3_test testor;
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
    //testor.Problem_4_test();
    //correct

    //--- Problem 5 test ---
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;
    
    return 0;
}
