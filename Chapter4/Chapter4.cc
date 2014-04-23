#include "Chapter4.h"

/*Problem 1
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
*/

bool Chapter4::checkBalance(BTree *root, int &height){
    if(root==NULL){
	height = 0;
	return true;
    }
    int leftHeight;
    bool leftResult = checkBalance(root->left, leftHeight);
    if(leftResult==false)
	return false;
    int rightHeight;
    bool rightResult = checkBalance(root->right, rightHeight);
    if(rightResult==false)
	return false;
    if(leftHeight-rightHeight<=1 && leftHeight-rightHeight>=-1){
	height = max(leftHeight, rightHeight)+1;
	return true;
    }
    return false;
}

bool Chapter4::Problem_1(BTree *root){
    int height;
    return checkBalance(root, height);
}

/*Problem 2
Given a directed graph, design an algorithm to find out whether there is a route
between two nodes.
*/

bool Chapter4::Problem_2_BFS(int source, int target, const Graph &graphInput){
    if(graphInput.graph.empty() || source<0 || target<0 || source>=graphInput.graph.size() || target>=graphInput.graph.size())
	return false;
    vector<bool> visitedNode(graphInput.graph.size(), false);
    list<int> frontier;
    frontier.push_back(source);
    visitedNode[source]=true;
    while(!frontier.empty()){
	int currNode = frontier.front();
	if(currNode == target)
	    return true;
	frontier.pop_front();
	for(list<int>::const_iterator iter=graphInput.graph[currNode].begin(); iter!=graphInput.graph[currNode].end(); ++iter){
	    if(visitedNode[*iter]==false){
		frontier.push_back(*iter);
		visitedNode[*iter]=true;
	    }
	}
    }
    return false;
}

bool Chapter4::Problem_2_DFS(int source, int target, const Graph &graphInput){
    if(graphInput.graph.empty() || source<0 || target<0 || source>=graphInput.graph.size() || target>=graphInput.graph.size())
	return false;
     vector<bool> visitedNode(graphInput.graph.size(), false);
     list<int> frontier;
     frontier.push_back(source);
     while(!frontier.empty()){
	 int currNode=frontier.back();
	 if(currNode==target)
	     return true;
	 frontier.pop_back();
	 if(visitedNode[currNode]==false){
	     visitedNode[currNode]=true;
	     for(list<int>::const_iterator iter=graphInput.graph[currNode].begin(); iter!=graphInput.graph[currNode].end(); ++iter){
		 if(visitedNode[*iter]=false)
		     frontier.push_back(*iter);
	     }
	 }
     }
     return false;
}


/*Problem 3
Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
*/

void Chapter4::buildBST(BTree *&root, const vector<int> & array, int startPos, int endPos){
    if(startPos==endPos){
	root = NULL;
	return;
    }
    int midPos = (startPos+endPos)/2;
    root = new BTree();
    root->value = array[midPos];
    buildBST(root->left, array, startPos, midPos);
    buildBST(root->right, array, midPos+1, endPos);
}

BTree * Chapter4::Problem_3(const vector<int> & array){
    BTree *root;
    buildBST(root, array, 0, array.size());
    return root;
}

/*Problem 4
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
*/

void Chapter4::createLinkedList(BTree *root, vector<list<BTree*> > &result, int height){
    if(root==NULL)
	return;
    if(result.size()>=height){
	list<BTree *> temp(1, root);
	result.push_back(temp);
    }
    else
	result[height].push_back(root);
    createLinkedList(root->left, result, height+1);
    createLinkedList(root->right, result, height+1);
}

void Chapter4::Problem_4(BTree *root, vector<list<BTree*> > &result){
    createLinkedList(root, result, 0);
}


/*Problem 5
Imp/emen t a function to check if a binary tree is a binary search tree.
*/

bool Chapter4::checkBinaryTree(BTree *root, int &maxVal, int &minVal){
    if(root==NULL){
	maxVal = INT_MIN;
	minVal = INT_MAX;
	return true;
    }
    int maxLeftVal, minLeftVal;
    bool leftResult = checkBinaryTree(root->left, maxLeftVal, minLeftVal);
    if(leftResult==false)
	return false;
    int maxRightVal, minRightVal;
    bool rightResult = checkBinaryTree(root->right, maxRightVal, minRightVal);
    if(rightResult==false)
	return false;
    if(root->value>=maxLeftVal && root->value<=minRightVal)
	return true;
    return false;
}

bool Chapter4::Problem_5(BTree *root){
    int maxVal, minVal;
    return checkBinaryTree(root, maxVal, minVal);
}

/*Problem 6
Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
a binary search tree. You may assume that each node has a link to its parent.
*/

BTreeParent *Chapter4::findLeftMostNode(BTreeParent *curr){
    if(curr==NULL)
	return NULL;
    while(curr->left!=NULL)
	curr=curr->left;
    return curr;
}

BTreeParent *Chapter4::findLeftAncestor(BTreeParent *curr){
    if(curr==NULL)
	return NULL;
    while(curr->parent!=NULL && curr!=curr->parent->left)
	curr = curr->parent;
    return curr->parent;
}

BTreeParent *Chapter4::Problem_6(BTreeParent *curr){
    BTreeParent *nextChild = findLeftMostNode(curr->right);
    if(nextChild!=NULL)
	return nextChild;
    BTreeParent *nextParent = findLeftAncestor(curr);
    return nextParent;
}

/*Problem 7
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree.
*/

BTree *Chapter4::findCommonAncestor(BTree *root, const BTree * &first, const BTree *& second, int &state) {// state 0: no node, state 1: only first node, state 2: only right node
    if(root==NULL){
	state = 0;
	return NULL;
    }
    int leftState;
    BTree *leftResult = findCommonAncestor(root->left, first, second, leftState);
    if(leftResult!=NULL)
	return leftResult;
    int rightState;
    BTree *rightResult = findCommonAncestor(root->right, first, second, rightState);
    if(rightResult!=NULL)
	return rightResult;
    
    if(leftState+rightState==3)
	return root;
    
    if(root!=first && root!=second){
	state = leftState+rightState;
	return NULL;
    }

    if(root==first && root==second)
	return root;
    
    if(root==first){
	state = 1;
	return (leftState+rightState==2?root:NULL);
    }

    if(root==second){
	state = 2;
	return (leftState+rightState==1?root:NULL);
    }
}

BTree *Chapter4::Problem_7(BTree *root, const BTree * &first, const BTree *& second){
    int state;
    return findCommonAncestor(root, first, second, state);
}


/*Problem 8
You have two very large binary trees: T1, with millions of nodes, and T2, with
hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
*/

bool Chapter4::compareTrees(BTree *rootFirst, BTree *rootSecond){
    if(rootFirst==NULL && rootSecond==NULL)
	return true;
    if(rootFirst==NULL || rootSecond==NULL)
	return false;
    if(rootFirst->value!=rootSecond->value)
	return false;
    bool leftResult = compareTrees(rootFirst->left, rootSecond->left);
    if(leftResult==false)
	return false;
    bool rightResult = compareTrees(rootFirst->right, rootSecond->right);
    if(rightResult==false)
	return false;
    return true;
}

bool Chapter4::Problem_8(BTree *largeTree, BTree *smallTree){
    if(smallTree==NULL)
	return true;
    if(largeTree==NULL)
	return false;
    vector<BTree *> frontier;
    frontier.push_back(largeTree);
    while(!frontier.empty()){
	BTree *currNode = frontier.back();
	frontier.pop_back();
	if(currNode->value == smallTree->value){
	    bool result = compareTrees(currNode, smallTree);
	    if(result==true)
		return true;
	}
	if(currNode->right!=NULL)
	    frontier.push_back(currNode->right);
	if(currNode->left!=NULL)
	    frontier.push_back(currNode->left);
    }
    return false;
}

/*Problem 9
You are given a binary tree in which each node contains a value. Design an algo-
rithm to print all paths which sum to a given value. The path does not need to start or end at the root or a leaf.
*/

void Chapter4::printPath(const vector<int> &pathSum, int i){
    cout<<"path: "<<flush;
    for(size_t k=i; k<pathSum.size(); ++k){
	cout<<pathSum[k]-pathSum[k+1]<<" "<<flush;
    }
    cout<<pathSum.back()<<endl;
}

void Chapter4::findCorrectPath(BTree *root, int sum, vector<int> &pathSum){
    if(root==NULL)
	return;
    for(size_t i=0; i<pathSum.size(); ++i)
	pathSum[i]+=root->value;
    pathSum.push_back(root->value);
    for(size_t i=0; i<pathSum.size(); ++i){
	if(pathSum[i]==sum)
	    printPath(pathSum, i);
    }
    findCorrectPath(root->left, sum, pathSum);
    findCorrectPath(root->right, sum, pathSum);
    pathSum.pop_back();
    for(size_t i=0; i<pathSum.size(); ++i)
	pathSum[i]-=root->value;
}

void Chapter4::Problem_7(BTree *root, int sum){
    vector<int> pathSum;
    findCorrectPath(root, sum, pathSum);
}


