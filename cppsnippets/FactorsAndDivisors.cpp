void factors(int x,vector<int> &fac,unordered_map<int,int> &f)
{
    int n=x;
    for(int i=2;i*i<=n;i++)
    {
        while(x%i==0)
        {
            if(f[i]==0)
            fac.push_back(i);
            f[i]++;
            x/=i;
        }
        if(x==1)
            break;
    }
    if(x!=1)
    {
        fac.push_back(x);
        f[x]++;
    }
}
void divisors(int x,int pos,int res,vector<int> &fac,vector<int> &div,unordered_map<int,int> &f)
{
     if(pos==(int)fac.size()){
        div.push_back(res);
        return;
     }
     for(int i=0;i<=f[fac[pos]];i++)
     {
        divisors(x,pos+1,res,fac,div,f);
        res*=fac[pos];
     }
}
//Calling function
void solve()
{
   int x;
   cin>>x;
   vector<int> fac;
   unordered_map<int,int> f;
   factors(x,fac,f);
   vector<int> div;
   divisors(x,0,1,fac,div,f);
   for(int s:fac)
    cout<<s<<" ";
   cout<<"\n";
   for(int s:div)
    cout<<s<<" ";
   cout<<"\n";
   vector<int> sum=sum_of_divisors(100);
   for(int d:sum)
    cout<<d<<" ";
}