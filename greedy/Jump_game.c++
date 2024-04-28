class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist=nums[0];
        if(nums.size()==1)return 1;
        for(int i=0;i<nums.size(); i++){
            dist--; 
            if(dist==-1)return 0; 
            if(dist<nums[i])dist=nums[i];
        }    
        return 1;
    }
};
// time complexity o(n)
// space complexity o(1)