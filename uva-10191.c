#include<stdio.h>
#include<stdlib.h>
int main(){
    int cases,day=0;
    char ls[300];
    int lsi[100][2];
    int i=0,j,aux,anterior,ultimo,resp;
    
    while(fgets(ls,300,stdin)!=NULL){
       
        if(cases==0){
            cases = atoi(ls);
            if(cases<1 || cases>100)cases=0;
            else day++;
            continue;
        }
        lsi[i][0]=((ls[1]-48)*60)+(((ls[3]-48)*10)+(ls[4]-48));
        lsi[i][1]=((ls[7]-48)*60)+(((ls[9]-48)*10)+(ls[10]-48));

        if(i+1==cases){
            for(j=0;j<i;j++){
                for(aux=j+1;aux<=i;aux++){
                    if(lsi[aux][0]<lsi[j][0]){
                        int lsaux[2];
                        lsaux[0] = lsi[j][0];
                        lsaux[1] = lsi[j][1];
                        lsi[j][0] = lsi[aux][0];
                        lsi[j][1] = lsi[aux][1];
                        lsi[aux][0] = lsaux[0];
                        lsi[aux][1] = lsaux[1];
                    }
                }

            }
            for(j=0;j<i;j++){
                for(aux=j+1;aux<=i;aux+=1){
                    if(lsi[aux][0]<=lsi[j][1] && lsi[aux][1]<=lsi[j][1]){
                        lsi[aux][0]=lsi[j][1];
                        lsi[aux][1]=lsi[j][1];
                    }else if(lsi[aux][0]<=lsi[j][1] && lsi[aux][1]>=lsi[j][1]){
                        lsi[aux][0]=lsi[j][1];
                    } 
                }
            }
           
            ultimo = 0;
            resp = 0;
            anterior = 0;
            for(j=0;j<cases;j++){
                aux=lsi[j][0]-anterior;
                if(aux>resp){
                    resp=aux;
                    ultimo = anterior;
                    
                }
                anterior = lsi[j][1];
                
            }
            aux=480-anterior;
            if(aux>resp){
                resp=aux;
                ultimo = anterior;
            }
            int horas = resp/60,minutos = resp%60;
            int aux2 = ultimo%60;
            if(horas>0)
                if(aux2>=10)
                    printf("Day #%i: the longest nap starts at %i:%i and will last for %i hours and %i minutes.\n",day,(ultimo/60)+10,ultimo%60,horas,minutos);
                else
                    printf("Day #%i: the longest nap starts at %i:0%i and will last for %i hours and %i minutes.\n",day,(ultimo/60)+10,ultimo%60,horas,minutos);
            else
                if(aux2>=10)
                    printf("Day #%i: the longest nap starts at %i:%i and will last for %i minutes.\n",day,(ultimo/60)+10,ultimo%60,minutos);
                else
                    printf("Day #%i: the longest nap starts at %i:0%i and will last for %i minutes.\n",day,(ultimo/60)+10,ultimo%60,minutos);
            cases=i=0;
            
        }else{
            i++;
        }
        
        
    }
    return 0;
}