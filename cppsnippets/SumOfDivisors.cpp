vector<int> sum_of_divisors(int N)
{
    vector<int> sum(N,0);
    vector<int> d(N,-1);
    d[1]=1;
    for(int i=2;i*i<N;i++)
    {
        if(d[i]==-1)
        {
            d[i]=i;
            for(int j=i*i;j<N;j+=i)
            {
                if(d[j]==-1)
                    d[j]=i;
            }
        }
    }
    sum[1]=1;
    for(int i=2;i<N;i++)
    {
        if(d[i]==-1)
        {
            d[i]=i;
            sum[i]=i+1;
        }
        else
        {
            int j=i;
            sum[i]=1;
            while(j%d[i]==0)
            {
                j/=d[i];
                sum[i]=sum[i]*d[i]+1;
            }
            sum[i]*=sum[j];
        }
    }
    return sum;
}