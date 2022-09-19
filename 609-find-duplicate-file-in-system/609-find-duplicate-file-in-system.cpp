class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        map<string, vector<string>> M;
        
        for(auto & p: paths){
            
            stringstream stream(p);
            string filepath;
            string s;
            getline(stream, filepath, ' ');
            while (getline(stream, s, ' ')) {
                string fname = filepath + '/' + s.substr(0, s.find('('));
                string fcontent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                M[fcontent].push_back(fname);
            }

        }
        
        vector<vector<string>> ans;
        
        for(auto & m : M){
            if(m.second.size()>=2){
                ans.emplace_back(m.second);
            }
        }
        
        
        return ans;
        
        
    }
};