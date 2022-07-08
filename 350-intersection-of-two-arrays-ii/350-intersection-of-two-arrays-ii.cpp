class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     
        unordered_map<int,int> map;
        vector<int> res;
        for(int i:nums1){
            if(map.find(i)!=map.end())
                map[i]+=1;
            else
                map[i]=1;
        }
        
        for(int i:nums2){
            if(map.find(i)!=map.end() and map[i]!=0){
                res.push_back(i);
                map[i]-=1;
            }
        }
        return res;
        
    }
};