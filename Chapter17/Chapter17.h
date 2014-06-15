#include "../DataStructure/DataStructure.h"

struct BiNode{
    BiNode *node1;
    BiNode *node2;
    int value;
BiNode(int newValue):value(newValue), node1(NULL), node2(NULL){};
};

class Chapter17{
 public:
    int Problem_3(int n);
    int Problem_4(int a, int b);
    int getIndex(char c);
    int getHits(vector<int> &charNumArray, string &guessStr, const string &correctStr);
    int getPseudoHits(vector<int> &charNumArray, const string &guessStr);
    void Problem_5(const string &correctStr, const string &guessStr, int &hitCount, int &pseudoHitCount);
    int spanLeftPart(const vector<int> &array);
    int spanRightPart(const vector<int> &array);
    void getMiddlePartMinMaxValue(const vector<int> &array, int start, int end, int &minVal, int &maxVal);
    void updateMaxMinValue(int &minVal, int &maxVal, int newVal);
    void Problem_6(const vector<int> &array, int &leftIndex, int &rightIndex);
    string getDigitStr(int n);
    string getTenToNineteenStr(int n);
    string getTwentyToNinetyStr(int n);
    string createZeroToNineHundredNinetyNineStr(int n);
    string Problem_7(long long n);
    int Problem_8(const vector<int> &inputArray);
    int rand7();
    void convertTreeToLinkedList(BiNode *root, BiNode *&head, BiNode *&tail);
    void Problem_13(BiNode *root, BiNode *&head, BiNode *&tail);
    void createIndex(const set<string> &dict, vector<vector<int> > &index, const string &inputStr);
    int rand5();
    int Problem_14(const string &inputStr, const set<string> &dict, string &strOut);
    
};

class Chapter17_test{
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
