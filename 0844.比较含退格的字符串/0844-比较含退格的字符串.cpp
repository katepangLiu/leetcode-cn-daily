class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> sS;
        stack<char> sT;
        for( auto c : S ) {
            if( c == '#' ) {
                if( !sS.empty() ) {
                    sS.pop();         
                }
            }else {
                sS.push(c);  
            }
        }

        for( auto c : T ) {
            if( c == '#' ) {
                if( !sT.empty() ) {
                    sT.pop() ;               
                }
            }else {
                sT.push(c);    
            }
        }

        while(  !sS.empty() && !sT.empty() ) {
            if( sS.top() != sT.top() ) {
                return  false;
            }
            sS.pop();
            sT.pop();
        }

        return sS.empty() && sT.empty();
    }
};