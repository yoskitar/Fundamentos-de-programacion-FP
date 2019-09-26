/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 27 :
            Programa para obtener el precio final de un automóvil sabiendo
            que es la suma del costo del vehículo, el porentaje de ganancia
            del vendedor, y el IVA aplicado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cmath>       // Inclusión de los recursos matemáticos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
   
   const double IVA = 0.16;               // Porcentajes de interés e IVA.
   const double VENDEDOR = 0.2;         
   
   double coche;                    //Costo y precio final del vehículo.
	double total;                
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca el costo del vehículo: ";
   cin >> coche;
   
   
	// Cálculos.

/* Suma del costo del vehiculo más el % de ganacias 
del vendedor y la parte correspondiente al IVA. */
   total = IVA*coche + VENDEDOR*coche + coche; 

   //Resultados.
   
   cout << "\nAplicación de interés e IVA...";
	cout << "\nEl precio de venta del vehículo es: " << total << " €" "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
