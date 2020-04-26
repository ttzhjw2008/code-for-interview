#include "common.h"
#include "test_solution.h"
#include<iostream>


ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k) {
    // std::cout << "test_1" << std::endl;
    ListNode* temp_node_ptr = pListHead;
    ListNode* selected_node_ptr = pListHead;
    unsigned int node_count = 0;
    while (temp_node_ptr->next != NULL) {
        node_count += 1;
        temp_node_ptr = temp_node_ptr->next;
        if (node_count >= k) {
            selected_node_ptr = selected_node_ptr->next;
        }
    }
    return selected_node_ptr;
}

std::vector<int> Solution::printMatrix(std::vector<std::vector<int>>& matrix) {
    std::vector<int> output_vec;    
    int matrix_row = matrix.size();    
    if (matrix_row < 1) {
        return output_vec;
    }

    int matrix_line = matrix[0].size();
    if (matrix_line < 1) {
        return output_vec;
    }

    int min_number = (matrix_line <  matrix_row) ? matrix_line : matrix_row;
    int max_iter = (min_number%2) ? (min_number/2+1) : (min_number/2);
    for (int count = 0; count < max_iter; count++) {
        for (int j = count; j <= matrix_line-1-count; j++) {
            output_vec.push_back(matrix[count][j]);
        }
        for (int i = count+1; i <= matrix_row-1-count; i++) {
            output_vec.push_back(matrix[i][matrix_line-1-count]);
        }
        for (int j = matrix_line-2-count; j >= count; j--) {
            if (matrix_row-1-count > count) {
                output_vec.push_back(matrix[matrix_row-1-count][j]);
            }
        }
        for (int i = matrix_row-2-count; i >= count+1; i--) {
            if (matrix_line-1-count > count) {
                output_vec.push_back(matrix[i][count]);
            }
        }
    }
    return output_vec; 
}

bool Solution::Find2dArray(int target, std::vector<std::vector<int> > array) {
    int array_row = array.size();
    if (array_row < 1) {
        return false;
    }
    int array_line = array[0].size();
    if (array_line < 1) {
        return false;
    }

    for (int counter_row=0; counter_row< array_row; counter_row++) {
        for (int counter_line=0; counter_line<array_line; counter_line++) {
            if (target == array[counter_row][counter_line]) {
                return true;
            } else if (target > array[counter_row][counter_line]) {
                continue;
            }
        }
    }
    return false;
}

void Solution::replaceSpace(char *str,int length) {
    std::vector<char> str_out;
    for (int i = 0; i < length; i++) {
        if (' ' == str[i]) {
            str_out.push_back('%');
            str_out.push_back('2');
            str_out.push_back('0');
        } else {
            str_out.push_back(str[i]);
        }
    }
}

std::vector<int> Solution::printListFromTailToHead(ListNode* head) {
    std::vector<int> list_vector_temp, list_vector_out;

    while (head->next != NULL)
    {
        head = head->next;
        list_vector_temp.emplace_back(head->val);
    }
    size_t i = list_vector_temp.size();
    while(i > 0) {
        list_vector_out.emplace_back(list_vector_temp[i-1]);
        i--;
    }
    return list_vector_out;
}

TreeNode* Solution::reConstructBinaryTree(std::vector<int>& pre, std::vector<int>& vin) {
    if (pre.size() <= 1) {
        TreeNode* tree_node_leaf = new TreeNode(pre[0]);
        return tree_node_leaf;
    }

    TreeNode* tree_node_new = new TreeNode(pre[0]);
    int64_t index = 0;
    for (size_t i=0; i<vin.size(); i++) {
        if (pre[0] == vin[i]) {
            index = i;
            break;
        }
    }
    if (index>0) {
        std::vector<int> pre_left(pre.begin()+1, pre.begin()+index+1);
        std::vector<int> vin_left(vin.begin(), vin.begin()+index);
        tree_node_new->left = reConstructBinaryTree(pre_left,vin_left);
    }
    if (vin.size()-index-1 > 0) {
        std::vector<int> pre_right(pre.begin()+index+1,pre.end());
        std::vector<int> vin_right(vin.begin()+index+1, vin.end());
        tree_node_new->right = reConstructBinaryTree(pre_right,vin_right);
    }

    return tree_node_new;   
}

void Solution::push(int node) {
    while (!stack2.empty())
    {
        stack1.push(stack2.top());
        stack2.pop();
    }
    stack1.push(node);
}

int Solution::pop() {
    while (!stack1.empty())
    {
        stack2.push(stack1.top());
        stack1.pop();
    }
    int return_result =  stack2.top();
    stack2.pop();

    return return_result;
}

int Solution::minNumberInRotateArray(std::vector<int>& rotateArray) {
    int min_index = 0;
    for (size_t i=0; i<rotateArray.size(); i++) {
        if (rotateArray[i] < rotateArray[min_index]) {
            min_index = i;
            break;
        }
    }
    return rotateArray[min_index];
}

int Solution::Fibonacci(int n) {
    if (n<0||n>39) {
        return 0;
    }
    if (n<2) {
        return n;
    }

    int sn1 = 1;
    int sn2 = 0;
    int s = 1;
    for (int i=2; i<=n; i++) {
        s = sn2 + sn1;
        sn2 = sn1;
        sn1 = s;
    }
    
    return s;
    // return (Fibonacci(n-1) + Fibonacci(n-2));
}

int Solution::jumpFloor(int number) { 
    if (number < 0) {
        return 0;
    }

    if (number<=2) {
        return number;
    }

    int solver_number = 0;
    solver_number = jumpFloor(number-1) + jumpFloor(number-2);
    return solver_number;
}

int Solution::jumpFloorII(int number) {
    if (number < 0) {
        return 0;
    }
    if (number<=2) {
        return number;
    }
    std::vector<int> jump_result = {0,1,2};
    for (int i=3;i<=number; i++) {
        int s_jump = 0;
        for (size_t j=0; j<jump_result.size(); j++) {
            s_jump = s_jump + jump_result[j];
        }
        jump_result.emplace_back(s_jump+1);
    }
    return jump_result[number];
}



    int Solution::maxScore1(std::string s) {
    int max_sum = 0;
    for (size_t i = 0; i < s.length()-1; i++) {
        int counter_left = 0;
        int counter_right = 0;
        for (size_t j = 0; j <= i; j++) {
            counter_left += (s[j] == '0') ? 1 : 0;
        }
        for (size_t j = i+1; j < s.length(); j++) {
            counter_right += (s[j] == '1') ? 1 :0; 
        }
        max_sum = (max_sum < (counter_left + counter_right)) ? (counter_left + counter_right) : max_sum;
    }
    return max_sum;
}

int Solution::maxScore2(std::vector<int>& cardPoints, int k) {
    // if (k == 1) {
    //     return (cardPoints[0] >= cardPoints[cardPoints.size()-1]) ? cardPoints[0] : cardPoints[cardPoints.size() -1]; 
    // } 

    // std::vector<int> vec_left;
    // vec_left.insert(vec_left.begin(), cardPoints.begin(), cardPoints.end()-1);
    // int counter_left = maxScore2(vec_left, k-1);

    // std::vector<int> vec_right;
    // vec_right.insert(vec_right.begin(), cardPoints.begin()+1, cardPoints.end());
    // int counter_right = maxScore2(vec_right, k-1);

    // int max_left = cardPoints[cardPoints.size()-1] + counter_left;
    // int max_right = cardPoints[0] + counter_right;
    // return (max_left >= max_right) ? max_left : max_right;


    // long int sum_all = 0;
    // for (size_t i = 0; i < cardPoints.size(); i++) {
    //     sum_all += cardPoints[i];
    // }
    // long int min_counter = sum_all;
    // for (size_t i = 0; i <= k; i++) {
    //     long int counter_k = 0;
    //     size_t counter_size = cardPoints.size() - k;
    //     for (size_t j = i; j < counter_size + i; j++) {
    //         counter_k += cardPoints[j];
    //     }
    //     min_counter = (min_counter < counter_k) ? min_counter : counter_k;
    // }
    // return sum_all - min_counter;

    // long int sum_max = 0;
    // for (size_t i = 0; i <= k; i++) {
    //     long int counter_left = 0;
    //     long int counter_right = 0;

    //     for (size_t j = 0; j < i; j++) {
    //         counter_left += cardPoints[j];
    //     }

    //     size_t counter_size = cardPoints.size() - k;
    //     for (size_t j = cardPoints.size() - k + i; j < cardPoints.size(); j++) {
    //         counter_right += cardPoints[j];
    //     }
    //     sum_max = (sum_max > counter_left + counter_right) ? sum_max : counter_left + counter_right;
    // }
    // return sum_max;

    size_t card_point_size = cardPoints.size();
    int sum_max = 0;
    std::vector<int> sum_vec_left(k, 0);
    std::vector<int> sum_vec_right(k, 0);
    sum_vec_left[0] = cardPoints[0];
    sum_vec_right[k-1] = cardPoints[card_point_size-1];
    for (size_t i = 1; i < k; i++) {
        sum_vec_left[i] = sum_vec_left[i-1] + cardPoints[i];
        sum_vec_right[k-1-i] = sum_vec_right[k-i] + cardPoints[card_point_size-1-i];
    }
    
    sum_max = sum_vec_left[k-1] > sum_vec_right[0] ? sum_vec_left[k-1] : sum_vec_right[0]; 
    for (size_t i = 0; i < k-1 ; i++) {
        int each_sum = sum_vec_left[i] + sum_vec_right[i+1];
        sum_max = (sum_max > each_sum) ? sum_max : each_sum;
    }

    return sum_max;
}