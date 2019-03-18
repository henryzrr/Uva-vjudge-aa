#include<stdio.h>

int main(){
    int b,p,m;
    while(scanf("%i %i %i",&b,&p,&m)!=EOF){ 
        int i=0,aux=p;
        int resp,resf=1,actual=b%m;
        while(aux>0){
            resp=aux%2;
    
            if(resp!=0){
                resf = (resf*actual)%m;
            }
            actual =(actual*actual)%m; 
            aux /=2;
            i++;
        }
        resf = resf%m;
        printf("%i\n",resf);
    }
    return 0;
}