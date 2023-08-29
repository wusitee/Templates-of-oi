#include <algorithm>

const int maxn = 1e4 + 10;
int fa[maxn];
struct edge
{
    int u, v, w;
    bool operator<(const edge a)
    {
        return this->w < a.w;
    }
} e[maxn * maxn]; // 存边
int find(int x)
{
    return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
}
void Merge(int a, int b)
{
    fa[find(a)] = find(b);
} // 并查集
int Kruskal(int m, int n) // m为边的数量,n为点的数量
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        fa[i] = i; // 初始化联通块
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, w] = e[i]; // c++17大法好
        if (find(u) == find(v))
        {
            continue;
        }
        else
        {
            sum += w;
            Merge(u, v);
        }
    }
    return sum;
}