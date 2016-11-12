#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define ARR_SIZE 100
using namespace std;
void ERROR()
{cout<<"������ � ����� ������ ��� ������� ����!"<<endl<<endl;}
struct Animals
 {

  string name;
  int age;
  bool sex;
  int angry;
  int hungry;
  int sleep;
  bool ok;
 };
 int FindCat(Animals *cat)
{
 string CatName;
 cout<<"������� ��� ������: ";
   //scanf("%s",&CatName);
   cin>>CatName;
 int x=-1;
 for (int i=0; i<ARR_SIZE; i++)
  if (cat[i].name==CatName && cat[i].ok!=0) {x=i; break;}
 if (x!=-1) return x;
 else
 {
  cout<<"������ � ����� ������ ����!"<<endl;
  cout<<"������� 1 ��� ������� �����"<<endl;
  int ok;
  cin>>ok;
  if (ok==1) x=FindCat(cat); else return -1;
 }
}
int func1(Animals *cat)
 {
  int kol=0;
  for (int i=0; i<ARR_SIZE; i++)
   if (cat[i].ok!=0) kol++;
  return kol;
 }
void writeCat(Animals *cat, int x)
{
 cout<<"����� �� ������� "<<x+1<<endl;
 //printf("��� ������ %s\n",cat[x].name);
 cout<<"��� ������ "<<cat[x].name<<endl;
 cout<<"������� ������: "<<cat[x].age<<endl;
 if (cat[x].sex==1) cout<<"��� �������"<<endl; else cout<<"��� �������"<<endl;
 cout<<"������ ������ "<<cat[x].angry<<endl;
 cout<<"������� ����� ��� "<<cat[x].hungry<<endl;
 cout<<"������� ����� ���� "<<cat[x].sleep<<endl<<endl;
}
int PrAge()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"��� ����� ��� �� �������, ��������� ������� "<<endl; return PrAge();}
 else
  if (x>200) {cout<<"��� ����� ��� ����, ��������� �������"<<endl; return PrAge();}
  else return x;
}
int PrSex()
{
 int x;
 cin>>x;
 if (x!=0 && x!=1)
  {cout<<"��� �� ��������, ��������� �������"<<endl; return PrSex();}
 else return x;
}
int PrAngry()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"��� ����� �������� ����, ��������� ������� "<<endl; return PrAngry();}
 else
  if (x>100) {cout<<"���� �� ������ ������ �����, ��������� �������"<<endl; return PrAngry();}
  else return x;
}
int PrHungry()
{
 int x;
 cin>>x;
 if (x<1)
  {cout<<"��� ����� ��� ���� �� ������, ��������� ������� "<<endl; return PrHungry();}
 else return x;
}
int PrSleep()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"���-�� ����� �� ����� ���� �������������, ��������� ������� "<<endl; return PrSleep();}
 else
  if (x>24) {cout<<"� ����� ������ 24 ����, ��������� �������"<<endl; return PrSleep();}
  else return x;
}
void func2(Animals *cat)
 {
  if (func1(cat)==ARR_SIZE) cout<<"������ �������� ������!\n";
   else
    {
     for (int i=0; i<ARR_SIZE; i++)
      if (cat[i].ok==0)
       {
        cout<<"������� ��� ������: ";
        //scanf("%s",&cat[i].name);
        cin>>cat[i].name;
        cout<<"������� ������� ������? ";
        cat[i].age=PrAge();
        cout<<"������ ���� �����? (1-�, 0-�) ";
        cat[i].sex=PrSex();
        cout<<"��������� ���� ��� ����� (� %)? ";
        cat[i].angry=PrAngry();
        cout<<"������� ������ ��� ����� (� ��)? ";
        cat[i].hungry=PrHungry();
        cout<<"������� �� ���� (� �����)? ";
        cat[i].sleep=PrSleep();
       // printf("����� %s ������",cat[i].name);
        cout<<"����� "<<cat[i].name<<" ������"<<endl<<endl;
        cat[i].ok=1;
        break;
       }
    }
 }

void func3(Animals *cat)
{
 cout<<"����� ����: 1-�� �����, 0-�� ������ ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1)
    {cout<<"������� �������� �������, ���������� �����"; func3(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func3(cat);
  }
 else
  {
   cout<<"������� ����� ������: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func3(cat);}
  }
  cat[nom].ok=0;
  //printf("����� %s �������",cat[nom].name);
  cout<<"����� "<<cat[nom].name<<" �������"<<endl<<endl;
}

void func5(Animals *cat)
{
 cout<<"����� ����: 1-�� �����, 0-�� ������ ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1) {
  cout<<"������� �������� �������, ���������� �����"; func5(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func5(cat);
  }
 else
  {
   cout<<"������� ����� ������: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func5(cat);}
  }
 writeCat(cat,nom);
}

void func6(Animals *cat)
{
  cout<<"���-�� ����� ������� "<<func1(cat)<<endl;
  for (int i=0; i<ARR_SIZE; i++)
   if (cat[i].ok!=0) writeCat(cat,i);
}

void func7()
 { exit(0); }

void func4(Animals *cat)
{
cout<<"����� ����: 1-�� �����, 0-�� ������ ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1) {
  cout<<"������� �������� �������, ���������� �����"; func4(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func4(cat);
  }
 else
  {
   cout<<"������� ����� ������: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func4(cat);}
  }
 int x;
 cout<<"��� �� ������ �������� � ������?"<<endl;
 cout<<"1-���"<<endl;
 cout<<"2-���-�� ���"<<endl;
 cout<<"3-���"<<endl;
 cout<<"4-���-�� ������"<<endl;
 cout<<"5-������� ����������"<<endl;
 cout<<"6-���-�� ����� ���"<<endl;
 cin>>x;
 switch(x)
  {
   case 1: { cout<<"������� ��� ������: "; cin>>cat[nom].name; break; }
   case 2: { cout<<"������� ������� ������? "; cat[nom].age=PrAge(); break; }
   case 3: { cout<<"������ ���� �����? (1-�, 0-�) "; cat[nom].sex=PrSex(); break; }
   case 4: { cout<<"��������� ���� ��� ����� (� %)? "; cat[nom].angry=PrAngry(); break; }
   case 5: { cout<<"������� ������ ��� ����� (� ��)? "; cat[nom].hungry=PrHungry(); break; }
   case 6: { cout<<"������� �� ���� (� �����)? "; cat[nom].sleep=PrSleep(); break; }
   default : cout<<"������� �������� �������!"<<endl<<endl; func4(cat);
  }
 cout<<"������� ���������!"<<endl;
}
void enter(Animals *cat)
{
 int x;
 cout<<"1 - ������� ���-�� �������\n";
 cout<<"2 - ����� ������ ������\n";
 cout<<"3 - �������� ������\n";
 cout<<"4 - �������� �������������� ������\n";
 cout<<"5 - ���������� ������\n";
 cout<<"6 - ���������� ���� �������\n";
 cout<<"7 - ��������� ���� ������� � �������\n";
 cout<<"������� �������: ";
 cin>>x;
 cout<<endl;
 switch (x)
 {
  case 1 : { cout<<"���-�� ����� �������: "<<func1(cat)<<endl<<endl; break; }
  case 2 : { func2(cat); break; }
  case 3 : { func3(cat); break; }
  case 4 : { func4(cat); break; }
  case 5 : { func5(cat); break; }
  case 6 : { func6(cat); break; }
  case 7 : { func7(); break; }
  default : cout<<"������� �������� �������!"<<endl<<endl;
 }
 enter(cat);
}
int main()
{
setlocale(LC_ALL,"Rus");
Animals cat[ARR_SIZE];
for (int i=0; i<ARR_SIZE; i++)
 cat[i].ok=0;
enter(cat);
getch();
return 0;
}
