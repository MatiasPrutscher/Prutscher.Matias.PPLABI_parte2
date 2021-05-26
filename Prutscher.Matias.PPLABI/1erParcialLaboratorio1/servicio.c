#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

#include "servicio.h"


void mostrarServicios(eServicio sevicios[], int tam)
{
    printf("************** Lista de sevicios **************\n");
    printf(" _______________________________________________________\n");
    printf("|\tID\t|\tServicio\t|\tPrecio\t|\n");
    printf("|_______________|_______________________|_______________|\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarServicio(sevicios[i]);
        printf("|_______________|_______________________|_______________|\n");
    }
}

void mostrarServicio(eServicio servicio)
{
    printf("|\t%d\t|  %-20s\t| \t%.2f  |\n", servicio.id, servicio.descripcion, servicio.precio);
}

int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[])
{
    int todoOk = 0;
    if(servicios != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(desc, servicios[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int pasarIndex(eServicio servicios[], int tam, int* index, int id)
{
    int todoOk = 0;
    if(servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                *index = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

