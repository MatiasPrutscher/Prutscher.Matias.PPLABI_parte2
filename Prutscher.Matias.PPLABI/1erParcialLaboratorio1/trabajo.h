#include "mascotas.h"
#include "servicio.h"
#include "fecha.h"
#include "menu.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa todos los trabajos y hace el llamado para inicializar las mascotas
 *
 * \param lista eTrabajo[] lista a inicializar
 * \param tam int tamaño de la lista a inicializar
 * \param mascotas eMascotas[] lista de mascotas a pasar
 * \param tamM int tamaño de la lista de mascotas
 * \param clientes eCliente[] lista de clientes a pasar
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tam, eMascotas mascotas[], int tamM, eCliente clientes[], int tamC);

/** \brief recibe la lista de trabajos, busca un lugar libre para completar y devuelve el index de dicho lugar
 *
 * \param lista eTrabajo[] lista en la que buscar
 * \param tam int tamaño de la lista en la que buscar
 * \return devuelve -1 si no hay lugar y sino el index
 *
 */
int buscarLibreT(eTrabajo lista[], int tam, int* index);

/** \brief Le pide al usuario todos los datos para dar de alta a un trabajo
 *
 * \param trabajos eTrabajo[] lista a dar de alta
 * \param lista eMascotas[] muestra las mascotas a elegir
 * \param servicios eServicio[] muestra el servicio a elegir
 * \param tamT int tamaño de la lista de trabajos
 * \param tamM int tamaño de la lista de mascotas
 * \param nTrabajo int* puntero al siguiente trabajo a cargar
 * \param tipos eTipo[] lista de tipos para mostrar la lista de mascotas
 * \param colores eColor[] lista de colores para mostrar la lista de mascotas
 * \param tamTipo int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param idMActual int id actual de la lista de mascotas, evita que ingresen una mascota no cargada
 * \param tamS int tamaño de la lista de servicios
 * \param clientes eCliente[] lista de clientes para mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int altaTrabajo(eTrabajo trabajos[], eMascotas lista[], eServicio servicios[], int tamT, int tamM, int* nTrabajo, eTipo tipos[], eColor colores[], int tamTipo, int tamCo, int idMActual, int tamS, eCliente clientes[], int tamC);

/** \brief Muestra la lista completa de trabajos
 *
 * \param trabajos eTrabajo[] Lista a mostrar
 * \param tamT int tamaño de la lista de trabajos
 * \param lista eMascotas[] lista de mascotas para mostrar el nombre en vez del id
 * \param tamM int tamaño de la lista de mascotas
 * \param lista eMascotas[] lista de servicios para mostrar el servicio en vez del id
 * \param tamS int tamaño de la lista de servicios
 * \param limpiar int si se pasa 1 limpia la pantalla o en caso contrario pasar 0
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[], int tamT, eMascotas lista[], int tamM, eServicio servicios[], int tamS, int limpiar);

/** \brief Muestra una sola trabajo
 *
 * \param trabajo eTrabajo trabajo a mostrar
 * \param mascota eMascotas[] lista de mascotas para mostrar la descripcion en vez del id
 * \param tamM int tamaño de la lista de mascotas
 * \param servicios eServicio[] lista de servicios para mostrar la descripcion en vez del id
 * \param tamS int tamaño de la lista de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eMascotas mascota[], int tamM, eServicio servicios[], int tamS);

/** \brief muestra la lista de mascotas, se elige una por id y muestra todos los trabajos que se le realizaron
 *
 * \param trabajo eTrabajo[] lista de trabajos
 * \param mascota eMascotas[] lista de mascotas
 * \param tamM int tamaño de la lista de mascotas
 * \param servicios eServicio[] lista de servicios
 * \param tamS int tamaño de la lista de servicios
 * \param tamT int tamaño de la lista de trabajos
 * \param tipos eTipo[] lista de tipos para mostrar la lista de mascotas
 * \param colores eColor[] lista de colores para mostrar la lista de mascotas
 * \param tamTipo int tamaño de la lista de tipos
 * \param idActual int id actual de la lista de mascotas, evita que ingresen una mascota no cargada
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cantidadDeTrabajosPorMascota(eTrabajo trabajo[], eMascotas mascota[], int tamM, eServicio servicios[], int tamS, int tamT, eTipo tipos[], eColor colores[], int tamTipo, int tamCo, int idActual, eCliente clientes[], int tamC);

/** \brief muestra la lista de mascotas, se elige una por id y muestra todos los trabajos que se le realizaron y el precio total de los mismos
 *
 * \param trabajo eTrabajo[] lista de trabajos
 * \param mascota eMascotas[] lista de mascotas
 * \param tamM int tamaño de la lista de mascotas
 * \param servicios eServicio[] lista de servicios
 * \param tamS int tamaño de la lista de servicios
 * \param tamT int tamaño de la lista de trabajos
 * \param tipos eTipo[] lista de tipos para mostrar la lista de mascotas
 * \param colores eColor[] lista de colores para mostrar la lista de mascotas
 * \param tamTipo int tamaño de la lista de tipos
 * \param idActual int id actual de la lista de mascotas, evita que ingresen una mascota no cargada
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int precioCantidadDeTrabajosPorMascota(eTrabajo trabajo[], eMascotas mascota[], int tamM, eServicio servicios[], int tamS, int tamT, eTipo tipos[], eColor colores[], int tamTipo, int tamCo, int idActual, eCliente clientes[], int tamC);

/** \brief se ingresa una fecha y muestra si se realizo algun servicio en dicha fecha
 *
 * \param trabajo eTrabajo[] lista de trabajos
 * \param servicios eServicio[] lista de servicios
 * \param tamS int tamaño de la lista de servicios
 * \param tamT int tamaño de la lista de trabajos
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int listaPorFecha(eTrabajo trabajo[], eServicio servicios[], int tamS, int tamT);
