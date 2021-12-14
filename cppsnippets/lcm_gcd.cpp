vector<long long int> LCM(43);

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b)
{
    return (a / gcd(a, b)) * b;
}
//Function call
void solve(){
    LCM[1]=1;
    for(int i=2;i<43;i++)
    {
       LCM[i]=lcm(LCM[i-1],i);
    }
}