



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

ordered_set s;

s.insert(1);
...


int x=*(s.find_by_order(k));   ///kth element of the set --- 0 base index;

int x= order_of_key(val);  /// position of the val in the set  --- 0 base index;




