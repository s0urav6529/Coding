

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int main()
{
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>lis;
        lis.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(lis.back()<a[i]) lis.push_back(a[i]);
            else
            {
                int indx=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();

                lis[indx]=a[i];
            }
        }

        set<int>s;
        for(int i=0;i<lis.size();i++) s.insert(lis[i]);

        cout<<s.size()<<endl;
    }
    return 0;
}





