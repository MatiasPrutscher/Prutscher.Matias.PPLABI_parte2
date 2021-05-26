#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief recibe un año (int, AAAA) y devuelve 1 si es bisiesto o 0 sino
 *
 * \param anio int año a validar
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int aBisiesto(int anio);

/** \brief recibe una fecha, valida la misma y devuelve 1 si esta todo bien o en caso contrario 0
 *
 * \param fecha eFecha recibe la fecha a validar
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int validarFecha(eFecha fecha);
