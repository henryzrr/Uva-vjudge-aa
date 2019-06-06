#include<cstdio>

using namespace std;
int n,izq,der,i,aux;
char cad[300005];
bool correcto;

int main(){
    scanf("%i",&n);
    if(n&1)puts(":(");
    else{
        scanf("%s",cad);
        der=izq=0;
        for(i=0;i<n;i++){
            if(cad[i]=='(')izq++;
            else if(cad[i]==')')der++;
        }
        aux = n/2;
        if(izq>aux || der>aux) puts(":(");
        else{
            for(i=0;i<n;i++){
                if(cad[i]=='?'){
                    if(izq<aux){
                        cad[i]='(';
                        izq++;
                    }else cad[i]=')';
                }
            }
            izq=der=0;
            correcto=true;
            for(i=0;i<n;i++){
                if(cad[i]=='(')izq++;
                else der++;
                if(izq<=der && i<n-1){
                    correcto=false;
                    break;
                }
            }
            if(correcto) printf("%s\n",cad);
            else puts(":(");
        }
    }
    return 0;
}