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
#define READ_IN(i) int i;cin>>i
using namespace std;
int *arr;
int length;

stack<int> q;
//0 undecided
//1 min heap
//-1 max heap
//3 not heap
int status=0;


void display(stack<int> &qu){
    stack<int> d(qu);
    vector<int> tmp;
    while(d.size()!=0){
        tmp.push_back(d.top());
        d.pop();
    }
    int len=tmp.size();
    for(int i=len-1;i>=0;i--){
        if(i==0){
            printf("%d",tmp[i]);
        }
        else{
            printf("%d ",tmp[i]);
        }
    }
    printf("\n");
}


void change(int root,int lchild,int rchild){
    if(lchild>=length &&rchild>=length)
    {
        display(q);
    }
    else if(lchild>=length && rchild<length){
        if(status==0){
            if(arr[root]<arr[rchild]){status=1;}
            else status=-1;
        }
        else if(status==1){
            if(arr[root]>arr[rchild]){
                status=3;
            }
        }
        else if(status==-1){
            if(arr[root]<arr[rchild]){
                status=3;
            }
        }
    }
    else if(lchild<length && rchild>=length){
        if(status==0){
            if(arr[root]<arr[lchild]){status=1;}
            else status=-1;
        }
        else if(status==1){
            if(arr[root]>arr[lchild]){
                status=3;
            }
        }
        else if(status==-1){
            if(arr[root]<arr[lchild]){
                status=3;
            }
        }
    }
    else{
        if(status==0){
            if(arr[root]<arr[rchild] && arr[root]<arr[lchild]){status=1;}
            else if(arr[root]>arr[rchild] && arr[root]>arr[lchild]){status=-1;}
            else status=3;
        }
        else if(status==1){
            if(arr[root]>arr[rchild]||arr[root]>arr[lchild]){
                status=3;
            }
        }
        else if(status==-1){
            if(arr[root]<arr[rchild]||arr[root]<arr[lchild]){
                status=3;
            }
        }
    }

}


void dfs(int root){
    if(root>=length)return;
    q.push(arr[root]);

    int lchild=root*2+1;
    int rchild=root*2+2;

    change(root,lchild,rchild);

    dfs(rchild);
    dfs(lchild);


    q.pop();
    return;
}

int main()
{
    freopen("data.txt","r",stdin);
    cin>>length;
    arr=new int[length];
    FOR(i,0,length){
        cin>>arr[i];
    }
    dfs(0);
    switch (status){
    case 3:
        printf("Not Heap");
        break;
    case 1:
        printf("Min Heap");
        break;
    case -1:
        printf("Max Heap");
    }
	return 0;
}


