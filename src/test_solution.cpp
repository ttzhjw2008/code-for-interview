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
    if (number <= 0) {
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
    for (int i = 1; i < k; i++) {
        sum_vec_left[i] = sum_vec_left[i-1] + cardPoints[i];
        sum_vec_right[k-1-i] = sum_vec_right[k-i] + cardPoints[card_point_size-1-i];
    }
    
    sum_max = sum_vec_left[k-1] > sum_vec_right[0] ? sum_vec_left[k-1] : sum_vec_right[0]; 
    for (int i = 0; i < k-1 ; i++) {
        int each_sum = sum_vec_left[i] + sum_vec_right[i+1];
        sum_max = (sum_max > each_sum) ? sum_max : each_sum;
    }

    return sum_max;
}

int Solution::rectCover(int number) {
    if (number<=0) {
        return 0;
    }
    if (number<=2) {
        return number;
    }

    std::vector<int> cover_vec = {0,1,2};
    int sum_cover_path = 0;
    for (int i=3; i<=number; i++) {
        sum_cover_path = cover_vec[i-1] + cover_vec[i-2];
        cover_vec.emplace_back(sum_cover_path);
    }
    return cover_vec[number];
}

int  Solution::NumberOf1(int n) {
    std::vector<int> binary_vec;
    int temp = n;
    if (n<0) {
        temp = -n;
    }
    while(temp/2>=0) {
        binary_vec.emplace_back(temp%2);
        if (temp<=1) {
            break;
        }
        temp /= 2;
    }
    if(n<0) {
        for (size_t i = binary_vec.size(); i< (sizeof(int)*8-1); i++) {
            binary_vec.emplace_back(0);
        }
        for (size_t i = 0; i < binary_vec.size(); i++) {
            binary_vec[i] = (binary_vec[i] == 0) ? 1 : 0;
        }
        bool up_flag = 1;
        for (size_t i = 0; i < binary_vec.size(); i++) {
            if (binary_vec[i] == 1 && up_flag) {
                binary_vec[i] = 0;
            } else if (binary_vec[i] == 0 && up_flag) {
                binary_vec[i] = 1;
                up_flag = 0;
            } else {
                break;
            }
        }
        binary_vec.emplace_back(1);
    }
    int counter_1 = 0;
    for (size_t i = 0; i < binary_vec.size(); i++) {
        counter_1 += binary_vec[i];
    }
    return counter_1;
}

double Solution::Power(double base, int exponent) {
        if (base == 0 && exponent ==0) {
            return 1;
        }

        double power_result = 1;
        int temp_exp = (exponent>=0) ? exponent:-exponent;
        for (int i=1; i<=temp_exp; i++) {
            power_result *= base;
        }
        if (exponent<0) {
            power_result = 1/power_result;
        }
        return power_result;
}

void Solution::reOrderArray(std::vector<int> &array) {
    std::vector<int> array_1;
    std::vector<int> array_2;

    for (size_t i=0; i<array.size(); i++) {
        if(array[i]%2 >0) {
            array_1.emplace_back(array[i]);
        } else {
            array_2.emplace_back(array[i]);
        }
    }
    size_t arr1_size = array_1.size();
    for (size_t i=0; i<array_1.size(); i++) {
        array[i] = array_1[i];
    }
    for (size_t i=0; i<array_2.size(); i++) {
        array[i+arr1_size] = array_2[i];
    }
}

ListNode* Solution::ReverseList(ListNode* pHead) {
    ListNode* pre_node = nullptr;
    ListNode* next_node = nullptr;
    if ( pHead != NULL) {
        pre_node = pHead;
        pHead = pHead->next;
        pre_node->next = NULL;
    }
    while (pHead != NULL)
    {
        next_node = pHead->next;
        pHead->next = pre_node;
        pre_node = pHead;
        pHead = next_node;
    }
    
    return pre_node;
}

ListNode* Solution::Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* pre_node = new ListNode(0);
    ListNode* cur_node = pre_node;
    
    while (pHead1 != NULL && pHead2 != NULL) {
        if (pHead2->val < pHead1->val) {
            cur_node->next = pHead2;
            pHead2 = pHead2->next;
        } else {
            cur_node->next = pHead1;
            pHead1 = pHead1->next;
        }      
        return pre_node->next;
    }
    while (pHead1 != NULL) {
        cur_node->next = pHead1;
        pHead1 = pHead1->next;
        cur_node = cur_node->next;
    }
    while (pHead2 != NULL) {
        cur_node->next = pHead2;
        pHead2 = pHead2->next;
        cur_node = cur_node->next;
    }
    
    return pre_node->next;
}

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }
    if (pRoot2->left == NULL &&  pRoot2->right == NULL && pRoot1->val == pRoot2->val) {
        return true;
    }
    if (pRoot2->left == NULL && pRoot2->val == pRoot1->val) {
        if (HasSubtree(pRoot1->right, pRoot2->right)) {
            return true;
        }
    }
    if (pRoot2->right == NULL && pRoot2->val == pRoot2->val) {
        if (HasSubtree(pRoot1->left, pRoot2->left)) {
            return true;
        }
    }
    if (pRoot1->val == pRoot2->val) {
        if(HasSubtree(pRoot1->left, pRoot2->left) && HasSubtree(pRoot1->right, pRoot2->right)) {
            return true;
        }
    }
    if (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)) {
        return true;
    } else {
        return false;
    }
}

void Solution::Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) {
        return;
    }
    TreeNode* temp_node = nullptr;
    while (pRoot != NULL) {
        temp_node = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp_node; 
    }
    Mirror(pRoot->left);
    Mirror(pRoot->right);    
}

 std::vector<int> Solution::PrintFromTopToBottom(TreeNode* root){
    std::vector<int> ret_vec;
     while (root == NULL) {
        return ret_vec;
     }
     std::vector<TreeNode*> each_row;
     each_row.emplace_back(root);
     while (each_row.size() > 0) {
        std::vector<TreeNode*> next_row;
        for (size_t i = 0; i < each_row.size(); i++) {
            ret_vec.emplace_back(each_row[i]->val);
            if (each_row[i]->left != NULL) {
                next_row.emplace_back(each_row[i]->left);
            }
            if (each_row[i]->right != NULL) {
                next_row.emplace_back(each_row[i]->right);
            }
        }
        each_row.swap(next_row);
     }
     return ret_vec;
}

bool Solution::VerifySquenceOfBST(std::vector<int> sequence) {
    size_t seq_size = sequence.size();
    if (seq_size < 1) {
        return false;
    }
    if (seq_size == 1) {
        return true;
    }
    if (seq_size == 2) {
        return true;
    }
    // if (seq_size == 3) {
    //     if (sequence[0] < sequence[2] 
    //         && sequence[1] > sequence[2]) {
    //             return true;
    //     } else {
    //         return false;
    //     }
    // }
    size_t left_boot_index = 0;
    for (size_t i = 0; (i < seq_size-1) && (sequence[i] < sequence[seq_size-1]); i++) {
        left_boot_index = i;
    }
    for (size_t i = left_boot_index+1; i < seq_size-1; i++) {
        if (sequence[i] < sequence[seq_size-1]) {
            return false;
        }
    }
    std::vector<int> left_sequence;
    std::vector<int> right_sequence;
    left_sequence.insert(left_sequence.begin(), sequence.begin(), sequence.begin()+left_boot_index+1);
    right_sequence.insert(right_sequence.begin(), sequence.begin()+left_boot_index+1, sequence.begin()+seq_size-1);

    bool left_result = true;
    bool right_result = true;
    if (left_sequence.size() > 0) {
        left_result = VerifySquenceOfBST(left_sequence);
    }
    if (right_sequence.size() > 0) {
        right_result = VerifySquenceOfBST(right_sequence);
    }
    bool recurrence_result = left_result && right_result;
    return recurrence_result;
}

std::string Solution::serialize(TreeNode* root) {
    std::string str_serialeze = "";
    std::vector<std::string> str_vec;

    get_serialize_vec(root, str_vec);
    // std::cout << "the size of str_vec is: " << str_vec.size() << std::endl;
    size_t last_index= 0;
    for (size_t i = 0; i < str_vec.size(); i++) {
        if (str_vec[i] != "null" && str_vec[i] != ",") {
            last_index = i;
        }
    }

    str_serialeze.append("[");
    for (size_t i = 0; i <= last_index; i++) {
        str_serialeze.append(str_vec[i]);
    }
    str_serialeze.append("]");
    return str_serialeze;
}

bool Solution::get_serialize_vec(TreeNode* root, std::vector<std::string>& str_vec) {
    if (root == NULL) {
        str_vec.emplace_back("null");
        str_vec.emplace_back(",");
        return true;
    }
    
    static std::vector<int> each_row;
    each_row.emplace_back(root->val);
    str_vec.emplace_back(std::to_string(root->val));
    str_vec.emplace_back(",");
    get_serialize_vec(root->left, str_vec);
    get_serialize_vec(root->right, str_vec);
    return true;
}

// Decodes your encoded data to tree.
TreeNode* Solution::deserialize(std::string data) {
    if (data.empty()) {
        TreeNode* test_node = NULL;
        return test_node;
    }
    std::vector<std::string> str_vec;
    for(int data_index = 1; data_index < data.size(); data_index++) {
        for (int j = data_index; j < data.size(); j++) {
            if (data[j] == ',' || data[j] == ']') {
                str_vec.emplace_back(data.substr(data_index, j-data_index));
                data_index = j;
                break;
            }
        }
    }
    int str_index = 0;
    TreeNode* root_node = creat_tree(str_vec, str_index);

    return root_node;
}

TreeNode* Solution::creat_tree(std::vector<std::string>& input_vec, int& index) {
    if (index >= input_vec.size()) {
        return NULL;
    }
    if (input_vec[index] == "null" ) {
        index = index +1;
        return NULL;
    }
    TreeNode* current_node = new TreeNode(std::stoi(input_vec[index]));
    index = index +1;
    current_node->left = creat_tree(input_vec, index);
    current_node->right = creat_tree(input_vec, index);
    return current_node;
}