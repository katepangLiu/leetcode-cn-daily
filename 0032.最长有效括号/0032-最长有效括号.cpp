class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length()];
        memset(dp,0,sizeof(dp));
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]=='('){
                if(s[i+1]=='('){
                    int pos=dp[i+1]+1+i;
                    if(s[pos]==')'){
                        dp[i]=dp[i+1]+2+dp[pos];
                    }
                }else{
                    dp[i]=dp[i+1]+2;
                }
            }
            else{
                if(s[i+1]=='('){
                    dp[i]=dp[i+1];
                }
            }
        }
        int res=0;
        for(int i=0;i<s.length();i++){
            res=max(res,dp[i]);
        }
        return res;
    }
};