
****  The value of nCr even or odd ?
  
      if ((n & r) == r) then value is odd;    & = bitwise and 
      else even


....................................................................................


 **** For a given n, find the number of even and odd numbers among the set, { nC0, nC1 ... nCn }.


        ll n;
        scanf("%lld",&n);

        ll odd = 1 , even =n+1;

        for(int i=0 ; i <= 45 ;i++){

            if((n & (1LL << i))){
                odd += odd;
            }
        }

        printf("%lld %lld\n",even-odd,odd);

//// 
input 4
output 3 2           (for 4, values are: 4C0 = 1, 4C1 = 4 , 4C2 =  6, 4C3 =  4, 4C4 =  1. Hence 3 2)
  

...................................................................................








