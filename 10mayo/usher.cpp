#include<cstdio>
#define min(x,y) x>y?y:x

using namespace std;
int cases,feligreses,rataComp,i,j,k,compfeligreses,a,b;
long monto,grafo[501][501],auxmonto,mini;

void iniciarGrafo(){
    for(i=0;i<=feligreses;i++){
        for(j=0;j<=feligreses;j++){
            grafo[i][j]=20000000000;
        }
        grafo[i][i]=0;
    }
}

void floyd_warshall(){
    for(k=0;k<=feligreses;k++){
        for(i=0;i<=feligreses;i++){
            for(j=0;j<=feligreses;j++){
                grafo[i][j]=min(grafo[i][j],grafo[i][k]+grafo[k][j]);
            }
        }
    }
}

int main(){
    
    scanf("%i",&cases); 
    while(cases--){
        
        scanf("%li %i %i",&monto,&feligreses,&rataComp);
        iniciarGrafo();
        for(i=0;i<rataComp;i++){
            scanf("%i",&b);
            grafo[0][b]=0;
        }
        for(i=1;i<=feligreses;i++){
            scanf("%i",&compfeligreses);
            while(compfeligreses--){
                scanf("%li %i",&auxmonto,&b);
                grafo[i][b]=auxmonto<grafo[i][b]?auxmonto:grafo[i][b];
        
            }
        }
      
        floyd_warshall();
        mini=20000000000;
        
        for(i=1;i<=feligreses;i++){
            if(grafo[0][i]!=0)continue;
            mini = grafo[i][0]<mini?grafo[i][0]:mini;
        }
        auxmonto=0;
        i=0;
        while(true){
            auxmonto+=mini;
            if(auxmonto>=monto) break;
            i++;
            auxmonto--;
        }
        printf("%i\n",i);
    }
    return 0;
}
