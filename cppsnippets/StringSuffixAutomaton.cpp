//Implementation:
struct state{
    int len,link;
    map<char,int> next;
};
const int MAXLEN=100000;
vector<state> st;
int sz,last;
void sa_init(){
    st[0].len=0;
    st[0].link=-1;
    sz=1;
    last=0;
}
void sa_extend(char c) {
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

// Building suffix automaton
void sa_build(string &s){
    int n=s.size();
    vector<state> local_st(n*2);
    st=local_st;
    sa_init();
    for(char c:s){
     sa_extend(c);
   }
}
//Application:
//Check if string exist in the Bigger string
bool check_substring(string p){
    int cur=0;
    bool ans=true;
    for(int i=0;i<p.size();i++){
        if(st[cur].next.count(p[i]))
        {
            cur=st[cur].next[p[i]];
        }
        else
            return false;
    }
    return ans;
}
//Total No of different substrings
long long int dp_ways[MAXLEN*2];
long long int no_of_different_substrings(int cur){
    if(dp_ways[cur]!=-1)
        return dp_ways[cur];
    long long int ans=0;
    for(pair<char,int> p:st[cur].next){
        ans+=no_of_different_substrings(p.second);  
    }
    return dp_ways[cur]=ans+1;
}
//Total length of different substring
long long int Total_length[MAXLEN*2];
long long int total_length(int cur){
    if(Total_length[cur]!=-1)
        return Total_length[cur];
    long long int ans=0;
    for(pair<char,int> p:st[cur].next){
        ans=ans+dp_ways[p.second]+total_length(p.second);
    }
    return Total_length[cur]=ans;
}
//To find Kth lexicographically smallest (Different substrings)
string k_ans="";
void lex_path(int cur,int k){
    if(k>dp_ways[0]-1)
        return;
    if(k<=0)
        return;
    int path=0;
    for(pair<char,int> p: st[cur].next){
        if(path+dp_ways[p.second] <k)
        {
            path+=dp_ways[p.second];
        }
        else{
            path+=1;
            k_ans+=p.first;
            lex_path(p.second,k-path);
            break;
        }
    }
}
//To find the longest common substring of two string 
string lcs(string s, string t)
{
    string ans;
    sa_build(s);
    int v=0,l=0,best=0,bestpos=0;
    for(int i=0;i<t.size();i++)
    {
        while(v && !st[v].next.count(t[i]))
        {
            v=st[v].link;
            l=st[v].len;
        }
        if(st[v].next.count(t[i]))
        {
            v=st[v].next[t[i]];
            l++;
        }
        if(l>best){
            best=l;
            bestpos=i;
        }
    }
    ans=t.substr(bestpos-best+1,best);
    return ans;
}
//To find the longest common substring of multiple string
string lcs_multiple(vector<string> &S)
{
    int n=S.size();
    sa_build(S[0]);
    string ans;
    int best=0,bestpos=0;
    for(int i=1;i<n;i++)
    {
        int v=0,l=0;
        string next="";
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
                    //next.insert(next.end(),S[i].begin()+j-l,S[i].begin()+j);
                    //next.push_back('#');
                    next+=S[i].substr(j-l,l);
                    next+='#';
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
    ans=S[n-1].substr(bestpos-best+1,best);
    return ans;
}
//Function call:
void solve()
{
   string s;
   cin>>s;
   sa_build(s);

   cout<<check_substring("abc")<<"\n";
   
   //Total No of different substrings
   memset(dp_ways,-1,sizeof dp_ways);
   cout<<"Total No of different substrings:"<<no_of_different_substrings(0)-1<<"\n";
  
   // Total length of different substring
   memset(Total_length,-1,sizeof Total_length);
   cout<<"Total length of different substring:"<<total_length(0)<<"\n";
   
   // To find Kth lexicographically smallest (Different substrings)
   int k=13;
   lex_path(0,k);
   cout<<k_ans<<"\n";

   // To find the longest common substring of two string
   string S,T;
   cin>>S>>T;
   string ans_lcs=lcs(S,T);
   cout<<"Longest common substring of s and t:"<<ans_lcs<<"\n";

   // To find the longest common substring of multiple strings
   vector<string> mul;
   for(int i=0;i<4;i++)
   {
      string p;
      cin>>p;
      mul.push_back(p);
   }
   string ans_lcs_mul=lcs_multiple(mul);
   cout<<"Longest common substring of multiple string is:"<<ans_lcs_mul<<"\n";
}