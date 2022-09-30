


/// For distinct value 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

ordered_set s;

s.insert(1);
...


int x=*(s.find_by_order(k));   ///kth element of the set --- 0 base index;

int x= s.order_of_key(val);  /// position of the val in the set  --- 0 base index;


/// For duplicate value 


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

ordered_set s;

s.insert(1);
...


int x=*(s.find_by_order(k));   ///kth element of the set --- 0 base index;

int x= s.order_of_key(val);  /// position of the val in the set  --- 0 base index;

/// Erase k'th position value of orginal array from the set
            
    /// a[k] is the value of k'th position of the orginal array & pos is the postion of that value in the set
    int pos = s.order_of_key(a[k]);      

    /// Erasing the value from the set.
    s.erase(s.find_by_order(pos));




