class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int n=s.size();
        int count=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }else{
                if(count>0){
                    count--;
                }else{
                   ans++;
                }
                 if(i+1<n && s[i+1]==')'){ 
                       i+=2; 
                 }else{
                    ans++;
                    i++;
                 }
            }
        }
        return ans+2*count;
    }
}; 