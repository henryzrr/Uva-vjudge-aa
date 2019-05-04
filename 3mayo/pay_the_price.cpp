#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<vector>

using namespace std;
unsigned long long ls[301][301];
int tam,auxn;
string aux;
char num[100];
vector<unsigned long long>res;
int main(){
    //ls[0][0]=0;
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
        vector<int>query;
        while(getline(s,aux,' ')){
            auxn = atoi(aux.c_str());
            query.push_back(auxn);
        }
        tam = query.size();
        if(tam==1){
            if(query[0]==0)res.push_back(1);//puts("1");
            //else if(query[0]>300) printf("%llu\n",ls[query[300]][300]);
            else res.push_back(ls[query[0]][query[0]]);//printf("%llu\n",ls[query[0]][query[0]]);
        }else if(tam==2){
            if(query[1]>300) res.push_back(ls[300][query[0]]);//printf("%llu\n",ls[300][query[0]]);
            else if(query[0]==0&&query[1]==0)res.push_back(1);//puts("1");
            else if(query[1]==0)res.push_back(0);//puts("1");
            else res.push_back(ls[query[1]][query[0]]);//printf("%llu\n",ls[query[1]][query[0]]);
        }else{
            if(query[0]==0 && query[1]==0) res.push_back(1);//puts("1");
            else if(query[0]==0&&query[1]>0) res.push_back(0);//puts("0");
            else if(query[2]==0 || query[1]>300) res.push_back(0);//puts("0");
            else if(query[1]<=1&&query[2]<301) res.push_back(ls[query[2]][query[0]]);//printf("%llu\n",ls[query[2]][query[0]]);
            else if(query[2]<301) res.push_back(ls[query[2]][query[0]]-ls[query[1]-1][query[0]]);//printf("%llu\n",ls[query[2]][query[0]]-ls[query[1]-1][query[0]]);
            else res.push_back(ls[300][query[0]]-ls[query[1]-1][query[0]]);
        }
    }
    for(auto&x:res){
            printf("%llu\n",x);
    }
    return 0;
}