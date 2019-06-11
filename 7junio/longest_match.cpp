#include<string>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
char texto[1005],patron[1005];
vector<string>t,p,*puntero;
string aux;
int tam,i,j,tam2,dp[1000][1000],auxint,cont=1;

void separarCadena(char * arr, vector<string>*v){
    tam = strlen(arr);
    aux="";
    for(i=0;i<tam;i++){
        if(arr[i]>='a'&&arr[i]<='z' || arr[i]>='A'&& arr[i]<='Z' || 
            arr[i]>='0'&& arr[i]<='9')aux=aux+arr[i];
        else if(aux.size()>0){
            v->push_back(aux);
            aux="";
        }
    }
    if(aux.size()>0)v->push_back(aux);
}

void preparardp(){
    auxint = tam>tam2?tam:tam2;
    for(i=0;i<=auxint;i++)
        dp[0][i]=dp[i][0]=0;
}

int main(){
    while(fgets(texto,1002,stdin)){
        p.clear();
        t.clear();
        fgets(patron,1002,stdin);
        puntero=&t;
        separarCadena(texto,puntero);
        puntero=&p;
        separarCadena(patron,puntero);
        tam=t.size();
        tam2=p.size();
        
        if(tam2==0||tam==0){
            printf("%2i. Blank!\n",cont++);
            continue;
        }
        
        preparardp();

        for(i=1;i<=tam2;i++){
            for(j=1;j<=tam;j++){
                if(p[i-1].compare(t[j-1])==0)dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j];
            }
        }
        printf("%2i. Length of longest match: %i\n",cont++,dp[tam2][tam]);
    }
    return 0;
}