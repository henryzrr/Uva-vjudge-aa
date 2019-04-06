#include<stdio.h>
#include<list>
using namespace std;
typedef struct segmento{
    int a;
    int b;
}segmento;

int main(){
    int cases,lim,a,b,ini;
    list<segmento> lsSegmentos,lsres;
    scanf("%i",&cases);
    char trash[10];
    while(cases){
        fgets(trash,9,stdin);
        fgets(trash,9,stdin);
        scanf("%i",&lim);
        while(scanf("%i %i",&a,&b) &&(a||b)){
            if(b>0 && a<lim){
                segmento s;
                s.a = a;
                s.b=b;
                lsSegmentos.push_back(s);
            }
        }
        b=1;
        ini=0;
        
        while(!lsSegmentos.empty() && ini<lim &&b){
            segmento res;
            res.b=ini;
            a = lsSegmentos.size();
            for(auto x = lsSegmentos.begin();x!=lsSegmentos.end();x++){
                if((*x).b>ini && (*x).a<=ini){
                    if((*x).b>res.b){
                        res.a = (*x).a;
                        res.b = (*x).b;
                    }
                    lsSegmentos.erase(x);
                    x--;
                    if(res.b>=lim) break;
                }
            }
            if(a==lsSegmentos.size()){
                b=0;
                break;
            }
            ini = res.b;
            lsres.push_back(res);
        }
        if(b==0 || ini<lim){
            printf("0\n\n");
        }else{
            printf("%i\n",lsres.size());
            for(auto&x:lsres){
                printf("%i %i\n",x.a,x.b);
            }
            puts("");
        }
        lsres.clear();
        lsSegmentos.clear();
        cases--;
    }
    return 0;
}