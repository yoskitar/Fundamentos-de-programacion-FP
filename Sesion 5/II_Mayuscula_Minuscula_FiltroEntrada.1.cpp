/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*       Sesion 01-05.
         Problema número 14:
           Leer caracter mayúscula desde teclado y repetir acción
           con un filtro en caso de que no lo sea.Versión sin tolower
           ni toupper.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>     // Inclusión de llamadas al sistema.


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
