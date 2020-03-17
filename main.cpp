/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        vector<int>bst;
        inorder(root,bst);
        int low,high;
        low=0;
        high=bst.size()-1;
        while(low<high)
        {
            if(bst[low]+bst[high]==k)
            {
                return true;
            }
            else if(bst[low]+bst[high]>k)
            {
                high--;
            }
            else if(bst[low]+bst[high]<k)
            {
                low++;
            }
        }
        return false;
    }
    void inorder(TreeNode* root,vector<int> &bst)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,bst);
        bst.push_back(root->val);
        inorder(root->right,bst);
    }
};
