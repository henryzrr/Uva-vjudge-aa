#include<stdio.h>

using namespace std;

int main(){
    int cases,nroCoins,coin;
    scanf("%i",&cases);
    while(cases){
        scanf("%i",&nroCoins);
        int res=0,aux=0;
        for(int i=0;i<nroCoins;i++){
            scanf("%i",&coin);
            if(coin>=aux){
                aux = coin;
                aux +=aux;
                res++;
            }
        }
        printf("%i\n",res);
        cases--;
    }
    return 0;
}