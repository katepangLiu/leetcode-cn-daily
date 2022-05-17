class Solution {
public:
    map<char, string> dict = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if( digits.length() == 0 ) {
            return {};
        }
        bacetrace(digits, "", 0 );
        return ans;
    }

    void bacetrace(string digits, string tmp, int i ) {
        if( i == digits.length() ) {
            ans.push_back(tmp);
            return;
        }

        cout << digits[i] << endl;
        cout << dict[digits[i]] << endl;

        for( auto c : dict[digits[i]] ) {
            cout << c << endl;
            string newTmp = tmp + c;
            bacetrace(digits, newTmp, i+1 );
        }
    }
};