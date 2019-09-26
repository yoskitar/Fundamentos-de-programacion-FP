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
#include <cctype>       // Inclusión de datos lógicos.
#include <cstdlib>     // Inclusión de llamadas al sistema.
#include <cmath>      // Inclusión de recursos matemáticos.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
   
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
	 	
      //Resultados 1.
   
    	cout << "\nEl resultado es: " << cond_1_1 << " bits" "\n";
    	
    	system("pause");
   
	return (0);
    	
    }
    
    if( bit == bits){
     	
     	bits = bit;
     	
     	//Resultados 2.
   
    	cout << "\nEl resultado es: " << bits << " bits" "\n";
     	
     }

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
