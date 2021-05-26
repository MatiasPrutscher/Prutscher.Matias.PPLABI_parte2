#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"

int aBisiesto(int anio)
{
    int bisiesto = 0;

    if ( (anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))
    {
        bisiesto = 1;
    }

    return bisiesto;
}


int validarFecha(eFecha fecha)
{
    int todoOk = 0;

    if(aBisiesto(fecha.anio))
    {
        switch(fecha.mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(fecha.dia >= 1 && fecha.dia <= 31)
                {
                    todoOk = 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(fecha.dia >= 1 && fecha.dia <= 30)
                {
                    todoOk = 1;
                }
                break;
            case 2:
                if(fecha.dia >= 1 && fecha.dia <=29)
                {
                    todoOk = 1;
                }
                break;
        }//fin switch(fecha.mes)
    }//if(aBisiesto(fecha.anio))
    else
    {
        switch(fecha.mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(fecha.dia >= 1 && fecha.dia <= 31)
                {
                    todoOk = 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(fecha.dia >= 1 && fecha.dia <= 30)
                {
                    todoOk = 1;
                }
                break;
            case 2:
                if(fecha.dia >= 1 && fecha.dia <=28)
                {
                    todoOk = 1;
                }
                break;
        }//Fin switch(fecha.mes)
    }//Fin else if(aBisiesto(fecha.anio))
    return todoOk;
}//Fin int validarFecha(eFecha fecha)
