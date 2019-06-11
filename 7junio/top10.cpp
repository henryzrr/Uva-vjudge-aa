#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
typedef struct auxcad{
    int pos;
    int rep;
}auxcad;
vector<string>diccionario;
vector<auxcad>match;
string cad;
int tamdicc,querys,i,j,auxtam,auxtam2,cont,k,menor;

bool comparador(auxcad a,auxcad b){
    auxtam = diccionario[a.pos].size();
    auxtam2 = diccionario[b.pos].size();
    if(auxtam!=auxtam2)return auxtam<auxtam2;
    else{
        for(i=0;i<auxtam;i++){
            if(diccionario[a.pos][i]!=diccionario[b.pos][i])break;
        }
        if(i<auxtam) return diccionario[a.pos][i]<diccionario[b.pos][i];
        else return a.pos<b.pos;
    }
}
void buscarMatch(){
    auxtam=cad.size();
    int auxarr[auxtam];
    i=0;
    j=1;
    auxarr[0]=0;
    while(j<auxtam){
        if(cad[i]==cad[j]){
            auxarr[j]=i+1;
            i++;
            j++;
        }else if(i==0){
            auxarr[j]=0;
            j++;
        }
        else i=auxarr[i-1];
    }
    for(i=0;i<tamdicc;i++){
        auxtam2=diccionario[i].size();
        k=0;
        j=0;
        cont=0;
        while(j<auxtam2){
            if(k==auxtam){
                cont++;
                k=auxarr[k-1];
            }else if(diccionario[i][j]==cad[k]){
                j++;
                k++;
            }else if(k==0)j++;
            else k=auxarr[k-1];
        }
        if(k==auxtam)cont++;
        if(cont>0){
            auxcad a;
            a.pos=i;
            a.rep=cont;
            match.push_back(a);
        }
    }
}

void mostrarMatch(){
    auxtam=match.size();
    auxtam2 = auxtam>10?10:auxtam;
    if(auxtam==0)puts("-1");
    else{
        printf("%i",match[0].pos+1);
        for(i=1;i<auxtam2;i++) printf(" %i",match[i].pos+1);
        puts("");
    }
}

int main(){
    cin>>tamdicc;
    diccionario.reserve(tamdicc);
    for(i=0;i<tamdicc;i++){
        cin>>cad;
        diccionario[i]=cad;
    }
    cin>>querys;
    while(querys--){
        cin>>cad;
        match.clear();
        buscarMatch();
        
        sort(match.begin(),match.end(),comparador);       
        mostrarMatch();
    }
    return 0;
}