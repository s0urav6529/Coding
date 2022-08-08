

 ///Minimum operation needed to make an all the elements 0 .

 /// Operations choose L & R then reduce L to R by 1.
  
  for(int i=1;i<=n;i++) {
      int x;
      cin>>x;
      if(x==a.back()) continue;
      else a.push_back(x);
  }
 
    a.push_back(0);
    int len=a.size(),lagbe=0;
    for(int i=1;i<len-1;i++){

        if(a[i]>a[i-1] && a[i]>a[i+1]){
 
            lagbe+=(a[i]-max(a[i-1],a[i+1]));

            a[i]=max(a[i-1],a[i+1]);
            i++;
        }
    }
    sortv(a);
    lagbe+=a.back();

