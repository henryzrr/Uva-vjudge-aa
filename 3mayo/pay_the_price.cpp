#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<vector>

using namespace std;
unsigned long long ls[301][301];
int tam,auxn;
string aux;
char num[100];
int main(){
    ls[0][0]=1;
    for(int i=1;i<=300;i++){
        ls[i][0]=1;
        ls[0][i]=0;
    }
    for(int i=1;i<=300;i++){
        for(int j=1;j<=300;j++){
            if(j>=i){
                ls[i][j]=ls[i-1][j]+ls[i][j-i];
            }else{
                ls[i][j]=ls[i-1][j];
            }
            
        }
    } 
    while(fgets(num,99,stdin)){
        stringstream s(num);
        int query[3];
        auxn=0;
        while(getline(s,aux,' ')){
            query[auxn] = atoi(aux.c_str());
            auxn++;
        }
        if(auxn==1){
            if(query[0]>300) printf("%llu\n",ls[query[300]][query[300]]);
            else printf("%llu\n",ls[query[0]][query[0]]);
        }else if(auxn==2){
            if(query[1]<301)printf("%llu\n",query[0]==0?1:ls[query[1]][query[0]]);
            else printf("%llu\n",ls[300][query[0]]);
        }else if(auxn==3){
            if(query[0]==0) printf("%llu\n",query[1]==0?1:0);
            else if(query[1]<=1) printf("%llu\n",query[2]==0?0:query[2]>300?ls[300][query[0]]:ls[query[2]][query[0]]);
            else if(query[1]<301) printf("%llu\n",query[2]<301?ls[query[2]][query[0]]-ls[query[1]-1][query[0]]:ls[300][query[0]]-ls[query[1]-1][query[0]]);
            else puts("0");
        }
    }
    return 0;
}