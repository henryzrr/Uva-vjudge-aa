#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
int cases,buldings,roads,a,b,ini,fin,grafo[100][100],cont=1,resp,aux;
//static const int maxv = 100000;

void iniciarGrafo(){
    for (int i=0;i<buldings;i++){
        for(int j=0;j<buldings;j++){
            grafo[i][j]=1000;
        }
        grafo[i][i]=0;
    } 
}
void floydwarshall(){
    for(int k=0;k<buldings;k++){
        for(int i=0;i<buldings;i++){
            for(int j=0;j<buldings;j++){
                if(j==i) continue;
                aux = grafo[i][k]+grafo[k][j];
                grafo[i][j]=aux<grafo[i][j]?aux:grafo[i][j];
            }
        }
    }
}
int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i %i",&buldings,&roads);
        iniciarGrafo();
        while(roads--){
            scanf("%i %i",&a,&b);
            grafo[a][b]=grafo[b][a]=1;
        }
        scanf("%i %i",&ini,&fin);
        floydwarshall();
        resp=0;
        aux=0;

        for(int i=0;i<buldings;i++){
            if(grafo[ini][i]>aux){
                aux=grafo[ini][i];
                resp=grafo[i][fin]+aux;
            }else if(grafo[ini][i]==aux){
                resp=resp<grafo[i][fin]+grafo[ini][i]?grafo[i][fin]+grafo[ini][i]:resp;
            }
        }
        printf("Case %i: %i\n",cont,resp);
        cont++;
    }
    return 0;
}