class Solution {
public:
    int digitSum(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end(),[&](int a, int b){
            if(digitSum(a)==digitSum(b)){
            return a<b;
            }
            return digitSum(a) < digitSum(b);
        });
        unordered_map<int,int>pos;
        for(int i=0;i<n;i++){
            pos[nums[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=sorted[i]){
                swaps++;
                int j=pos[sorted[i]];
                pos[nums[i]]=j;
                pos[sorted[i]]=i;
                swap(nums[i],nums[j]);
            }
        }
        return swaps;
    }
};