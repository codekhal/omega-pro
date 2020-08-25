/* Solution has 2 cases: (If we had been given a Node as a whole then more efficient)

 Case1: There exists a right subtree for the given value of node
 then we just have to return the left most value (smallest val) from
 that right subtree
 
 Case2: There isn't any right subtree then we have to look at the 
 ansestors. Do going bottom to top isnt possible in a tree. So
 we maintain a leftTurn pointer and the last left turn we took
 to reach that element is our answer.
 
 Reference Vedio: https://www.youtube.com/watch?v=JdmAYw5h3G8
*/
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {

    // Base Cases
    if(A == NULL)
        return NULL;
    
    if(A->val == B)
        return A->right;
        
    // lets do an inorder traversal and find inorder successor
    stack<TreeNode*> stk;
    TreeNode *root = A;
 
    while(!stk.empty() || root != NULL)
    {
        if(root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
        
        else
        {
            TreeNode *currNode = stk.top();
            stk.pop();
            root = currNode->right;
            
            if(currNode->val == B)
            {
                if(currNode->right != NULL) // there exist a rightsubtree
                {
                    TreeNode* leftMostNode = currNode->right;
                    
                    while(leftMostNode->left != NULL)
                        leftMostNode = leftMostNode->left;
                    
                    return leftMostNode;
                }
                
                // else we follow case 2;
                
                else if(!stk.empty())
                {
                    return stk.top();
                }
            }
        }
    }
    
    return NULL;
}

// Time: O(n), since we only had a val and if we were given a node then it would be O(h), h is height of tree.
// Space: O(h)