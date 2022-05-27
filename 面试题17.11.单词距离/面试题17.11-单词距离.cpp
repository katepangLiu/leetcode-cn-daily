class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, list<int>> dict;
        for( int i=0; i< words.size(); i++ ) {
            auto word = words[i];
            auto l = &dict[word];
            auto it = l->begin();
            for( ; it!= l->end(); it++ ) {
                if( i < *it ) {
                    break;       
                }
            }
            l->insert(it, i);
        }

        auto l1 = &dict[word1];
        auto l2 = &dict[word2];
        auto it1 = l1->begin();
        auto it2 = l2->begin();
        int ans = INT_MAX;

        while( it1 != l1->end() && it2 != l2->end() ) {
            ans = min( abs(*it1-*it2), ans);
            if( *it1 > *it2 ) {
                it2 ++;
            } else {
                it1++;
            }
        }
        
        return ans;

    }
};