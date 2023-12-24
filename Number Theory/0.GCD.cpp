Time Complexity: O(log(min(a,b))
Auxiliary Space: O(log(min(a,b))
  
// Recursive function to return gcd of a and b in single line
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
  
// Driver program to test above function
int main()
{
    int a = 98, b = 56;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
    return 0;
}
