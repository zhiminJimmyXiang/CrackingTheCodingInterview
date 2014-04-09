#include "Chapter1.h"

/*
Problem 1:
Implement an algorithm to determine if a string has all unique characters. What if
you cannot use additional data structure
*/
bool Chapter1::Problem_1(const string &input){
    int ASCII_size = 128;
    vector<bool> bitmap(ASCII_size, false);
    for(unsigned i=0; i<input.size(); ++i){
	if(bitmap[input[i]]==true)
	    return false;
	else
	    bitmap[input[i]]=true;
    }
    return true;
}

/*
Problem 2: 
Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
*/
void Chapter1::Problem_2(char *str){
    int back = strlen(str)-1;
    int front = 0;
    while(front<back){
	char temp = str[front];
	str[front]=str[back];
	str[back]=temp;
	++front;
	--back;
    }
}

/*
Problem 3:
Given two strings, write a method to decide if one is a permutation of the other.
*/
//we assume that the character of string is 'a'-'z'
bool Chapter1::Problem_3(const string &str1st, const string &str2nd){
    vector<int> counter1st(26, 0);
    vector<int> counter2nd(26, 0);
    for(unsigned i=0; i<str1st.size(); ++i){
	if(str1st[i]<'a' || str1st[i]>'z')
	    return false;
	++counter1st[str1st[i]-'a'];
    }
    for(unsigned i=0; i<str2nd.size(); ++i){
	if(str2nd[i]<'a' || str2nd[i]>'z')
	    return false;
	++counter2nd[str2nd[i]-'a'];
    }
    for(unsigned i=0; i<26; ++i){
	if(counter1st[i]!=counter2nd[i])
	    return false;
    }
    return true;
}

/*Problem 4:
Write a method to replace all spaces in a string with '%20'. You may assume that the
string has sufficient space at the end of the string to hold the additional characters,
and that you are given the "true" length of the string
 */

void Chapter1::Problem_4(char str[], int len){
    int spaceSize = 0;
    for(int i=0; i<len; ++i){
	if(str[i]==' ')
	    ++spaceSize;
    }
    int i=len;
    while(spaceSize>0){
	if(str[i]!=' '){
	    str[i+2*spaceSize]=str[i];
	}
	else{
	    str[i+2*spaceSize]='0';
	    str[i+2*spaceSize-1]='2';
	    str[i+2*spaceSize-2]='%';
	    --spaceSize;
	}
	--i;
    }
}

/*Problem 5:
Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.*/

void Chapter1::Problem_5(const string &strIn, string &strOut){
    strOut.clear();
    if(strIn.size()==0){
	strOut.clear();
	return;
    }
    char pre = strIn[0];
    int count = 1;
    for(unsigned i=1; i<strIn.size(); ++i){
	if(strIn[i]!=pre){
	    strOut=strOut+string(1, pre);
	    strOut=strOut+String::positiveIntToString(count);
	    pre = strIn[i];
	    count = 1;
	}
	else
	    ++count;
    }
    strOut = strOut+string(1, pre);
    strOut=strOut+String::positiveIntToString(count);
    if(strOut.size()>=strIn.size())
	strOut = strIn;
}

/*Problem 6:
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/
void Chapter1::Problem_6(MATRIX &matrix){
    int N = matrix.size();
    if(N<=1)
	return;
    int numRound = N/2;
    for(int i=0; i<numRound; ++i){
	//for each inner round
	for(int j=i; j<N-i-1; ++j){
	    int temp = matrix[i][j];
	    matrix[i][j]=matrix[N-1-j][i];
	    matrix[N-1-j][i]=matrix[N-1-i][N-1-j];
	    matrix[N-1-i][N-1-j]=matrix[j][N-1-i];
	    matrix[j][N-1-i]=temp;
	}
    }
}

/*Problem 7:
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.
*/
void Chapter1::Problem_7(MATRIX &matrix){
    if(matrix.empty() || matrix[0].empty())
	return;
    vector<bool> rowFlag(matrix.size(), false);
    vector<bool> columnFlag(matrix[0].size(), false);
    for(unsigned int i=0; i<matrix.size(); ++i){
	for(unsigned int j=0; j<matrix[0].size(); ++j){
	    if(matrix[i][j]==0){
		rowFlag[i]=true;
		columnFlag[j]=true;
	    }
	}
    }
    for(unsigned int i=0; i<matrix.size(); ++i){
	for(unsigned int j=0; j<matrix[0].size(); ++j){
	    if(rowFlag[i] || columnFlag[j])
		matrix[i][j]=0;
	}
    }
}

/*Problem 8:
Assume you have a method isSubstring which checks if one word is a substring
of another. Given two strings, si and s2, write code to check if s2 is a rotation of s1
using only one call to isSubstring (e.g., "waterbottLe" is a rotation of "erbot-
tLewat").
*/






