#include <bits/stdc++.h>
using namespace std;

// Structure for a line segment
struct Seg {
    int x1, y1, x2, y2;
};
// Structure for a point
struct Pt {
    int x, y;
    bool operator<(const Pt &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

const double eps = 1e-9;

// Check if point (x,y) lies on segment s (with tolerance)
bool onSegD(double x, double y, const Seg &s) {
    double x1 = s.x1, y1 = s.y1, x2 = s.x2, y2 = s.y2;
    if (min(x1, x2) - eps <= x && x <= max(x1, x2) + eps &&
        min(y1, y2) - eps <= y && y <= max(y1, y2) + eps) {
        double dx = x2 - x1, dy = y2 - y1;
        double dx1 = x - x1, dy1 = y - y1;
        if (fabs(dx) < eps && fabs(dy) < eps) return fabs(x - x1) < eps && fabs(y - y1) < eps;
        if (fabs(dx) < eps) return fabs(dx1) < eps;
        if (fabs(dy) < eps) return fabs(dy1) < eps;
        // compare ratios with tolerance
        return fabs(dx1 / dx - dy1 / dy) < 1e-7;
    }
    return false;
}

// Map dx,dy to one of 8 directions (N, E, S, W, NW, NE, SE, SW)
int dirIndex(int dx, int dy) {
    if (dx == 0 && dy > 0) return 0;      // N
    if (dx > 0 && dy == 0) return 1;      // E
    if (dx == 0 && dy < 0) return 2;      // S
    if (dx < 0 && dy == 0) return 3;      // W
    if (dx < 0 && dy > 0 && abs(dx) == abs(dy)) return 4;  // NW
    if (dx > 0 && dy > 0 && abs(dx) == abs(dy)) return 5;  // NE
    if (dx > 0 && dy < 0 && abs(dx) == abs(dy)) return 6;  // SE
    if (dx < 0 && dy < 0 && abs(dx) == abs(dy)) return 7;  // SW
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Seg> segs(N);
    for (int i = 0; i < N; i++) cin >> segs[i].x1 >> segs[i].y1 >> segs[i].x2 >> segs[i].y2;

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    // Step 1: Find candidate intersection points (potential star centers)
    set<pair<int, int>> cand;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double x1 = segs[i].x1, y1 = segs[i].y1, x2 = segs[i].x2, y2 = segs[i].y2;
            double x3 = segs[j].x1, y3 = segs[j].y1, x4 = segs[j].x2, y4 = segs[j].y2;
            double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

            if (fabs(den) < eps) {
                // Parallel or collinear segments: check endpoints overlap
                vector<pair<int, int>> pts = {{segs[i].x1, segs[i].y1}, {segs[i].x2, segs[i].y2},
                                              {segs[j].x1, segs[j].y1}, {segs[j].x2, segs[j].y2}};
                for (auto &p : pts)
                    if (onSegD(p.first, p.second, segs[i]) && onSegD(p.first, p.second, segs[j]))
                        cand.insert(p);
            } else {
                // Calculate intersection
                double xi = ((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4)) / den;
                double yi = ((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4)) / den;
                double rx = round(xi), ry = round(yi);
                if (fabs(xi - rx) < 1e-7 && fabs(yi - ry) < 1e-7) {
                    int xiI = (int)rx, yiI = (int)ry;
                    if (onSegD(xiI, yiI, segs[i]) && onSegD(xiI, yiI, segs[j])) cand.insert({xiI, yiI});
                }
            }
        }
    }

    // Step 2: Collect star centers (points lying on >=2 segments)
    vector<pair<int, int>> centers;
    for (auto &p : cand) {
        int cx = p.first, cy = p.second;
        int cnt = 0;
        for (auto &s : segs) if (onSegD(cx, cy, s)) cnt++;
        if (cnt >= 2) centers.push_back({cx, cy});
    }

    int S = (int)centers.size();
    if (S == 0) {
        cout << "Impossible\n";
        return 0;
    }

    // Step 3: Prepare star reachability (cardinal and diagonal)
    vector<int> maxCard(S, 0), maxDiag(S, 0);
    vector<vector<int>> segsPerCenter(S);
    for (int i = 0; i < S; i++) {
        int cx = centers[i].first, cy = centers[i].second;
        for (int j = 0; j < N; j++) {
            if (onSegD(cx, cy, segs[j])) {
                segsPerCenter[i].push_back(j);
                // Check both endpoints
                pair<int,int> endpoints[2] = {{segs[j].x1,segs[j].y1},{segs[j].x2,segs[j].y2}};
                for (int k = 0; k < 2; ++k) {
                    int ex = endpoints[k].first;
                    int ey = endpoints[k].second;
                    if (ex == cx && ey == cy) continue;
                    int dx = ex - cx, dy = ey - cy;
                    int di = dirIndex(dx, dy);
                    if (di == -1) continue;
                    int len = max(abs(dx), abs(dy));
                    if (di <= 3) maxCard[i] = max(maxCard[i], len);
                    else maxDiag[i] = max(maxDiag[i], len);
                }
            }
        }
    }

    auto pointOnCenterStar = [&](int px,int py,int ci)->bool{
        for(int sid: segsPerCenter[ci]) if(onSegD(px,py,segs[sid])) return true;
        return false;
    };

    // Step 4: Find start and target stars
    vector<int> starts, targets;
    for(int i=0;i<S;i++){
        if(pointOnCenterStar(sx,sy,i)) starts.push_back(i);
        if(pointOnCenterStar(tx,ty,i)) targets.push_back(i);
    }
    if(starts.empty() || targets.empty()){
        cout<<"Impossible\n"; return 0;
    }

    // Step 5: Build adjacency list (graph)
    vector<vector<int>> adj(S);
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++) if(i!=j){
            int dx = centers[j].first - centers[i].first;
            int dy = centers[j].second - centers[i].second;
            int di = dirIndex(dx,dy);
            if(di == -1) continue;
            int need = max(abs(dx), abs(dy));
            if(di <= 3){
                if(maxCard[i] >= need) adj[i].push_back(j);
            } else {
                if(maxDiag[i] >= need) adj[i].push_back(j);
            }
        }
    }

    // Step 6: BFS to find minimum stars
    vector<int> dist(S, -1);
    queue<int> q;
    for(int s: starts){ dist[s]=1; q.push(s); }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: adj[u]) if(dist[v]==-1){ dist[v]=dist[u]+1; q.push(v); }
    }

    int ans=INT_MAX;
    for(int t: targets) if(dist[t]!=-1) ans=min(ans, dist[t]);
    if(ans==INT_MAX) cout<<"Impossible\n"; else cout<<ans<<"\n";

    return 0;
}
