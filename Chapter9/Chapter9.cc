#include "Chapter9.h"


/*Problem 1
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.
*/
int Chapter9::Problem_1(int n){
    if(n<0)
	return 0;
    if(n==0)
	return 1;
    vector<int> numSteps(n+1, 1);
    for(int i=1; i<=n; ++i){
	int threeStepsBeforeNum = (i-3>=0?numSteps[i-3]:0);
	int twoStepsBeforeNum = (i-2>=0?numSteps[i-2]:0);
	int oneStepsBeforeNum = (i-1>=0?numSteps[i-1]:0);
	numSteps[i] = oneStepsBeforeNum+twoStepsBeforeNum+threeStepsBeforeNum;
    } 
    return numSteps[n];
}

/*Problem 2
Imagine a robot sitting on the upper left comer of an X by Ygrid. The robot can only move in two directions: right and down. How many possible paths are there for the robot to go from (0, 0) to (X, Y) ?
FOLLOW UP
Imagine certain spots are "off limits," such that the robot cannot step on them.
Design an algorithm to find a path for the robot from the top left to the bottom right.
*/

bool Chapter9::DFSSearch(const vector<vector<int> > &graph, vector<vector<bool> > &visited, vector<pair<int, int> > &path, int i, int j){
    if(i==graph.size()-1 && j==graph[0].size()-1){
	path.push_back(make_pair(i, j));
	return true;
    }

    if(visited[i][j]==true)
	return false;

    path.push_back(make_pair(i, j));
    visited[i][j]==true;
    bool tempResult = false;
    if(i<graph.size()-1 && graph[i+1][j]==0)
	tempResult = DFSSearch(graph, visited, path, i+1, j);
    if(tempResult)
	return true;
    if(j<graph[0].size()-1 && graph[i][j+1]==0)
	tempResult = DFSSearch(graph, visited, path, i, j+1);
    if(tempResult)
	return true;
    path.pop_back();
    return false;
}

void Chapter9::Problem_2(const vector<vector<int> > &graph, vector<pair<int, int> > &path){
    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    DFSSearch(graph, visited, path, 0, 0);
}

/*Problem 3
A magic index in an array A[l.. .n-l] is defined to be an index such that A[i] =
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
FOLLOW UP
What if the values are not distinct?
*/


int Chapter9::searchMagicNumDistinct(const vector<int> &A, unsigned start, unsigned end){
    if(start==end)
	return -1;
    unsigned middle = (start+end)/2;
    if(A[middle]==middle)
	return middle;
    if(A[middle]<middle)
	return searchMagicNumDistinct(A, middle+1, end);
    if(A[middle]>middle)
	return searchMagicNumDistinct(A, start, middle);
}

int Chapter9::Problem_3_distinct(const vector<int> & A){
    return searchMagicNumDistinct(A, 0, A.size());
} 


int Chapter9::searchMagicNumSame(const vector<int> &A, unsigned start, unsigned end){
    if(start==end)
	return -1;
    unsigned middle = (start+end)/2;
    if(A[middle]==middle)
	return middle;
    if(A[middle]>middle){
	int leftValue = searchMagicNumSame(A, start, middle);
	if(leftValue!=-1)
	    return leftValue;
	int rightValue = searchMagicNumSame(A, A[middle], end);
	return rightValue;
    }
    if(A[middle]<middle){
	int rightValue = searchMagicNumSame(A, middle+1, end);
	if(rightValue!=-1)
	    return rightValue;
	int leftValue = searchMagicNumSame(A, start, A[middle]+1);
	return leftValue;
    }
}

int Chapter9::Problem_3_same(const vector<int> &A){
    return searchMagicNumSame(A, 0, A.size());
}

/*Problem 4
Write a method to return all subsets of a set
*/



void Chapter9::getAllSubset(const vector<int> & wholeSet, int i, vector<vector<int> > &results){
    if(i==wholeSet.size()-1){
	vector<int> temp;
	results.push_back(temp);
	temp.push_back(wholeSet[i]);
	results.push_back(temp);
	return;
    }
    getAllSubset(wholeSet, i+1, results);
    unsigned originalSize = results.size();
    for(size_t j=0; j!=originalSize; ++j){
	vector<int> temp(results[j].begin(), results[j].end());
	temp.push_back(wholeSet[i]);
	results.push_back(temp);
    }
}

void Chapter9::Problem_4(const vector<int> & wholeSet, vector<vector<int> > &results){
    getAllSubset(wholeSet, 0, results);
}

/*Problem 5
Write a method to compute all permutations of a string
*/

void Chapter9::computePermutation(const string &oriStr, int i, list<string> &preResults){
    if(i==oriStr.size()-1){
	preResults.push_back(string(1, oriStr[i]));
	return;
    }
    computePermutation(oriStr, i+1, preResults);
    size_t preSize = preResults.size();
    for(unsigned j=0; j<preSize; ++j){
	string temp = preResults.front();
	preResults.pop_front();
	for(size_t len = 0; len!=temp.size(); ++len){
	    preResults.push_back(temp.substr(0, len)+string(1, oriStr[i])+temp.substr(len, temp.size()-len));
	}
	preResults.push_back(temp+string(1, oriStr[i]));
    }
}
void Chapter9::Problem_5(const string &oriStr, list<string> &results){
    computePermutation(oriStr, 0, results);
}

/*Problem 6
Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n-pairs of parentheses.
 */

void Chapter9::printParenthese(int n, int leftNum, int rightNum, string &currResult){
    if(leftNum==n && rightNum==n){
	cout<<currResult<<endl;
	return;
    }
    if(leftNum<n){
	currResult = currResult + string(1, '(');
	printParenthese(n, leftNum+1, rightNum, currResult);
        currResult=currResult.substr(0, currResult.size()-1);
    }
    if(rightNum<leftNum){
	currResult = currResult + string(1, ')');
	printParenthese(n, leftNum, rightNum+1, currResult);
	currResult=currResult.substr(0, currResult.size()-1);
    }
}
 
void Chapter9::Problem_6(int n){
    string currResult;
    printParenthese(n, 0, 0, currResult);
}


/*Problem 7
Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color
*/

void Chapter9::paintFill(vector<vector<int> > &screen, int x, int y, int oriColor, int newColor){
    if(x<0 || x>=screen[0].size() || y<0 || y>=screen.size())
	return;
    if(screen[y][x]==oriColor){
	screen[y][x]=newColor;
	paintFill(screen, x+1, y, oriColor, newColor);
	paintFill(screen, x-1, y, oriColor, newColor);
	paintFill(screen, x, y+1, oriColor, newColor);
	paintFill(screen, x, y-1, oriColor, newColor);
    }
}

void Chapter9::Problem_7(vector<vector<int> > &screen, int x, int y, int newColor){
    paintFill(screen, x, y, screen[y][x], newColor);
}

/*Problem 8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents)
and pennies (1 cent), write code to calculate the number of ways of representing n cents.
*/

int Chapter9::calculateNumOfRepresenting(int n, const vector<int> &components, int i, vector<vector<int> > &prevResult){
   
    if(n==0)
	return 1;
    if(prevResult[n][i]!=-1)
	return prevResult[n][i];
    if(i==components.size()-1){
	prevResult[n][i]=1;
	return 1;
    }
    int cent = components[i];
    int totalNum = 0;
    for(size_t j=0; j<=n/cent; ++j){
	totalNum+=calculateNumOfRepresenting(n-j*cent, components, i+1, prevResult); 
    }
    prevResult[n][i]=totalNum;
    return totalNum;
}

int Chapter9::Problem_8(int n){
    int components[]={25, 10, 5, 1};
    vector<int> componentsArray(components, components+4);
    vector<vector<int> >prevResult(n+1, vector<int>(5, -1));
    return calculateNumOfRepresenting(n, componentsArray, 0, prevResult);
}

/*Problem 9
Write an algorithm to print all ways of arranging eight queens on an 8x8 chess
board so that none of them share the same row, column or diagonal. In this case,
"diagonal" means all diagonals, not just the two that bisect the board.
*/

bool Chapter9::checkValid(int currPos, const vector<int> &preInput){
    for(size_t j=0; j<preInput.size(); ++j){
	if(currPos==preInput[j]||(currPos-preInput[j]==preInput.size()-j) || (currPos-preInput[j]==j-preInput.size()))
	    return false;
    }
    return true;
}

void Chapter9::printEightQueens(int currRow, int size, vector<int> &preInput){
    if(currRow==size){
	for(size_t j=0; j<preInput.size(); ++j)
	    cout<<preInput[j]<<" "<<flush;
	cout<<endl;
	return;
    }

    for(size_t j=0; j<size; ++j){
	if(checkValid(j, preInput)){
	    preInput.push_back(j);
	    printEightQueens(currRow+1, size, preInput);
	    preInput.pop_back();
	}
    }
    
}

void Chapter9::Problem_9(){
    vector<int> preInput;
    printEightQueens(0, 8, preInput);
}

/*Problem 10

You have a stack of n boxes, with widths w1, heights l1 and depths d1. The boxes
cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to build the tallest stack possible, where the heigh t of a stack is the sum of the heights of each box.
*/

int Chapter9::findMaxHeight(const vector<Box> &boxStack, int bottomIndex, map<int, int> &preResults){
    if(preResults.find(bottomIndex)!=preResults.end()){
	return preResults[bottomIndex];
    }
    int maxHeight = 0;
    for(size_t i=0; i<boxStack.size(); ++i){
	if(boxStack[i].above(boxStack[bottomIndex])){
	    maxHeight = max(maxHeight, findMaxHeight(boxStack, i, preResults));
	}
    }
    preResults[bottomIndex] = maxHeight+boxStack[bottomIndex].height;
    return preResults[bottomIndex];
}

int Chapter9::Problem_10(const vector<Box> &boxStack){
    int height = 0;
    map<int, int> preResults;
    for(size_t i=0; i<boxStack.size(); ++i){
	height = max(height, findMaxHeight(boxStack, i, preResults)); 
    }
    return height;
}


/*Problem 11
Given a boolean expression consisting of the symbols 0,1, &, |, and ^ , and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.
*/

int Chapter9::countExpNum(const string &exp, bool result, map<pair<string, bool>, int> &preResult){
   
    if(exp.empty())
	return 1;
    if((exp=="1" && result) ||  (exp=="0" && !result))
	return 1;
    if((exp=="1" && !result) ||  (exp=="0" && result))
	return 0;
    if(preResult.find(make_pair(exp, result))!=preResult.end())
	return preResult[make_pair(exp, result)];
    int totalNum = 0;
    for(size_t len=1; len<=exp.size()-2; len+=2){
	int tempNum = 0;
	char op = exp[len];
	if(op=='&'){
	    if(result){
		tempNum = countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult);
	    }
	    else{
		tempNum =  countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult)+countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult)+ countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult);
	    }
	}

	else if(op == '|'){
	    if(result){
		tempNum =  countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult)+countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult)+ countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult);
	    }
	    else{
		tempNum = countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult);
	    }
	}
	else if(op == '^'){
	    if(result){
		tempNum =  countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult)+countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult);
	    }
	    else{
		tempNum =  countExpNum(exp.substr(0, len), true, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), true, preResult)+countExpNum(exp.substr(0, len), false, preResult)*countExpNum(exp.substr(len+1, exp.size()-len-1), false, preResult);
	    }
	}
	totalNum += tempNum;
    }
    preResult[make_pair(exp, result)]=totalNum;
    return totalNum;
}

int Chapter9::Problem_11(const string &exp, bool result){
    map<pair<string, bool>, int> preResult;
    return countExpNum(exp, result, preResult);
}
