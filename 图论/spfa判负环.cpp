#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <iostream>

const int maxn = 1e4 + 10;
std::queue<int> q;
int dis[maxn],len[maxn];//判断负环
struct Edge
{
    int to, w;
    bool operator<(const Edge &a) const
    {
        return this->w < a.w;
    }
};
std::vector<Edge> g[maxn];
bool inq[maxn];

void spfa_judge(int n)
{
    std::fill(dis + 1, dis + 1 + n, INT_MAX);
    dis[1] = 0, inq[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto v : g[u])
        {
            if (dis[v.to] > dis[u] + v.w)
            {
                dis[v.to] = dis[u] + v.w;
                len[v.to] = len[u] + 1;
                if(len[v.to] == n)//如果最短路长度大于等于n，就说明有负环
                {
                    puts("Yes");
                    return;
                }
                if (!inq[v.to])
                {
                    q.push(v.to);
                    inq[v.to] = true;
                }
            }
        }
    }
    puts("No");
} // 好像广搜