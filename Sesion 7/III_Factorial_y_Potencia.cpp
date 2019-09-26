/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
// 
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
// 
// 
/* 
         Sesión 01-07.
         Problema número 4:
           Cálculo del factorial o la potencia de un valor entero
           medinate funciones que controlen un menú, un filtro y 
           el cálculo de la opción escogida.
           
*/        
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cctype>      //Inclusión de recursos de carácter.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 



//Función para el menú.
char Eleccion(string texto){
	
	char opcion;
	
	do{
	
	cout << texto;
	cin >> opcion;
	opcion = toupper(opcion);
	
   }while(opcion != 'P' && opcion != 'F');
	
	return opcion;
}


//Función para filtrar el valor introducido.
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


//Función para calcular la potencia.
//El ciclo for hace que se vaya multiplicando la base por sí misma
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

//Función para calcular el factorial de un número.
//Si el entero introducido es 0 ó 1 el factorial valdrá 1.
//En el caso de ser superior, encontramos un ciclo for que multiplicará
//progresivamente el valor en ese momento de la funcíon por 'total' que se
//incrementa en una unidad con cada vuelta, hasta legar al valor del número
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
	
	//Declaración de variables.
	
	bool potencia_b;   //Expresión ógica para controlar los condicionales.
	
	int entero;       //Valor del entero introducido.
	char eleccion;    //Opción elegida en el menú.
	
	long long factorial;   //Valor del factorial.
	long long exponente;   //Valor del ecponente.
	long long potencia;    //Valor de la potencia.
	
	//Cálculos y resultados.
	
	//Filtro para el entero.
	entero = LeeEnteroPositivo("\nIntroduzca un entero positivo: ");
	
	//Elección del menú.
	eleccion = Eleccion("\n¿Desea calcular su potencia(p) o el factorial(f)?");
	
	//Expresión lógica para calcular la potencia en el condicional.
	potencia_b = ('P' == eleccion);
	
	
	//Si el carácter introducido es una 'p' la estructua condicional calculará
	//la potencia del valor introducido.
	//En el caso contrario, calculará el factorial; cada uno con sus respectivas
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
