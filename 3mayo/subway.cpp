#include<cstdio>
#include<sstream>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;
typedef struct nodo{
    int padre;
    float distMin;
    int visitado;
    int x;
    int y;
    int linea;
    int n;
}nodo;
struct comparador{
    bool operator()(const nodo &a, const nodo& b){
        return b.distMin<a.distMin;
    }
};

int cases,i,j,res;
float minutos[202][202];
nodo lsNodos[202],auxnodo;
string straux;
char lineaGrafo[3000],actual,trash[4];
bool first=true,auxf;
float rel,dist;

void iniciarMinutos(){
    for(int k=0;k<202;k++){
        for(int l=0;l<202;l++){
            minutos[k][l]=-1.0;
        }
    }
}
void setWeight(){
    for(int k=0;k<i-1;k++){
        for(int l=k+1;l<i;l++){
                
            if(minutos[k][l]==-1){
                dist=pow((lsNodos[k].x -lsNodos[l].x)/1000.0,2.0) + pow((lsNodos[k].y-lsNodos[l].y)/1000.0,2.0);
                dist=sqrt(dist)*6.0;
                minutos[l][k]=minutos[k][l]=dist;
            }
        }
    }
}

float findCaminoMinimo(){
    priority_queue<nodo,vector<nodo>,comparador> cola;
    cola.push(lsNodos[0]);
    while(!cola.empty()){
        auxnodo = cola.top();
        cola.pop();
        lsNodos[auxnodo.n].visitado=1;
        if(auxnodo.n==1) return auxnodo.distMin;
        for(int k=0;k<i;k++){
            if(minutos[auxnodo.n][k]!=-1){
                if(lsNodos[k].visitado==-1){
                    lsNodos[k].visitado=0;
                    lsNodos[k].distMin = lsNodos[auxnodo.n].distMin+minutos[auxnodo.n][k];
                    lsNodos[k].padre = auxnodo.n;
                    cola.push(lsNodos[k]);
                }else if(lsNodos[k].visitado==0){
                    dist = lsNodos[auxnodo.n].distMin+minutos[auxnodo.n][k];
                    if(dist<lsNodos[k].distMin){
                        lsNodos[k].distMin=dist;
                        lsNodos[k].padre=auxnodo.n;
                        cola.push(lsNodos[k]);
                    }
                }
            }
        }
    }

}
int main(){
    scanf("%i",&cases);
    fgets(trash,2,stdin);
    fgets(trash,2,stdin);
    while(cases--){
        iniciarMinutos();
        scanf("%i %i %i %i",&lsNodos[0].x,&lsNodos[0].y,&lsNodos[1].x,&lsNodos[1].y);
        lsNodos[0].padre=-1;
        lsNodos[0].distMin=0.0;
        lsNodos[0].visitado=-1;
        lsNodos[0].linea=-2;
        lsNodos[0].n=0;
        lsNodos[1].visitado=-1;
        lsNodos[1].linea=-1;
        lsNodos[1].n=1;
        i=2;
        fgets(trash,2,stdin);
        actual='x';
        j=1;
        
        while(fgets(lineaGrafo,2999,stdin)&&lineaGrafo[0]!='\n'){
            stringstream ss(lineaGrafo);
            auxf=true;
            while(getline(ss,straux,' ')){
                if(straux=="-1")break;
                if(actual=='x'){
                    lsNodos[i].x=atoi(straux.c_str());
                    actual='y';
                }else{
                    lsNodos[i].y=atoi(straux.c_str());
                    lsNodos[i].visitado=-1;
                    lsNodos[i].linea=j;
                    lsNodos[i].n=i;
                    if(!auxf){
                        dist=pow((lsNodos[i].x -lsNodos[i-1].x)/1000.0,2.0) + pow((lsNodos[i].y-lsNodos[i-1].y)/1000.0,2.0);
                        dist=sqrt(dist)*1.5;
                        minutos[i][i-1]=minutos[i-1][i]=dist;
                    }
                    i++;
                    actual='x';
                    if(auxf) auxf=false;
                }
            }
            j++;
        }
    
        setWeight();
        res = (int)round(findCaminoMinimo());
        if(!first) puts("");
        printf("%i\n",res);
        if(first) first=false;
    }

    return 0;
}