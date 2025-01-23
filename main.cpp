#include "header/menu_sys.h"
#include "header/mecanic.h"
#include<fstream>
using namespace std;


int main()
{
  int b;
  MESURE * messure = (MESURE*) malloc(sizeof(MESURE) * b);
  SPECIALMESURE * sp_messure = (SPECIALMESURE*) malloc(sizeof(SPECIALMESURE) * b);
  int num_messures;
  int sp_num_messures;
  

  ifstream file("data/simple.txt");
  for(int i = 0; file >> messure[i].nature && file >> messure[i].type; i++);
  file.close();

  ifstream ofs("data/special.txt");
  for(int i = 0; ofs >> sp_messure[i].con_name && ofs >> sp_messure[i].type && ofs >> sp_messure[i].nature && ofs >> sp_messure[i].intial_unit && ofs >> sp_messure[i].final_unit && ofs >> sp_messure[i].sign_to_use && ofs >> sp_messure[i].constant; i++);
  ofs.close();

  ifstream filed("data/size.txt");
  int a, b = 1 ;
  while(filed >> a) 
  {
    if(b == 1) sp_num_messures = a;
    else num_messures = a;
    b++;
  }
  filed.close();


  main_menu(messure,num_messures,sp_messure,sp_num_messures);


  ofstream files("data/simple.txt");
  for(int i = 0; i < num_messures; i++)
  {
    files << messure[i].nature << messure[i].type << endl;
  }
  files.close();

  ofstream ofss("data/special.txt");
  for(int i = 0; i < sp_num_messures; i++)
  {
    ofss << sp_messure[i].con_name << sp_messure[i].type << sp_messure[i].nature << sp_messure[i].intial_unit << sp_messure[i].final_unit << sp_messure[i].sign_to_use << sp_messure[i].constant << endl;
  }
  ofss.close();

  ofstream fileds("data/size.txt");
  fileds << sp_num_messures << endl;
  fileds << num_messures;
  fileds.close();

  
  return 0;
}
