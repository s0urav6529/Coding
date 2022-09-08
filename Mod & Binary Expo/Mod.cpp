

ll addmod(ll a,ll b){
    return Mod(Mod(a)+Mod(b));  ///((a%m)+(b%m))%m
}

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD); ///we add mod because x can be positive or negative
}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b)); ///((a%m)*(b%m))%m
}

ll Binary_expo(ll a,ll p){   ///a^n
	ll res=1;
	while(p){

		if(p & 1)
		res=mulmod(res,a);

		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}





