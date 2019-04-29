#include<cstdio>
#include<cmath>
#include<unordered_map>


using namespace std;
unsigned long cortes[21],res,n,tam,aux;
unordered_map<unsigned long, unordered_map<unsigned long,unsigned long>> saved;
unordered_map<unsigned long,unsigned long>::iterator it;

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
        aux = round(pow(n,(double)1/3));
        aux = aux>21?21:aux;
        printf("%lu\n",n<8?1:getWaystoPay(n,n<27?aux:aux-1));
    }
    return 0;
}