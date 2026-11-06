class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=queries.size();
        vector<pair<int,int>>q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        unordered_map<int,int>mp;
        vector<int>ans(m);
        int l=0,r=0;
        int total=0;
        for(auto &it:q){
            int time=it.first;
            int idx=it.second;
            while(r<logs.size() && logs[r][1]<=time){
                mp[logs[r][0]]++;
                if(mp[logs[r][0]]==1) total++;
                r++;
            }
            while(l<r && logs[l][1]<time-x){
                mp[logs[l][0]]--;
                if(mp[logs[l][0]]==0) total--;
                l++;
            }
            ans[idx]=n-total;
        }
        return ans;
    }
};