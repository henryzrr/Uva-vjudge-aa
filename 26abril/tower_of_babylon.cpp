#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
typedef struct ladrillo{
    int base1;
    int base2;
    int altura;
}ladrillo;
ladrillo ls[90];
int n,i,j,a,b,c,valmax[90],valm,auxmaxval,aux;

bool comparador(ladrillo la, ladrillo lb){
    return la.base1+la.base2>lb.base1+lb.base2;
}

int main(){
    i=1;
    while(scanf("%i",&n)&&n!=0){
        j=0;
        while(n--){
            scanf("%i %i %i",&a,&b,&c);
            ls[j].base1 = b;
            ls[j].base2 = c;
            ls[j].altura = a;
            ls[++j].base1 = c; 
            ls[j].base2 = a;
            ls[j].altura = b;
            ls[++j].base1 = a;  
            ls[j].base2 = b;
            ls[j].altura = c;
            j++;
        }
        sort(ls,ls+j,comparador);
        valm = 0;
        for(int k=j-1;k>=0;k--){
            auxmaxval = ls[k].altura;
            for(int l = k+1;l<j;l++){
                if((ls[l].base1<ls[k].base1 && ls[l].base2<ls[k].base2) || 
                    (ls[l].base1<ls[k].base2 && ls[l].base2<ls[k].base1)){
                        aux = ls[k].altura+valmax[l];
                        auxmaxval = aux>auxmaxval?aux:auxmaxval;
                }
            }
            valmax[k]=auxmaxval;
            if(auxmaxval>valm){
                valm = auxmaxval;
            }
        }
        printf("Case %i: maximum height = %i\n",i,valm);
        i++;
    }
    return 0;
}