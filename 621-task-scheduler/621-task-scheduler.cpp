class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        int size = t.size();
    vector<int> alpha(26);
    for(auto ch:t)
    {
        alpha[ch-'A']++;
    }
    
    priority_queue<int> pq; 
    
    for(auto x:alpha)
    {
        if(x>0)
            pq.push(x);
        
    }
    int count = 0;
    
    while(pq.size())
    {
        queue<int> q;
        int flag = 0;
        for(int i=0;i<=n;i++)
        {
            
            if(pq.size())
            {
                int x = pq.top();
                pq.pop();
                if(x>1)
                {
                    flag = 1;
                    q.push(x-1);
                }
                count++;
            }
            else if(flag)
            count++;
        }
        while(q.size())
        {
            int temp = q.front();
            q.pop();
            
            if(temp>0)
                pq.push(temp);
        }
    }
return count;
    }
};