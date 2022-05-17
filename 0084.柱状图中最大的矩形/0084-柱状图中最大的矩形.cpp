class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> newHeights(n+2);

        for( int i=0; i<n; i++ ) {
            newHeights[i+1] = heights[i];
        }

        stack<int> st;
        st.push(0);
        int maxArea = 0;

        for( int i=1; i<n+2; i++ ) {
            while( newHeights[i] < newHeights[st.top()] ) {
                int h = newHeights[st.top()] ;
                st.pop();
                int r = i;
                int l = st.top();
                int area = h*(r-l-1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};