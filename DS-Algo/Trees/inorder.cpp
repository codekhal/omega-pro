// Iterative: Inorder -> left | root | right

vector<int> inorderTraversal(TreeNode* root) 
{

    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<TreeNode*> stk;

    while(!stk.empty() || root != NULL)
    {
        while(root != NULL) // travel as left as possible
        {
            stk.push(root); // pushing root seen so far into the stack
            root = root->left;
        }
        
        root = stk.top(); // since root was null we intialise to a new node
        stk.pop();
        // we have travelled left and now between we are going in drawing
        // so we have our inorder with us.
        ans.push_back(root->val); 
        root = root->right; // we traverse right of the subtree.
    }

    return ans;
}