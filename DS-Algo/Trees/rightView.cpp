/*
    Given a Binary Tree, print right view of it. Right view of a Binary Tree is 
    set of nodes visible when tree is visited from right side.

    Input: 10 30 20 (Level wise)
    Output: 10 20   (Left View)
*/

// BFS way is much more intuitive. Do the level order traversal, and add the last node on every layer
    
vector<int> rightSideView(TreeNode* root) {
    
    vector<int> result;
    
    if(!root)
        return result;
    
    queue<TreeNode*> qu;
    qu.push(root);
    
    while(!qu.empty())
    {
        int size = qu.size(); // helps finding level of the tree
        int i=0;
        while(i++ < size) // visiting all the nodes on a level
        {
            TreeNode* visited = qu.front();
            qu.pop();
            
            // In case of left view i should be equal to 0 for it.
            // That's the only difference.
            if(i == size) // we are at the final node of that level
                result.push_back(visited->val);
            
            if(visited->left)
                qu.push(visited->left);
            
            if(visited->right)
                qu.push(visited->right);
        }
    }
    
    return result;
}