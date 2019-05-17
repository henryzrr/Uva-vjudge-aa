#include<cstdio>
#include<queue>
#include<vector>
#include<set>

using namespace std;
int tam,grafo[100][100],cases,i,j,cont=1,aux,k,tamaux;
bool dominator[100][100],espadre;
vector<vector<int>> padres;
vector<set<int>>hijos;
set<int>::iterator it;
queue<int>cola;

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i",&tam);
        padres.reserve(tam);
        hijos.reserve(tam);
        
        for(i=0;i<tam;i++){
            set<int>auxset;
            auxset.insert(i);
            for(j=0;j<tam;j++){
                scanf("%i",&aux);
                if(aux==1){
                    padres[j].push_back(i);
                    auxset.insert(j);
                } 
                dominator[i][j]=false;
            }
            hijos[i]=auxset;
        }

    
        for(i=0;i<tam;i++){
            bool visitado[tam]={false};
            for(auto&x:hijos[i]){
                cola.push(x); 
                visitado[x]=true;;
            }
            dominator[i][i]=true;
            visitado[i]=true;
            while(!cola.empty()){
                aux=cola.front();
                cola.pop();
                espadre=true;
                for(auto& x:padres[aux]){
                    it = hijos[i].find(x);
                    espadre = it!=hijos[i].end()?true:false;
                    if(!espadre)break;
                }
                if(!espadre)continue;
                dominator[i][aux]=true;
                hijos[i].insert(aux);
                for(auto&x:hijos[aux]){
                    if(!visitado[x] ){
                        cola.push(x);
                        visitado[x]=true;
                    } 
                }
            }
        }
        printf("Case %i:\n",cont);
        aux=2*tam;
        printf("+");
        for(i=1;i<aux;i++)printf("-");
        printf("+\n");

        for(i=0;i<tam;i++){
            printf("|");
            k=0;
            for(j=1;j<=aux;j++){
                if(j&1){
                    printf("%s",dominator[i][k]?"Y":"N");
                    k++;
                }else printf("|");
            }
            printf("\n+");
            for(k=1;k<aux;k++)printf("-");
            printf("+\n");
        }
        padres.clear();
        hijos.clear();
        cont++;
    }    
    return 0;
}