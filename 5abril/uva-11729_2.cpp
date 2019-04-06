#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int cases, cont=1;
    while(scanf("%i",&cases)&&cases){
        int ls[cases][2];
        int mayor=0;
        int posMayor=0;
        int tmayor =0;
        for(int i=0;i<cases;i++){
            scanf("%i %i",&ls[i][0],&ls[i][1]);
            if(ls[i][1]>mayor){
                mayor = ls[i][1];
                posMayor =i;
                tmayor = ls[i][0];

            }
        }
        int ant =tmayor,tf=0;
        for(int i=0;i<cases;i++){
            if(posMayor!=i){
                int aux = ls[i][0]+ant+ls[i][1];
                if(tf<aux) tf=aux;
                ant+=ls[i][0];
            }
            
        }
        printf("Case %i: %i\n",cont,tf);
        cont++;
    }
    return 0;
}