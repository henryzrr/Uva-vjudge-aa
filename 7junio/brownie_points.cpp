#include<cstdio>

using namespace std;
int puntos,i,j,x[200000],y[200000],ollie,stan,medio;
int main(){
    while(scanf("%i",&puntos)&puntos!=0){
        for(i=0;i<puntos;i++)
            scanf("%i %i",&x[i],&y[i]);
        medio = puntos/2;
        stan=0;
        ollie=0;
        for(i=0;i<puntos;i++){
            if(x[i]>x[medio]&&y[i]>y[medio])stan++;
            else if((x[i]<x[medio]&&y[i]<y[medio]))stan++;
            else if(x[i]>x[medio]&&y[i]<y[medio])ollie++;
            else if (x[i]<x[medio]&&y[i]>y[medio]) ollie++;
        }
        printf("%i %i\n",stan,ollie);
    }
}