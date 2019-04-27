#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
unsigned long cortes[21],res,n,tam,aux;
map<unsigned long, set<unsigned long>> saved;
map<unsigned long, set<unsigned long>>::iterator it;
void llenarcortes(){
    for(int i=0;i<21;i++){
        cortes[i]=pow(i+1,3);
    }
}
unsigned long getWaystoPay(int saldo,int pos,int cont){
    if(pos==0) return saldo;

    long saldorest,i,corte;
    while(corte<=saldorest){
        saldorest = saldo-corte;
        it = saved.find(saldorest);
        if(it!=saved.end()){
            
        } 
    }
}
int main(){
    llenarcortes();
    double lg3 = log10(3);
    while(scanf("%lu",&n)!=EOF){
        aux = (unsigned long)(log10(n)/lg3)
        printf("%lu\n",getWaystoPay(n,aux-1,0));
    }
    return 0;
}