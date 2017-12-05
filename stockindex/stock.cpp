#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#define N 600000
using namespace std;

int getRandChar()
{
    int ch;
    ch=rand()%26; //����0-25��ֵ
    ch += 'A' ; //�ɵõ�һ�������ĸ
    //printf("%c",ch);    
    return ch ;
}

int getRandNum()
{
    int num;
    num=rand()%10; //����0-9��ֵ
    //printf("%d",num);
    return num ;
}

//������ĸ
/*char PutLetterIn()
{
    //int i;
    char aa;
    scanf("%c",&aa);   
    //getchar();
    if(aa>='a'&&aa<='z')
    {
      aa-=32;    //�Զ�ת��д�����������ѯ
    }
    //else a-=32;
    //printf("%c\n",a);    
    return aa;  
}*/


int main(int argc,char* argv[])
{
    if(strcmp(argv[1],"--help")==0)    //�����ĵ�
    {
        printf("\nThis program is used to deal with the stock and its code. The detailed usage is as it follows:\n\n\n");
        printf("--adding [FILE] [NUM] : Adding the first letters of pinyins and stock codes of stocks to the file.\n");
        printf("--generate [FILE] [NUM] : Generate specified numbers of random data of stocks in the designated file.\n");
        printf("--search [FILE][PINYIN] : Search for the stock code according to the first letters of pinyins you input.\n\n");
        exit(0);
    } 
    
    if(argc<4)
    {
        printf("\nThe command is not correct, please retype.\nIf you do not know how to type the correct command, you can input \"./stock --help\" to learn the way to input the command.\n\n"); 
        exit(0);  
    }     

    char Letter[15];
    //long stockcode[10];
    char StockCode[7];
    //��������
    char aa[N+1][11]={-1};
    char bb[N+1][7]={-1};
    //char db[1001][11]={-1};
    int a=0,b=0,c=0,i;
    char Let[15];
    char StCode[10];
    char* d=NULL;
    char ans;
    char TempChar;
    int j;
    double start,end;
    double Time=0.0;
    double Time_Sum=0.0;
    srand((unsigned)time(NULL)); 

    
  
    
   
    
    if(strcmp(argv[1],"--add")!=0&&strcmp(argv[1],"--generate")!=0&&strcmp(argv[1],"--search")!=0)
    {
        printf("\nThe command is not correct, please retype.\nIf you do not know how to type the correct command, you can input \"./stock --help\" to learn the way to input the command.\n\n");
    }
    
    if(strcmp(argv[1],"--add")==0)    //������ӣ�Ҫָ��һ��txt�ļ������������
    {    
        FILE * st = fopen(argv[2],"r+");
        if(st==NULL)
        {
            printf("cannot open the file\n");
            exit(0);
        }
        int Num = atoi(argv[3]);
        printf("start adding data!\n");
        fseek(st, 0, SEEK_END);   //�ƶ��ļ�ָ�뵽�ļ�ĩ
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
                  Let[i]-=32;    //�Զ�ת��д�����������ѯ
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
    
    if(strcmp(argv[1],"--generate")==0)    //�������ɣ�Ҫָ��һ��txt�ļ�������������
    {
        //argv[2]="stock.txt";
        FILE * s = fopen(argv[2],"w+");
        start=clock();
        long n = atol(argv[3]);
        for(j=0;j<n;j++)
        {
            string SC;
            a = 3+(rand()%8);
            //srand((unsigned)time(NULL)); 
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

    
    if(strcmp(argv[1],"--search")==0)    //���ݲ��ң�ָ��һ��txt�ļ����в�ѯ��
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
            fscanf(st, "%s %s\n", Letter, StockCode);//ɨ���ȡ����
            //����ƥ��,�����й�Ʊƴ������ĸ����aa���飬���й�Ʊ�������bb����
            
            for(b=0;b<10;b++)
            {
                if(Letter[b]>'Z'||Letter[b]<'A')break;
                aa[a][b]=Letter[b];
                //printf("aa[%d][%d]=%c  ",a,b,aa[a][b]);      //����
            }
        
            //printf("\n");
            
            for(c=0;c<6;c++)
            {
                //  a++;
                bb[a][c]=StockCode[c];
                //printf("bb[0][%d]=%c  ",c,bb[0][c]);
                //printf("bb[%d][%d]=%c  ",a,c,bb[a][c]);      //����
            }        
            a++;
        } 

        d = argv[3];
        int Length=0;
        while(d[i]!=NULL)   
        {
            if(d[i]>='a'&&d[i]<='z')
            {
                d[i]-=32;    //�Զ�ת��д�����������ѯ
            }
            if(d[i]<'A'||d[i]>'z')
            {
                printf("\nPlease enter the correct letters!\n\n");
                exit(0);
                //break;
            }
            i++;
        }
        j=0;
        printf("\n");
        for(i=0;i<12;i++)
        {
            if(d[i]=='\n')
            {
                i--;
                continue;
            }
            start = clock();
            for(a=0;a<N;a++)
            {                   
                if(aa[a][0]==-1)
                {
                    continue; 
                } //��ֹѭ������
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
                    if(d[i+1]==NULL)
                    {  
                        j=1;    //�ж����޲�ѯ������
                        printf("%s ",aa[a]);
                        printf("%s",bb[a]); 
                        printf("\n");

                    }
                    continue;   
                }
                break;
            }
            end = clock();
            Time = (end-start)/CLOCKS_PER_SEC;

        }
        
        if(j==0)
        {
            printf("Sorry, we can not find the result.\n");
        }
        if(j==1)
        {
            printf("\nFinish!\n");
        }      
        printf("\nThe time to search the code is %lf s\n\n",Time);
        fclose(st);
    }

    return 0;
}