#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int lg[maxn];

void init_log() {
    for (int i = 1; i < maxn; i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
}

vector<int> g[maxn];

int fa[maxn][32], dep[maxn];
bool vst[maxn];

void dfs(int pos, int father) {
    fa[pos][0] = father, vst[pos] = true;
    dep[pos] = dep[father] + 1;
    for (int i = 1; i <= lg[dep[pos]]; i++) {
        fa[pos][i] = fa[fa[pos][i - 1]][i - 1];
    }
    for (auto nxt : g[pos]) {
        dfs(nxt, pos);
    }
}
