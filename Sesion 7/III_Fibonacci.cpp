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
         Problema n�mero 6:
            C�lculo de un valor de la sucesi�n de Fibonacci mediante 
				funciones, as� como la sucesi�n hasta un valor introducido.
           
*/        
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Primera funci�n para ir transformando los valores en cadena de texto.
string ToString(int fn, string cadena){
	
	string texto;
	
	texto = to_string(fn) + ", ";
   texto = cadena + texto;
   
   return texto;

}

int Filtro(string mensaje){
	
	bool valores_correctos;
	int numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero;
	
	valores_correctos = numero <= 0 ;
	
	}while(valores_correctos);
	
	return numero;
	
}

//Funci�n para el c�lculo del valor de la sucesi�n en un punto determinado.
//Si el valor de 'n' es 1 � 2, la funci�n valdr�1.
//En caso de ser un valor mayor, encontramos un ciclo for que va sumando 
//y actualizando los valores de las variables hasta llegar al valor de
//'n' introducido.
int Fibonacci(int n){

   const int F1 = 1;
   const int F2 = 2;
   int fa;
   int fb;
   int fc;
	int fn;
   int inicio_n;
   
   fa = F1;
   fb = F1;
   fc = F1;
   
   if( (n == F1) || (n == F2) ){
   	
   	fn = F1;
	
	}
	
	else{
		
		for(inicio_n=3 ; inicio_n<=n ; inicio_n++){
			
			fn = fa+fb;
			fa = fn;
			fb = fc;
			fc = fa;
			
		}
		
	}
	
	return fn;
	
}

//Funci�n para hallar la secuencia entera hasta un valor concreto.
//En este caso, el procedimiento es el mismo que en el anterior, pero
//hacemos uso de la primera funci�n que va guardando los valores de
//la sucesi�n en una cadena de texto que luego se mostrar� en la salida. 
string FibonacciSecuencia(int n){

   const int F1 = 1;
   const int F2 = 2;
   int fa;
   int fb;
   int fc;
	int fn;
   int inicio_n;
   string secuencia_1;
   string secuencia;
   string cadena;
   
   fa = F1;
   fb = F1;
   fc = F1;
   cadena = "";
   
   if( (n == F1) || (n == F2) || ( n>=3 ) ){
   	
   	
   	for(inicio_n=1 ; inicio_n<=n ; inicio_n++){
			
			if(inicio_n <= 2){
			   
				fn = F1;
		
			   secuencia_1 = ToString(fn, cadena);
			   cadena = secuencia_1;
	         secuencia = secuencia_1;
	      }
			
		}
	
	   if(n>=3){
		
		  for(inicio_n=3 ; inicio_n<=n ; inicio_n++){
			
		   	fn = fa+fb;
			   fa = fn;
			   fb = fc;
			   fc = fa;
			
			   secuencia = ToString(fn, cadena);
			   cadena = secuencia;
            	
		   }
		
	   }
	
	}
	
	return secuencia;
	
}
	
	
	
	
int main(){

   //	Declaraci�n de variables;

	int n;                //Entero natural introducido.
	int k;                //Valor para calcular la secuencia hasta el orden k.
   int valor_fibonacci;          //Valor en f(n).
   string secuencia_fibonacci;   //Valor de la secuencia hasta k.
   
   
   
   
	//	Entrada de datos 1.
	n = Filtro("\nIntroduzca el valor de 'n' para calcular f(n)"
	" atendiendo a la secuencia de Fibonacci: ");
	
   
   // Calculos 1.
   valor_fibonacci = Fibonacci(n);
   
	
   //	Salida de datos 1.
	cout << "\nEl valor de f(" << n <<")" << " segun la secuencia de "
	<<"Fibonacci es: " << valor_fibonacci << "\n\n";
	
	
   //	Entrada de datos 2.
	k = Filtro("\nIntroduzca el valor de 'k' para mostrar la secuencia"
	" hasta dicho valor: ");
		
   
   // Calculos 2.
   secuencia_fibonacci = FibonacciSecuencia(k);
   
   
   // Salida de datos 2.
   cout << "\nLa secuencia de Fibonacci para el valor de k (" << k <<") "
	<< "introducido seria: " <<secuencia_fibonacci <<"\n\n";
   	

	return(0);
}




