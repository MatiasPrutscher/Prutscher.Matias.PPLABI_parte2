#include "tipo.h"
#include "color.h"
#include "funciones.h"
#include "cliente.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idCliente;
    int isEmpty;
}eMascotas;

#endif // MASCOTAS_H_INCLUDED


/** \brief Inicializa todas las mascotas y hace el llamado para inicializar los clientes
 *
 * \param lista eMascotas[] lista a inicializar
 * \param tam int tamaño de la lista a inicializar
 * \param clientes eCliente[] lista de clientes a pasar
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int inicializarmascotas(eMascotas lista[], int tam, eCliente clientes[], int tamC);

/** \brief recibe la lista de mascotas, busca un lugar libre para completar y devuelve el index de dicho lugar
 *
 * \param lista eMascotas[] lista en la que buscar
 * \param tam int tamaño de la lista en la que buscar
 * \return devuelve -1 si no hay lugar y sino el index
 *
 */
int buscarLibre(eMascotas lista[], int tam);

/** \brief Le pide al usuario todos los datos para dar de alta a una mascota
 *
 * \param lista eMascotas[] lista a dar de alta
 * \param tam int tamaño de la lista a dar de alta
 * \param pId int* puntero al id del main para modificarlo con cada entrada
 * \param tipos eTipo[] lista de tipos para poder mostrar la lista y que el cliente pueda elegir
 * \param colores eColor[] lista de colores para poder mostrar la lista y que el cliente pueda elegir
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista y que el cliente pueda elegir
 * \param tamC int tamaño de la lista de clientes
 * \param nextCliente int pasa el valor del id de cliente para que no pueda seleccionar un id inexistente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int altaMascotas(eMascotas lista[], int tam, int* pId, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC, int nextCliente);

/** \brief Muestra la lista completa de mascotas
 *
 * \param lista eMascotas[] lista a mostrar
 * \param tam int tamaño de la lista a mostrar
 * \param limpiar int si se pasa 1 limpia la pantalla o en caso contrario pasar 0
 * \param tipos eTipo[] lista de tipos para mostrar la descripcion en vez del id
 * \param colores eColor[] lista de colores para mostrar la descripcion en vez del id
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar el nombre en vez del id
 * \param tamC int tamaño de la lista de clientes
 * \return void
 *
 */
void mostrarMascotas(eMascotas lista[], int tam, int limpiar, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief Muestra una sola mascota
 *
 * \param mascota eMascotas mascota a mostrar
 * \param tipos eTipo[] lista de tipos para mostrar la descripcion en vez del id
 * \param colores eColor[] lista de colores para mostrar la descripcion en vez del id
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar el nombre en vez del id
 * \param tamC int tamaño de la lista de clientes
 * \return void
 *
 */
void mostrarMascota(eMascotas mascota, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief Busca una mascota entre las que estan dadas de alta por su id
 *
 * \param lista eMascotas[] lista a buscar
 * \param tam int tamaño de la lista a buscar
 * \param id int id a buscar en la lista de mascotas
 * \return devuelve -1 si no hay lugar y sino el index
 *
 */
int buscarMascota(eMascotas lista[], int tam, int id);

/** \brief muestra la lista de mascotas, el usuario elige el id de cual modificar y permite modificar entre tipo y edad
 *
 * \param lista eMascotas[] lista a modificar
 * \param tam int tamaño de la lista a modificar
 * \param tipos eTipo[] lista de tipos para mostrar la descripcion en vez del id
 * \param colores eColor[] lista de colores para mostrar la descripcion en vez del id
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar el nombre en vez del id
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int modificarMascota(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief muestra la lista de mascotas, el usuario elige el id y se da de baja .isEmpty = 1
 *
 * \param lista eMascotas[] lista a modificar
 * \param tam int tamaño de la lista a modificar
 * \param tipos eTipo[] lista de tipos para mostrar la descripcion en vez del id
 * \param colores eColor[] lista de colores para mostrar la descripcion en vez del id
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para mostrar el nombre en vez del id
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int bajaMascotas(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief busca una mascota en especifico a traves del id y carga el nombre en la variable desc
 *
 * \param id int id a buscar dentro de la lista de mascotas
 * \param lista eMascotas[] lista de mascotas a buscar
 * \param tam int tamaño de la lista de mascotas
 * \param desc char[] carga el nombre de la mascota
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cargarNombreDeMascota(int id, eMascotas lista[], int tam, char desc[]);

/** \brief El usuario ingresa el color (caracteres) y muestra todas las mascotas de dicho color
 *
 * \param lista eMascotas[] lista de mascotas en la que buscar
 * \param colores eColor[] muestra la lista de colores, luego de la eleccion del usuario compara con la lista de mascotas
 * \param tipos eTipo[] lista de tipos para poder mostrar la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int mostrarMascotasXColorUsuario(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief El usuario ingresa el tipo (id) y muestra todas las mascotas de dicho color
 *
 * \param lista eMascotas[] lista de mascotas en la que buscar
 * \param colores eColor[] lista de colores para poder mostrar la lista de mascotas
 * \param tipos eTipo[] muestra la lista de colores, luego de la eleccion del usuario compara con la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int mostrarMascotasXTipoUsuario(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief Muestra la lista de mascotas separadas por tipo
 *
 * \param lista eMascotas[] lista de mascotas
 * \param colores eColor[] lista de colores para poder mostrar la lista de mascotas
 * \param tipos eTipo[] lista de tipos para poder mostrar la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int mostrarMascotasPorTipo(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief El usuario ingresa el color y el tipo por id y muestra todas las mascotas de dicho color y tipo
 *
 * \param lista eMascotas[] lista de mascotas en la que buscar
 * \param colores eColor[] muestra la lista de colores, luego de la eleccion del usuario compara con la lista de mascotas
 * \param tipos eTipo[] muestra la lista de tipos, luego de la eleccion del usuario compara con la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int mostrarMascotasPorTipoYColor(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC);

/** \brief Busca y muestra el color mas popular
 *
 * \param lista eMascotas[] lista de mascotas en la que buscar
 * \param colores eColor[] lista de colores para poder mostrar la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamCo int tamaño de la lista de colores
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int colorMasPopularDeMascotas(eMascotas lista[], eColor colores[], int tam, int tamCo);

/** \brief Busca y muestra la/las mascotas de menor edad
 *
 * \param lista eMascotas[] lista de mascotas en la que buscar
 * \param colores eColor[] lista de colores para poder mostrar la lista de mascotas
 * \param tipos eTipo[] lista de tipos para poder mostrar la lista de mascotas
 * \param tam int tamaño de la lista de mascotas
 * \param tamT int tamaño de la lista de tipos
 * \param tamCo int tamaño de la lista de colores
 * \param clientes eCliente[] lista de clientes para poder mostrar la lista de mascotas
 * \param tamC int tamaño de la lista de clientes
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int mascotaDeMenorEdad(eMascotas lista[], eColor colores[], eTipo tipos[], int tam, int tamT, int tamCo, eCliente clientes[], int tamC);
