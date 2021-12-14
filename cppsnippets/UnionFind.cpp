//Implementation:
int parent(int x,vector<int> &link)
{
    while(link[x]!=x)x=link[x];
}
 void Union(int x,int y,vector<int> &link,vector<int> &len)
 {
        if(x==y)return;
        while(x!=link[x])x=link[x];
        while(y!=link[y])y=link[y];
        if(x==y)return;
        if(len[x]<len[y])swap(x,y);
        link[y]=x;
        len[x]+=len[y];
 }
void solve()
{
    int n;
    cin>>n;
    vector<int> link(n);
    vector<int> len(n);
    for(int i=1;i<10;i++)link[i]=i;
    for(int i=1;i<10;i++)len[i]=1;
    vector<vector<int>> edges{{1,4},{7,4},{6,3},{8,3},{3,2}};
    for(vector<int> e:edges)
        Union(e[0],e[1],link,len);
    int ans=0;
    for(int i=1;i<10;i++)
    {
        if(link[i]==i)ans++;
    } 
    cout<<ans;
}