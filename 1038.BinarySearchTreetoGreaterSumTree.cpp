#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int sum = 0;

    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};

// Helper function to print the tree in-order
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        std::cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    Solution solution;

    // Creating a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    std::cout << "Original BST (in-order): ";
    printInOrder(root);
    std::cout << std::endl;

    TreeNode* newRoot = solution.bstToGst(root);

    std::cout << "Greater Sum Tree (in-order): ";
    printInOrder(newRoot);
    std::cout << std::endl;

    // Clean up memory
    // (in a real-world scenario, you'd want to delete the nodes to avoid memory leaks)
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
