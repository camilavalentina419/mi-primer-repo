
#include <iostream>
using namespace std;

float areaRectangulo( float base,float altura){
	return base * altura ;}
	
	
	float areaCuadrado (float lado){	
		return lado *lado;}
		
float areaCirculo (float radio){
	return 3.1416 * radio *radio ;}
	
	
	float areaTriangulo ( float base,float altura ){
		return (base*altura)/2;}
		
		
int main (){
	float lado, base, altura, radio, area;
	int opcion;

   
    cout << "\n\t--- CALCULADORA DE AREAS ---\n";
    cout << "\t1. \"Circulo\"\n";
    cout << "\t2. \"Cuadrado\"\n";
    cout << "\t3. \"Rectangulo\"\n";
    cout << "\t4. \"Triangulo equilatero\"\n";
    cout << "\n\tElige una opcion (1-4): ";
    cin >> opcion;

    
    switch(opcion) {
        case 1:
            cout << "\n\t--- Calculando el Circulo ---\n";
            cout << "\tIngresa el radio: ";
            cin >> radio;
            area = areaCirculo (radio);
            cout << "\tEl area es: " << area << "\n";
            break;

        case 2:
            cout << "\n\t--- Calculando el Cuadrado ---\n";
            cout << "\tIngresa el lado: ";
            cin >> lado;
            area = areaCuadrado (lado);
            
            cout << "\tEl area es: " << area << "\n";
            break;

        case 3:
            cout << "\n\t--- Calculando el Rectangulo ---\n";
            cout << "\tIngresa la base: ";
            cin >> base;
            cout << "\tIngresa la altura: ";
            cin >> altura;
            area = areaRectangulo (base,altura);
            cout << "\tEl area es: " << area << "\n";
            break;

        case 4:
            cout << "\n\t--- Calculando el Triangulo Equilatero ---\n";
            cout << "\tIngresa el lado: ";
            cin >> lado;
          
            area = areaTriangulo ( base,altura)
            cout << "El area es: " << area <<endl;
            break;

        default:
            cout << "\n\t[Error] Opcion no valida. Ejecute el programa de nuevo.\n";
            break;
    }

    return 0;
	
