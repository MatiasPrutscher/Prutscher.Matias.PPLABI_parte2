#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED


/** \brief Muestra la lista completa de tipos
 *
 * \param tipos eTipo[] Lista a mostrar
 * \param tam int tamaño de la lista de tipos
 * \return void
 *
 */
void mostrarTipos(eTipo tipos[], int tam);

/** \brief Muestra el tipo especifico
 *
 * \param tipos eTipo tipo mostrar
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief busca un tipo en especifico a traves del id y carga la descripcion en la variable desc
 *
 * \param id int id a buscar dentro de la lista de tipos
 * \param tipos eTipo[] lista de tipos a buscar
 * \param tam int tamaño de la lista de tipos
 * \param desc char[] carga el nombre de la tipos
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);

/** \brief busca el id a traves de char tipo (caracteres)
 *
 * \param tipos eTipo[] lista de tipos a buscar
 * \param tam int tamaño de la lista de tipos
 * \param tipo char[] tipo pasado a comparar y buscar
 * \param id int* puntero a guardar el id encontrado
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int busquedaIdtipo(eTipo tipos[], int tam, char tipo[], int* id);
