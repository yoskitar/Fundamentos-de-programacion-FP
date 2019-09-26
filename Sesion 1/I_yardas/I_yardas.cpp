/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 4 :
            Programa que pida una longuitud en yardas y exprese 
            esa distancia en millas, pies, y pulgadas.
           
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
   
   const double YAR_MET = 0.9144;          //Equivalencia en metros de 
   const double PUL_MET = 0.0254;         //de cada unidad de medida.
   const double PIE_MET = 0.3048;
   const double MILL_MET = 1609.344;
   
   double metros;
	double yardas;                //Variables para calcular la
	double pulgadas;             //conversi�n de yardas a cada
   double pies;                //una de las medidas pedidas.
   double millas;
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca la longuitud en yardas: ";
   cin >> yardas;
   
   
	// C�lculos.


   metros = YAR_MET*yardas;             //Factores de conversi�n.
   pulgadas = metros/PUL_MET;
   pies = metros/PIE_MET;
   millas = metros/MILL_MET;
   
  
   //Resultados.
   
	cout << "\n" << yardas << " yardas son: "  "\n"  ;
	cout << "\n    �"  << pulgadas << " pulgadas" ;
   cout << "\n    �"  << pies << " pies" ;
   cout << "\n    �" << millas << " millas" "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
