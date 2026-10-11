class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int a=stones.back();
            stones.pop_back();
            int b= stones.back();
            stones.pop_back();
            if(a!=b){
                stones.push_back(abs(a-b));
            }
        }
       return stones.empty()? 0: stones[0]; 
    }
};