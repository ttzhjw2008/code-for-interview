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


//  Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

	bool creat_tree_node(TreeNode* top_node, std::vector<int> value_list);
	bool pre_order_travel(std::vector<int>& out_vec, TreeNode* top_node);
 };


bool set_link_list(ListNode* head, std::vector<int> val_list);
bool check_inside();

#endif
