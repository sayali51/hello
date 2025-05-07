 #include <iostream>
#include<map>
#include<climits>
using namespace std;

class graph {
	map<string,int> cityIndex;
	string cities[10];
    int a[10][10], b[10][10];
    int n;

public:
    graph(int x) {
        n = x;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                a[i][j] = INT_MAX; // Initialize adjacency and MST matrix
                b[i][j]=0;
    }

    void prims() {
        int visited[10]={0}, from[10], dist[10];
        int sum = 0;

        for (int i = 0; i < n; i++) {
           
            dist[i] =INT_MAX;
            from[i] = 0;
        }
        dist[0]=0;

        visited[0] = 1;
        int edges =0;

        while (edges<n-1) {
            int min =INT_MAX, u = -1, v = -1;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    v = i;
                    u = from[v];
                }
            }

            if (u != -1 && v != -1) {
                b[u][v] = b[v][u] = min;
                sum += min;
                visited[v] =1;
                edges++;

                for (int i = 0; i < n; i++) {
                    if (!visited[i] && a[i][v] < dist[i]) {
                        dist[i] = a[i][v];
                        from[i] = v;
                    }
                }
            }
        }
        cout << "The sum of the minimum spanning tree is: " << sum << endl;
    }

    void input() {
        cout << "Enter names of the cities (Enter -1 for no edge):\n";
        for (int i = 0; i < n; i++) {
                cin >>cities[i];
                cityIndex[cities[i]]=i;
	    }
	    cout << "Enter the weight of the adjacency matrix(-1 for no edge):";
        for (int i=0;i<n;i++){
        	for(int j=i+1;j<n;j++){
        		cout << "Enter the weight of the edge (" <<cities[i]<< "," <<cities[j]<< ") = ";
        		cin>>a[i][j];
			    if (a[i][j] == -1) {  // No edge
                    a[i][j] = a[j][i] = 100;  // A large value to indicate no connection
                } else {
                    a[j][i] = a[i][j];  // Automatically assign the same value to (j, i)
                }
            }
            a[i][i] = 0;  // No self-loops
        }
    }

    void display() {
        cout << "Minimum Spanning Tree Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n > 10) {
        cout << "Error: Maximum number of vertices is 10.\n";
        return 1;
    }

    graph g(n);
    g.input();
    g.prims();
    g.display();

    return 0;
}
