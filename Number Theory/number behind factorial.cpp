#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tc=1;
    cin>>tc;
    while(tc--)
    {
        double sum=0;
        cin>>n;
        int i=1;
        while(i<=n)
        {
            sum+=log10(i);
            i++;
        }
        cout<<floor(sum)+1<<endl;
    }
    return 0;
}
