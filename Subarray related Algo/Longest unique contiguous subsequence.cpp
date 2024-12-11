#include<bits/stdc++.h>
using namespace std;
#define rep(i,k)  for (int i=1 ; i<=k ; i++)


void solution(int t){

    int n;
    cin>>n;
    int a[n+5];
    rep(i,n) cin>>a[i];
    map<int,int>p;
    int ans=1,mn=1;

    rep(i,n){

        if(p[a[i]]==0){
            ans=max(ans,abs(i-mn+1));
            //cout<<mn<<" "<<abs(i-mn+1)<<endl;
        }
        else{
            int pos=p[a[i]];
            if(pos>=mn)
                mn=max(mn+1,pos+1);
            ans=max(ans,abs(i-mn+1));
            //cout<<mn<<" "<<abs(i-mn+1)<<endl;
        }
        p[a[i]]=i;
    }
    cout<<ans<<endl;

    return;
}
int main()
{
    solution(t);
    return 0;
}


