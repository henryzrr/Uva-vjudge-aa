#include<cstdio>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;
int cases,j,k,aux;


int main(){
    scanf("%i",&cases);
    char trash[5];
    char pesos[150];
    int pesosint[20],i;
    fgets(trash,4,stdin);
    while(cases--){
        fgets(pesos,149,stdin);
        stringstream ss(pesos);
        string token;
        int sum =0;
        i=0;
        while(getline(ss,token,' ')){
            pesosint[i]=atoi(token.c_str());
            sum +=pesosint[i];
            i++;
        }
        if(sum&1){
            puts("NO");
            continue;
        }
        sum /=2;
        sort(pesosint,pesosint+i);
        int mres[i][sum+1];
        for(j=0;j<i;j++) mres[j][0]=0;
        for(k=1;k<=sum;k++){
            if(k<pesosint[0]) mres[0][k]=0;
            else mres[0][k]=pesosint[0];
        }
        for(j=1;j<i;j++){
            for(k=1;k<=sum;k++){
                if(k<pesosint[j]) mres[j][k]=mres[j-1][k];
                else{
                    aux = pesosint[j]+ mres[j-1][k-pesosint[j]];
                    mres[j][k]=aux>mres[j-1][k]?aux:mres[j-1][k];
                } 
            }
        }
        printf("%s\n",mres[i-1][sum]==sum?"YES":"NO");
    }

    return 0;
}