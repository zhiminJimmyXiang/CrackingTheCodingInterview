#include "../DataStructure/DataStructure.h"

class Chapter5{
 private:
    bool getBit(const vector<unsigned> &A, int currIndex, int bitPos);
 public:
    unsigned Problem_1(unsigned M, unsigned N, unsigned i, unsigned j);
    string Problem_2(double input);
    unsigned findPreviousSmallest(unsigned input);
    unsigned findNextLargest(unsigned input);
    unsigned Problem_5(unsigned a, unsigned b);
    unsigned Problem_5_1(unsigned a, unsigned b);
    unsigned Problem_6(unsigned a);
    unsigned Problem_7(unsigned n, const vector<unsigned> &A);
    void Problem_8(vector<char> &screen, int width, int x1, int x2, int y);
};


class Chapter5_test{
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
