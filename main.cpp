#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<regex>
#define FOR(i,a,b) for( int i=(a);i<(b);++i)
#define MEMSET(arr,value,type,length) memset(arr,value,sizeof(type)*length)
#define MEMSET_0(arr,type,length) MEMSET(arr,0,type,length)
#define MEMSET_MIN(arr,type,length) MEMSET(arr,-0x3f,type,length)
#define MEMSET_MAX(arr,type,length) MEMSET(arr,0x3f,type,length)
#define READ_INT(i) int i;scanf("%d",&i)
using namespace std;
int *arr;
int *res;
int length;

bool check(int wolf1,int wolf2){
    FOR(i,1,length+1){
        if(i==wolf1||i==wolf2){
            res[i]=-1;
        }
        else{
            res[i]=1;
        }
    }

    int lier_v=0;
    int lier_w=0;
    FOR(i,1,length+1){
        if(res[i]==1){
            if(arr[i]>0&&res[arr[i]]==1)continue;
            if(arr[i]<0&&res[-arr[i]]==-1)continue;
            lier_v++;
        }
        else{
            if(arr[i]>0&&res[arr[i]]==1)continue;
            if(arr[i]<0&&res[-arr[i]]==-1)continue;
            lier_w++;
        }
    }
    return lier_v==1&&lier_w==1;
}

int main()
{
    freopen("data.txt","r",stdin);
    cin>>length;
    arr=new int[length+1];
    res=new int[length+1];

    FOR(i,1,length+1){
        cin>>arr[i];
    }
    for(int i=1;i<=length-1;i++){
        for(int j=i+1;j<=length;j++){
            if(check(i,j)){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");
	return 0;
}







