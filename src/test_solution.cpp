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
    std::vector<int> list_vector;
    ListNode* temp_node = new ListNode(0);
    temp_node->next = head->next;
    while (temp_node->next != NULL)
    {
        temp_node = temp_node->next;
        list_vector.push_back(temp_node->val);
    }
    return list_vector;
}