#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};
int dX[] = {0,1,0,-1};
int dY[] = {1,0,-1,0};
bool visited[5][5];
bool valid(int x) {
    return x <= 4 && x >= 0;
}
bool canEatFood(int maze[5][5], int fx, int fy){ //fx,fy is coordinate of destination
    stack<node> st;
    st.push(node(0,0));
    visited[0][0] = true;
    node u (0,0),v (0,0);
    while(!st.empty()) {
        u = st.top();
        st.pop();
        for (int i=0;i<4;i++) {
            v.x = u.x + dX[i];
            v.y = u.y + dY[i];
            if (valid(v.x) && valid(v.y) && maze[v.x][v.y]==1 && !visited[v.x][v.y]) {
                visited[v.x][v.y] = true;
                st.push(v);
                if (v.x == fx-1 && v.y==fy-1)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    int maze[5][5] = {
    { 1, 0, 1, 1, 0 },
    { 1, 1, 1, 0, 1 },
    { 0, 1, 0, 1, 1 },
    { 1, 1, 1, 1, 0 },
    { 1, 0, 0, 1, 0 }
    };

    // Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy);
}