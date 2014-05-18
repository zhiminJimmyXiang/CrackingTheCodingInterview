#include "Chapter9.h"

bool Chapter9_test::Problem_1_test(){
    Chapter9 chapter9;
    //case 1
    if(chapter9.Problem_1(5)!=13)
	return false;
    //case 2
    cout<<chapter9.Problem_1(6)<<endl;
    if(chapter9.Problem_1(6)!=24)
	return false;
    return true;
}



int main(){
    Chapter9_test testor;
    //Problem 1
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;
    return 0;
}
