#include<cstdio>
#include<string>
#include<unordered_set>
#include<cstring>
#include<vector>

using namespace std;
unordered_set<string>diccionario;
unordered_set<string>::iterator it;
vector<string>resp;
char cad[25],auxchar, texto[260];
string aux;
int i,j,tam,arr[260],arr2[260],auxcont,kres,cont;

int main(){
    while(scanf("%s",cad)&&cad[0]!='#'){
        diccionario.insert(cad);
    }
    fgets(texto,255,stdin);
    fgets(texto,255,stdin);
    tam = strlen(texto)-1;
    for(i=0;i<tam;i++){
        texto[i]= texto[i]==' '?'@':texto[i];
        arr[i]=texto[i]-64;
    }
    cont=0;
    for(i=1;i<=26;i++){
        for(j=0;j<tam;j++){
            arr2[j]=(arr[j]+i)%27;
        }
        aux="";
        auxcont=0;
        for(j=0;j<tam;j++){
            if(arr2[j]>0){
                auxchar=arr2[j]+64;
                aux=aux+auxchar;
            }else{
                it = diccionario.find(aux);
                if(it!=diccionario.end())auxcont++;
                aux="";               
            }
        }
        if(auxcont>cont){
            cont=auxcont;
            kres=i;
        }   
    }
    aux="";
    for(j=0;j<tam;j++){
        auxchar =char(((arr[j]+kres)%27)+64);
        if(auxchar=='@'){
            resp.push_back(aux);
            resp.push_back(" ");
            aux="";
        }else{
            aux = aux+auxchar;
        }
    }
    if(aux.size()>0)resp.push_back(aux);
    aux="";
    tam=resp.size();
    cont=0;
    for(i=0;i<tam;i++){
        auxcont = resp[i].size();
        if(auxcont+cont>60){
            if(aux[cont-1]==' ')aux[cont-1]='\0';
            printf("%s\n",aux.c_str());
            if(resp[i][0]!=' '){
                aux=""+resp[i];
                cont=auxcont;
            }else{
                aux="";
                cont=0;
            }
            
        }else{
            aux=aux+resp[i];
            cont+=auxcont;
        }
    }
    if(aux[cont-1]==' ')aux[cont-1]='\0';
    printf("%s\n",aux.c_str());

    return 0;
}