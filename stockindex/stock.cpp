#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#define N 500000
using namespace std;

int getRandChar()
{
    int ch;
    ch=rand()%26; //生成0-25的值
    ch += 'A' ; //可得到一个随机字母
    //printf("%c",ch);    
    return ch ;
}

int getRandNum()
{
    int num;
    num=rand()%10; //生成0-9的值
    //printf("%d",num);
    return num ;
}

//输入字母
char PutLetterIn()
{
    //int i;
    char aa;
    scanf("%c",&aa);   
    //getchar();
    if(aa>='a'&&aa<='z')
    {
      aa-=32;    //自动转大写，方便后续查询
    }
    //else a-=32;
    //printf("%c\n",a);    
    return aa;  
}


int main(int argc,char* argv[])
{
    if(argc<2)
    {
        printf("The command is not correct, please retype.\nIf you do not know how to type the correct command, you can input \"./stock --help\" to learn the way to input the command.\n"); 
        exit(0);  
    }     

    char Letter[15];
    //long stockcode[10];
    char StockCode[7];
    //定义数组
    char aa[N+1][11]={-1};
    char bb[N+1][7]={-1};
    //char db[1001][11]={-1};
    int a=0,b=0,c=0,i;
    char Let[15];
    char StCode[10];
    char d[10];
    char ans;
    char TempChar;
    int j;
    double start,end;
    double Time=0.0;
    double Time_Sum=0.0;

    
    if(strcmp(argv[1],"--help")==0)    //帮助文档
    {
        printf("\nThis program is used to deal with the stock and its code. The detailed usage is as it follows:\n\n\n");
        printf("--adding [FILE] [NUM] : Adding the first letters of pinyins and stock codes of stocks to the file.\n");
        printf("--generate [FILE] [NUM] : Generate specified numbers of random data of stocks in the designated file.\n");
        printf("--search [FILE] : Search for the stock code according to the first letter of pinyins you input.\n\n");
    }   
    
   
    
    if(strcmp(argv[1],"--help")!=0&&strcmp(argv[1],"--add")!=0&&strcmp(argv[1],"--generate")!=0&&strcmp(argv[1],"--search")!=0)
    {
        printf("The command is not correct, please retype.\n If you do not know how to type the correct command, you can input \"./stock --help\" to learn the way to input the command.\n");   
    }
    
    if(strcmp(argv[1],"--add")==0)    //数据添加（要指定一个txt文件与添加数量）
    {    
        FILE * st = fopen(argv[2],"r+");
        if(st==NULL)
        {
            printf("cannot open the file\n");
            exit(0);
        }
        int Num = atoi(argv[3]);
        printf("start adding data!\n");
        fseek(st, 0, SEEK_END);   //移动文件指针到文件末
        for(i=0;i<Num;i++)
        {
            printf("input the first letter of pinyin of the stock\n");
            scanf("%s",&Let);
            printf("input the stockcode of the stock\n");
            scanf("%s",&StCode);  
            for(i=0;i<10;i++) 
            {
                if(Let[i]>='a'&&Let[i]<='z')
                {
                  Let[i]-=32;    //自动转大写，方便后续查询
                }               
            }
            start=clock();
            fwrite("\r\n",1,2,st);         
            fwrite(Let, strlen(Let), 1, st);
            fwrite(" ",1,1,st);
            fwrite(StCode, strlen(StCode), 1, st);   
            end = clock();
            Time = (end - start)/CLOCKS_PER_SEC;
            printf("the time to add data in the designated file is %lf s\n",Time);                   
        }
        printf("Finish!\n");
        fclose(st);
    }
    
    if(strcmp(argv[1],"--generate")==0)    //数据生成（要指定一个txt文件与生成数量）
    {
        //argv[2]="stock.txt";
        FILE * s = fopen(argv[2],"w+");
        start=clock();
        long n = atol(argv[3]);
        for(j=0;j<n;j++)
        {
            string SC;
            a = 3+(rand()%8);
            for(i=0;i<a;i++)
            {
                TempChar = getRandChar();
                SC += TempChar;
            }     
            //printf(" ");
             SC += ' ';
            for(i=0;i<6;i++)
            {    
                TempChar = (getRandNum() + '0');
                SC += TempChar;
            }
            SC += '\n';  
            fprintf(s,"%s",SC.c_str()); 
            SC = "";
        }
        end = clock();
        Time = (end - start)/CLOCKS_PER_SEC;
        printf("Finish!\n");
        printf("the time to generate data in the designated file is %lf s\n",Time);        
        fclose(s);    
    }

    
    if(strcmp(argv[1],"--search")==0)    //数据查找（指定一个txt文件进行查询）
    {   
        FILE * st = fopen(argv[2],"r+");
        if(st==NULL)
        {
            printf("cannot open the file\n");
            exit(0);
        } 
        //printf("aaa");
        fseek(st, 0, SEEK_SET); 
        //printf("start searching\n");
        
        while (!feof(st))
        {
            b=0,c=0;
            fscanf(st, "%s %s\n", Letter, StockCode);//扫描读取数据
            //遍历匹配,将所有股票拼音首字母存入aa数组，所有股票代码存入bb数组
            
            for(b=0;b<10;b++)
            {
                if(Letter[b]>'Z'||Letter[b]<'A')break;
                aa[a][b]=Letter[b];
                //printf("aa[%d][%d]=%c  ",a,b,aa[a][b]);      //测试
            }
        
            //printf("\n");
            
            for(c=0;c<6;c++)
            {
                //  a++;
                bb[a][c]=StockCode[c];
                //printf("bb[0][%d]=%c  ",c,bb[0][c]);
                //printf("bb[%d][%d]=%c  ",a,c,bb[a][c]);      //测试
            }        
            a++;
        } 

        i=0;
        printf("please input the first letter of pinyin of stock(only ONE letter),and input \"enter\" to confirm.\n");            
        for(i=0;i<12;i++)
        {


            d[i] = PutLetterIn();  
            if(i!=0||d[i]!='\n')
            {
                Time_Sum = Time_Sum + Time;
                printf("The time to scan file is %lf s\n",Time);
                printf("The total time of the execution of the program %lf s\n",Time_Sum);
                //continue;
            }

            printf("If you find the result, input '.' to exit.If not,please continue inputing the letter(Input \"Enter\" to confirm.)\n");;    
            if(d[i]=='\n')
            {
                i--;
                continue;
            }
                    //start = clock();
            start = clock();
            if(d[i]=='.')
            {
                printf("bye!\n");
                break;
            }
            for(a=0;a<N;a++)
            {                   
                if(aa[a][0]==-1)
                {
                    continue; 
                } //终止循环条件
                //    for(b=0;b<10;b++){
                if(d[i]!='\n'&&d[i]<'A'&&d[i]>'Z') 
                {
                    continue;
                }
                if(d[i]!=aa[a][i]) 
                {
                    aa[a][0]=-1; 
                    continue;
                }
                else
                {
                    printf("%s ",aa[a]);
                    printf("%s",bb[a]); 
                    printf("\n");
                    end = clock();
                    Time = (end-start)/CLOCKS_PER_SEC; 
                    continue;   
                }

                  // printf("n");
                break;
                    }
                //d[i]=' ';
            
            
            if(ans=='.')
                break;
        }
        fclose(st);
    }

    return 0;
}