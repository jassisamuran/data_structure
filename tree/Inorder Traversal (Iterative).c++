class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int>ans;
        stack<Node*>s;
        while(root!=NULL || !s.empty()){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            ans.push_back(root->data);
            root=root->right;
        }
        return ans;
    }
};
// time complexity o(n)
// space complexity o(n)