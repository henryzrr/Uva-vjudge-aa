#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;
vector<long>ls;
int n;
int main(){
    ls.reserve(1000000);
    ls[0]=1;
    for(int i=1;i<1000000;i++){
        ls[i]=(ls[(i-sqrt(i))]+ls[(log(i))]+ls[(i*pow(sin(i),2))])%1000000;
    }
    while(scanf("%i",&n)&&n!=-1) printf("%li\n",ls[n]);
    return 0;
}