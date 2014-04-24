#include "Chapter4.h"

void Chapter4_test::buildBST(BTree *&root, const vector<int> & array, int startPos, int endPos){
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

void Chapter4_test::preOrderTraverse(BTree *root, vector<int> &result){
    if(root==NULL)
	return;
    result.clear();
    vector<BTree*> frontier;
    frontier.push_back(root);
    while(!frontier.empty()){
	BTree *currNode = frontier.back();
	frontier.pop_back();
	result.push_back(currNode->value);
	if(currNode->right!=NULL)
	    frontier.push_back(currNode->right);
	if(currNode->left!=NULL)
	    frontier.push_back(currNode->left);
    }
}

void Chapter4_test::postOrderTraverse(BTree *root, vector<int> &result){
    if(root==NULL)
	return;
    result.clear();
    vector<BTree *>frontier;
    vector<int> tempResult;
    frontier.push_back(root);
    while(!frontier.empty()){
	BTree *currNode = frontier.back();
	frontier.pop_back();
	tempResult.push_back(currNode->value);
	if(currNode->left!=NULL)
	    frontier.push_back(currNode->left);
	if(currNode->right!=NULL)
	    frontier.push_back(currNode->right);
    }
    result.assign(tempResult.rbegin(), tempResult.rend());
}

void Chapter4_test::inOrderTraverse(BTree *root, vector<int> &result){
    if(root==NULL)
	return;
    result.clear();
    vector<BTree *> stack;
    stack.push_back(root);
    BTree *curr=  stack.back();
    while(!stack.empty()){
	if(stack.back()->left!=NULL)
	    stack.push_back(stack.back()->left);
	else{
	    curr = stack.back();
	    result.push_back(curr->value);
	    stack.pop_back();
	    while(!stack.empty() && curr->right==NULL){
		curr = stack.back();
		result.push_back(curr->value);
		stack.pop_back();
	    }
	    if(curr->right!=NULL){
		stack.push_back(curr->right);
		curr = stack.back();
	    }
	}
    }
}


bool Chapter4_test::Problem_1_test(){
    Chapter4 chapter4;
    BTree* root = NULL;
    //case 1
    if(chapter4.Problem_1(root)==false)
	return false;
    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    buildBST(root, array, 0, 15);
    if(chapter4.Problem_1(root)==false)
	return false;
   
    //case 3
    root->right->left = NULL;
    if(chapter4.Problem_1(root)==true)
	return false;
    return true;
}

bool Chapter4_test::Problem_3_test(){
    Chapter4 chapter4;
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    BTree *root;
    buildBST(root, array, 0, 15);
    int correctPreOrder[]={8,4,2,1,3,6,5,7,12,10,9,11,14,13,15};
    int correctInOrder[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int correctPostOrder[]={1,3,2,5,7,6,4,9,11,10,13,15,14,12,8};
    vector<int> result;
    //pre-order traverse
    preOrderTraverse(root, result);
    if(result.size()!=15)
	return false;
    for(size_t i=0; i<15; ++i){
	if(result[i]!=correctPreOrder[i])
	    return false;
    }
    //in-order traverse
    inOrderTraverse(root, result);
    if(result.size()!=15)
	return false;
    for(size_t i=0; i<15; ++i){
	if(result[i]!=correctInOrder[i])
	    return false;
    }
    //post-order traverse
    postOrderTraverse(root, result);
     if(result.size()!=15)
	return false;
    for(size_t i=0; i<15; ++i){
	if(result[i]!=correctPostOrder[i])
	    return false;
    }
    return true;
}

bool Chapter4_test::Problem_4_test(){
    Chapter4 chapter4;
    //case 1
    BTree *root = NULL;
    vector<list<BTree *> > result;
    chapter4.Problem_4(root, result);
    if(!result.empty())
	return false;
    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    buildBST(root, array, 0, 15);
    chapter4.Problem_4(root, result);
    int correctAnswer[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
    int correctSize[]={1,2,4,8};
    int count = 0;
    if(result.size()!=4)
	return false;
    for(size_t i=0; i<4; ++i){
	if(result[i].size()!=correctSize[i])
	    return false;
	for(list<BTree *>::iterator iter = result[i].begin(); iter!=result[i].end(); ++iter){
	    if((*iter)->value!=correctAnswer[count])
		return false;
	    ++count;
	}
    }
    return true;
}

bool Chapter4_test::Problem_5_test(){
    Chapter4 chapter4;
    //case 1
    BTree *root = NULL;
    if(chapter4.Problem_5(root)==false)
	return false;
    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    buildBST(root, array, 0, 15);
    if(chapter4.Problem_5(root)==false)
	return false;
    //case 3
    root->right->value = 18;
    if(chapter4.Problem_5(root)==true)
	return false;
    return true;
}

bool Chapter4_test::Problem_6_test(){
    Chapter4 chapter4;
    BTreeParent *root = NULL;
    //case 1
    if(chapter4.Problem_6(root)!=NULL)
	return false;

    //case 2
    root = new BTreeParent();
    root->value = 9;
    root->left = new BTreeParent();
    root->left->value = 3;
    root->left->parent = root;
    root->left->left = new BTreeParent();
    root->left->left->value = 1;
    root->left->left->parent = root->left;
    root->right = new BTreeParent();
    root->right->value = 8;
    root->right->parent = root;
    root->right->left = new BTreeParent();
    root->right->left->value = 2;
    root->right->left->parent = root->right;
    root->right->right = new BTreeParent();
    root->right->right->value = 4;
    root->right->right->parent = root->right;
    if(chapter4.Problem_6(root->right->right)!=NULL)
	return false;

    //case 3
    if(chapter4.Problem_6(root)->value!=2)
	return false;

    //case 4
    if(chapter4.Problem_6(root->left)->value!=9)
	return false;
    return true;
}

bool Chapter4_test::Problem_7_test(){
    Chapter4 chapter4;
    //case 1
    BTree *root(NULL), *first(NULL), *second(NULL);
    if(chapter4.Problem_7(root, first, second)!=NULL)
	return false;

    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    buildBST(root, array, 0, 15);
    if(chapter4.Problem_7(root, root->left->left, root->right->right->right)!=root)
	return false;

    //case 3
     if(chapter4.Problem_7(root, root->left->left, root->left->left->left)!=root->left->left)
	return false;

     //case 4
     if(chapter4.Problem_7(root, root->left->right->left, root->left->left->left)!=root->left)
	return false;
    return true;
}



bool Chapter4_test::Problem_8_test(){
    Chapter4 chapter4;
    //case 1
    BTree *largeTree = new BTree(); 
    BTree *smallTree(NULL);
    if(chapter4.Problem_8(largeTree, smallTree)==false)
	return false;
    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> arrayLarge(a, a+15);
    buildBST(largeTree, arrayLarge, 0, 15);
    int b[]={9,10,11,12,13,14,15};
    vector<int> arraySmall(b, b+7);
    buildBST(smallTree, arraySmall, 0, 7);
    if(chapter4.Problem_8(largeTree, smallTree)==false)
	return false;

    //case 3
    smallTree->right->value = 0;
    if(chapter4.Problem_8(largeTree, smallTree)==true)
	return false;
    return true;
}


bool Chapter4_test::Problem_9_test(){
    Chapter4 chapter4;
    //case 1
    BTree *root=NULL;
    chapter4.Problem_9(root, 0);
    //case 2
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> array(a, a+15);
    buildBST(root, array, 0, 15);
    chapter4.Problem_9(root, 6);
    
    //case 3
    chapter4.Problem_9(root, 39);
}


int main(){
     Chapter4_test testor;
    //--- Problem 1 test ---
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;

    //--- Problem 3 test ---
    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;

     //--- Problem 4 test ---
    if(!testor.Problem_4_test())
	cout<<"Test 4 Failed!!!!!"<<endl;
    else
	cout<<"Test 4 Passed!"<<endl;

    //--- Problem 5 test ---
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;

    //--- Problem 6 test ---
    if(!testor.Problem_6_test())
	cout<<"Test 6 Failed!!!!!"<<endl;
    else
	cout<<"Test 6 Passed!"<<endl;

    //--- Problem 7 test ---
    if(!testor.Problem_7_test())
	cout<<"Test 7 Failed!!!!!"<<endl;
    else
	cout<<"Test 7 Passed!"<<endl;

    //--- Problem 8 test ---
    if(!testor.Problem_8_test())
	cout<<"Test 8 Failed!!!!!"<<endl;
    else
	cout<<"Test 8 Passed!"<<endl;

    //--- Problem 9 test ---
    //testor.Problem_9_test();
}
