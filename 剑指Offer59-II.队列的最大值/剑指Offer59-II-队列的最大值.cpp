class MaxQueue {
private:    
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if( !d.empty() ){
            return d.front();
        }
        return -1;
    }
    
    void push_back(int value) {
        q.push(value);
        while( !d.empty() && d.back() < value  ){
            d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if( q.empty() ){
            return -1;
        }

        int value = q.front();
        q.pop();

        if( !d.empty() && d.front() == value ) {
            d.pop_front();
        }

        return value;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */