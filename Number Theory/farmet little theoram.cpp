
Fermat’s little theorem states that if p is a prime number, then for any integer a, the number a p – a is an integer multiple of p. 

Link : https://www.geeksforgeeks.org/fermats-little-theorem/#:~:text=Fermat%27s%20little%20theorem%20states%20that,an%20integer%20multiple%20of%20p.&text=ap%20%E2%89%A1%20a%20(mod,an%20integer%20multiple%20of%20p.
    

#include<bits/stdc++.h>
using namespace std;

int FLT(int a,int n,int m){

    int result=1;
    while(n){

        if(n%2)result=(result*a)%m;
        n/=2;
        a=(a*a)%m;
    }
    return result;
}
int main(){

    int a,m;
    cin>>a>>m;
    cout<<FLT(a,m-2,m)<<endl;
    return 0;
}




