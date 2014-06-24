#include "Chapter18.h"

/*
Problem 1
Write a function that adds two numbers. You should not use + or any arithmetic
operators
*/

int Chapter18::add(int a, int b, int carry){
    if(a==0 && b==0)
	return carry;
    int tempA = (a&1), tempB = (b&1);
    int tempResult =  (tempA^tempB^carry);
    carry = ((((tempA|tempB|carry)==1) && ((tempA|tempB==1)||(tempA|carry==1)||(tempB|carry==1)))?1:0);
    a=a>>1;
    b=b>>1;
    int restResult = add(a, b, carry);
    int result = ((restResult<<1)|tempResult);
    return result;
}

int Chapter18::Problem_1(int a, int b){
    return add(a,b,0);
}

/*
Problem 4
Write a method to count the number of 2s that appear in all the numbers
between 0 and n (inclusive).
*/
unsigned Chapter18::computeResult(unsigned residual, unsigned factor, unsigned i, unsigned preResult){
    preResult += (factor*i);
    if(residual>=(3*i-1))
	preResult+=i;
    else if(residual>=2*i)
	preResult+=(residual%(2*i)+1);
    return preResult;
}

unsigned Chapter18::Problem_4(unsigned a){
    unsigned i=10, factor=a/i, result=0, res=a%i;
    bool flag = false;
    while(factor!=0){
	result = computeResult(res, factor i/10, result);
	if(UINT_MAX/10>=i){
	    i=i*10;
	    factor=a/i;
	    res=a%i;
	}
	else{
	    flag=true;
	    res=a;
	    break;
	}
    }
    if(flag){
	result = computeResult(res, 0, i, result);
    }
    else
	result = computeResult(res, 0, i/10, result);
    return result;
}

/*
Problem 5
You have a large text file containing words. Given any two words, find the
shortest distance (in terms of number of words) between them in the file. If the
operation will be repeated many times for the same file (but different pairs of
words), can you optimize your solution?
*/

int Chapter18::Problem_5(const vector<string> &strVector, const string &str1, const string &str2){
    int posStr1=-1, posStr2=-1, minDistance = INT_MAX;
    for(size_t i=0; i<strVector.size(); ++i){
	if(strVector[i]==str1){
	    posStr1 = i;
	    if(posStr2>=0)
		minDistance = min(minDistance, posStr1-posStr2);
	}
	else if(strVector[i]==str2){
	    posStr2 = i;
	    if(posStr1>=0)
		minDistance = min(minDistance, posStr2-posStr1);
	}
    }
    return minDistance;
}

/*
Problem 7
Given a list of words, write a program to find the longest word made of other
words in the list
*/
bool Chapter18::checkCombination(const string &str, bool flag, const set<string> &strSet){
    if(flag==false && strSet.find(str)!=strSet.end())
	return true;
    if(str.empty())
	return false;
    for(size_t i=1; i!=str.size(); ++i){
	if(strSet.find(string(str.begin(), str.begin()+i))!=strSet.end()){
	    bool resultSecond = checkCombination(string(str.begin()+i, str.end()), false, strSet);
	    if(resultSecond)
		return true;
	}
    }
    return false;
}

string Chapter18::Problem_7(const set<string> &strSet){
    string result;
    for(set<string>::iterator iter=strSet.begin(); iter!=strSet.end(); ++iter){
	if(checkCombination(*iter, true, strSet) && iter->size()>result.size())
	    result = *iter;
    }
    return result;
}

/*
Problem 8
Given a string s and an array of smaller strings T, design a method to search s
for each small string in T.
*/

bool Chapter18::Problem_8(const string &s, const string &t){
    SuffixTree sfTree(s);
    return sfTree.searchString(t);
}

/*
Problem 9
Numbers are randomly generated and passed to a method. Write a program to
find and maintain the median value as new values are generated.
*/
int Problem_9_DataStructure::getMedianValue(){
    return largeVlaues.top();
}

void Problem_9_DataStructure::insertValue(int v){
    if(largeValues.empty()){
	largeValues.push(v);
	return;
    }
    if(largeValues.size()>smallValues.size()){
	if(v<=largeValues.top())
	    smallValues.push(v);
	else{
	    int temp = largeValues.top();
	    smallValues.push(temp);
	    largeValues.pop();
	    largeValues.push(v);
	}
    }
    else if(largeValues.size()==smallValues.size()){
	if(v>=smallValues.top())
	    largeValues.push(v);
	else{
	    int temp = smallValues.top();
	    largeValues.push(temp);
	    smallValues.pop();
	    smallValues.push(v);
	}
    }
}

void Chapter18::Problem_9(const vector<int> &inputIntStream, vector<int> &outputMedianValues){
    Problem_9_DataStructure twoQueues;
    for(size_t i=0; i!=inputIntStream.size(); ++i){
	twoQueues.insertValue(inputIntStream[i]);
	outputMedianValues.push_back(twoQueues.getMedianValue());
    }
}

/*
Problem 10
Given two words of equal length that are in a dictionary, write a method to
transform one word into another word by changing only one letter at a time.
The new word you get in each step must be in the dictionary.
*/

bool Chapter18::checkOneLetterChange(const string &str1, const string &str2){
    if(str1.size()!=str2.size())
	return false;
    bool changedFlag = false;
    for(size_t i=0; i!=str1.size(); ++i){
	if(str1[i]!=str2[i]){
	    if(changedFlag)
		return false;
	    else
		changedFlag = true;
	}
    }
    return changedFlag;
}

bool Chapter18::DFS(const string &strStart, const string &strEnd, const set<string> &dict, vector<string> &path, set<string> &visitedStrings){
    if(checkOneLetterChange(strStart, strEnd)){
	path.push_back(strEnd);
	return true;
    }
    for(set<string>::iterator iter=dict.begin(); iter!=dict.end(); ++iter){
	if(visitedStrings.find(*iter)==visitedStrings.end() && checkOneLetterChange(strStart, *iter)){
	    path.push_back(*iter);
	    visitedStrings.insert(*iter);
	    bool temp = DFS(*iter, strEnd, dict, path);
	    if(temp)
		return true;
	    else{
		path.pop_back();
	    }
	}
    }
    return false;
}

void Chapter18::Problem_10(const string &strStart, const string &strEnd, const set<string> &dict, vector<string> &path){
    set<string> visitedStrings;
    DFS(strStart, strEnd, dict, path, visitedStrings);
}

/*
Problem 11
Imagine you have a square matrix, where each cell (pixel) is either black or white.
Design an algorithm to find the maximum subsquare such that all four borders are
filled with black pixels.
*/

unsigned Chapter18::Problem_11(const MATRIX &matrix){
    vector<vector<pair<int, int> > > matrixPreknowledge;
    preprocessMatrix(matrix, matrixPreknowledge);
    unsigned matrixSize = matrix.size();
    for(size_t i=matrixSize; i!=0; --i){
	bool temp = findSubsquares(matrixPreknowledge, i);
	if(temp)
	    return i;
    }
    return 0;
}

bool Chapter18::findSubspuares(const vector<vector<pair<int, int> > > &matrixPreknowledge, unsigned subsquareLen){
    unsigned matrixSize = matrixPreknowledge.size();
    unsigned rowNum = matrixSize-i+1, colNum = rowNum;
    for(size_t i=0; i!=rowNum; ++i){
	for(size_t j=0; j!=colNum; ++j){
	    if(isSquare(matrixPreknowledge, i, j, subsquareLen))
		return true;
	}
    }
    return false;
}

bool Chapter18::isSquare(const vector<vector<pair<int, int> > > &matrixPreknowledge, unsigned row, unsigned col, unsigned subsquareLen){
    if((matrixPreknowledge[row][col].first>=subsquareLen && matrixPreknowledge[row][col].second>=subsquareLen) && (matrixPreknowledge[row][col+subsquareLen-1].second>=subsquareLen) && (matrixPreknowledge[row+subsquareLen-1][col].first>=subsquareLen))
	return true;
    return false;
}

void Chapter18::preprocessMatrix(const MATRIX &matrix, vector<vector<pair<int, int> > > &matrixPreknowledge){
    int matrixSize = matrix.size();
    for(int i=matrixSize-1; i>=0; --i){
	for(int j=matrixSize-1; j>=0; --j){
	    if(matrix[i][j]==0){ //white pixel
		matrixPreknowledge[i][j].first = 0;
		matrixPreknowledge[i][j].second = 0;
	    }
	    else{
		//first value for border length to right edge
		matrixPreknowledge[i][j].first = (j==matrixSize-1?1:matrixPreknowledge[i][j+1].first+1);
		//second value for border length to bottom edge
		matrixPreknowledge[i][j].second = (i==matrixSize-1?1:matrixPreknowledge[i+1][j].second+1);
	    }
	}
    }
}

/*
Problem 12
Given an NxN matrix of positive and negative integers, write code to find the
submatrix with the largest possible sum
*/

MAXSUMSTORAGE Chapter18::initializeStorage(int matrixSize){
    return MAXSUMSTORAGE(matrixSize, vector<vector<vector<int> > > (matrixSize, vector<vector<int> > (matrixSize, vector<int>(matrixSize, 0))));
}

int Chapter18::maxSumOfMatrixDP(const MATRIX &matrix){
    int matrixSize = matrix.size();
    MAXSUMSTORAGE maxMatrixStore = inializeStorage(matrixSize);
    int maxVal = INT_MIN;
    for(int i=matrixSize-1; i>=0; --i){
	for(int j=matrixSize-1; j>=0; --j){
	    for(size_t width=0; width!=matrixSize; ++width){
		for(size_t height = 0; height!=matrixSize; ++height){
		    
		    int rightMatrixVal=(j+width>=matrixSize?0:maxMatrixStore[i][j+1][width-1][height]);
		    int bottomMatrixVal=(i+height>=matrixSize?0:maxMatrixStore[i+1][j][width][height-1]);
		    int overlapMatrixVal=(j+width>=matrixSize||i+height>=matrixSize?0:maxMatrixStore[i+1][j+1][width-1][height+1]);
		    maxMatrixStore[i][j][width][height] = matrix[i][j]+rightMatrixVal+bottomMatrixVal-overlapMatrixVal;
		    maxVal = max(maxVal, maxMatrixStore[i][j][width][height]);
		}
	    }
	}
    }
    return maxVal;
}

int Chapter18::Problem_12_dynamic_program(const MATRIX &matrix){
    return maxSumOfMatrixDP(matrix);
}


void Chapter18::getSumValueOfRowSegment(const MATRIX &matrix, vector<vector<int> > &oneRowSumValues, int rowNum, int colStart, int colEnd){
    if(colEnd==colStart)
	return matrix[rowNum][colStart];
    return oneRowSumValues[colStart][colEnd-1]+matrix[colStart][colEnd];
}

void Chapter18::getRowSumValues(const MATRIX &matrix, vector<vector<vector<int> > > &rowsSumValues){
    for(size_t rowNum=0; rowNum!=matrix.size(); ++rowNum){
	for(size_t colStart=0; colStart!=matrix.size(); ++colStart){
	    for(size_t colEnd=colStart; colEnd!=matrix.size(); ++colEnd){
		rowsSumValues[rowNum][colStart][colEnd] = getSumValueOfRowSegment(matrix, rowsSumValues[rowNum], rowNum, colStart, colEnd);
	    }
	}
    }
}

int Chapter18::getMaxValue(const vector<vector<vector<int> > > &rowsSumValues, int matrixSize){
    int maxValue = INT_MIN;
    for(size_t colStart=0; colStart!=matrixSize; ++colStart){
	for(size_t colEnd=colStart; colEnd!=matrixSize; ++colEnd){
	    vector<int> maxColumnValues(matrixSize, 0);
	    maxColumnValues[0]=rowsSumValues[0][colStart][colEnd];
	    for(size_t rowNum = 1; rowNum!=matrixSize; ++rowNum){
		maxColumnValues[rowNum] = (maxColumnValues[rowNum-1]>=0?maxColumnValues[rowNum-1]+rowsSumValues[rowNum][colStart][colEnd]:rowsSumValues[rowNum][colStart][colEnd]);
		maxValue = max(maxValue, maxColumnValues[rowNum]);
	    }
	}
    }
    return maxValue;
}

int Chapter18::maxSumOfMatrixRowColumn(const MATRIX &matrix){
    int matrixSize = matrix.size();
    vector<vector<vector<int> > > rowsSumValues(matrixSize, vector<vector<int> >(matrixSize, vector<int>(matrixSize, 0)));
    getRowMaxValues(matrix, rowsSumValues);
    return getMaxValue(maxRowValues, matrixSize);
}

int Chapter18::Problem_12_max_row_column(const MATRIX &matrix){
    return maxSumOfMatrixRowColumn(matrix);
}







