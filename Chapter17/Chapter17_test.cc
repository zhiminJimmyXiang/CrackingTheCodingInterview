#include "Chapter17.h"

bool Chapter17_test::Problem_3_test(){
    Chapter17 chapter17;
    int inputArray[] = {5, 100, 128};
    int correctResult[] = {1, 24, 31};
    for(size_t i=0; i<3; ++i){
	int result = chapter17.Problem_3(inputArray[i]);
	if(result!=correctResult[i])
	    return false;
    }
    return true;
}

bool Chapter17_test::Problem_4_test(){
    Chapter17 chapter17;
    int a[]={1,4,-9,7,-2};
    int b[]={1,9,11,2,8};
    int correctResult[] = {1, 9, 11, 7, 8};
    for(size_t i=0; i<5; ++i){
	int result = chapter17.Problem_4(a[i], b[i]);
	if(result!=correctResult[i])
	    return false;
    }
    return true;
}	    

bool Chapter17_test::Problem_5_test(){
    Chapter17 chapter17;
    string correctStrArray[5] = {"RGBY", "RRGG", "RGBB", "YGRR", "YBBB"};
    string guessStrArray[5] = {"RBGG", "GGRB", "RGBB", "RRGR", "YBGB"};
    int correctHitsArray[5] = {1, 0, 4, 1, 3};
    int pseudoHitsArray[5] = {2, 3, 0, 2, 0};
    int hitCount=0;
    int pseudoHitCount=0;
    for(size_t i=0; i<5; ++i){
	chapter17.Problem_5(correctStrArray[i], guessStrArray[i], hitCount, pseudoHitCount);
	
       	if(hitCount!=correctHitsArray[i] || pseudoHitCount!=pseudoHitsArray[i])
	    return false;
    }
    return true;
}

bool Chapter17_test::Problem_6_test(){
    Chapter17 chapter17;
    vector<vector<int> > inputArrayVec;
    int array1[] = {1,2,3,4,5,6,7};
    int array2[] = {7,6,5,4,3,2,1};
    int array3[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    int array4[] = {1,3,5,10,2,4,6,7};
    inputArrayVec.push_back(vector<int>(array1, array1+7));
    inputArrayVec.push_back(vector<int>(array2, array2+7));
    inputArrayVec.push_back(vector<int>(array3, array3+13));
    inputArrayVec.push_back(vector<int>(array4, array4+8));
    int correctLeft[] = {0,0,3, 1};
    int correctRight[] = {0, 6, 9, 7};
    for(size_t i=0; i<inputArrayVec.size(); ++i){
	int leftIndex=0, rightIndex=0;
	chapter17.Problem_6(inputArrayVec[i],leftIndex, rightIndex);
	if(leftIndex!=correctLeft[i] || rightIndex!=correctRight[i])
	    return false;
    }
    return true;	    	    
}

bool Chapter17_test::Problem_7_test(){
    Chapter17 chapter17;
    long long inputArray[]={12345678, 876543210, 871234, 7761321};
    for(size_t i=0; i<4; ++i){
	string result = chapter17.Problem_7(inputArray[i]);
	cout<<result<<endl;
    }
    return true;
}

bool Chapter17_test::Problem_8_test(){
    Chapter17 chapter17;
    int array[4][7]={{1,2,-2,3,3,-10,2},{0,8,-3,-3,100,-2,9},{3,8,0,-1,-8,10,-100}, {9,-10,-8,99,12,11,100}
    };
    int correctResult[4]={7, 109, 12, 222};
    int (*rowPointer)[7] = array;
    for(size_t i=0; i<4; ++i){
	vector<int> newInput(*rowPointer, *rowPointer+7);
	int result = chapter17.Problem_8(newInput);
	if(result!=correctResult[i])
	    return false;
	++rowPointer;
    }
    return true;
}

bool Chapter17_test::Problem_13_test(){
    Chapter17 chapter17;
    BiNode *root = new BiNode(10);
    root->node1 = new BiNode(0);
    root->node2 = new BiNode(18);
    root->node1->node1 = new BiNode(-2);
    root->node1->node2 = new BiNode(8);
    root->node2->node2 = new BiNode(22);
    int correctResult[] = {-2, 0, 8, 10, 18, 22};
    BiNode *head, *tail;
    chapter17.Problem_13(root, head, tail);
    size_t i=0;
    for(BiNode *curr = head; curr!=NULL; curr=curr->node2){
	if(curr->value!=correctResult[i])
	    return false;
	++i;
    }
    i=5;
    for(BiNode *curr = tail; curr!=NULL; curr=curr->node1){
	if(curr->value!=correctResult[i])
	    return false;
	--i;
    }
    return true;  
}

bool Chapter17_test::Problem_14_test(){
}

int main(){
    Chapter17_test testor;
    
    //Problem 3
    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;

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

     
     //Problem 13
     if(!testor.Problem_13_test())
	cout<<"Test 13 Failed!!!!!"<<endl;
     else
	cout<<"Test 13 Passed!"<<endl;
    return 0;
}
