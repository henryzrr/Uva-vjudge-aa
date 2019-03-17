#include<stdio.h>
#include<string.h>
int main(){
    char ls[100000]={};
    while(scanf("%s",ls)!=EOF){
        int size = strlen(ls);
        int ntam = (size*2)+2;
        int ini=ntam-1,fin=ntam,i,flag=1,aux=0;
        char ls2[ntam];
        for(i=0;i<size;i++){
            if(ls[i]=='['){
                if(aux!=0){
                    int j,n=ini-aux,k=i-aux;
                    for(j=n+1;j<=ini;j++){
                        ls2[j]=ls[k];
                        k++;
                    }
                    ini=n; 
                }
                flag=0;
                aux=0;
            }else if(ls[i]==']'){
                if(aux!=0){
                    int j,n=ini-aux,k=i-aux;
                    for(j=n+1;j<=ini;j++){
                        ls2[j]=ls[k];
                        k++;
                    }
                    ini=n;
                    aux=0; 
                }
                flag=1;
            }else{
                if(flag){
                    ls2[fin]=ls[i];
                    fin++;
                }else{
                    aux +=1;
                }
            }
        }
        if(aux!=0){
            int j,n=ini-aux,k=i-aux;
            for(j=n+1;j<=ini;j++){
                ls2[j]=ls[k];
                k++;
            }
            ini=n; 
        }
        for(i=ini+1;i<fin;i++)printf("%c",ls2[i]);
        printf("\n");
    }
    return 0;
}