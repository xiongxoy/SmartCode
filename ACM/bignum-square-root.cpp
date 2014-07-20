#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEPTH 10

typedef int BigInteger[10100];

int comp(const BigInteger a,const int c,const int d,const BigInteger b) //大数比较
{
  int i,t=0,O=-DEPTH*2;
  if(b[0]-a[0]<d&&c) return 1;
  for(i=b[0];i>d;i--)
  {
    t=t*DEPTH+a[i-d]*c-b[i];
    if(t>0) return 1;
    if(t<O) return 0;
  }
  for(i=d;i;i--)
  {
    t=t*DEPTH-b[i];
    if(t>0) return 1;
    if(t<O) return 0;
  }
  return t>0;
}

void sub(BigInteger a,const BigInteger b,const int c,const int d) //大数减
{
  int i,O=b[0]+d;
  for(i=1+d;i<=O;i++)
    if((a[i]-=b[i-d]*c)<0)
      a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
  for(;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
  for(;!a[a[0]]&&a[0]>1;a[0]--);
}

void Sqrt(BigInteger b,BigInteger a) //开平方
{
  int h,l,m,i;
  memset((void*)b,0,sizeof(BigInteger));
  for (i= b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)
    for (h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)
      if (comp(b,m,i-1,a)) h=m-1;
      else l = m;
  for (;!b[b[0]]&&b[0]>1;b[0]--);
  for (i = 1; i <= b[0]; b[i++] >>= 1);
}

char str[10100];
BigInteger a,b;

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%s",str);
    a[0]=strlen(str);
    for(int i=1; i<=a[0]; i++)
      a[i]=str[a[0]-i]-'0';
    Sqrt(b,a);
    for(int i=b[0]; i>=1; i--)
      printf("%d",b[i]);
    printf("\n");
    if(t)
      puts("");
  }
  return 0;
}

