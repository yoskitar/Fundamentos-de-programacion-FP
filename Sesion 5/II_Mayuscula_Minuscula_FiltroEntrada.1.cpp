/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*       Sesion 01-05.
         Problema n�mero 14:
           Leer caracter may�scula desde teclado y repetir acci�n
           con un filtro en caso de que no lo sea.Versi�n sin tolower
           ni toupper.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.


using namespace std; 



int main(){ // Programa Principal.
            
            
   // Declara variables para guardar.
   
   char caracter;
   bool minuscula;
   char caracter_min;
   char diferencia;
	
	
	do{
		
	cout << "\nIntroduzca una letra mayuscula: ";
	cin >> caracter;
	
	minuscula = ((caracter >= ('a')) && (caracter <= ('z')));
	
	  if (!minuscula){
	  	
	  	diferencia = 'A'-'a';
	  	caracter_min = caracter - diferencia;
   
      cout << "\nLa minuscula de " << caracter <<" es: " 
      << caracter_min << "\n";
      
	  }
	  
   }while (minuscula);
   
   
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
