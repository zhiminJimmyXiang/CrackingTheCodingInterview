#include "../DataStructure/DataStructure.h"


class Chapter4{
 private:
    bool checkBalance(BTree *root, int &height);
    void buildBST(BTree *&root, const vector<int> & array, int startPos, int endPos);
    void createLinkedList(BTree *root, vector<list<BTree*> > &result, int height);
    bool checkBinaryTree(BTree *root, int &maxVal, int &minVal);
    BTreeParent* findLeftMostNode(BTreeParent *curr);
    BTreeParent *findLeftAncestor(BTreeParent *curr);

    BTree *findCommonAncestor(BTree *root, const BTree * &first, const BTree *& second, int &state);

    bool compareTrees(BTree *rootFirst, BTree *rootSecond);
    void printPath(const vector<int> &pathSum, int i);
    void findCorrectPath(BTree *root, int sum, vector<int> &pathSum);

 public:
    bool Problem_1(BTree *root);
    bool Problem_2_BFS(int source, int target, const Graph &graphInput);
    bool Problem_2_DFS(int source, int target, const Graph &graphInput);
    BTree * Problem_3(const vector<int> & array);
    void Problem_4(BTree *root, vector<list<BTree*> > &result);
    bool Problem_5(BTree *root);
    BTreeParent* Problem_6(BTreeParent *curr);
    BTree *Problem_7(BTree *root, const BTree * &first, const BTree *& second);
    bool Problem_8(BTree *largeTree, BTree *smallTree);
    void Problem_7(BTree *root, int sum);
};


class Chapter4_test{
 private:
    void buildBST(BTree *&root, const vector<int> & array, int startPos, int endPos);
    void preOrderTraverse(BTree *root, vector<int> &result);
    void inOrderTraverse(BTree *root, vector<int> &result);
    void postOrderTraverse(BTree *root, vector<int> &result); 
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
};
