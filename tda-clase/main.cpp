#include <iostream>
#include <stdio.h>
#include "listaprod.h"

using namespace std;

int main() {
    int num = 0;
    int cont = 0;

    Lista L;
    cout << endl << "Cuantos nodos va a insertar: " << endl; cin >> num;
    fflush(stdin);

    while (cont<num)
    {
        ++cont;
        cout << endl << "Ingreso de Nodo: ";
        L.insertarNodo();
    }

    cout << endl << "El contenido de la lista es: " << endl;
    L.imprimelista();
    cout << endl << "El numero de nodos es: " << L.cuentaNodos();

    char prod[20];
    cout << endl << "Que producto desea borrar? ";
    gets(prod);
    L.eliminarNodo(prod);

    cout << endl << "El contenido de la lista es:" << endl;
    L.imprimelista();

    cout << "Ingreso de un nodo al final: ";
    L.insertarNodoFin();
    cout << endl << "El contenido de la lista es:" << endl;
    L.imprimelista();

    cout << endl << "Se eliminara el ultimonodo: " << endl;
    L.eliminarUltimo();
    L.imprimelista();

    prod[20];
    cout << endl << "El nodo anterior a que producto desea borrar? ";
    gets(prod);
    L.eliminaAntesX(prod);
    L.imprimelista();

    L.esDescendente();

    return 0;
}
