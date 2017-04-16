#include <iostream>
#include <vector>
#include <stack>
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
        vector<int> preorderTraversal(Tree *root){
            vector<int> result;
            TreeNode *cur = root;
            while(cur){
                if(cur->left == NULL){
                    result.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    TreeNode *node = cur->left;
                    while(node->right != NULL && node->right != cur)
                        node = node->right;
                    if(node->right == NULL){
                        result.push_back(cur->val);
                        node->right = cur;
                        cut = cur->left;
                    }
                    else
                        cur = cur->right;

                }
            }
            return result;

        }
          
};

int main(){
    Solution sol;
    return 0;
}
