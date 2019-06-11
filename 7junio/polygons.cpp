#include<cstdio>
#include<vector>
#include<cmath>
#include<unordered_set>
#define PI 3.14159265

using namespace std;
typedef struct nodo{
    int x;
    int y;
    int sig;
}nodo;

vector<nodo>p1,p2,*vpun,*recta,vnew,vaux;
vector<int>ptsa,ptsb,*ptsaux;
int mx,my,la,lb,i,j,tama,tamb,tamaux,ant,laux,pt,laux2;
double auxgrados,m,ma,mb,a,b,c,A,x,y;
bool recta;
bool iguales(){
    if(la!=lb) return false;
    for(i=0;i<la;i++) 
        if(p1[i].x!=p2[i].x || p1[i].y!=p2[i].y)return false;
    return true;
}

void findPuntos(){
    ptsa.clear();
    ptsb.clear();
    //PUNTOS DE A en B
    for(i=0;i<la;i++){
        auxgrados=0;
        for(j=0;j<lb;j++){
            a=pow((p2[j].x-p2[p2[j].sig].x),2)+pow((p2[j].y-p2[p2[j].sig].y),2);
            b=pow(p1[i].x-p2[j].x,2)+pow(p1[i].y-p2[j].y,2);
            c=pow(p1[i].x-p2[p2[j].sig].x,2)+pow(p1[i].y-p2[p2[j].sig].y,2);
            A=acos((a-b-c)/(-2*(sqrt(b)*sqrt(c))));
            auxgrados+=A;
        }
        auxgrados = auxgrados*180/PI;
        if((int)auxgrados==360) ptsb.push_back(i);
    }
    //Puntos de B en A
    for(i=0;i<lb;i++){
        auxgrados=0;
        for(j=0;j<la;j++){
            a=pow((p1[j].x-p1[p1[j].sig].x),2)+pow((p1[j].y-p1[p1[j].sig].y),2);
            b=pow(p2[i].x-p1[j].x,2)+pow(p2[i].y-p1[j].y,2);
            c=pow(p2[i].x-p1[p1[j].sig].x,2)+pow(p2[i].y-p1[p1[j].sig].y,2);
            A=acos((a-b-c)/(-2*(sqrt(b)*sqrt(c))));
            auxgrados+=A;
        }
        auxgrados = auxgrados*180/PI;
        if((int)auxgrados==360) ptsa.push_back(i);
    }
}

void iniciarfindnewArea(){
        if(tama>0&&tamb>0){
            if(tama<tamb){
                vpun=&p1;
                recta=&p2;
                ptsaux=&ptsa;
                tamaux=tama;
                laux=lb;
                laux2=la;
            }else{
                vpun=&p2;
                recta=&p1;
                ptsaux=&ptsb;
                tamaux=tamb;
                laux=la;
                laux2=lb;
            }
        }else{
            if(tama>0){
                vpun=&p1;
                recta=&p2;
                ptsaux=&ptsa;
                tamaux=tama;
                laux=lb;
                laux2=la; 
            }else{
                vpun=&p2;
                recta=&p1;
                ptsaux=&ptsb;
                tamaux=tamb;
                laux=la;
                laux2=lb;
            }
        }
        unordered_set<int>um;    
        unordered_set<int>::iterator it;
        vaux.clear();
        for(i=0;i<tamaux;i++){
            ant=(*ptsaux)[i]-1;
            ant = ant==-1?laux-1:ant;
            pt = (*ptsaux)[i];
            it = um.find(pt);
            if(it==um.end()){
                vaux.push_back((*recta)[pt]);
                um.insert(pt);
            }
            it = um.find(ant);
            if(it==um.end()){
                vaux.push_back((*recta)[ant]);
                um.insert(ant);
            }
        }
        //for(auto&x:vaux)printf("%i %i -- ",x.x,x.y);
       // puts("");
}
void ecuacion recta(){
     if((*vpun)[i].x!=(*vpun)[(*vpun)[i].sig].x &&  (*vpun)[i].y!=(*vpun)[(*vpun)[i].sig].y){
            m=(double)((*vpun)[(*vpun)[i].sig].y-(*vpun)[i].y)/(double)((*vpun)[(*vpun)[i].sig].x-(*vpun)[i].x);
            x=m;
            b=(m*(*vpun)[i].x)+(*vpun)[i].y;
            recta=false;
        }else{
            recta=true;
        }
}
void findArea(){
    vnew.clear();
    laux=vaux.size();
    for(i=0;i<laux2;i++){
        int auxx = (*vpun)[i].x; 
        int auxy = (*vpun)[i].y;
        int auxx2= (*vpun)[(*vpun)[i].sig].x;
        int auxy2= (*vpun)[(*vpun)[i].sig].y;
        for(j=0;j<laux;j++){
            x1=vaux[j].x;
            y1=vaux[j].x;
            x2=vaux[vaux[j].sig].x;
            y2=vaux[vaux[j].sig].x;
            
        }
    }
}

int main(){
    while(scanf("%i",&la)&&la!=0){
        p1.reserve(la);
        for(i=0;i<la;i++){
            scanf("%i %i",&p1[i].x,&p1[i].y);
            p1[i].sig=i+1;
        }
        p1[la-1].sig=0;
        scanf("%i",&lb);
        p2.reserve(lb);
        for(i=0;i<lb;i++){
            scanf("%i %i",&p2[i].x,&p2[i].y);
            p2[i].sig=i+1;
        }
        p2[lb-1].sig=0;
        if(iguales()){
            printf("    0.00\n");
            continue;
        }
        ///puts("---");
        findPuntos();
        tama=ptsa.size();
        tamb=ptsb.size();
        if(tama>0||tamb>0){
            iniciarfindnewArea();
            findArea();
        }
        /*for(auto&x:ptsa)printf("%d ",x);
        puts("");
        for(auto&x:ptsb)printf("%d ",x);
        puts("----------");*/

    }
    return 0;
}