#include <algorithm>
#include <limits.h>

const int maxn = 1e4 + 10;
int G[maxn][maxn]; // 邻接矩阵存图(因为是稠密图)
int dis[maxn];
bool used[maxn];
int Prim(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        dis[i] = G[1][i];
    used[1] = true; // 先把节点1加入到最小生成树中,并更新初始dis数组
    for (int i = 1; i <= n - 1; i++)
    {
        int minn = INT_MAX, mind;
        for (int j = 1; j <= n; j++)
        {
            if (minn > dis[j] && !used[j])
            {
                minn = dis[j];
                mind = i;
            }
        } // 找到离当前生成树最近的节点
        used[mind] = true;
        sum += minn; // 把它加入生成树
        for (int j = 1; j <= n; j++)
        {
            dis[j] = std::min(dis[j], G[mind][j]);
        } // 更改其他节点
    }
    return sum;
}