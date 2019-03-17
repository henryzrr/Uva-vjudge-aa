#include<stdio.h>
int main(){
    int cars;
    while(scanf("%i",&cars) &&cars){
        int pos[1000]={},c,p,i,flag=0;
        for(i=0;i<cars;i++){
            scanf("%i %i",&c,&p);
            int aux=i+p;
            if(aux>=cars || aux<0){
                flag =1;
                continue;
            }else if(pos[aux]){
                flag=1;
                continue;
            }else{
                pos[aux]=c;
            }
        }
        if(!flag){
            for(i=0;i<cars-1;i++) printf("%i ",pos[i]);
            printf("%i\n",pos[cars-1]);
        }else{
            printf("-1\n");
        }
        
    }
    return 0;
}