#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXX = 500 + 10;
struct Edge {
    int vertex, weight;
};

vector<Edge> edges[MAXX];
bool visited[MAXX];
long long  dist[MAXX];
long long  team[MAXX];
long long team_sum[MAXX];
long long road[MAXX];
int n, m,c1,c2;

void dijkstra(int v) {
    dist[v] = 0;
    road[v] = 1;
    team_sum[v]=team[v];
    for(int i = 0;i < n;i++){
        int min_dist = INF,min_vertex;
        for(int j = 0;j < n; j++){
            if(!visited[j] && dist[j] < min_dist){
                min_dist = dist[j];
                min_vertex = j;
            }
        }
        visited[min_vertex] = 1;
        for(int j = 0;j < edges[min_vertex].size();j++){
            Edge temp = edges[min_vertex][j];
            if( min_dist + temp.weight < dist[temp.vertex]){
                road[temp.vertex] = road[min_vertex];
                dist[temp.vertex] = min_dist + temp.weight;
                team_sum[temp.vertex] = team_sum[min_vertex] + team[temp.vertex];
            }
            else if( min_dist + temp.weight == dist[temp.vertex]){
                road[temp.vertex] += road[min_vertex];
                dist[temp.vertex] = min_dist + temp.weight;
                team_sum[temp.vertex] = max(team_sum[temp.vertex], team_sum[min_vertex] + team[temp.vertex]);
            }
        }
    }
}

int main() {
    while ((cin >> n >> m >> c1 >> c2) && n && m){
        memset(edges,0, sizeof(edges));
        memset(visited, 0, sizeof(visited));
        memset(dist, 0x3f, sizeof(dist));
        memset(team,0, sizeof(team));
        memset(road,0, sizeof(road));

        for (int i = 0; i < n; i++){
            cin >> team[i];
        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges[a].push_back(Edge{b, c});
            edges[b].push_back(Edge{a, c});
        }
        dijkstra(c2);
        cout << road[c1] << " " << team_sum[c1] <<endl;

    }
    return 0;
}