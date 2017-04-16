#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        bool isSameTree(TreeNode *p, TreeNode *q){
            if(!p || !q) return p == q;
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
          
};

int main(){
    Solution sol;
    return 0;
}
