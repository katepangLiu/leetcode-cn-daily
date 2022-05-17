class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if( n< 2 ) {
            return 0;
        }

        int area = 0;
        stack<int> st;

        st.push(0);
        //[1, n] ��Ϊ 0 �� n+1 �����ģ�����Խ������Ӱ��;
        for( int i=1; i<n; i++ ) {
            while( !st.empty() && height[i] >= height[st.top()] ) {
                int cur = st.top();
                st.pop();
                if( st.empty() ) {
                    break;
                }

                int l = st.top();
                int r = i;
                int h = min( height[l], height[r]) - height[cur];
                int w = r-l-1; 
                area += h*w;
            }
            st.push(i);
        }

        return area;
    }
};