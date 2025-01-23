#include<math.h>
#include "../header/mecanic.h"

/*POUR LES CONVERSOINS DE TYPES BASIQUE*/
double Basic_convert(CONVERTION &convertion, int dest)
{
    double convert = 0.0f;

    switch(convertion.prefixe)
    {
        case 0: //KILO_TO_ALL
        {
            convert = convertion.valeur * pow(10, dest);
            break;
        }
        case 1: //HECTO_TO_ALL
        {
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest) convert = convertion.valeur * pow(10, (0));
            else if((int)(convertion.prefixe) < dest) convert = convertion.valeur * pow(10, (dest));
            break;
        }
        case 2: //DECA_TO_ALL
        {
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest)convert = convertion.valeur * pow(10, (0));
            else if((int)(convertion.prefixe) < dest)convert = convertion.valeur * pow(10, (dest));
        }
        case 3: //BASE_TO_ALL
        {
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest)convert = convertion.valeur * pow(10, (0));
            else if((int)(convertion.prefixe) < dest)convert = convertion.valeur * pow(10, (dest));
            break;
        }
        case 4: //DECI_TO_ALL
        {   
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest)convert = convertion.valeur * pow(10, (0));
            else if((int)(convertion.prefixe) < dest)convert = convertion.valeur * pow(10, (dest));
            break;
        }
        case 5: //CENTI_TO_ALL
        {
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest)convert = convertion.valeur * pow(10, (0));
            else if((int)(convertion.prefixe) < dest)convert = convertion.valeur * pow(10, (dest));
            break;
        }
        case 6: //MILLI_TO_ALL
        {
            if((int)(convertion.prefixe) > dest)convert = convertion.valeur * pow(10, (dest*-1));
            else if((int)(convertion.prefixe) == dest)convert = convertion.valeur * pow(10, (0));
            break;
        }
    }
    return convert;
}

/*CONVERSION DES TYPES DE BASE VERS DES TYPES SPECIAUX*/

//----------CAS DE LA DISTANCE
double meter_to_miles(CONVERTION &convertion)
{
    double convert = 0.0f;
    switch(convertion.prefixe)
    {
        case 0: //KILOMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
        case 1: //HECTOMETER_TO_MILES
        {
            convert =Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
        case 2: //DECAMETER_TO_MILES    
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
        case 3: //METER_TO_MILES
        {
            convert = convert /1609.34;
            break;
        }
        case 4: //DECIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
        case 5: //CENTIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
        case 6: //MILLIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /1609.34;
            break;
        }
    }
    return convert;
}

double miles_to_meter(CONVERTION &convertion, int dest, double valeur)
{
    double convert = 0.0f;
    switch(dest)
    {
        case 0: //MILES_TO_KILOMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 1: //MILES_TO_HECTOMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 2: //MILES_TO_DECAMETER   
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 3: //MILES_TO_METER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 4: //MILES_TO_DECIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 5: //MILES_TO_CENTIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 6: //MILES_TO_MILLIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
    }
    return convert;  
}

//---------CAS DES MASSES
double gramme_to_livre(CONVERTION &convertion)
{
    double convert = 0.0f;
    switch(convertion.prefixe)
    {
        case 0: //KILOGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 1: //HECTOGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 2: //DECAGRAMME_TO_LIVRE    
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 3: //GRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 4: //DECIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 5: //CENTIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
        case 6: //MILLIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /453.592;
            break;
        }
    }
    return convert;

}

double livre_to_gramme(CONVERTION &convertion, int dest, double valeur)
{
    double convert = 0.0f;
    switch(dest)
    {
        case 0: //LIVRE_TO_KILOGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 1: //LIVRE_TO_HECTOGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 2: //LIVRE_TO_DECAGRAMME   
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 3: //LIVRE_TO_GRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 4: //LIVRE_TO_DECIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 5: //LIVRE_TO_CENTIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
        case 6: //LIVRE_TO_MILLIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert = Basic_convert(convertion, dest);
            break;
        }
    }
    return convert;  
}

//----------CAS DES LITRES
double litre_to_gallon(CONVERTION &convertion)
{
    double convert = 0.0f;
    switch(convertion.prefixe)
    {
        case 0: //KILOLITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 1: //HECTOLITRE_TO_GALLON
        {
            convert =Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 2: //DECALITRE_TO_GALLON    
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 3: //LITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 4: //DECILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 5: //CENTILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
        case 6: //MILLILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3);
            convert = convert /3.785;
            break;
        }
    }
    return convert;

}

double gallon_to_litre(CONVERTION &convertion, int dest, double valeur)
{
    double convert = 0.0f;
    switch(dest)
    {
        case 0: //GALLON_TO_KILOGRAMME
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 1: //GALLON_TO_HECTOLITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 2: //GALLON_TO_DECALITRE   
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 3: //GALLON_TO_LITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 4: //GALLON_TO_DECILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 5: //GALLON_TO_CENTILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
        case 6: //GALLON_TO_MILLILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convertion.prefixe = (PREFIX)(3);
            convert =  Basic_convert(convertion, dest);
            break;
        }
    }
    return convert;  
}

/*CONVERTION SPECIALE AJOUTEE PAR L'UTILISATEUR*/
double special_convert(SPECIALMESURE &specialmesure, double valeur)
{
    double specialConvert = 0.0f;
    switch(specialmesure.sign_to_use)
    {
        case 1: //do a simple addition with define constant
        {
            specialConvert = valeur+specialmesure.constant;
            break;
        }

        case 2: //do a simple soustraction with define constant
        {
            specialConvert = valeur-specialmesure.constant;
            break;
        }

        case 3: //do a simple multiplication with define constant
        {
            specialConvert = valeur*specialmesure.constant;
            break;
        }

        case 4: //do a simple division with define constant 
        {
            specialConvert = valeur/specialmesure.constant;
            break;
        }
    }
    return specialConvert;
}
