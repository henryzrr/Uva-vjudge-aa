#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<stack>

using namespace std;
int j,cases,personas,poleras,resp,nump,grafo[50][50],i,minim,tam,aux1,aux2,aux,tam1,tam2;
char talla1[5],talla2[5];
unordered_map<string,int>tallas;
unordered_map<int,int> padre;
bool encontrado,camino;

void settallas(){
    tallas["XXL"]=2;
    tallas["XL"]=3;
    tallas["L"]=4;
    tallas["M"]=5;
    tallas["S"]=6;
    tallas["XS"]=7;
}
void iniciargrafo(){
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            grafo[i][j]=0;
        }
    }
    aux = 8+personas;
    for(i=8;i<aux;i++) grafo[0][i]=1;
    for(i=2;i<8;i++) grafo[i][1]=nump;
    
}

int main(){
    scanf("%i",&cases);
    settallas();
    while(cases--){
        scanf("%i %i",&poleras,&personas);
        nump = poleras/6;
        iniciargrafo();
        for(i=0;i<personas;i++){
            scanf("%s %s",talla1,talla2);
            tam1 = tallas[talla1];
            tam2 = tallas[talla2];
            grafo[8+i][tam1]=1;
            grafo[8+i][tam2]=1;
        }
        resp=0;
        camino=false;
        while(!camino){
            stack<int>pila;
            pila.push(0);
            encontrado=false;
            minim=50000;
            padre.clear();
            padre[0]=0;
            while(!encontrado && !pila.empty()){
                aux1 = pila.top();
                pila.pop();
                if(aux1!=1){
                    for(i=0;i<8+personas;i++){
                        if(grafo[aux1][i]>0 && padre.find(i)==padre.end()){
                            padre[i]=aux1;
                            pila.push(i);
                            minim = minim<grafo[aux1][i]?minim:grafo[aux1][i];
                        }
                    }
                    
                }else{
                    encontrado =true;
                    aux1 = 1;
                    while(padre[aux1]!=aux1){
                        aux2 = padre[aux1];
                        aux = grafo[aux2][aux1]-minim;
                        grafo[aux2][aux1] = aux;
                        aux = grafo[aux1][aux2]+minim;
                        grafo[aux1][aux2] = aux;
                        aux1 = aux2;
                    }
                    resp +=minim;
                }
            }
            if(!encontrado)camino=true;        
        }
        if(resp==personas)puts("YES");
        else puts("NO");
    }
    return 0;
}