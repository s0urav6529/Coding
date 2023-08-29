https://leetcode.com/problems/minimum-penalty-for-a-shop/description/


class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int prefix[n+1];

        prefix[0] = (customers[0] == 'Y') ? 1 : 0; 
        int ans = 1e9 , h = 0;

        for(int i=1;i<n;i++){
            
            prefix[i] = ((customers[i] == 'Y') ? 1 : 0) + prefix[i-1];

        }
        prefix[n] = prefix[n-1];

        for(int i=0;i<=n;i++){
            
            int No = 0 , Yes = prefix[n];
            if(i > 0){
                No = i - prefix[i-1];
            }
            if(i > 0){
                Yes  -= prefix[i-1];
            }

            if(ans > (No + Yes)){
                ans = No + Yes;
                h = i;
            }
        }

        return h;
    }
};
