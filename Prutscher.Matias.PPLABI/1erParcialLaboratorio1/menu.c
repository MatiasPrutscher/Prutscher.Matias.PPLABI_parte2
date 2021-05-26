#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu()
{
    char opcion;

    printf("************************Menu************************\n\n");
    printf("A. ALTA CLIENTE: ");
    printf("\nB. ALTA MASCOTA: ");
    printf("\nC. MODIFICAR MASCOTA: ");
    printf("\nD. BAJA MASCOTA:: ");
    printf("\nE. ALTA TRABAJO: ");
    printf("\nF. INFORMES: ");
    printf("\nG. SALIR: \n");
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    return opcion;
}

char submenu()
{
    char opcion;

    printf("************************Informes************************\n\n");
    printf("\nA. LISTAR MASCOTAS: ");
    printf("\nB. LISTAR TIPOS: ");
    printf("\nC. LISTAR COLORES: ");
    printf("\nD. LISTAR MASCOTAS DEL COLOR SELECCIONADO POR EL USUARIO: ");
    printf("\nE. LISTAR MASCOTAS DEL TIPO SELECCIONADO POR EL USUARIO: ");
    printf("\nF. LISTAR MASCOTAS DE MENOR EDAD: ");
    printf("\nG. LISTAR MASCOTAS POR TIPO: ");
    printf("\nH. LISTAR MASCOTAS DEL TIPO Y COLOR SELECCIONADO POR EL USUARIO: ");
    printf("\nI. LISTAR COLOR MAS ELEGIDO POR LOS CLIENTES: ");
    printf("\nJ. LISTAR SERVICIOS: ");
    printf("\nK. LISTAR SERVICIOS POR FECHA: ");
    printf("\nL. LISTAR TRABAJOS:  ");
    printf("\nM. LISTAR TRABAJOS POR MASCOTA SELECCIONADA: ");
    printf("\nN. LISTAR TRABAJOS POR MASCOTA SELECCIONADA Y SUMA DE LOS MISMO: ");
    printf("\nX. ATRAS: \n");
    opcion = getchar();
    opcion = tolower(opcion);
    return opcion;
}
