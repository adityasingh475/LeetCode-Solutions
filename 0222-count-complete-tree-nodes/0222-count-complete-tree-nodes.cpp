/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findleftHeight(TreeNode* root) {
        int h=0;

        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }    

    int findrightHeight(TreeNode* root) {
        int h=0;

        while(root!=NULL){
            h++;
            root=root->right;
        }
        return h;
    }   

     int countNodes(TreeNode* root) {

        if(root == NULL)
            return 0;

        int leftHeight = findleftHeight(root);
        int rightHeight = findrightHeight(root);
        
        int h=0;
        if(leftHeight == rightHeight) {
            return pow(2,rightHeight)-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};  

       
       

       

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna