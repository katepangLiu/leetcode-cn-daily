class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 0 ) {
            return s;
        }

        if( numRows == 1 ) {
            return s;
        }

        vector<string> rows( min(numRows, int(s.size())) ); //��ֹs�ĳ���С������;
        int curRow = 0;
        bool goingDown = false;

        for( char c : s ) {
            rows[curRow] += c;
            if( curRow == 0 || curRow == (numRows -1) ) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for( string row : rows ) {
            ret += row;
        }

        return ret;
    }
};