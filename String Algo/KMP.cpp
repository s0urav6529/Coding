
/// Idea : Finding the longest suffix from any index s[i] which is also a proper prefix from s[0]

/// Proper prefix means not the whole sub-string that are started from index s[i]

///complexity of kmp algorithm is O(n+m) where n is the lenght of the text and m is the lenght of the pattern.
///o(m) needed to built the suffix and the perfix array;
/// and o(n) is needed to search the pattern in the text;
///video source tusher

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e6+5;
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

void kmp(string s,string p){

    string ss = p + "?" + s;    /// s is the larger text  & p the searching pattern/word
    int n=ss.size();
    vector<int> pi(n);

    for(int i=1;i<n;i++){

        int j=pi[i-1];
        
        while(j>0 && ss[i]!=ss[j])
            j = pi[j-1];

        if (ss[i]==ss[j])
            j++;
        
        pi[i] = j;
    }
    
    int cnt=0;
    
    for(int i=p.size();i<n;i++){

        if(pi[i]==p.size()) cnt++;
    }
    
    if(cnt) cout<<"YES"<<" "<<cnt<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    
    fast;
    int q;
    string s,p;
    cin>>s >> q;   /// s = text & q = no of queries
    while(q--) {
        cin>>p;   /// searching pattern
        kmp(s,p); 
    }
    return 0;
}





