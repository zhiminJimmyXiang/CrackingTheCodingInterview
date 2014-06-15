#include "Chapter17.h"

/*
Problem 3
Write an algorithm which computes the number of trailing zeros in n factorial.
*/
/*Idea:
the number of 5 is equal to the number of 0
*/
int Chapter17::Problem_3(int n){
    if(n<0)
	return -1;
    int count = 0;
    for(int i=5; n/i>0; i*=5){
	count += n/i;
    }
    return count;
}

/*
Problem 4
Write a method which finds the maximum of two numbers. You should not use
if-else or any other comparison operator
*/
/*Pay attention to overflow */

int Chapter17::Problem_4(int a, int b){
    int signA = ((unsigned)a>>31)-1,  signB = ((unsigned)b>>31)-1;
    int flag = (((unsigned)(a-b)>>31)-1);
    return (signA&~signB&a)|(~signA&signB&b)|(((signA&signB)|(~signA&~signB))&(flag&a)|(~flag&b));
    
}

/*
Problem 5
Write a method that, given a guess and a solution, returns the number of hits
and pseudo-hits
*/

int Chapter17::getIndex(char c){
    switch(c){
    case 'R':
	return 0;
    case 'Y':
	return 1;
    case 'G':
	return 2;
    case 'B':
	return 3;
    default:
	return -1;
    }
}

int Chapter17::getHits(vector<int> &charNumArray, string &guessStr, const string &correctStr){
    int count = 0;
    for(size_t i=0; i<min(guessStr.size(), correctStr.size()); ++i){
	if(guessStr[i]==correctStr[i]){
	    ++count;
	    --charNumArray[getIndex(guessStr[i])];
	    guessStr[i] = '0';
	}
    }
    return count;
}

int Chapter17::getPseudoHits(vector<int> &charNumArray, const string &guessStr){
    int count = 0;
    for(size_t i=0; i<guessStr.size(); ++i){
	int index = getIndex(guessStr[i]);
	if(index!=-1 && charNumArray[index]>0){
	    ++count;
	    --charNumArray[index];
	}
    }
    return count;
}

void Chapter17::Problem_5(const string &correctStr, const string &guessStr, int &hitCount, int &pseudoHitCount){
    string tempGuess(guessStr);
    vector<int> charNumArray(4, 0);
    for(size_t i=0; i<correctStr.size(); ++i){
	int index = getIndex(correctStr[i]);
	if(index==-1)
	    return;
	++charNumArray[index];
    }
  
    hitCount = getHits(charNumArray, tempGuess, correctStr);
    pseudoHitCount = getPseudoHits(charNumArray, tempGuess);
    return;
}




/*Problem 6
Given an array of integers, write a method to find indices m and n such that if you sorted elements m through n, the entire array would be sorted. Minimize n - m (that is, find the smallest such sequence).
*/

int Chapter17::spanLeftPart(const vector<int> &array){
    for(size_t i=0; i<array.size()-1; ++i){
	if(array[i+1]<array[i])
	    return i;
    }
    return -1;
}

int Chapter17::spanRightPart(const vector<int> &array){
    for(size_t i=array.size()-1; i>0; --i){
	if(array[i-1]>array[i])
	    return i;
    }
    return -1;
}

void Chapter17::getMiddlePartMinMaxValue(const vector<int> &array, int start, int end, int &minVal, int &maxVal){
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for(size_t i=start; i<end; ++i){
	if(array[i]<minVal)
	    minVal = array[i];
	if(array[i]>maxVal)
	    maxVal = array[i];
    }
}

void Chapter17::updateMaxMinValue(int &minVal, int &maxVal, int newVal){
    minVal = min(minVal, newVal);
    maxVal = max(maxVal, newVal);
}

void Chapter17::Problem_6(const vector<int> &array, int &leftIndex, int &rightIndex){
    leftIndex = 0;
    rightIndex = 0;
    int leftRange = spanLeftPart(array);
    if(leftRange == -1)
	return;
    int rightRange = spanRightPart(array);
    if(rightRange == -1)
	return;
    int minVal, maxVal;
    getMiddlePartMinMaxValue(array, leftRange+1, rightRange, minVal, maxVal);
    if(minVal == INT_MAX && maxVal ==  INT_MIN){
	minVal = array[leftRange];
	maxVal = array[leftRange];
	--leftRange;
    }
    while(!((leftRange<0 || minVal>=array[leftRange]) && (rightRange>=array.size()|| maxVal<=array[rightRange]))){
	if(leftRange>=0 && minVal<array[leftRange]){
	    updateMaxMinValue(minVal, maxVal, array[leftRange]);
	     --leftRange;
	}
	if(rightRange<array.size() && maxVal>array[rightRange]){
	    updateMaxMinValue(minVal, maxVal, array[rightRange]);
	     ++rightRange;
	}
    }
    leftIndex = leftRange+1;
    rightIndex = rightRange-1;
}

/*Problem 7
Given any integer, print an English phrase that describes the integer (e.g., "One Thousand, Two Hundred Thirty Four")
*/

string Chapter17::getDigitStr(int n){
    switch(n){
    case 1:
	return "one";
    case 2:
	return "two"; 
    case 3:
	return "three";
    case 4:
	return "four"; 
    case 5:
	return "five"; 
    case 6:
	return "six"; 
    case 7:
	return "seven"; 
    case 8:
	return "eight"; 
    case 9:
	return "nine"; 
    default:
	return "";
    }
}

string Chapter17::getTenToNineteenStr(int n){
     switch(n){
     case 10:
	 return "ten"; 
     case 11:
	 return "eleven"; 
     case 12:
	 return  "twelve"; 
     case 13:
	 return "third"; 
     case 14:
	 return "fourteen";
     case 15:
	 return "fifteen"; 
     case 16:
	 return "sixteen"; 
     case 17:
	 return "seventeen"; 
     case 18:
	 return "eighteen"; 
     case 19:
	 return "nineteen"; 
     default:
	 return "";
     }
}

string Chapter17::getTwentyToNinetyStr(int n){
    switch(n){
     case 20:
	 return "tweenty";
     case 30:
	 return "thirty"; 
     case 40:
	 return "fourty"; 
     case 50:
	 return "fifty"; 
     case 60:
	 return "sixty"; 
     case 70:
	 return "seventy";
     case 80:
	 return "eighty"; 
     case 90:
	 return "ninety"; 
     default:
	 return "";
     }
}

string Chapter17::createZeroToNineHundredNinetyNineStr(int n){
    string result;
    if(n>=100){
	result = getDigitStr(n/100)+" hundred ";
	n=n%100;
    }
    if(n>=20){
	result = result+getTwentyToNinetyStr(n-n%10)+" ";
	if(n%10>0)
	    result = result+getDigitStr(n%10)+" ";
    }
    else{
	if(n>=10)
	    result = result+getTenToNineteenStr(n)+" ";
	else if(n>0 || result=="")
	    result = result+getDigitStr(n)+" ";
    }
    return result;
}



string Chapter17::Problem_7(long long n){
    if(n==0)
	return "zero";
    string unitArray[] = {"million", "thousand"};
    long long intArray[] = {1000000, 1000};
    string result;
    for(size_t i=0; i<2 && n>0; ++i){
	if(n/intArray[i]>0){
	    result = result+createZeroToNineHundredNinetyNineStr(n/intArray[i])+unitArray[i]+" ";
	    n = n%intArray[i];
	}
    }
    if(n>0)
	result = result+createZeroToNineHundredNinetyNineStr(n);
    return result;
}

/*
Problem 8
You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.
*/

int Chapter17::Problem_8(const vector<int> &inputArray){
    if(inputArray.empty())
	return 0;
    int maxVal = inputArray[0], prevVal = inputArray[0];
    for(size_t i=1; i<inputArray.size(); ++i){
        if(prevVal>=0)
	    prevVal = prevVal+inputArray[i];
	else
	    prevVal = inputArray[i];
	maxVal = max(maxVal, prevVal);
    }
    return maxVal;
}

/*
Problem 11
Implement a method rand70 given randSQ- That is, given a method that generates
a random number between 0 and 4 (inclusive), write a method that generates a
random number between 0 and 6 (inclusive)
*/
int Chapter17::rand5(){
    return rand()%5;
}

int Chapter17::rand7(){
    int n = 5*rand5()+rand5();
    while(n>=21)
	n = 5*rand5()+rand5();
    return n%7;
}

/*
Problem 13
Implement a method
to convert a binary search tree (implemented with BiNode) into a doubly linked
list. The values should be kept in order and the operation should be performed
in place (that is, on the original data structure).
*/
void Chapter17::convertTreeToLinkedList(BiNode *root, BiNode *&head, BiNode *&tail){
    if(root==NULL){
	head = NULL;
	tail = NULL;
	return;
    }
    BiNode *leftHead(NULL), *leftTail(NULL);
    convertTreeToLinkedList(root->node1, leftHead, leftTail);
    root->node1 = leftTail;
    if(leftTail!=NULL)
	leftTail->node2 = root;
    BiNode *rightHead(NULL), *rightTail(NULL);
    convertTreeToLinkedList(root->node2, rightHead, rightTail);
    root->node2 = rightHead;
    if(rightHead!=NULL)
	rightHead->node1 = root;
    head = (leftHead==NULL?root:leftHead);
    tail = (rightTail==NULL?root:rightTail);
    return;
}

void Chapter17::Problem_13(BiNode *root, BiNode *&head, BiNode *&tail){
    convertTreeToLinkedList(root, head, tail);
}

/*
Problem 14
*/

int Chapter17::Problem_14(const string &inputStr, const set<string> &dict, string &outputStr){
    if(inputStr.empty()){
	outputStr = "";
	return 0;
    }
    vector<int> unmatchNumArray(inputStr.size()+1, 0);
    vector<int> spacePos(inputStr.size()+1, 0);
    for(size_t i=1; i<inputStr.size()+1; ++i){
	int minUnmatchNum = INT_MAX;
	for(int j=i-1; j>=0; --j){
	    int wordUnmatchNum = (dict.find(string(inputStr.begin()+j, inputStr.begin()+i))!=dict.end()?0:i-j);
	    int currUnmatchNum = wordUnmatchNum+unmatchNumArray[j];
	    if(currUnmatchNum<minUnmatchNum){
		minUnmatchNum = currUnmatchNum;
		spacePos[i] = j;
	    }
	}
	unmatchNumArray[i] = minUnmatchNum;
    }
    outputStr.clear();
    int startPos = spacePos.back(), endPos = inputStr.size();
    while(startPos!=0){
	outputStr = string(inputStr.begin()+startPos, inputStr.begin()+endPos)+" "+outputStr;
	endPos = startPos;
	startPos = spacePos[startPos];
    }
    outputStr = string(inputStr.begin(), inputStr.begin()+endPos)+" "+outputStr;
    outputStr = string(outputStr.begin(), outputStr.begin()+outputStr.size()-1);
    return unmatchNumArray.back();
    
}






