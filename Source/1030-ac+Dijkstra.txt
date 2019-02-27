#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<regex>
#include<set>
#include<queue>
using namespace std;

struct node{
    int dis=0x7fffffff;
    int pre=0x7fffffff;
    int cost=0x7fffffff;
}ls[500];
int adj[500][500];
int cost[500][500];
bool vis[500];

int city_count,edge_count,_st,_end;
int main()
{
    freopen("data.txt","r",stdin);
    cin>>city_count>>edge_count>>_st>>_end;

    memset(adj,7,sizeof(int)*500*500);
    memset(cost,7,sizeof(int)*500*500);
    for(int i=0;i<edge_count;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        adj[a][b]=adj[b][a]=c;
        adj[a][a]=adj[b][b]=0;
        cost[a][b]=cost[b][a]=d;
    }

    for(int i=0;i<500;i++){
        ls[i].dis=adj[_st][i];
        ls[i].cost=cost[_st][i];
        ls[i].pre=_st;
    }
    vis[_st]=true;
    ls[_st].pre=_st;
    ls[_st].cost=0;
    for(int i=0;i<500;i++){
        int _min=0x7fffffff;
        int n;
        for(int j=0;j<500;j++){
            if(!vis[j]&&ls[j].dis<_min){
                _min=ls[j].dis;
                n=j;
            }
        }
        vis[n]=true;
        for(int j=0;j<500;j++){
            if(!vis[j]){
                if(ls[j].dis>ls[n].dis+adj[n][j]){
                    ls[j].dis=ls[n].dis+adj[n][j];
                    ls[j].cost=ls[n].cost+cost[n][j];
                    ls[j].pre=n;
                }
                else if(ls[j].dis==ls[n].dis+adj[n][j]){
                    if(ls[j].cost>ls[n].cost+cost[n][j]){
                        ls[j].dis=ls[n].dis+adj[n][j];
                        ls[j].cost=ls[n].cost+cost[n][j];
                        ls[j].pre=n;
                    }
                }
            }
        }
    }

    vector<int> res;
    int i=_end;
    while(ls[i].pre!=i){
        res.push_back(i);
        i=ls[i].pre;
    }
    res.push_back(i);
    for(int i=res.size()-1;i>=0;i--){
        printf("%d ",res[i]);
    }
    printf("%d %d",ls[_end].dis,ls[_end].cost);
    return 0;
}
