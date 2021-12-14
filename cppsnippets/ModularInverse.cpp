int power(int x, int y, int m) {
   if (y == 0)
      return 1;
   int p = power(x, y / 2, m) % m;
   p = (int)((p * (long long int )p) % m);
   if (y % 2 == 0)
      return p;
   else
      return (int)((x * (long long int)p) % m);
}
int modInverse(int a, int m) {
        return power(a, m - 2, m);
}
//Function call
void solve()
{
     int x=modInverse(5,MOD);
     cout<<x<<"\n";
}