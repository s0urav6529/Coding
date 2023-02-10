
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll number_ache[20];
void precal(){

    ll tot=10;
    number_ache[1]=9;
    for(int i=2;i<=18;i++){

        number_ache[i]=(tot*9)*i;
        tot*=10;
        //cout<<number_ache[i]<<endl;
    }

}

int main(){

    precal();
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;

        if(k<10){
            cout<<k<<endl;
            continue;
        }

        ll i=0;
        while(k>number_ache[++i]){
            k-=number_ache[i];
        }

        //cout<<k<<" "<<i<<endl;

        ll jump=max(0ll,(k/i)+((k%i)>0?1:0)-1);

        ll surur_number=1;

        for(int j=1;j<i;j++)
            surur_number*=10ll;

        ll oi_number=(surur_number+jump);

        //cout<<jump<<" "<<surur_number<<" "<<oi_number<<endl;


        vector<int>rem;

        while(oi_number){
            rem.push_back(oi_number%10);
            oi_number/=10;
        }

        reverse(rem.begin(),rem.end());

        ll pos=(k%i==0?i:k%i);

        cout<<rem[pos-1]<<endl;



    }

}
