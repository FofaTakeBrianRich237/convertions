#ifndef __MENU_SYS_H_
#define __MENU_SYS_H_


void main_menu(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures);
void display_messures_simple(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures);
void modifORuse_simple (MESURE * messure,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures);
void add_mesure_simple(MESURE * messure,int &num_messures);
void modif_mesure_simple(MESURE * messure,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures);
void modif_mech_simple(MESURE * messure,int modif,int &num_messures,char mesure[30],SPECIALMESURE * sp_messure,int &sp_num_messures);
void use_convert_simple(CONVERTION &convertion,char mesure[30],int & dest);
void source_dest_name(char mesure[30],char name[10],int source_dest_value);
void select_units_simple(char mesure[30],CONVERTION &convertion,int & dest);



void upper_case(char word[30]);
int sourceTOdest(char mesure[30]);
void display_messure(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures);
void add_mesure(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures);



void add_mesure_special(SPECIALMESURE * sp_messure,int &sp_num_messures);
void display_messure_special(MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures);
void mdoifyORuse_special_messure (MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures,int modif_use);
void mdoify_special_messure (MESURE * messure,int &num_messures,SPECIALMESURE * sp_messure,int &sp_num_messures,int modif);
void use_predifine_special_convertion(int m,int b);
void use_predifine_special_convertion_for_source(int a,int b,char name[10]);
void use_predifine_special_convertion_for_dest(int a,int b,char name[10]);

#endif
