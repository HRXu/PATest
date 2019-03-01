#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
#include<map>
#include<unordered_map>
#include<regex>
#include<queue>
#include<set>
#define ll long long
using namespace std;

int* pos;
int main()
{
	freopen("data.txt", "r", stdin);
    int length;
    cin>>length;
    pos=new int[length];
    int _start=0;
    for(int i=0,j;i<length;i++){
        cin>>j;
        pos[j]=i;
    }

    int swap_count=0;
    int i=0;
    while(1){
        if(pos[0]==0){
            for(;i<length && pos[i]==i;i++);
            if(i==length) break;
            swap(pos[0],pos[i]);
            swap_count++;
        }
        else{
            swap(pos[0],pos[pos[0]]);
            swap_count++;
        }
    }
    cout<<swap_count;
	return 0;
}
