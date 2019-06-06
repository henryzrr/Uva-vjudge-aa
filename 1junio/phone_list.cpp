#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
vector<string>guia;
int cases,i,n,k,auxtam,j;
char telf[15];
bool igual,consistente;

bool comparador(string a, string b){
    return a.size()<b.size();
}

int main(){
    scanf("%i",&cases);
    while(cases--){
        guia.clear();
        scanf("%i",&n);
        for(i=0;i<n;i++){
            scanf("%s",telf);
            guia.push_back(telf);
        }
        sort(guia.begin(),guia.end(),comparador);
        n--;
        consistente=true;
        for(i=0;i<n;i++){
            auxtam = guia[i].size();
            for(j=i+1;j<=n;j++){
                igual=guia[i][0]==guia[j][0];
                k=1;
                while(k<auxtam && igual){
                    igual = guia[i][k]==guia[j][k];
                    k++;
                }
                if(igual){
                    consistente=false;
                    break;
                }
            }
            if(!consistente) break;
        }
        if(!consistente) puts("NO");
        else puts("YES");
    }
    return 0;
}