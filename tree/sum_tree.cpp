class Solution
{
    public:
    unordered_map<Node*,int>m;
    
    int sum( Node *root)
    {
        if (root == NULL)
            return 0;
            if(m[root]){
                return m[root];
            }
         
        return sum(root->left) + root->data +
               sum(root->right);
    }
    int isSum(Node* node)
    {
        int ls, rs;
     
        // If node is NULL or it's a leaf
        // node then return true 
        if (node == NULL ||
           (node->left == NULL && 
            node->right == NULL))
            return 1;
     
       // Get sum of nodes in left and
       // right subtrees 
       ls = sum(node->left);
       rs = sum(node->right);
     
       // If the node and both of its 
       // children satisfy the property 
       // return 1 else 0
        if ((node->data == ls + rs) &&
              isSum(node->left) &&
              isSum(node->right))
            return 1;
     
       return 0;
    }
    bool isSumTree(Node* root)
    { 
         // Your code here
         return isSum(root);//o(n)time complexity o(n)space complexity
    }
};
