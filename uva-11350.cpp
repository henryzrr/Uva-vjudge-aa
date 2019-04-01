#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int cases;
    char trash[5];
    char d;
    scanf("%i",&cases);
    fgets(trash,5,stdin);
    while(cases){
        unsigned long long int inum=0,iden=1,mnum=1,mden=1,dnum=1,dden=0;
        while(scanf("%c",&d)&&d!='\n'){
            if(d=='R'){
                inum=mnum;
                iden=mden;
                mnum=inum+dnum;
                mden=iden+dden;
            }else{
                dnum=mnum;
                dden=mden;
                mnum=dnum+inum;
                mden=dden+iden;
            }
        }
        cout<<mnum<<"/"<<mden<<"\n";
        cases--;
    }
    return 0;
}