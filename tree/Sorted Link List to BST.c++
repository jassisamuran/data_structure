class Solution{
  public:
    TNode *convert(int l,int r,vector<int>&v){
        if(l>r)return NULL;
        int mid=l+(r-l)/2;
        if((r - l)%2 != 0) mid = mid+1;
        TNode *node=new TNode(v[mid]);
        node->left=convert(l,mid-1,v);
        node->right=convert(mid+1,r,v);
        return node;
    }
    TNode* sortedListToBST(LNode *head) {
        vector<int>v;
        //code here
        while(head!=NULL){
            v.push_back(head->data);
            head=head->next;
        }
        return convert(0,v.size()-1,v);
    }
};
// time complexity o(n)
// space complexity o(n)