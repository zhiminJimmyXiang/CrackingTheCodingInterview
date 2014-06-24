#include "../DataStructure/DataStructure.h"

typedef vector<vector<vector<vector<int> > > > MAXSUMSTORAGE;

class Chapter18{
 public:
    int add(int a, int b, int carry);
    int Problem_1(int a, int b);
    unsigned computeResult(unsigned residual, unsigned factor, unsigned i, unsigned preResult);
    unsigned Problem_4(unsigned a);
    int Problem_5(const vector<string> &strVector, const string &str1, const string &str2);
    bool checkCombination(const string &str, bool flag, const set<string> &strSet);
    string Problem_7(const set<string> &strSet);
    bool Problem_8(const string &s, const string &t);
    void Problem_9(const vector<int> &inputIntStream, vector<int> &outputMedianValues);
    bool checkOneLetterChange(const string &str1, const string &str2);
    bool DFS(const string &strStart, const string &strEnd, const set<string> &dict, vector<string> &path, set<string> &visitedStrings);
    void Problem_10(const string &strStart, const string &strEnd, const set<string> &dict, vector<string> &path);
    unsigned Problem_11(const MATRIX &matrix);
    bool findSubspuares(const vector<vector<pair<int, int> > > &matrixPreknowledge, unsigned subsquareLen);
    bool isSquare(const vector<vector<pair<int, int> > > &matrixPreknowledge, unsigned row, unsigned col, unsigned subsquareLen);
    void preprocessMatrix(const MATRIX &matrix, vector<vector<pair<int, int> > > &matrixPreknowledge);
    MAXSUMSTORAGE initializeStorage(int matrixSize);
    int maxSumOfMatrixDP(const MATRIX &matrix);
    int Problem_12_dynamic_program(const MATRIX &matrix);
    void getSumValueOfRowSegment(const MATRIX &matrix, vector<vector<int> > &oneRowSumValues, int rowNum, int colStart, int colEnd);
    void getRowSumValues(const MATRIX &matrix, vector<vector<vector<int> > > &rowsSumValues);
    int getMaxValue(const vector<vector<vector<int> > > &rowsSumValues, int matrixSize);
    int maxSumOfMatrixRowColumn(const MATRIX &matrix);
    int Problem_12_max_row_column(const MATRIX &matrix)
};

class Chapter18_test{
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
    bool Problem_12_test();
    bool Problem_13_test();
    bool Problem_14_test();
    
};

class Problem_9_DataStructure{
 public:
    priority_queue<int, vector<int>, greater<int> > smallValues;
    priority_queue<int> largeValues;
    int getMedianValue();
    void insertValue(int v);
};


