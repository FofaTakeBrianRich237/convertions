#include<math.h>
#include<iostream>
#include "../header/mecanic.h"

/*POUR LES CONVERSOINS DE TYPES BASIQUE*/
double Basic_convert(CONVERTION &convertion, int source, int dest, int situation)
{
    convertion.prefixe= (PREFIX)source;
    double convert = 0.0;
    switch (situation)
    {
        //------------situation du kilo
        case 0: //KILO_TO_KILO
        {
            if (convertion.prefixe == 0 && dest == 0)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 1: //KILO_TO_HECTO
        {
            if (convertion.prefixe == 0 && dest == 1)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;
        }
        case 2: //KILO_TO_DECA
        {
            if (convertion.prefixe == 0 && dest == 2)
            {
                convert = convertion.valeur * pow(10, 2);
            }
            break;
        }
        case 3: //KILO_TO_BASE
        {
            if (convertion.prefixe == 0 && dest == 3)
            {
                convert = convertion.valeur * pow(10, 3);
            }
            break;
        }
        case 4: //KILO_TO_DECI
        {
            if (convertion.prefixe == 0 && dest == 4)
            {
                convert = convertion.valeur * pow(10, 4);
            }
            break;
        }
        case 5: //KILO_TO_CENTI
        {
            if (convertion.prefixe == 0 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 5);
            }
            break;
        }
        case 6: //KILO_TO_MILLI
        {
           if (convertion.prefixe == 0 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 6);
            }
            break;
        }

        //------------situation du hecto
        case 7: //HECTO_TO_KILO
        {
            if (convertion.prefixe == 1 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 8: //HECTO_TO_HECTO
        {
            if (convertion.prefixe == 1 && dest == 1)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 9: //HECTO_TO_DECA
        {
            if (convertion.prefixe == 1 && dest == 2)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;
        }
        case 10: //HECTO_TO_BASE
        {
            if (convertion.prefixe == 1 && dest == 3)
            {
                convert = convertion.valeur * pow(10, 2);
            }
            break;
        }
        case 11: //HECTO_TO_DECI
        {
            if (convertion.prefixe == 1 && dest == 4)
            {
                convert = convertion.valeur * pow(10, 3);
            }
            break;
        }
        case 12: //HECTO_TO_CENTI
        {
           if (convertion.prefixe == 1 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 4);
            }
            break;
        }
        case 13: //HECTO_TO_MILLI
        {
            if (convertion.prefixe == 1 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 5);
            }
            break;
        }
        
        //-------------situation DECA
        case 14: //DECA_TO_KILO
        {
            if (convertion.prefixe == 2 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -2);
            }
            break;
        }
        case 15: //DECA_TO_HECTO
        {
            if (convertion.prefixe == 2 && dest == 1)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 16: //DECA_TO_DECA
        {
            if (convertion.prefixe == 2 && dest == 2)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 17: //DECA_TO_BASE
        {
            if (convertion.prefixe == 2 && dest == 3)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;
        }
        case 18: //DECA_TO_DECI
        {
           if (convertion.prefixe == 2 && dest == 4)
            {
                convert = convertion.valeur * pow(10, 2);
            }
            break;
        }
        case 19: //DECA_TO_CENTI
        {
           if (convertion.prefixe == 2 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 3);
            }
            break;
        }
        case 20: //DECA_TO_MILLI
        {
            if (convertion.prefixe == 2 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 4);
            }
            break;
        }
       
        //-------------situation BASE
        case 21: //BASE_TO_KILO
        {
            if (convertion.prefixe == 3 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -3);
            }
            break;
        }
        case 22: //BASE_TO_HECTO
        {
            if (convertion.prefixe == 3 && dest == 1)
            {
                convert = convertion.valeur * pow(10, -2);
            }
            break;
        }
        case 23: //BASE_TO_DECA
        {
            if (convertion.prefixe == 3 && dest == 2)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 24: //BASE_TO_BASE
        {
            if (convertion.prefixe == 3 && dest == 3)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 25: //BASE_TO_DECI
        {
           if (convertion.prefixe == 3 && dest == 4)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;
        }
        case 26: //DECA_TO_CENTI
        {
           if (convertion.prefixe == 3 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 2);
            }
            break;
        }
        case 27: //BASE_TO_MILLI
        {
          if (convertion.prefixe == 3 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 3);
            }
            break;  
        }
        
        //-------------situation DECI
        case 28: //DECI_TO_KILO
        {
            if (convertion.prefixe == 4 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -4);
            }
            break;
        }
        case 29: //DECI_TO_HECTO
        {
            if (convertion.prefixe == 4 && dest == 1)
            {
                convert = convertion.valeur * pow(10, -3);
            }
            break;
        }
        case 30: //DECI_TO_DECA
        {
            if (convertion.prefixe == 4 && dest == 2)
            {
                convert = convertion.valeur * pow(10, -2);
            }
            break;
        }
        case 31: //DECI_TO_BASE
        {
            if (convertion.prefixe == 4 && dest == 3)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 32: //DECI_TO_DECI
        {
           if (convertion.prefixe == 4 && dest == 4)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 33: //DECI_TO_CENTI
        {
           if (convertion.prefixe == 4 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;
        }
        case 34: //DECI_TO_MILLI
        {
          if (convertion.prefixe == 4 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 2);
            }
            break;  
        }
        
        //-------------situation CENTI
        case 35: //CENTI_TO_KILO
        {
            if (convertion.prefixe == 5 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -5);
            }
            break;
        }
        case 36: //CENTI_TO_HECTO
        {
            if (convertion.prefixe == 5 && dest == 1)
            {
                convert = convertion.valeur * pow(10, -4);
            }
            break;
        }
        case 37: //CENTI_TO_DECA
        {
            if (convertion.prefixe == 5 && dest == 2)
            {
                convert = convertion.valeur * pow(10, -3);
            }
            break;
        }
        case 38: //CENTI_TO_BASE
        {
            if (convertion.prefixe == 5 && dest == 3)
            {
                convert = convertion.valeur * pow(10, -2);
            }
            break;
        }
        case 39: //CENTI_TO_DECI
        {
           if (convertion.prefixe == 5 && dest == 4)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 40: //CENTI_TO_CENTI
        {
           if (convertion.prefixe == 5 && dest == 5)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;
        }
        case 41: //CENTI_TO_MILLI
        {
          if (convertion.prefixe == 5 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 1);
            }
            break;  
        }
        
        //-------------situation MILLI
        case 42: //MILLI_TO_KILO
        {
            if (convertion.prefixe == 6 && dest == 0)
            {
                convert = convertion.valeur * pow(10, -6);
            }
            break;
        }
        case 43: //MILLI_TO_HECTO
        {
            if (convertion.prefixe == 6 && dest == 1)
            {
                convert = convertion.valeur * pow(10, -5);
            }
            break;
        }
        case 44: //MILLI_TO_DECA
        {
            if (convertion.prefixe == 6 && dest == 2)
            {
                convert = convertion.valeur * pow(10, -4);
            }
            break;
        }
        case 45: //MILLI_TO_BASE
        {
            if (convertion.prefixe == 6 && dest == 3)
            {
                convert = convertion.valeur * pow(10, -3);
            }
            break;
        }
        case 46: //MILLI_TO_DECI
        {
           if (convertion.prefixe == 6 && dest == 4)
            {
                convert = convertion.valeur * pow(10, -2);
            }
            break;
        }
        case 47: //MILLI_TO_CENTI
        {
           if (convertion.prefixe == 6 && dest == 5)
            {
                convert = convertion.valeur * pow(10, -1);
            }
            break;
        }
        case 48: //MILLI_TO_MILLI
        {
          if (convertion.prefixe == 6 && dest == 6)
            {
                convert = convertion.valeur * pow(10, 0);
            }
            break;  
        }
        
    }	
     return convert;
}

/*CONVERSION DES TYPES DE BASE VERS DES TYPES SPECIAUX*/

//----------CAS DE LA DISTANCE
double meter_to_miles(CONVERTION &convertion, int source)
{
    double convert = 0.0;
    switch(source)
    {
        case 0: //KILOMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 0, 3, 3);
            convert = convert /1609.34;
            break;
        }
        case 1: //HECTOMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 1, 3, 10);
            convert = convert /1609.34;
            break;
        }
        case 2: //DECAMETER_TO_MILES    
        {
            convert = Basic_convert(convertion, 2, 3, 17);
            convert = convert /1609.34;
            break;
        }
        case 3: //METER_TO_MILES
        {
            convert = Basic_convert(convertion, 3, 3, 24);
            convert = convert /1609.34;
            break;
        }
        case 4: //DECIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 4, 3, 31);
            convert = convert /1609.34;
            break;
        }
        case 5: //CENTIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 5, 3, 38);
            convert = convert /1609.34;
            break;
        }
        case 6: //MILLIMETER_TO_MILES
        {
            convert = Basic_convert(convertion, 6, 3, 45);
            convert = convert /1609.34;
            break;
        }
    }
    return convert;
}
double miles_to_meter(CONVERTION &convertion, int dest, double valeur)
{
    double convert = 0.0;
    switch(dest)
    {
        case 0: //MILES_TO_KILOMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 0, 21);
            break;
        }
        case 1: //MILES_TO_HECTOMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 1, 22);
            break;
        }
        case 2: //MILES_TO_DECAMETER   
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 2, 23);
            break;
        }
        case 3: //MILES_TO_METER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 3, 24);
            break;
        }
        case 4: //MILES_TO_DECIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 4, 25);
            break;
        }
        case 5: //MILES_TO_CENTIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 5, 26);
            break;
        }
        case 6: //MILES_TO_MILLIMETER
        {
            convert = valeur *1609.34;
            convertion.valeur = convert;
            convert = (convertion, 3, 6, 27);
            break;
        }
    }
    return convert;  
}

//---------CAS DES MASSES
double gramme_to_livre(CONVERTION &convertion, int source)
{
    double convert = 0.0;
    switch(source)
    {
        case 0: //KILOGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 0, 3, 3);
            convert = convert /453.592;
            break;
        }
        case 1: //HECTOGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 1, 3, 10);
            convert = convert /453.592;
            break;
        }
        case 2: //DECAGRAMME_TO_LIVRE    
        {
            convert = Basic_convert(convertion, 2, 3, 17);
            convert = convert /453.592;
            break;
        }
        case 3: //GRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 3, 3, 24);
            convert = convert /453.592;
            break;
        }
        case 4: //DECIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 4, 3, 31);
            convert = convert /453.592;
            break;
        }
        case 5: //CENTIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 5, 3, 38);
            convert = convert /453.592;
            break;
        }
        case 6: //MILLIGRAMME_TO_LIVRE
        {
            convert = Basic_convert(convertion, 6, 3, 45);
            convert = convert /453.592;
            break;
        }
    }
    return convert;

}

double livre_to_gramme(CONVERTION &convertion, int dest, double valeur)
{
    double convert = 0.0;
    switch(dest)
    {
        case 0: //LIVRE_TO_KILOGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 0, 21);
            break;
        }
        case 1: //LIVRE_TO_HECTOGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 1, 22);
            break;
        }
        case 2: //LIVRE_TO_DECAGRAMME   
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 2, 23);
            break;
        }
        case 3: //LIVRE_TO_GRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 3, 24);
            break;
        }
        case 4: //LIVRE_TO_DECIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 4, 25);
            break;
        }
        case 5: //LIVRE_TO_CENTIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 5, 26);
            break;
        }
        case 6: //LIVRE_TO_MILLIGRAMME
        {
            convert = valeur * 453.592;
            convertion.valeur = convert;
            convert = (convertion, 3, 6, 27);
            break;
        }
    }
    return convert;  
}

//----------CAS DES LITRES
double litre_to_gallon(CONVERTION &convertion, int source)
{
    double convert = 0.0;
    switch(source)
    {
        case 0: //KILOLITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 0, 3, 3);
            convert = convert /3.785;
            break;
        }
        case 1: //HECTOLITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 1, 3, 10);
            convert = convert /3.785;
            break;
        }
        case 2: //DECALITRE_TO_GALLON    
        {
            convert = Basic_convert(convertion, 2, 3, 17);
            convert = convert /3.785;
            break;
        }
        case 3: //LITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 3, 3, 24);
            convert = convert /3.785;
            break;
        }
        case 4: //DECILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 4, 3, 31);
            convert = convert /3.785;
            break;
        }
        case 5: //CENTILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 5, 3, 38);
            convert = convert /3.785;
            break;
        }
        case 6: //MILLILITRE_TO_GALLON
        {
            convert = Basic_convert(convertion, 6, 3, 45);
            convert = convert /3.785;
            break;
        }
    }
    return convert;

}

double gallon_to_litre(CONVERTION &convertion, int dest, double valeur)
{
     double convert = 0.0;
    switch(dest)
    {
        case 0: //LIVRE_TO_KILOGRAMME
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 0, 21);
            break;
        }
        case 1: //GALLON_TO_HECTOLITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 1, 22);
            break;
        }
        case 2: //GALLON_TO_DECALITRE   
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 2, 23);
            break;
        }
        case 3: //GALLON_TO_LITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 3, 24);
            break;
        }
        case 4: //GALLON_TO_DECILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 4, 25);
            break;
        }
        case 5: //GALLON_TO_CENTILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 5, 26);
            break;
        }
        case 6: //GALLON_TO_MILLILITRE
        {
            convert = valeur * 3.785;
            convertion.valeur = convert;
            convert = (convertion, 3, 6, 27);
            break;
        }
    }
    return convert;  
}
