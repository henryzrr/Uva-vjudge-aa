#include<cstdio>
#include<vector>
using namespace std;

typedef struct arista{
    int a;
    int b;
    int p;
}arista;
vector<arista>grafo;
vector<int>distancia;
int i,j,vertices,vertini,aristas,sumaux,a,b,p;


int main(){
    scanf("%i %i %i",&vertices,&aristas,&vertini);
    grafo.reserve(aristas);
    distancia.assign(vertices,100000);
    distancia[vertini]=0;
    for(i=0;i<aristas;i++){
        arista ar;
        scanf("%i %i %i",&ar.a,&ar.b,&ar.p);
        grafo[i]=ar;
    } 
    for(i=0;i<vertices-1;i++){
        for(j=0;j<aristas;j++){
            sumaux = distancia[grafo[j].a]+grafo[j].p;
            if(sumaux<distancia[grafo[j].b])distancia[grafo[j].b]=sumaux;
        }
        puts("");
        for(j=0;j<vertices;j++){
            printf("V:%i %i\n",j,distancia[j]);
        }
    }
    /*for(i=0;i<vertices;i++){
        printf("V:%i %i\n",i,distancia[i]);
    }*/
    return 0;
}