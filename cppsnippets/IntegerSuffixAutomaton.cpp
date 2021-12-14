//Longest common subarray of multiple arrays
struct state{
    int len,link;
    unordered_map<int,int> next;
};
vector<state> st;
int sz,last;
void sa_init(){
    st[0].len=0;
    st[0].link=-1;
    sz=1;
    last=0;
}
void sa_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void sa_build(vector<int> &s){
    int n=s.size();
    vector<state> local_st(n*2);
    st=local_st;
    sa_init();
    for(int c:s){
     sa_extend(c);
   }
}
int lcs_multiple(vector<vector<int>> &S)
{
    int n=S.size();
    sa_build(S[0]);
    string ans;
    int best=0,bestpos=0;
    for(int i=1;i<n;i++)
    {
        int v=0,l=0;
        vector<int> next;
        for(int j=0;j<=S[i].size();j++)
        {
            if(j==S[i].size() || !st[v].next.count(S[i][j]))
            {
                if(i==n-1)
                {
                     if(l>best)
                     {
                        best=l;
                        bestpos=j-1;
                     }
                }
                else
                {
                    next.insert(next.end(),S[i].begin()+j-l,S[i].begin()+j);
                    next.push_back(100001);
                    //next+=S[i].substr(j-l,l);
                    //next+='#';
                }
            }
            while(j<S[i].size() && v && !st[v].next.count(S[i][j]))
            {
                v=st[v].link;
                l=st[v].len;
            }
            if(j<S[i].size() && st[v].next.count(S[i][j]))
            {
                v=st[v].next[S[i][j]];
                l++;
            }
        }
        sa_build(next);
    }
    return best;
}
int longestCommonSubarray(int n, vector<vector<int>>& a) 
{
     return lcs_multiple(a);
}