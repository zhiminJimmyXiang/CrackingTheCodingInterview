#include "../DataStructure/DataStructure.h"

class Chapter2{
 private:
    int addDigit(LinkedList *&sumDigit, LinkedList *num1st, LinkedList *num2nd);
    bool recursivePalindrome(LinkedList *forward, LinkedList *&reverseNext, LinkedList *middleBefore, LinkedList *middleAfter);
 public:
    LinkedList *Problem_1_1(LinkedList *head);
    LinkedList *Problem_1_2(LinkedList *head);
    LinkedList *Problem_2(LinkedList *head, int k);
    void Problem_3(LinkedList *middle);
    LinkedList* Problem_4(LinkedList *head, int x);
    LinkedList* Problem_5_reverse(LinkedList *num1st, LinkedList *num2nd);
    LinkedList* Problem_5_forward(LinkedList *num1st, LinkedList *num2nd);
    LinkedList* Problem_6(LinkedList *head);
    bool Problem_7_reverse(LinkedList *head);
    bool Problem_7_recursive(LinkedList *head);
};


class Chapter2_test{
 public:
    bool Problem_1_test();
    bool Problem_2_test();
    bool Problem_3_test();
    bool Problem_4_test();
    bool Problem_5_test();
    bool Problem_6_test();
    bool Problem_7_test();
};
