#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dni;
    char nombre[25];
    int edad;
    int estado;
}ePersona;

int cantidad;

/** Despliega el menu de opciones.
 * \param no recibe ningun valor.
 * \return Retorna el valor de la opcion ingresada por el usuario.
 */
int Menu();

/** Inicializa el estado de todas las personas en 0.
 * \param conjunto de estructuras a inicializar.
 */
void Inicializar(ePersona[]);

/** Carga los datos de las personas al sistema.
 * \param personas el array se pasa como parametro.
 */
void Alta(ePersona personas[]);

/** \brief cambia el estado de una persona a 2.
 * \param conjunto de estructuras usadas como parametro.
 * \param tamaño de dicho conjunto.
 */
void Baja(ePersona personas[]);

/** Ordena las personas ingresadas al sistema por orden alfabetico.
 * \param x el array se pasa como parametro.
 */
void Ordenar(ePersona personas[]);

/** \brief muestra los datos de un conjunto de personas.
 * \param conjunto de personas a mostrar datos.
 */
void ImprimirRegistro(ePersona otrasPersonas[]);

/** imprime un grafico de barras indicando la cantidad de personas por rango de edad.
 * \param personas el array se pasa como parametro.
 */
void Grafico(ePersona personas[]);

 /** Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \return Retorna el primer indice disponible
 */
int PosicionLibre(ePersona[]);

/** Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param  el dni es buscado en el array.
 * \return Retorna el indice en donde se encuentra el elemento con el parametro dni.
 */
int Existe(ePersona personas[], int dni);

#endif // FUNCIONES_H_INCLUDED
