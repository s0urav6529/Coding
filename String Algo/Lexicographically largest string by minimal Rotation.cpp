#include<bits/stdc++.h>
using namespace std;

/// sending the string only.
// returns the index from where lexographically largest string starts
int maxlex(string s){

    int len = s.size();

    vector<int>numaric_s(len);
    
    /// convert into numberic string to find the lexicographically largest string
    /// by putting -ve in front of every number thus it return us the smallest number
    /// index from where it show the l. minimul but naturally it's maximul.
    for(int i=0;i<len;i++){
        numaric_s[i] = -(s[i]-'a');
    }

    int n = 2 * len , i = 0 , j = 1 , k = 0;

    int a , b;

    while(i + k < n &&  j + k < n){

        a = (i + k >= len) ? numaric_s[i + k - len] : numaric_s[i + k];
        b = (j + k >= len) ? numaric_s[j + k - len] : numaric_s[j + k];

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

    int h = maxlex(s);
    
    int n = s.size();

    s += s;
    
    cout << s.substr(h,n) <<endl;
    return 0;
}
