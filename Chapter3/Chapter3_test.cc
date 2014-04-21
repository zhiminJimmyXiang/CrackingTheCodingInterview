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

int main(){
    Chapter3_test testor;
    //--- Problem 2 test ---
    if(!testor.Problem_2_test())
	cout<<"Test 2 Failed!!!!!"<<endl;
    else
	cout<<"Test 2 Passed!"<<endl;
    
    //--- Problem 3 test ---
    
    return 0;
}
