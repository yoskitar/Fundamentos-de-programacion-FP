/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
// 
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
// 
// 
/* 
         Sesi�n 01-07.
         Problema n�mero 4:
           C�lculo del factorial o la potencia de un valor entero
           medinate funciones que controlen un men�, un filtro y 
           el c�lculo de la opci�n escogida.
           
*/        
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cctype>      //Inclusi�n de recursos de car�cter.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 



//Funci�n para el men�.
char Eleccion(string texto){
	
	char opcion;
	
	do{
	
	cout << texto;
	cin >> opcion;
	opcion = toupper(opcion);
	
   }while(opcion != 'P' && opcion != 'F');
	
	return opcion;
}


//Funci�n para filtrar el valor introducido.
int LeeEnteroPositivo(string mensaje){
	
	double entero_d;
	int entero;
	
	cout << mensaje;
	
	do{
		
		cin >> entero_d;
		entero = entero_d;
	
	}while(entero<0 && entero_d - entero != 0.0);
	
	return entero;

}

//Entrada de datos del exponente.
long long Exponente(string mensaje){

	long long exponent;
	
	cout << mensaje;
	cin >> exponent;
	
	return exponent;

}


//Funci�n para calcular la potencia.
//El ciclo for hace que se vaya multiplicando la base por s� misma
//actualizando su valor en cada vuelta hasta llegar a superar el exponente
//introducido.
long long Potencia(int base, int exponente){
	
	int n; 
	long long poten;
	
	poten = base;
	
	for(n=2 ; n <= exponente ; n++){
		
		poten = poten * base;
	
	}
	
	return poten;

}

//Funci�n para calcular el factorial de un n�mero.
//Si el entero introducido es 0 � 1 el factorial valdr� 1.
//En el caso de ser superior, encontramos un ciclo for que multiplicar�
//progresivamente el valor en ese momento de la func�on por 'total' que se
//incrementa en una unidad con cada vuelta, hasta legar al valor del n�mero
//introducido.
long long Factorial(int entero){
	
	long long fact;
	long long total;
	
	fact = 1;
	
	if (entero == 0 || entero == 1){
		
		fact = 1;
	
	}
	
	else{
		
		for(total = 2 ;total <= entero ; total++){
			
			fact = fact * total;
			
		}
	
	}
	
	return fact;
	 
}


int main(){
	
	//Declaraci�n de variables.
	
	bool potencia_b;   //Expresi�n �gica para controlar los condicionales.
	
	int entero;       //Valor del entero introducido.
	char eleccion;    //Opci�n elegida en el men�.
	
	long long factorial;   //Valor del factorial.
	long long exponente;   //Valor del ecponente.
	long long potencia;    //Valor de la potencia.
	
	//C�lculos y resultados.
	
	//Filtro para el entero.
	entero = LeeEnteroPositivo("\nIntroduzca un entero positivo: ");
	
	//Elecci�n del men�.
	eleccion = Eleccion("\n�Desea calcular su potencia(p) o el factorial(f)?");
	
	//Expresi�n l�gica para calcular la potencia en el condicional.
	potencia_b = ('P' == eleccion);
	
	
	//Si el car�cter introducido es una 'p' la estructua condicional calcular�
	//la potencia del valor introducido.
	//En el caso contrario, calcular� el factorial; cada uno con sus respectivas
	//funciones anteriormente definidas.  
	if ( potencia_b ){
		
		exponente = Exponente("\nIntroduzca el exponente al que desee elevarlo: ");
		potencia = Potencia(entero,exponente);
		
		cout <<"\nEl entero " <<entero <<"  elevado a " << exponente << " seria: " 
	   << potencia;
	
	}
	
	else{
		
		factorial = Factorial(entero);
		
		cout <<"\nEl factorial de " <<entero << " seria: " <<factorial;
	
	}
	
   return(0);
}
