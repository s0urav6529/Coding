.......................

Declaration type:

1. bitset<32>bs;   ///default all bit 0

2. bitset<32>bs(string("0110"));   ///storing the bit

3. bitset<32>bs(5);   ///storing the binary value of 5

........................

Operation:

bs.set();  ///make all bit set (1)

bs.flip();  ///flipping the set bit to unset & vice versa

bs.reset()   ///making all bit reset(0)

cout<<bs<<endl;   ///print the all 32 bit

cout<<bs[0]<<endl;   ///print the index bit

cout<<bs.to_ullong()<<endl;    ///print the value that made by those bit


........................

Other ways to declare

Type 1:

struct node{
  int e;  ///edge 
  bitset<32>bs;
};
  
vector<node>a[limit];

a[i].push_back({j,val});  //j==edge && val== bitset value

....................

Type 2:

vector<bitset<32>>ans(n,bitset<32>(0));


.....................




