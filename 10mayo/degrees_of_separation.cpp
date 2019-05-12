#include<cstdio>
#include<unordered_map>
#include<string>

using namespace std;
unordered_map<string,int> index;
unordered_map<string,int>::iterator it,it2;

string n1,n2;
int i,p,j,r,cont,grafo[50][50],maxdegree,aux,ia,ib,contn,disconnected;
char nombre1[100],nombre2[100];

void iniciarGrafo(){
    for(i=0;i<p;i++) for(j=0;j<p;j++) grafo[i][j]=-1;
}
void setPath(int fj,int fi){
    for(cont=0;cont<p;cont++){
        if(grafo[fi][cont]!=-1){
            if(grafo[fj][cont]==-1){
                grafo[fj][cont]=grafo[fi][cont]+grafo[fi][fj];
                disconnected--;
            }else if(grafo[fj][cont]>1){
                aux = grafo[fi][cont]+grafo[fi][fj];
                grafo[fj][cont]=aux<grafo[fj][cont]?aux:grafo[fj][cont];
            } 
        }
    }
}
int main(){
    contn=1;
    while(scanf("%i %i",&p,&r)&&p!=0 && r!=0){
        cont=0;
        iniciarGrafo();
        disconnected=p*p;
        for(i=0;i<r;i++){
            scanf("%s %s",nombre1,nombre2);
            n1 =nombre1;
            n2=nombre2;
            it=index.find(n1);
            it2=index.find(n2);
            if(it == index.end()){
                index[n1]=cont;
                ia=cont;
                cont++;
                grafo[ia][ia]=0;
                disconnected--;
            }else ia=it->second;
            
            if(it2 == index.end()){
                index[n2]=cont;
                ib=cont;
                cont++;
                grafo[ib][ib]=0;
                disconnected--;
            }else ib=it2->second;
            
            grafo[ia][ib]=1;
            grafo[ib][ia]=1;
            disconnected -=2;
        }
        maxdegree=1;
        for(i=0;i<p;i++){
            for(j=0;j<p;j++){
                if(grafo[i][j]!=-1 && i!=j) setPath(j,i);
            }
        }
        maxdegree=1;
        for(i=0;i<p;i++) for(j=0;j<p;j++) maxdegree=grafo[i][j]>maxdegree?grafo[i][j]:maxdegree;
        if(disconnected==0) printf("Network %i: %i\n\n",contn,maxdegree);
        else printf("Network %i: DISCONNECTED\n\n",contn);
        contn++;   
        index.clear();
    }
    return 0;
}