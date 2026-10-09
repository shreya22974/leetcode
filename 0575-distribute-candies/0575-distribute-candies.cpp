class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int>st;
        for(int x:candyType){
            st.insert(x);
        }
        return min(n/2,(int)st.size());
    }
};