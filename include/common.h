#ifndef IV_INCLUDE_COMMON_H
#define IV_INCLUDE_COMMON_H
#include<string>
#include<vector>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

bool set_link_list(ListNode* head, std::vector<int> val_list);
bool check_inside();

#endif
