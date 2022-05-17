class Solution {
public:
    string reorderSpaces(string text) {
        int nWord = 0;
        int nSpace = 0;
        int n = text.length();
        vector<string> words;
        
        int i=0;;
        while( i < n ) {
            int j = i;
            while( j<n && text[j] == ' ' ) {
                j++;
            }
            nSpace += j-i;
            i = j;
            while( j<n && text[j] != ' ' ) {
                j++;
            }
            if( j - i > 0 ) {
                words.emplace_back( text.substr(i, j-i) );
                //cout << words[nWord] << endl;
                nWord++;
            }
            i = j;
        }
        
        cout << nWord << ',' << nSpace << endl;
        
        int avgSpace = 0;
        int leftSpace = 0;
        if( nWord == 1 ) {
            leftSpace = nSpace;
        } else {
            avgSpace = nSpace/(nWord-1);
            leftSpace = nSpace%(nWord-1);
        }

        string strAvgSpace = "";
        string strLeftSpace = ""; 
        for( int i=0; i<avgSpace; i++ ) {
            strAvgSpace.push_back(' ');
        }
        for( int i=0; i<leftSpace; i++ ) {
            strLeftSpace.push_back(' ');
        }
        
        string ans = words[0];
        for( int i=1; i< nWord; i++ ) {
            ans += strAvgSpace + words[i];
        }
        ans += strLeftSpace;
        
        return ans;
        
    }
};