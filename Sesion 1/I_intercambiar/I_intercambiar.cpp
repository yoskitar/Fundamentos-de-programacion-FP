/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 9 :
            Programa que intercambie los valores de dos variables 
            cuyo valor es introducido desde teclado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   double edad_Pedro;          //Declaramos las variables de las
   double edad_Juan;          //edades de Pedro y Juan y una tercera  
   double cambio;            //que nos ser� de ayuda para realizar el
                            //cambio del valor de dichas variables.
   
   // Entrada de datos.
   
   cout << "\nIntroduzca los a�os de Pedro: ";
   cin >> edad_Pedro;
   
   cout << "Introduzca los a�os de Juan: ";
   cin >> edad_Juan;
   
   
	// C�lculos.
	
	/* Asignamos a "cambio" el valor asignado a la 1� variable. 
	El valor de esa  1� variable adquiere ahora el valor de 
	la 2� variable, y a esa 2� variable le volvemos a asignar
	el valor que copiamos de la 1� variable con la  variable "cambio". */
	
   cambio = edad_Pedro;              
   edad_Pedro = edad_Juan;          
   edad_Juan = cambio;             
   
   
  
   //Resultados
   //Variables con los valores cambiados.
   
	cout << "\nIntercambio de variables... " "\n";                     
	cout << "\nAhora Pedro tiene " << edad_Pedro << " a�os" "\n";
   cout << "Ahora Juan tiene " << edad_Juan << " a�os" "\n";
     
   //Pausa del programa.
   
   system("pause");   
   
	return (0);
}
