#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

// ����ͼ�����ݽṹ��ʹ���ڽӾ����ʾ
class Graph {
private:
    // �������ͱ���
    int V, E;
    // �ڽӾ��󣬴洢�ߵ�Ȩ�أ����û�б���Ϊ�����
    std::vector<std::vector<int>> adjMatrix;
public:
    // ���캯������ʼ��ͼ
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        // ��ʼ���ڽӾ���Ϊ�����
        adjMatrix = std::vector<std::vector<int>>(V, std::vector<int>(V, std::numeric_limits<int>::max()));
    }

    // ���һ���ߣ�������㣬�յ��Ȩ��
    void addEdge(int u, int v, int w) {
        // ���߽�����
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return;
        }
        // �����ڽӾ���
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // ����������ͼ
    }

    // ��ӡ�ڽӾ���
    void printAdjMatrix() {
        std::cout << "�ڽӾ���:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == std::numeric_limits<int>::max()) {
                    std::cout << "INF\t"; // ��INF��ʾ�����
                }
                else {
                    std::cout << adjMatrix[i][j] << "\t";
                }
            }
            std::cout << "\n";
        }
    }



    // ʵ��DFS�㷨��������㣬��ӡ����˳��
    void DFS(int s) {
        // ���߽�����
        if (s < 0 || s >= V) {
            std::cout << "Invalid source: " << s << "\n";
            return;
        }
        // ����һ��ջ�����ڴ洢�����ʵĶ���
        std::stack<int> st;
        // ����һ�����飬���ڱ���ѷ��ʹ��Ķ���
        std::vector<bool> visited(V, false);
        // �������ջ�������Ϊ�ѷ���
        st.push(s);
        visited[s] = true;
        // ��ӡ����˳��
        std::cout << "��� " << s << " ��DFS����˳��Ϊ:\n";
        while (!st.empty()) {
            // ȡ��ջ��Ԫ�أ�����ӡ
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
    // ʵ�����·���㷨��ʹ��Dijkstra�㷨��������㣬��ӡ���ж������̾���
    void shortestPath(int s) {
        if (s < 0 || s >= V) {
            std::cout << "Invalid source: " << s << "\n";
            return;
        }
        // ����һ�����飬���ڴ洢��㵽�����������̾��룬��ʼΪ�����
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
            // ���û���ҵ������Ķ��㣬˵���Ѿ�������������ͨ�Ķ��㣬�˳�ѭ��
            if (u == -1) {
                break;
            }
            // ���uΪ��ȷ����̾���
            visited[u] = true;
            // ����u�������ڽӶ��㣬���ͨ��u�������̵���v�ľ��룬�����dist[v]
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != std::numeric_limits<int>::max() && !visited[v] && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
        // ��ӡ��㵽�����������̾���
        std::cout << "��� " << s << " ��ÿ���ڵ���̾���:\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == std::numeric_limits<int>::max()) {
                std::cout << i << ": INF\n"; // ��INF��ʾ�����
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