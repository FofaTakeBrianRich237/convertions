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
double meter_to_miles(CONVERTION &convertion);
double miles_to_meter(CONVERTION &convertion);

//---------CAS DES LITRES
#endif