

///complexity of kmp algorithm is O(n+m) where n is the lenght of the text and m is the lenght of the pattern.
///o(m) needed to built the suffix and the perfix array;
/// and o(n) is needed to search the pattern in the text;
///video source tusher

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define limit 1000006
int n;


//bool kmp(string t,string p)
//{
//    int lps[p.size()+5]; ///lps=longest prefix and suffix array
//    memset(lps,0,sizeof(lps));
//    ///built the longest prefix & suffix array
//    int i=0;
//    for(int j=1;j<p.size();)
//    {
//        if(p[i]==p[j])
//        {
//            lps[j]=i+1;
//            i++;
//            j++;
//        }
//        else
//        {
//            if(i==0)
//            {
//                lps[j]=0;
//                j++;
//            }
//            else
//            {
//                i=lps[i-1];
//            }
//        }
//    }
//
//    ///searching the pattern exist or not
//
//    i=0;
//    int j=0; ///i for text and j for pattern
//    while(i<t.size() && j<p.size())
//    {
//        if(t[i]==p[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            if(j!=0)
//            {
//                j=lps[j-1];
//            }
//            else i++;
//        }
//    }
//    if(j==p.size()) return true;
//    return false;
//}

void kmp(string t,string p)
{
    string s=p+"?"+t;
    int n=s.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];

        if (s[i]==s[j])
            j++;
        pi[i] = j;
    }
    int cnt=0;
    for(int i=p.size();i<n;i++)
    {
        if(pi[i]==p.size()) cnt++;
    }
    if(cnt) cout<<"YES"<<" "<<cnt<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    fast;
    int tc=1;
    string t,p;
    cout<<"Enter the text"<<endl;
    cin>>t;
    cout<<"No of query"<<endl;
    cin>>tc;
    cout<<"Enter Searching Pattern"<<endl;
    while(tc--) {
        cin>>p;
        kmp(t,p);
    }
    return 0;
}





