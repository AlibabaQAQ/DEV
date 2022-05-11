#include<stdio.h>
#include<string.h>
int GetWordNumber(char string[])
{
	int i, in_word, word_num;
    word_num = 0;                
    in_word = 0;                 
    for (i = 0; string[i]; i++) 
    {
        if (string[i] == ' ' || string[i] == ',') 
        { // 检测到空格
            	in_word = 0;        
        } 
        else if (in_word == 0) 
        { // 在单词内
            	word_num++;            
            	in_word = 1;         
		}
	}
    return word_num;
}
int GetCharNumber(char string[])
{
	int sum = 0;
	int i ;
	for(i = 0;string[i] != '\0'; i++)
	{
		if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')|| (string[i] ==' ')|| (string[i] =='\n')|| (string[i] =='\t'))
		{
			sum ++;
		}
	}
	return sum ;
}
int main()
{
	char buff[256];
	char string[10000] = "\0";
	FILE *fp = NULL;
	int sum = 0;  
	char temp1[5],temp2[100];    
	scanf("%s %s",temp1,temp2);
	fp = fopen(temp2,"r");
	
	if(fp == NULL)
	{
		printf("文件读取失败\n");
		return -1;
	}
	while(!feof(fp))
	{
		if(fgets(buff,255,fp) != NULL)
		{ 
			strcat(string,buff);
		}
	} 
	puts(string);
	if(strcmp(temp1,"-w") == 0)
	{
		sum = GetWordNumber(string);
		printf("单词数： %d\n",sum);
	}
	else if(strcmp(temp1,"-c") == 0)
	{
		sum = GetCharNumber(string);
		printf("字符数： %d\n",sum);
	}
}


