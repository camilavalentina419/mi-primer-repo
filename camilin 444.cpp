#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Configurar la semilla para números aleatorios basados en el tiempo actual
    srand(static_cast<unsigned int>(time(0)));

    string repetir = "si";

    // Bucle principal para repetir todo el programa mientras el usuario escriba "si"
    while (repetir == "si" || repetir == "SI" || repetir == "Si") {
        int numOpciones = 0;

        // Validación de la cantidad de opciones (debe ser 2, 3, 4 o 10)
        while (true) {
            cout << "\n\033[1;36m========================================\033[0m\n";
            cout << "\033[1;33m       SIMULADOR DE RULETA DE OPCIONES    \033[0m\n";
            cout << "\033[1;36m========================================\033[0m\n";
            cout << "Ingrese el numero de opciones permitidas (\033[1;32m2, 3, 4 o 10\033[0m): ";
            cin >> numOpciones;

            // Validar si hubo error de lectura o si el número no es exactamente 2, 3, 4 o 10
            if (cin.fail() || (numOpciones != 2 && numOpciones != 3 && numOpciones != 4 && numOpciones != 10)) {
                cin.clear(); // Limpiar el estado de error de cin
                cin.ignore(10000, '\n'); // Descarta la entrada incorrecta
                cout << "\033[1;31m[Error] Opcion invalida. Debe ingresar estrictamente 2, 3, 4 o 10.\033[0m\n";
            } else {
                cin.ignore(10000, '\n'); // Limpiar el buffer de salto de línea
                break;
            }
        }

        // Variables individuales para almacenar cada opción (sin arreglos, listas ni punteros)
        string op1 = "", op2 = "", op3 = "", op4 = "", op5 = "";
        string op6 = "", op7 = "", op8 = "", op9 = "", op10 = "";

        cout << "\n\033[1;35m--- Ingrese las " << numOpciones << " opciones (palabras, numeros o simbolos) ---\033[0m\n";

        // Ingreso y validación de la Opción 1
        while (true) {
            cout << "Opcion 1: ";
            getline(cin, op1);
            if (op1.empty()) {
                cout << "\033[1;31m[Error] La opcion no puede estar vacia. Intente de nuevo.\033[0m\n";
            } else {
                break;
            }
        }

        // Ingreso y validación de la Opción 2
        while (true) {
            cout << "Opcion 2: ";
            getline(cin, op2);
            if (op2.empty()) {
                cout << "\033[1;31m[Error] La opcion no puede estar vacia. Intente de nuevo.\033[0m\n";
            } else {
                break;
            }
        }

        // Si el usuario eligió 3, 4 o 10 opciones, pedimos la Opción 3
        if (numOpciones >= 3) {
            while (true) {
                cout << "Opcion 3: ";
                getline(cin, op3);
                if (op3.empty()) {
                    cout << "\033[1;31m[Error] La opcion no puede estar vacia. Intente de nuevo.\033[0m\n";
                } else {
                    break;
                }
            }
        }

        // Si el usuario eligió 4 o 10 opciones, pedimos la Opción 4
        if (numOpciones >= 4) {
            while (true) {
                cout << "Opcion 4: ";
                getline(cin, op4);
                if (op4.empty()) {
                    cout << "\033[1;31m[Error] La opcion no puede estar vacia. Intente de nuevo.\033[0m\n";
                } else {
                    break;
                }
            }
        }

        // Si el usuario eligió 10 opciones, pedimos desde la 5 hasta la 10
        if (numOpciones == 10) {
            while (true) {
                cout << "Opcion 5: ";
                getline(cin, op5);
                if (op5.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
            while (true) {
                cout << "Opcion 6: ";
                getline(cin, op6);
                if (op6.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
            while (true) {
                cout << "Opcion 7: ";
                getline(cin, op7);
                if (op7.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
            while (true) {
                cout << "Opcion 8: ";
                getline(cin, op8);
                if (op8.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
            while (true) {
                cout << "Opcion 9: ";
                getline(cin, op9);
                if (op9.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
            while (true) {
                cout << "Opcion 10: ";
                getline(cin, op10);
                if (op10.empty()) { cout << "\033[1;31m[Error] No puede estar vacia.\033[0m\n"; } else { break; }
            }
        }

        // Simulación de la ruleta generando un número aleatorio entre 0 y (numOpciones - 1)
        int indiceGanador = rand() % numOpciones;

        cout << "\n\033[1;33m----------------------------------------\033[0m\n";
        cout << "\033[1;35m¡Girando la ruleta...\033[0m\n";
        cout << "¡El resultado ganador es: \033[1;32m** ";

        // Mostrar la opción ganadora según el índice generado aleatoriamente
        if (indiceGanador == 0) cout << op1;
        else if (indiceGanador == 1) cout << op2;
        else if (indiceGanador == 2) cout << op3;
        else if (indiceGanador == 3) cout << op4;
        else if (indiceGanador == 4) cout << op5;
        else if (indiceGanador == 5) cout << op6;
        else if (indiceGanador == 6) cout << op7;
        else if (indiceGanador == 7) cout << op8;
        else if (indiceGanador == 8) cout << op9;
        else if (indiceGanador == 9) cout << op10;

        cout << " **\033[0m !\n";
        cout << "\033[1;33m----------------------------------------\033[0m\n";

        // Preguntar si desea repetir el programa escribiendo "si"
        cout << "¿Desea volver a usar la ruleta? (\033[1;36msi/no\033[0m): ";
        getline(cin, repetir);
    }

    cout << "\n\033[1;36m¡Gracias por usar la ruleta de opciones! Hasta luego.\033[0m\n";

    return 0;
}
