#include<stdio.h>
#include <ctype.h>


int asciiValueToBinary(int asciiInput)//получаем из БУКВЫ 8-ми битный КОД
{
    int res = 0, i = 1, rem;

    while (asciiInput > 0)
    {
        rem = asciiInput % 2;
        res += (i * rem);
        asciiInput /= 2;
        i *= 10;
    }
    return(res);
}

void wordToFile (char (*str))
{
    FILE *fptr;

    fptr = fopen("test.txt","w");
    
    if(fptr == NULL)
    {
       printf("Error!");
    }

    fprintf(fptr,"%s",str);
    fclose(fptr);
}

void fileToWord(int x)
{

    FILE * hi;
    char string[100];
    
    hi = fopen("test.txt","r");
    while(!feof(hi))
    {
        int res = fscanf(hi,"%s",&*string);
        if (res == EOF)
        {
            break;
        }
        
    printf("\nword in binary after read file - %s\n\n",string);
    }
    fclose(hi);
    int count = 0;
    char codeOfWord[100];
    for (int i = 0; i < sizeof(string); i ++) {
        
        if ((string[i] == '1') || (string[i] == '0')) {
            snprintf(codeOfWord, sizeof(codeOfWord), "%s%c", codeOfWord, string[i]);
            count += 1;
        }
//        printf("%c, %s\n",string[i], codeOfWord);
    }
//    printf("\noutput fro func - %s\n", codeOfWord);
//    printf("%d\n", count);
    for (int i = 7; i < count + 1; i +=7) {
        for (int j = i - 7; j < i; j ++) {
            printf("%c", codeOfWord[j]);
        }
        printf("\n");
    }
    
}

int main()
{
    char str[10]="baraban";
    int vs[256]={0};
    
    
    char *string = "BARABAN";//Начальное слово
    printf("word - %s\n\n", string);
    
    char codeOfWord[sizeof(string) * 8];//Выходное слово
    
    int avbReturn = 0;//восьмибитное представление каждой буквы
    int len = 0;//длина (чисто по приколу(for joke))
    int n = 0;

    for (int i = 0; i < sizeof(string)-1; i++) {

        if (string[i]) {
            
            char codeOfWord_local[8];//Объявление оперативной переменной для записи из int в char

            avbReturn = asciiValueToBinary(toascii(string[i]));//собственно это и есть восьмибитное представление буквы

            sprintf(codeOfWord_local, "%d", avbReturn);//Замена типа данных
            snprintf(codeOfWord, sizeof codeOfWord, "%s%s", codeOfWord, codeOfWord_local);//Сложение восьмибитных представление слов в одно большое слово

            len += sprintf(codeOfWord_local, "%d", avbReturn) + 1;//Сумма букв
            printf("%c - %s\n", string[i], codeOfWord_local);//Выврд
        }
    }
    printf("\nword in binary to write - %s\n", codeOfWord);
    wordToFile(codeOfWord);
    fileToWord(n);

    return 0;
}
