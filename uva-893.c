#include<stdio.h>

int main(){
    int d,m,a,aux,mesA,anhoA;
    unsigned long dias;
    int meses [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(scanf("%lu %i %i %i",&dias,&d,&m,&a)!=EOF){
        if(dias==0 && d==0 && m==0 && a==0) break;
        if((a%4==0 && a%100!=0)||(a%4==0 && a%400==0))meses[1]=29;
        else meses[1]=28;
        dias +=d; 
        mesA = m-1;
        anhoA = a;
        aux = meses[mesA];
        while(dias>aux){
            if(mesA==11){ 
                mesA=0;
                anhoA +=1;
                aux +=31;
                if((anhoA%4==0 && anhoA%100!=0)||(anhoA%4==0 && anhoA%400==0))meses[1]=29;
                else meses[1]=28;
            }else{
                mesA+=1;
                aux +=meses[mesA];
            }
        }
        aux -=dias;
        int res = meses[mesA]-aux;
        printf("%i %i %i\n",res,mesA+1,anhoA);
    }
    return 0;
}