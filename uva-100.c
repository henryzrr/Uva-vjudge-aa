#include<stdio.h>
int giveSecuence(int n);

int main(){
    int a,b,res=0,menor,mayor;
    
    scanf("%d %d",&a,&b);

    if(a>=b){
        mayor=a;
        menor=b;
    }else {
        mayor = b;
        menor=a;
    }

    while(menor<=mayor){
        int r=giveSecuence(menor);
        if(r>res) res=r;
        menor+=1;
    }

    printf("%i %i %i",a,b,res);
    return 0;
}
int giveSecuence(int n){
    int cont=0,i;
    while(n!=1){
        if(n%2!=0) n=(3*n) +1;
        else n=n/2;
        cont++;
    }
    return cont+1;
}