/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 28 :
            Programa para realizar un factor de conversi�n entre grados
            Celsius y grados Fahrenheit.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cmath>       // Inclusi�n de los recursos matem�ticos.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
  
   
   double celsius;              //Variables para calcular 
	double fahr;                //la conversi�n de temperatura.
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduca la temperatura en grados Celsius: ";
   cin >> celsius;
   
   
	// C�lculos.


   fahr = (celsius*180/100) + 32;        //Factor de conversi�n.
   
  
   //Resultados.
   
	cout << "\nLa temperatura es de: " << fahr << " Fahrenheit." "\n";

   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
