class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long max=0;
        long long min =0;
        for(int i=0;i<n;i++){
            nums[i]=1LL*nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=(n/2);i--){
           max+=nums[i];
        }
        for(int i=0;i<=(n/2)-1;i++){
            min+=nums[i];
        }
        return max-min;
    }
};