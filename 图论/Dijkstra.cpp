#include <algorithm>
#include <limits.h>
const int maxn = 1e4 + 10;
int G[maxn][maxn];
int dis[maxn];
bool vst[maxn];
void dijkstra(int n, int stp)
{
    std::fill(dis + 1, dis + 1 + n, INT_MAX);//优雅
    vst[stp] = true;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = std::min(dis[i], G[stp][i]);
    }//首先从起点开始松弛
    for (int i = 1; i <= n - 1; i++)
    {
        int minn = INT_MAX, mind;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] < minn && !vst[j])
            {
                minn = dis[j];
                mind = j;
            }
        }//找到离起点最近的点
        vst[mind] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[j] = std::min(dis[j], G[mind][j]);
        }//松弛
    }
}