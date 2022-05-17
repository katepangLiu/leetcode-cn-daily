using my_pair_t = pair<int, int>;
using my_container_t = vector<my_pair_t>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int ,int> numFreqMap;

        for( int& num : nums ) {
            numFreqMap[num]++;
        }

        std::priority_queue<my_pair_t, my_container_t, decltype(&cmp)> q(cmp);
        for( auto& [num, freq] : numFreqMap ) {
            if( q.size() == k ) {
                if( freq > q.top().second ) {
                    q.pop();
                    q.emplace(num, freq); 
                }
                
            } else {
                q.emplace(num, freq); 
            }
        }

        vector<int> ans;
        while( !q.empty() ) {
            ans.push_back( q.top().first );
            q.pop();
        }

        return ans;
    }

    static bool cmp( pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};