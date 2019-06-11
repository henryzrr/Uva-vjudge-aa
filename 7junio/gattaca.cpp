#include<cstdio>
#include<map>
#include<unordered_map>
#include<cstring>
#include<string>

using namespace std;
int cases,i,j,tam,k,tammax,maxim,umint;
char cad[1005];
map<string,int>resp;
map<string,int>::iterator it;
unordered_map<string,int>visitado;
string aux;

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%s",cad);
        tam = strlen(cad)-1;
        for(i=0;i<tam;i++){
            k=i;
            j=i+1;
            aux="";
            while(j<=tam){
                if(cad[k]==cad[j]){
                    aux=aux+cad[j];
                    k++;
                    j++;
                }else if(k!=i){
                    it = resp.find(aux);
                    if(it==resp.end()){
                        resp[aux]=2;
                        visitado[aux]=i;    
                    }else{
                        umint=visitado[aux];
                        if(umint==i)
                        resp[aux]=it->second+1;
                    }
                    j=j-(k-i)+1;
                    k=i;
                    aux="";
                }else j++;
            }
            if(k!=i){
                it = resp.find(aux);
                if(it==resp.end())resp[aux]=2;
                else{
                    umint=visitado[aux];
                    if(umint==i)resp[aux]=it->second+1;
                } 
            }

        }
        tammax=0;
        for(auto&x:resp){
            tam = x.first.size();
            if(tam>tammax){
                tammax=tam;
                aux=x.first;
                maxim=x.second;
            }
        }
        if(tammax==0)puts("No repetitions found!");
        else{
            printf("%s %i\n",aux.c_str(),maxim);
        }
        resp.clear();
        visitado.clear();
    }
    return 0;
}