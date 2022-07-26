class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        /*stringstream s_in_stream (s);
        
        vector<string>words;
        
        string temp;
        
        while(getline(s_in_stream, temp, ' '))
        {
            words.push_back(temp);
        }
        
        //map<char,string> m;
        
        if(pattern.length()!=words.size()){
            return false;
        }
        
        int N= words.size();
        
        map<string,int> m_p;
        map<string,int> m_s;
        
        for(int i=0; i<N; i++){
            if(m_p.find(pattern[i])==m_p.end()){
                m_p[pattern[i]]
            }
        }
        

        
        // for(int i=0; i<N; i++){
        //     if(m.find(pattern[i])==m.end()){
        //         m[pattern[i]]=words[i];
        //     }else if((m.find(pattern[i])!=m.end()) && (m[pattern[i]].compare(words[i])!=0)  )   {
        //         return false;
        //     }
        // }
        
        map<string,char> m;
        for(int i=0; i<N; i++){
            if(m.find(words[i])==m.end()){
                cout<<"H2";
                m[words[i]]=pattern[i];
            }else if((m.find(words[i])!=m.end()) && (m[words[i]]!=pattern[i])  )   {
                cout<<words[i]<<endl;
                return false;
            }
        }
        
        cout<<"--------------------------";
        cout<<m.size()<<endl;
        for(auto x: m){
            cout<<x.first<<" "<<x.second<<endl;
        }
        
                return true;

        */
        
         map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(s);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
    }
};