#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>

using namespace std;

int table[1010][1010];
int main()
{
 int test,t,i,j,len;
 char x[1010],y[1010];
 scanf("%d",&test);
 t=1;
 while(t<=test)
 {
  scanf("%s",x);
  len=strlen(x);
  strcpy(y,x);
  reverse(y,y+len);
  for(i=0;i<=len;i++)
  table[i][0]=i;
  for(j=0;j<=len;j++)
   table[0][j]=j;
  for(i=1;i<=len;i++)
  {
   for(j=1;j<=len;j++)
   {
    if(x[i-1]==y[j-1])
     table[i][j]=table[i-1][j-1];
    else
     table[i][j]=min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]))+1;
   }
  }
  printf("Case %d: %d\n",t++,table[len][len]/2);
 }
 return 0;
}