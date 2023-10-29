#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

#include "listaprod.h"

using namespace std;

Lista :: Lista()
{
    primero = NULL;
}

Lista :: ~Lista()
{
    Nodo *p;
    Nodo *temp;
    p = primero;
    while (p!=NULL)
    {
        temp = p->sig;
        delete p;
        p = temp;
    }
}

void Lista :: insertarNodo()
{
    char nom[20];
    fflush(stdin);
    cout << "\nIngrese el nombre del producto: "; gets(nom);
    fflush(stdin);
    float pre;
    cout << "Ingrese precio: "; cin>> pre;
    fflush(stdin);

    Nodo *p;
    p = new Nodo;
    strcpy(p -> producto, nom);
    p -> precio = pre;
    p -> sig = primero;
    primero = p;
}

void Lista :: eliminarNodo(char prod[])
{
    bool encuentra = false;
    Nodo *p;
    Nodo *antP;
    p = primero;
    antP = NULL;

    if(listaVacia())
        cout << "\nLista vacia no hay nodo a eliminar" << endl;
    else{
        while (!encuentra && p != NULL)
        {
            if(strcmp (p->producto, prod)==0)
                encuentra = true;
            else{
                antP = p;
                p = p -> sig;
            }
        }

        if(encuentra)
        {
            if(antP == NULL) { //caso del primer nodo
                primero = p -> sig;
                delete p;
            }
            else
            {
                antP -> sig = p -> sig;
                delete p;
            }
        }
        else
            cout << "\nEl producto " << prod << " no esta en la lista" << endl;

    }
}

void Lista::imprimelista() {
    Nodo *p;
    p = primero;
    if(!listaVacia()) {
        while (p != NULL) {
            cout << p->producto << " S/." << p->precio << " -> ";
            p = p->sig;
        }
        cout << "NULO" << endl;
    }
    else {
        cout << "\nLa lista esta vacia...!" << endl;
    }
}

bool Lista::listaVacia() {
    if(primero == NULL) {
        return true;
    } else {
        return false;
    }
}

int Lista::cuentaNodos() {
    int cont = 0;
    Nodo *p;
    p = primero;
    if(!listaVacia()) {
        while (p != NULL)
        {
            p = p->sig;
            cont++;
        }
        return cont;
    } else {
        return 0;
    }
}

void Lista::insertarNodoFin() {
    Nodo *p;
    p = primero;
    if(!listaVacia()) {
        while(p->sig != NULL) {
            p = p->sig;
        }
    }

    char nom[20];
    fflush(stdin);
    cout << "\nIngrese nombre del producto: ";
    gets(nom);
    fflush(stdin);
    float pre;
    cout << "Inserte precio: "; cin >> pre;
    fflush(stdin);

    //Isertando nodo al final
    Nodo *q;
    q = new Nodo;
    strcpy(q->producto, nom);
    q->precio = pre;
    q->sig = NULL;
    if(p == NULL) {
        primero = q;
    } else {
        p->sig = q;
    }
}

//Ejercicio propuesto 6 a:
void Lista::eliminarUltimo() {
    Nodo *p;
    Nodo *antP;
    p = primero;
    antP = NULL;

    if(listaVacia()) {
        cout << "\nLista vacia no hay nodo a eliminar" << endl;
    } else{
        while(p->sig != NULL) {
            antP = p;
            p = p->sig;
        }
        if(primero == p) {
            primero = p->sig;
            delete p;
        } else {
            antP->sig = p->sig;
            delete p;
        }
    }
}

//Ejercicio 6 b:
void Lista::eliminaAntesX(char prod[]) {
    bool encuentra = false;
    Nodo *p;
    Nodo *antP;
    Nodo *antAntP;
    p = primero;
    antP = NULL;
    antAntP = NULL;

    if(listaVacia())
        cout << "\nLista vacia no hay nodo a eliminar" << endl;
    else{
        while (!encuentra && p != NULL)
        {
            if(strcmp (p->producto, prod)==0)
                encuentra = true;
            else{
                antAntP = antP;
                antP = p;
                p = p -> sig;
            }
        }

        if(encuentra)
        {
            if(primero == p) {
                cout << "No se puede eliminar el nodo anterior al primero de la lista" << endl;
            } else if(antP == primero) { //caso del primer nodo
                primero = p;
                delete antP;
            }
            else
            {
                antAntP->sig = p;
                delete antP;
            }
        }
        else
            cout << "\nEl producto " << prod << " no esta en la lista" << endl;

    }
}

//Ejercicio propuesto 7
bool Lista::esDescendente() {
    bool descendente = true;
    Nodo *p;
    Nodo *sigP;
    p = primero;
    sigP = p->sig;
    int cont = 1;

    if(listaVacia())
        cout << "\nLista vacia...!" << endl;
    else{
        while (descendente && p->sig != NULL)
        {
            if(sigP > p) {
                descendente = false;
            } else{
                p = p -> sig;
                sigP = p->sig;
            }
            cont ++;
        }

        if(descendente) {
            cout << "La lista es descendente" << endl;
            return true;
        } else {
            cout << "El ordenamiento descendente falla en: " << cont << endl;
            return false;
        }

    }
}
