#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstring>

const int maxn=1e4+10;
int f[maxn][maxn];

void Floryd(int n)
{
    for(int k=1;k<=n;k++)
    {
        f[k][k]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(f[i][j]==-1) f[i][j]=INT_MAX;
                f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
            }
    }
}

int main()
{
    int n,m;
    std::cin>>n>>m;
    std::memset(f,-1,sizeof(f));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        std::cin>>u>>v>>w;
        f[u][v]=w;
    }
    Floryd(n);
    return 0;
}