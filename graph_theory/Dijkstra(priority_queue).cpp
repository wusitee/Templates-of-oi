#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

const int maxn = 1e4 + 10;

struct Edge
{
    int to, weight;
    bool operator<(const Edge &a)
    {
        return this->weight < a.weight;
    }
};

std::vector<Edge> G[maxn]; // 存储图的邻接表
int dis[maxn];             // 存储起始节点到各节点的最短距离
bool vst[maxn];            // 标记节点是否已访问过

void dijkstra(int n, int stp)
{
    std::priority_queue<Edge> p;              // 优先队列，用于选择当前权重最小的边
    std::fill(dis + 1, dis + n + 1, INT_MAX); // 初始化距离数组为正无穷
    dis[stp] = 0;                             // 起始节点到自身的距离为0
    p.push({stp, 0});                         // 将起始节点加入优先队列

    while (!p.empty())
    {
        auto [u, w] = p.top(); // 弹出当前权重最小的边
        p.pop();

        if (vst[u])
            continue; // 如果节点已经访问过，跳过

        vst[u] = true; // 标记节点为已访问

        // 遍历从节点u可达的所有边
        for (auto v : G[u])
        {
            auto [t, wei] = v; // t为目标节点，wei为边的权重

            // 如果经过节点u到达节点t的距离更短
            if (dis[t] > dis[u] + wei)
            {
                dis[t] = dis[u] + wei; // 更新最短距离
                p.push({t, dis[t]});   // 将节点t及其新距离加入优先队列，以便后续处理
            }
        }
    }
}
