
map<int,int>mp;
int com_to=1;

for(int i=0;i<n;i++){
  cin>>a[i];
  
  if(mp.find(a[i])!=mp.end()){
      a[i]=mp[a[i]];
  }
  else{
      mp[a[i]]=com_to;
      a[i]=com_to++;
  }
}
  



