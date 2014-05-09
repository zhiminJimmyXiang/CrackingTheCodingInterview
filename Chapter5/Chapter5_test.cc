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
    Chapter5 chapter5;
    //case 1
    unsigned a[]={0,1,2,3,4,6,7,8,9,10};
    vector<unsigned> A(a, a+10);
    unsigned result =  chapter5.Problem_7(10, A);
    if(result!=5)
	return false;

    //case 2
    unsigned b[]={0,1,2,3,4,5,6,7,8,9};
    A.assign(b, b+10);
    result = chapter5.Problem_7(10, A);
    if(result!=10)
	return false;
    return true;
}

bool Chapter5_test::Problem_8_test(){
    Chapter5 chapter5;
    //case 1
    char temp[]={0,0,0,0,0,0,0,0,0};
    vector<char> screen(temp, temp+9);
    chapter5.Problem_8(screen, 24, 1, 11, 2);
    char correct[]={0,0,0,0,0,0,0x7F,0xF0, 0};
    for(unsigned i=0; i<9; ++i){
	//cout<<bitset<8>(screen[i])<<" "<<flush;
	if(screen[i]!=correct[i])
	    return false;
    }
    
    //case 2
    screen.assign(temp, temp+9);
    chapter5.Problem_8(screen, 24, 1, 2, 2);
    char correct2[]={0,0,0,0,0,0,0x60,0, 0};
    for(unsigned i=0; i<9; ++i){
	if(screen[i]!=correct2[i])
	return false;
    }
    
    //case 3
    screen.assign(temp, temp+9);
    chapter5.Problem_8(screen, 24, 1, 4, 2);
    char correct3[]={0,0,0,0,0,0,0x78,0, 0};
    for(unsigned i=0; i<9; ++i){
	if(screen[i]!=correct3[i])
	return false;
    }
    
    
    return true;    
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
    
    if(!testor.Problem_8_test())
	cout<<"Test 8 Failed!!!!!"<<endl;
    else
	cout<<"Test 8 Passed!"<<endl;
    
    
    return 0;
}
