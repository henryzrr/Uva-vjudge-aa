#include<stdio.h>
#include<stdlib.h>
int main(){
    int cases,day=1;
    char ls[256];
    char h[4]={0,0,0,0};
    char hr[4]={10,0,0,0};
    int hini=0,hfin,hres=0;
    
    while(fgets(ls,256,stdin)){
       
        if(cases==0){
            cases = atoi(ls);
            continue;
        }

        hfin = ((ls[1]-48)*60)+((ls[3]-48)*10)+(ls[4]-48);
        int aux = hfin - hini;
        
        if(aux>hres){
            hres=aux;
            if(hini!=0){
                hr[0]=h[0];
                hr[1]=h[1];
                hr[2]=h[2];
                hr[3]=h[3];
            }
        }

        h[0]=ls[6];
        h[1]=ls[7];
        h[2]=ls[9];
        h[3]=ls[10];
        hini = ((ls[7]-48)*60)+((ls[9]-48)*10)+(ls[10]-48);
        cases--;
        
        if(cases==0){
            int aux2 = 480 - hini;
            if(aux2>hres){
                 hres = aux2;
                 hr[0]=h[0];
                hr[1]=h[1];
                hr[2]=h[2];
                hr[3]=h[3];
            }
            int horas = hres/60,minutos = hres%60;
            if(horas>0)
                printf("Day #%i: the longest nap starts at %c%c:%c%c and will last for %i hours and %i minutes.\n",day,hr[0],hr[1],hr[2],hr[3],horas,minutos);
            else
                printf("Day #%i: the longest nap starts at %c%c:%c%c and will last for %i minutes.\n",day,hr[0],hr[1],hr[2],hr[3],minutos);
            day++;
            hres=0;
            hini=0;
        }
        
    }
    return 0;
}