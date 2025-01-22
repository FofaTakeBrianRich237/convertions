#ifndef MECANIC_H_INCLUDED
#define MECANIC_H_INCLUDED

enum PREFIX
{
	KILO=0,
	HECTO,
	DECA,
	BASE,
	DECI,
	CENTI,
	MILLI
};

typedef struct
{
	char type[30];
	char nature[30];
}MESURE;

typedef struct //  
{
	char con_name[30];
	char type[30];
	char nature[30];
	char intial_unit[10];
    char finial_unit[10];
	int sign_to_use;
	double constant;
}SPECIALMESURE;

typedef struct
{
	double valeur;
	MESURE mesure;
	PREFIX prefixe;
}CONVERTION;

/*POUR LES CONVERSOINS DE TYPES BASIQUE*/
double Basic_convert(CONVERTION &convertion, int source, int dest, int situation);

/*CONVERSION DES TYPES DE BASE VERS DES TYPES SPECIAUX*/

//----------CAS DE LA DISTANCE
double meter_to_miles(CONVERTION &convertion, int source);
double miles_to_meter(CONVERTION &convertion, int dest, double valeur);

//---------CAS DES MASSES
double gramme_to_livre(CONVERTION &convertion, int source);
double livre_to_gramme(CONVERTION &convertion, int dest, double valeur);

//----------CAS DES LITRES
double litre_to_gallon(CONVERTION &convertion, int source);
double gallon_to_litre(CONVERTION &convertion, int dest, double valeur);

#endif