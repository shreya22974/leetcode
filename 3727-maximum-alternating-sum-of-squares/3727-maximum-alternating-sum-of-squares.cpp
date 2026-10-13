class Solution {
public:
// INSTEAD OF SORTING COMPLETELY WE CAN PARTIALLY SORT USING THE NTH_ELEMENT 
    long long maxAlternatingSum(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
        nums[i]=nums[i]*nums[i];
       }
       nth_element(nums.begin(),nums.begin()+n/2,nums.end());
       long long largeHalf=accumulate(nums.begin()+n/2,nums.end(),0LL);
       long long smallHalf=accumulate(nums.begin(),nums.begin()+n/2,0LL);

       return largeHalf-smallHalf;
    }
};