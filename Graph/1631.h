//
// Created by QinJM on 2023/12/11.
//

#ifndef LEETCODE_1631_H
#define LEETCODE_1631_H
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
    struct ifo{
        int height;
        int x;
        int y;
        int count;
        ifo() = default;
        ifo(int a, int b, int c, int d){
            height = a;
            x = b;
            y = c;
            count  = d+1;
        }
    };
    struct cmp{
        bool operator()(ifo* x, ifo *y) const {
            return x->height > y->height;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        ifo *origin = new ifo(0, 0, 0, 0);
        priority_queue<ifo*, vector<ifo*> , cmp> q;
        q.push(origin);
        int ret = -1;
        while(!q.empty()){
            ifo *now = q.top(); q.pop();
            if(now->x==row-1 && now->y==col-1){
                ret = now->height;
                break;
            }
            int nx = now->x;
            int ny = now->y;
            if(nx-1>=0 ){
                int tmpH = static_cast<int>(abs(heights[nx-1][ny] - heights[nx][ny]));
                int H = tmpH > now->height? tmpH : now->height;
                ifo *tmp = new ifo(H, nx-1, ny, now->count);
                if(tmp->count <= col*row)
                    q.push(tmp);
            }
            if(ny-1>=0){
                int tmpH = static_cast<int>(abs(heights[nx][ny-1] - heights[nx][ny]));
                int H = tmpH > now->height? tmpH : now->height;
                ifo *tmp = new ifo(H, nx, ny-1, now->count);
                if(tmp->count <= col*row)
                    q.push(tmp);
            }
            if(nx+1<row){
                int tmpH = static_cast<int>(abs(heights[nx+1][ny] - heights[nx][ny]));
                int H = tmpH > now->height? tmpH : now->height;
                ifo *tmp = new ifo(H, nx+1, ny, now->count);
                if(tmp->count <= col*row)
                    q.push(tmp);
            }
            if(ny+1<col){
                int tmpH = static_cast<int>(abs(heights[nx][ny+1] - heights[nx][ny]));
                int H = tmpH > now->height? tmpH : now->height;
                ifo *tmp = new ifo(H, nx, ny+1, now->count);
                if(tmp->count <= col*row)
                    q.push(tmp);
            }
        }
        return ret;
    }
};
#endif //LEETCODE_1631_H
