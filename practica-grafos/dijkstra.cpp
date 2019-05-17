#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct comparador{
    bool operator()(const int&a, const int& b ){
        return a>b;
    }
};

typedef struct arista{
    int a,b,p;
}arista;
vector<vector<arista>>grafo;
vector<int>distancia;
vector<int>visitado;
priority_queue<int,vector<int>,comparador>cola;
int i,j,aristas,vertices,ini,sum,aux,tam;
int main(){
    scanf("%i %i %i",&vertices,&aristas,&ini);
    grafo.reserve(vertices);
    distancia.assign(vertices,100000);
    visitado.assign(vertices,-1);
    distancia[ini]=0;
    
    for(i=0;i<aristas;i++){
        arista ar;
        scanf("%i %i %i",&ar.a,&ar.b,&ar.p);
        grafo[ar.a].push_back(ar);
    }

    cola.push(ini);
    while(!cola.empty()){
        aux = cola.top();
        visitado[aux]=1;
        cola.pop();
        tam = grafo[aux].size();
        for(i=0;i<tam;i++){
            if(visitado[grafo[aux][i].b]==-1){
                visitado[grafo[aux][i].b]==1;
                distancia[grafo[aux][i].b]=distancia[aux]+grafo[aux][i].p;
                cola.push(grafo[aux][i].b);
            }else{
                sum = distancia[aux]+grafo[aux][i].p;
                if(sum<distancia[grafo[aux][i].b])distancia[grafo[aux][i].b]=sum;
            }
        }
    }
    for(i=0;i<vertices;i++){
        printf("V:%i %i\n",i,distancia[i]);
    }
}