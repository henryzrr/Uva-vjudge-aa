
#include<map>
#include<string>
#include<iostream>
#include<stdio.h>
#include<iterator>
using namespace std;

typedef struct equipo{
    string nombre;
    int pj;
    int ga;
    int gr;
    int pts;
}equipo;

int main(){
    int t,g,i;
    map<string,equipo> ls;
    while(scanf("%i %i",&t,&g) && t && g){
        for(i=0;i<t;i++){
          string aux;  
          cin>>aux;
          equipo  e = {aux,0,0,0,0};
          ls[aux]= e;
        }
        equipo p = ls.find("pedro");
        cout<<p.nombre<<endl;
        //for(map<string,int>::iterator it = ls.begin();i!=ls.end();it++){
          //cout<<it->second->nombre<<"\n";
        //}
        /*for(i=0;i<g;i++){

        }*/
    }
    return 0;
}