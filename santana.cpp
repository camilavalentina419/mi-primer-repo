// UN LICEO EVALUA MEDIANTE TRES EVALUACIONES CON UN PORTENTAJE DE 20%,30% Y 50% ,DADAS LAS NOTAS DE LA EVALUONES 1 Y 
// VERIFIQUE QUE NOTA DEBERIA SACAR EN LA TERCERA EVALUACION PARA APROBAR,SI ES POSIBLE LA ESCALA DE EVALUACION ES DE
// 1 A 10 Y SI APRUEBA CON NOTA MINIMA DE 6 NOTA MAIMA 10 


#include <iostream>
using namespace std;


int main(){

	float notauno=0;
	float notados=0;
	float notatres=0;
	 
	 # define NOTA_APROBATORIA 6.0
	 # define PESO3 0.5
	 # define PESO2 0.3
	 # define PESO1 0.2
	  
	 cout<<"ingrese el valor de notauno"<<endl;
	 cin>>notauno;
	 
	 cout<<"ingrese el valor de notados"<<endl;
	 cin>>notados; 
	 
	  cout<<"nota acumulada"<<endl;
	acumulada = notauno*PESO1+ notados*PESO2;
	out << acumulada << endl;
	
	cout<<"nota necesaria para aprobar"<<endl;
	necesaria=(NOTA_APROBATORIA-ACUMULADA)/PESO3;
	out << necesaria << endl;
	 

}
return 0;






 


