#include<stdio.h>
#include<stdlib.h>
int m;
int comparar(const void * a, const void *b){
    int n1=*(int*)a,n2=*(int*)b,res1,res2,aux;
    res1 = n1%m;
    res2 = n2%m;
    if(res1==res2){
        if(n1%2!=0 && n2%2==0){
            return -1;
        }else if(n1%2==0 && n2%2!=0){
            return 1;
        }else if(n1%2!=0 && n2%2!=0){
            if(n1>n2) return -1;
            else return 1;
        }else{
            if(n1>n2) return 1;
            else return -1;
        }
    }else{
        return (res1-res2);
    }
    
}
int main(){
    int n;
    
    while(scanf("%i %i",&n,&m)&& n &&m){
        int i;
        int ls[n];
        for(i=0;i<n;i++){
            scanf("%i",&ls[i]);
        }
        qsort(ls,n,sizeof(int),comparar);
        printf("%i %i\n",n,m);
        for(i=0;i<n;i++){
            printf("%i\n",ls[i]);
        }
        
    }
    printf("0 0\n");
    return 0;
}