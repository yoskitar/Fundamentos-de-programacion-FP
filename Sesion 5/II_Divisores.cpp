/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*       Sesion 01-05.
         Problema número 16:
           Imprimir por pantalla los divisores de un número entero
           utilizando un filtro para introducir solo enteros positivos.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>     // Inclusión de llamadas al sistema.


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
