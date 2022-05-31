set<char> vow = {'a','e','i','o','u'};
bool isvow(char c)
{
     return vow.find(c) != vow.end();
}


bool compair(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
    if(a.first<b.first) return true;
    else if(a.first==b.first&&a.second.first<b.second.first) return true;
    else if(a.first==b.first&&a.second.first==b.second.first&&a.second.second<b.second.second) return true;
    return false;
}


bool compair(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.ff==b.ff)return a.ss<b.ss;
    return a.ff>b.ff;
}


bool compair(string a,string b)
{
    return a.size()<b.size();
}



bool compair(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.ss.ff!=b.ss.ff) return a.ss.ff>b.ss.ff;
    else if(a.ss.ff==b.ss.ff && a.ss.ss!=b.ss.ss) return a.ss.ss<b.ss.ss;
    else return a.ff<b.ff;
}

///EKTA PORTION KE SORT KORA

compair(pair<int,int>p,pair<int,int>q){

    if(p.ff=q.ff) return p.ss>q.ss;
    return p.ff<q.ff;

}

vector<pair<int,int>>a(n);

sort(a.begin()+x,a.begin()+y,compair);

