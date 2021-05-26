#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"


int inicializarmascotas(eMascotas lista[], int tam, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    if(lista != NULL && clientes != NULL && tam > 0 && tamC > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        inicializarClientes(clientes, tamC);
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eMascotas lista[], int tam)
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

int altaMascotas(eMascotas lista[], int tam, int* pId, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC, int nextCliente)
{
    int todoOk = 0;
    eMascotas auxMascota;
    int i;

    system("cls");
    printf("******* Alta MAscota *******\n\n");
    printf("Id: %d\n", *pId);

    if(lista != NULL && tam > 0 && pId)
    {
        i = buscarLibre(lista, tam);
        if(i != -1)
        {
            utn_getString("Ingrese el nombre: ", "Error, reingrese: ", 20, 5, auxMascota.nombre);

            mostrarTipos(tipos, tamT);
            utn_getInt("ingrese el tipo: ", "Error, reingrese: ", 1000, 1004, 5, &auxMascota.idTipo);

            mostrarColores(colores, tamCo);
            utn_getInt("Ingrese el color: ", "Error, reingrese: ", 5000, 5004, 5, &auxMascota.idColor);

            utn_getInt("ingrese la edad (1-15): ", "Error, reingrese: ", 1, 15, 5, &auxMascota.edad);

            mostrarClientes(clientes, tamC);
            utn_getInt("ingrese el cliente: ", "Error, reingrese: ", 8000, nextCliente, 5, &auxMascota.idCliente);

            auxMascota.isEmpty = 0;
            auxMascota.id = *pId;
            (*pId)++;
            lista[i] = auxMascota;
            todoOk = 1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }


    return todoOk;
}

void mostrarMascotas(eMascotas lista[], int tam, int limpiar, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int hayMascotas = 0;

    if(limpiar == 1)
    {
        system("cls");
    }
    printf("\t********************************* Lista de mascotas *********************************\n");
    printf(" ___________________________________________________________________________________________________\n");
    printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\t\t    |\n");
    printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\t Duenio:    |\n");
    printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarMascota(lista[i], tipos, colores, tamT, tamCo, clientes, tamC);
            printf("|_______________|___________________|___________|____________|__________________|___________________|\n");
            hayMascotas = 1;
        }
    }
    if(!hayMascotas)
    {
        printf("No hay mascotas para mostrar\n");
    }
    printf("\n\n");
}

void mostrarMascota(eMascotas mascota, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC)
{
    char descripcionC[20];
    char descripcionT[20];
    char nombreCliente[20];

    cargarDescripcionColor(mascota.idColor, colores, tamCo, descripcionC);
    cargarDescripcionTipo(mascota.idTipo, tipos, tamT, descripcionT);
    cargarNombreDeCliente(mascota.idCliente, clientes, tamC, nombreCliente);

    printf("|      %d\t|\t %-10s |\t %d\t|   %-6s   |\t%-10s\t|\t %-10s |\n"
           , mascota.id
           , mascota.nombre
           , mascota.edad
           , descripcionT
           , descripcionC
           , nombreCliente);
}

int buscarMascota(eMascotas lista[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMascota(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmacion;
    int opcion;


    system("cls");
    printf("*****************Modificar Mascota*****************\n");
    mostrarMascotas(lista, tam, 0, tipos, colores, tamT, tamCo, clientes, tamC);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    indice = buscarMascota(lista, tam, id);
    if(indice != -1)
    {
        printf("La mascota a modificar es:\n");
        printf(" ___________________________________________________________________________________________________\n");
        printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\t\t    |\n");
        printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\t Duenio:    |\n");
        printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
        mostrarMascota(lista[indice], tipos, colores, tamT, tamCo, clientes, tamC);
        printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
        utn_getString("Confirmar? ", "Error, reingrese: ", 4, 5, &confirmacion);
        confirmacion = tolower(confirmacion);
        if(confirmacion == 's')
        {
            utn_getInt("\n1-Modificiar tipo: \n2-Modificiar edad: \n", "Error, reingrese: ", 1, 2, 5, &opcion);
            switch(opcion)
            {
                case 1:
                    mostrarTipos(tipos, tamT);
                    utn_getInt("ingrese el tipo: ", "Error, reingrese: ", 1000, 1004, 5, &lista[indice].idTipo);
                    break;
                case 2:
                    utn_getInt("ingrese la edad (1-15): ", "Error, reingrese: ", 1, 15, 5, &lista[indice].edad);
            }

            todoOk = 1;
            printf("\nSe realizo la modificacion con exito\n\n");
        }
        else
        {
            printf("\nSe cancelo la modificacion por el usuario\n\n");
        }

    }
    else
    {
        printf("El id indicado no existe.\n\n");
    }
    return todoOk;
}

int bajaMascotas(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmacion;


    system("cls");
    printf("*****************Baja Mascota*****************\n");
    mostrarMascotas(lista, tam, 0, tipos, colores, tamT, tamCo, clientes, tamC);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    indice = buscarMascota(lista, tam, id);
    if(indice != -1)
    {
        printf("La mascota a dar de baja es:\n");
        printf(" ___________________________________________________________________________________________________\n");
        printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\t\t    |\n");
        printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\t Duenio:    |\n");
        printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
        mostrarMascota(lista[indice], tipos, colores, tamT, tamCo, clientes, tamC);
        printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
        utn_getString("Confirmar? ", "Error, reingrese: ", 4, 5, &confirmacion);
        confirmacion = tolower(confirmacion);
        if(confirmacion == 's')
        {
            lista[indice].isEmpty = 1;

            todoOk = 1;
            printf("\nSe realizo la modificacion con exito\n\n");
        }
        else
        {
            printf("\nSe cancelo la modificacion por el usuario\n\n");
        }

    }
    else
    {
        printf("El id indicado no existe.\n\n");
    }
    return todoOk;
}

int cargarNombreDeMascota(int id, eMascotas lista[], int tam, char desc[])
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(desc, lista[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarMascotasXColorUsuario(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    char color[20];
    int id = 0;
    int bandera = 0;

    system("cls");

    if(lista != NULL && colores != NULL && tipos != NULL && tam > 0 && tamT > 0 && tamCo > 0)
    {
        mostrarColores(colores, tamCo);
        utn_getString("ingrese el color que desea mostrar: ", "Error, reingrese: ", 20, 5, color);
        if(busquedaIdColor(colores, tamCo, color, &id))
        {
            printf("**************Las mascotas de color %s son:**************\n\n", color);
            printf(" _______________________________________________________________________________\n");
            printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\n");
            printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\n");
            printf("|_______________|___________________|___________|____________|__________________| \n");
            for(int i = 0; i < tam; i++)
            {
                if(lista[i].idColor == id)
                {
                    mostrarMascota(lista[i], tipos, colores, tamT, tamCo, clientes, tamC);
                    bandera = 1;
                }
            }
            printf("|_______________|___________________|___________|____________|__________________| \n");
        }
        else
        {
            printf("\nNo hay coincidencias de color\n");
        }
        if(!bandera)
        {
            printf("No hay mascotas de dicho color\n");
        }
    }
    return todoOk;
}

int mostrarMascotasXTipoUsuario(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    char tipo[20];
    int id = 0;
    int bandera = 0;

    system("cls");

    if(lista != NULL && colores != NULL && tipos != NULL && tam > 0 && tamT > 0 && tamCo > 0)
    {
        mostrarTipos(tipos, tamT);
        utn_getString("ingrese el tipo que desea mostrar: ", "Error, reingrese: ", 20, 5, tipo);
        if(busquedaIdtipo(tipos, tamT, tipo, &id))
        {
            printf("**************Las mascotas de tipo %s son:**************\n\n", tipo);
            printf(" _______________________________________________________________________________\n");
            printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\n");
            printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\n");
            printf("|_______________|___________________|___________|____________|__________________| \n");
            for(int i = 0; i < tam; i++)
            {
                if(lista[i].idTipo == id)
                {
                    mostrarMascota(lista[i], tipos, colores, tamT, tamCo, clientes, tamC);
                    bandera = 1;
                }
            }
            printf("|_______________|___________________|___________|____________|__________________| \n");
        }
        else
        {
            printf("\nNo hay coincidencias de tipo\n");
        }
        if(!bandera)
        {
            printf("No hay mascotas de dicho tipo\n");
        }
    }
    return todoOk;
}

int mostrarMascotasPorTipo(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int haymascotas = 0;
    if(lista != NULL && colores != NULL && tipos != NULL && tam > 0 && tamT >0 && tamCo > 0)
    {
        system("cls");
        for(int i = 0; i < tamT; i++)
        {
            printf("**************Las mascotas de tipo %s son:**************\n\n", tipos[i].descripcion);
            printf(" _______________________________________________________________________________\n");
            printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\n");
            printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\n");
            printf("|_______________|___________________|___________|____________|__________________| \n");

            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && (tipos[i].id == lista[j].idTipo))
                {
                    mostrarMascota(lista[j], tipos, colores, tamT, tamCo, clientes, tamC);
                    haymascotas = 1;
                    todoOk = 1;
                }
            }
            printf("|_______________|___________________|___________|____________|__________________| \n");
            if(haymascotas == 0)
            {
                printf("No hay mascotas de dicho tipo\n\n");
            }
            else
            {
                haymascotas = 0;
                printf("\n\n");
            }

        }
    }
    return todoOk;
}

int mostrarMascotasPorTipoYColor(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    char tipo[20];
    char color[20];
    int idtipo = 0;
    int idcolor = 0;
    int bandera = 0;

    system("cls");

    if(lista != NULL && colores != NULL && tipos != NULL && tam > 0 && tamT >0 && tamCo > 0)
    {
        mostrarTipos(tipos, tamT);
        utn_getString("ingrese el tipo que desea mostrar: ", "Error, reingrese: ", 20, 5, tipo);
        mostrarColores(colores, tamCo);
        utn_getString("ingrese el color que desea mostrar: ", "Error, reingrese: ", 20, 5, color);
        if(busquedaIdtipo(tipos, tamT, tipo, &idtipo))
        {
            if(busquedaIdColor(colores, tamCo, color, &idcolor))
            {
                printf("**************Las mascotas de tipo %s  y color %s son:**************\n\n", tipo, color);
                printf(" _______________________________________________________________________________\n");
                printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\n");
                printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\n");
                printf("|_______________|___________________|___________|____________|__________________| \n");
                for(int i = 0; i < tam; i++)
                {
                    if(lista[i].idTipo == idtipo)
                    {
                        mostrarMascota(lista[i], tipos, colores, tamT, tamCo, clientes, tamC);
                        bandera = 1;
                    }
                }
                printf("|_______________|___________________|___________|____________|__________________| \n");
            }
            else
            {
                printf("\nNo hay coincidencias de color\n");
            }
        }
        else
        {
            printf("\nNo hay coincidencias de tipo\n");
        }
        if(!bandera)
        {
            printf("No hay mascotas de dicho tipo y color\n");
        }
    }
    return todoOk;
}

int colorMasPopularDeMascotas(eMascotas lista[], eColor colores[], int tam, int tamCo)
{
    int todoOk = 0;
    int contador[tamCo];
    int mayor = 0;


    for(int i = 0; i < tamCo; i++)
    {
        contador[i] = 0;
        for(int j = 0; j < tam; j++)
        {
            if(lista[j].isEmpty == 0 && (lista[j].idColor == colores[i].id))
            {
                contador[i]++;
            }
        }
        if(i == 0 || mayor < contador[i])
        {
            mayor = contador[i];
        }
    }
    printf("************** Colores Mas populares **************\n");
    printf("Con la cantidad de: %d\n", mayor);
    printf(" _______________________________________\n");
    printf("|\tID\t|\tColor\t\t|\n");
    printf("|_______________|_______________________|\n");
    for(int k = 0; k <tamCo; k++)
    {
        if(mayor == contador[k])
        {
            mostrarColor(colores[k]);
            printf("|_______________|_______________________|\n");
        }
    }

    return todoOk;
}

int mascotaDeMenorEdad(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int menor = 0;

    if(lista != NULL && colores != NULL && tipos != NULL && clientes != NULL && tam > 0 && tamT > 0 && tamCo > 0 && tamC > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(i == 0 || menor > lista[i].edad)
            {
                menor = lista[i].edad;
            }
        }
        printf("************** Mascotas de menor edad **************\n");
        printf("Con la edad de: %d\n", menor);
        printf(" ___________________________________________________________________________________________________\n");
        printf("|\t\t|\t\t    |\t\t|            |\t\t\t|\t\t    |\n");
        printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo:     |\t Color:\t\t|\t Duenio:    |\n");
        printf("|_______________|___________________|___________|____________|__________________|___________________| \n");
        for(int j = 0; j <tam; j++)
        {
            if(menor == lista[j].edad)
            {
                mostrarMascota(lista[j], tipos, colores, tamT, tamCo, clientes, tamC);
                printf("|_______________|___________________|___________|____________|__________________|___________________|\n");
            }
        }

    }
    return todoOk;
}

