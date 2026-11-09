class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int largest=INT_MIN;
        int second_largest=INT_MIN;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>largest){
                second_largest=largest;
                largest=nums[i];
                index=i;
            }else if(nums[i]>second_largest){
                second_largest=nums[i];
            }
        }
        if(largest>=2*second_largest){
            return index;
        }
        return -1;
    }
};