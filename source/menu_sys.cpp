#include <iostream>
#include <string.h>
#include "../header/menu_sys.h"
#include <windows.h>
using namespace std;

//\033[31m" << "1 VS 1" << "\033[37m"  

void upper_case(std::string word)
{
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= ('a' - 'A');
        }
    }
    std::cout << "\033[31m" << word << "\033[37m" << std::endl;
}


void main_menu(MESURE * messure,int &num_messures)
{
  int  a = 0;
  while(true)
  {
    system("cls");
    if(a == 0)  cout << "\033[31m" << "MESSURES" << "\033[37m" << endl << "add a messure" << endl << "exit" << endl;
    else if(a == 1) cout << "messures" << endl << "\033[31m" << "ADD A MESSURE" <<  "\033[37m" << endl <<  "exit" << endl; 
    else cout << "messures"  << endl << "add a convertion" << endl << "\033[31m" << "EXIT" << "\033[37m" << endl;
    if(GetAsyncKeyState(0x26))  
    {
      if(a == 0) a = 2;
      else if (a == 1) a = 0;
      else a = 1;
    }
    if(GetAsyncKeyState(0x28))  
    { 
      if(a == 0) a = 1;
      else if (a == 1) a = 2;
      else a = 0;
    }
    if(GetAsyncKeyState(0X0D))  break;
    Sleep(100);
  }
  if (a == 0) display_messures(messure,num_messures);
  else if (a == 1) add_mesure(messure,num_messures);
}

void display_messures(MESURE * messure,int &num_messures)
{
  int a = 0;
  while (true)
  {
    system("cls");
    if(GetAsyncKeyState(0x26))
    {
      if(a == 0) a = num_messures;
      else a -= 1;
    }
    if(GetAsyncKeyState(0x28))
    {
      if(a == num_messures) a = 0;
      else a += 1;
    }
    if(GetAsyncKeyState(0x0D)) break;
    for (int i = 0; i < num_messures; i++)
    {
      if(a == i) cout << upper_case(messure[i].nature) << endl;
      else cout << messure[i].nature << endl;
    }
    if(a == num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl;
    else cout << "back" << endl;
    Sleep(100);
  }
  if (a == num_messures) main_menu(messure,num_messures);
  else modifORuse (messure,num_messures);
}

void modifORuse (MESURE * messure,int &num_messures)
{
  int a = 0;
  while(true)
  {
    system("cls");
    if(GetAsyncKeyState(0x26))
    {
      if(a == 0) a = 3;
      else if(a == 1) a = 0;
      else if(a == 2) a = 1;
      else a = 2;
    }
    if(GetAsyncKeyState(0x28))
    {
      if(a == 0) a = 1;
      else if(a == 1) a = 2;
      else if(a == 2) a = 3;
      else a = 0;
    }
    if(GetAsyncKeyState(0x0D)) break;
    if(a == 0) cout << "\033[31m" << "MODIFY" << "\033[37m" << endl << "use" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 1) cout << "modify" << endl << "\033[31m" <<"USE" << "\033[37m" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 2) cout << "modify" << endl << "use" << endl << "\033[31m" <<"BACK" << "\033[37m" << endl << "back to menu" << endl;
    else cout << "modify" << endl << "use" << endl <<"back"<< endl << "\033[31m" << "BACK TO MENU" << "\033[37m" << endl;
  }
  if (a == 3) main_menu(messure,num_messures);
  else if(a == 2) display_messures(messure,num_messures);
  else if(a == 1) ///////////////// 
  else modif_mesure(messure,num_messures);
}

void add_mesure(MESURE * messure,int &num_messures)
{
  system("cls");
  int a = 0;
  cout << "Enter the nature" << endl;
  cin.getline(messure[num_messures].nature,30);
  cout << "Enter the type" << endl;
  cin.getline(messure[num_messures].type,30);
  num_messures++;
  main_menu(MESURE * messure,int &num_messures);
}

void modif_mesure(MESURE * messure,int &num_messures)
{
  int a = 0;
  while (true)
  {
    system("cls");
    if(GetAsyncKeyState(0x26))
    {
      if(a == 0) a = num_messures + 1;
      else a -= 1;
    }
    if(GetAsyncKeyState(0x28))
    {
      if(a == num_messures + 1) a = 0;
      else a += 1;
    }
    if(GetAsyncKeyState(0x0D)) break;
    for (int i = 0; i < num_messures; i++)
    {
      if(i == 0) cout << "Nature" << "  " << "TYPE" <<endl << endl;
      if(a == i) cout << upper_case(messure[i].nature) << "  " << upper_case(messure[i].type) << endl;
     else cout << messure[i].nature << endl << "  " << messure[i].type;  
    }
    if(a == num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl << "back to menu";
    else if(a == num_messures + 1) cout << "back" << endl <<"\033[31m" << "BACK TO MENU" << "\033[37m" << endl;
    else cout << "back" << endl << "back to menu" << endl;
    Sleep(100);
  }
  if(a == num_messures + 1) main_menu(messure,num_messures);
  else if(a == num_messures) modifORuse (messure,num_messures);
  else modif_mech(messure,a,num_messures);
  main_menu(messure,num_messures);
}

void modif_mech(MESURE * messure,int modif,int &num_messures)
{
  system("cls");
  int b = 0;
  char answer = n;
  char inter_nature[30];
  char inter_type[30];
  bool nature_modif = false,type_modif = false;
  cout << "Do you want to change the nature name ? (y/n)" << endl;
  cin << answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin << answer;
  }
  if(answer == 'y') 
  {
    nature_modif = true;
    cout << "Enter new nature name" << endl;
    cin.getline(inter_nature,30);
  }
  cout << "Do you want to change the type name ? (y/n)"  << endl;
  cin << answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin << answer;
  }
  if(answer == 'y') 
  {
    type_modif = true;
    cout << "Enter new nature name" << endl;
    cin.getline(inter_type,30);
  }
  while (true)
  {
    system("cls");
    if(b == 0) cout << "\033[31m" << "SAVE" << "\033[37m" << "  " << "edit" << "  " << "back" << endl;
    else if(b == 1) cout << "save" << "  " << "\033[31m" << "EDIT" << "\033[37m" << "  " << "back" << endl;
    else cout << "save" << "  " << "edit" << "  " << "\033[31m" << "BACK" << "\033[37m" << endl;
    if(GetAsyncKeyState(0x25))
    {
      if(b == 0) b = 2;
      else if(b == 1) b = 0;
      else b = 1;
    }
    if(GetAsyncKeyState(0x27))
    {
      if(b == 0) b = 1;
      else if (b == 1) b = 2;
      else b = 0;
    }
    if(GetAsyncKeyState(0x0D)) break;
    Sleep(100);
  }
  if(b == 0) 
  {
    if(nature_modif) messure[modif].nature = inter_nature;
    if(type_modif) messure[modif].type = inter_type;
  }
  else if(b == 1) modif_mech(messure,modif);
  else modif_mesure(messure,num_messures);
}

