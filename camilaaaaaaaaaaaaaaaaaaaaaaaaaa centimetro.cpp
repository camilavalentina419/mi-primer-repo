#include <iostream>
#include <limits>

using namespace std;

// Función para limpiar el búfer y validar la entrada numérica
double leerNumero(string mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
            cout << "  [Error] Entrada invalida. Por favor, ingrese un numero.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar salto de línea pendiente
            return valor;
        }
    }
}

// Conversiones de Longitud (Base: Metros)
double convertirLongitud(double valor, int de, int a) {
    double enMetros = 0;
    // 1: Metro, 2: Kilometro, 3: Centimetro, 4: Milimetro, 5: Milla, 6: Pulgada
    switch (de) {
        case 1: enMetros = valor; break;
        case 2: enMetros = valor * 1000.0; break;
        case 3: enMetros = valor / 100.0; break;
        case 4: enMetros = valor / 1000.0; break;
        case 5: enMetros = valor * 1609.34; break;
        case 6: enMetros = valor * 0.0254; break;
    }

    switch (a) {
        case 1: return enMetros;
        case 2: return enMetros / 1000.0;
        case 3: return enMetros * 100.0;
        case 4: return enMetros * 1000.0;
        case 5: return enMetros / 1609.34;
        case 6: return enMetros / 0.0254;
        default: return 0;
    }
}

// Conversiones de Masa (Base: Kilogramos)
double convertirMasa(double valor, int de, int a) {
    double enKg = 0;
    // 1: Kilogramo, 2: Gramo, 3: Miligramos, 4: Tonelada, 5: Libra, 6: Onza
    switch (de) {
        case 1: enKg = valor; break;
        case 2: enKg = valor / 1000.0; break;
        case 3: enKg = valor / 1000000.0; break;
        case 4: enKg = valor * 1000.0; break;
        case 5: enKg = valor * 0.453592; break;
        case 6: enKg = valor * 0.0283495; break;
    }

    switch (a) {
        case 1: return enKg;
        case 2: return enKg * 1000.0;
        case 3: return enKg * 1000000.0;
        case 4: return enKg / 1000.0;
        case 5: return enKg / 0.453592;
        case 6: return enKg / 0.0283495;
        default: return 0;
    }
}

// Conversiones de Tiempo (Base: Segundos)
double convertirTiempo(double valor, int de, int a) {
    double enSegundos = 0;
    // 1: Segundo, 2: Minuto, 3: Hora, 4: Dia
    switch (de) {
        case 1: enSegundos = valor; break;
        case 2: enSegundos = valor * 60.0; break;
        case 3: enSegundos = valor * 3600.0; break;
        case 4: enSegundos = valor * 86400.0; break;
    }

    switch (a) {
        case 1: return enSegundos;
        case 2: return enSegundos / 60.0;
        case 3: return enSegundos / 3600.0;
        case 4: return enSegundos / 86400.0;
        default: return 0;
    }
}

int main() {
    int opcionCategoria;

    do {
        cout << "\n=========================================\n";
        cout << "        CONVERSOR DE UNIDADES            \n";
        cout << "=========================================\n";
        cout << "1. Longitud (Metros, Kilometros, Centimetros, etc.)\n";
        cout << "2. Masa (Kilogramos, Gramos, Libras, etc.)\n";
        cout << "3. Tiempo (Segundos, Minutos, Horas, Dias)\n";
        cout << "4. Salir\n";
        
        opcionCategoria = (int)leerNumero("Seleccione una categoria (1-4): ");

        if (opcionCategoria >= 1 && opcionCategoria <= 3) {
            int unidadOrigen, unidadDestino;
            double cantidad;

            if (opcionCategoria == 1) {
                cout << "\n--- UNIDADES DE LONGITUD ---\n";
                cout << "1. Metro (m)\n2. Kilometro (km)\n3. Centimetro (cm)\n4. Milimetro (mm)\n5. Milla (mi)\n6. Pulgada (in)\n";
                unidadOrigen = (int)leerNumero("Elija unidad de ORIGEN (1-6): ");
                unidadDestino = (int)leerNumero("Elija unidad de DESTINO (1-6): ");
                
                if (unidadOrigen < 1 || unidadOrigen > 6 || unidadDestino < 1 || unidadDestino > 6) {
                    cout << "  [Error] Opcion de unidades invalida.\n";
                    continue;
                }

                cantidad = leerNumero("Ingrese la cantidad a convertir: ");
                double resultado = convertirLongitud(cantidad, unidadOrigen, unidadDestino);
                cout << "\n>>> Resultado: " << cantidad << " = " << resultado << " <<<\n";

            } else if (opcionCategoria == 2) {
                cout << "\n--- UNIDADES DE MASA ---\n";
                cout << "1. Kilogramo (kg)\n2. Gramo (g)\n3. Miligramo (mg)\n4. Tonelada (t)\n5. Libra (lb)\n6. Onza (oz)\n";
                unidadOrigen = (int)leerNumero("Elija unidad de ORIGEN (1-6): ");
                unidadDestino = (int)leerNumero("Elija unidad de DESTINO (1-6): ");

                if (unidadOrigen < 1 || unidadOrigen > 6 || unidadDestino < 1 || unidadDestino > 6) {
                    cout << "  [Error] Opcion de unidades invalida.\n";
                    continue;
                }

                cantidad = leerNumero("Ingrese la cantidad a convertir: ");
                double resultado = convertirMasa(cantidad, unidadOrigen, unidadDestino);
                cout << "\n>>> Resultado: " << cantidad << " = " << resultado << " <<<\n";

            } else if (opcionCategoria == 3) {
                cout << "\n--- UNIDADES DE TIEMPO ---\n";
                cout << "1. Segundo (s)\n2. Minuto (min)\n3. Hora (h)\n4. Dia (d)\n";
                unidadOrigen = (int)leerNumero("Elija unidad de ORIGEN (1-4): ");
                unidadDestino = (int)leerNumero("Elija unidad de DESTINO (1-4): ");

                if (unidadOrigen < 1 || unidadOrigen > 4 || unidadDestino < 1 || unidadDestino > 4) {
                    cout << "  [Error] Opcion de unidades invalida.\n";
                    continue;
                }

                cantidad = leerNumero("Ingrese la cantidad a convertir: ");
                double resultado = convertirTiempo(cantidad, unidadOrigen, unidadDestino);
                cout << "\n>>> Resultado: " << cantidad << " = " << resultado << " <<<\n";
            }

        } else if (opcionCategoria == 4) {
            cout << "\nSaliendo del programa. ¡Hasta luego!\n";
        } else {
            cout << "  [Error] Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcionCategoria != 4);

    return 0;
}
