#include<cstdio>
#include<cstring>

using namespace std;
int ns,i,arr[1000001][26],tamcad,aux,j,auxp,s,p,k;
char cad[1000005],chars,charp;

void prepararArreglo(){
    for(j=0;j<=ns;j++){
        for(k=0;k<26;k++){
            arr[j][k]=0;
        }
    }
}

int main(){
    scanf("%i",&ns);
    prepararArreglo();
    for(i=1;i<=ns;i++){
        
        scanf("%s",cad);
        tamcad = strlen(cad);
        p=1;s=tamcad-2;
        charp=cad[0];
        chars=cad[tamcad-1];
        //printf("%i %i",ns,tamcad);
        while(cad[p]==charp && p<tamcad)p++;
        while(cad[s]==chars && s>=0)s--;
        
        int arraux[26]={0};
        arraux[cad[0]-'a']=1;
        arr[i][cad[0]-'a']=1;
        for(j=1;j<tamcad;j++){
            aux = cad[j]-'a';
            if(cad[j]==cad[j-1])arraux[aux]++;
            else arraux[aux]=1;
            arr[i][aux]= arraux[aux]>arr[i][aux]?arraux[aux]:arr[i][aux];
        }
        if(p==tamcad){
            if(arr[i-1][charp-'a']>0){
                auxp = ((arr[i-1][charp-'a']+1)*p) + arr[i-1][charp-'a'];
                arr[i][charp-'a']=auxp;
            }
        }else{
            if(charp!=chars){
                if(arr[i-1][charp-'a']>0)arr[i][charp-'a']=1+p;
                if(arr[i-1][chars-'a']>0)arr[i][chars-'a']=tamcad-s;  
            }else{
                if(arr[i-1][charp-'a']>0) arr[i][charp-'a']=p+tamcad-s;
            }
        }
        
        for(j=0;j<26;j++){
            arr[i][j]=arr[i][j]==0&&arr[i-1][j]>0?1:arr[i][j];
        }
    
    }
    auxp=0;
    for(j=0;j<26;j++){
        auxp = arr[ns][j]>auxp?arr[ns][j]:auxp;
    }
    /*for(j=0;j<=ns;j++){
        for(i=0;i<26;i++){
            printf("%i ",arr[j][i]);
        }
        puts("");
    }*/
    printf("%i\n",auxp);
    return 0;
}