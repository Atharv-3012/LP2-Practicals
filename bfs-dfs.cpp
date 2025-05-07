#include<iostream>
#define Max 100
using namespace std;

class Graph {
    int adj[Max][Max];
    int visited[Max];
    int n;

public:
    Graph(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addedge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void dfs(int v) {
        visited[v] = 1;
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }

    void bfs(int start) {
        cout << start << " ";
        int queue[Max], front = 0, rear = 0;
        visited[start] = 1;
        queue[rear++] = start;

        while (front < rear) {
            int curr = queue[front++]; 
            for (int i = 0; i < n; i++) {
                if (adj[curr][i] == 1 && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                    cout << i << " ";
                }
            }
        }
    }

    void reset_visited() {
        for (int i = 0; i < Max; i++) {
            visited[i] = 0;
        }
    }
};

int main() {
    int vertices, edges, u, v, start;
    int choice;
    
    // Take number of vertices as input
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create the graph object
    Graph g(vertices);

    // Take number of edges as input
    cout << "Enter number of edges: ";
    cin >> edges;

    // Take edges input and add them to the graph
    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addedge(u, v);
    }

    // Take the starting vertex for traversal
    cout << "Enter starting vertex for traversal: ";
    cin >> start;

    // Take the user's choice for BFS or DFS
    cout << "Choose Traversal Algorithm:\n";
    cout << "1. DFS (Depth-First Search)\n";
    cout << "2. BFS (Breadth-First Search)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Perform DFS if the user selects 1
        cout << "DFS Traversal: ";
        g.dfs(start);
    } 
    else if (choice == 2) {
        // Perform BFS if the user selects 2
        cout << "BFS Traversal: ";
        g.reset_visited();  // Reset visited array before BFS
        g.bfs(start);
    }
    else {
        cout << "Invalid choice. Please choose either 1 (DFS) or 2 (BFS).\n";
    }

    return 0;
}

// Enter number of vertices: 5
// Enter number of edges: 4
// Enter 4 edges (u v):
// 0 1
// 0 2
// 1 3
// 1 4
// Enter starting vertex for traversal: 0
// Choose Traversal Algorithm:
// 1. DFS (Depth-First Search)
// 2. BFS (Breadth-First Search)
// Enter your choice (1 or 2): 1

// DFS Traversal: 0 1 3 4 2
