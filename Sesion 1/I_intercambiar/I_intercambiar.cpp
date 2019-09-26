/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 9 :
            Programa que intercambie los valores de dos variables 
            cuyo valor es introducido desde teclado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   double edad_Pedro;          //Declaramos las variables de las
   double edad_Juan;          //edades de Pedro y Juan y una tercera  
   double cambio;            //que nos será de ayuda para realizar el
                            //cambio del valor de dichas variables.
   
   // Entrada de datos.
   
   cout << "\nIntroduzca los años de Pedro: ";
   cin >> edad_Pedro;
   
   cout << "Introduzca los años de Juan: ";
   cin >> edad_Juan;
   
   
	// Cálculos.
	
	/* Asignamos a "cambio" el valor asignado a la 1ª variable. 
	El valor de esa  1ª variable adquiere ahora el valor de 
	la 2ª variable, y a esa 2ª variable le volvemos a asignar
	el valor que copiamos de la 1ª variable con la  variable "cambio". */
	
   cambio = edad_Pedro;              
   edad_Pedro = edad_Juan;          
   edad_Juan = cambio;             
   
   
  
   //Resultados
   //Variables con los valores cambiados.
   
	cout << "\nIntercambio de variables... " "\n";                     
	cout << "\nAhora Pedro tiene " << edad_Pedro << " años" "\n";
   cout << "Ahora Juan tiene " << edad_Juan << " años" "\n";
     
   //Pausa del programa.
   
   system("pause");   
   
	return (0);
}
