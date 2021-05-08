
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void countc(char *file);
void countd(char *file);
int main(int argc, char* argv[])
{
   /* char a[50];
    
    
        char filename[]="/Users/bright/Documents/WordCount/WordCount/%s.txt";
    printf("%s",filename);*/
    char a,b;
    scanf("%c%c",&a,&b);
    if(a=='-'&&b=='c'){
    countc("/Users/bright/Documents/WordCount/WordCount/ww1.txt");
    }
    else if(a=='-'&&b=='w'){
        countd("/Users/bright/Documents/WordCount/WordCount/ww1.txt");
    }
}
void countc(char *file){//读取字符数
    FILE *fp;
    char buffer[500];
    char c;
    int bufferlen;
    int Lastchar = 0; // 上个字符是否是空格(1表示是  0表示不是)
    int charCount=0;
    if((fp=fopen(file,"r"))==NULL){
        printf("文件有错误无法打开");
        exit(0);
    }
    while(fgets(buffer,500,fp)!=NULL){
        bufferlen=strlen(buffer);
        for(int i=0;i<bufferlen;i++){
            c=buffer[i];
            if(c==' ' || c=='\t'){
                Lastchar = 1;
            }
           else if(c!='\n'&&c!='\r'){
                charCount++;
               Lastchar=0;
            }
        }
    }
    fclose(fp);
    printf("字符数：%d\n",charCount);
}
void countd(char *file){//读取单词数
    FILE *fp;
    char buffer[500];
    char c;
    int bufferlen;
    int Lastchar = 0; // 上个字符是否是空格(1表示是  0表示不是)
    int wordCount=0;
    int i;
    if((fp=fopen(file,"r"))==NULL){
        printf("文件有错误无法打开");
        exit(0);
    }
    while(fgets(buffer,500,fp)!=NULL){
        bufferlen=strlen(buffer);
        for(i=0;i<bufferlen;i++){
            c=buffer[i];
            if(c==' ' || c=='\t'){
                if(Lastchar==0){
                    wordCount++;
                }
                Lastchar=1;
            }else if(c!='\n'&&c!='\r'){
                
                Lastchar=0;
            }
        }
        if(Lastchar==0)
            wordCount++;
        Lastchar=1;
    }
    fclose(fp);
    
    
    printf("单词数：%d\n",wordCount);
}


