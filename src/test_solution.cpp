#include "common.h"
#include "test_solution.h"


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

bool Solution::Find2dArray(int target, vector<vector<int> > array) {
    
}