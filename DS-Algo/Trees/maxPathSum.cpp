/*
Binary Tree Maximum Path Sum (Leetcode: 124)
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node 
in the tree along the parent-child connections. The path must contain at least one node 
and does not need to go through the root.
*/

/* We can think of a *Bottom Up Approach* for this.
        
        For a subtree we can have sum of the left part, right part, just curr
        node's value(if it is a leaf node) or all three of them (like Eg.1)
        
        we have: x + y + nodes->val for a subtree and we pass it to the parent 
        node. So we store a global max and check which path gives greater 
        value.
    */
    
    int maxAns;
    int returnMax(TreeNode* root) // dfs
    {
        if(!root) // No modes are present
            return 0;
        
        int leftSubTreeSum = returnMax(root->left);
        int rightSubTreeSum = returnMax(root->right);
        
        // maxAns can we root value plus left and right subtree nodes
        maxAns = max(maxAns, leftSubTreeSum + rightSubTreeSum + root->val);
        
        return max (0 , root->val +  max(leftSubTreeSum, rightSubTreeSum));
    }
    
    int maxPathSum(TreeNode* root) {
        
        maxAns = INT_MIN;
        
        returnMax(root);
        
        return maxAns;
    }
};

/* Last lines Explaination:
maxValue is the value which recording whether this current root is the final 
root, so we use left + right + node.val. But to the upper layer(after return 
statement), we cannot choose both left and right brunches, so we need to 
select the larger one, so we use max(left, right) + node.val to prune the 
lower brunch.
     
*/