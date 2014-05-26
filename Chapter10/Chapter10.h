#include "../DataStructure/DataStructure.h"

class Person{
 public:
    int weight;
    int height;
    Person():height(0), weight(0){};
};

class BTreeRank{
 public:
    int value;
    int leftNum;
    BTreeRank *left;
    BTreeRank *right;
    BTreeRank():value(0),leftNum(0),left(NULL),right(NULL){};
};

class Problem_8{
 public:
    BTreeRank *root;
    Problem_8():root(NULL){};
    void track(int x);
    int getRank(int x);
};


class Chapter10{
 public:
    void Problem_1(int A[], int lenA, int B[], int lenB);
    string sortString(const string &inputStr);
    void Problem_2(const vector<string> &inputStrArray, vector<string> &outputStrArray);
    int searchDistinct(const vector<int> &dataArray, int begin, int end, int x);
    int Problem_3_distinct(const vector<int> &dataArray, int x);
    int searchNonDistinct(const vector<int> &dataArray, int begin, int end, int x);
    int Problem_3_nondistinct(const vector<int> &dataArray, int x);
    int searchStr(const vector<string> &strVect, int begin, int end, const string & xStr);
    void searchTopRight(const vector<vector<int> > &matrix, int &rowOut, int &colOut, int x);
    void Problem_6(const vector<vector<int> > &matrix, int &rowOut, int &colOut, int x);
    int getLargestNumDP(const vector<Person> &input, int bottom, vector<int> &preResult);
    int Problem_7_DP(const vector<Person> &input);
    static bool myFunction(const Person &x, const Person &y);
    int Problem_7_sort(const vector<Person> &input);
    
};
class Chapter10_test{
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
    bool Problem_8_test();
};






