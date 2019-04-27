#include<cstdio>
#include<algorithm>

using namespace std;
typedef struct elephants{
    int peso;
    int iq;
    int pos;
}elephants;

elephants ls[1000];
int nroElem[1000],punteros[1000],posmax,aux,posaux,sumaux;
bool comparador(elephants a, elephants b){
    return a.peso<b.peso;
}
int main(){
    int i=0;
    while(scanf("%i %i",&ls[i].peso,&ls[i].iq)!=EOF){
        ls[i].pos = i;
        i++;
    } 
    sort(ls,ls+i,comparador);
    //for(auto&x:ls) printf("%i %i\n",x.peso,x.iq);
    int lim = i-1;
    int max=0;
    for(int j=lim;j>=0;j--){
        aux = 1;
        posaux = j;
        for(int k=j;k<=lim;k++){
            if(ls[j].peso == ls[k].peso) continue;
            else if(ls[j].iq>ls[k].iq){
                sumaux = 1+nroElem[k];
                if(sumaux>aux){
                    aux = sumaux;
                    posaux = k;
                }
            }
        }
        nroElem[j]=aux;
        punteros[j]= posaux;
        if(aux>max){
            max= aux;
            posmax = j;
        }
    }
    printf("%i\n",max);
    int j = posmax;
    printf("%i\n",ls[posmax].pos+1);
    while(punteros[j]!=j){
        printf("%i\n",ls[punteros[j]].pos+1);
        j = punteros[j];
    }
    return 0;
}