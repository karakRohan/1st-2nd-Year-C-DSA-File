#include <bits/stdc++.h>
using namespace std;

struct Seg{int x1,y1,x2,y2;};

bool onSeg(int x,int y,const Seg &s){
    int x1=s.x1,y1=s.y1,x2=s.x2,y2=s.y2;
    if(min(x1,x2) <= x && x <= max(x1,x2) && min(y1,y2) <= y && y <= max(y1,y2)){
        if(x1==x2 && y1==y2) return x==x1 && y==y1;
        int dx = x2 - x1, dy = y2 - y1;
        if(dx==0) return x==x1;
        if(dy==0) return y==y1;
        return (x - x1) * dy == (y - y1) * dx;
    }
    return false;
}

double yOnSegAtX(int x,const Seg &s){
    double x1=s.x1, y1=s.y1, x2=s.x2, y2=s.y2;
    if(!(min(s.x1,s.x2) <= x && x <= max(s.x1,s.x2))) return 1e9;
    if(fabs(x2 - x1) < 1e-9) return 1e9;
    double t = (x - x1) / (x2 - x1);
    return y1 + t * (y2 - y1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; if(!(cin>>N)) return 0;
    vector<Seg> segs(N);
    for(int i=0;i<N;i++) cin>>segs[i].x1>>segs[i].y1>>segs[i].x2>>segs[i].y2;
    int sx,sy; cin>>sx>>sy;
    int cx = sx, cy = sy;
    set<pair<int,int>> visited;
    for(int steps=0; steps<10000; ++steps){
        if(visited.count({cx,cy})) break;
        visited.insert({cx,cy});
        
        bool slid = false;
        for(const auto &s: segs){
            if(onSeg(cx,cy,s)){
                pair<int,int> p1 = {s.x1,s.y1}, p2 = {s.x2,s.y2};
                pair<int,int> lower = (p1.second <= p2.second) ? p1 : p2;
                
                if(lower.first==cx && lower.second==cy){
                    
                    slid = false;
                } else {
                    cx = lower.first; cy = lower.second;
                    slid = true;
                }
                break;
            }
        }
        if(slid) continue;
        
        double bestY = -1e9;
        int hitIndex = -1;
        for(int i=0;i<N;i++){
            double yhit = yOnSegAtX(cx, segs[i]);
            if(yhit < cy - 1e-9){ // strictly below current
                if(yhit > bestY){
                    bestY = yhit; hitIndex = i;
                }
            }
        }
        if(hitIndex==-1){
            cy = 0;
            break;
        } else {
            int yint = (int)round(bestY);
            
            if(yint==cy){
                
            }
            cx = cx; cy = yint;
            continue;
        }
    }
    cout<<cx<<" "<<cy<<"\n";
    return 0;
}