#include "common.h"
#include "test_print.h"
#include "test_solution.h"

#include <gtest/gtest.h>

#include<iostream>
#include<vector>


TEST(testCase,test0){
    EXPECT_FALSE(check_inside());
}

TEST(testSwardToOffer,print_matrix){
    std::vector<std::vector<int>> input_matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    std::vector<int> out_test = {1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10};
    
    Solution solver;
    std::vector<int> out_put = solver.printMatrix(input_matrix);
    EXPECT_EQ(out_put, out_test);
}

TEST(testSwardToOffer,find_2d_array){
    std::vector<std::vector<int>> input_matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int targe = 5;
    Solution solver;
    EXPECT_EQ(true, solver.Find2dArray(targe, input_matrix));
    EXPECT_EQ(false, solver.Find2dArray(18, input_matrix));
}

TEST(testSwardToOffer,replace_space){
    ;
}

TEST(testSwardToOffer,printListFromTailToHead){
    std::vector<int> test_vector= {1, 2, 3, 4, 5, 6};
    ListNode *test_list = new ListNode(0);
    bool set_list_result = set_link_list(test_list, test_vector);
    // std::cout << "111" << std::endl;
    Solution solver;
    EXPECT_TRUE(set_list_result);
    // std::cout << test_vector.size() << std::endl;
    std::vector<int> reverted_vector = {6,5,4,3,2,1};
    EXPECT_EQ(reverted_vector, solver.printListFromTailToHead(test_list));
}

TEST(testSwardToOffer,reConstructBinaryTree){
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t21 = new TreeNode(2);
    TreeNode* t22 = new TreeNode(3);
    TreeNode* t31 = new TreeNode(4);
    TreeNode* t32 = new TreeNode(5);
    TreeNode* t33 = new TreeNode(6);
    TreeNode* t41 = new TreeNode(7);
    TreeNode* t42 = new TreeNode(8);
    t1->left = t21;
    t1->right = t22;
    t21->left = t31;
    t22->left = t32;
    t22->right = t33;
    t31->right = t41;
    t33->left = t42;
    
    Solution solver;
    std::vector<int> pre_vec = {1,2,4,7,3,5,6,8};
    std::vector<int> vin_vec = {4,7,2,1,5,3,8,6};
    TreeNode* return_node = solver.reConstructBinaryTree(pre_vec, vin_vec);
    
    EXPECT_EQ(1,return_node->val);
}

TEST(testSwardToOffer,stack_push_pop){

    std::vector<int> test_vec = {1,2,4,5,3};

    Solution solver;
    solver.push(test_vec[3]);
    solver.push(test_vec[1]);

    int result_1 = solver.pop();


    EXPECT_EQ(5,result_1);
}

int main(int argc,char **argv) {

    testing::InitGoogleTest(&argc,argv);
    int run_result = RUN_ALL_TESTS();

    return run_result;

}