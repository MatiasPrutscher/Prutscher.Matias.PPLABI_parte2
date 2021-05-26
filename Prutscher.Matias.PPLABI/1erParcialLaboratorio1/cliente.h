#include "funciones.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief Inicializa todos los clientes
 *
 * \param lista eCliente[] lista a inicializar
 * \param tam int tamaño de la lista a inicializar
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int inicializarClientes(eCliente lista[], int tam);

/** \brief recibe la lista de clientes, busca un lugar libre para completar y devuelve el index de dicho lugar
 *
 * \param lista eCliente[] lista en la que buscar
 * \param tam int tamaño de la lista en la que buscar
 * \return devuelve -1 si no hay lugar y sino el index
 *
 */
int buscarLibreCliente(eCliente lista[], int tam);

/** \brief Realiza el alta de los clientes
 *
 * \param lista eCliente[] lista de clientes en la que cargar
 * \param tam int tamaño de la lista de clientes
 * \param nextId int* id que se le debe asignar al cliente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int altaCliente(eCliente lista[], int tam, int* nextId);

/** \brief Muestra la lista completa de Clientes
 *
 * \param lista eCliente[] Lista a mostrar
 * \param tam int tamaño de la lista de Clientes
 * \return void
 *
 */
void mostrarClientes(eCliente lista[], int tam);

/** \brief Muestra un Cliente especifico
 *
 * \param lista eCliente Cliente a mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);

/** \brief busca un Cliente en especifico a traves del id y carga la descripcion en la variable desc
 *
 * \param id int id a buscar dentro de la lista de Clientes
 * \param lista eCliente[] lista de clientes a buscar
 * \param tam int tamaño de la lista de tipos
 * \param desc char[] carga el nombre del Cliente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cargarNombreDeCliente(int id, eCliente lista[], int tam, char nombre[]);

/** \brief carga los valores ya guardados en la biblioteca datawarehouse
 *
 * \param lista eCliente[] lista de clientes a cargar
 * \param tam int tamaño de la lista de clientes
 * \param cant int cantidad de clientes a cargar
 * \param nextId int* id que se le debe asignar al cliente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int hardcodearClientes(eCliente lista[], int tam, int cant, int* pLegajo);
