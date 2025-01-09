#ifndef MECANIC_H_INCLUDED
#define MECANIC_H_INCLUDED

enum PREFIX
{
	YOTTA=0,
	ZETTA,
	EXA,
	PETA,
	TERA,
	GIGA,
	MEGA,
	KILO,
	HECTO,
	DECA,
	DECI,
	CENTI,
	MILLI,
	MICRO,
	NANO,
	PICO,
	FEMTO,
	ATTO,
	ZEPTO,
	YOCTO
};

typedef struct
{
	char type[30];
	char nature[30];
}MESURE; 

typedef struct
{
	MESURE mesure;
	PREFIX prefixe;
}CONVERTION;

void Basic_convert(CONVERTION &convertion);

#endif