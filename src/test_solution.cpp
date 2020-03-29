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
