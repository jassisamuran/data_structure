class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0;
        int maxim=0;
        int last=0;
        for(int i=0; i<nums.size()-1; i++){
            maxim=max(maxim,nums[i]+i);

            if(i==last){
                last=maxim;
                cnt++;

            }
        }
    return cnt;
    }
};
// time complexity O(n)
// space commplexity O(1)