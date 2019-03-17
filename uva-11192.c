#include<stdio.h>
#include<string.h>
int main(){
    char ls[100],lsres[100];
    int ini,size,fin,n,j,i,s;
    while(scanf("%i",&n)!=EOF){
        if(n==0) break;
        scanf("%s",ls);
        ini =-1;
        size = strlen(ls);
        i=0;
        s = size/n;
        for(fin=s-1;fin<size;fin+=s){
            for(j=fin;j>ini;j--){
                lsres[i]=ls[j];
                i++;
            }
            ini=fin;
        }
        lsres[i]='\0';
        printf("%s\n",lsres);
    }
    return 0;
}