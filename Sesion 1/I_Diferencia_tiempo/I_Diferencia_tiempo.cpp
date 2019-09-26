/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 16 :
            Programa para calcular la diferencia en segundos entre dos 
            instantes del día.
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

	double hor_i;           
	double min_i;             
   double seg_i;       
   double hor_f;
   double min_f;
   double seg_f;
   double dif;
   double inst_i;
   double inst_f;
   
   //Entrada de datos
   
   cout << "\nDatos del instante inical...: ";
   
   cout << "\nIntruduzca la hora: ";
   cin >> hor_i;
   
   cout << "Introduzca el minuto: ";
   cin >> min_i;
   
   cout << "Introduzca el segundo: ";
   cin >> seg_i;
   
   
   cout << "\n""\n";
   
   
   cout << "\nDatos del instante final: ";
   
   cout << "Introduzca la hora: ";
   cin >> hor_f;
   
   cout << "Introduzca el minuto: ";
   cin >> min_f;
   
   cout << "Introduzca el segundo: ";
   cin >> seg_f;
   
   
	// Cálculos
  inst_i = hor_i*3600 + min_i*60 + seg_i;
  inst_f = hor_f*3600 + min_f*60 + seg_f;
  dif = inst_f - inst_i;
  
   //Resultados
   
	cout << "\nLa diferencia entre ambos ";
	cout << "instantes es de: " << dif << " seg" "\n";

   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
