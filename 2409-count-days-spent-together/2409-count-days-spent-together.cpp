class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start=max(arriveAlice,arriveBob);
        string end=min(leaveAlice,leaveBob);
        if(start>end){
            return 0;
        }
        int days[]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int count=0;
        int startMonth=stoi(start.substr(0,2));
        int startDay=stoi(start.substr(3,2));

        int endMonth=stoi(end.substr(0,2));
        int endDay=stoi(end.substr(3,2));

        for(int i=1;i<startMonth;i++){
            startDay+=days[i];
        }
        for(int i=1;i<endMonth;i++){
            endDay+=days[i];
        }
        count=endDay-startDay+1;

        return count;
    }
};