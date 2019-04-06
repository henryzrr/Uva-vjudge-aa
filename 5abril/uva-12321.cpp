#include<stdio.h>
#include<list>

using namespace std;

typedef struct segmento{
    int a;
    int b;
}segmento;

int main(){
    int lenRoad,nroGas,x,r,limi;
    list<segmento> lsSegmentos;
    while(scanf("%i %i",&lenRoad,&nroGas)&&lenRoad&&nroGas){
        limi = 0;
        for(int i=0;i<nroGas;i++){
            scanf("%i %i",&x,&r);
            segmento s;
            s.a = x-r;
            s.b = x+r;
            lsSegmentos.push_front(s);
        }
        int aux,res = 0,laux;
        while(!lsSegmentos.empty() && limi<lenRoad){
            aux=res;
            laux = limi;
            for(auto x = lsSegmentos.begin();x!=lsSegmentos.end();x++){
                if((*x).a<=limi && (*x).b>limi){
                    res++;
                    if((*x).b>laux) laux = (*x).b;                  
                    lsSegmentos.erase(x);
                    x--;
                }
            }
            limi=laux;
            if(aux==res){
                res =-1;
                break;
            }
            res--;
        }
        if(limi>=lenRoad)printf("%i\n",res+lsSegmentos.size());
        else puts("-1");
        lsSegmentos.clear();
    }
    return 0;
}