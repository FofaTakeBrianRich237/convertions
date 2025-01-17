#include <iostream>
#include <string.h>
#include <typeinfo>
#include "../header/menu_sys.h"
#include "../header/mecanic.h"
#include <windows.h>
using namespace std;

//\033[31m" << "1 VS 1" << "\033[37m"  

void upper_case(char word[30])
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
  system("cls");
  int  a = 0;
  while(true)
  {
    system("cls");
    if(a == 0)  cout << "\033[31m" << "SIMPLE MESSURES" << "\033[37m" << endl << "special messures" << endl<< "add a messure" << endl << "exit" << endl;
    else if(a == 2) cout << "simple messures" << endl << "special messueres" << endl << "\033[31m" << "ADD A MESSURE" <<  "\033[37m" << endl <<  "exit" << endl; 
    else if(a == 1) cout << "simple messures" << endl << "\033[31m" << "SPCECIAL MESSURES" << "\033[37m" << endl << "add a messure" << endl << "exist" << endl;
    else cout << "simple messures"  << endl << "special messures" << endl << "add a convertion" << endl << "\033[31m" << "EXIT" << "\033[37m" << endl;
    if(GetAsyncKeyState(0x26))  
    {
      if(a == 0) a = 3;
      else if (a == 1) a = 0;
      else if(a == 2) a = 1;
      else a = 2;
    }
    if(GetAsyncKeyState(0x28))  
    { 
      if(a == 0) a = 1;
      else if (a == 1) a = 2;
      else if(a == 2) a = 3;
      else a = 0;
    }
    if(GetAsyncKeyState(0X0D))  break;
    Sleep(100);
  }
  if (a == 0) display_messures_simple(messure,num_messures);
  //else if (a == 1) 
  //else if (a == 2) add_mesure(messure,num_messures);
}

//void add_mesure(messure,num_messures)simple + special


void display_messures_simple(MESURE * messure,int &num_messures)
{
  system("cls");
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
      if(a == i) 
      {
        upper_case(messure[i].nature);
        cout << endl;
      }
      else cout << messure[i].nature << endl;
    }
    if(a == num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl;
    else cout << "back" << endl;
    Sleep(100);
  }
  if (a == num_messures) main_menu(messure,num_messures);
  else modifORuse_simple (messure,num_messures,messure[a].type);
}

void modifORuse_simple (MESURE * messure,int &num_messures,char mesure[30])
{
  int a = 0,dest = 0,source = 0;
  PREFIX prefix;
  CONVERTION convertion;
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
  else if(a == 2) display_messures_simple(messure,num_messures);
  else if(a == 1) use_convert_simple(convertion,mesure,source,dest,prefix);
  else modif_mesure_simple(messure,num_messures,mesure);
}

void add_mesure_simple(MESURE * messure,int &num_messures)
{
  system("cls");
  int a = 0;
  cout << "Enter the nature" << endl;
  cin.getline(messure[num_messures].nature,30);
  cout << "Enter the type" << endl;
  cin.getline(messure[num_messures].type,30);
  num_messures++;
  main_menu(messure,num_messures);
}

void modif_mesure_simple(MESURE * messure,int &num_messures,char mesure[30])
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
      if(a == i) 
      {
        upper_case(messure[i].nature);
        cout << "  ";
        upper_case(messure[i].type);
        cout << endl;
      }
     else cout << messure[i].nature << endl << "  " << messure[i].type;  
    }
    if(a == num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl << "back to menu";
    else if(a == num_messures + 1) cout << "back" << endl <<"\033[31m" << "BACK TO MENU" << "\033[37m" << endl;
    else cout << "back" << endl << "back to menu" << endl;
    Sleep(100);
  }
  if(a == num_messures + 1) main_menu(messure,num_messures);
  else if(a == num_messures) modifORuse_simple (messure,num_messures,mesure);
  else modif_mech_simple(messure,a,num_messures,mesure);
  main_menu(messure,num_messures);
}

void modif_mech_simple(MESURE * messure,int modif,int &num_messures,char mesure[30])
{
  system("cls");
  int b = 0;
  char answer = 'n';
  char inter_nature[30];
  char inter_type[30];
  bool nature_modif = false,type_modif = false;
  cout << "Do you want to change the nature name ? (y/n)" << endl;
  cin >> answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin >> answer;
  }
  if(answer == 'y') 
  {
    nature_modif = true;
    cout << "Enter new nature name" << endl;
    cin.getline(inter_nature,30);
  }
  cout << "Do you want to change the type name ? (y/n)"  << endl;
  cin >> answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin >> answer;
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
    if(nature_modif) messure[modif].nature == inter_nature;
    if(type_modif) messure[modif].type == inter_type;
  }
  else if(b == 1) modif_mech_simple(messure,modif,num_messures,mesure);
  else modif_mesure_simple(messure,num_messures,mesure);
}

void use_convert_simple(CONVERTION &convertion,char mesure[30],int & source,int & dest,PREFIX prefix)
{
  system("cls");
  int value = 0;
  
  char source_name[10];
  char dest_name[10];
  
  select_units_simple(mesure,source,dest); 
  
  cout << "enter value" << endl;
  cin >> value;
  source_dest_name(mesure,source_name,source);
  source_dest_name(mesure,dest_name,source);
  
  cout << "Convertion made" << endl << endl;
  if(source !=3 && dest != 3) cout << value << source_name << " " << mesure << " " << "is equal to " << Basic_convert(convertion,source, dest,situation_simple(source,dest)) << " " << dest_name << " " << mesure << endl;
  else if(source == 3 && dest != 3) cout << value << " " << mesure << " " << "is equal to " << Basic_convert(convertion,source, dest,situation_simple(source,dest)) << " " << dest_name << " " << mesure << endl;
  else if(source != 3 && dest == 3) cout << value << source_name << " " << mesure << " " << "is equal to " << Basic_convert(convertion,source, dest,situation_simple(source,dest)) << " " << mesure << endl;
  else cout << value << " " << mesure << " " << "is equal to " << Basic_convert(convertion,source, dest,situation_simple(source,dest)) << " " << mesure << endl;
}

void source_dest_name(char mesure[30],char name[10],int source_dest_value)
{
  if (source_dest_value == 0) 
  [
    name[0] = 'K';
    name[1] = 'i';
    name[2] = 'l';
    name[3] = 'o';
    name[4] = '\0';
  ]
  else if (source_dest_value == 0) 
  {
    name[0] = 'H';
    name[1] = 'e';
    name[2] = 'c';
    name[3] = 't';
    name[4] = 'o';
    name[5] = '\0';

  }
  else if (source_dest_value == 0) 
  {
    name[0] = 'D';
    name[1] = 'e';
    name[2] = 'c';
    name[3] = 'a';
    name[4] = '\0';
  }
  else if (source_dest_value == 0) name = mesure;
  else if (source_dest_value == 0) 
  {
    name[0] = 'C';
    name[1] = 'e';
    name[2] = 'n';
    name[3] = 't';
    name[4] = 'i';
    name[5] = '\0';
  }
  else if (source_dest_value == 0) 
  {
    name[0] = 'D';
    name[1] = 'e';
    name[2] = 'c';
    name[3] = 't';
    name[4] = '\0';
  }
  else 
  {
    name[0] = 'M';
    name[1] = 'i';
    name[2] = 'l';
    name[3] = 'l';
    name[4] = 'i';
    name[5] = '\0';
  }
}

void select_units_simple(char mesure[30],int & source,int & dest)
{
  cout << "Select initial unit" << endl;
  source = sourceTOdest_simple(mesure);
  cout << "Select final unit" << endl;
  dest = sourceTOdest_simple(mesure);
}

int sourceTOdest_simple(char mesure[30])
{
  system("cls");
  int a = 0;
  while(true)
  {
    if(GetAsyncKeyState(0x26)) 
    {
      if(a == 0) a = 6;
      else a -= 1;
    }
    if(GetAsyncKeyState(0x28)) 
    {
      if(a == 6) a == 0;
      else a += 1;
    }
    if(GetAsyncKeyState(0x0D)) break;

    if(a == 0) cout << "\033[31m" << "KILO" << "\033[37m" << endl << "hecto" << endl << "deca" << endl << mesure << endl << "deci" << endl << "centi" << endl << "milli" << endl;
    else if (a == 1) cout << "kilo" << endl << "\033[31m" << "HECTO" << "\033[37m" << endl << "deca" << endl << mesure << endl << "deci" << endl << "centi" << endl << "milli" << endl;
    else if(a == 2) cout << "kilo" << endl << "hecto" << endl << "\033[31m" << "DECA" << "\033[37m" << endl << mesure << endl << "deci" << endl << "centi" << endl << "milli" << endl;
    else if (a == 3) 
    {
      cout << "kilo" << endl << "hecto" << endl << "deca" << endl;
      upper_case(mesure); 
      cout << endl << "deci" << endl << "centi" << endl << "milli" << endl;
    }
    else if(a == 4) cout << "kilo" << endl << "hecto" << endl << "deca" << endl << mesure << endl <<  "\033[31m" << "DECI" << "\033[37m" << endl << "centi" << endl << "milli" << endl;
    else if(a == 5) cout << "kilo" << endl << "hecto" << endl << "deca" << endl << mesure << endl << "deci" << endl << "\033[31m" << "CENTI" << "\033[37m" << endl << "milli" << endl;
    else  cout << "kilo" << endl << "hecto" << endl << "deca" << endl << mesure << endl << "deci" << endl << "centi" << endl << "\033[31m" << "MILLI" << "\033[37m" << endl;
  }
  return a;
}

