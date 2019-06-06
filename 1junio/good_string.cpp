#include<cstdio>

using namespace std;
char cad[105];
int i,j,cases,n,res;

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i %s",&n,cad);
        for(i=0;i<n;i++){
            if(cad[i]=='>'|| i==n-1)break;
        }
        for(j=n-1;j>=0;j--){
            if(cad[j]=='<' || j==0)break;
        }
        res = n-1-j;
        printf("%i\n",i<res?i:res);
    }
    return 0;
}