class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, pair<int, int>> spanMap;
        vector< pair<char, pair<int, int>> > spansVec; 

        for( int i=0; i<S.size(); i++ ) {
            char c = S[i];
            if( spanMap.count(c) == 0 ) {
                spanMap[c].first = i;
                spanMap[c].second = i; 
            } else {
                spanMap[c].second = i;
            }
        }
        
        for( auto entry : spanMap ) {
            spansVec.push_back( entry );
        }

        vector<int> ans;
        sort( spansVec.begin(), spansVec.end(), cmp );

        for( auto [c, span] : spansVec ) {
            cout << c << ':' << span.first << ',' << span.second << endl;
            int n = ans.size();
            if( n == 0 ) {
                ans.push_back( span.second +1);
            } else {
                if( span.second < ans[n-1] ) {
                    continue;
                } else if( span.first < ans[n-1] ) {
                    ans[n-1] = span.second + 1;
                } else {
                    ans.push_back(span.second + 1);
                }
            }
        }

        for( int i=ans.size()-1; i>0; i-- ) {
            ans[i] = ans[i] - ans[i-1];
        }

        return ans;
    }


    static bool cmp( pair<char, pair<int, int>> & a, pair<char, pair<int, int>> & b) 
    { 
        return a.second.first < b.second.first; 
    } 
};