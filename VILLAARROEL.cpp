// realice un pograma que permita ecibir un numero por teclado entre 100 y 999 y lo devuelva invertido,ademas diga si es numero es capicua 





#include <iostream>
using namespace std;
int main(){

	int numero=0 ;
    int Invertido;
	
	cout<<"ingrese un numero "<<endl;
	cin>>numero;
	
	if (numero>=100 && numero<=999){
	int centena=numero/100;
   int 	decena=(numero/10)%10;
  int 	unidad=numero%10;
	
	Invertido=(unidad*100)+(decena*10)+centena;
	 cout<<"el numero Invertido:"<<Invertido<<endl;

    if (numero == Invertido) {
        cout << "Es capicua." << endl;
    } else {
        cout << "No es capicua." << endl;
    }

    return 0;

}
}





