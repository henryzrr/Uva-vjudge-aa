#include<stdio.h>
#include<algorithm>

using namespace std;
typedef struct soldado{
    int t1;
    int t2;
}soldado;
bool comparador(soldado a, soldado b){
    return (b.t2)<(a.t2);
}
int main(){
    int cases, cont=1;
    while(scanf("%i",&cases)&&cases){
        soldado lss[cases];
        for(int i=0;i<cases;i++){
            soldado aux;
            scanf("%i %i",&aux.t1,&aux.t2);
            lss[i]=aux;    
        }
        sort(lss,lss+cases,comparador);
        int ant =0,tf=0;
        for(int i=0;i<cases;i++){
            int aux = lss[i].t1+ant+lss[i].t2;
            if(tf<aux) tf=aux;
            ant+=lss[i].t1;
        }
        printf("Case %i: %i\n",cont,tf);
        cont++;
    }
    return 0;
}