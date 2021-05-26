#include "funciones.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;


#endif // SERVICIO_H_INCLUDED

/** \brief Muestra la lista completa de sevicios
 *
 * \param sevicios eServicio[] Lista a mostrar
 * \param tam int tamaño de la lista de sevicios
 * \return void
 *
 */
void mostrarServicios(eServicio sevicios[], int tam);

/** \brief Muestra el servicio especifico
 *
 * \param servicio eServicio color mostrar
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief busca un servicio en especifico a traves del id y carga la descripcion en la variable desc
 *
 * \param id int id a buscar dentro de la lista de servicios
 * \param servicios eServicio[] lista de servicios a buscar
 * \param tam int tamaño de la lista de servicios
 * \param desc char[] carga el nombre del color
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);

/** \brief Busca la posicion del servicio y guarda la misma en el puntero index
 *
 * \param sevicios eServicio[] lista de servicios en la cual buscar
 * \param tam int tamaño de la lista de servicios
 * \param index int* puntero donde guardar la posicion encontrada
 * \param id int id a buscar
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int pasarIndex(eServicio sevicios[], int tam, int* index, int id);
