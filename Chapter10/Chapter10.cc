#include "Chapter10.h"

/*
Problem 1
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted orde
*/

void Chapter10::Problem_1(int A[], int lenA, int B[], int lenB){
    int posA = lenA-1, posB = lenB-1, posMerge = lenA+lenB-1;
    while(posA>=0 && posB>=0){
	if(A[posA]>=B[posB]){
	    A[posMerge] = A[posA];
	    --posA;
	}
	else{
	    A[posMerge] = B[posB];
	    --posB;
	}
	--posMerge;
    }
    while(posB>=0){
	A[posMerge]=B[posB];
	--posB;
	--posMerge;
    }
}

/*
Problem 2
Write a method to sort an array of strings so that all the anagrams are next to each other.
*/

string Chapter10::sortString(const string &inputStr){
    string outputStr = inputStr;
    sort(outputStr.begin(), outputStr.end());
    return outputStr;
}

void Chapter10::Problem_2(const vector<string> &inputStrArray, vector<string> &outputStrArray){
    map<string, vector<string> > strBucket;
    for(size_t i=0; i!=inputStrArray.size(); ++i){
	strBucket[sortString(inputStrArray[i])].push_back(inputStrArray[i]);
    }
    for(map<string, vector<string> >::iterator iter=strBucket.begin(); iter!=strBucket.end(); ++iter){
	for(size_t i=0; i<(iter->second).size(); ++i){
	    outputStrArray.push_back((iter->second)[i]);
	}
    }
    
}

/*
Problem 3
Given a sorted array of n integers that has been rotated an unknown number of
times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.
*/

int Chapter10::searchDistinct(const vector<int> &dataArray, int begin, int end, int x){
    if(begin>=end)
	return -1;
    int mid = (begin+end)/2;
    if(dataArray[mid]==x)
	return mid;
    
    if(dataArray[mid]>dataArray[end-1]){
	if(x>=dataArray[begin] && x<=dataArray[mid])
	    return searchNonDistinct(dataArray, begin, mid, x);
	else
	    return searchNonDistinct(dataArray, mid+1, end, x);
    }
    else if(dataArray[mid]<dataArray[end-1]){
	if(x>=dataArray[mid] && x<=dataArray[end-1])
	    return searchNonDistinct(dataArray, mid+1, end, x);
	else
	    return searchNonDistinct(dataArray, begin, mid, x);
    }
    
}

int Chapter10::Problem_3_distinct(const vector<int> &dataArray, int x){
    return searchDistinct(dataArray, 0, dataArray.size(), x);
}
int Chapter10::searchNonDistinct(const vector<int> &dataArray, int begin, int end, int x){
    if(begin>=end)
	return -1;
    int mid = (begin+end)/2;
    if(dataArray[mid]==x)
	return mid;
    
    if(dataArray[mid]>dataArray[end-1]){
	if(x>=dataArray[begin] && x<=dataArray[mid])
	    return searchNonDistinct(dataArray, begin, mid, x);
	else
	    return searchNonDistinct(dataArray, mid+1, end, x);
    }
    else if(dataArray[mid]<dataArray[end-1]){
	if(x>=dataArray[mid] && x<=dataArray[end-1])
	    return searchNonDistinct(dataArray, mid+1, end, x);
	else
	    return searchNonDistinct(dataArray, begin, mid, x);
    }
    else{
	int leftResult = searchNonDistinct(dataArray, begin, mid, x);
	if(leftResult!=-1)
	    return leftResult;
	int rightResult = searchNonDistinct(dataArray, mid+1, end, x);
	return rightResult;
    }
}

int Chapter10::Problem_3_nondistinct(const vector<int> &dataArray, int x){
    return searchNonDistinct(dataArray, 0, dataArray.size(), x);
}


/*
Problem 5
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string
*/

int Chapter10::searchStr(const vector<string> &strVect, int begin, int end, const string & xStr){
    if(xStr=="")
	return -1;
    if(begin>=end)
	return -1;
    int mid = (begin+end)/2;
    int midLeft = mid;
    int midRight = mid;
    while(midLeft>=begin && strVect[midLeft]=="")
	--midLeft;
    while(midRight<end && strVect[midRight]=="")
	++midRight;
    if(midRight<end){
	if(xStr == strVect[midRight])
	    return midRight;
	else if(xStr.compare(strVect[midRight])>0)
	    return searchStr(strVect, midRight+1, end, xStr);
    }
    if(midLeft>=begin){
	if(xStr == strVect[midLeft])
	    return midLeft;
	else if(xStr.compare(strVect[midLeft])<0)
	    return searchStr(strVect, begin, midLeft, xStr);
    }
    return -1;
}




/*Problem 6
Given an M x N matrix in which each row and each column is sorted in ascending
order, write a method to find an element
*/

//complexity: O(M+N)
void Chapter10::searchTopRight(const vector<vector<int> > &matrix, int &rowOut, int &colOut, int x){
    int col = matrix[0].size()-1, row = 0;
    while(row<matrix.size() && col>=0){
	if(matrix[row][col]==x){
	    rowOut = row;
	    colOut = col;
	    return;
	}
	else if(matrix[row][col]>x)
	    --col;
	else
	    ++row;
    }
    rowOut = -1;
    colOut = -1;
    return;
}

void Chapter10::Problem_6(const vector<vector<int> > &matrix, int &rowOut, int &colOut, int x){
    searchTopRight(matrix, rowOut, colOut, x);
}

/*
Problem 7
A circus is designing a tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of
each person in the circus, write a method to compute the largest possible number
of people in such a tower.
*/

int Chapter10::getLargestNumDP(const vector<Person> &input, int bottom, vector<int> &preResult){
    if(preResult[bottom]!=-1)
	return preResult[bottom];
    int maxNum = 0;
    for(size_t i=0; i<input.size(); ++i){
	if(input[i].weight<input[bottom].weight && input[i].height<input[bottom].height){
	    int currNum = getLargestNumDP(input, i, preResult);
	    maxNum = max(maxNum, currNum);
	}	    
    }
    preResult[bottom] = maxNum+1;
    return maxNum+1;
}

int Chapter10::Problem_7_DP(const vector<Person> &input){
    vector<int> preResult(input.size(), -1);
    int maxNum = 0;
    for(size_t i=0; i<input.size(); ++i){
	int currNum = getLargestNumDP(input, i, preResult);
	maxNum = max(maxNum, currNum);
    }
    return maxNum;
}

bool Chapter10::myFunction(const Person &x, const Person &y){
    return x.height<y.height;
}

int Chapter10::Problem_7_sort(const vector<Person> &input){
    if(input.empty())
	return 0;
    vector<Person> tempInput(input);
    sort(tempInput.begin(), tempInput.end(),myFunction);
    //int maxNum = 1, preLength = 1, prevWeight = input[0].weight;
    vector<int> numEachPos(input.size(), 0);
    for(size_t i=1; i<input.size(); ++i){
	int maxNum = 0;
	for(size_t j=0; j<i; ++j){
	    if(input[i].weight>input[j].weight)
		maxNum = max(maxNum, numEachPos[j]+1);
	}
	numEachPos[i] = maxNum;
    }
    return numEachPos.back()+1;
}

/*Problem 8
  Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a number x (the number of values less than or equal tox).
Implement the data structures and algorithms to support these operations.That
is, implement the method track(int x), which is called when each number
is generated, and the method getRankOfNumber(int x), which returns the
number of values less than or equal to x (not including x itself).
 */

void Problem_8::track(int x){
    if(root==NULL){
	root = new BTreeRank();
	root->value = x;
	return;
    }
    BTreeRank *curr = root, *prev = NULL;
    while(curr!=NULL){
	prev = curr;
	if(x<=curr->value){
	    (curr->leftNum)+=1;
	    curr = curr->left;
	}
	else
	    curr = curr->right;
    }
    if(x<=prev->value){
	prev->left = new BTreeRank();
	prev->left->value = x;
    }
    else{
	prev->right = new BTreeRank();
	prev->right->value = x;
    }
}

int Problem_8::getRank(int x){
    int sumNum = 0;
    BTreeRank *curr = root;
    while(curr!=NULL && curr->value!=x){
	if(x<curr->value)
	    curr = curr->left;
	else{
	    sumNum+=(curr->leftNum+1);
	    curr = curr->right;
	}
    }
    if(curr==NULL)
	return -1;
    else{
	sumNum+=curr->leftNum;
    }
    return sumNum;
}





