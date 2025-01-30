#include "header/menu_sys.h"
#include "header/mecanic.h"
#include<fstream>
#include<iostream>
using namespace std;


int main()
{

  //-------------variable declaration
  int b; 
  MESURE * messure = (MESURE*) malloc(sizeof(MESURE) * b); // to store messures
  SPECIALMESURE * sp_messure = (SPECIALMESURE*) malloc(sizeof(SPECIALMESURE) * b); // to store data about special convertions
  int num_messures; // to store the number of messures stored in the messure array
  int sp_num_messures; // to store the number of special stored in the sp_messure array
  //-----------------
  
  //-------------------reading data from text file and filling up variable 
    //---------------coping from the size.txt file into num_messures and sp_num_messures
  fstream filed("data/size.txt");
  int a;
  b = 1 ;
  while(filed >> a) 
  {
    if(b == 1) sp_num_messures = a;
    else num_messures = a;
    b++;
  }
  filed.close();
    //------------------

    //-------------coping from the simple.txt file into the messure array
  ifstream file("data/simple.txt");
  for(int i = 0;i < num_messures; i++)
  {
     file >> messure[i].nature >> messure[i].type;
  }
  file.close();
    //--------------

    //--------------coping from the special.txt file into the sp_messure array
  ifstream ofs("data/special.txt");
  for(int i = 0; i < sp_num_messures; i++)
  {
    ofs >> sp_messure[i].con_name  >> sp_messure[i].type  >> sp_messure[i].nature  >> sp_messure[i].intial_unit  >> sp_messure[i].final_unit  >> sp_messure[i].sign_to_use >> sp_messure[i].constant;
  }
  ofs.close();
    //--------------
  //----------------------
  
  //-------------main menu
  main_menu(messure,num_messures,sp_messure,sp_num_messures);
  //-------------

  //---------------writing into the text files to save modification made 
    //---------saving modifs form the messure array into the simple.txt file
  ofstream files("data/simple.txt");
  for(int i = 0; i < num_messures; i++)
  {
    files << messure[i].nature <<" "<< messure[i].type << endl;
  }
  files.close();
    //----------------

    //---------saving modifs form the sp_messure array into the special.txt file
  ofstream ofss("data/special.txt");
  for(int i = 0; i < sp_num_messures; i++)
  {
    ofss << sp_messure[i].con_name <<" " <<sp_messure[i].type <<" "<< sp_messure[i].nature <<" "<< sp_messure[i].intial_unit <<" "<< sp_messure[i].final_unit <<" "<< sp_messure[i].sign_to_use <<" "<< sp_messure[i].constant <<" "<< endl;
  }
  ofss.close();
    //-----------
    
    //-------saving the changes in the number of messures and special convertions stored in the num_messures and sp_num_messures variable into the size.txt file
  ofstream fileds("data/size.txt");
  fileds << sp_num_messures << endl;
  fileds << num_messures;
  fileds.close();
  //------------------------

  //---------freeing allocated memory 
  delete [] messure; // freeing the messure array
  delete [] sp_messure; // freeing the sp_messure array
  //----------------
  
  return 0;
}
