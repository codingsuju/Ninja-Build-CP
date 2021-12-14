//Implementation:
void update(int k,int x,vector<int> &trees)
{
    for(;k<trees.size();k+=(k&-k))
    {
        trees[k]+=x;
    }
}
int sum(int k,vector<int> &trees)
{
    int ans=0;
    while(k>=1)
    {
        ans+=trees[k];
        k-=(k&-k);
    }
    return ans;
}
int query(int l,int r,vector<int> &trees)
{
    return sum(r,trees)-sum(l-1,trees);
}
//Function call:
void solve()
{
      int n;
      cin>>n;
      int inp;
      vector<int> a(n);
      for(int i=0;i<n;i++)
      {
         cin>>inp;
         a[i]=inp;
      }
      vector<int> trees(n+1,0);
      for(int i=0;i<n;i++)
      {
        update(i+1,a[i],trees);
      }
      cout<<"\n"<<query(0,4,trees);
}