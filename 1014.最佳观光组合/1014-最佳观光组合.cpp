class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore = 0;
        int dp = A[0] + 0; //A[i] + i的最大值，初识为 i=0;
        for (int j = 1; j < A.size(); ++j) {
            int score = dp + A[j] - j;
            maxScore = max( maxScore, score  );
            dp = max(dp, A[j]+j );
        }
        return maxScore;
    }
};