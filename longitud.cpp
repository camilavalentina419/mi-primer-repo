#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Códigos de colores ANSI para la consola
const string RESET = "\033[0m";
const string NEGRITA = "\033[1m";
const string ROJO = "\033[1;31m";
const string VERDE = "\033[1;32m";
const string AMARILLO = "\033[1;33m";
const string AZUL = "\033[1;34m";
const string CIAN = "\033[1;36m";
const string MAGENTA = "\033[1;35m";

// Funciones para obtener el nombre textual de cada unidad
string obtenerNombreLongitud(int opcion) {
    switch (opcion) {
        case 1: return "Metro (m) [SI]";
        case 2: return "Kilometro (km)";
        case 3: return "Centimetro (cm)";
        case 4: return "Milimetro (mm)";
        case 5: return "Micrometro (um)";
        case 6: return "Nanometro (nm)";
        case 7: return "Milla (mi)";
        case 8: return "Pulgada (in)";
        case 9: return "Pie (ft)";
        default: return "Desconocido";
    }
}

string obtenerNombreMasa(int opcion) {
    switch (opcion) {
        case 1: return "Kilogramo (kg) [SI]";
        case 2: return "Gramo (g)";
        case 3: return "Miligramo (mg)";
        case 4: return "Microgramo (ug)";
        case 5: return "Tonelada (t)";
        case 6: return "Libra (lb)";
        case 7: return "Onza (oz)";
        default: return "Desconocido";
    }
}

string obtenerNombreTiempo(int opcion) {
    switch (opcion) {
        case 1: return "Segundo (s) [SI]";
        case 2: return "Milisegundo (ms)";
        case 3: return "Minuto (min)";
        case 4: return "Hora (h)";
        case 5: return "Dia (d)";
        default: return "Desconocido";
    }
}

string obtenerNombreTemperatura(int opcion) {
    switch (opcion) {
        case 1: return "Celsius (°C)";
        case 2: return "Fahrenheit (°F)";
        case 3: return "Kelvin (K) [SI]";
        default: return "Desconocido";
    }
}

// Función para validar y leer entradas numéricas de forma segura
double leerNumero(string mensaje) {
    double valor;
    while (true) {
        cout << CIAN << mensaje << RESET;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ROJO << "  [X] Error: Ingrese un numero valido." << RESET << "\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

// Conversiones de Longitud (Base: Metros)
double convertirLongitud(double valor, int de, int a) {
    double enMetros = 0;
    switch (de) {
        case 1: enMetros = valor; break;
        case 2: enMetros = valor * 1000.0; break;
        case 3: enMetros = valor / 100.0; break;
        case 4: enMetros = valor / 1000.0; break;
        case 5: enMetros = valor / 1000000.0; break;
        case 6: enMetros = valor / 1000000000.0; break;
        case 7: enMetros = valor * 1609.34; break;
        case 8: enMetros = valor * 0.0254; break;
        case 9: enMetros = valor * 0.3048; break;
    }
    switch (a) {
        case 1: return enMetros;
        case 2: return enMetros / 1000.0;
        case 3: return enMetros * 100.0;
        case 4: return enMetros * 1000.0;
        case 5: return enMetros * 1000000.0;
        case 6: return enMetros * 1000000000.0;
        case 7: return enMetros / 1609.34;
        case 8: return enMetros / 0.0254;
        case 9: return enMetros / 0.3048;
        default: return 0;
    }
}

// Conversiones de Masa (Base: Kilogramos)
double convertirMasa(double valor, int de, int a) {
    double enKg = 0;
    switch (de) {
        case 1: enKg = valor; break;
        case 2: enKg = valor / 1000.0; break;
        case 3: enKg = valor / 1000000.0; break;
        case 4: enKg = valor / 1000000000.0; break;
        case 5: enKg = valor * 1000.0; break;
        case 6: enKg = valor * 0.453592; break;
        case 7: enKg = valor * 0.0283495; break;
    }
    switch (a) {
        case 1: return enKg;
        case 2: return enKg * 1000.0;
        case 3: return enKg * 1000000.0;
        case 4: return enKg * 1000000000.0;
        case 5: return enKg / 1000.0;
        case 6: return enKg / 0.453592;
        case 7: return enKg / 0.0283495;
        default: return 0;
    }
}

// Conversiones de Tiempo (Base: Segundos)
double convertirTiempo(double valor, int de, int a) {
    double enSegundos = 0;
    switch (de) {
        case 1: enSegundos = valor; break;
        case 2: enSegundos = valor / 1000.0; break;
        case 3: enSegundos = valor * 60.0; break;
        case 4: enSegundos = valor * 3600.0; break;
        case 5: enSegundos = valor * 86400.0; break;
    }
    switch (a) {
        case 1: return enSegundos;
        case 2: return enSegundos * 1000.0;
        case 3: return enSegundos / 60.0;
        case 4: return enSegundos / 3600.0;
        case 5: return enSegundos / 86400.0;
        default: return 0;
    }
}

// Conversiones de Temperatura
double convertirTemperatura(double valor, int de, int a) {
    double enCelsius = 0;
    // 1: Celsius, 2: Fahrenheit, 3: Kelvin
    switch (de) {
        case 1: enCelsius = valor; break;
        case 2: enCelsius = (valor - 32.0) * 5.0 / 9.0; break;
        case 3: enCelsius = valor - 273.15; break;
    }

    switch (a) {
        case 1: return enCelsius;
        case 2: return (enCelsius * 9.0 / 5.0) + 32.0;
        case 3: return enCelsius + 273.15;
        default: return 0;
    }
}

int main() {
    int opcionCategoria;
    char repetir;

    do {
        cout << "\n" << AZUL << NEGRITA << "=================================================" << RESET << "\n";
        cout << AZUL << NEGRITA << "          CONVERSOR DE UNIDADES UNIVERSAL        " << RESET << "\n";
        cout << AZUL << NEGRITA << "=================================================" << RESET << "\n";
        cout << VERDE << " [1]" << RESET << " Longitud    " << MAGENTA << "(m, km, cm, mm, um, nm, mi, in, ft)" << RESET << "\n";
        cout << VERDE << " [2]" << RESET << " Masa        " << MAGENTA << "(kg, g, mg, ug, t, lb, oz)" << RESET << "\n";
        cout << VERDE << " [3]" << RESET << " Tiempo      " << MAGENTA << "(s, ms, min, h, d)" << RESET << "\n";
        cout << VERDE << " [4]" << RESET << " Temperatura " << MAGENTA << "(Celsius, Fahrenheit, Kelvin)" << RESET << "\n";
        cout << VERDE << " [5]" << RESET << " Salir" << "\n";
        cout << AZUL << NEGRITA << "=================================================" << RESET << "\n";
        
        opcionCategoria = (int)leerNumero(" >> Seleccione una categoria (1-5): ");

        if (opcionCategoria == 5) {
            cout << "\n" << VERDE << " ¡Saliendo del programa. Exito con tu nota!" << RESET << "\n\n";
            break;
        }

        if (opcionCategoria >= 1 && opcionCategoria <= 4) {
            int unidadOrigen, unidadDestino;
            double cantidad;

            if (opcionCategoria == 1) {
                cout << "\n" << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << AMARILLO << "             UNIDADES DE LONGITUD                " << RESET << "\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << " 1. Metro (m) [SI]       6. Nanometro (nm)\n";
                cout << " 2. Kilometro (km)       7. Milla (mi)\n";
                cout << " 3. Centimetro (cm)      8. Pulgada (in)\n";
                cout << " 4. Milimetro (mm)       9. Pie (ft)\n";
                cout << " 5. Micrometro (um)\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                
                unidadOrigen = (int)leerNumero(" >> Elija unidad de ORIGEN (1-9): ");
                unidadDestino = (int)leerNumero(" >> Elija unidad de DESTINO (1-9): ");
                
                if (unidadOrigen < 1 || unidadOrigen > 9 || unidadDestino < 1 || unidadDestino > 9) {
                    cout << "\n" << ROJO << " [X] Error: Opciones fuera de rango (1-9)." << RESET << "\n";
                } else {
                    cantidad = leerNumero(" >> Ingrese la cantidad a convertir: ");
                    double resultado = convertirLongitud(cantidad, unidadOrigen, unidadDestino);
                    
                    cout << "\n" << VERDE << "=================================================" << RESET << "\n";
                    cout << VERDE << " RESULTADO:\n" << RESET;
                    cout << " " << cantidad << " [" << obtenerNombreLongitud(unidadOrigen) << "]\n";
                    cout << " Equivale a: " << NEGRITA << resultado << " [" << obtenerNombreLongitud(unidadDestino) << "]" << RESET << "\n";
                    cout << VERDE << "=================================================" << RESET << "\n";
                }

            } else if (opcionCategoria == 2) {
                cout << "\n" << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << AMARILLO << "               UNIDADES DE MASA                  " << RESET << "\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << " 1. Kilogramo (kg) [SI]  5. Tonelada (t)\n";
                cout << " 2. Gramo (g)            6. Libra (lb)\n";
                cout << " 3. Miligramo (mg)       7. Onza (oz)\n";
                cout << " 4. Microgramo (ug)\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                
                unidadOrigen = (int)leerNumero(" >> Elija unidad de ORIGEN (1-7): ");
                unidadDestino = (int)leerNumero(" >> Elija unidad de DESTINO (1-7): ");

                if (unidadOrigen < 1 || unidadOrigen > 7 || unidadDestino < 1 || unidadDestino > 7) {
                    cout << "\n" << ROJO << " [X] Error: Opciones fuera de rango (1-7)." << RESET << "\n";
                } else {
                    cantidad = leerNumero(" >> Ingrese la cantidad a convertir: ");
                    double resultado = convertirMasa(cantidad, unidadOrigen, unidadDestino);
                    
                    cout << "\n" << VERDE << "=================================================" << RESET << "\n";
                    cout << VERDE << " RESULTADO:\n" << RESET;
                    cout << " " << cantidad << " [" << obtenerNombreMasa(unidadOrigen) << "]\n";
                    cout << " Equivale a: " << NEGRITA << resultado << " [" << obtenerNombreMasa(unidadDestino) << "]" << RESET << "\n";
                    cout << VERDE << "=================================================" << RESET << "\n";
                }

            } else if (opcionCategoria == 3) {
                cout << "\n" << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << AMARILLO << "              UNIDADES DE TIEMPO                 " << RESET << "\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << " 1. Segundo (s) [SI]     4. Hora (h)\n";
                cout << " 2. Milisegundo (ms)     5. Dia (d)\n";
                cout << " 3. Minuto (min)\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                
                unidadOrigen = (int)leerNumero(" >> Elija unidad de ORIGEN (1-5): ");
                unidadDestino = (int)leerNumero(" >> Elija unidad de DESTINO (1-5): ");

                if (unidadOrigen < 1 || unidadOrigen > 5 || unidadDestino < 1 || unidadDestino > 5) {
                    cout << "\n" << ROJO << " [X] Error: Opciones fuera de rango (1-5)." << RESET << "\n";
                } else {
                    cantidad = leerNumero(" >> Ingrese la cantidad a convertir: ");
                    double resultado = convertirTiempo(cantidad, unidadOrigen, unidadDestino);
                    
                    cout << "\n" << VERDE << "=================================================" << RESET << "\n";
                    cout << VERDE << " RESULTADO:\n" << RESET;
                    cout << " " << cantidad << " [" << obtenerNombreTiempo(unidadOrigen) << "]\n";
                    cout << " Equivale a: " << NEGRITA << resultado << " [" << obtenerNombreTiempo(unidadDestino) << "]" << RESET << "\n";
                    cout << VERDE << "=================================================" << RESET << "\n";
                }

            } else if (opcionCategoria == 4) {
                cout << "\n" << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << AMARILLO << "            UNIDADES DE TEMPERATURA              " << RESET << "\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                cout << " 1. Celsius (°C)\n";
                cout << " 2. Fahrenheit (°F)\n";
                cout << " 3. Kelvin (K) [SI]\n";
                cout << AMARILLO << "-------------------------------------------------" << RESET << "\n";
                
                unidadOrigen = (int)leerNumero(" >> Elija unidad de ORIGEN (1-3): ");
                unidadDestino = (int)leerNumero(" >> Elija unidad de DESTINO (1-3): ");

                if (unidadOrigen < 1 || unidadOrigen > 3 || unidadDestino < 1 || unidadDestino > 3) {
                    cout << "\n" << ROJO << " [X] Error: Opciones fuera de rango (1-3)." << RESET << "\n";
                } else {
                    cantidad = leerNumero(" >> Ingrese la cantidad a convertir: ");
                    double resultado = convertirTemperatura(cantidad, unidadOrigen, unidadDestino);
                    
                    cout << "\n" << VERDE << "=================================================" << RESET << "\n";
                    cout << VERDE << " RESULTADO:\n" << RESET;
                    cout << " " << cantidad << " [" << obtenerNombreTemperatura(unidadOrigen) << "]\n";
                    cout << " Equivale a: " << NEGRITA << resultado << " [" << obtenerNombreTemperatura(unidadDestino) << "]" << RESET << "\n";
                    cout << VERDE << "=================================================" << RESET << "\n";
                }
            }

        } else {
            cout << "\n" << ROJO << " [X] Error: Opcion de categoria no valida." << RESET << "\n";
        }

        // Bucle de repetición controlado por el usuario
        cout << "\n" << MAGENTA << "¿Desea realizar otra conversion? (s/n): " << RESET;
        cin >> repetir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repetir == 's' || repetir == 'S');

    cout << "\n" << VERDE << "¡Programa finalizado con exito! Mucho exito con tu entrega." << RESET << "\n";
    return 0;
}
