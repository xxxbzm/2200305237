#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

// 定义图的数据结构，使用邻接矩阵表示
class Graph {
private:
    // 顶点数和边数
    int V, E;
    // 邻接矩阵，存储边的权重，如果没有边则为无穷大
    std::vector<std::vector<int>> adjMatrix;
public:
    // 构造函数，初始化图
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        // 初始化邻接矩阵为无穷大
        adjMatrix = std::vector<std::vector<int>>(V, std::vector<int>(V, std::numeric_limits<int>::max()));
    }

    // 添加一条边，给定起点，终点和权重
    void addEdge(int u, int v, int w) {
        // 检查边界条件
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return;
        }
        // 更新邻接矩阵
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // 假设是无向图
    }

    // 打印邻接矩阵
    void printAdjMatrix() {
        std::cout << "邻接矩阵:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == std::numeric_limits<int>::max()) {
                    std::cout << "INF\t"; // 用INF表示无穷大
                }
                else {
                    std::cout << adjMatrix[i][j] << "\t";
                }
            }
            std::cout << "\n";
        }
    }



    // 实现DFS算法，给定起点，打印遍历顺序
    void DFS(int s) {
        // 检查边界条件
        if (s < 0 || s >= V) {
            std::cout << "Invalid source: " << s << "\n";
            return;
        }
        // 创建一个栈，用于存储待访问的顶点
        std::stack<int> st;
        // 创建一个数组，用于标记已访问过的顶点
        std::vector<bool> visited(V, false);
        // 将起点入栈，并标记为已访问
        st.push(s);
        visited[s] = true;
        // 打印遍历顺序
        std::cout << "起点 " << s << " 的DFS遍历顺序为:\n";
        while (!st.empty()) {
            // 取出栈顶元素，并打印
            int u = st.top();
            st.pop();
            std::cout << u << " ";
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != std::numeric_limits<int>::max() && !visited[v]) {
                    st.push(v);
                    visited[v] = true;
                }
            }
        }
        std::cout << "\n";
    }
    // 实现最短路径算法，使用Dijkstra算法，给定起点，打印所有顶点的最短距离
    void shortestPath(int s) {
        if (s < 0 || s >= V) {
            std::cout << "Invalid source: " << s << "\n";
            return;
        }
        // 创建一个数组，用于存储起点到各个顶点的最短距离，初始为无穷大
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        std::vector<bool> visited(V, false);
        dist[s] = 0;
        for (int i = 0; i < V; i++) {
            int u = -1;
            int minDist = std::numeric_limits<int>::max();
            for (int j = 0; j < V; j++) {
                if (!visited[j] && dist[j] < minDist) {
                    u = j;
                    minDist = dist[j];
                }
            }
            // 如果没有找到这样的顶点，说明已经遍历完所有连通的顶点，退出循环
            if (u == -1) {
                break;
            }
            // 标记u为已确定最短距离
            visited[u] = true;
            // 遍历u的所有邻接顶点，如果通过u可以缩短到达v的距离，则更新dist[v]
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != std::numeric_limits<int>::max() && !visited[v] && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
        // 打印起点到各个顶点的最短距离
        std::cout << "起点 " << s << " 到每个节点最短距离:\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == std::numeric_limits<int>::max()) {
                std::cout << i << ": INF\n"; // 用INF表示无穷大
            }
            else {
                std::cout << i << ": " << dist[i] << "\n";
            }
        }
    }
    void minimumSpanningTree() {
        std::vector<int> parent(V, -1);
        std::vector<int> key(V, std::numeric_limits<int>::max());
        std::vector<bool> visited(V, false);
        key[0] = 0;
    }

};

int main() {
    Graph g(6, 9);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 4, 1);
    g.addEdge(4, 5, 1);
    g.printAdjMatrix();
    g.DFS(0);
    g.shortestPath(0);
    g.minimumSpanningTree();
    return 0;
}