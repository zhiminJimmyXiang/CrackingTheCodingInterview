#include "Chapter18.h"

bool Chapter18_test::Problem_1_test(){
    Chapter18 chapter18;
    int a[] = {1212,123,-5,-10000};
    int b[] = {291,-234,1123,-112};
    int correctResult[] = {1503, -111, 1118, -10112};
    for(size_t i=0; i!=4; ++i){
	int result = chapter18.Problem_1(a[i], b[i]);
	if(result!=correctResult[i])
	    return false;
    }
    return true;
}

int Chapter18_test::count2ForOneNumber(unsigned num){
    int count = 0;
    while(num!=0){
	if(num%10==2)
	    ++count;
	num=num/10;
    }
    return count;
}

int Chapter18_test::count2sBruteForce(unsigned num){
    int count = 0;
    for(int i=0; i<=num; ++i){
	count+=count2ForOneNumber(i);
    }
    return count;
}

bool Chapter18_test::Problem_4_test(){
    Chapter18 chapter18;
    int a[] = {12,30,22222,222211};
    for(size_t i=0; i!=4; ++i){
	int correctResult = count2sBruteForce(a[i]);
	int result = chapter18.Problem_4(a[i]);
	if(correctResult!=result)
	    return false;
    }
    return true;
}


bool Chapter18_test::Problem_5_test(){
    Chapter18 chapter18;
    string file[]={"a", "b","c","d","c","a","b","e","d"};
    vector<string> strVector(file, file+9);
    string str1[]={"a", "b", "c"};
    string str2[]={"d","d", "d"};
    int correctResult[] = {2, 2, 1};
    for(size_t i=0; i!=3; ++i){
	int result = chapter18.Problem_5(strVector, str1[i], str2[i]);
	if(result!=correctResult[i])
	    return false;
    }
    return true;
}

bool Chapter18_test::Problem_7_test(){
    Chapter18 chapter18;
    string strArray[] = {"a", "b", "ab", "c", "abcabd", "abcd", "abab"};
    set<string> strSet(strArray, strArray+7);
    string result = chapter18.Problem_7(strSet);
    if(result!="abab")
	return false;
    return true;
}

bool Chapter18_test::Problem_8_test(){
    Chapter18 chapter18;
    string strArray[] = {"bcdef", "cd", "ef", "ad"};
    string s = "abcdef";
    bool correctResult[] = {true, true, true, false};
    for(size_t i=0; i!=4; ++i){
	bool result = chapter18.Problem_8(s, strArray[i]);
	if(result!=correctResult[i])
	    return false;
    }
    return true;
}

bool Chapter18_test::Problem_9_test(){
    Chapter18 chapter18;
    int numInsertation[] = {2,4,1,-2,10,9,11,0};
    vector<int> inputIntStream(numInsertation, numInsertation+8);
    int correctResult[] = {2, 4, 2, 2, 2, 4, 4, 4};
    vector<int> result;
    chapter18.Problem_9(inputIntStream, result);
    for(size_t i=0; i!=result.size(); ++i){
	if(correctResult[i]!=result[i])
	    return false;
    }
    return true;
}


bool Chapter18_test::Problem_10_test(){
    Chapter18 chapter18;
    string strStart="DAMP", strEnd="LIKE";
    string strTempArray[]={"DAMP", "LAMP", "LIME","LIKE", "LIMP"};
    set<string> dict(strTempArray, strTempArray+5);
    vector<string> path;
    string correctResult[]={"DAMP","LAMP","LIMP","LIME","LIKE"};
    chapter18.Problem_10(strStart, strEnd, dict, path);
    for(size_t i=0; i!=5; ++i){
	if(path[i]!=correctResult[i])
	    return false;
    }
    return true;
}

bool Chapter18_test::Problem_11_test(){
    Chapter18 chapter18;
    MATRIX matrix;
    int tempMatrix[5][5] = {{0,1,1,1,1},{0,1,0,0,1},{0,1,0,0,1},{0,1,1,1,1}, {0,0,0,0,0}};
    int (*p)[5]=tempMatrix;
    for(size_t i=0; i!=5; ++i){
	matrix.push_back(vector<int>(*(p+i), *(p+i)+5));
    }
    unsigned correctResult = 4;
    unsigned result = chapter18.Problem_11(matrix);
    if(result!=correctResult)
	return false;
    return true;
}

bool Chapter18_test::Problem_12_test(){
    Chapter18 chapter18;
    MATRIX matrix;
    int tempMatrix[5][5] = {{0,1,1,1,4},{0,1,0,0,1},{0,1,0,0,1},{0,1,1,1,1}, {0,0,0,0,0}};
    int (*p)[5]=tempMatrix;
    for(size_t i=0; i!=5; ++i){
	matrix.push_back(vector<int>(*(p+i), *(p+i)+5));
    }
    int correctResult = 15;
    int result = chapter18.Problem_12_dynamic_program(matrix);
    if(result!=correctResult)
	return false;
    result = chapter18.Problem_12_max_row_column(matrix);
    if(result!=correctResult)
	return false;
    return true;
    
}

int main(){
    Chapter18_test testor;
    //Problem 1
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;

    //Problem 4
    if(!testor.Problem_4_test())
	cout<<"Test 4 Failed!!!!!"<<endl;
    else
	cout<<"Test 4 Passed!"<<endl;
    
    
    //Problem 5
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;

    //Problem 7
    if(!testor.Problem_7_test())
	cout<<"Test 7 Failed!!!!!"<<endl;
    else
	cout<<"Test 7 Passed!"<<endl;

    //Problem 8
    if(!testor.Problem_8_test())
	cout<<"Test 8 Failed!!!!!"<<endl;
    else
	cout<<"Test 8 Passed!"<<endl;

    //Problem 9
    if(!testor.Problem_9_test())
	cout<<"Test 9 Failed!!!!!"<<endl;
    else
	cout<<"Test 9 Passed!"<<endl;
     
    //Problem 10
    if(!testor.Problem_10_test())
	cout<<"Test 10 Failed!!!!!"<<endl;
    else
	cout<<"Test 10 Passed!"<<endl;
    
    //Problem 11
    if(!testor.Problem_11_test())
	cout<<"Test 11 Failed!!!!!"<<endl;
    else
	cout<<"Test 11 Passed!"<<endl;

    //Problem 12
    if(!testor.Problem_12_test())
	cout<<"Test 12 Failed!!!!!"<<endl;
    else
	cout<<"Test 12 Passed!"<<endl;
    
    
    return 0;
}
