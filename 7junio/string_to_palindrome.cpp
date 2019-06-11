#include<cstdio>
#include<cstring>
#define menor(a,b) a<b?a:b

using namespace std;
char cad[1005],cad2[1005];
int cases,i,j,k,tam,aux,dp[1001][1001],cont=1;

void prepararcad(){
    i=0;
    for(j=tam-1;j>=0;j--){
        cad2[i++]=cad[j];
    }
}

void preparardp(){
    for(i=0;i<=tam;i++) dp[i][0]=dp[0][i]=i;
}

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%s",cad);
        tam = strlen(cad);
        prepararcad();
        preparardp();

        for(i=1;i<=tam;i++){
            for(j=1;j<=tam;j++){
                if(cad2[i-1]==cad[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+(menor(menor(dp[i][j-1],dp[i-1][j-1]),dp[i-1][j]));
            }
        }
        //cad2[aux]=cad1[aux]='\0';
        //printf("%s %s\n",cad1,cad2);
        printf("Case %i: %i\n",cont++,dp[tam][tam]/2);
        /*for(i=0;i<=aux;i++){
            for(j=0;j<=aux;j++){
                printf("%i ",dp[i][j]);        
            }
            puts("");
        }*/
    }
    return 0;
}