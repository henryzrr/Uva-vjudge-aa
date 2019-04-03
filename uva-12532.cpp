#include<cstdio>
#include<vector>
using namespace std;
int ls[100005];
int lszeros[100005];
int lsnegs[100005];
int tam;
void resetLs(int n){
    for(int i=0;i<=n;i++){
        lszeros[i]=0;
        lsnegs[i]=0;
        tam=n;
    }
}
void updateFT(int pos,int val,int lss){
    int *aux=lss==0?lszeros:lsnegs;
    while(pos<=tam){
        aux[pos]+=val;
        pos +=pos&-pos;
    }
}
int consulta(int a,int lss){
    int *aux=lss==0?lszeros:lsnegs; 
    int suma=0;
    while(a){   
        suma += aux[a];
        a -=a&-a;
    }
    return suma;
}
int consulta(int a, int b, int lss){
    return a==1?consulta(b,lss):consulta(b,lss)-consulta(a-1,lss);
}
int main(){
    int n,k,aux,aux2;
    char op;
    while(scanf("%d %d",&n,&k)!=EOF){
        resetLs(n);
        for(int i=1;i<=n;i++){
            scanf("%i",&ls[i]);
            if(ls[i]<0) updateFT(i,1,-1);
            else if(ls[i]==0) updateFT(i,1,0);
        }
        
        for(int i=0;i<k;i++){
            scanf("%c",&op);
            while(op!='P' && op !='C')scanf("%c",&op);
            scanf("%i %i",&aux,&aux2);
            
            switch(op){
                case 'P':
                    if(consulta(aux,aux2,0)){
                        printf("0");
                    }else if(consulta(aux,aux2,-1)%2!=0){
                        printf("-");
                    }else{
                        printf("+");
                    }
                    break;
                case 'C':
                    if(aux2==0){
                        if(ls[aux]!=0){
                            updateFT(aux,1,0);
                            if(ls[aux]<0)updateFT(aux,-1,-1);
                        }
                    }else if(aux2>0){
                        if(ls[aux]==0) updateFT(aux,-1,0);
                        else if(ls[aux]<0) updateFT(aux,-1,-1);
                    }else{
                        if(ls[aux]>=0){
                            updateFT(aux,1,-1);
                            if(ls[aux]==0) updateFT(aux,-1,0);
                        }
                    }
                    ls[aux]=aux2;
                    break;
            }
        }
        
        printf("\n");
       
    }
    return 0;
}