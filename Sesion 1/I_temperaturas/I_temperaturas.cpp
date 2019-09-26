/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 28 :
            Programa para realizar un factor de conversión entre grados
            Celsius y grados Fahrenheit.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cmath>       // Inclusión de los recursos matemáticos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
  
   
   double celsius;              //Variables para calcular 
	double fahr;                //la conversión de temperatura.
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduca la temperatura en grados Celsius: ";
   cin >> celsius;
   
   
	// Cálculos.


   fahr = (celsius*180/100) + 32;        //Factor de conversión.
   
  
   //Resultados.
   
	cout << "\nLa temperatura es de: " << fahr << " Fahrenheit." "\n";

   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
