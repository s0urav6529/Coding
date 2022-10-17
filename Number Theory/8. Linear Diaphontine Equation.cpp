/// Linear Diaphontine Equation
/// which is (ax+by=c) where c = k*gcd(a,b) [ k = 1,2,....] then exits a solution otherwise no solution
/// find x and y of the solution 



bool no_solution = false;

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

/// If (c%d>0) no solution otherwise solution exits

tuple<int,int> diaphontine(ll a, ll b, ll c){

    auto[d, x , y] =exgcd(a , b);

    if(c % d){
        no_solution=true;
        return {-1,-1}; /// Invalid returns
    }
    else {
        ll k = c/d;
        return {x*k , y*k};
    }
}

int main(){

    fast;
    ll a, b ,c;

    cin >> a >> b >> c;

    auto[x,y] = diaphontine(a, b , c);

    if(no_solution){
        cout<<"No Solution Exits"<<endl;
    }
    else cout<< x <<" "<< y<<endl;

    return 0;
}



