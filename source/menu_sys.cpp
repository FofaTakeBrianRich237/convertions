#include <iostream>
#include <string.h>
#include <typeinfo>
#include "../header/menu_sys.h"
#include "../header/mecanic.h"
#include<fstream>
#include <windows.h>
using namespace std;

//9\033[31m" << "text" << "\033[37m") color code (for red color specifically)


/*
function to change all laters in a word to uppercase leter
char word[30] is the word to be put in capital
*/ 
void upper_case(char word[30])
{
  char capps[30]; // will contain word in capital
    for(int i = 0; word[i] != '\0'; i++) // cross checking the word for non capital letters
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
          capps[i] = word[i] - ('a' - 'A'); 
        }
        else capps[i] = word[i];
    }
    std::cout << "\033[31m" << capps<< "\033[37m" << std::endl;  // to display word in capital and in red color
}



/*
the main menu function 
messure is an array of messures
num_messures is the number of messures store in messure
*/
void main_menu(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  system("cls");
  int  a = 0;
  while(true)// display of choices
  {
    system("cls");
    if(a == 0)  cout << "\033[31m" << "MESSURES" << "\033[37m" << endl << "add a messure or convertion" << endl << "exit" << endl;
    else if(a == 1) cout << "messures" << endl << "\033[31m" << "ADD A MESSURE OR CONVERTION" <<  "\033[37m" << endl <<  "exit" << endl; 
    else cout << "messures"  <<  endl << "add a messure" << endl << "\033[31m" << "EXIT" << "\033[37m" << endl;
    // -------------- input collection from keyboard
    if(GetAsyncKeyState(0x26))  
    {
      if(a == 0) a = 2;
      else if (a == 1) a = 0;
      else  a = 1;
    }
    if(GetAsyncKeyState(0x28))  
    { 
      if(a == 0) a = 1;
      else if (a == 1) a = 2;
      else a = 0;
    }
    if(GetAsyncKeyState(0X0D))  break;
    //-------------- end of colletion
    Sleep(100);
  }
  //-------------use of function depending on the chioce made
  if (a == 0) display_messure(messure,num_messures,sp_messure,sp_num_messures); // to display the different messures store in the messure array
  else if (a == 1) add_mesure(messure,num_messures,sp_messure,sp_num_messures);// to add a special convertion or a simple messure
}



void add_mesure(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  int a = 0;
  while (true)
  {
    system("cls");
    if( GetAsyncKeyState(0X26) || GetAsyncKeyState(0X28))
    {
      if(a == 0) a = 1;
      else a = 0;
    }
    if(GetAsyncKeyState(0X0D)) break;

    if(a == 0) cout << "\033[31m" << "ADD A SIMPLE MESSURE" << "\033[37m" << endl << "add a special convetion" << endl;
    else cout << "add a simple messure" << endl << "\033[31m" << "ADD A SPECIAL CONVERTION" << " \033[37m" << endl;
    Sleep(100);
  }

  if(a == 0) add_mesure_simple(messure,num_messures);
  else add_mesure_special(sp_messure,sp_num_messures);
  main_menu(messure,num_messures,sp_messure,sp_num_messures);
}



/*
fucntion to display simple messures convetions
*/
void display_messures_simple(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  system("cls");
  int a = 0; // use to determine choice
  while (true)
  {
    //---------------input colletion
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
    //---------------end of input collection

    // ----------display of messures store in the messure array and of other choices 
    for (int i = 0; i < num_messures; i++)
    {
      if(a == i) 
      {
        upper_case(messure[i].nature);
        cout << endl;
      }
      else cout << messure[i].nature << endl;
    }
    if(a == num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl << "main menu" << endl;
    else if (a == num_messures + 1) cout << "back" << endl << "\033[31m" << "MAIN MENU" << "\033[37m" << endl;
    else cout << "back" << endl << "main menu" << endl; 
    //---------------end of display of selection
    Sleep(100);
  }

  //---------function calls depending on choice made
  if (a == num_messures + 1) main_menu(messure,num_messures,sp_messure,sp_num_messures);// to return to the main menu
  else if(a == num_messures) display_messure(messure,num_messures,sp_messure,sp_num_messures);
  else modifORuse_simple (messure,num_messures,messure[a].type,sp_messure,sp_num_messures);// to modify or use a convertion
  //----------
}



/* 
fucntoin modify or use a convetion for a certain messure
char mesure[30] is the messure name
*/
void modifORuse_simple (MESURE * messure,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  int a = 0,dest = 0; // dest for destionation messure and source for intial messure in case we are to do a convertion
  CONVERTION convertion;
  while(true)
  {
    system("cls");
    //-----choice input mechanicsm
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
    //----------end of input colletion

    //----display of choices 
    if(a == 0) cout << "\033[31m" << "MODIFY" << "\033[37m" << endl << "use" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 1) cout << "modify" << endl << "\033[31m" <<"USE" << "\033[37m" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 2) cout << "modify" << endl << "use" << endl << "\033[31m" <<"BACK" << "\033[37m" << endl << "back to menu" << endl;
    else cout << "modify" << endl << "use" << endl <<"back"<< endl << "\033[31m" << "BACK TO MENU" << "\033[37m" << endl;
    //-----end of display of choices
    Sleep(100);
  }

  //-------fucntion calls depending on choice made
  if (a == 3) main_menu(messure,num_messures,sp_messure,sp_num_messures);// to return to the main menu
  else if(a == 2) display_messures_simple(messure,num_messures,sp_messure,sp_num_messures); // to return to display of simple messures convertions
  else if(a == 1) use_convert_simple(convertion,mesure,source);// to use a messure
  else modif_mesure_simple(messure,num_messures,mesure,sp_messure,sp_num_messures); // to modify a messure\
  //------------
}



/*
function to add a new messure for simple convetions
*/
void add_mesure_simple(MESURE * messure,int &num_messures)
{
  system("cls");
  int a = 0;
  cout << "Enter the nature" << endl;
  cin.getline(messure[num_messures].nature,30);// to get the nature 
  cout << "Enter the type" << endl;
  cin.getline(messure[num_messures].type,30); // to get the type of the messure
  num_messures++;
}



/*
function to add a new special convert
sp_messures is an array of th SPECIALMESURE type 
sp_numesseres stores the number of elements in sp_messure
*/
void add_mesure_special(SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  cout << "Enter the convetion name" << endl;
  cin.getline(sp_messure[sp_num_messures].con_name,30); // geting the special convertion's name
  cout << "Enter the nature" << endl; 
  cin.getline(sp_messure[sp_num_messures].nature,30); // geting the nature name 
  cout << "Enter the type" << endl;
  cin.getline(sp_messure[sp_num_messures].type,30); // geting the type name
  cout << "Enter the initial unit" << endl; 
  cin.getline(sp_messure[sp_num_messures].intial_unit,30); // geting the initial unit
  cout << "Enter the final unit" << endl;
  cin.getline(sp_messure[sp_num_messures].final_unit,30); // geting the final unit 
  cout << "Enter the constant for the convertion" << endl;
  cin >> sp_messure[sp_num_messures].constant; // geting the constant for the convertion
  cout << "Enter the sign to be used on the constant" << endl;
  cout << "Enter:" << endl << "1  for addition" << endl << "2 for substraction" << endl << "3 for multiplication" << endl << "4 for division" << endl;
  cin >> sp_messure[sp_num_messures].sign_to_use; // geting the sign to be used with the constant upon the values to be cnverted
  //--------------checking validity of the sign choiced
  while (!( sp_messure[sp_num_messures].sign_to_use >= 1 && sp_messure[sp_num_messures].sign_to_use <= 4)) 
  {
    cout << "Invalid entry" << endl;
    cout << "Enter:" << endl << "1  for addition" << endl << "2 for substraction" << endl << "3 for multiplication" << endl << "4 for division" << endl;
    cin >> sp_messure[sp_num_messures].sign_to_use;
  }
  //------------------

}



/*
function for the actual modification of a messure for simple convertions
*/
void modif_mesure_simple(MESURE * messure,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  int a = 0;
  while (true)// display of existing messures store in the messure array
  {
    system("cls");
    //---------input collection
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
    
    //-------display of the messures
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

  //--------function calls depending on choice made
  if(a == num_messures + 1) main_menu(messure,num_messures,sp_messure,sp_num_messures);// to to main menu
  else if(a == num_messures) modifORuse_simple (messure,num_messures,mesure,sp_messure,sp_num_messures); // to return to previous fucntion
  else modif_mech_simple(messure,a,num_messures,mesure);// to modify 
  //--------

  main_menu(messure,num_messures,sp_messure,sp_num_messures);// to return to main menu
}



/*
function for the modification mechanism
modif is the positon in the messure array that contains to messure to be modified
*/
void modif_mech_simple(MESURE * messure,int modif,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  system("cls");
  int b = 0;// to nevigate over chioces
  char answer = 'n';// to collects response on which parameter to be changed
  char inter_nature[30];// variable to temporarily store the new nature name
  char inter_type[30];// variable to temporarily store the new type name
  bool nature_modif = false,type_modif = false; // to determine if yes or no modification a to be made to a given parameter
  cout << "Do you want to change the nature name ? (y/n)" << endl;
  
  //--------answer colletion(y/n)
  cin >> answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin >> answer;
  }
  //--------
  
  // new name entering for nature
  if(answer == 'y') 
  {
    nature_modif = true;
    cout << "Enter new nature name" << endl;
    cin.getline(inter_nature,30);
  }
  //-------------

  cout << "Do you want to change the type name ? (y/n)"  << endl;

  //----------answer collection(y/n)
  cin >> answer;
  while (answer != 'y' && answer != 'n') 
  {
    cout << "Enter 'y' for yes and 'n' for no" << endl;
    cin >> answer;
  }
  //--------

  //-----------new name entering for type
  if(answer == 'y') 
  {
    type_modif = true;
    cout << "Enter new nature name" << endl;
    cin.getline(inter_type,30);
  }


  while (true)// selection of an action to be done
  {
    system("cls");
    //-----------display of possible actions
    if(b == 0) cout << "\033[31m" << "SAVE" << "\033[37m" << "  " << "edit" << "  " << "back" << endl;
    else if(b == 1) cout << "save" << "  " << "\033[31m" << "EDIT" << "\033[37m" << "  " << "back" << endl;
    else cout << "save" << "  " << "edit" << "  " << "\033[31m" << "BACK" << "\033[37m" << endl;
    //----------

    //--------input collections for choice navigation
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
    //-----------

    Sleep(100);
  }
  
  //---------actions depending of choice made
  if(b == 0) // to save changes made
  {
    if(nature_modif) messure[modif].nature == inter_nature;// save changes made to the nature name
    if(type_modif) messure[modif].type == inter_type; // save changes made to th type name
  }
  else if(b == 1) modif_mech_simple(messure,modif,num_messures,mesure);// do not save change and recalls the fucntion itself
  else modif_mesure_simple(messure,num_messures,mesure,sp_messure,sp_num_messures); //return backward
}



/*  
fucntion to use a simple conetion
dest is the destination unit
source is the initial unit
prefix store the different prefixes for convetions
*/
void use_convert_simple(CONVERTION &convertion,char mesure[30],int & dest)
{
  system("cls");
  
  
  char source_name[10];// source unit
  char dest_name[10];// destination unit 
  
  select_units_simple(mesure,convertion,dest); // destination and source unit selection
  
  cout << "enter value" << endl;
  cin >> convertion.valeur;
  //--------assignation of source and destionation units nae=me
  source_dest_name(mesure,source_name,convertion.prefixe);
  source_dest_name(mesure,dest_name,convertion.prefixe);
  //----------
  
  //----to display the answer of the convetions
    //Basic_convet is the function that dose the convetion
  cout << "Convertion made" << endl << endl;
  if(convertion.prefixe !=3 && dest != 3) cout << convertion.valeur << source_name << " " << mesure << " " << "is equal to " << Basic_convert(convertion,dest) << " " << dest_name << " " << mesure << endl;
  else if(convertion.prefixe == 3 && dest != 3) cout << convertion.valeur << " " << mesure << " " << "is equal to " << Basic_convert(convertion,dest) << " " << dest_name << " " << mesure << endl;
  else if(convertion.prefixe != 3 && dest == 3) cout << convertion.valeur << source_name << " " << mesure << " " << "is equal to " << Basic_convert(convertion,dest) << " " << mesure << endl;
  else cout << convertion.valeur << " " << mesure << " " << "is equal to " << Basic_convert(convertion,dest) << " " << mesure << endl;
  while(true) if(GetAsyncKeyState(0x0D)) break;
  //-----------
}



/*
function for the source and destination unit names assignation
source_dest_value is the value that represents a unit in the the convertion enumeration
*/
void source_dest_name(char mesure[30],char name[10],int source_dest_value)
{
  if (source_dest_value == 0) 
  {
    name[0] = 'K';
    name[1] = 'i';
    name[2] = 'l';
    name[3] = 'o';
    name[4] = '\0';
  }
  else if (source_dest_value == 1) 
  {
    name[0] = 'H';
    name[1] = 'e';
    name[2] = 'c';
    name[3] = 't';
    name[4] = 'o';
    name[5] = '\0';

  }
  else if (source_dest_value == 2) 
  {
    name[0] = 'D';
    name[1] = 'e';
    name[2] = 'c';
    name[3] = 'a';
    name[4] = '\0';
  }
  else if (source_dest_value == 3) name = mesure;
  else if (source_dest_value == 4) 
  {
    name[0] = 'C';
    name[1] = 'e';
    name[2] = 'n';
    name[3] = 't';
    name[4] = 'i';
    name[5] = '\0';
  }
  else if (source_dest_value == 5) 
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



/*
function to selcet intial and destination unit
*/
void select_units_simple(char mesure[30],CONVERTION &convertion,int & dest)
{
  cout << "Select initial unit" << endl;
  convertion.prefixe = sourceTOdest(mesure); // to initialise source unit
  cout << "Select final unit" << endl;
  dest = sourceTOdest(mesure);// to determine final unit
}



/*
function for the selcetion of the unit
*/
int sourceTOdest(char mesure[30])
{
  system("cls");
  int a = 0;
  while(true)
  {
    system("cls");
    //------------input colletion
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
    //-----------
    
    //------------display of base unit
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
    Sleep(100);
  }
  //-------------   

  return a;//returns the selected unit
}



/*
display function
messure an array for simple messures
num_mussres the number of messures stored in the messure arry
sp_messure an array fo special convertions
sp_num_messures the number of special convertions stored in sp_messure
*/
void display_messure(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  system("cls");
  int a = 0;
  while(true) // choice making
  {
    system("cls");
    //--------------input collction
    if(GetAsyncKeyState(0x26) || GetAsyncKeyState(0x28)) 
    {
      if(a == 0) a = 1;
      else a = 0;
    } 
    if(GetAsyncKeyState(0x0D)) break;
    //---------------

    //-------------function calls depending on choice made 
    if(a == 1) cout << "SIMPLE MESSUREMENTS" << endl << "special messurements" << endl; // to dislay simple messure
    else cout << "simple messurements" << endl << "SPECIAL MESSUREMENTS" << endl; // to dislay special messure
    //----------
    Sleep(100);
  }

  //---------------function calls depending on choices made
  if(a == 0) display_messures_simple(messure,num_messures,sp_messure,sp_num_messures); // to dislpay simple messuress
  else display_messure_special(messure,num_messures,sp_messure,sp_num_messures);// to display special convertions
  //---------------

  main_menu(messure,num_messures,sp_messure,sp_num_messures);// to return to the main menu 
}



/*
functino to diaplY spcecial convetions
*/
void display_messure_special(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures)
{
  int a = sp_num_messures + 5; // variable for navigation over and choice of convetion
  while (true)
  {
    system("cls");
    //---------input collection
    if(GetAsyncKeyState(0x26))
    {
      if(a == 0) a = sp_num_messures + 6;
      else a -= 1;
    }
    if(GetAsyncKeyState(0x28))
    {
      if(a == sp_num_messures + 6) a = 0;
      else a += 1;
    }
    if(GetAsyncKeyState(0x0D)) break;
    //--------------

    //-----------------choice display
      //-------display of predifine special convertions
    if(a == sp_num_messures + 1) cout << "\033[31m" <<"METER TO MILES" << "\033[37m" << endl << "miles to meter" << endl << "grammes to livre" << endl << "livre to grames" << endl << "litre to gallon" << endl << "gallon ot litre" << endl;
    else if(a == sp_num_messures + 2) cout << "meter to miles" << endl << "\033[31m" <<"MILES OT METER" << "\033[37m" << endl << "grammes to livre" << endl << "livre to grames" << endl << "litre to gallon" << endl << "gallon ot litre" << endl;
    else if(a == sp_num_messures + 3) cout << "meter to miles" << endl << "miles to meter" << endl << "\033[31m" <<"GRAMMES TO LIVRE" << "\033[37m" << endl << "livre to grames" << endl << "litre to gallon" << endl << "gallon ot litre" << endl;
    else if(a == sp_num_messures + 4) cout << "meter to miles" << endl << "miles to meter" << endl << "grammes to livre" << endl << "\033[31m" <<"LIVRE TO GRAMMES" << "\033[37m" << endl << "litre to gallon" << endl << "gallon ot litre" << endl;
    else if(a == sp_num_messures + 5) cout << "meter to miles" << endl << "miles to meter" << endl << "grammes to livre" << endl << "livre to grames" << endl << "\033[31m" <<"LITRE TO GALLON" << "\033[37m" << endl << "gallon ot litre" << endl;
    else if(a == sp_num_messures + 6) cout << "meter to miles" << endl << "miles to meter" << endl << "grammes to livre" << endl << "livre to grames" << endl << "litre to gallon" << endl << "\033[31m" << "GALLON TO LITRE" << "\033[73m" << endl;
    else << "meter to miles" << endl << "miles to meter" << endl << "grammes to livre" << endl << "livre to grames" << endl << "litre to gallon" << endl << "gallon to litre" << endl;
      //---------
      //---------display of special convertions that have been added by users
    for (int i = 0; i < sp_num_messures; i++)
    {
      if(a == i) 
      {
        upper_case(sp_messure[i].con_name);
        cout << endl;
      }
      else cout << sp_messure[i].con_name << endl;
    }
     //-----------
    if(a == sp_num_messures) cout << "\033[31m" << "BACK" << "\033[37m" << endl;
    else cout << "back" << endl;
    //---------------------
    Sleep(100);
  }
  
  //-----------------fucntion call depending on the choices made
  if(a >= 0 && a < sp_num_messures) void mdoifyORuse_special_messure (messure,num_messures,sp_messure,sp_num_messures,a); // to use or modify a special convertion
  else if(a != sp_num_messures) use_predifine_special_convertion(a,sp_num_messures);  // to use a predifine convertion
  //-----------------
}



/*
fucntion to modify or use a special convertion
modif_use store the position of the convertion to use or modify in sp_messure
*/
void mdoifyORuse_special_messure (MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures,int modif_use)/////////
{
  int a = 0;

  while(true)
  {
    system("cls");
    //-----choice input mechanicsm
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
    //----------end of input colletion

    //----display of choices 
    if(a == 0) cout << "\033[31m" << "MODIFY" << "\033[37m" << endl << "use" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 1) cout << "modify" << endl << "\033[31m" <<"USE" << "\033[37m" << endl << "back" << endl << "back to menu" << endl;
    else if(a == 2) cout << "modify" << endl << "use" << endl << "\033[31m" <<"BACK" << "\033[37m" << endl << "back to menu" << endl;
    else cout << "modify" << endl << "use" << endl <<"back"<< endl << "\033[31m" << "BACK TO MENU" << "\033[37m" << endl;
    //-----end of display of choices
    Sleep(100);
  }

  //-------fucntion calls depending on choice made
  if (a == 3) main_menu(messure,num_messures,sp_messure,sp_num_messures);// to return to the main menu
  else if(a == 2) display_messure_special(messure,num_messures,sp_messure,sp_num_messures); // to return to display of simple messures convertions
  else if(a == 1) cout << "&";////////////////////////////////////////////////////////
  else mdoify_special_messure (messure,num_messures,sp_messure,sp_num_messures,modif_use);// to modify special convertion
  //--------------------
}



/*
fucntion to modify a special convertion
*/
void mdoify_special_messure (MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures,int modif)
{
  system("cls");
  //-------intermidiate variable definitions
  char temp_con_name[30]; // store name 
  char temp_type[30]; // store type name 
	char temp_nature[30]; // store nature name 
	char temp_intial_unit[10]; // store inital unit 
  char temp_final_unit[10]; // store final unit 
	int temp_sign_to_use; // store sign
  double temp_constant; // store convertion constant
  //---------------

  char answer = 'n'; // to get answer 
  bool ifname = false,iftype = false, iftintial = false,ifnature = false,iffinal = false,ifconst = false,ifsign = false; // to dertemine which modificatin were made
  

  //---------------------geting the answers and the setting up the intermidiate variable(ici je suis deja tired louis tu vas flex de tout facon)
  cout << "Answer yes or no please (y/n)" << endl << endl;
  cout << "Do yo want to modify the convertion name" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the convertion name" << endl;
    cin >> answer;
  }
  if(answer == 'y')
  {
    ifname = true;
    cout << "enter the new convertion name" << endl;
    cin.getline(temp_con_name,30);
  }

  cout << "Do yo want to modify the nature name" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the nature name" << endl;
    cin >> answer;
  }

  if(answer == 'y')
  {
    ifnature = true;
    cout << "enter the new nature name" << endl;
    cin.getline(temp_nature,30);
  }


  cout << "Do yo want to modify the type name" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    iftype = true;
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the type name" << endl;
    cin >> answer;
  }
  if(answer == 'y')
  {
    cout << "enter the new type name" << endl;
    cin.getline(temp_type,30);
  }


  cout << "Do yo want to modify the initial unit  name" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the initial unit name" << endl;
    cin >> answer;
  }
  if(answer == 'y')
  {
    iftintial = true;
    cout << "enter the new intitial unit name" << endl;
    cin.getline(temp_intial_unit,10);
  }

  cout << "Do yo want to modify the final unit  name" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the final unit name" << endl;
    cin >> answer;
  }
if(answer == 'y')
{
  iffinal = true;
  cout << "enter the new final unit name" << endl;
  cin.getline(temp_final_unit,10);
}

  cout << "Do yo want to modify the convertion constant" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the convetion constant" << endl;
    cin >> answer;
  }
  if(answer == 'y')
  {
    ifconst = true;
    cout << "Enter the new convetion constante" << endl;
    cin >> temp_constant;
  }

  cout << "Do yo want to modify the sign to be used" << endl;
  cin >> answer;
  while (answer != 'n' && answer != 'y')
  {
    cout << "invalid choice" << endl;
    cout << "Answer yes or no please (y/n)" << endl << endl;
    cout << "Do yo want to modify the sign to be used" << endl;
    cin >> answer;
  }
  if(answer == 'y')
  {
    ifsign = true;
    cout << "enter the new sign to be used" << endl << "1  for addition" << endl << "2 for substraction" << endl << "3 for multiplication" << endl << "4 for division" << endl;
    cin >> temp_sign_to_use;
    while (!(temp_sign_to_use >= 1 && temp_sign_to_use <= 4))
    {
      cout << "invalid entry" << endl;
      cout << "enter the new sign to be used" << endl << "1  for addition" << endl << "2 for substraction" << endl << "3 for multiplication" << endl << "4 for division" << endl;
      cin >> temp_sign_to_use;
    }
  }
  //-----------------------

  int a = 0;
  while (true)
  {
    system("cls");
    if(GetAsyncKeyState(0x26)) 
    {
      if(a == 0) a = 2;
      else if(a == 1) a = 0;
      else a = 1;
    }
    if(GetAsyncKeyState(0x26)) 
    {
      if(a == 0) a = 1;
      else if(a == 1) a = 2;
      else a = 0;
    }
    if(GetAsyncKeyState(0x26)) break;

    if(a == 0) cout << "\033[31m" <<"SAVE" << "\033[37m" << endl << "edit" << endl << "back" << endl;
    else if(a == 1) cout << "save" << endl << "\033[31m" <<"EDIT" << "0\33[37m" << endl << "back" << endl;
    else  cout << "save" << endl << "edit" << endl << "\033[31m" << "BACK" << "\033[37m" << endl;

    Sleep(100);
  }

  if (a == 2) mdoifyORuse_special_messure (messure,num_messures,sp_messure,sp_num_messures,modif);
  else if (a == 1) mdoify_special_messure (messure,num_messures,sp_messure,sp_num_messures,modif);
  else
  {
    if(ifname) temp_con_name == sp_messure[modif].con_name;
    if(ifnature) temp_nature == sp_messure[modif].nature;
    if(iftype) temp_type == sp_messure[modif].type;
    if(iftintial) temp_intial_unit == sp_messure[modif].intial_unit;
    if(iffinal) temp_final_unit == sp_messure[modif].final_unit;
    if(ifconst) temp_constant = sp_messure[modif].constant;
    if(ifsign) temp_sign_to_use = sp_messure[modif].sign_to_use;
  }
}



/*
function to use predefined special convertion
*/
void use_predifine_special_convertion(int m,int b)
{
  char name[10];// to store the source or destination unit name

  //------------ffilling the unit name in name
  if(m == b + 1 || a == b + 2) source_dest_name("metre",name,sourceTOdest_simple("metre")); // in case its from or to metre convetion
  else if(m == b + 3 || a == b + 4) source_dest_name("gramme",name,sourceTOdest_simple("gramme")); // in case its from or to gramme convetion
  else if(m == b + 5 || a == b + 6) source_dest_name("litre",name,sourceTOdest_simple("litre")); // in case its from or to litre convetion
  //------------

  //--------------function calls depending on the special convertion choiced
  if(m == b + 1 || m == b + 3  || m == b + 5)  use_predifine_special_convertion_for_source(m,b,name);
  else  use_predifine_special_convertion_for_dest(m,b,name);
  //-----------------
  
}



/*
function
*/
void use_predifine_special_convertion_for_source(int a,int b,char name[10])
{
  CONVERTION convertion;
  cout << "choose unit"  << endl;

  //--------source unit selection
  if(a == b + 1) convertion.prefixe = sourceTOdest("metre");
  else if(a == b + 3) convertion.prefixe = sourceTOdest("grammes");
  else convertion.prefixe = sourceTOdest("litre");
  //----------

  cout << "enter value to be converted" << endl;
  cin >> convertion.valeur; // geting value to convert
  
  //----------converting and displaying result
  if(a == b + 1 && convertion.prefixe == 3 ) cout << convertion.valeur << " metre" << " is equal to " << meter_to_miles(convertion) << " milles" << endl;
  else if(a == b + 1 && convertion.prefixe != 3 ) cout << convertion.valeur << name << " metre" << " is equal to " << meter_to_miles(convertion) << " milles" << endl;
  else if(a == b + 3 && convertion.prefixe == 3) cout << convertion.valeur << " grammes" << " is equal to " << gramme_to_livre(convertion) << " livre" << endl;
  else if(a == b + 3 && convertion.prefixe != 3) cout << convertion.valeur << name << " grammes" << " is equal to " << gramme_to_livre(convertion) << " livre" << endl;
  else if(a == b + 5 && convertion.prefixe == 3) cout << convertion.valeur << " litre" << " is equal to " << litre_to_gallon(convertion) << " gallon" << endl;
  else if(a == b + 5 && convertion.prefixe != 3) cout << convertion.valeur << name << " litre" << " is equal to " << litre_to_gallon(convertion) << " gallon" << endl;
  //----------------
  
  cout << endl < endl << "pres ENTER to proceed" << endl;
  while(true) if(GetAsyncKeyState(0x0D)) break;
}



/*
fucntion 
*/
void use_predifine_special_convertion_for_dest(int a,int b,char name[10])
{
  CONVERTION &convertion;
  int dest;
  double valeur;
  
  //-----destination unit selection
  cout << " choose the final unit" << endl;
  if(a == b + 2) dest = sourceTOdest("metre");
  else if(a == b + 4) dest  = sourceTOdest("grammes");
  else dest  = sourceTOdest("litre");
  //-------

  cout << "enter value to be converted" << endl;
  cin >> valeur;// geting the value to be converted

  //----------converting value and displaying result
  if(a == b + 2 && convertion.prefixe == 3) cout << valeur << " milles" << " is equal to " << miles_to_meter(convertion,dest,valeur) << " metre" << endl;
  else if(a == b + 2 && convertion.prefixe != 3) cout << valeur << " milles" << " is equal to " << miles_to_meter(convertion,dest,valeur) << name << " metre" << endl;
  else if(a == b + 4 && convertion.prefixe == 3) cout << valeur << " livre" << " is equal to " << livre_to_gramme(convertion,dest,valeur) << " metre" << endl;
  else if(a == b + 4 && convertion.prefixe != 3) cout << valeur << " livre" << " is equal to " << livre_to_gramme(convertion,dest,valeur) << name << " metre" << endl;
  else if(a == b + 6 && convertion.prefixe == 3) cout << valeur << " livre" << " is equal to " << gallon_to_litre(convertion,dest,valeur) << " metre" << endl;
  else if(a == b + 6 && convertion.prefixe != 3) cout << valeur << " livre" << " is equal to " << gallon_to_litre(convertion,dest,valeur) << name << " metre" << endl;
  //--------------
  
  cout << endl < endl << "pres ENTER to proceed" << endl;
  while(true) if(GetAsyncKeyState(0x0D)) break;
}


