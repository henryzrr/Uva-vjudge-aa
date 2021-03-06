#include<cstdio>
#include<cmath>
#include<map>
#include<ctime>

using namespace std;
unsigned long cortes[21],res,n,tam,aux;
map<unsigned long, map<unsigned long,unsigned long>> saved;
map<unsigned long,unsigned long>::iterator it;
clock_t ti,tf;
void llenarcortes(){
    for(int i=0;i<21;i++){
        cortes[i]=pow(i+1,3);
    }
}
unsigned long getWaystoPay(unsigned long saldo,int pos){

    unsigned long saldorest,i=0,corte=0,cont=0;
    while(corte<=saldo){
        saldorest = saldo-corte;
        if(pos-1>1){
            it = (saved[cortes[pos-1]]).find(saldorest);
            if(it!=(saved[cortes[pos-1]]).end()) cont +=it->second;
            else{
                aux = getWaystoPay(saldorest,pos-1);
                cont+=aux;
                (saved[cortes[pos-1]])[saldorest] = aux;
            }
        
        }else cont +=(saldorest/8)+1;
        i++;
        corte = i*cortes[pos];
    }
    return cont;
}
int main(){
    llenarcortes();
    while(scanf("%lu",&n)!=EOF){
        ti=clock();
        aux = round(pow(n,(double)1/3));
        aux = aux>21?21:aux;
        printf("%lu\n",n<8?1:getWaystoPay(n,n<27?aux:aux-1));
        tf=clock();
        printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    }
    return 0;
}