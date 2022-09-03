

Euler's totient function, also known as phi-function , counts the number of integers between 1 and  inclusive, which are coprime to n.


Link : https://cp-algorithms.com/algebra/phi-function.html



>>>>>>>>>>>>>>>>>>>>Euler totient implementation using factorization in :  O( sqrt (n) )  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include<bits/stdc++.h>
using namespace std;

int Euler_totient(int n){
    
    int res=n;
    for(int i=2;i*i<=n;i++){
        
        if(n%i==0){
            
            while(n%i==0){
                
                n=n/i;
            }
            res-=(res/i);
        }
    }
    if(n>1)
        res-=(res/n);
    return res;
}

int main(){
    
    int n,c=0;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        
        if(n%i==0){
            
            c=1;
            break;
        }
    }
    if(c==1){
        
        cout<<Euler_totient(n)<<endl;
    }
    else
        cout<<n-1<<endl;
    return 0;
}


>>>>>>>>>>>>>>>>> Euler totient function from 1 to n in O( n log log n)) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include<bits/stdc++.h>
using namespace std;

const int limit=1e7+5;
int coprime[limit];

void Euler_totient() {
    for (int i = 0; i <= limit; i++)
        coprime[i] = i;

    for (int i = 2; i <= limit; i++) {

        if (coprime[i] == i) {

            for (int j = i; j <= limit; j += i){
                coprime[j] -= coprime[j] / i;
            }
        }
    }
}
int main(){
    
    Euler_totient();

    int tc; cin >> tc;

    while(tc--){

        int n; cin >> n;

        cout<<coprime[n]<<endl;

    }
    return 0;
}





