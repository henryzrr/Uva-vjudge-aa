#include<iostream>
#include<stdio.h>
#include<vector>
#include <sstream>
using namespace std;
int main(){
    int cases,p;
    string trash;
    scanf("%i",&cases);
    while(cases){
        scanf("%i",&p);
        getline(cin,trash);
        vector<int> ls[p];
        for(int i=0;i<p;i++){
            string cad;
            getline(cin,cad);
            string num;
            stringstream ss(cad);
            while(getline(ss,num,' ')){
                ls[i].push_back(stoi(num));
            }
        }
        vector<int> res;
        int min=p+1;
        for(int i=0;i<p;i++){
            int tam = ls[i].size();
            if(tam<min){
                res.clear();
                min = tam;
                res.push_back(i+1);
            }else if(tam==min){
                res.push_back(i+1);
            }
        }
        int tamr = res.size();
        for(int i=0;i<tamr;i++){
            if(tamr-i!=1) cout<<res[i]<<" ";
            else cout<<res[i]<<"\n";
        }
        cases--;
    }
    return 0;
}