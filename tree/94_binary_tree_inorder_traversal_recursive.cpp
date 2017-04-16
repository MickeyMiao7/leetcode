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
        vector<int> inorderTraversal(TreeNode *root){
            vector<int> result;
            stack<TreeNode *> s;
            TreeNode *p = root;
            while(p != NULL || !s.empty()){
                if(p != NULL){
                    s.push(p);
                    p = p->left;
                }
                else{
                    p = s.top();
                    s.pop();
                    result.push_back(p->val);
                    p = p->right;
                }

            }
            return result;
        }
          
};

int main(){
    Solution sol;
    return 0;
}
