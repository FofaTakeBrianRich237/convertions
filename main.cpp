#include "header/menu_sys.h"
#include "header/mecanic.h"
#include<fstream>
using namespace std;


int main()
{
  MESURE * messure;
  int num_messures;
  SPECIALMESURE * sp_messure;
  int sp_num_messures;
  
  ifstream file("data/simple.txt");
  char nature[30];
  char type[30];
  for(int i = 0; file >> nature && file >> type; i++)
  {
    messure[i].nature == nature;
    messure[i].type == type;
  }
  file.close();

  ifstream file("data/special.txt");
  int a, b = 1 ;
  while(file >> a) 
  {
    if(b == 1) sp_num_messures = a;
    else num_messures = a;
    b++;
  }
  file.close();
  main_menu(messure,num_messures,sp_messure,sp_num_messures);
  return 0;
}
