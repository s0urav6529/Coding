#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define null NULL



/// Vasiliy's Multiset : https://codeforces.com/contest/706/problem/D

struct trie{
	int val,cnt;
	trie* childs[2];
};

trie* get_node(){

	trie* temp=new trie;
	temp->childs[0]=temp->childs[1]=null;
	temp->val = 1;
	temp->cnt = 0;
	return temp;
}

void Insert(int n,trie* root)
{
	trie* cur = root;
	for(int i=30;i>=0;i--){

		bool bit= (n&(1<<i));

		if(cur->childs[bit]==null)
            cur->childs[bit] = get_node();

		cur=cur->childs[bit];
		cur->cnt++;
	}
	cur->val=n;
}

void Delete(int n,trie* root){

	trie* cur=root;
	for(int i=30;i>=0;i--) {

		bool bit=(n&(1<<i));
		cur=cur->childs[bit];
		cur->cnt--;
	}
}

int MaxXor(int n,trie* root){

	trie* cur=root;
	trie* x;
	for(int i=30;i>=0;i--){

		bool bit=!(n & (1<<i));

		if(cur->childs[bit]==null)
            cur = cur->childs[!bit];
		else{

			x=cur->childs[bit];
			if(x->cnt==0)
                cur=cur->childs[!bit];
			else
                cur=cur->childs[bit];
		}
	}
	return cur->val^n;
}
trie* root;
int main()
{
	root=get_node();

	int n,q;
	char c;
	cin>>q;
	Insert(0,root);

	while(q--){
		cin>>c>>n;
		if(c=='+') Insert(n,root);
		else
		if(c=='-') Delete(n,root);
		else
		cout<<MaxXor(n,root)<<endl;
	}
}
