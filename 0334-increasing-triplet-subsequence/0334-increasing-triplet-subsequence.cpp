class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;
        
        for(int num : nums){
            if(num <= one)
                one = num;
            else if(num <= two)
                two = num;
            // there is a number that exceeds the first and second values
            else
                return true;
        }
        
        return false;
    }
};