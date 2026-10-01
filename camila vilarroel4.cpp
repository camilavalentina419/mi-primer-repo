// realice un programa que permita al usuario ingresar 3 numeros y diga cuales son los ivisores en comun.



#include <iostream>
using namespace std;
int main(){
	int numero1=0;
	int numero2=0;
	int numero3=0;
	
	cout<<"ingrese el valor de numero1"<<endl;
	cin>>numero1;
	
		
	cout<<"ingrese el valor de numero2"<<endl;
	cin>>numero2;
	
		
	cout<<"ingrese el valor de numero3"<<endl;
	cin>>numero3;

	
  for ( int i=1; i<999; i++){
		
		if(numero1%i==0 && numero2%i==0&& numero3%i==0){
		
	cout<<i <<" es un divisor en comun"<<endl;
	
	
		}
}

}
	
	





