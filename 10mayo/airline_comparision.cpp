#include<cstdio>
using namespace std;
int cases,a1,i,padre[28],rk[28],pa,pb;
char c1[10],c2[10];
bool second,res,first=true;
void iniciarUF(){
	for(int i=1;i<=27;i++){
		rk[i]=0;
		padre[i]=i;
	}
}
int find(int n){
	return padre[n]==n?n:padre[n]=find(padre[n]);
}
void unionfind(int a, int b){
	pa=find(a);
	pb=find(b);
	if(pa!=pb){
		if(second) res = false;
		
		if(rk[pa]>rk[pb])padre[pb]=pa;
		else{
			padre[pa]=pb;
			if(rk[pa]==rk[pb]) rk[pa]++;
		}
		
	}
}

int main(){
	scanf("%i",&cases);
	while(cases--){
		iniciarUF();
		scanf("%i",&a1);
		second=false;
		for(i=0;i<a1;i++){
			scanf("%s %s",c1,c2);
			unionfind(c1[0]-64,c2[0]-64);
		}
		scanf("%i",&a1);
		res=true;
		second=true;
		for(i=0;i<a1;i++){
			scanf("%s %s",c1,c2);
			unionfind(c1[0]-64,c2[0]-64);
			if(!res)break;
		}
		if(!first)puts("");
		printf("%s\n",res?"YES":"NO");
		if(first) first=false;
	}
	return 0;
}