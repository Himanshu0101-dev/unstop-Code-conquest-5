#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> islandId;
unordered_map<int,int> sizes;

int dfs(int r, int c, int idVal) {
    stack<pair<int,int>> st;
    st.push({r,c});
    islandId[r][c] = idVal;
    int size = 1;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!st.empty()) {
        auto [x,y] = st.top(); st.pop();
        for(auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if(nx>=0 && nx<N && ny>=0 && ny<N) {
                if(grid[nx][ny] == 1 && islandId[nx][ny] == 0) {
                    islandId[nx][ny] = idVal;
                    size++;
                    st.push({nx,ny});
                }
            }
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    grid.assign(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> grid[i][j];
        }
    }

    islandId.assign(N, vector<int>(N,0));
    int idCounter = 2;
    int maxIsland = 0;

    // Step 1: find islands
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 1 && islandId[i][j] == 0) {
                int size = dfs(i,j,idCounter);
                sizes[idCounter] = size;
                maxIsland = max(maxIsland, size);
                idCounter++;
            }
        }
    }

    // Step 2: try flipping each 0
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 0) {
                unordered_set<int> seen;
                int newSize = 1;
                for(auto &d : dirs) {
                    int nx = i + d[0], ny = j + d[1];
                    if(nx>=0 && nx<N && ny>=0 && ny<N) {
                        int idVal = islandId[nx][ny];
                        if(idVal > 1 && seen.find(idVal) == seen.end()) {
                            seen.insert(idVal);
                            newSize += sizes[idVal];
                        }
                    }
                }
                maxIsland = max(maxIsland, newSize);
            }
        }
    }

    // Edge case: no land at all
    if(maxIsland == 0) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 0) {
                    maxIsland = 1;
                    break;
                }
            }
        }
    }

    cout << maxIsland << "\n";
    return 0;
}
