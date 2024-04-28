class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0;int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
    
};
// time complexity o(n)
// space complexity o(1)