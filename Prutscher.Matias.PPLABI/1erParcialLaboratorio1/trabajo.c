#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "trabajo.h"

int inicializarTrabajos(eTrabajo lista[], int tam, eMascotas mascotas[], int tamM, eCliente clientes[], int tamC)
{
    int todoOk = 0;

    if(lista != NULL && mascotas != NULL && clientes != NULL && tam > 0 && tamM > 0 && tamC > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        inicializarmascotas(mascotas, tamM, clientes, tamC);
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreT(eTrabajo lista[], int tam, int* index)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                *index = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], eMascotas lista[], eServicio servicios[], int tamT, int tamM, int* nTrabajo, eTipo tipos[], eColor colores[], int tamTtipo, int tamCo, int idMActual, int tamS, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    eTrabajo auxTrabajo;
    int i;

    system("cls");
    printf("******* Alta trabajo *******\n\n");

    if(lista != NULL && tamT > 0 && trabajos != NULL && servicios != NULL)
    {
        buscarLibreT(trabajos, tamT, &i);
        if(i != -1)
        {
            printf("Trabajo numero: %d\n", *nTrabajo);

            mostrarMascotas(lista, tamM, 0, tipos, colores, tamT, tamCo, clientes, tamC);
            utn_getInt("ingrese id de una mascota: ", "Error, reingrese: ", 100, idMActual, 5, &auxTrabajo.idMascota);

            mostrarServicios(servicios, tamS);
            utn_getInt("ingrese id del servicio a realizar: ", "Error, reingrese: ", 20000, 20002, 5, &auxTrabajo.idServicio);

            printf("ingrese la fecha DD/MM/AAAA: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            while((!validarFecha(auxTrabajo.fecha)) && (auxTrabajo.fecha.anio < 2000 && auxTrabajo.fecha.anio >2022))
            {
                printf("Reingrese: ");
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            }

            auxTrabajo.isEmpty = 0;
            auxTrabajo.id = *nTrabajo;
            (*nTrabajo)++;
            trabajos[i] = auxTrabajo;
            todoOk = 1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }


    return todoOk;
}

void mostrarTrabajos(eTrabajo trabajos[], int tamT, eMascotas lista[], int tamM, eServicio servicios[], int tamS, int limpiar)
{
    int hayTrabajos = 0;

    if(limpiar == 1)
    {
        system("cls");
    }
    printf("\t********************************* Lista de trabajos *********************************\n");
    printf(" ___________________________________________________________________________________\n");
    printf("|\t\t\t|\t\t    |\t\t\t|                   |\n");
    printf("|     Nro Trabajo:\t|\t Nombre:    |\t Servicio:\t|  Fecha:\t    |\n");
    printf("|_______________________|___________________|___________________|___________________|\n");
    for(int i = 0; i < tamT; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i], lista, tamM, servicios, tamS);
            printf("|_______________________|___________________|___________________|___________________|\n");
            hayTrabajos = 1;
        }
    }
    if(!hayTrabajos)
    {
        printf("No hay trabajos para mostrar\n");
    }
    printf("\n\n");
}

void mostrarTrabajo(eTrabajo trabajo, eMascotas mascota[], int tamM, eServicio servicios[], int tamS)
{
    char nombre[20];
    char descripcionS[25];

    cargarDescripcionServicio(trabajo.idServicio, servicios, tamS, descripcionS);
    cargarNombreDeMascota(trabajo.idMascota, mascota, tamM, nombre);

    printf("|      %d\t\t|\t %-10s |\t %-10s\t|   %2d/%2d/%4d\t    |\n"
           , trabajo.id
           , nombre
           , descripcionS
           , trabajo.fecha.dia
           , trabajo.fecha.mes
           , trabajo.fecha.anio);
}

int cantidadDeTrabajosPorMascota(eTrabajo trabajo[], eMascotas mascota[], int tamM, eServicio servicios[], int tamS, int tamT, eTipo tipos[], eColor colores[], int tamTipo, int tamCo, int idActual, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int id;

    mostrarMascotas(mascota, tamM, 1, tipos, colores, tamT, tamCo, clientes, tamC);

    utn_getInt("Ingrese el id de la mascota: ", "Error, reingrese: ", 100, idActual, 5, &id);

    printf("\n ___________________________________________________________________________________\n");
    printf("|\t\t\t|\t\t    |\t\t\t|                   |\n");
    printf("|     Nro Trabajo:\t|\t Nombre:    |\t Servicio:\t|  Fecha:\t    |\n");
    printf("|_______________________|___________________|___________________|___________________|\n");

    for(int i = 0; i < tamT; i++)
    {
        if(id == trabajo[i].idMascota)
        {
            mostrarTrabajo(trabajo[i], mascota, tamM, servicios, tamS);
            printf("|_______________________|___________________|___________________|___________________|\n");
            todoOk = 1;
        }
    }

    return todoOk;
}

int precioCantidadDeTrabajosPorMascota(eTrabajo trabajo[], eMascotas mascota[], int tamM, eServicio servicios[], int tamS, int tamT, eTipo tipos[], eColor colores[], int tamTipo, int tamCo, int idActual, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int id;
    float suma = 0;
    int index;

    mostrarMascotas(mascota, tamM, 1, tipos, colores, tamT, tamCo, clientes, tamC);

    utn_getInt("Ingrese el id de la mascota: ", "Error, reingrese: ", 100, idActual, 5, &id);

    printf("\n ___________________________________________________________________________________\n");
    printf("|\t\t\t|\t\t    |\t\t\t|                   |\n");
    printf("|     Nro Trabajo:\t|\t Nombre:    |\t Servicio:\t|  Fecha:\t    |\n");
    printf("|_______________________|___________________|___________________|___________________|\n");

    for(int i = 0; i < tamT; i++)
    {
        if(id == trabajo[i].idMascota)
        {
            mostrarTrabajo(trabajo[i], mascota, tamM, servicios, tamS);
            printf("|_______________________|___________________|___________________|___________________|\n");

            pasarIndex(servicios, tamS, &index, trabajo[i].idServicio);
            suma += servicios[index].precio;
        }
    }
    printf("\nEl total a abonar de los trabajos realizados para dicha mascota es: %.2f\n", suma);
    todoOk = 1;

    return todoOk;
}

int listaPorFecha(eTrabajo trabajo[], eServicio servicios[], int tamS, int tamT)
{
    int todoOk = 0;
    eTrabajo auxTrabajo;
    int index;
    int bandera = 0;

    if(trabajo != NULL && servicios != NULL && tamS > 0 && tamT > 0)
    {
        printf("ingrese la fecha a verificar DD/MM/AAAA: ");
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
        while((!validarFecha(auxTrabajo.fecha)) && (auxTrabajo.fecha.anio < 2000 && auxTrabajo.fecha.anio >2022))
        {
            printf("Reingrese: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
        }

        printf(" _______________________________________________________\n");
        printf("|\tID\t|\tServicio\t|\tPrecio\t|\n");
        printf("|_______________|_______________________|_______________|\n");
        for(int i = 0; i <tamT; i++)
        {
            if(((auxTrabajo.fecha.anio == trabajo[i].fecha.anio) && (auxTrabajo.fecha.mes == trabajo[i].fecha.mes) && (auxTrabajo.fecha.dia == trabajo[i].fecha.dia)) && !trabajo[i].isEmpty)
            {
                pasarIndex(servicios, tamS, &index, trabajo[i].idServicio);
                mostrarServicio(servicios[index]);
                printf("|_______________|_______________________|_______________|\n");
                bandera = 1;
            }
        }
        if(bandera == 0)
        {
            printf("No hay servicios cargados en la fecha ingresada");
        }
    }

    return todoOk;
}

