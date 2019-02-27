#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<regex>
#include<set>
#include<map>
#include<queue>
using namespace std;
struct edge{
    int weight=0;
    string _begin;
    int _nBegin;
    string _end;
    int _nEnd;
}*edges;

int call_count,threthold;
int people_count;
map<string,int> m;
map<int,string> m2;
int** adj;

int *weight_m;
bool *vis;
bool *vis_e;
void dfs(int i2,int& weight)
{
    for(int i=0;i<call_count;i++){
        if(!vis_e[i]&&i2==edges[i]._nBegin){
            vis_e[i]=true;
            weight_m[edges[i]._nBegin]+=edges[i].weight;
            weight+=edges[i].weight;
            weight_m[edges[i]._nEnd]+=edges[i].weight;
            vis[edges[i]._nEnd]=true;
            dfs(edges[i]._nEnd,weight);
        }
        if(!vis_e[i]&&i2==edges[i]._nEnd){
            vis_e[i]=true;
            weight_m[edges[i]._nBegin]+=edges[i].weight;
            weight+=edges[i].weight;
            weight_m[edges[i]._nEnd]+=edges[i].weight;
            vis[edges[i]._nBegin]=true;
            dfs(edges[i]._nBegin,weight);
        }
    }
}

struct node{
    int _count;
    string leader;
};
vector<node> res;
bool cmp(const node&a,const node&b){
    return a.leader<b.leader;
}
int main()
{
    freopen("data.txt","r",stdin);
    cin>>call_count>>threthold;
    edges=new edge[call_count];
    set<string> s;
    for(int i=0;i<call_count;i++){
        string s1,s2;int c;
        cin>>s1>>s2>>c;
        if(s.find(s1)==s.end())s.insert(s1);
        if(s.find(s2)==s.end())s.insert(s2);
        edges[i]._begin=s1;
        edges[i]._end=s2;
        edges[i].weight=c;
    }
    people_count=s.size();
    vis=new bool[people_count];
    memset(vis,0,sizeof(bool)*people_count);
    weight_m=new int[people_count];
    vis_e=new bool[call_count];
    memset(vis_e,0,sizeof(bool)*people_count);

    int i1=0;
    for(auto &it:s){
        m[it]=i1;
        m2[i1]=it;
        i1++;
    }

    for(int i=0;i<call_count;i++){
        edges[i]._nBegin=m[edges[i]._begin];
        edges[i]._nEnd=m[edges[i]._end];
    }

    for(int i=0;i<people_count;i++){
        if(!vis[i]){
            memset(weight_m,0,sizeof(int)*people_count);
            vis[i]=true;
            int w=0;
            dfs(i,w);
            if(w<=threthold) continue;
            int _min1=0,_min2=0,j=0;
            for(int k=0;k<people_count;k++){
                if(weight_m[k]!=0)j++;
                if(weight_m[k]>_min2) {
                        _min2=weight_m[k];
                        _min1=k;
                }
            }
            if(j<=2) continue;
            node n;
            n.leader=m2[_min1];
            n._count=j;
            res.push_back(n);
        }
    }
    if(res.size()==0){
        printf("0");return 0;
    }
    sort(res.begin(),res.end(),cmp);
    printf("%d\n",res.size());
    for(auto &it:res){
        printf("%s %d\n",it.leader.c_str(),it._count);
    }
    return 0;
}
