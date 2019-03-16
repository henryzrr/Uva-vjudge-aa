#include<stdio.h>
int giveSecuence(unsigned long n);

int main(){
    unsigned long a,b,menor,mayor;
    while(scanf("%lu %lu",&a,&b)!=EOF){
        int respuesta=0;
        if(a>=b){
            mayor=a;
            menor=b;
        }else {
            mayor = b;
            menor=a;
        }

        while(menor<=mayor){
            int r=giveSecuence(menor);
            if(r>respuesta) respuesta=r;
            menor+=1;
        }

        printf("%d %d %d\n",a,b,respuesta);
    }
    return 0;
}
int giveSecuence(unsigned long n){
    int contador=1,i;
    while(n!=1){
        if(n%2!=0) n=(3*n) +1;
        else n=n/2;
        contador++;
    }
    return contador;
}