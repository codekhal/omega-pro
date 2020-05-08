/* 
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

*/

int finding_height(TreeNode* root, int &parent, int value, int height)
{
    if(!root)
        return 0;
    
    if(root->val == value) // If we got root node then return height = 0.
        return height;
    
    // We are passing parent by reference therefore if element found the the returned 
    // value won't change.
    parent = root->val;
    
    int left = finding_height(root->left,parent,value,height+1);
    
    if(left) // It indicates the element x is found in the left side if left != 0. 
        return left;
    
    parent  = root->val;
    int right = finding_height(root->right,parent,value,height+1);
    
    return right;
    
}

bool isCousins(TreeNode* root, int x, int y) {
    
    /* For cousins:
        - Height Should be same
        - Parent should be diffrent
    */

    if(root->val == x || root->val == y)
        return false;
    
    int parent = -1;

    int xheight = finding_height(root,parent,x,0);
    
    int yparent = -1;
    
    int yheight = finding_height(root,yparent,y,0);
    
    if(yparent != parent and xheight == yheight)
        return true;
    
    return false;
    
    
}