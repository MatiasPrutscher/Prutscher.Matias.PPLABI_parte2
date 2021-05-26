#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}eColor;


#endif // COLOR_H_INCLUDED

/** \brief Muestra la lista completa de colores
 *
 * \param colores eColor[] Lista a mostrar
 * \param tam int tamaño de la lista de colores
 * \return void
 *
 */
void mostrarColores(eColor colores[], int tam);

/** \brief Muestra el color especifico
 *
 * \param color eColor color mostrar
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief busca un color en especifico a traves del id y carga la descripcion en la variable desc
 *
 * \param id int id a buscar dentro de la lista de colores
 * \param colores eColor[] lista de colores a buscar
 * \param tam int tamaño de la lista de colores
 * \param desc char[] carga el nombre del color
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[]);

/** \brief busca el id a traves de char color (caracteres)
 *
 * \param colores eColor[] lista de colores a buscar
 * \param tam int tamaño de la lista de colores
 * \param color char[] color pasado a comparar y buscar
 * \param id int* puntero a guardar el id encontrado
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int busquedaIdColor(eColor colores[], int tam, char color[], int* id);
