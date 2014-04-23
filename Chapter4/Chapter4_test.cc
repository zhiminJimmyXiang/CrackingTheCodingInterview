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
}
