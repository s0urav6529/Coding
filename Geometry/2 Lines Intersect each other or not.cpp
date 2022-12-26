
///Check wheather 2 lines are intersect themselves or not 

int orientation(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){

    ll val=(y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);

    if(val>0) return 1;
    else if(val<0) return -1;
    else return val;
}

bool projection(ll a,ll b,ll c,ll d){
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);

    return max(a,c)<=min(b,d);
}

void run_case(){


    ll x1,y1, x2,y2, x3,y3, x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    int p1=orientation(x1,y1,x2,y2,x3,y3);
    int p2=orientation(x1,y1,x2,y2,x4,y4);
    int p3=orientation(x3,y3,x4,y4,x1,y1);
    int p4=orientation(x3,y3,x4,y4,x2,y2);

    if((p1!=p2) && (p3!=p4)){
        pyes;
    }
    else if(p1==0 && p4==0){


        if(projection(x1,x2,x3,x4) && projection(y1,y2,y3,y4)){
            pyes;
        }
        else pno;

    }
    else pno;

    return;
}

