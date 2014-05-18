#include "Chapter9.h"

bool Chapter9_test::Problem_1_test(){
    Chapter9 chapter9;
    //case 1
    if(chapter9.Problem_1(5)!=13)
	return false;
    //case 2
    cout<<chapter9.Problem_1(6)<<endl;
    if(chapter9.Problem_1(6)!=24)
	return false;
    return true;
}

bool Chapter9_test::Problem_2_test(){
    Chapter9 chapter9;
    vector<vector<int> > graph(4, vector<int>(4,0));
    graph[0][1]=1;
    graph[1][1]=1;
    graph[3][2]=1;
    vector<pair<int, int> > path;
    vector<pair<int, int> > correctPath;
    correctPath.push_back(make_pair(0,0));
    correctPath.push_back(make_pair(1,0));
    correctPath.push_back(make_pair(2,0));
    correctPath.push_back(make_pair(2,1));
    correctPath.push_back(make_pair(2,2));
    correctPath.push_back(make_pair(2,3));
    correctPath.push_back(make_pair(3,3));
    chapter9.Problem_2(graph, path);
    if(path.size()!=correctPath.size())
	return false;
    for(size_t i=0; i<path.size(); ++i){
	if(path[i].first!=correctPath[i].first)
	    return false;
	if(path[i].second!=correctPath[i].second)
	    return false;
    }
    return true;
}


bool Chapter9_test::Problem_3_test(){
    Chapter9 chapter9;
    int a[]={-2,0,2,4,7,8,10};
    vector<int> distinctA(a, a+7);
    if(chapter9.Problem_3_distinct(distinctA)!=2)
	return false;
    int b[]={-2,-2,0,0,3,3,8,8,8,8,15};
    vector<int> nonDistinctA(b, b+11);
    if(chapter9.Problem_3_same(nonDistinctA)!=8)
	return false;
    return true;
}

bool Chapter9_test::Problem_4_test(){
    Chapter9 chapter9;
    int a[]={1,2,3,4};
    vector<int> wholseSet(a, a+4);
    vector<vector<int> > results;
    chapter9.Problem_4(wholseSet, results);
    if(results.size()!=16)
	return false;
    for(size_t i=0; i<results.size(); ++i){
	for(size_t j=0; j<results[i].size(); ++j)
	    cout<<results[i][j]<<" "<<flush;
	cout<<endl;
    }
    return true;
}

bool Chapter9_test::Problem_5_test(){
    Chapter9 chapter9;
    string oriStr = "abc";
    list<string> results;
    string correctTemp[]={"abc", "acb", "bca", "bac", "cab", "cba"};
    set<string> correctResult(correctTemp, correctTemp+6);
    chapter9.Problem_5(oriStr, results);
    if(results.size()!=6)
	return false;
    for(list<string>::iterator iter=results.begin(); iter!=results.end(); ++iter){
	if(correctResult.find(*iter)==correctResult.end())
	    return false;
    }
    return true;
}

bool Chapter9_test::Problem_6_test(){
    Chapter9 chapter9;
    chapter9.Problem_6(4);
    return true;
}

bool Chapter9_test::Problem_7_test(){
    int rowOne[] = {0,1,0,0};
    int rowTwo[] = {1,0,1,1};
    int rowThree[] = {1,0,0,0};
    int rowFour[] = {0,1,1,1};
    vector<vector<int> > screen;
    screen.push_back(vector<int>(rowOne, rowOne+4));
    screen.push_back(vector<int>(rowTwo, rowTwo+4));
    screen.push_back(vector<int>(rowThree, rowThree+4));
    screen.push_back(vector<int>(rowFour, rowFour+4));
    
    vector<vector<int> > correctScreen;
    for(size_t i=0; i<screen.size(); ++i){
	correctScreen.push_back(vector<int>(screen[i].begin(), screen[i].end()));
    }
    correctScreen[1][1]=2;
    correctScreen[2][1]=2;
    correctScreen[2][2]=2;
    correctScreen[2][3]=2;
  
    Chapter9 chapter9;
    chapter9.Problem_7(screen, 1, 2, 2);
    
    for(size_t i=0; i<screen.size(); ++i){
	for(size_t j=0; j<screen[0].size(); ++j){
	    if(screen[i][j]!=correctScreen[i][j]){
		return false;
	    }
	}
    }
    return true;
    
}

bool Chapter9_test::Problem_8_test(){
    Chapter9 chapter9;
    if(chapter9.Problem_8(10)!=4)
	return false;
    if(chapter9.Problem_8(30)!=18)
	return false;
    return true;
}

bool Chapter9_test::Problem_9_test(){
    Chapter9 chapter9;
    chapter9.Problem_9();
    return true;
}


bool Chapter9_test::Problem_10_test(){
    vector<Box> boxStack;
    boxStack.push_back(Box(10,8,9));
    boxStack.push_back(Box(11,7,11));
    boxStack.push_back(Box(6,5,4));
    boxStack.push_back(Box(4,3,2));
    Chapter9 chapter9;
    if(chapter9.Problem_10(boxStack)!=21)
	return false;
    boxStack.push_back(Box(10,6,8));
    if(chapter9.Problem_10(boxStack)!=31)
	return false;
    return true;
}

bool Chapter9_test::Problem_11_test(){
    string exp = "1&0^1";
    Chapter9 chapter9;
    if(chapter9.Problem_11(exp, true)!=2)
	return false;
    exp = "1&1^0|0";
    if(chapter9.Problem_11(exp, true)!=5)
	return false;
    return true;
}

int main(){
    Chapter9_test testor;
    //Problem 1
    if(!testor.Problem_1_test())
	cout<<"Test 1 Failed!!!!!"<<endl;
    else
	cout<<"Test 1 Passed!"<<endl;

    //Problem 2
    if(!testor.Problem_2_test())
	cout<<"Test 2 Failed!!!!!"<<endl;
    else
	cout<<"Test 2 Passed!"<<endl;

    //Problem 3
    
    if(!testor.Problem_3_test())
	cout<<"Test 3 Failed!!!!!"<<endl;
    else
	cout<<"Test 3 Passed!"<<endl;
    

    //Problem 4
    /*
    if(!testor.Problem_4_test())
	cout<<"Test 4 Failed!!!!!"<<endl;
    else
	cout<<"Test 4 Passed!"<<endl;
    */
    //Problem 5
    if(!testor.Problem_5_test())
	cout<<"Test 5 Failed!!!!!"<<endl;
    else
	cout<<"Test 5 Passed!"<<endl;

    //Probelm 6
    /*
    if(!testor.Problem_6_test())
	cout<<"Test 6 Failed!!!!!"<<endl;
    else
	cout<<"Test 6 Passed!"<<endl;
    */
    
    //Problem 7
    if(!testor.Problem_7_test())
	cout<<"Test 7 Failed!!!!!"<<endl;
    else
	cout<<"Test 7 Passed!"<<endl;

    //Problem 8
    if(!testor.Problem_8_test())
	cout<<"Test 8 Failed!!!!!"<<endl;
    else
	cout<<"Test 8 Passed!"<<endl;
    
    //Problem 9
    /*
    if(!testor.Problem_9_test())
	cout<<"Test 9 Failed!!!!!"<<endl;
    else
	cout<<"Test 9 Passed!"<<endl;
    */

    //Problem 10
    if(!testor.Problem_10_test())
	cout<<"Test 10 Failed!!!!!"<<endl;
    else
	cout<<"Test 10 Passed!"<<endl;

    //Problem 11
    if(!testor.Problem_11_test())
	cout<<"Test 11 Failed!!!!!"<<endl;
    else
	cout<<"Test 11 Passed!"<<endl;

    return 0;
}
