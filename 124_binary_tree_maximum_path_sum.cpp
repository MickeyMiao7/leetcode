#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
    private:
        int calculate(TreeNode *root, int &result){
            if (root == 0) return 0;
            int leftMax = max(0, calculate(root->left, result));
            int rightMax = max(0, calculate(root->right, result));
            result = max(result, leftMax + rightMax + root->val);
            return max(leftMax, rightMax) + root->val;

        }

    public:
        int maxPathSum(TreeNode *root){
            int result = -2147483648;
            calculate(root, result);
            return result;
        }
          
};

int main(){
    Solution sol;
    return 0;
}
