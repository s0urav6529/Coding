#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<string,int>>v;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)v.push_back({s.substr(i),i});sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)cout<<v[i].second<<" "<<v[i].first<<endl;
    cin>>s;
    return 0;
}
