class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
	
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
		// most time we do not go inside this if condition
		// therefore pop takes O(1)
		// this is the meaning of amortized O(1)
		
        if(s2.empty()){
            while(!s1.empty()){
			// we take all elements of s1 and put it into 2nd stack so that order is reversed
			// and we get queue behavior
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
		// most time we do not go inside this if condition
		// therefore peek takes O(1)
		// this is the meaning of amortized O(1)
		
        if(s2.empty()){
            while(!s1.empty()){
				// we take all elements of s1 and put it into 2nd stack so that order is reversed
				// and we get queue behavior
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};