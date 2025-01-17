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
double gramme_to_livre(CONVERSION &convertion, int source);
double livre_to_gramme(CONVERSION &convertion, int dest, double valeur);

//----------CAS DES LITRES
double litre_to_gallon(CONVERSION &convertion, int source);
double gallon_to_litre(CONVERTION &convertion, int dest, double valeur);

#endif