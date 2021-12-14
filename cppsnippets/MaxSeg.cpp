//Implementation:
void build(int node,int low,int high,vector<int>&a,vector<int> &seg)
{
    if(low==high)
    {
        seg[node]=low;
        return;
    }
    int mid=(low+high)/2;
    build(2*node+1,low,mid,a,seg);
    build(2*node+2,mid+1,high,a,seg);
    if(a[seg[2*node+1]]==a[seg[2*node+2]])
      seg[node]=max(seg[2*node+1],seg[2*node+2]);  // Change here
    else if(a[seg[2*node+1] ]>a[(seg[2*node+2])])
      seg[node]=seg[2*node+1];
    else
      seg[node]=seg[2*node+2];    
}
void update(int node,int low,int high,int index,int val,vector<int> &a,vector<int> &seg)
{
    if(low==high)
    {
        a[index]=val;
        seg[node]=val;
        return;
    }
    int mid=(low+high)/2;
    if(index<=mid)
        update(2*node+1,low,mid,index,val,a,seg);
    else
        update(2*node+2,mid+1,high,index,val,a,seg);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);     // Change here
}
int query(int node,int low,int high,int l,int r,vector<int> &a,vector<int> &seg)
{
    int mid=(low+high)/2;
    if(l>high || r<low) return -1;
    else if(l<=low && high<=r)
     return seg[node];
    int p=query(2*node+1,low,mid,l,r,a,seg);
    int q=query(2*node+2,mid+1,high,l,r,a,seg); // Change here
    if(p==-1 || q==-1)
    {
        if(p!=-1)
            return p;
        else if(q!=-1)
            return q;
        else 
            return -1;
    }
    if(a[p]==a[q])
      return min(p,q);
    else if(a[p]>a[q])
      return p;
    else if(a[q]>a[p])
      return q;   
}
//Function call
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
    int m=4*n;
    vector<int> seg(m);
    build(0,0,n-1,a,seg);
    long long int ans=calculate(0,n-1,seg,n,a);
    //cout<<ans<<"\n";

    cout<<"\n"<<query(0,0,n-1,0,3,a,seg);
    //update(0,0,n-1,3,1,a,seg);
    //cout<<"\n"<<query(0,0,n-1,2,5,a,seg);
}
//Application:
//Divide and conquer + Segment Tree
long long int calculate(int l,int r,vector<int> &seg,int n,vector<int> &a)
{
    if(l>r)
        return 0;
    int m=query(0,0,n-1,l,r,a,seg);
    return 0;
}