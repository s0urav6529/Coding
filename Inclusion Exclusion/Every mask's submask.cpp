
  /// Sometimes we need to iterate over mask' submask , below code we can iterate over musk's submask

/*

For n = 3 we have 1 to 7 mask 

for 1 mask we have submask 
1 0

for 2 mask we have submask 
2 0

for 3 mask we have submask 
3 0
2 1
1 2

for 4 mask we have submask 
4 0

for 5 mask we have submask 
5 0
4 1
1 4

for 6 mask we have submask 
6 0
4 2
2 4

for 7 mask we have submask 
7 0
6 1
5 2
4 3
3 4
2 5
1 6

*/

/// Iterating over every mask
  for(int mask = 0;mask < (1<<n); mask++){

      /// calculating answer for every musk's submask
      for(int i = mask ; i>0 ; i = (i-1)&mask){

          int j = mask^i;

          ans of mask = ans of submask i + ans of submask j

      }

  }


