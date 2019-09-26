/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*       
         Sesi�n 01 - 03
         Problema n�mero 20 :
            Pasar una letra may�scula a min�scula sin usar toupper
            ni tolower.
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   char mayuscula;               //Variables de tipo caracter.
   char diferencia;
   char minuscula;
   
	//Entrada de datos.
	
	cout << "\nIntroduzca la letra may�scula: ";
	cin >> mayuscula;
	
	
	//C�lculos.
	
	/*Calculamos la diferencia en la tabla de valores ASCII, 
	siendo nuestra min�scula el valor correspondiente a la may�scula
	m�s esa diferencia.
	*/
	
	diferencia = 'A' - 'a';                   
	minuscula = mayuscula - diferencia;
	
   //Resultados.
   
	cout << "\nLa min�scula de " << mayuscula << " ser�a: " << minuscula << "\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
