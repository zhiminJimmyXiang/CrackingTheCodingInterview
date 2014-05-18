#include "../DataStructure/DataStructure.h"

class Box{
 public:
    int height;
    int width;
    int depth;
    bool above(const Box &box) const;
};


class Chapter9{
 private:
    bool DFSSearch(const vector<vector<int> > &graph, vector<vector<bool> > &visited, vector<pair<int, int> > &path, int i, int j);
    int searchMagicNumDistinct(const vector<int> &A, unsigned start, unsigned end);
    int searchMagicNumSame(const vector<int> &A, unsigned start, unsigned end);
    void getAllSubset(const vector<int> & wholeSet, int i, vector<vector<int> > &results);
    void computePermutation(const string &oriStr, int i, list<string> &preResults);
    void printParenthese(int n, int leftNum, int rightNum, string &currResult);
    void paintFill(vector<vector<int> > &screen, int x, int y, int oriColor, int newColor);
    int calculateNumOfRepresenting(int n, const vector<int> &components, int i, vector<vector<int> > &prevResult);
    bool checkValid(int currPos, const vector<int> &preInput);
    void printEightQueens(int currRow, int size, vector<int> &preInput);
    int findMaxHeight(const vector<Box> &boxStack, int bottomIndex, map<int, int> &preResults);
    int countExpNum(const string &exp, bool result, map<pair<string, bool>,int> &preResult);

 public:
    int Problem_1(int n);
    void Problem_2(const vector<vector<int> > &graph, vector<pair<int, int> > &path);
    int Problem_3_distinct(const vector<int> & A);
    int Problem_3_same(const vector<int> &A);
    void Problem_4(const vector<int> & wholeSet, vector<vector<int> > &results);
    void Problem_5(const string &oriStr, list<string> &results);
    void Problem_6(int n);
    void Problem_7(vector<vector<int> > &screen, int x, int y, int newColor);
    int Problem_8(int n);
    void Problem_9();
    int Problem_10(const vector<Box> &boxStack);
    int Problem_11(const string &exp, bool result);
};

class Chapter9_test{
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
    bool Problem_8_test();
    bool Problem_9_test();
    bool Problem_10_test();
    bool Problem_11_test();
};
