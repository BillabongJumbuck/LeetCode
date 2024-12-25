//
// Created by QinJM on 2023/11/8.
//

#ifndef LEETCODE_1584_H
#define LEETCODE_1584_H
#include <vector>
#include <cmath>

#define MAXNUM 5e6
using std::vector;
typedef int WeightType;
typedef int VertexType;
struct Edge{
    VertexType v1, v2;
    WeightType weight;
    Edge(int i, int j, const vector<int> &x, vector<int> &y){
        v1 = i;
        v2 = j;
        weight = getDistance(x, y);
    }
    int getDistance(const vector<int> &x, vector<int> &y){
        return abs(x[0] - y[0])+abs(x[1]-y[1]);
    }
};
struct Graph{
    int Vnum;
    int Enum;
    vector<vector<int>> G;
    Graph(int Vnum){
        this->Vnum = Vnum;
        Enum = 0;
        G = vector<vector<int>>(Vnum, vector<int>(Vnum, 0));
    }
    void InserEdge(Edge* E){
        G[E->v1][E->v2] = E->weight;
        G[E->v2][E->v1] = E->weight;
        Enum++;
    }
};

class Solution {
private:
    Graph *graph;

    VertexType FindMinDist(const vector<WeightType> &dist){
        VertexType  minV;
        WeightType minDist = MAXNUM;

        for(int i=0;i<dist.size();++i){
            if(dist[i]!=0 && dist[i]<minDist){
                minDist = dist[i];
                minV = i;
            }
        }
        if(minDist<MAXNUM)
            return minV;
        else
            return -1;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 建立图
        graph = new Graph(points.size());
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                Edge *E = new Edge(i , j, points[i], points[j]);
                graph->InserEdge(E);
            }
        }

        vector<WeightType> dist(points.size(), 0);
        WeightType totalWeight = 0;
        int Vcount = 0;
        for(int i=0;i<graph->Vnum;i++){
            dist[i] = graph->G[0][i];
        }

        dist[0] = 0;
        Vcount++;

        VertexType V;
        while(true){
            V = FindMinDist(dist);
            if(V == -1)
                break;

            totalWeight+=dist[V];
            dist[V] = 0;
            Vcount++;

            for(int i=0;i<graph->Vnum;i++){
                if(dist[i]!=0 && dist[i]>graph->G[V][i]){
                    dist[i] = graph->G[V][i];
                }
            }
        }
        return totalWeight;
    }
};
#endif //LEETCODE_1584_H
