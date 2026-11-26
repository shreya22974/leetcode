class Solution {
public:
    bool canAliceWin(int n) {
        int move=10;
        int count=0;
        while(n>=move){
            n-=move;
            move--;
            count++;
        }
        return count%2==1;
    }
};