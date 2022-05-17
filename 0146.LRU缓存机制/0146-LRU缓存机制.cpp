class LRUCache {
public:
    int mCap;
    list<pair<int, int>> mList;
    map<int, list<pair<int, int>>::iterator> mMap;
public:
    LRUCache(int capacity) {
        mCap = capacity;   
    }
    
    int get(int key) {
        if( mMap.find(key) == mMap.end() ) {
            return -1;
        }

        auto kv = *mMap[key];
        mList.erase(mMap[key]);
        mList.push_front(kv);
        mMap[key] = mList.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        if( mMap.find(key) == mMap.end() ) {
            if( mMap.size() == mCap ) {
                int lastKey = mList.back().first;
                mList.pop_back();
                mMap.erase(lastKey);
            }
            mList.push_front({key, value});
            mMap[key] = mList.begin();
        } else {
            mList.erase(mMap[key]);
            mList.push_front({key, value});
            mMap[key] = mList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */