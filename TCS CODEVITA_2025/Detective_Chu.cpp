#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; ++i) cin >> grid[i];

    string sequence;
    cin >> sequence;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    set<pair<int,int>> finalLocations;

    for (int startRow = 0; startRow < R; ++startRow) {
        for (int startCol = 0; startCol < C; ++startCol) {
            if (grid[startRow][startCol] == '#') continue;

            for (int startDir = 0; startDir < 4; ++startDir) {
                int currRow = startRow, currCol = startCol, currDir = startDir;
                bool valid = true;

                for (char move : sequence) {
                    if (move == 'L') currDir = (currDir + 3) % 4;
                    else if (move == 'R') currDir = (currDir + 1) % 4;
                    else {
                        int nr = currRow + dr[currDir];
                        int nc = currCol + dc[currDir];
                        if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') {
                            valid = false;
                            break;
                        }
                        currRow = nr;
                        currCol = nc;
                    }
                }

                if (valid) finalLocations.insert({currRow, currCol});
            }
        }
    }

    if (finalLocations.empty()) cout << "Impossible";
    else cout << finalLocations.size();

    return 0;
}