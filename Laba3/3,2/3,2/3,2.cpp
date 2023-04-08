#include <iostream>
#include<climits>

using namespace std;

int** set_graph(int);

int main()
{
    int n, v = 0;
    int min = INT_MAX;
    int vx;
    cout << "Enter number of vertexes : ";
    cin >> n;
    int** graph = set_graph(n);
    int* min_e = new int[n] {0}, * sel_e = new int[n] {0}, * visited = new int[n] {0};
    // min_e[v] = -1;
    // sel_e[v] = -1;
    visited[v] = -1;

    while (true) {
        vx = -1;
        for (int i = 0; i < n; i++) {
            min = INT_MAX;

            if (visited[i] != -1) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] == -1) {
                        if (graph[i][j] <= min) {
                            min = graph[i][j];
                            vx = j;
                        }
                    }
                }

                sel_e[i] = vx;
                min_e[i] = min;

            }

        }
        if (vx == -1)
            break;
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (min_e[i] < min && visited[i] != -1) {
                min = min_e[i];
                vx = i;
            }
        }

        visited[vx] = -1;

        for (int i = 0; i < n; i++) {
            cout << i << " : " << sel_e[i] << " " << min_e[i] << " visited : " << visited[i] << endl;
        }
        cout << endl;
    }

}

int** set_graph(int n) {
    // cout << "Enter number of vertexes : ";
    // cin >> n;
    // cout << endl;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        cout << "v" << i << " : ";
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                arr[i][j] = INT_MAX;
        }
        cout << endl;
    }
    return arr;
}

