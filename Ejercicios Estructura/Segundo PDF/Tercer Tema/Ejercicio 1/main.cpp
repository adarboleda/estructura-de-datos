// Programa7_Ejercicio1_SegundoConjunto.cpp
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

// Definición de una lista dinámica simple (MyList)
template<typename T>
class MyList {
public:
    T* data;
    int capacity;
    int count;
    MyList() : capacity(10), count(0) {
        data = new T[capacity];
    }
    ~MyList() { delete [] data; }
    void push_back(const T &value) {
        if (count == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < count; i++)
                newData[i] = data[i];
            delete [] data;
            data = newData;
        }
        data[count++] = value;
    }
    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
    int size() const { return count; }
};

// Utilizaremos std::pair para representar celdas (fila, columna)
typedef pair<int, int> pii;

// Función que obtiene los vecinos (4 direcciones) de una celda en el laberinto
MyList<pii> getNeighbors(const MyList<MyList<int>> &maze, pii cell) {
    MyList<pii> neighbors;
    int rows = maze.size();
    int cols = maze[0].size();
    int x = cell.first, y = cell.second;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == 0)
            neighbors.push_back({nx, ny});
    }
    return neighbors;
}

void solveLabyrinth(const MyList<MyList<int>> &maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    // Crear estructuras "dist" y "prev" usando MyList
    MyList<MyList<int>> dist;
    MyList<MyList<pii>> prev;
    for (int i = 0; i < rows; i++) {
        MyList<int> dRow;
        MyList<pii> pRow;
        for (int j = 0; j < cols; j++) {
            dRow.push_back(numeric_limits<int>::max());
            pRow.push_back({-1, -1});
        }
        dist.push_back(dRow);
        prev.push_back(pRow);
    }
    
    // Usamos priority_queue de la STL (para simplicidad) para la cola de prioridades.
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int d = std::get<0>(current);
        int x = std::get<1>(current);
        int y = std::get<2>(current);
        if (d > dist[x][y]) continue;
        if (x == rows - 1 && y == cols - 1) break; // destino alcanzado
        MyList<pii> neighbors = getNeighbors(maze, pii(x,y));
        for (int i = 0; i < neighbors.size(); i++) {
            pii nb = neighbors[i];
            int nx = nb.first, ny = nb.second;
            if (dist[nx][ny] > d + 1) {
                dist[nx][ny] = d + 1;
                prev[nx][ny] = std::make_pair(x, y);
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    
    if (dist[rows - 1][cols - 1] == numeric_limits<int>::max()) {
        cout << "No se encontró camino en el laberinto." << endl;
        return;
    }
    
    cout << "Camino más corto encontrado (longitud = " << dist[rows - 1][cols - 1] << "):" << endl;
    MyList<pii> path;
    int cx = rows - 1, cy = cols - 1;
    while (!(cx == 0 && cy == 0)) {
        path.push_back({cx, cy});
        pii p = prev[cx][cy];
        cx = p.first; cy = p.second;
    }
    path.push_back({0, 0});
    // Invertir la lista "path" manualmente
    for (int i = 0, j = path.size()-1; i < j; i++, j--) {
        swap(path.data[i], path.data[j]);
    }
    for (int i = 0; i < path.size(); i++) {
        cout << "(" << path[i].first << "," << path[i].second << ") ";
    }
    cout << endl;
}

int main() {
    // Construir el laberinto como una lista de listas (0 = celda libre, 1 = pared)
    MyList<MyList<int>> maze;
    {
        MyList<int> row;
        row.push_back(0); row.push_back(0); row.push_back(1); row.push_back(0);
        maze.push_back(row);
    }
    {
        MyList<int> row;
        row.push_back(1); row.push_back(0); row.push_back(0); row.push_back(0);
        maze.push_back(row);
    }
    {
        MyList<int> row;
        row.push_back(0); row.push_back(0); row.push_back(1); row.push_back(0);
        maze.push_back(row);
    }
    {
        MyList<int> row;
        row.push_back(0); row.push_back(1); row.push_back(0); row.push_back(0);
        maze.push_back(row);
    }
    
    cout << "Ejercicio 1 (segundo conjunto): Laberinto - Camino más corto usando Dijkstra" << endl;
    solveLabyrinth(maze);
    return 0;
}
