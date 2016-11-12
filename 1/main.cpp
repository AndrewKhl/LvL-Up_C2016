#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define ARR_SIZE 100
using namespace std;
void ERROR()
{cout<<"Котика с таким именем или номером нету!"<<endl<<endl;}
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
 cout<<"Введите имя котика: ";
   //scanf("%s",&CatName);
   cin>>CatName;
 int x=-1;
 for (int i=0; i<ARR_SIZE; i++)
  if (cat[i].name==CatName && cat[i].ok!=0) {x=i; break;}
 if (x!=-1) return x;
 else
 {
  cout<<"Котика с таким именем нету!"<<endl;
  cout<<"Нажмите 1 для повтора ввода"<<endl;
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
 cout<<"Котик по номером "<<x+1<<endl;
 //printf("Имя котика %s\n",cat[x].name);
 cout<<"Имя котика "<<cat[x].name<<endl;
 cout<<"Возраст котика: "<<cat[x].age<<endl;
 if (cat[x].sex==1) cout<<"Это мальчик"<<endl; else cout<<"Это девочка"<<endl;
 cout<<"Злость котика "<<cat[x].angry<<endl;
 cout<<"Столько котик ест "<<cat[x].hungry<<endl;
 cout<<"Столько котик спит "<<cat[x].sleep<<endl<<endl;
}
int PrAge()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"Ваш котик ещё не родился, повторите попытку "<<endl; return PrAge();}
 else
  if (x>200) {cout<<"Ваш котик уже умер, повторите попытку"<<endl; return PrAge();}
  else return x;
}
int PrSex()
{
 int x;
 cin>>x;
 if (x!=0 && x!=1)
  {cout<<"Пол не определён, повторите попытку"<<endl; return PrSex();}
 else return x;
}
int PrAngry()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"Ваш котик возможно мёртв, повторите попытку "<<endl; return PrAngry();}
 else
  if (x>100) {cout<<"Коты не бывают такими злыми, повторите попытку"<<endl; return PrAngry();}
  else return x;
}
int PrHungry()
{
 int x;
 cin>>x;
 if (x<1)
  {cout<<"Ваш котик ещё умрёт от голода, повторите попытку "<<endl; return PrHungry();}
 else return x;
}
int PrSleep()
{
 int x;
 cin>>x;
 if (x<0)
  {cout<<"Кол-во часов не может быть отрицательным, повторите попытку "<<endl; return PrSleep();}
 else
  if (x>24) {cout<<"В часах только 24 часа, повторите попытку"<<endl; return PrSleep();}
  else return x;
}
void func2(Animals *cat)
 {
  if (func1(cat)==ARR_SIZE) cout<<"Нельзя добавить котика!\n";
   else
    {
     for (int i=0; i<ARR_SIZE; i++)
      if (cat[i].ok==0)
       {
        cout<<"Введите имя котика: ";
        //scanf("%s",&cat[i].name);
        cin>>cat[i].name;
        cout<<"Сколько годиков котику? ";
        cat[i].age=PrAge();
        cout<<"Какого пола котик? (1-м, 0-д) ";
        cat[i].sex=PrSex();
        cout<<"Насколько злой ваш котик (в %)? ";
        cat[i].angry=PrAngry();
        cout<<"Сколько кушает ваш котик (в кг)? ";
        cat[i].hungry=PrHungry();
        cout<<"Сколько он спит (в часах)? ";
        cat[i].sleep=PrSleep();
       // printf("Котик %s принят",cat[i].name);
        cout<<"Котик "<<cat[i].name<<" принят"<<endl<<endl;
        cat[i].ok=1;
        break;
       }
    }
 }

void func3(Animals *cat)
{
 cout<<"Вывод кота: 1-по имени, 0-по номеру ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1)
    {cout<<"Введена неверная команда, попробуйте снова"; func3(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func3(cat);
  }
 else
  {
   cout<<"Введите номер котика: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func3(cat);}
  }
  cat[nom].ok=0;
  //printf("Котик %s выкинут",cat[nom].name);
  cout<<"Котик "<<cat[nom].name<<" выкинут"<<endl<<endl;
}

void func5(Animals *cat)
{
 cout<<"Вывод кота: 1-по имени, 0-по номеру ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1) {
  cout<<"Введена неверная команда, попробуйте снова"; func5(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func5(cat);
  }
 else
  {
   cout<<"Введите номер котика: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func5(cat);}
  }
 writeCat(cat,nom);
}

void func6(Animals *cat)
{
  cout<<"Кол-во наших котиков "<<func1(cat)<<endl;
  for (int i=0; i<ARR_SIZE; i++)
   if (cat[i].ok!=0) writeCat(cat,i);
}

void func7()
 { exit(0); }

void func4(Animals *cat)
{
cout<<"Вывод кота: 1-по имени, 0-по номеру ";
 int ok,nom;
 cin>>ok;
 if (ok != 0 && ok != 1) {
  cout<<"Введена неверная команда, попробуйте снова"; func4(cat);}
 if (ok!=0)
  {
   nom = FindCat(cat);
   if (nom == -1) func4(cat);
  }
 else
  {
   cout<<"Введите номер котика: ";
   cin>>nom;
   nom--;
   if (cat[nom].ok==0) {ERROR(); func4(cat);}
  }
 int x;
 cout<<"Что ты хочешь поменять в котике?"<<endl;
 cout<<"1-Имя"<<endl;
 cout<<"2-Кол-во лет"<<endl;
 cout<<"3-Пол"<<endl;
 cout<<"4-Кол-во злости"<<endl;
 cout<<"5-Уровень прожорства"<<endl;
 cout<<"6-Кол-во часов сна"<<endl;
 cin>>x;
 switch(x)
  {
   case 1: { cout<<"Введите имя котика: "; cin>>cat[nom].name; break; }
   case 2: { cout<<"Сколько годиков котику? "; cat[nom].age=PrAge(); break; }
   case 3: { cout<<"Какого пола котик? (1-м, 0-д) "; cat[nom].sex=PrSex(); break; }
   case 4: { cout<<"Насколько злой ваш котик (в %)? "; cat[nom].angry=PrAngry(); break; }
   case 5: { cout<<"Сколько кушает ваш котик (в кг)? "; cat[nom].hungry=PrHungry(); break; }
   case 6: { cout<<"Сколько он спит (в часах)? "; cat[nom].sleep=PrSleep(); break; }
   default : cout<<"Введена неверная команда!"<<endl<<endl; func4(cat);
  }
 cout<<"Команда выполнена!"<<endl;
}
void enter(Animals *cat)
{
 int x;
 cout<<"1 - Вывести кол-во котиков\n";
 cout<<"2 - Взять нового котика\n";
 cout<<"3 - Выкинуть котика\n";
 cout<<"4 - Изменить характеристики котика\n";
 cout<<"5 - Посмотреть котика\n";
 cout<<"6 - Посмотреть всех котиков\n";
 cout<<"7 - Выпустить всех котиков и сбежать\n";
 cout<<"Введите команду: ";
 cin>>x;
 cout<<endl;
 switch (x)
 {
  case 1 : { cout<<"Кол-во наших котиков: "<<func1(cat)<<endl<<endl; break; }
  case 2 : { func2(cat); break; }
  case 3 : { func3(cat); break; }
  case 4 : { func4(cat); break; }
  case 5 : { func5(cat); break; }
  case 6 : { func6(cat); break; }
  case 7 : { func7(); break; }
  default : cout<<"Введена неверная команда!"<<endl<<endl;
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
