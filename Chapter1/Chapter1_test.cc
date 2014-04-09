#include "Chapter1.h"

bool Chapter1_test::Problem_1_test(){
    Chapter1 chapter1;
    string test1="";
    if(chapter1.Problem_1(test1)==false)
	return false;
    test1="ababz0sd;fsa";
    if(chapter1.Problem_1(test1)==true)
	return false;
    test1="asdf-012;l,";
    if(chapter1.Problem_1(test1)==false)
	return false;
    return true;
}


bool Chapter1_test::Problem_2_test(){
    Chapter1 chapter1;
    char str[] = "";
    // case 1
    chapter1.Problem_2(str);
    if(str[0]!='\0')
	return false;
    // case 2
    char str1[] = "abcdefgsdfsdfa";
    char str2[] = "abcdefgsdfsdfa";
    chapter1.Problem_2(str1);
    int length = strlen(str1);
    for(unsigned i=0; i<length; ++i){
	if(str1[i]!=str2[length-1-i])
	    return false;
    }
    return true;   
}

bool Chapter1_test::Problem_3_test(){
    Chapter1 chapter1;
    string str1 = "";
    string str2 = "";
    //case 1
    if(!chapter1.Problem_3(str1, str2))
	return false;
    //case 2
    str1 = "adfsfagagadfe";
    str2 = "adwefgagdfagh";
    if(chapter1.Problem_3(str1, str2))
       return false;
    //case 3
    str1 = "aaaaaaab";
    str2 = "baaaaaaa";
    if(!chapter1.Problem_3(str1, str2))
       return false;
    //case 4
    str1 = "asdfgab";
    str2 = "aasgbdf";
    if(!chapter1.Problem_3(str1, str2))
       return false;
    return true;
}

bool Chapter1_test::Problem_4_test(){
    Chapter1 chapter1;
    //case 1
    char str[]="";
    int len = 0;
    chapter1.Problem_4(str, len);
    if(str[0]!='\0')
	return false;
    //case 2
    char str1[100] = "abc";
    char strCorrect1[100]="abc";
    len = 3;
    chapter1.Problem_4(str1, len);
    if(strlen(str1)!=strlen(strCorrect1))
	return false;
    for(unsigned int i=0; i<strlen(strCorrect1); ++i){
	if(str1[i]!=strCorrect1[i])
	    return false;
    }
    //case 3
    char str2[100]="     ";
    char strCorrect2[100]="%20%20%20%20%20";
    len = 5;
    chapter1.Problem_4(str2, len);
    if(strlen(str2)!=strlen(strCorrect2))
	return false;
    for(unsigned int i=0; i<strlen(strCorrect2); ++i){
	if(str2[i]!=strCorrect2[i])
	    return false;
    }
    //case 4
    char str3[100]=" a b c d e f g ";
    char strCorrect3[100]="%20a%20b%20c%20d%20e%20f%20g%20";
    len = 15;
    chapter1.Problem_4(str3, len);
    if(strlen(str3)!=strlen(strCorrect3))
	return false;
    for(unsigned int i=0; i<strlen(strCorrect3); ++i){
	if(str3[i]!=strCorrect3[i])
	    return false;
    }
    return true;
}

bool Chapter1_test::Problem_5_test(){
    Chapter1 chapter1;
    //case 1
    string strIn, strOut;
    chapter1.Problem_5(strIn, strOut);
    if(!strOut.empty())
	return false;
    //case 2
    strIn = "abcdefg";
    chapter1.Problem_5(strIn, strOut);
    if(strOut!=strIn)
	return false;
    //case 3
    strIn = "aabbbbcdefffgeeeeeee";
    chapter1.Problem_5(strIn, strOut);
    if(strOut!=string("a2b4c1d1e1f3g1e7"))
	return false;
    //case 4
    strIn = "aaaaaaaaaaaaaabbbbbbbbbbbbbbbcccccccccccccccceeeeeeeeeeeeeeeee";
    chapter1.Problem_5(strIn, strOut);
    if(strOut!=string("a14b15c16e17"))
       return false;
    return true;
}

bool Chapter1_test::Problem_6_test(){
    Chapter1 chapter1;
    MATRIX matrix1, matrixCorrect;
    //case 1
    chapter1.Problem_6(matrix1);
    if(!matrix1.empty())
	return false;
    //case 2
    matrix1.push_back(vector<int>(3, 1));
    matrix1.push_back(vector<int>(3, 2));
    matrix1.push_back(vector<int>(3, 3));
    int temp[3]={3,2,1};
    matrixCorrect.push_back(vector<int>(temp, temp+3));
    matrixCorrect.push_back(vector<int>(temp, temp+3));
    matrixCorrect.push_back(vector<int>(temp, temp+3));
    chapter1.Problem_6(matrix1);
    if(matrix1!=matrixCorrect)
	return false;
    //case 3
    int size = 500;
    matrix1.clear();
    matrixCorrect.clear();
    for(unsigned i=0; i<size; ++i)
	matrix1.push_back(vector<int>(size, i+1));
    int *temp1 = new int[size];
    for(int i=0; i<size; ++i)
	temp1[i] = size-i;
    for(unsigned i=0; i<size; ++i)
	matrixCorrect.push_back(vector<int>(temp1, temp1+size));
    chapter1.Problem_6(matrix1);
    if(matrix1!=matrixCorrect)
	return false;
    delete temp1;
    return true;
}

bool Chapter1_test::Problem_7_test(){
    Chapter1 chapter1;
    MATRIX matrix, matrixCorrect;
    //case 1
    chapter1.Problem_7(matrix);
    if(!matrix.empty())
	return false;
  
    //case 2
    int temp[3]={1,2,0};
    matrix.push_back(vector<int>(temp, temp+3));
    matrix.push_back(vector<int>(temp, temp+3));
    matrix.push_back(vector<int>(temp, temp+3));
    matrixCorrect.push_back(vector<int>(3, 0));
    matrixCorrect.push_back(vector<int>(3, 0));
    matrixCorrect.push_back(vector<int>(3, 0));
    chapter1.Problem_7(matrix);
    if(matrix!=matrixCorrect)
	return false;

    //case 3
    matrix.clear();
    matrixCorrect.clear();
    int size = 100;
    vector<int> temp1;
    for(unsigned i=0; i<size; ++i)
	temp1.push_back(i+1);
    for(unsigned i=0; i<size; ++i)
	matrix.push_back(temp1);
    matrix[0][0]=0;
    matrix[size-1][size-1]=0;
    matrixCorrect = matrix;
    for(unsigned i=0; i<size; ++i){
	matrixCorrect[0][i]=0;
	matrixCorrect[i][0]=0;
	matrixCorrect[size-1][i]=0;
	matrixCorrect[i][size-1]=0;
    }
    chapter1.Problem_7(matrix);
    if(matrix!=matrixCorrect)
	return false;
    return true;
}

int main(){
    Chapter1_test testor;
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
