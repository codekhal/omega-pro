/* Problem: Check if a BST is valid or Not.

One brute force solution is to check left and right subtrees and every left tree node
 for if it is smaller than the root node's value and right subtree nodes as greater than
 root nodes's value.
 
 Better Solution is to use range. min and maxvalue (-inf, +inf) for the root node, 
 and root node as max valfor leftsubtree and root node as min value for rightsubtree.
 
*/
bool validBSTUtil(TreeNode* root, int minVal, int maxVal)
{
    if(root == NULL)
        return true;
        
    if(root->val >= minVal && root->val < maxVal 
    && validBSTUtil(root->left,minVal, root->val) 
    && validBSTUtil(root->right, root->val, maxVal))
    {
        return true;
    }
    
    return false;
}

int Solution::isValidBST(TreeNode* A) {
    
    return validBSTUtil(A,INT_MIN, INT_MAX);
    
}


// Time complexity : O(N), since we visit each node exactly once.
// Space complexity : O(N), since we keep up to the entire tree.
