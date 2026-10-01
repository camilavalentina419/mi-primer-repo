//realice un programa que reciba un monto en bs y un a tasa de conversion a dolares y devuelva el monto en dolares

#include<iostream>
using namespace std;
int main(){
	float montoBs= 0;
	float tasaDolar= 0;
	float resultado= 0;
	
	cout<<"ingrese monto en bs"<< endl;
	cin>>montoBs;
	cout<<"ingrese tasa dolar actual"<< endl;
	cin>>tasaDolar;
	if(montoBs>=0){
		resultado= montoBs/ tasaDolar;
		cout<<"su monto en dolares es"<<resultado<<endl;
		}
		
	else{
	cout<<"ingrese monto valido\n";
}
		
	return 0;
}
