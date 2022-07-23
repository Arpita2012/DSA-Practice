//reference - https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less_equall
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, 
            null_type,
            less_equal<int>, 
            rb_tree_tag,
             tree_order_statistics_node_update>
        ORDERED_SET;
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(),0);
        ORDERED_SET s;
        for(int i=nums.size()-1;i>=0;i--){
            s.insert(nums[i]);
            count[i] = s.order_of_key(nums[i]);
        }
        return count;
    }
};