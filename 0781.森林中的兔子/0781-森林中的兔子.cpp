class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> colorCounts;
        for( int answer : answers ) {
            int count = answer + 1;
            colorCounts[count]++;
            //cout << count << ':' << colorCounts[count]  << endl;
        }

        int ans = 0;
        for( auto [count, countCount] : colorCounts ) {
            //cout << count << ':' << countCount << endl;
            int realCountCount = countCount/count;
            if( countCount%count!=0 ) {
                realCountCount += 1;
            }
            ans += count*realCountCount ;
        }

        return ans;
    }
};