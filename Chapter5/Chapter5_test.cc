#include "Chapter5.h"

bool Chapter5_test::Problem_1_test(){
    Chapter5 chapter5;
    //case 1
    unsigned N=0x400, M=0x13, i=2, j=6;
    unsigned result = chapter5.Problem_1(M, N, i, j);
    //cout<<result<<endl;
    if(result!=0x44C)
	return false;
    return true;
}

bool Chapter5_test::Problem_2_test(){
    Chapter5 chapter5;
    //case 1
    double input = 0.5;
    string result=chapter5.Problem_2(input);
    if(result!="0.1")
	return false;
    //case 2
    input = 0.625;
    result = chapter5.Problem_2(input);
    if(result!="0.101")
	return false;

    //case 3
    input = 0.333;
    result = chapter5.Problem_2(input);
    if(result!="ERROR")
	return false;
    return true;
}

bool Chapter5_test::Problem_3_test(){
    Chapter5 chapter5;
    //case 1
    unsigned input = 3;
    unsigned result = chapter5.findPreviousSmallest(input);
    if(result!=0)
	return false;
    input = 0xF0000000;
    result = chapter5.findNextLargest(input);
    if(result!=0)
	return false;

    //case 2
    input = 0x18;
    result = chapter5.findPreviousSmallest(input);
    if(result!=0x14)
	return false;
    result = chapter5.findNextLargest(input);
    if(result!=0x21)
	return false;
    
    
    //case 3
    input = 0x23;
    result = chapter5.findPreviousSmallest(input);
    if(result!=0x1C)
	return false;
    result = chapter5.findNextLargest(input);
    if(result!=0x25)
	return false;
    
    return true;
}

bool Chapter5_test::Problem_5_test(){
    Chapter5 chapter5;
    //case 1
    unsigned a=0x5, b=0x0;
    unsigned result = chapter5.Problem_5(a, b);
    if(result!=2)
	return false;
    result = chapter5.Problem_5_1(a, b);
    if(result!=2)
	return false;

    //case 2
    a=0xfffff;
    b=0xfffff;
    result = chapter5.Problem_5(a, b);
    if(result!=0)
	return false;
    result = chapter5.Problem_5_1(a, b);
    if(result!=0)
	return false;  

    //case 3
    a=0xff0f0;
    b=0xfffff;
    result = chapter5.Problem_5(a, b);
    if(result!=8)
	return false;
    result = chapter5.Problem_5_1(a, b);
    if(result!=8)
	return false;

    return true;    
}

bool Chapter5_test::Problem_6_test(){
    Chapter5 chapter5;
    //case 1
    unsigned a=0xffffffff;
    unsigned result = chapter5.Problem_6(a);
    if(result!=a)
	return false;

    //case 2
    a=0x69;
    result = chapter5.Problem_6(a);
    if(result!=0x96)
	return false;
    return true;
}

bool Chapter5_test::Problem_7_test(){
    
}

int main(){
    Chapter5_test testor;
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;
    
    if(!testor.Problem_2_test())
	cout<<"Test 2 Failed!!!!!"<<endl;
    else
	cout<<"Test 2 Passed!"<<endl;

    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;

    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;
    
    if(!testor.Problem_6_test())
	cout<<"Test 6 Failed!!!!!"<<endl;
    else
	cout<<"Test 6 Passed!"<<endl;
    
    if(!testor.Problem_7_test())
	cout<<"Test 7 Failed!!!!!"<<endl;
    else
	cout<<"Test 7 Passed!"<<endl;
    
    
    return 0;
}
