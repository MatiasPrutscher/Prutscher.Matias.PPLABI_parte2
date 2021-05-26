#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "trabajo.h"

#define TAM 5
#define TAMTIPO 5
#define TAMCO 5
#define TAMS 3
#define TAMC 3

int main()
{
    int flagAlta = 1;
    int flagCliente = 1; // Dejo la bandera en 1 porque tengo clientes hardcodeados
    char salir;
    char atras;
    int tamT = TAM*3;
    int nextId = 100;
    int nextTrabajo = 1;
    int nextCliente = 8000;

    eTipo tipos[TAMTIPO] = { {1000, "Ave"},
                       {1001, "Perro"},
                       {1002, "Gato"},
                       {1003, "Roedor"},
                       {1004, "Pez"}};

    eColor colores[TAMCO] = {{5000, "Negro"},
                         {5001, "Blanco"},
                         {5002, "Gris"},
                         {5003, "Rojo"},
                         {5004, "Azul"}};

    eServicio servicios[TAMS] = {{20000, "corte", 250},
                                 {20001, "Desparasitado", 300},
                                 {20002, "Castrado", 400}};

    eMascotas mascotas[TAM];
    eTrabajo trabajos[tamT];
    eCliente clientes[TAMC];

    inicializarTrabajos(trabajos, tamT, mascotas, TAM, clientes, TAMC);

    hardcodearClientes(clientes, TAMC, 5, &nextCliente);
    //hardcodearMascotas(mascotas, TAM, 5, &nextId);

    do
    {
        fflush(stdin);
        switch(menu())
        {
             case 'A':
                altaCliente(clientes, TAMC, &nextCliente);
                flagCliente = 1;
                system("pause");
                break;
             case 'B':
                if(flagCliente == 0)
                {
                    printf("Para cargar una mascota, primero debe cargar un cliente\n");
                }
                else
                {
                    if(altaMascotas(mascotas, TAM, &nextId, tipos, colores, TAMTIPO, TAMCO, clientes, TAMC, nextCliente))
                    {
                        printf("Alta exitosa!!\n");
                        flagAlta = 1;
                    }
                    else
                    {
                        printf("Hubo un problema al realizar el alta\n");
                    }
                }
                system("pause");
                break;
            case 'C':
                if(flagAlta == 0)
                {
                    printf("Para modificar una mascota, primero debe cargarla\n");
                }
                else
                {
                    if(!modificarMascota(mascotas, TAM, tipos, colores, TAMTIPO, TAMCO, clientes, TAMC))
                    {
                        printf("Hubo un problema para realizar la modificacion\n");
                    }
                }
                system("pause");
                break;
            case 'D':
                if(flagAlta == 0)
                {
                    printf("Para dar de baja una mascota, primero debe cargarla\n");
                }
                else
                {
                    if(!bajaMascotas(mascotas, TAM, tipos, colores, TAMTIPO, TAMCO, clientes, TAMC))
                    {
                        printf("Hubo un problema para realizar la baja\n");
                    }
                }
                system("pause");
                break;
            case 'E':
                if(flagAlta == 0)
                {
                    printf("Para dar de alta un trabaja, primero debe tener una mascota\n");
                }
                else
                {
                    if(altaTrabajo(trabajos, mascotas, servicios, tamT, TAM, &nextTrabajo, tipos, colores, TAMTIPO, TAMCO, nextId, TAMS, clientes, TAMC))
                    {
                        printf("\nSe dio de alta el trabajo\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error\n");
                    }
                }
                system("pause");
                break;
            case 'F':
                do
                {
                    system("cls");
                    fflush(stdin);
                    switch(submenu())
                    {
                        case 'a':
                            mostrarMascotas(mascotas, TAM, 1, tipos, colores, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'b':
                            mostrarTipos(tipos, TAMTIPO);
                            break;
                        case 'c':
                            mostrarColores(colores, TAMCO);
                            break;
                        case 'd':
                            mostrarMascotasXColorUsuario(mascotas, colores, tipos, TAM, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'e':
                            mostrarMascotasXTipoUsuario(mascotas, colores, tipos, TAM, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'f':
                            mascotaDeMenorEdad(mascotas, colores, tipos, TAM, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'g':
                            mostrarMascotasPorTipo(mascotas,colores, tipos, TAM, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'h':
                            mostrarMascotasPorTipoYColor(mascotas, colores, tipos, TAM, TAMTIPO, TAMCO, clientes, TAMC);
                            break;
                        case 'i':
                            colorMasPopularDeMascotas(mascotas, colores, TAM, TAMCO);
                            break;
                        case 'j':
                            mostrarServicios(servicios, TAMS);
                            break;
                        case 'k':
                            listaPorFecha(trabajos, servicios, TAMS, tamT);
                            break;
                        case 'l':
                            mostrarTrabajos(trabajos, tamT, mascotas, TAM, servicios, TAMS, 1);
                            break;
                        case 'm':
                            cantidadDeTrabajosPorMascota(trabajos, mascotas, TAM, servicios, TAMS, tamT, tipos, colores, TAMTIPO, TAMCO, nextId, clientes, TAMC);
                            break;
                        case 'n':
                            precioCantidadDeTrabajosPorMascota(trabajos, mascotas, TAM, servicios, TAMS, tamT, tipos, colores, TAMTIPO, TAMCO, nextId, clientes, TAMC);
                            break;
                        case 'x':
                            utn_getString("Confirmar salida s/n: ", "Error, reingrese", 2, 5, &atras);
                            break;
                        default:
                            printf("Error, reingrese una opcion valida\n");
                            break;
                    }
                    system("pause");
                }while(atras != 's');
                break;
            case 'G':
                utn_getString("Confirmar salida: ", "Error, reingrese", 2, 5, &salir);
                system("pause");
                break;
            default:
                printf("Error, reingrese una opcion valida\n");
                system("pause");
                break;
        }
        system("cls");
    }while(salir != 's');
    return 0;
}
