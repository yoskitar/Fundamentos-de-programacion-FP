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
         Problema número 20 :
            Pasar una letra mayúscula a minúscula sin usar toupper
            ni tolower.
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   char mayuscula;               //Variables de tipo caracter.
   char diferencia;
   char minuscula;
   
	//Entrada de datos.
	
	cout << "\nIntroduzca la letra mayúscula: ";
	cin >> mayuscula;
	
	
	//Cálculos.
	
	/*Calculamos la diferencia en la tabla de valores ASCII, 
	siendo nuestra minúscula el valor correspondiente a la mayúscula
	más esa diferencia.
	*/
	
	diferencia = 'A' - 'a';                   
	minuscula = mayuscula - diferencia;
	
   //Resultados.
   
	cout << "\nLa minúscula de " << mayuscula << " sería: " << minuscula << "\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
