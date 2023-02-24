
*** Demo-1
  
double binary_search(int n)
{
    double l=0,h=n,mid;
    while(h-l>0.000000001)
    {
        mid=(l+h)/2;
        if(mid*mid>n)
            h=mid;
        else
            l=mid;
    }
    return mid;

}

*** Demo-2
  
