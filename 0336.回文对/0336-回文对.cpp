class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if( n <2 ) {
            return ans;
        }

        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( i == j ) {
                    continue;
                }
                if( isPalindromePair(words[i], words[j]) ) {
                    ans.push_back( {i, j} );
                }
            }
        }

        return ans;
    }

    bool isPalindromePair(string& word1, string& word2) {
        int m = word1.size();
        int n = word2.size();
        int i = 0;
        int j = n-1;

        while( i < m && j >= 0  ) {
            if( word1[i] != word2[j] ) {
                return false;
            }

            i++;
            j--;
        }

        if( i < m ) {
            j = m-1;
            while( i < j ) {
                if(word1[i] != word1[j]) {
                    return false;
                }
                i++;
                j--;
            } 
        }else if( j > 0 ) {
            i = 0;
            while( i < j ) {
                if(word2[i] != word2[j]) {
                    return false;
                }
                i++;
                j--;
            } 
        }

        return true;
    }
};