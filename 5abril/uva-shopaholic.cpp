#include<stdio.h>
#include<algorithm>
using namespace std;
bool comparador(int a, int b){
	return b<a;
}
int main(){
	int cases,nroCompra;
	while(cases){
		scanf("%i",&nroCompra);
		int ls[nroCompra];
		for(int i=0;i<nroCompra;i++){
			scanf("%i",&ls[i]);
		}
		sort(ls,ls+cases,comparador);
		cases--;
		for(auto&x:ls){
			printf("%i ",x);
		}
		puts("");
	}
	return 0;
}