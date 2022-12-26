

///Given some 2D points of a simple polygone . Find the area of the polygone.

ll poly_area(vector<pair<ll,ll>>&poly,int n){

    ll area = 0;
    for(int i=0;i<n;i++){
        
        /// Cross product (x1*y2)-(x2*y1)
        
        area += (poly[i].first*poly[(i+1)%n].second) - (poly[(i+1)%n].first*poly[i].second);

    }
    area = abs(area);

    return area/2LL;

}

void run_case(){


    int n;
    cin>>n;
    vector<pair<ll,ll>>poly(n);

    for(int i=0;i<n;i++) {
        cin>>poly[i].first>>poly[i].second;
    }

    ll area = poly_area(poly,n);

    cout<<area<<endl;
    return;
}

