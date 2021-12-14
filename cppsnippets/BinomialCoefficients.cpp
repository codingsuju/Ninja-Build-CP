#define ll long long 
const int MAX_N=1e6;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;
const int choose_k=4;
long long int C[MAX_N][choose_k];
void precompute()
{
  for(int i=0;i<MAX_N;i++)
  {
      C[i][0]=1;
      if(i<choose_k)
      {
          C[i][i]=1;
      }
      for(int j=1;j<i && j<choose_k;j++)
      {
          C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
      }
  }
  cout<<C[5][3];
}           