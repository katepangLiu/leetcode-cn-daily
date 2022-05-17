class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> mapTickets;
    stack<string> st;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for( auto& ticket : tickets ) {
            mapTickets[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        vector<string> ans;
        while( !st.empty() ) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

    void dfs( string cur ) {
        while( mapTickets.count(cur) && mapTickets[cur].size() > 0 ) {
            string next = mapTickets[cur].top();
            mapTickets[cur].pop();
            dfs(next);
        }

        st.push(cur);
    }
};