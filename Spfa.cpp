#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

const int maxn = 1e4 + 10;
std::queue<int> q;
int dis[maxn];
struct Edge
{
    int to, w;
    bool operator<(const Edge &a) const
    {
        return this->w < a.w;
    }
};
std::vector<Edge> g[maxn];
bool inq[maxn];//记录是否在队列中

void spfa(int n, int stp)
{
    std::fill(dis + 1, dis + 1 + n, INT_MAX);
    dis[stp] = 0, inq[stp] = true;
    q.push(stp);//让起点进队，同时更行起点到起点距离
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto v : g[u])
        {
            if (dis[v.to] > dis[u] + v.w)//松弛操作
            {
                dis[v.to] = dis[u] + v.w;
                if (!inq[v.to])
                {
                    q.push(v.to);
                    inq[v.to] = true;
                }//重新进队
            }
        }
    }
}
