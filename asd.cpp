#include<stdio.h>
#include<vector>
using namespace std;
int lszero[11];
int lsneg[11];
int lss[11]={0,1,0,2,0,1,3,1,2,0,1};

void updateFT(int pos,int val){
    while(pos<=10){
        lsneg[pos]+=val;
        pos +=pos&-pos;
    }
}
int getFrec(int n){
    int suma = 0;
    while(n>0){
        suma +=lsneg[n];
        n -=n&-n;
    }
    return suma;
}
int main(){
    
    for(int i=1;i<=10;i++){
        updateFT(i,lss[i]);
        
    }
    puts("neg");
        for(auto& x:lss){
            printf("%i ",x); 
        }
        puts("");
    
    int a = getFrec(1);
    int b = getFrec(7)-getFrec(5);
    int c = getFrec(1)-getFrec(0);

    printf("%i %i %i\n",a,b,c);
    /*updateFT(1,-1);
    puts("neg");
        for(auto& x:lsneg){
            printf("%i ",x); 
        }
        puts("");
        puts("zero");
        for(auto& x:lszero){
            printf("%i ",x);

        }
        puts("");*/

    return 0;
}