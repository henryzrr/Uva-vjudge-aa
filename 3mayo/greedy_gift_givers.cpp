#include<cstdio>
#include<unordered_map>
#include<string>
#include<vector>


using namespace std;

vector<string>orden;
int n,monto,nroAmigos,i,montoRegalo;
char nombre[25],nombre2[25];
bool first=true;
string aux;
unordered_map<string,int>lsAmigos;

int main(){
    while(scanf("%i",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%s",nombre);
            orden.push_back(nombre);
            lsAmigos[nombre]=0;
        }

        while(n--){
            scanf("%s %d %d",nombre,&monto,&nroAmigos);
            if(nroAmigos==0) continue;
            montoRegalo = monto/nroAmigos;
            lsAmigos[nombre]-=montoRegalo*nroAmigos;
            while(nroAmigos--){
                scanf("%s",nombre);
                lsAmigos[nombre]+=montoRegalo;
            }
        }

        if(!first) puts("");
        n=orden.size();
        for(int k=0;k<n;k++){
            printf("%s %i\n",orden[k].c_str(),lsAmigos[orden[k]]);
        }
        if(first)first=false;
        lsAmigos.clear();
        orden.clear();
    }
    return 0;
}