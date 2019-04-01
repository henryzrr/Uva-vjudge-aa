#include<stdio.h>
#include<set>
#include<forward_list>
#include<string.h>
using namespace std;

int main(){
    int cases;
    char par[100];
    scanf("%i",&cases);
    fgets(par,100,stdin);
    forward_list<set<char>>ls;
    while(cases){
        while(fgets(par,100,stdin)!=NULL){
            if(par[0]=='*') break;
            
            bool a=false,b=false;
            forward_list<set<char>>::iterator ita,itb;
            for(auto x=ls.begin();x!=ls.end(); x++){
                if(!a && (*x).find(par[1])!=(*x).end()){
                    a=true;
                    ita=x;
                    continue;
                }
                if(!b && (*x).find(par[3])!=(*x).end()){
                    b=true;
                    itb=x;
                }
                if(a&&b) break;
            }
            if(!a&&!b){
                set<char> lc;
                lc.insert(par[1]);
                lc.insert(par[3]);
                ls.push_front(lc);
            }else if(!a && b){
                itb->insert(par[1]);
            }else if(a&&!b){
                ita->insert(par[3]);
            }else{
                ita->insert(itb->begin(),itb->end());
                ls.remove(*itb);
            }
            
        }
       
        char abc [100];
        fgets(abc,100,stdin);
        int tam = strlen(abc);
        for(int i=0;i<tam;i++){
            if(abc[i]>='A' && abc[i]<='Z'){
                bool encontrado=false;
                for(auto x=ls.begin(); x!=ls.end();x++){
                    if((*x).find(abc[i])!=(*x).end()){
                        encontrado = true;
                        break;
                    }
                }
                if(!encontrado){
                    set<char> res;
                    res.insert(abc[i]);
                    ls.push_front(res);
                }
            }
        }
        int arboles=0;
        int acorn = 0;
        for(auto& x:ls){
            if(x.size()==1) acorn++;
            else arboles ++;
        }
        printf("There are %i tree(s) and %i acorn(s).\n",arboles,acorn);
        cases--;
        ls.clear();
    }
    return 0;
}