/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 33 :
          Calcular el mínimo numero de bits para representar un 
          número.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>     // Inclusión de llamadas al sistema.
#include <cmath>      // Inclusión de recursos matemáticos.

using namespace std; 

enum class NumBits{caso_1, caso_2};

int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   NumBits num_bits ;
   
   const double DOS = 2.0;
   
   double numero;
   double bit;
   int bits;
   int cond_1;
   int cond_1_1;
  
	//Entrada de datos.
	
	cout << "\nIntroduzca el numero: ";
	cin >> numero;
	
	
	//Cálculos.
	
	/*LOG en base 2 del número de elementos nos da el número de bits
	necesario para almacenar dicho valor.
	Como van en potencia de dos, si el resutado es 2.65, el mínimo número 
	de bits será 3.
	*/
	
	bit =  (log(numero)) / log(DOS);
	bits = bit;
	cond_1 = bits+1;
	
	 if( bit > bits and bit < cond_1){
	 	
	 	cond_1_1 = bits + 1;
	   num_bits = NumBits::caso_1;
    	
     }
    
    if( bit == bits){
     	
     	bits = bit;
     	num_bits = NumBits::caso_2;
   
     }
     
     
     //Resultados.
     
     /*
     Si el número necista un valor real de bits para ser 
	  representado, 3.23 por ejmplo, puesto que no es posible,
	  el mínimo número de dígitos para su representación serán
	  4 dígitos. En este caso se da el "caso_1".
	  Si coincide con un valor entero, nos encontraremos en el "caso_2"
     */
     
     switch(num_bits){
     	case NumBits::caso_1:
     		cout << "\nEl resultado es: " << cond_1_1 << " bits" "\n";
     		break;
     	
     	case NumBits::caso_2:
     		cout << "\nEl resultado es: " << bits << " bits" "\n";
     		break;
     		
	  }

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
