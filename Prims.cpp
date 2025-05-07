#include<iostream>
#define Max 100
#define INF 999
using namespace std;
int cost[Max][Max];
int visited[Max];
void prim(int n){
    int totalcost=0;
    visited[0]=1;
    for(int edges=1;edges<n ; edges++){
        int min=INF;
        int u=-1;
        int v=-1;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(cost[i][j]&&!visited[j]&&cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(u!=-1&&v!=-1){
            cout<<"edge "<<u<<"- "<<v<<"| cost- "<<min<<endl;
            totalcost+=min;
            visited[v]=1;
        }
    }
    cout<<"Total Minimum Cost : "<<totalcost<<endl;
}
int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix (0 for no edge) (" << n <<" in one Row) : ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    prim(n);
    return 0;
}

// Enter number of vertices: 4
// Enter cost matrix (0 for no edge) (4 in one Row) : 
// 0 10 0 20
// 10 0 30 0
// 0 30 0 10
// 20 0 10 0

// edge 0- 1| cost- 10
// edge 0- 3| cost- 20
// edge 1- 2| cost- 30
// Total Minimum Cost : 60
