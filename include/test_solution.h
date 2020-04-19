#ifndef IV_INCLUDE_TEST_SOLUTION_H
#define IV_INCLUDE_TEST_SOLUTION_H
#include<string>
#include<vector>
#include<stack>

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
    std::vector<int> printMatrix(std::vector<std::vector<int>>& matrix);
    bool Find2dArray(int target, std::vector<std::vector<int> > array);
    void replaceSpace(char *str,int length);
    std::vector<int> printListFromTailToHead(ListNode* head);
    TreeNode* reConstructBinaryTree(std::vector<int>& pre, std::vector<int>& vin);
    int minNumberInRotateArray(std::vector<int>& rotateArray);
    int Fibonacci(int n);
    int jumpFloor(int number);
    int jumpFloorII(int number);

    void push(int node);
    int pop();
    
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

#endif