#include <bits/stdc++.h>
using namespace std;

// Rotate square matrix (size x size) 90 degrees clockwise
vector<string> rotateClockwise(const vector<string>& mat, int size) {
    vector<string> out(size, string(size, ' '));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            out[j][size - 1 - i] = mat[i][j];
    return out;
}

// Split N x N grid into (K x K) sheets of size M x M
vector<vector<vector<string>>> splitSheets(const vector<string>& grid, int N, int M) {
    int K = N / M;
    vector<vector<vector<string>>> sheets(K, vector<vector<string>>(K));
    for (int br = 0; br < K; ++br) {
        for (int bc = 0; bc < K; ++bc) {
            vector<string> block(M);
            for (int i = 0; i < M; ++i)
                block[i] = grid[br * M + i].substr(bc * M, M);
            sheets[br][bc] = block;
        }
    }
    return sheets;
}

// BFS shortest path from S to D on full grid (walk on 'T' and 'D', start at 'S')
// returns -1 if no path, else distance (count includes S as 1 and includes D)
int shortestPathOnGrid(const vector<string>& full) {
    int N = (int)full.size();
    pair<int,int> S = {-1,-1}, D = {-1,-1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (full[i][j] == 'S') S = {i,j};
            if (full[i][j] == 'D') D = {i,j};
        }
    }
    if (S.first == -1 || D.first == -1) return -1;
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int,int>> q;
    dist[S.first][S.second] = 1;
    q.push(S);
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        if (x == D.first && y == D.second) return dist[x][y];
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] != -1) continue;
            char c = full[nx][ny];
            if (c == 'T' || c == 'D') {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) cin >> grid[i];

    int K = N / M;
    auto sheets = splitSheets(grid, N, M);

    // Prepare 4 rotations for each sheet
    // allRot[r][c][rotIndex] => rotated MxM block
    vector<vector<vector<vector<string>>>> allRot(K, vector<vector<vector<string>>>(K));
    for (int r = 0; r < K; ++r) {
        for (int c = 0; c < K; ++c) {
            vector<string> cur = sheets[r][c];
            for (int rot = 0; rot < 4; ++rot) {
                allRot[r][c].push_back(cur);
                cur = rotateClockwise(cur, M);
            }
        }
    }

    // rotationChoice for each sheet in row-major order
    vector<int> rotationChoice(K * K, 0);
    int best = INT_MAX;

    // DFS over rotations only (positions of sheets are kept as in input)
    function<void(int)> dfs = [&](int idx) {
        if (idx == K * K) {
            // reconstruct full grid
            vector<string> full(N, string(N, ' '));
            for (int sr = 0; sr < K; ++sr) {
                for (int sc = 0; sc < K; ++sc) {
                    int idxTile = sr * K + sc;
                    int rot = rotationChoice[idxTile];
                    const vector<string>& block = allRot[sr][sc][rot];
                    for (int i = 0; i < M; ++i)
                        for (int j = 0; j < M; ++j)
                            full[sr * M + i][sc * M + j] = block[i][j];
                }
            }
            int d = shortestPathOnGrid(full);
            if (d != -1 && d < best) best = d;
            return;
        }
        for (int r = 0; r < 4; ++r) {
            rotationChoice[idx] = r;
            dfs(idx + 1);
        }
    };

    dfs(0);

    if (best == INT_MAX) cout << -1 << '\n';
    else cout << best << '\n';
    return 0;
}