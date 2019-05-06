#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef struct lines{
    int a;
    int b;
    int p;
}lines;

int nroC,k,i,a,b,c,res;
vector<int>parent;
vector<int>rankk;
lines ls[100100];
bool first=true;


bool comparador(lines a,lines b){
    return a.p<b.p;
}

void iniParent(){
    parent.reserve(nroC+1);
    for(int j=1;j<=nroC;j++) parent[j]=j;
}

int findParent(int n){
    return parent[n]==n?n:(parent[n]=findParent(parent[n]));
}

void getMinimumConected(){
    res=0;
    for(int j=0;j<i;j++){
        a = findParent(ls[j].a);
        b = findParent(ls[j].b);
        if(a!=b){
            if(rankk[a]>rankk[b])parent[b]=a;
            else{
                parent[a]=b;
                if(rankk[a]==rankk[b]) rankk[b]++;
            } 
            res +=ls[j].p;
        }
    }
}

int main(){
    while(scanf("%i",&nroC)!=EOF){
        rankk.assign(nroC+1,0);
    
        iniParent();
        res=0;
        for(i=0;i<nroC-1;i++){
            scanf("%i %i %i",&ls[i].a,&ls[i].b,&ls[i].p);
            res +=ls[i].p;
        }
        scanf("%i",&k);
        while(k--){
            scanf("%i %i %i",&ls[i].a,&ls[i].b,&ls[i].p);
            i++;
        }
        scanf("%i",&k);
        while(k--){
            scanf("%i %i %i",&a,&b,&c);
        }
        sort(ls,ls+i,comparador);
        
        if(!first) puts("");
        printf("%i\n",res);
        getMinimumConected();
        printf("%i\n",res);
        if(first) first=false;
    }    
    return 0;
}