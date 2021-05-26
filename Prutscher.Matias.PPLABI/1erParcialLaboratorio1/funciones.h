#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#endif // FUNCIONES_H_INCLUDED

/** \brief recibe un array de tipo int y los ordena por orden ascendente o desendente
 *
 * \param lista[] int array a ordenar
 * \param tam int tamaño tamaño del array a ordenar
 * \param orden int criterio de ordenamiento 1 para ascendente o 0 para desendente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int ordenamientoInt(int lista[], int tam, int orden);

/** \brief recibe un array de char y los ordena por orden ascendente o desendente
 *
 * \param lista[] char array a ordenar
 * \param tam int tamaño tamaño del array a ordenar
 * \param orden int criterio de ordenamiento 1 para ascendente o 0 para desendente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int ordenamientoString(char lista[][20], int tam, int orden);

/** \brief recibe un array de tipo char, un char a buscar dentro del array y un char para reemplazarlo
 *
 * \param palabra char[] array a buscar coincidencias
 * \param unaLetra char letra a buscar dentro del array
 * \param otraLetra char letra a reemplazar
 * \return retorna 0 si no encontro coincidencias o la cantidad de coincidencias y reemplazos que realizo
 *
 */
int DameCantidadReemplazos(char palabra[],char unaLetra, char otraLetra);

/** \brief recibe un array de tipo char y lo da vuelta
 *
 * \param cadena char[] array a dar vuelta
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int invertirCadena(char cadena[]);

/** \brief recibe un array de tipo char y ordena de forma ascendiente 1 o desendiente 0
 *
 * \param nombre char[] array a dar vuelta
 * \param orden int el orden en el que se desea ordenar la cadena, 1 para ascendiente o 0 para desendiente
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int ordenarCaracteres(char nombre[], int orden);

/** \brief recibe un array de tipo char y valida si son todos letras
 *
 * \param string char[] array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int isChar(char string[]);

/** \brief recibe un array de tipo char y valida el largo y que sean todos caracter letra
 *
 * \param string char[] array a revisar
 * \param tam int tamaño a validar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int getString(char input[], int tam);

/** \brief recibe un array de tipo char y pasa todo el array a minuscula salvo la primer letra del mismo que queda en mayuscula
 *
 * \param string char[] array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int SizeString(char string[]);

/** \brief recibe un array de tipo char con el mensaje de pedido, uno con el mensaje de error, tamaño del array, reintentos y una variable char donde guarda el dato
 *
 * \param mensaje char[] mensaje a mostrar el usuario
 * \param mensajeError char[] mensaje de error
 * \param tam int tamaño del array
 * \param reintentos int cantidad de reintentos que tiene el usuario
 * \param input char[] donde se guarda la variable verificada
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);

/** \brief recibe un array de tipo char y valida si son todos numeros
 *
 * \param input char[] array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int isInt(char input[]);

/** \brief recibe un puntero int, valida que sea tipo int con isInt y convierte de char a int con atoi
 *
 * \param input int* array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int getInt(int* input);

/** \brief recibe un array de tipo char con el mensaje de pedido, uno con el mensaje de error, numero minimo, maximo, reintentos y una variable int donde guarda el dato
 *
 * \param mensaje char[] mensaje a mostrar el usuario
 * \param mensajeError char[] mensaje de error
 * \param min int numero minimo
  * \param max int numero maximo
 * \param reintentos int cantidad de reintentos que tiene el usuario
 * \param input int* donde se guarda la variable verificada
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input);

/** \brief recibe un array de tipo char y valida si son todos numeros
 *
 * \param input char[] array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int isFloat(char input[]);

/** \brief recibe un puntero float, valida que sea tipo float con isFloat y convierte de char a float con atoi
 *
 * \param input float* array a revisar
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int getFloat(float* input);

/** \brief recibe un array de tipo char con el mensaje de pedido, uno con el mensaje de error, numero minimo, maximo, reintentos y una variable float donde guarda el dato
 *
 * \param mensaje char[] mensaje a mostrar el usuario
 * \param mensajeError char[] mensaje de error
 * \param min int numero minimo
  * \param max int numero maximo
 * \param reintentos int cantidad de reintentos que tiene el usuario
 * \param input int* donde se guarda la variable verificada
 * \return retorna -1 si hubo un error o 0 si esta todo bien
 *
 */
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);
