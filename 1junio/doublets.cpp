#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<queue>
#include<unordered_map>

using namespace std;
map<short int,vector<short int>>grafo;
unordered_map<string,short int> indice;
unordered_map<string,short int>::iterator it;
unordered_map<string,short int>::iterator it2;
char word[18],word2[18];
vector<string>diccionario;
vector<short int> tamDic;
vector<short int> distancia;
vector<short int> lsaux;
vector<bool>visitado;
vector<short int>padre;
short int tam,i,aux,j,k,tamaux,cont;
queue<short int> cola;
bool first=true;

int main(){
    diccionario.reserve(25143);
    tamDic.reserve(25143);
    distancia.reserve(25143);
    visitado.reserve(25143);
    padre.reserve(25143);
    tam=0;
    while(fgets(word,18,stdin)&&word[0]!='\n'){
        aux = strlen(word)-1;
        word[aux]='\0';
        diccionario[tam]=word;
        indice[word]=tam;
        tamDic[tam++]=aux;
    }
    tam--; 
    for(i=0;i<tam;i++){
        for(j=i;j<=tam;j++){
            if(tamDic[i]==tamDic[j]){
                cont=0;
                for(k=0;k<tamDic[i];k++){
                    if(diccionario[i][k]!=diccionario[j][k]){
                        cont++;
                        if(cont>1)break;
                    }
                }
                if(cont==1){
                    (grafo[i]).push_back(j);
                    (grafo[j]).push_back(i);
                }
            }
        }
    } 
    while(scanf("%s %s",word,word2)!=EOF){
        if(first)first=false;
        else puts("");
        it = indice.find(word2);
        it2 = indice.find(word);
        if(it!=indice.end() && it2!=indice.end()){
            aux=it->second;
            for(i=0;i<=tam;i++){
                visitado[i]=false;
                distancia[i]=0;
                padre[i]=-1;
            } 
            padre[aux]=aux;
            cola.push(aux);
            while(!cola.empty()){
                aux = cola.front();
                visitado[aux]=true;
                cola.pop();
                lsaux = grafo[aux];
                tamaux = lsaux.size();
                for(i=0;i<tamaux;i++){
                    if(distancia[lsaux[i]]==0 && !visitado[lsaux[i]]){
                        padre[lsaux[i]]=aux;
                        distancia[lsaux[i]]=1;
                        cola.push(lsaux[i]);
                    }else if(distancia[lsaux[i]]>distancia[aux]+1){
                        padre[lsaux[i]]=aux;
                        distancia[lsaux[i]]=distancia[aux]+1;
                    }
                    
                }
            }
            if(padre[it2->second]==-1){
                puts("No solution.");
            }else{
                aux = it2->second;
                while(padre[aux]!=aux){
                    printf("%s\n",diccionario[aux].c_str());
                    aux = padre[aux];
                }
                printf("%s\n",diccionario[aux].c_str());
            }
        } else{
            puts("No solution.");
            continue;
        }

    }
    return 0;
}