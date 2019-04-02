#include<cstdio>
#include<vector>
using namespace std;
 int ls[100005];

void updateFT(int pos,int val,vector<int>*lss,int n){
    while(pos<=n){
        (*lss)[pos] +=val;
        pos += pos&-pos;
    }
}
int getProduct(int a,vector<int>* ls){
    int suma=0;
    while(a>0){
        suma +=(*ls)[a];
        a -= a&-a;
    }
    return suma;
}
int getProduct(int a, int b,vector<int> ls){
    int res=0;
    if(a==1) res=getProduct(b,&ls);
    else res=getProduct(b,&ls)-getProduct(a-1,&ls);
    return res;
}
int main(){
    int n,k,aux,aux2;
    char op;
    while(scanf("%d %d",&n,&k)!=EOF){
         vector <int>lsneg,lzero;
         lsneg.assign(n+1,0);
         lzero.assign(n+1,0);
        for(int i=1;i<=n;i++){
            scanf("%i",&ls[i]);
            if(ls[i]<0) updateFT(i,1,&lsneg,n);
            else if(ls[i]==0) updateFT(i,1,&lzero,n);
        }
        for(int i=0;i<k;i++){
            scanf("%c",&op);
            while(op!='P' && op !='C')scanf("%c",&op);
            scanf("%i %i",&aux,&aux2);
            switch(op){
                case 'C':
                    if(ls[aux]>=0 && aux2<0){
                        updateFT(aux,1,&lsneg,n);
                    }else if( ls[aux]<0 && aux2>=0){
                        updateFT(aux,1,&lsneg,n);
                    } 
                    if(ls[aux]!=0 && aux2==0){
                        updateFT(aux,1,&lzero,n);
                    }else if(aux2!=0 &&ls[aux]==0){
                        updateFT(aux,-1,&lzero,n);
                    }
                    
                    ls[aux]=aux2;
                    
                    break;
                case 'P':
                    
                    if(getProduct(aux,aux2,lzero)){
                        printf("0");
                    }else if(getProduct(aux,aux2,lsneg)%2==0){
                        printf("+");
                        
                    }else{
                        printf("-");
                    }
                
                    break;
            }
        }
        printf("\n");
        //lsneg.clear();
        //lzero.clear();
    }
    return 0;
}