#include<stdio.h>

int main(){
    int a,b;

    while(scanf("%i %i",&a,&b)&& (a || b)){
        int carries=0,aux=0;
        while(a>0 || b>0){
            aux = (((a%10) + (b%10)+aux)/10);
            if(aux>0) carries ++;
            a /=10;
            b /=10;
        }
        switch(carries){
            case 0:
                puts("No carry operation.");
                break;
            case 1:
                puts("1 carry operation.");
                break;
            default:
                printf("%i carry operations.\n",carries);
        }
    }
    
    return 0;
}