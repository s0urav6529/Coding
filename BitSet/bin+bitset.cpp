#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){

        int n;
        cin >> n;

        int cnt[n+5][30];

        memset(cnt,0,sizeof cnt);


        for(int i=1;i<=n;i++){

            int x;
            cin >> x;

            for(int j=0;j<30;j++){

                int add = 0;

                if(x & (1<<j)){

                    add=1;
                }

                cnt[i][j] = cnt[i-1][j] + add;

            }

        }

        int l = 1, r = n-1, ans = -1;

        while(l<=r){


            int mid = l + (r - l) / 2;
            bool ok = false;

           // cout << mid <<endl;

            for(int i = 1 ; (i+mid-1)<=n ; i++){

                int f = i+mid-1 , subsum = 0, leftsum = 0 ,add = 1 ;

                for(int j=0 ; j<30 ; j++){

                    if(cnt[f][j]-cnt[i-1][j] > 0){

                        subsum += add;
                    }

                    if((cnt[n][j]-cnt[f][j] > 0) || (cnt[i-1][j] > 0)) leftsum += add;

                    add+=add;

                }

                if(subsum == leftsum) {

                    ok = true;
                    break;
                }

                //cout << l <<" "<< r<<" "<<i<<" "  <<" "<<f << " "<< subsum <<" "<<leftsum<<endl;


            }
            if(ok){

                ans = max(ans , mid);

                l = mid + 1;

            }
            else r = mid - 1;

        }

        cout << ans <<endl;


    }

    return 0;
}

