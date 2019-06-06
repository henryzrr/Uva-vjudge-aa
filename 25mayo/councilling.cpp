#include<cstdio>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

map<string,map<string,int>>grafo;
map<string,int> auxm;
map<string,string>percv,clubcv,clubvc,partcv,partvc,camino;
map<string,string>::iterator it1;
queue<string>cola2;
char linea[82];
int minimo,cases,nroPersonas,nroPartidos,nroClubes,contaux,nodo,auxper,auxtam,resp,tamg;
vector<string>auxv;
string auxcad,auxpersona,auxnodo;
bool caminoe,encontrado,first=true;

int main(){
    scanf("%i",&cases);
    fgets(linea,3,stdin);
    fgets(linea,3,stdin);
    while(cases--){
        grafo.clear();
        auxv.clear();
        partcv.clear();
        partvc.clear();
        percv.clear();
        clubcv.clear();
        clubvc.clear();
        tamg=2;
        if(first)first=false;
        else puts("");
        nroPartidos=nroPersonas=nroClubes=0;
        while(fgets(linea,81,stdin)&&linea[0]!='\n'){
            auxtam = strlen(linea)-1;
            linea[auxtam]='\0';
            contaux=1;
            stringstream ss(linea);
            string cad;
            while(getline(ss,cad,' ')){
                if(contaux==1){
                    map<string,int>umaux;
                    auxcad = to_string(tamg);
                    percv[auxcad]=cad;
                    tamg++;
                    grafo[auxcad]=umaux;
                    auxpersona = auxcad;
                    nroPersonas++;
                    
                }else{
                    if(contaux==2){
                        it1 = partvc.find(cad);
                        if(it1==partvc.end()){
                            auxcad = to_string(tamg);
                            tamg++;
                            auxv.push_back(auxcad);
                            nroPartidos++;
                            partcv[auxcad]=cad;
                            partvc[cad]=auxcad;
                        }else auxcad = it1->second;
                        (grafo[auxcad])[auxpersona]=1;
                        (grafo[auxpersona])[auxcad]=0;
                    }else{
                        it1 = clubvc.find(cad);
                        if(it1==clubvc.end()){
                            auxcad = to_string(tamg);
                            tamg++;
                            clubcv[auxcad]=cad;
                            clubvc[cad]=auxcad;
                            (grafo[auxcad])["finendfinal"]=1;
                            (grafo["finendfinal"])[auxcad]=0;
                            nroClubes++;
                        }else auxcad = it1->second;
                        (grafo[auxpersona])[auxcad]=1;
                        (grafo[auxcad])[auxpersona]=0;
                    }
                }
                
                contaux++;  
            }
        }
        if(nroClubes<=2){
            puts("Impossible.");
            continue;
        }
        contaux = nroClubes/2;
        contaux = nroClubes&1?contaux:contaux-1;
        auxper = nroClubes/contaux;
        auxper = nroClubes%contaux==0?auxper:auxper+1;
        if(nroPartidos>=auxper && nroPersonas>=nroClubes){
            auxtam = auxv.size();
            for(int i=0;i<auxtam;i++){
                (grafo["inistartcio"])[auxv[i]]=contaux;
                (grafo[auxv[i]]["inistartcio"])=0;
            }
    
            resp=0;
            caminoe=false;
            while(!caminoe){
                stack<string>cola;
                cola.push("inistartcio");
                encontrado=false;
                minimo=50000;
                camino.clear();
                camino["inistartcio"]="inistartcio";
                while(!encontrado && !cola.empty()){
                    auxcad = cola.top();
                    cola.pop();
                    if(auxcad.compare("finendfinal")!=0){
                         auxm= grafo[auxcad];
                        for(auto&x:auxm){
                            if(camino.find(x.first)==camino.end() && x.second>0){
                                camino[x.first]=auxcad;
                                cola.push(x.first);
                                minimo = minimo<x.second?minimo:x.second;
                            }
                        }
                    }else{
                        encontrado =true;
                        auxcad = "finendfinal";
                   
                        while((camino[auxcad]).compare(auxcad)!=0){
                            auxnodo = camino[auxcad];
                            contaux = ((grafo[auxnodo])[auxcad])-minimo;
                            (grafo[auxnodo])[auxcad] = contaux;
                            contaux = ((grafo[auxcad])[auxnodo])+minimo;
                            (grafo[auxcad])[auxnodo] = contaux;
                            auxcad = auxnodo;
                        }
                
                        resp += minimo;
                    } 
                    
                }
                if(!encontrado)caminoe=true;
                
            }
            if(resp!=nroClubes)puts("Impossible.");
            else{
                auxm= grafo["finendfinal"];
                for(auto&x:auxm)cola2.push(x.first); 
                while(!cola2.empty()){
                    auxcad = cola2.front();
                    cola2.pop();
                    auxm= grafo[auxcad];
                    for(auto&x:auxm){
                        if(x.second==1) auxpersona = x.first;
                    }
                    printf("%s %s\n",(percv[auxpersona]).c_str(),(clubcv[auxcad]).c_str());
                }
            }
        }else{
            puts("Impossible.");
        }
       
    }
    return 0;
}