#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define mem(dp,a) memset(dp,a,sizeof dp)

struct trie{
    bool leaf;
    trie* child[26];
};

trie* create(){
    trie* temp=new trie();
    temp->leaf=false;    ///end
    mem(temp->child,NULL);
    return temp;
}

void Insert(trie* root,string s){

    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']==NULL)
            root->child[s[i]-'a']=create();
        root=root->child[s[i]-'a'];
    }
    root->leaf=true;
}

bool Search(trie* root,string s){

    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']==NULL)
            return false;
        root=root->child[s[i]-'a'];
    }
    return root->leaf;
}

bool StartWith(trie* root,string s){

    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']==NULL)
            return false;
        root=root->child[s[i]-'a'];
    }
    return true;
}

trie *root;

int main(){
    fast;
    int n,q,p;
    cin>>n>>q>>p;
    root=create();
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        Insert(root,s);
    }
    while(q--){
        string s;
        cin>>s;
        if(Search(root,s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    while(p--){
        string s;
        cin>>s;
        if(StartWith(root,s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


