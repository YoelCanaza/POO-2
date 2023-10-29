#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int NUMNODOS = 10;
const int INFINITO = -32768;

struct tipoNodo {
    int indice;
    int info, sig;
};
tipoNodo nodos[NUMNODOS];

void iniciarLista(tipoNodo nodos[]);
int obtenerNodo();
void liberarNodo(int p);
void insertarNodo(int x);
//Ejercicio propuesto 1:
void mostrarNodo(tipoNodo nodos[]);
//Ejercicio propuesto 2:
void eliminarNodo(int p, int* px);
//Ejercicio propuesto 3:
bool esVacia();
void mensajeListaVacia();
//Ejercicio propuesto 4:
void buscarNodo(int aBuscar);

int i, disponible = NUMNODOS;
int bottom = NUMNODOS -1;
int x;
int inicio = 0;


int main()
{
    iniciarLista(nodos);

    cout << "\nLa lista creada es: " << endl;
    mostrarNodo(nodos);

    mensajeListaVacia();

    cout << endl << "Presione una tecla para continuar";
    getchar();
    x = 15;     insertarNodo(x);    x = 17;     insertarNodo(x);
    x = 10;     insertarNodo(x);    x = 30;     insertarNodo(x);
    x = 49;     insertarNodo(x);    x = 50;     insertarNodo(x);
    x = 80;     insertarNodo(x);    x = 99;     insertarNodo(x);
    x = 55;     insertarNodo(x);    x = 88;     insertarNodo(x);

    cout << "La lista actual es: " << endl;
    mostrarNodo(nodos);
    mensajeListaVacia();

    cout << endl << "Presione una tecla para continuar";
    getchar();

    insertarNodo(100);
    cout << "\tLa lista la nueva actual es:" << endl;
    mostrarNodo(nodos);
    mensajeListaVacia();

    int aBorrar;
    cout << "Que elemento de la lista desea borrar?: "; cin >> aBorrar;
    eliminarNodo(aBorrar, &x);
    mostrarNodo(nodos);
    mensajeListaVacia();

    int nodoaBuscar;
    cout << "Que dato desea buscar? (los datos son numeros enteros): "; cin >> nodoaBuscar;
    buscarNodo(nodoaBuscar);


    cout << "INGRESANDO NUEVA LISTA: " << endl << endl;

    iniciarLista(nodos); // funciona como un reseteo de la lista

    int numeroNodos;
    cout << "Cuantos nodos tendra la lista?: "; cin >> numeroNodos;

    cout << "Inserte nuevos nodos: " << endl;
    for(int i = 0; i < numeroNodos; i++) {
        cout << "Nodo " << i << ": "; cin >> x;
        insertarNodo(x);
    }
    mostrarNodo(nodos);


    cout << "INGRESANDO NUEVA LISTA: " << endl << endl;

    iniciarLista(nodos);

    cout << "Cuantos nodos tendra la lista?: "; cin >> numeroNodos;

    cout << "Inserte nuevos nodos: " << endl;
    for(int i = 0; i < numeroNodos; i++) {
        cout << "Nodo " << i << ": "; cin >> x;
        insertarNodo(x);
    }
    mostrarNodo(nodos);


    cout << "INGRESANDO NUEVA LISTA: " << endl << endl;

    iniciarLista(nodos);

    cout << "Cuantos nodos tendra la lista?: "; cin >> numeroNodos;

    cout << "Inserte nuevos nodos: " << endl;
    for(int i = 0; i < numeroNodos; i++) {
        cout << "Nodo " << i << ": "; cin >> x;
        insertarNodo(x);
    }
    mostrarNodo(nodos);


    cout << "Presione una tecla para finalizar...";
    return 0;
}

void iniciarLista(tipoNodo nodos[]) {
    inicio = 0;
    for(i = 0; i< NUMNODOS; i++) {
        disponible = NUMNODOS;
        nodos[i].sig = i + 1;
        nodos[i].info = INFINITO;
        nodos[i].indice = i;
    }

    nodos[NUMNODOS - 1].sig = -1;//modificado de -1 a 0
}

int obtenerNodo() {
    int p = 0;
    if(!disponible) {
        return -1;
    }

    --disponible;

    while(nodos[p].info != INFINITO) {
        p++;
    }

    return (p);
}

void liberarNodo(int p) {
    nodos[p].info = INFINITO;
    nodos[p].sig = -1;

    bottom = p;
    ++disponible;
}

void insertarNodo(int x) {
    int q;
    q = obtenerNodo();

    if(q == -1) {
        cout << "Insercion no efectuada... !" << endl;
        return;
    }
    nodos[q].info = x;
}

//Ejercicio propuesto 1:
void mostrarNodo(tipoNodo nodos[]) {
    int indNodo = inicio;
    int contador = 0;

    cout << "Num Nodo\t\tindice array\tinfor\tsig" << endl;
    while(nodos[indNodo].info != INFINITO && nodos[indNodo].sig != -1) {
        cout << "Numero de nodo: " << contador << "\t" << "Indice array " << nodos[indNodo].indice << ":\t" << nodos[indNodo].info << "\t" << nodos[indNodo].sig << "\t" << endl;
        indNodo = nodos[indNodo].sig;
        contador++;
    }
    if(nodos[indNodo].sig == -1) {
        cout << "Numero de nodo: " << contador << "\t" << "Indice array " << nodos[indNodo].indice << ":\t" << nodos[indNodo].info << "\t" << nodos[indNodo].sig << "\t" << endl;
    }
}

//Ejercicio propuesto 2:
void eliminarNodo(int p, int* px) {
    int contador = 0;
    int indNodo = inicio;
    int ant;

    if(p == inicio) {
        *px = nodos[inicio].info;
        inicio = nodos[inicio].sig;

        liberarNodo(p);
    } else if(p < NUMNODOS) {
        while(contador < p) {
            ant = indNodo;
            indNodo = nodos[indNodo].sig;
            contador++;
        }
        *px = nodos[indNodo].info;
        nodos[ant].sig = nodos[indNodo].sig;
        liberarNodo(p);

    } else {
        cout << "El nodo indicado no existe...!" << endl;
    }
}

//Ejercicio propuesto 3:
bool esVacia() {
    if(nodos[inicio].info == INFINITO) {
        return true;
    } else {
        return false;
    }
}
void mensajeListaVacia() {
    if(esVacia()) {
        cout << "Todos la informacion de los nodos es un valor por defecto, la lista esta vacia" << endl;
    } else {
        cout << "La lista no esta vacia" << endl;
    }
}

//Ejercicio propuesto 4:
void buscarNodo(int aBuscar) {
    int contador = 0;
    int indNodo = inicio;

    if(esVacia()) {
        cout << "La lista esta vacia...!" << endl;
    } else {
        while(nodos[indNodo].info != aBuscar) {
            indNodo = nodos[indNodo].sig;
            if(indNodo == -1) {
                cout << "No se ha encontrado el nodo en la lista" << endl;
                break;
            }
            contador++;
        }

        if(indNodo == -1) {

        } else {
           cout << "Nodo solicitado: " << nodos[indNodo].info << endl;
           cout << "Posicion en la lista: " << contador << endl;
           cout << "Indice del array: " << nodos[indNodo].indice << endl;
        }
    }
}
