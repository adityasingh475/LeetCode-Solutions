class Solution {
public:

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size()==0)
            return NULL;

        int rootValue=postorder[postorder.size()-1];

        TreeNode* root=new TreeNode(rootValue);

        int index=0;

        while(inorder[index]!=rootValue)
            index++;

        vector<int> leftInorder;
        vector<int> rightInorder;

        for (int i=0; i<index; i++)
            leftInorder.push_back(inorder[i]);

        for (int i=index+1; i<inorder.size();i++)
            rightInorder.push_back(inorder[i]);

        vector<int> leftPostorder;
        vector<int> rightPostorder;

        for (int i=0; i<index; i++)
            leftPostorder.push_back(postorder[i]);

        for (int i=index; i<postorder.size()-1; i++)
            rightPostorder.push_back(postorder[i]);

        root->left=solve(leftInorder, leftPostorder);
        root->right=solve(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, postorder);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna