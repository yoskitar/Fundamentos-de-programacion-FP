/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-12.
         Problema número 16:
           Programa para hallar el fibonacci de orden n hasta el tope k 
           mediante le utilizacion de vectores y los métodos correspondientes.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.
#include <cctype>     //Inclusion de recursos de caracteres.

using namespace std; 

//Declaración de la clase Fibonacci.
class Fibonacci{
	
	//Datos privados de la clase.
	private:
		
		int vector_fibo[200];
		int n;
		int valor_tope;
	
	//Datos públicos de la clase.	
	public:
		
		Fibonacci(int valor_n){
			
			n = valor_n;
			valor_tope = 0;
			
		}
		
		
	
	
	   // Función que calcula el número de Fibonacci de orden n, definida como: 
      //		fib(1) = 1
      //		fib(2) = 1
      //		fib(n) = fib(n-2) + fib(n-1) para n > 2
      //
      // Existe una versión recursiva para esta función que estudiaremos en
      // el tema 6. De hecho, es uno de los ejemplos típicos de recursividad. 
      //
      // Entrada: n
      // Salida: fib(n)
      //
      // PRE: n > 0

      void CalculaPrimeros (int k){ 

	      int ant1 = 1; // fib(2)
	      int ant2 = 1; // fib(1) 
	      vector_fibo[1] = ant1;
	      vector_fibo[2] = ant2;
	      valor_tope = k;
	      
	      for (int i=3 ; i<=k; i++) {
	      	
	      	int orden;
	      	int suma = 0;
	      	int cuenta = 0;
	      	
	      	for(orden = i - 1 ; orden >= 1 && cuenta < n ; orden--){ 
		         
               suma = vector_fibo[orden] + suma;
               
		         cuenta++;
		      
				}
				
				vector_fibo[i] = suma;
	      
			}
	   
      }
      
      
      //Función para devolver el valor del tope
      int TotalCalculados(void){
      	
      	return valor_tope;
      
      }
      
      
      //Funcion para devolver el valor de la secuencia de fibonacci 
      //de orden i.
      int Elemento(int i){
      	
      	int valor_secuencia;
      	
      	valor_secuencia = vector_fibo[i];
      	
      	return valor_secuencia;
      	
      }
	
};


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   int k = 10;
   int tope;
   int n = 4;
   
   Fibonacci secuencia(n);
   
  
  
	//Cálculos.

   secuencia.CalculaPrimeros(k);
   tope = secuencia.TotalCalculados();
   
   //Resultados.
   
   cout << "Tope: " <<tope <<endl;
   cout << "Secuecnia de Fibonacci de orden (" << n << "):" << endl;
   
   for (int i = 1 ; i<=tope ; i++){
   	
   	cout << secuencia.Elemento(i) << " ";
	
   }
  

	return (0);
	
}
