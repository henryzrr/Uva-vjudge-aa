
#include<cstdio>
using namespace std;


int m,n,i,j,mini,k,resp,respaux,auxmin,auxmin2;

int main(){
    while(scanf("%i %i",&m,&n)&&m!=0&&n!=0){
        int ls[m][n],lssup[m][n],lsizq[m][n];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%i",&ls[i][j]);
            }
        }
        j=n-1;
        lssup[m-1][j] = ls[m-1][j]==1?0:1;
        lsizq[m-1][j] = ls[m-1][j]==1?0:1;
        for(i=m-2;i>=0;i--){
            lssup[i][j]=ls[i][j]==1?0:1+lssup[i+1][j];
            lsizq[i][j] = ls[i][j]==1?0:1;
        }
        
        i=m-1;
        for(j=n-2;j>=0;j--){
            lssup[i][j]=ls[i][j]==1?0:1;
            lsizq[i][j]=ls[i][j]==1?0:1+lsizq[i][j+1];
        }
        for(i=m-2;i>=0;i--){
            for(j=n-2;j>=0;j--){
                if(ls[i][j]==0){
                    lssup[i][j]=1+lssup[i+1][j];
                    lsizq[i][j]=1+lsizq[i][j+1];
                }else{
                    lssup[i][j]=0;
                    lsizq[i][j]=0;
               }
            }
        }
        resp =0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(lssup[i][j]!=0){
                    if(lssup[i][j]==1) resp = lsizq[i][j]>resp?lsizq[i][j]:resp;
                    else{
                        mini = lssup[i][j];
                        auxmin = lssup[i][j];
                        for(k=0;k<lsizq[i][j];k++){
                            if(lssup[i][j+k]==1) break;
                            mini = lssup[i][j+k]<mini?lssup[i][j+k]:mini;
                            auxmin2 = mini*(k+1);
                            if(auxmin2>auxmin)auxmin=auxmin2;
                        }
                        respaux = auxmin;
                        resp = respaux>resp?respaux:resp;
                        resp = lsizq[i][j]>resp?lsizq[i][j]:resp;
                    }
                }
                
            }
        }
        printf("%i\n",resp);
    
    }

}