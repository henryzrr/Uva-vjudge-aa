#include<cstdio>
#include<unordered_set>
#include<cmath>
using namespace std;
typedef struct nodo{
    int i;
    int j;
}nodo;

int cases,posi,posj,tami,tamj,auxi,auxj,grafo[20][20],nroVertices,res;
nodo auxls[20];
void setValues(){
    int aux;
    for(int i=0;i<=nroVertices-1;i++){
        for(int j=i+1;j<=nroVertices;j++){
            aux = abs(auxls[i].i-auxls[j].i)+abs(auxls[i].j-auxls[j].j);
            grafo[i][j]=grafo[j][i]=aux;
        }
    }
}
int findMinPath(unordered_set<int> lsant,int nodo,int tamset){
    if(tamset==nroVertices) return grafo[nodo][0];
    int max = 100000;
    unordered_set<int>newus (lsant.begin(),lsant.end());
    newus.insert(nodo);
    for(int i=0;i<=nroVertices;i++){
        if(i==nodo) continue;
        auto x = lsant.find(i);
        if(x==lsant.end()){
            int auxmax = grafo[nodo][i]+findMinPath(newus,i,tamset+1);
            max = auxmax<max?auxmax:max;
        }
    }
    return max;
}

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i %i %i %i %i",&tami,&tamj,&posi,&posj,&nroVertices);
        auxls[0].i=posi;
        auxls[0].j=posj;
        for(int i=1;i<=nroVertices;i++){
            scanf("%i %i",&auxls[i].i,&auxls[i].j);
        }
        setValues();
        unordered_set<int> auxset;
        res = findMinPath(auxset,0,0);
        printf("The shortest path has length %i\n",res);
    }
    return 0;
}