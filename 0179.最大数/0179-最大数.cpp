class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for( int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        sort( strNums.begin(), strNums.end(), [](const string& x, const string& y){
            return x+y > y+x;
        } );

        if( strNums[0] == "0" ) {
            return "0";
        }

        string ans;
        for( auto& strNum : strNums ) {
            ans += strNum;
        }

        return ans;
    }
};