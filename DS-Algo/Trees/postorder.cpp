/* Iterative: Inorder -> left | root | right
    Method 1: 
        We can iterate the tree in preorder but little different: 
        root --> right --> left . Than reverse it:

*/

vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> result;
    if(root == NULL) return result;
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()) 
    {
        TreeNode* cur = stk.top();
        result.push_back(cur->val);
        stk.pop();

        if(cur->left) stk.push(cur->left);

        if(cur->right) stk.push(cur->right);
    }

    reverse(result.begin(), result.end());
    
    return result;
}