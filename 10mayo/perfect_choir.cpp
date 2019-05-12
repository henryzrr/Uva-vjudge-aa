#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;
int p,i,aux,sum;
vector<int>notas;
int main(){
    while(scanf("%i",&p)!=EOF){
        notas.reserve(p);
        sum=0;
        for(i=0;i<p;i++){
            scanf("%i",&aux);
            notas[i]=aux+100000;
            sum +=notas[i];
        }
        if(sum%p!=0)puts("-1");
        else{
            aux = sum/p;
            sum=0; 
            for(i=0;i<p;i++){
                sum+=abs(notas[i]-aux);
            }
            printf("%i\n",(sum/2)+1);
        }
        
    }

    return 0;
}