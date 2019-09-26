/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*       Sesion 01-05.
         Problema n�mero 16:
           Imprimir por pantalla los divisores de un n�mero entero
           utilizando un filtro para introducir solo enteros positivos.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.


using namespace std; 



int main(){ // Programa Principal.
            
            
   // Declara variables para guardar.
   
   int tope;
   int tope_menor;
   int tope_original;
   
   do{
	cout << "\nIntroduzca un entero positivo: ";
	cin >> tope;
	tope_original = tope;
	
   }while (tope <= 0);
   
   cout << "\nCalculando divisores: " << "\n";
   
   while(tope>0){
   	
   	tope_menor = tope;
   	
   	if (tope_original%tope_menor==0){
   	
		cout << "\n\t" << tope_menor << " es divisor de " 
		<< tope_original;
		
		}
		
   	tope_menor = tope - 1;
   	tope = tope -1;
   
	}
   
   cout << "\n\n";
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
