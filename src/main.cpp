#include "common.h"
#include "test_print.h"
#include<iostream>


bool test_check_inside() {
    std::cout << "test run"<< std::endl;
    return false;
}

bool test_check_find_kth_to_tail() {
    ListNode* test_list;
    std::vector<int> val_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // bool set_result = set_link_list(test_list, val_list);
    // if (val_list.size() == 0) {
    //     return false;
    // } 
    ListNode *current_ptr, *p;
    for (uint32_t i = 0; i < val_list.size(); i++) {
        p = new ListNode(val_list[i]);
        current_ptr->next = p;
        if (i == 0) {
            test_list = current_ptr;
        }
        current_ptr = current_ptr->next;
        // std::cout << current_ptr->val << std::endl;
    }
    while (test_list->next != NULL)
    {
        test_list = test_list->next;
        std::cout << test_list->val << std::endl;
    }
    
    // Solution solvers;
    // solvers.FindKthToTail(test_list, 3);
    return false;
}

int main() {
    my_print("hello world!");
    test_check_inside();
    test_check_find_kth_to_tail();
    return 0;
}