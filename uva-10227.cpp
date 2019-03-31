#include<iostream>
#include<set>
#include<unordered_map>
#include<stdio.h>

using namespace std;

int main(){
    int cases,t,p,np,nt;
    string lb;
    char line[15];
    scanf("%i",&cases);
    getline(cin,lb);
    getline(cin,lb);
    while(cases){
        scanf("%i %i",&p,&t);
        getline(cin,lb);
        unordered_map<int,set<int>> lspt;
        while(fgets(line,14,stdin)!=0&&line[0]!='\n'){
            sscanf(line,"%i %i",&np,&nt);
            set<int>ls = lspt[np];
            if(!ls.empty()){
                lspt[np].insert(nt);
            }else{
                set<int>trees;
                trees.insert(nt);
                lspt[np]=trees;
            }
        }
        int sinOpinion = lspt.size()-p==0?0:1;
        set<set<int>> opiniones;
        for(auto& x:lspt) opiniones.insert(x.second);
        cout<<opiniones.size()+sinOpinion<<"\n";
        if(cases>1)
            cout<<"\n";
        cases--;
    }
    return 0;
}