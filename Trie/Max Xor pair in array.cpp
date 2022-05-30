#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define mem(dp,a) memset(dp,a,sizeof dp)

class node{
public:
    node* left;
    node* right;
};

void Insert(node* head,int num){
    node*curr=head;

    for (int i=30;i>=0;i--) {

        if((num&(1<<i))){
            if (!curr->right)
                curr->right=new node();
            curr=curr->right;
        }
        else{
            if(!curr->left)
                curr->left=new node();
            curr=curr->left;
        }
    }
}

int Find(node* head,int num){
    node*curr=head;

    int cur_xor=0,add=pow(2,30);

    for(int i=30;i>=0;i--){

        if((num&(1<<i))){

            if(curr->left){
                cur_xor+=add;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        else{
            if(curr->right){
                cur_xor+=add;
                curr=curr->right;
            }
            else curr=curr->left;
        }
        add/=2;
    }
    return cur_xor;

}

int main(){
    fast;
    int n;
    cin>>n;
    vector<int>a(n);
    node* head=new node();
    for(int i=0;i<n;i++) {
        cin>>a[i];
        Insert(head,a[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,Find(head,a[i]));
    }
    cout<<ans<<endl;

    return 0;
}



