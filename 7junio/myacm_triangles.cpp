#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#define PI 3.14159265

using namespace std;
typedef struct punto{
    int x;
    int y;
    char lbl;
}punto;

vector<punto>ini,triangulo;
int nmon;
char label;
int x,y,i,j,k,sig,ii,jj;
double area,auxarea,a,b,c,A,auxgrados;
string cad;
bool valido;

bool verificarTriangulo(){
    
    for(ii=0;ii<nmon;ii++){
        auxgrados=0;
        for(jj=0;jj<3;jj++){
            sig=jj==2?0:jj+1;
            a=pow((triangulo[jj].x-triangulo[sig].x),2)+pow((triangulo[jj].y-triangulo[sig].y),2);
            b=pow(ini[ii].x-triangulo[jj].x,2)+pow(ini[ii].y-triangulo[jj].y,2);
            c=pow(ini[ii].x-triangulo[sig].x,2)+pow(ini[ii].y-triangulo[sig].y,2);
            A=acos((a-b-c)/(-2*(sqrt(b)*sqrt(c))));
            auxgrados+=A;
        }
        auxgrados = auxgrados*180/PI;
        if((int)auxgrados==360) return false;
    }
    return true;
}
void calcularArea(){
    punto p1,p2,p3;
    p1=triangulo[0];
    p2=triangulo[1];
    p3=triangulo[2];
    auxarea=abs( 0.5*(double)( ((p3.y-p1.y)*(p2.x-p1.x))-((p2.y-p1.y)*(p3.x-p1.x)) ) );
}
void setArea(){
    if(auxarea>area){
        area=auxarea;
       vector<char>t;
       t.push_back(triangulo[0].lbl);
       t.push_back(triangulo[1].lbl);
       t.push_back(triangulo[2].lbl);
       sort(t.begin(),t.end());
       cad="";
       for(auto&x:t)cad=cad+x;           
    }
}
int main(){
    while(scanf("%i",&nmon)&&nmon!=0){
        ini.reserve(nmon);
        for(i=0;i<nmon;i++){
            cin>>ini[i].lbl>>ini[i].x>>ini[i].y;
        }
        area=0;
        for(i=0;i<nmon;i++){
            for(j=i+1;j<nmon;j++){
                triangulo.clear();
                for(k=j+1;k<nmon;k++){
                    triangulo.push_back(ini[i]);
                    triangulo.push_back(ini[j]);
                    triangulo.push_back(ini[k]);
                    valido=verificarTriangulo();
                    if(valido){
                        calcularArea();
                        if(auxarea>area) setArea();
                    }
                }
            }
        }
        printf("%s\n",cad.c_str());
    }
}