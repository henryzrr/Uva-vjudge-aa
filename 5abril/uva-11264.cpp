#include<stdio.h>
using namespace std;

int main(){
    int cases,nroCoins;
    scanf("%i",&cases);
    while(cases){
        scanf("%i",&nroCoins);
        int res=0,aux=0,lsCoin[nroCoins],lastv;
        for(int i=0;i<nroCoins;i++){
            scanf("%i",&lsCoin[i]);
        }
        for(int i=0;i<nroCoins;i++){
            if(lsCoin[i]>aux){
                res++;
                lastv = aux;
                aux +=lsCoin[i];
            }else{
                aux = lastv+lsCoin[i];
            }
        }
        printf("%i\n",res);
        cases--;
    }
    return 0;
}