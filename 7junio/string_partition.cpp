#include<cstdio>
#include<cstring>
#define MAX_INT 2147483647
#define mayor(a,b) a>b?a:b
using namespace std;
int cases,i,j,tam;
char cad[205];
long dp[205],aux,aux2;

int main(){
    scanf("%i",&cases);
   // printf("%s\n",aux>MAX_INT?"true":"false");
    while(cases--){
        scanf("%s",cad);
        tam = strlen(cad);
        for(i=0;i<=tam;i++)dp[i]=0;

        for(i=0;i<tam;i++){
            if(cad[i]=='0'){
                dp[i+1]=mayor(dp[i],dp[i+1]);
                continue;
            }
            aux=0;
            for(j=i;j<tam;j++){
                aux = (aux*10) +cad[j]-'0';
                if(aux>MAX_INT)break;
                aux2 = aux+dp[i];
               // aux2 =aux2>MAX_INT?0:aux2;
                dp[j+1]=mayor(aux2,dp[j+1]);
            }
        }
        printf("%li\n",dp[tam]);
    }
    return 0;
}