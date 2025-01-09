#include <iostream>
#include "../header/display.h"
#include <windows.h>
using namespace std;

//\033[31m" << "1 VS 1" << "\033[37m"  

void main()
{
  int  a = 0;
  while(true)
  {
    if(a == 0)  cout << "\033[31m" << "CONVERTIONS" << "\033[37m" << endl << "add a convertion" << endl << "exit" << endl;
    else if(a == 1) cout << "convertions" << endl << "\033[31m" << "ADD A CONVERTION" <<  "\033[37m" << endl <<  "exit" << endl; 
    else cout << "convertions"  << endl << "add a convertion" << endl << "\033[31m" << "EXIT" << "\033[37m" << endl;
    if(GetAsyncKeyState(VR_UP))  
    {
      if(a ==0) a = 2;
      else if (a == 1) a = 0;
      else a = 1;
    }
    if(GetAsyncKeyState(VR_DOWN))  
    { 
      if(a == 0) a = 1;
      else if (a == 1) a = 2;
      else a = 0;
    }
    if(GetAsyncKeyState(0X0D))  break;
    Sleep(100);
  }
  if(a == 0)
  else if (a == 1)
}


