#include "Chapter5.h"

/*Problem 1
You are given two 32-bit numbers, N andM, and two bit positions, i and j. Write a
method to insert M into N such that M starts at bit j and ends at bit i. You can assume
that the bits j through i have enough space to fit all of M. That is, i fM= 10011,
you can assume that there are at least 5 bits between j and i. You would not, for
example, have j=3 and i=2, because M could not fully fit between bit 3 and bit 2.
*/
unsigned Chapter5::Problem_1(unsigned M, unsigned N, unsigned i, unsigned j){
    unsigned numBits = j-i+1;
    unsigned mask = ~(((1<<numBits)-1)<<i);
    N&=mask;
    M<<=i;
    return M | N;
}

/*Problem 2
Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
the binary representation. If the number cannot be represented accurately in binary
with at most 32 characters, print "ERROR."
*/
string Chapter5::Problem_2(double input){
    if(input==0)
	return string(1, '0');
    string result="0.";
    int count = 0;
    double i=0.5;
    while(count<32 && input!=0){
	if(input>=i){
	    input = input-i;
	    result=result+"1";
	}
	else
	    result = result+"0";
	i/=2;
	++count;
    }
    if(input!=0)
	return "ERROR";
    else
	return result;
}


/*Problem 3
  Given a positive integer, print the next smallest and the next largest number that
have the same number of 1 bits in their binary representation.
 */

unsigned Chapter5::findPreviousSmallest(unsigned input){
    bool flagEven = (input%2==0?true:false);
    bool flagZero = false;
    unsigned posZero(0), countOne(0);
    unsigned data = input;
    while((flagZero==false || data%2==0) && (data!=0)){
	if(data%2==0)
	    flagZero = true;
	else
	    ++countOne;
	data>>=1;
	++posZero;
    }
    if(data==0)
	return 0;
    
    unsigned mask = 3<<(posZero-1);
    input = input ^ mask;
    if(flagEven)
	return input;
    mask = (1<<countOne)-1;
    input  = input &(~mask);
    mask<<=(posZero-countOne-1);
    return input | mask;
}

unsigned Chapter5::findNextLargest(unsigned input){
    input = input ^ UINT_MAX;
    unsigned result = findPreviousSmallest(input);
    if(result==0)
	return result;
    return result^UINT_MAX;
}


/*
Problem 5
Write a function to determine the number of bits required to convert integer A to
integer B.
*/

unsigned Chapter5::Problem_5(unsigned a, unsigned b){
    unsigned count = 0;
    unsigned c = a^b;
    while(c!=0){
	if(c&1==1)
	    ++count;
	c>>=1;
    }
    return count;
}

unsigned Chapter5::Problem_5_1(unsigned a, unsigned b){
    unsigned count = 0;
    unsigned c = a^b;
    while(c!=0){
	++count;
	c=c&(c-1);
    }
    return count;
}

/*
Problem 6
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on
*/

unsigned Chapter5::Problem_6(unsigned a){
    return ((a&0x55555555)<<1) | ((a&0xAAAAAAAA)>>1);
}

/*
Problem 7
An array A contains all the integers from 0 through n, except for one number which is
missing. In this problem, we cannot access an entire integer in A with a single opera-
tion. The elements of A are represented in binary, and the only operation we can use
to access them is "fetch the jth bit ofA[i]," which takes constant time. Write code to
find the missing integer. Can you do it in 0(n) time?
*/

bool Chapter5::getBit(const vector<unsigned> &A, int currIndex, int bitPos){
    unsigned num = A[currIndex];
    if((num>>bitPos)&1==1)
	return true;
    return false;
}

unsigned Chapter5::Problem_7(unsigned n, const vector<unsigned> &A){
    list<unsigned> listZero;
    for(unsigned i=0; i<A.size(); ++i)
	listZero.push_back(i);
    list<unsigned> listOne;
    list<unsigned> *listPtr = &listZero;
    unsigned size = listPtr->size();
    unsigned result = 0;
    unsigned bitPos = 0;
    while(size>0){
	for(unsigned i=0; i<size; ++i){
	    unsigned currIndex = *(listPtr->begin());
	    if(getBit(A, currIndex, bitPos)){
		listOne.push_back(currIndex);
	    }
	    else{
		listZero.push_back(currIndex);
	    }
	    listPtr->pop_front();
	}
	if(size%2==0){
	    if(listOne.size()==listZero.size()){
		listPtr = &listZero;
		listOne.clear();
	    }
	    else{
		listPtr = &listOne;
		result+=1<<bitPos;
		listZero.clear();
	    }
	}
	else{
	    if(listOne.size()>listZero.size()){
		listPtr = &listZero;
		listOne.clear();
	    }
	    else{
		listPtr = &listOne;
		result+=1<<bitPos;
		listZero.clear();
	    }
	}
	bitPos+=1;
	size = listPtr->size();
    }
    return result;   
}


/*
Problem 8
A monochrome screen is stored as a single array of bytes, allowing eight consec-
utive pixels to be stored in one byte. The screen has width w, where w is divisible
by 8 (that is, no byte will be split across rows). The height of the screen, of course,
can be derived from the length of the array and the width. Implement a function
drawHorizontalLine(byte[] screen, int width, intxl, intx2, inty) which draws a hori-
zontal line from (x 1, y) to (x2, y).
*/


void Chapter5::Problem_8(vector<char> &screen, int width, int x1, int x2, int y){
    int byteX1 = x1/8;
    int byteX2 = x2/8;
    if(byteX1==byteX2){
	x1=x1%8;
	x2=x2%8;
	char mask=((1<<x2-x1+1)-1)<<(7-x2);
	screen[byteX1+y*width/8]|=mask;
    }
    else{
	for(int i=byteX1+y*width/8+1; i<y*width/8+byteX2; ++i)
	    screen[i]=0xFF;
	x1=x1%8;
	x2=x2%8;
	char maskX1 = (0xFF)>>x1;
	char maskX2 = (0xFF)<<(7-x2);
	screen[byteX1+y*width/8]|=maskX1;
	screen[byteX2+y*width/8]|=maskX2;
    }
    
}
