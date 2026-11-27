class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n=timeSeries.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(timeSeries[i]+duration<=timeSeries[i+1]){
                ans+=duration;
            }else{
                ans+=timeSeries[i+1]-timeSeries[i];
            }
        }
        if(n>0){
            ans+=duration;
        }
        return ans;
    }
};