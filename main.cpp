#include <iostream>
#include "Cola.h"
#include <locale>

using namespace std;

int main() {
    Cola MiCola;
    alumno x;

    int opc;

    do {
        setlocale(LC_ALL, "");
        cout << "\n\t------------ MEN� - COLA (DE DIRECCI�N ESCOLAR) ------------\n" << endl;
        cout << "\t1. Dar de alta una solicitud." << endl;
        cout << "\t2. Elaborar una constancia." << endl;
        cout << "\t3. Salir" << endl;
        cout << "\n\tElija una opci�n: ";
        cin >> opc;

        switch (opc) {
            case 1: // Dar de alta una solicitud
                cout << "\n\tIngrese los datos del alumno\n" << endl;
                cin >> x;
                MiCola.enqueue(x);
                cout << "\t�Solicitud de alumno encolada exitosamente!.\n" << endl;
                break;

            case 2: // Elaborar una constancia
                if (!MiCola.vacia()) {
                    cout << "\tElaborando constancia para el alumn@\n";
                    alumno constancia_alumno = MiCola.dequeue();
                    cout << constancia_alumno << endl;
                } else {
                    cout << "\tLa cola est� vac�a, no hay alumnos para elaborar constancias." << endl;
                }
                break;

            case 3: // Salir
                cout << "\n\tSaliendo del programa..." << endl;
                break;

            default:
                cout << "\n\tOpci�n no v�lida. Por favor, elija una opci�n v�lida." << endl;
                break;
        }

    } while (opc != 3);

    return 0;
}
