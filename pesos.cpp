//

#include <iostream>
using namespace std;

int main(){
    int estatura = 0;
    int peso = 0;
    
    cout << "ingrese estatura en centimetros" << endl;
    cin >> estatura;
    
    cout << "ingrese peso" << endl;
    cin >> peso;
    
    while (peso <= 0 || estatura <= 0) {
        cout << "error, ingrese los datos correctamente" << endl;
        cin >> estatura;
        cin >> peso;
    }
    
    float estaturametro = (float)estatura / 100.0;
    float estatura2 = estaturametro * estaturametro;
    float imc = peso / estatura2;
    
    if (imc < 16) {
        cout << "Delgadez severa" << endl;
    }
    else if (imc >= 16 && imc <= 16.99) {
        cout << "delgadez moderada" << endl;
    }
    else if (imc >= 17 && imc <= 18.49) {
        cout << "peso aceptable" << endl;
    }
    else if (imc >= 18.5 && imc <= 24.99) {
        cout << "peso normal" << endl;
    }
    else if (imc >= 25 && imc <= 29.99) {
        cout << "sobre peso" << endl;
    }
    else if (imc >= 30 && imc <= 34.99) {
        cout << "obesidad tipo 1" << endl;
    }
    else if (imc >= 35 && imc <= 40) {
        cout << "obesidad tipo 2" << endl;
    }
    else {
        cout << "obesidad tipo 3" << endl;
    }
    
    return 0;
}
