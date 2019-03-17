#include<stdio.h>

void cambiarLista2(int ls[][3]){

    ls[0][1]+=1;
    ls[0][2] =5;
}
/*void cambiarLista3(int*ls,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            printf("%i",*ls);
        }
        *ls+=1;
        ls++;
    } 
    puts("");
}*/
int main(){
    int ls[][3]={{1,2,3},{4,5,6}};
    cambiarLista2(ls);
    //cambiarLista3(ls);
    //int i;
    //for(i=0;i<7;i++) printf("%i",ls[i]);
    return 0;
}