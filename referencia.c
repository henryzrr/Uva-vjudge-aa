#include<stdio.h>

void cambiarLista2(int*ls,int n){
    int i;
    for(i=0;i<n;i++){
        ls[i]+=1;
        //printf("%i",ls[i]);
    }
    //puts("");
}
void cambiarLista3(int ls[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%i",*ls);
        *ls+=1;
        ls++;
    } 
    puts("");
}
int main(){
    int ls[7]={1,2,3,4,5,6,7};
    cambiarLista2(ls,7);
    cambiarLista3(ls,7);
    int i;
    for(i=0;i<7;i++) printf("%i",ls[i]);
    return 0;
}