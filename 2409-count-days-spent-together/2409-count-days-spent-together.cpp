class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Days in each month for a non-leap year
        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto convertToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int aliceArrival = convertToDayOfYear(arriveAlice);
        int aliceLeave = convertToDayOfYear(leaveAlice);
        int bobArrival = convertToDayOfYear(arriveBob);
        int bobLeave = convertToDayOfYear(leaveBob);
        
        int overlapStart = max(aliceArrival, bobArrival);
        int overlapEnd = min(aliceLeave, bobLeave);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};