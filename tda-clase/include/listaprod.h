#ifndef LISTAPROD_H
#define LISTAPROD_H

struct  Nodo
{
    char producto[20];
    float precio;
    struct Nodo *sig;
};

class Lista {
    Nodo *primero;
public:
    Lista();
    ~Lista();
    void insertarNodo();
    void eliminarNodo(char prod[]);
    void imprimelista();
    bool listaVacia();
    int cuentaNodos();
    void insertarNodoFin();
    void eliminarUltimo(); //Ejercicio 6 a
    void eliminaAntesX(char prod[]);//Ejercicio 6 b
    bool esDescendente();
};

#endif
