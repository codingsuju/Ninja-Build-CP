//Implementation:
vector<int> KMP(string text,string pat)
{
    int n=text.size();
    int m=pat.size();
    vector<int> lps(m);
    int j=0;
    lps[0]=0;
    for(int i=1;i<m;i++)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
        }
        else if(pat[i]!=pat[j])   //abcabcababcab //abcab
        {
            if(j>0)
            {
               j=lps[j-1];
               i--;
            }
            else if(j==0)
                lps[i]=0;
        }
    }
    //KMP
    vector<int> ans;
    j=0;
    for(int i=0;i<n;i++)
    {
        if(text[i]==pat[j])
        {
            j++;
        }
        else if(text[i]!=pat[j])
        {
            if(j>0)
            {
                j=lps[j-1];
                i--;
            }
        }
        if(j==m)
        {
            ans.push_back(i-j+1);
            j=lps[j-1];
        }
    }
    return ans;
}
//Function Call:
void solve()
{
    vector<int> ans;
    ans=KMP("abcabcababcab","abcab");
    cout<<"\nANS:";
    for(int x:ans)
        cout<<x<<" ";
}