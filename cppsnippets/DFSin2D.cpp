//Class Definition and Basic function:
const int INF=1e9;
class Point{
public:
    int x;
    int y;
    Point(int X,int Y){
        x=X;
        y=Y;
    }
};
class Matrix{
public:
    vector<Point> adj;
};
vector<vector<Matrix>> matrix; // Global class Variable
void set_vis_false(vector<vector<bool>> &vis)
{
   for(int i=0;i<vis.size();i++){
       for(int j=0;j<vis[0].size();j++){
          vis[i][j]=false;
       }
   }
}
bool is_valid(int x,int y,int m,int n)
{
   if(x<0 || y<0 ||x>=m ||y>=n)
      return false;
   return true;
}
//Checking if path exist:
bool dfs(Point s,Point &d,vector<vector<bool>> &vis)
{
   vis[s.x][s.y]=true;
   if(s.x==d.x && s.y==d.y)return true;
   bool ans=false;
   for(Point &P:matrix[s.x][s.y].adj)
   {
      if(vis[P.x][P.y]==false)
      {
        ans=(ans||dfs(P,d,vis));
      }
   }
   return ans;
}
//Shortest path:
int min_dfs(Point s,Point &d,vector<vector<bool>> &vis,vector<vector<int>> &min_dp)
{  
   if(s.x==d.x && s.y==d.y)return 0;
   else if(vis[s.x][s.y]==true)
      return min_dp[s.x][s.y];
   vis[s.x][s.y]=true;
   int ans=INF;
   for(Point P:matrix[s.x][s.y].adj)
   {
     ans=min(ans,min_dfs(P,d,vis,min_dp)+1);
   }  
   return min_dp[s.x][s.y]=ans;
}
//Longest path without visiting node twice:
int max_dfs(Point s,Point &d,vector<vector<bool>> &vis)
{  
   if(s.x==d.x && s.y==d.y)
      return 0;
   else if(vis[s.x][s.y]==true)
      return INT_MIN;
   vis[s.x][s.y]=true;
   int ans=INT_MIN;
   for(Point &P:matrix[s.x][s.y].adj)
   {
      ans=max(ans,max_dfs(P,d,vis)+1);
   }
   vis[s.x][s.y]=false;  
   return ans;
}
//Function call:
void solve()
{
     int m=4,n=4;
     vector<vector<Matrix>> matrix_dup(m,vector<Matrix>(n));
     matrix=matrix_dup;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
         if(is_valid(i+1,j,m,n)==true)
            matrix[i][j].adj.push_back(Point(i+1,j));  //Down
         if(is_valid(i,j+1,m,n)==true)
           matrix[i][j].adj.push_back(Point(i,j+1));   //Right
         if(is_valid(i-1,j,m,n)==true)
           matrix[i][j].adj.push_back(Point(i-1,j));   //Up
         if(is_valid(i,j-1,m,n)==true)
           matrix[i][j].adj.push_back(Point(i,j-1));   //Left
      }
     }
     vector<vector<bool>> vis(m,vector<bool>(n));
     Point s=Point(0,0);
     Point d=Point(2,2);
     
     set_vis_false(vis);
     cout<<(dfs(s,d,vis)==true?"YES":"NO");
 
     set_vis_false(vis);
     vector<vector<int>> min_dp(m,vector<int> (n,INF));
     cout<<"\n"<<min_dfs(s,d,vis,min_dp);
 
     set_vis_false(vis); 
     cout<<"\n"<<max_dfs(s,d,vis); //cannot visit node twice
}