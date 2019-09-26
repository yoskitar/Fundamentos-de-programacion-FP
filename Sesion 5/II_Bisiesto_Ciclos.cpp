/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
         Sesión 01 - 05.
         Problema número 23:
            Calcular número de años bisiestos que hay entre
            un intervalo de dos años introducido desde teclado.
            
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cctype>      // Inclusión de datos lógicos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
         
   // Declaración de variables para guardar.
   
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
   
	cout << "\nIntroduzca el primer año del intervalo: ";
	cin >> year_inic;
	
	do{
		
	cout << "\nIntroduzca el segundo año año del intervalo: ";
	cin >> year;
	
   }while( year < year_inic );


   //Cálculos.
	
	while (year >= year_inic){
	//Si al dividir el año entre 4 el resto es cero.
	//es decir, es divisible por 4.
   year_4 = year % 4;
   year_4_b = year_4 == 0;
   
	//Si al dividir el año entre 100 el resto es distinto de cero,
	//es decir, no es divisible por 100. 	
   year_100 = year % 100;
   year_100_b = year_100 !=0;
   
   //Es bisiesto si es divisible por 4 pero no por 100.
   year_b = year_4_b && year_100_b;
   
   //Si al dividir el año entre 400 el resto es  cero,
	//es decir, es divisible por 400.
   year_400 = year % 400;
   year_400_b = year_400 == 0;
   
   //Es divisible por 4 pero no por 100, o, es devisible por 400.
   year_b = year_400_b || year_b;
   
   
   //Resultados.
   
    if(year_b){
	 
	 cout << "\n\tEl año " << year << " es bisiesto." ;
	 
	 }
	 
   year = year - 1;
   
	}
	
	cout << "\n\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
