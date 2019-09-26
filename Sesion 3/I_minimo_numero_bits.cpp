/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 33 :
          Calcular el m�nimo numero de bits para representar un 
          n�mero.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cctype>       // Inclusi�n de datos l�gicos.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.
#include <cmath>      // Inclusi�n de recursos matem�ticos.

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
	
	
	//C�lculos.
	
	/*LOG en base 2 del n�mero de elementos nos da el n�mero de bits
	necesario para almacenar dicho valor.
	Como van en potencia de dos, si el resutado es 2.65, el m�nimo n�mero 
	de bits ser� 3.
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
