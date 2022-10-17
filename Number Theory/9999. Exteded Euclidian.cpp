


/// Return (d,x,y) such that ax + by = gcd(a,b) = d



tuple<ll, ll, ll> exgcd(ll a , ll b){

    if(b == 0){
        return {a, 1 , 0};
    }
    auto[d, _x, _y] = exgcd(b, a%b);

    ll x = _y;
    ll y = _x -(a/b)*_y;

    return {d, x, y};
}

int main(){
    fast;
    ll a, b;
    cin >> a >> b;

    auto[d, x , y] = exgcd(a , b);

    cout<< x <<" "<<y <<" "<<d<<endl;

    return 0;
}



