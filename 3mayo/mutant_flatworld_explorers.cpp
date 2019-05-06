#include<cstdio>
#include<cstring>

using namespace std;
bool grid[51][51];
int tamx,tamy,posx,posy,orr,tamaux,i,j,lostls[51][51];
char aux,cad[105],orientacion[4]={'E','N','W','S'};
bool lost;

void resetgrid(){
    for(i=0;i<=50;i++){
        for(j=0;j<=50;j++){
            grid[i][j]=true;
            lostls[i][j]=-1;
        }
    }
}
void moverRobocop(char instr){
    if(instr=='R') orr = orr==0?3:orr-1;
    else if(instr=='L') orr=orr==3?0:orr+1;
    else if(grid[posx][posy] || lostls[posx][posy]!=orr){
        if(orr==0){
                posx++;
                if(posx>tamx){
                    posx--;
                    if(grid[posx][posy]){
                        lost=true;
                        grid[posx][posy]=false;
                        lostls[posx][posy]=orr;
                    }
                }
            
        }else if(orr==1){
            
                posy++;
                if(posy>tamy){
                    posy--;
                    if(grid[posx][posy]){
                        lost=true;
                        grid[posx][posy]=false;
                        lostls[posx][posy]=orr;
                    }
                }
            
        }else if(orr==2){
                
                posx--;
                if(posx<0){
                   
                    posx++;
                    if(grid[posx][posy]){
                        lost=true;
                        grid[posx][posy]=false;
                        lostls[posx][posy]=orr;
                    }
            } 
        }else{
                posy--;
                if(posy<0){
                    posy++;
                    if(grid[posx][posy]){
                        lost=true;
                        grid[posx][posy]=false;
                        lostls[posx][posy]=orr;
                    }
                }
            
        }
    }
    
}

int main(){
    scanf("%i %i",&tamx,&tamy);
    resetgrid();
    while(scanf("%i %i %c",&posx,&posy,&aux)!=EOF){
        orr = aux=='E'?0:aux=='N'?1:aux=='W'?2:3;
        lost=false;
        scanf("%s",cad);
        tamaux = strlen(cad);
        i=0;
        while(!lost && i<tamaux){
            moverRobocop(cad[i]);
            i++;
        }
        
        printf("%i %i %c%s\n",posx,posy,orientacion[orr],(lost?" LOST":""));

    }
    
    return 0;
}