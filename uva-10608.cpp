#include<stdio.h>
#include<set>
#include<forward_list>
using namespace std;
int main(){
    int cases,n,m,pa,pb,pos=0;
    forward_list<set<int>> grafos;
    scanf("%i",&cases);
    while(cases){
        scanf("%i %i",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%i %i",&pa,&pb);
            bool aencontrado=false;
            bool bencontrado=false;
            forward_list<set<int>>::iterator a,b;
            
            for(forward_list<set<int>>::iterator x = grafos.begin();x!=grafos.end();x++){
            
                if(!aencontrado){
                    if((*x).find(pa)!=(*x).end()){
                        aencontrado = true;
                        a=x;
                        continue;
                    }
                }
                if(!bencontrado){
                    if((*x).find(pb)!=(*x).end()){
                        b=x;
                        bencontrado = true;
                    }
                } 
                if(aencontrado&&bencontrado) break;     
            }
            if(!aencontrado && !bencontrado){
                set<int>aux;
                aux.insert(pa);
                aux.insert(pb);
                grafos.push_front(aux);
            }else if(aencontrado && !bencontrado){
                (*a).insert(pb);
                
            }else if(!aencontrado && bencontrado){
                b->insert(pa);
            }else{
                (*a).insert((*b).begin(),(*b).end());
                grafos.remove(*b);
            }
        }
        cases--;
        int mayor=1;
        for(auto& x: grafos){
            if(x.size()>mayor) mayor=x.size();
        }
        printf("%i\n",mayor);
        grafos.clear();
    }
    return 0;
}