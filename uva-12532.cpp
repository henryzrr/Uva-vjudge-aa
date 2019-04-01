#include<cstdio>
#include<iostream>
#define compare(a,b) a==0 || b==0?0:a>0&&b<0?-1:a<0&&b<0?1:a
using namespace std;


int main(){
    int n,k,aux,aux2;
    char op;
    while(scanf("%d %d",&n,&k)!=EOF){
        string resp="";
        int ls[n];
        for(int i=0;i<n;i++){
            scanf("%i",&ls[i]);
        }
        for(int i=0;i<k;i++){
            scanf("%c",&op);
            while(op!='P' && op !='C')scanf("%c",&op);
            scanf("%i %i",&aux,&aux2);
            switch(op){
                case 'C':
                    ls[aux-1]=aux2;
                    break;
                case 'P':
                    aux2--;
                    int res = ls[aux-1];
                    for(int j=aux;j<=aux2;j++){
                        res = compare(res,ls[j]);
                        if(res==0)break;
                    }
                    resp+=res>0?'+':res<0?'-':'0';
            }
        }
        cout<<resp<<"\n";
    }
    return 0;
}