//Implementation:
void topological_sort_helper(int s,vector<vector<int>> &adj,vector<int> &res,vector<bool> &vis)
{
    if(vis[s]==true)
        return;
    vis[s]=true;
    for(int t:adj[s])
        topological_sort_helper(t,adj,res,vis);
    res.push_back(s);
}
vector<int> topological_sort(int n,vector<vector<int>> &adj)
{
    vector<int> res;
    vector<bool> vis(n+1);
    for(int i=0;i<=n;i++)vis[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])topological_sort_helper(i,adj,res,vis);
    }
    reverse(res.begin(),res.end());
    return res;
}
void solve()
{
    int n=6;
    vector<vector<int>> edges{{4,1},{4,5},{3,6},{5,3},{5,2}};
    vector<vector<int>> adj(n+1);
    for(int i=0;i<edges.size();i++)
      adj[edges[i][0]].push_back(edges[i][1]);
    vector<int> res=topological_sort(n,adj);
    for(int x:res)cout<<x<<" ";
}
//Cyclic find and topological sort:
int dp[2001];
bool vis[2001];
vector<int> res;
bool isnotcyclic(int s,vector<vector<int>> &adj)
{
    if(dp[s]!=-1)return dp[s];
    if(vis[s]==true)return false;
    vis[s]=true;
    bool ans=true;
    for(int &x:adj[s])ans=ans&(isnotcyclic(x,adj));
    return dp[s]=ans;
}
void topological_sort(int s,vector<vector<int>> &adj)
{
    if(vis[s]==true) return;
    vis[s]=true;
    for(int &x:adj[s])
        topological_sort(x,adj);
    res.push_back(s);
}
vector<int> findOrder(int n, vector<vector<int>>& p) {
    vector<vector<int>> adj(n);
    for(vector<int> &e:p)adj[e[0]].push_back(e[1]);
    bool ans=true;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)vis[i]=false;
    for(int i=0;i<n;i++)
        ans=ans&(isnotcyclic(i,adj));
    if(ans==false)return res;
    for(int i=0;i<n;i++)vis[i]=false;
    for(int i=0;i<n;i++)
        topological_sort(i,adj);
    return res;
}