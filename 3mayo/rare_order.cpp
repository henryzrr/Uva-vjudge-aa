#include<cstdio>
#include<set>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

char ls[6000][22];
int i,tamcad,j,k;
set<char>letras;
set<char>::iterator it;
string res="";
int main(){
    i=0;
    while(scanf("%s",ls[i])&&ls[i][0]!='#'){
        tamcad=strlen(ls[i]);
        for(j=tamcad;j<22;j++)ls[i][j]='x';
        i++;
    } 
    for(j=0;j<22;j++){
        for(k=0;k<i;k++){
            if(ls[k][j]>='A'&&ls[k][j]<='Z'){
                it = letras.find(ls[k][j]);
                if(it==letras.end()){
                    res+=ls[k][j];
                    letras.insert(ls[k][j]);
                }
            }
            
        }
    }
    printf("%s\n",res.c_str());
    return 0;
}