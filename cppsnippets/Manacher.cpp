//Implementation:
void manacher(String &S)
{
    int m=S.size();
    int n=(2*m)+1;
    int len[n];
    memset(len,0,sizeof len);
    int center=0;
    int right=0;
    string s="";
    s+='$';
    for(int i=0;i<S.size();i++)
    {
        s+=S[i];
        s+='$';
    }
    len[0]=0;
    len[n-1]=0;
    for(int i=1;i<n-1;i++)
    {
        int mirror=center-(i-center);
        if(i<right){
            len[i]=min(right-i,len[mirror]);
        }
        int a=i-len[i]-1;
        int b=i+len[i]+1;
        while(a>=0 && b<n && s[a]==s[b])
        {
            a--;
            b++;
            len[i]++;
        }
        if(i+len[i]>right)
        {
            center=i;
            right=i+len[i];
        }
    }
}
//Application:
//Manacher+ Queue
/* int Len[m];
memset(Len,0,sizeof Len);
int x=0;
for(int i=1;i<n;i+=2){
    Len[x]=1+((len[i]-1)/2);
    x++;
}
int r[m];
queue<array<int,2>> q1,q2;
for(int i=m-1;i>=0;i--){
    while(!q1.empty() && q1.front()[0]-q1.front()[1]>i-1)
    {
        q1.pop();
    }
    r[i]=1+(q1.empty()?0:(q1.front()[0]-i)*2);
    q1.push({i,Len[i]});
}
int l[m];
int first=1;
long long int ans=1;
for(int i=0;i<m-1;i++){
    while(!q2.empty() && q2.front()[0]+q2.front()[1]<i+1){
        q2.pop();
    }
    l[i]=1+(q2.empty()?0:(i-q2.front()[0])*2);
    first=max(first,l[i]);
    ans=max(ans,(long long)first*(r[i+1]));
    q2.push({i,Len[i]});
}
return ans;