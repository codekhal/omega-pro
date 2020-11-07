// Iterative: Preorder -> root | left | right

vector<int> preorderTraversal(TreeNode* root) {
    
    vector<int> ans;        
    
    if(root == NULL)
        return ans;
    
    stack<TreeNode*> stk;
    // we intially push the root
    stk.push(root);
    
    while(!stk.empty())
    {
        TreeNode* visited = stk.top();
        stk.pop();
        // we push root's value in the ans vector
        ans.push_back(visited->val);
        
        // we take care of right child first since we want left to be
        // above right in the stack because that's how preoder
        // traversal works. So when we pop fromthe stk we would get
        // left child first then right child.
        
        if(visited->right != NULL)
            stk.push(visited->right);
        
        if(visited->left != NULL)
            stk.push(visited->left);
        
    }
    
    return ans;
}