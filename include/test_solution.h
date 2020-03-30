#ifndef IV_INCLUDE_TEST_SOLUTION_H
#define IV_INCLUDE_TEST_SOLUTION_H
#include<string>
#include<vector>

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
    std::vector<int> printMatrix(std::vector<std::vector<int>>& matrix);
    bool Find2dArray(int target, std::vector<std::vector<int> > array);
};

#endif