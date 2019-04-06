#include<stdio.h>
#include<algorithm>
#include<list>
using namespace std;

typedef struct team{
    int pos;
    int size;
}team;

bool comparador(team a, team b){
    return b.size<a.size;
}

int main(){
    int equipos,mesas;
    
    while(scanf("%i %i",&equipos,&mesas)&&equipos&&mesas){
        team lsEquipos[equipos];
        list<int> resp[equipos];
        int lsMesas[mesas];
        for(int i=0;i<equipos;i++){
            team eq;
            eq.pos=i;
            scanf("%i",&eq.size);
            lsEquipos[i]=eq;
        }
        for(int i=0;i<mesas;i++){
            scanf("%i",&lsMesas[i]);
        }
        sort(lsEquipos,lsEquipos+equipos,comparador);
      
        int j=0;
        int res = 1;
        while(j<equipos && res){
            int aux =1; 
            list<int> grupo_mesa;
            for(int i=0;i<mesas;i++){
                if(lsMesas[i]>0 && lsEquipos[j].size>0){
                    grupo_mesa.push_back(i+1);
                    lsMesas[i] -=1;
                    lsEquipos[j].size -=1;
                }
            }
         
            if(lsEquipos[j].size!=0) res=0;
            else resp[lsEquipos[j].pos] = grupo_mesa;
            j++;
        }
        if(res){
            puts("1");
            for(int i=0;i<equipos;i++){
                auto aux = resp[i].begin();
                aux++;
                for(auto x = resp[i].begin();aux!=resp[i].end();x++){
                    printf("%i ",*x);
                    aux++;
                }
                auto x = resp[i].end();
                x--;
                printf("%i\n",*x);
            }
        }else{
            puts("0");
        }
    }
    return 0;
}