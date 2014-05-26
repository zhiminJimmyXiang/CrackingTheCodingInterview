#include "Chapter10.h"

bool Chapter10_test::Problem_1_test(){
    Chapter10 chapter10;
    int A[]={1,3,9,19,0,0,0,0,0,0};
    int B[]={2,3,9,11,13};
    int correctResult[]={1,2,3,3,9,9,11,13,19};
    chapter10.Problem_1(A, 4, B, 5);
    for(size_t i=0; i<9; ++i){
	if(A[i]!=correctResult[i])
	    return false;
    }
    return true;
}

bool Chapter10_test::Problem_2_test(){
    Chapter10 chapter10;
    string input[] = {"abc","bca","efg","acb","hij","gfe","hji","ihj","ijh"};
    string correctOutput[] = {"abc", "bca","acb","efg","gfe","hij","hji","ihj","ijh"};
    vector<string> inputStrArray(input, input+9), outputStrArray;
    chapter10.Problem_2(inputStrArray, outputStrArray);
    for(size_t i=0; i<outputStrArray.size(); ++i){
	if(outputStrArray[i]!=correctOutput[i])
	    return false;
    }
    return true;
}

bool Chapter10_test::Problem_3_test(){
    Chapter10 chapter10;
    //case 1: test distinct version
    int inputDistinct[] = {5,6,7,1,2,3,4};
    vector<int> dataArrayDistinct(inputDistinct, inputDistinct+7);
    if(chapter10.Problem_3_distinct(dataArrayDistinct, 5)!=0)
	return false;
    if(chapter10.Problem_3_distinct(dataArrayDistinct, 4)!=6)
	return false;
    if(chapter10.Problem_3_distinct(dataArrayDistinct, 7)!=2)
	return false;
    if(chapter10.Problem_3_distinct(dataArrayDistinct, 10)!=-1)
	return false;
    //case 2: test non-distinct version
    int inputNonDistinct[] = {5,5,5,5,6,6,7,7,1,1,2,3,4};
    vector<int> dataArrayNonDistinct(inputNonDistinct, inputNonDistinct+13);
    int result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 5);
    if(inputNonDistinct[result]!=5)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 6);
    if(inputNonDistinct[result]!=6)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 7);
    if(inputNonDistinct[result]!=7)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 1);
    if(inputNonDistinct[result]!=1)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 2);
    if(inputNonDistinct[result]!=2)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 3);
    if(inputNonDistinct[result]!=3)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 4);
    if(inputNonDistinct[result]!=4)
	return false;
    result = chapter10.Problem_3_nondistinct(dataArrayNonDistinct, 10);
    if(result!=-1)
	return false;
    return true;
}

bool Chapter10_test::Problem_5_test(){
    Chapter10 chapter10;
    string input[]={"","","abc","","","efg","","hij","lmn","","","","xyz"};
    vector<string> strVect(input, input+13);
    int result = chapter10.searchStr(strVect, 0, strVect.size(), "");
    if(result!=-1)
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "defg");
    if(result!=-1)
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "abc");
    if(strVect[result]!="abc")
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "efg");
    if(strVect[result]!="efg")
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "hij");
    if(strVect[result]!="hij")
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "lmn");
    if(strVect[result]!="lmn")
	return false;
    result = chapter10.searchStr(strVect, 0, strVect.size(), "xyz");
    if(strVect[result]!="xyz")
	return false;
    return true;
}

bool Chapter10_test::Problem_6_test(){
    Chapter10 chapter10;
    vector<vector<int> > matrix;
    int rowNum = 6, colNum = 7, rowDis = 2, colDis = 3;
    for(size_t i=0; i<rowNum; ++i){
	vector<int> temp;
	for(size_t j=0; j<colNum; ++j){
	    temp.push_back(1+i*rowDis+j*colDis);
	}
	matrix.push_back(temp);
    }
    int rowOut, colOut;
    for(size_t i=0; i<rowNum; ++i){
	for(size_t j=0; j<colNum; ++j){
	    chapter10.Problem_6(matrix, rowOut, colOut, matrix[i][j]);
	    if(matrix[rowOut][colOut]!=matrix[i][j])
		return false;
	}
    }
    return true;
}

bool Chapter10_test::Problem_7_test(){
    Chapter10 chapter10;
    int heights[] = {1,8,12,11,19,7,6};
    int weights[] = {1,7,6,13,18,9,10};
    vector<Person> input;
    for(size_t i=0; i<7; ++i){
	Person p;
	p.height = heights[i];
	p.weight = weights[i];
	input.push_back(p);
    }
    int result = chapter10.Problem_7_DP(input);
    if (result!=4)
	return false;
    result = chapter10.Problem_7_sort(input);
    if(result!=4)
	return false;
    return true;
}

bool Chapter10_test::Problem_8_test(){
    int stream[] = {5,3,8,4,2,1,7,6,9,3};
    Problem_8 problem8;
    for(size_t i=0; i<10; ++i){
	problem8.track(stream[i]);
    }
    int correctRank[]={5,3,8,4,1,0,7,6,9,3};
    for(size_t i=0; i<10; ++i){
	if(problem8.getRank(stream[i])!=correctRank[i]){
	    return false;
	}
    }
    return true;
}

int main(){
    Chapter10_test testor;
    //Problem 1
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;
    
    //Problem 2
    if(!testor.Problem_2_test())
	cout<<"Test 2 Failed!!!!!"<<endl;
    else
	cout<<"Test 2 Passed!"<<endl;
    //Problem 3
    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;
    
    //Problem 5
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;

     //Problem 6
    if(!testor.Problem_6_test())
	cout<<"Test 6 Failed!!!!!"<<endl;
    else
	cout<<"Test 6 Passed!"<<endl;
    
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
    return 0;
}
