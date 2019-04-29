#include<cstdio>

using namespace std;
int n,i,j,k,l,auxi,auxj,max,auxresp,sup,izq,el;
int main(){
    scanf("%i",&n);
    int ls[n][n],sum[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%i",&ls[i][j]);
        }
    }
    auxi=auxj=0;
    for(i=0;i<n;i++){
        auxi += ls[0][i];
        sum[0][i]=auxi;
        auxj +=ls[i][0];
        sum[i][0]=auxj;
    }
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            sum[i][j] = sum[i][j-1]+sum[i-1][j]+ls[i][j]-sum[i-1][j-1];
        }
    }
    
    max = -128;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            k=l=-1;
            auxi = i-1;
            auxj = j-1;
            while(k!=auxi || l!=auxj){
                if(k>-1 || l>-1){
                    sup = k==-1?0:sum[k][j];
                    izq = l==-1?0:sum[i][l];
                    el = k>-1&&l>-1?sum[k][l]:0;
                    auxresp = sum[i][j]-sup-izq+el;
                    max = auxresp>max?auxresp:max;
                }else{
                    max = ls[i][j]>max?ls[i][j]:max;
                } 

                l++;
                if(l>=auxj && k<auxi){
                    k++;
                    l = -1;
                }
    
            }
            max = ls[i][j]>max?ls[i][j]:max;
        }
    }
    printf("%i\n",max);
    return 0;
}