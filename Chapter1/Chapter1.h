#include "../DataStructure/DataStructure.h"

class Chapter1{
 public:
    bool Problem_1(const string &input); //decide whether all letters are unique in a string
    void Problem_2(char *str);
    bool Problem_3(const string &str1st, const string &str2nd);
    void Problem_4(char str[], int len);
    void Problem_5(const string &strIn, string &strOut);
    void Problem_6(MATRIX &matrix);
    void Problem_7(MATRIX &matrix);
};

class Chapter1_test{
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
};
