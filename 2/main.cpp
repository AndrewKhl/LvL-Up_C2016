#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
using namespace std;

int main()
{
setlocale(LC_ALL,"Rus");
FILE *input = fopen("input.txt","r");
FILE *output= fopen("output.txt","w");
if (input == NULL) printf("Ошибка при открытии input\n");
 else printf("Ok\n");
if (output == NULL) printf("Ошибка при открытии output\n");
 else printf("Ok\n");
int size;
fseek(input, 0 , SEEK_END);
size=ftell(input);
cout<<"size="<<size<<endl;
fseek(input, 0 ,SEEK_SET); 
char* buf = (char*) malloc(sizeof(char)*size);
fread(buf, sizeof(char), size, input);
//puts(buf);
long ans=0, kol=0;
for (int i=0; i<size; i++)
 if (buf[i]!=' ') kol++;
 else
  {
   if (ans<kol) ans=kol;
   kol=0;
  }
if (ans<kol) ans=kol;
fprintf(output,"%d",ans);
cout<<"ans="<<ans;
fclose(input);
fclose(output);
getch();
return 0;
}
