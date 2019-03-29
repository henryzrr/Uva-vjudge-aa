#include<stdio.h>
#include<stdlib.h>
typedef struct persona{
    char nombre[16];
    int dia;
    int mes;
    int anho;
}persona;
int main(){
    int n,i;
    persona * p,*mayor,*menor;
    scanf("%i",&n);
    p=malloc(sizeof(persona)*n);

    for(i=0;i<n;i++){
        scanf("%s",p[i].nombre);
        scanf("%i %i %i",&p[i].dia,&p[i].mes,&p[i].anho);
  
        if(i==0){
            menor = &p[i];
            mayor=&p[i];
        }else{ 
            if(p[i].anho<mayor->anho){
                mayor = &p[i];
            }else if(p[i].anho==mayor->anho){
                if(p[i].mes<mayor->mes){
                    mayor = &p[i];
                }else if(p[i].mes==mayor->mes){
                    if(p[i].dia<mayor->dia){
                        mayor = &p[i];
                    }
                } 
                
            }
            if(p[i].anho>menor->anho){
                menor = &p[i];
            }else if(p[i].anho==menor->anho){
                if(p[i].mes>menor->mes){
                    menor = &p[i];
                }else if(p[i].mes==menor->mes){
                    if(p[i].dia>menor->dia){
                        menor = &p[i];  
                    }
                } 
            }
        }
    }
    printf("%s\n%s\n",menor->nombre,mayor->nombre);
    
    return 0;
}