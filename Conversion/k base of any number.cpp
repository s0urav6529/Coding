

/// suppose we have a number 11 what is the 3 base of this number
/// 3 base of 11 = (102)
/// 4 base of 12 = 30


*********** Code ***************

    int n,base;
    cin >> n >> base;
    string s="";

    int N=n;
    while(N){
        s+=to_string(N%base);
        N/=base;
    }
    rev(s);
    cout<<base<<" base of "<<n <<" is = "<<s<<endl;

*********** code 2 *****************

    int n,base;
    cin >> n >> base;

    vector<ll>bit(31,0);
    int pos =0;

    while(n){
        bit[pos++] += (n%base);
        n/=base;
    }

    for(int i=29;i>=0;i--){
        cout<<bit[i];
    }
    cout<<endl;

**************************************



