#include<stdio.h>
#include<stdlib.h>

int comparator (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}
int main(){
    int tcase,i,nro,pos;
    scanf("%i",&tcase);
    for(i=0;i<tcase;i++){
        scanf("%i %i",&nro,&pos);
        int ls[nro],lsaux[nro],ls2[nro*((nro/2)+2)],j,print=0,aux=0,fin=nro;
        for(j=0;j<nro;j++){
            scanf("%i",&ls[j]);
            ls2[j]=j;
            lsaux[j]=ls[j];
        }
        qsort(lsaux,nro,sizeof(int),comparator);
        j=0;
        while(!print){
            if(ls[ls2[j]]==lsaux[aux]){
                if(ls2[j]==pos){
                    print =1;
                }else{
                    aux++;
                }
            }else{
                ls2[fin]=ls2[j];
                fin++;
            }
            j++;
        }
        printf("%i\n",aux+1);
    }
    return 0;
}