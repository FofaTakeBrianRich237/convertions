#ifndef __MENU_SYS_H_
#define __MENU_SYS_H_

#include "mecanic.h"
#include <cstring>

void upper_case(char word[30]);
void main_menu(MESURE * messure,int &num_messures);
//void add_mesure(messure,num_messures);
void display_messures_simple(MESURE * messure,int &num_messures);
void modifORuse_simple (MESURE * messure,int &num_messures,char mesure[30]);
void add_mesure_simple(MESURE * messure,int &num_messures);
void modif_mesure_simple(MESURE * messure,int &num_messures,char mesure[30]);
void modif_mech_simple(MESURE * messure,int modif,int &num_messures,char mesure[30]);
void use_convert_simple(CONVERTION &convertion,char mesure[30],int & source,int & dest,PREFIX prefix);
void source_dest_name(char mesure[30],char name[10],int source_dest_value);
void select_units_simple(char mesure[30],int & source,int & dest);
int sourceTOdest_simple(char mesure[30]);
int situation_simple(int source,int dest);

#endif
