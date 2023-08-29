#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>

const int maxn=110;
int ind[maxn];
std::vector <int> g[maxn];

std::vector <int> Topological_Sorting(int n)
{
    std::vector <int> ans;
    std::queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0) 
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(auto v : g[u])
        {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    return ans;
}