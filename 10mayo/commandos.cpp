#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
int cases,buldings,roads,a,b,ini,fin,grafo[100][100],dist[100],gvisit[100],cont=1,resp;


void iniciarGrafo(){
    for (int i=0;i<buldings;i++){
        gvisit[i]=-1;
        dist[i]=0;
        for(int j=0;j<buldings;j++){
            grafo[i][j]=-1;
        }
    }
}
void resetDistancia(){
     for (int i=0;i<buldings;i++){
        gvisit[i]=-1;
        dist[i]=0;
    }    
}
void getDPS(){
    queue<int>cola;
    cola.push(ini);
    while(!cola.empty()){
        a = cola.front();
        gvisit[a]=1;
        cola.pop();
        for(int i=0;i<buldings;i++){
            if(grafo[a][i]==-1) continue;
            if(gvisit[i]==-1){
                cola.push(i);
                gvisit[i]=0;
                dist[i]=dist[a]+grafo[a][i];
            }else if(gvisit[i]==0 ){
                roads = dist[a]+grafo[a][i];
                if(roads<dist[i]){
                    dist[i]=roads;
                }
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
        getDPS();
        resp=0;
        vector<int>ind;
        for(int i=0;i<buldings;i++){
            if(i!=fin){
                if(dist[i]>resp){
                    ind.clear();
                    resp=dist[i];
                    ind.push_back(i);
                }else if(dist[i]==resp ) ind.push_back(i);
            }else ini=i;
        }
        ini=ind.size()==0?ini:ind[0]; 
        for(int i=0;i<ind.size();i++){
            if(grafo[ind[i]][fin]==-1 && ind[i]!=fin)ini=ind[i];
        } 
       
        resetDistancia();
        getDPS();
        resp +=dist[fin];
        printf("Case %i: %i\n",cont,resp);
        cont++;
    }
    return 0;
}