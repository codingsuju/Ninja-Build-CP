//Implementation:
vector<int> Z(string text,string pat)
{
    int m=pat.size();
    string total=pat+'!'+text;
    int n=total.size();
    vector<int> temp(n);
    int l=0;
    int r=0;
    temp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=i;
            r=i;                                    // 0 1 2 3 4 5 6 7 8 9  10   11  12  13  14  15  16 17  18
            while(r<n && total[r-l]==total[r])      // a b c a b ! a b c a   b   c   a   b   a   b   c   a   b
                r++;                                // 0 0 0 2 0 0 5 0 0
            r--;
            temp[i]=r-l+1;
        }
        else
        {
           int j=i-l;
           if(temp[j]<(r-i+1))    //Should not be equal //Important
           {
               temp[i]=temp[j];
           }
           else
           {
               l=i;
               r=r+1;
               while(r<n && total[r-l]==total[r])
               {
                   r++;
               }
               r--;
               temp[i]=r-l+1;
           }
        }
    }
    vector<int> ans;
    for(int i=m+1;i<n;i++)
        if(temp[i]==m)ans.push_back(i-m-1);
    return ans;
}
//Function call:
void solve()
{
    vector<int> ans;
    ans=Z("abcabcababcab","abcab");
    cout<<"\nANS:";
    for(int x:ans)
        cout<<x<<" ";
}