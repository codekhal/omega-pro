/*
    Given a Binary Tree, print Left view of it. Left view of a Binary Tree is 
    set of nodes visible when tree is visited from Left side.

    Input: 10 30 20 (Level wise)
    Output: 10 30   (Left View)
*/
void leftSideView(Node *root, vector<int>& ans, int level, int &max_level)
{
    if(root == NULL)
        return;
        
    if(max_level < level) // for checking if we encountered a new level
    {
        ans.push_back(root->data);
        max_level = level;
    }
    
    // Moving to next level using recursion.
    leftSideView(root->left, ans, level + 1, max_level);
    leftSideView(root->right, ans, level + 1, max_level);
}
// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
    vector<int> ans;
    
    int max_level = 0;
    
    leftSideView(root, ans, 1, max_level);
    return ans;
}