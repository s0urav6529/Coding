#include<bits/stdc++.h>
using namespace std;

/// sending the string only.
// returns the index from where lexographically smallest string starts
int minlex(string s){

    int len = s.size();

    int n = 2 * len , i = 0 , j = 1 , k = 0;

    int a , b;

    while(i + k < n &&  j + k < n){

        a = (i + k >= len) ? s[i + k - len] : s[i + k];
        b = (j + k >= len) ? s[j + k - len] : s[j + k];

        if(a == b) k++;

        else if(a > b){
            i = i + k + 1;
            if(i <= j) i = j + 1;
            k = 0;
        }
        else{
            j = j + k + 1;
            if(j <= i) j = i + 1;
            k = 0;
        }

    }

    return min(i , j);
}

int main(){
    string s;
    cin >> s;

    int h = minlex(s);
    
    int n = s.size();

    s += s;
    
    cout << s.substr(h,n) <<endl;
    return 0;
}
