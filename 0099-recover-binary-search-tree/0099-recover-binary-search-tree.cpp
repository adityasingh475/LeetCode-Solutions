class Solution {
public:
    TreeNode *first=NULL,*middle=NULL,*last=NULL,*prev=NULL;

    void inorder(TreeNode* root) {
        if(root==NULL)
            return;

        inorder(root->left);

        if(prev!=NULL && prev->val>root->val) {
            if(first==NULL) {
                first=prev;
                middle=root;
            } else {
                last=root;
            }
        }

        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if(last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna