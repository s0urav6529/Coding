https://leetcode.com/problems/contiguous-array/description/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        map<int, int>pos;
        set<int>ache;
        
        ache.insert(0);
        pos[0] = -1;

        int n = nums.size(), sum = 0, ans = 0;

        for(int i=0;i<n;i++){

            int x = 1;
            if(nums[i] == 0) x = -1;

            sum += x;

            if(ache.count(sum) > 0){
                ans = max(ans, i - pos[sum]);
            }else {
                pos[sum] = i;
            }
            ache.insert(sum);
            
        }

        return ans;



    }
};
