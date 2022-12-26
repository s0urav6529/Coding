

/// We draw a line from the checking point to infinity
/// Then check that how many times it intersect the polygon 
/// If intersect odd times then it's inside the polygon otherwise outside the polygon
/// If a point co-linear then it's on boundary

ll orientation(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){
 
    ll val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
 
    if(val > 0) return 1 ; /// clock wise
    else if(val < 0) return -1; ///counter clock wise
    else return 0; ///collinear
 
}
 
bool on_segmant(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){
 
    return (x3<=max(x1,x2) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3>=min(y1,y2));
}
 
bool intersection(pair<ll,ll>a,pair<ll,ll>b,pair<ll,ll>c,pair<ll,ll>d){
 
    ll x1 = a.first , y1 = a.second;
    ll x2 = b.first , y2 = b.second;
    ll x3 = c.first , y3 = c.second;
    ll x4 = d.first , y4 = d.second;
 
    ll o1 = orientation(x1,y1,x2,y2,x3,y3);
    ll o2 = orientation(x1,y1,x2,y2,x4,y4);
    ll o3 = orientation(x3,y3,x4,y4,x1,y1);
    ll o4 = orientation(x3,y3,x4,y4,x2,y2);
 
    if((o1 != o2) && (o3 != o4) ){
        return true;
    }
    return false;
 
}
 
void an1nd1ta(int tc){
 
    int n , m;
    cin >> n >> m;
  
    vector<pair<ll,ll>>poly(n) , points(m);
    
    /// poly for storing coordinate and points 
    for(int i=0;i<n;i++){
        cin >> poly[i].first >> poly[i].second;
    }
 
    /// points for storing the checking point
    for(int i=0;i<m;i++){
        cin >> points[i].first >> points[i].second;
    }
 
 
    for(int i=0;i<m;i++){
 
        pair<ll,ll>inf_point = {(ll)INT_MAX , (ll)INT_MAX+1};
        pair<ll,ll>c = points[i];
        ll intersect = 0;
 
        bool  boundary = false;
 
        for(int j=0;j<n;j++){
 
            pair<ll,ll>a = poly[j];
            pair<ll,ll>b = poly[(j+1)%n];
            
            /// Boundary checking
            if(orientation(a.first , a.second , b.first , b.second , c.first , c.second) == 0 &&
               on_segmant(a.first , a.second , b.first , b.second , c.first , c.second)){
               
                boundary = true;
                break;
            }
            if(intersection(a,b,c,inf_point)){   /// Intersection checking
                intersect++;
            }
 
        }
 
        if(boundary) cout<<"BOUNDARY"<<endl;
        else if(intersect&1) cout<<"INSIDE"<<endl;   /// Odd times so inside
        else cout<<"OUTSIDE"<<endl;   /// Even times so outside
    }
    return;
}
