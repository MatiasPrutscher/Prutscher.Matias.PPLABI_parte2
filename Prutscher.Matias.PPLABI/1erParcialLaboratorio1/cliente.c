#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "datawarehouse.h"
#include "cliente.h"

int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreCliente(eCliente lista[], int tam)
{
    int ubicacion = -1;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            ubicacion = i;
            break;
        }
    }
    return ubicacion;
}

int altaCliente(eCliente lista[], int tam, int* nextId)
{
    int todoOk = 0;
    eCliente aux;
    int index;

    if(lista != NULL && tam > 0 && nextId != NULL)
    {
        index = buscarLibreCliente(lista, tam);
        if(index != -1)
        {
            printf("\nEl id del cliente es: %d\n", *nextId);
            utn_getString("Ingrese el nombre del cliente: ", "Error, reingrese: ", 20, 5, aux.nombre);
            utn_getString("Ingrese el sexo del cliente ('f' femenino 'm' masculino): ", "Error, reingrese: ", 4, 5, &aux.sexo);
            aux.sexo = tolower(aux.sexo);
            while(aux.sexo != 'f' &&  aux.sexo != 'm')
            {
                utn_getString("Error, reingrese el sexo del cliente ('f' femenino 'm' masculino): ", "Error, reingrese: ", 4, 5, &aux.sexo);
                aux.sexo = tolower(aux.sexo);
            }
            aux.isEmpty = 0;
            aux.id = *nextId;
            (*nextId)++;
            lista[index] = aux;
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarClientes(eCliente lista[], int tam)
{
    printf("************** Lista de clientes **************\n");
    printf(" _______________________________________________________\n");
    printf("|\tID\t|\tCliente\t\t|\tSexo\t|\n");
    printf("|_______________|_______________________|_______________|\n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarCliente(lista[i]);
            printf("|_______________|_______________________|_______________|\n");
        }
    }
}

void mostrarCliente(eCliente cliente)
{
    printf("|\t%d\t|  %-20s\t|\t%c\t|\n", cliente.id, cliente.nombre, cliente.sexo);
}

int cargarNombreDeCliente(int id, eCliente lista[], int tam, char nombre[])
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && nombre != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(nombre, lista[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int hardcodearClientes(eCliente lista[], int tam, int cant, int* pLegajo)
{
    int cantidad = 0;

    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}
