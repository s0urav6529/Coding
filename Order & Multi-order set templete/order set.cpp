



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

ordered_set s;

s.insert(1);
...


int x=*(s.find_by_order(k));   ///kth element of the set --- 0 base index;

int x= s.order_of_key(val);  /// position of the val in the set  --- 0 base index;




