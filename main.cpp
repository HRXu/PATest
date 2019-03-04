#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<regex>
#define FOR(i,a,b) for( int i=(a);i<(b);++i)
using namespace std;
struct num{
    char* real;
    int ex;
};
int length;
num* treat(string s){
    regex p1("[0-9]+$");
    regex p2("[0-9]+\\.[0-9]+$");
    regex p3("\\.[0-9]+$");
    int len=s.length();
    num* n=new num();
    if(regex_match(s,p1)){
        int pos1=0;
        for(int i=0;i<len;i++){
            if(s[i]!='0'){
                pos1=i;break;
            }
        }
        n->ex=len-pos1;
        n->real=new char[length];
        memset(n->real,'0',sizeof(char)*length);
        for(int j=pos1,i=0;i<length&&j<len;j++){
            n->real[i]=s[j];
            i++;
        }
    }
    else {
        int pos1=0,pos2=0;bool flag=false;
        for(int i=0;i<len;i++){
            if(s[i]!='0'&&s[i]!='.'&&!flag){pos1=i;flag=true;}
            else if(s[i]=='.'){pos2=i;}
        }
        if(pos2>pos1)n->ex=pos2-pos1;
        else n->ex=pos2-pos1+1;

        n->real=new char[length];
        memset(n->real,'0',sizeof(char)*length);
        for(int j=pos1,i=0;i<length&&j<len;j++){
            if(s[j]=='.')continue;
            n->real[i]=s[j];
            i++;
        }
    }
    return n;
};

int main()
{
	freopen("data.txt","r",stdin);
    string s1,s2;
	cin>>length>>s1>>s2;
    num* n1=treat(s1);
    num* n2=treat(s2);

    bool res=true;
    if(n1->ex==n2->ex){
        for(int i=0;i<length;i++){
            if(n1->real[i]!=n2->real[i]){
                res=false;
                break;
            }
        }
    }
    else{
        res= false;
    }

    if(res){
        printf("YES 0.",n1->real,n1->ex);
        for(int i=0;i<length;i++){
                printf("%c",n1->real[i]);
        }
        printf("*10^%d",n1->ex);
    }
    else{
        printf("NO 0.%s*10^%d",n1->real,n1->ex);
        for(int i=0;i<length;i++){
                printf("%c",n1->real[i]);
        }
        printf("*10^%d 0.",n1->ex);
        for(int i=0;i<length;i++){
                printf("%c",n2->real[i]);
        }
        printf("*10^%d",n2->ex);
    }
	return 0;
}


