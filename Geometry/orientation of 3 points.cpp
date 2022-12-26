

There is a line that goes through the points p1 and p2. There is also a point p3.

Your task is to determine whether p3 is located on the left or right side of the line or if it touches the line when we are looking from p1 to p2.
  
  ***code***
  
ll orientation(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){
 
    ll val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
 
    if(val > 0) return 1 ; /// clock wise
    else if(val < 0) return -1; ///counter clock wise
    else return 0; ///collinear
 
}
 
void run_case(){
 
 
    ll x1,y1,x2,y2,x3,y3;
 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;
 
    ll val=orientation(x1,y1,x2,y2,x3,y3);
 
    if(val==0ll) cout<<"TOUCH"<<endl;
    else if(val>0ll) cout<<"RIGHT"<<endl;
    else cout<<"LEFT"<<endl;
 
    return;
}


