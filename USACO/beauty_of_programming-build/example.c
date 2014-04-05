//source here
/*http://programming2013.cstnet.cn/qualification/problem/1*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 60000

struct node 
{
    int next[26]; //你懂得
    int like; //指向同音词
    char * word;//存单词
}ci[N];

int num ;
//记录所用节点的

//新节点的初始化
void newnode(int p)
{
    //ci[p].pass=0 ;
    int i;
    if(p>=N-1) while(1);
    for(i=0;i<26;i++)
    {
        ci[p].next[i]=-1 ;
    }
    ci[p].like = -1;
    if(ci[p].word !=NULL)
        free(ci[p].word);
        //delete ci[p].word;
    ci[p].word = NULL;
}


int insert(char *str)//插入单词
{
    int pos=0,id,flag = 0,i;
    for(i=0;str[i];i++)
    {
        id=str[i]-'a' ;
        //判断下一个节点不为空
        if(ci[pos].next[id]==-1)
        {
            newnode(++num);
            ci[pos].next[id]=num ;
            flag = 1;
        }
        pos=ci[pos].next[id];
        //pos移向下一个节点
        //ci[pos].pass++;
        //节点值曾一
    }
    if(ci[pos].word == NULL){ //??????????
        ci[pos].word = (char *)malloc(sizeof(char)*(strlen(str)+2));
        strcpy(ci[pos].word,str);
    }
    return pos; //返回单词最终节点的位置
}

//字典树查询，返回节点下标
int search(char *str)
{
    int pos=0,id,i;
    for(i=0;str[i];i++)
    {
        id=str[i]-'a';
        if(ci[pos].next[id]!=-1)
        {
            pos=ci[pos].next[id];
        }
        else 
        {
            //printf("0\n");
            return -1;
        }
    }
    return pos;
    //printf("%d\n",ci[pos].pass);
}
/*
inline void link_point(int p,int q)
{
    ci[p].like = q;
    return ;
}*/

void replace(char *str, int n)
{
    int p = search(str);
    if(p == -1) return;
    if(ci[p].word == NULL ) return;
    if(ci[p].like == -1 ) return;

    while( n-- && ci[p].like != -1)//同音词的替换，最多替换n-1次
    {
        p = ci[p].like;
    }
    if(ci[p].word)
        strcpy(str,ci[p].word);
    else
        while(1) printf("*");
}

int main()
{
    char str1[30],str2[30],say[200];
    char res[50][21];

    int n,m,t,i,j,p1,p2;

    //freopen("d:\\in.txt","r",stdin);

    scanf("%d",&t);
    int id = t;
    //printf("%d\n",t);
    while(t--){
        scanf("%d%d",&n,&m);
        //clear(num);
        num = 0;
        newnode(num);
        for(i=0;i<m;i++){
            scanf("%s%s",str1,str2);
            //printf("%s %s\n",str1,str2);
            p1=insert(str1);
            p2=insert(str2);
            //link_point(p1,p2);
            ci[p1].like = p2; //同音词的链接的建立
        }
        getchar();
        gets(say);
        //puts(say);
        int nr=0;
        for(i=0;say[i]!='\0';i++)
        {
            j=0;
            while( say[i]!='\0' && say[i] != ' ')
            {
                res[nr][j++]=say[i++];
            }
            //printf("j:%d\n",j);
            if(j){
                res[nr][j]='\0';
                nr++;
            }
            if(say[i]=='\0') break;
        }
        //printf("%d\n",nr);
        for(i=0;i<nr;i++)
        {
            //printf("%s\n",res[i]);
            replace(res[i],n-1);
        }

        
        printf("Case #%d:",id - t);
        for(i=0;i<nr;i++)
            printf(" %s",res[i]);
        puts("");
    }
    return 0 ;
}
