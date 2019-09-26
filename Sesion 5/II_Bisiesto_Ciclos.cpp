/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
         Sesi�n 01 - 05.
         Problema n�mero 23:
            Calcular n�mero de a�os bisiestos que hay entre
            un intervalo de dos a�os introducido desde teclado.
            
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cctype>      // Inclusi�n de datos l�gicos.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
         
   // Declaraci�n de variables para guardar.
   
   bool year_b;
   bool year_4_b;
   bool year_100_b;
   bool year_400_b;
   int year_400;
   int year;
   int year_4;
   int year_100;
   int year_inic;


   //Entrada de datos.
   
	cout << "\nIntroduzca el primer a�o del intervalo: ";
	cin >> year_inic;
	
	do{
		
	cout << "\nIntroduzca el segundo a�o a�o del intervalo: ";
	cin >> year;
	
   }while( year < year_inic );


   //C�lculos.
	
	while (year >= year_inic){
	//Si al dividir el a�o entre 4 el resto es cero.
	//es decir, es divisible por 4.
   year_4 = year % 4;
   year_4_b = year_4 == 0;
   
	//Si al dividir el a�o entre 100 el resto es distinto de cero,
	//es decir, no es divisible por 100. 	
   year_100 = year % 100;
   year_100_b = year_100 !=0;
   
   //Es bisiesto si es divisible por 4 pero no por 100.
   year_b = year_4_b && year_100_b;
   
   //Si al dividir el a�o entre 400 el resto es  cero,
	//es decir, es divisible por 400.
   year_400 = year % 400;
   year_400_b = year_400 == 0;
   
   //Es divisible por 4 pero no por 100, o, es devisible por 400.
   year_b = year_400_b || year_b;
   
   
   //Resultados.
   
    if(year_b){
	 
	 cout << "\n\tEl a�o " << year << " es bisiesto." ;
	 
	 }
	 
   year = year - 1;
   
	}
	
	cout << "\n\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
