#include"common.h"
#include<iostream>

bool set_link_list(ListNode* head, std::vector<int> val_list) {
    if (val_list.size() == 0) {
        return false;
    } 
    ListNode* current_ptr = nullptr;
    ListNode* p = nullptr;

    current_ptr = head;

    for (uint32_t i = 0; i < val_list.size(); i++) {
        p = new ListNode(0);
        // p = new ListNode(val_list[i]);
        p->val = val_list[i];
        p->next = NULL;
        current_ptr->next = p;
        current_ptr = current_ptr->next;
        // std::cout << current_ptr->val << std::endl;
    }
    // std::cout << "try to return" << std::endl;

    return true;
}

bool check_inside() {
    // std::cout << "test run"<< std::endl;
    return false;
}