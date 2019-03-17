#include<stdio.h>
#include<string.h>


int main(){
    char ls[1001];
    int cases=1;
    while(scanf("%s",ls)!=EOF){
        if(strcmp(ls,"end")==0)break;
        int i,size=strlen(ls),pila=0;
        char p[size];
        for(i=0;i<size;i++){
            int j=0;
            while(j<pila){
                if(ls[i]<=p[j]){ 
                    p[j]=ls[i];
                    break;
                }
                j++;
            }
            if(j==pila){
                p[pila]=ls[i];
                pila++;
            }
        }
        printf("Case %i: %i\n",cases,pila);
        cases++;
    }
    return 0;
}