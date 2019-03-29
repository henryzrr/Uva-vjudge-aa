#include<stdio.h>

int main(){
    int a,i,j,k;
    scanf("%i",&a);
    if(a==1){
        puts("1");
    }else{

    }
    int ls[a][5];
    for(i=0;i<a;i++){
        scanf("%i %i %i %i %i",&ls[i][0],&ls[i][1],&ls[i][2],&ls[i][3],&ls[i][4]);
        for(j=0;j<4;j++){
            for(k=j+1;k<5;k++){
                if(ls[j]>ls[k]){
                    int aux = ls[j];
                    ls[j]=ls[k];
                    ls[k]=aux;
                }
            }
        }
        for()
    }
    return 0;
}