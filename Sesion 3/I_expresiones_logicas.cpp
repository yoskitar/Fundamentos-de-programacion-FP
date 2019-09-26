/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
         Sesión 01 - 03
         Problema número 25 :
           Expresiones lógicas para los siguientes casos:
            ·Minúscula:TRUE Mayúscula:FALSE
            ·18<A>65: TRUE
            ·X / 4 AND A!/100:TRUE ó X / 400: TRUE
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cctype>      // Inclusión de datos lógicos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar1.

   bool letra_b;
   char letra;
   
   // Declara variables para guardar2.
   
   bool edad_b;
   int edad;
  
   // Declara variables para guardar3.
   
   bool year_b;
   bool year_4_b;
   bool year_100_b;
   bool year_400_b;
   int year_400;
   int year;
   int year_4;
   int year_100;
   
    
	//Entrada de datos1.
	
	cout << "\nIntroduzca una letra: ";
	cin >> letra;
	
	
	//Cálculos1.
	
	//Si la letra introducida esta dentro de los valores de la tabla ASCII
	//respectivos a las minúsculas el valor es true.
	letra_b = letra >= 'a' and letra <= 'z';
	
	
   //Resultados1.
   
	cout << "\nEl resultado es: " << letra_b << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
   
   
   	//Entrada de datos2.
	
	cout << "\nIntroduzca su edad en años: ";
	cin >> edad;
	
	
	//Cálculos2.
	
	//Establezco que sea verdad dentro de un intervalo [18,65]
	edad_b = edad <= 65 and edad >= 18;
	//Si no está en ese intervalo el valor es true.
   edad_b = !edad_b;  
	
	
   //Resultados2.
   
	cout << "\nEl resultado es: " << edad_b << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
   
   
   //Entrada de datos3.
	
	cout << "\nIntroduzca el año que desee saber si es bisiesto: ";
	cin >> year;


	//Cálculos3.
	
	//Si al dividir el año entre 4 el resto es cero.
	//es decir, es divisible por 4.
   year_4 = year % 4;
   year_4_b = year_4 ==0;
   
	//Si al dividir el año entre 100 el resto es distinto de cero,
	//es decir, no es divisible por 100. 	
   year_100 = year % 100;
   year_100_b = year_100 !=0;
   
   //Es bisiesto si es divisible por 4 pero no por 100.
   year_b = year_4_b and year_100_b;
   
   //Si al dividir el año entre 400 el resto es  cero,
	//es decir, es divisible por 400.
   year_400 = year % 400;
   year_400_b = year_400 ==0;
   
   //Es divisible por 4 pero no por 100, o, es devisible por 400.
   year_b = year_400_b || year_b;
   
   
   //Resultados3.
   
	cout << "\nEl resultado es: " << year_b << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
