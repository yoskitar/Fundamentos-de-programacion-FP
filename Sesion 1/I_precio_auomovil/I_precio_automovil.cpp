/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 27 :
            Programa para obtener el precio final de un autom�vil sabiendo
            que es la suma del costo del veh�culo, el porentaje de ganancia
            del vendedor, y el IVA aplicado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cmath>       // Inclusi�n de los recursos matem�ticos.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
   
   const double IVA = 0.16;               // Porcentajes de inter�s e IVA.
   const double VENDEDOR = 0.2;         
   
   double coche;                    //Costo y precio final del veh�culo.
	double total;                
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca el costo del veh�culo: ";
   cin >> coche;
   
   
	// C�lculos.

/* Suma del costo del vehiculo m�s el % de ganacias 
del vendedor y la parte correspondiente al IVA. */
   total = IVA*coche + VENDEDOR*coche + coche; 

   //Resultados.
   
   cout << "\nAplicaci�n de inter�s e IVA...";
	cout << "\nEl precio de venta del veh�culo es: " << total << " �" "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
