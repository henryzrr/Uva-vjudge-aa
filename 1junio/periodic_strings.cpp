#include<cstdio>
#include<cstring>

using namespace std;
int cases,i,j,tamcad,k;
char cad[85];
bool encontrado,first=true;

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%s",cad);
        tamcad = strlen(cad);
        i=-1;
        encontrado = false;
        while(!encontrado){
            i++;
            k=0;
            for(j=i+1;j<tamcad;j++){
                if(cad[k]!=cad[j])break;
                k= k==i?0:k+1;
            }
            if(j==tamcad && k==0) encontrado=true;
        }
        if(first)first=false;
        else puts("");
        printf("%i\n",i+1);

    }
    return 0;
}