

 ///  Find any rearrangement of two arrays A & B , such that a i'th bit can be set of array C,
 ///  Such that Ci = (Ai xor Bi) is set for all (1<=i<=n) in C.
 
 *********** Code *************
 
 bool canset(int number,vector<int>a,vector<int>b){

    int n=a.size();

    vector<int>aa(n),bb(n);

    for(int i=0;i<n;i++){
        
        /// Since Xor operation we need to find 0-1 or 1-0 combination to set i'th bit
        aa[i] =  a[i] & number;   
        bb[i] = ~b[i] & number;

    }
    sortv(aa);
    sortv(bb);

//    for(int i=0;i<n;i++) cout<<aa[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<n;i++) cout<<bb[i]<<" ";
//    cout<<endl;


   if(aa==bb) return true;
   return false;
}



