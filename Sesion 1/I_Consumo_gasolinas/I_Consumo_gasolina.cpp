/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 7 :
            Programa que calcule el consumo de gasolina, pidiendonos
            la distancia recorrida en kms, los litros de gasolina
            consumidos y los litros de gasolina que quedan en el depósito.
            Nos informará de tal modo del consumo en km/litro, 
            litros/100km, y cuantos km de autonomía le quedan con ese
            nivel de conbustible restante en el depósito.
                 
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
   
   
   double distan_re;
	double litros_cons;             //Variables para calcular los 
	double litros_dep;             //km/l recorridos, los l/100km consumidos,
   double km_lit;                //y el número de kms de autonomía con un
   double lit_100km;            //determinado nivel de gasolina restante.
   double km_rest;
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca los siguientes datos de la travesía... ";
   
   cout << "\n" "\nNúmero de kms recorridos: ";
   cin >> distan_re;
   
   cout << "Litros de gasolina consumidos: ";
   cin >> litros_cons;
   
   cout << "Litros de gasolina restantes en el depósito: ";
   cin >> litros_dep;
   
   
   
	// Cálculos.
	
//Distancia recorrida entre litros consumidos.
  km_lit = distan_re/litros_cons;  
//Litros consumidos a los 100 km.     
  lit_100km = 100*litros_cons/distan_re;
//kms de autonomía restantes con el consumo anterior.
  km_rest = litros_dep*100/lit_100km;
   
  
   //Resultados.
    
     
	cout << "\nDatos sobre el consumo de su vehículo:";
	cout << "\n" "\n    ·"  << km_lit << " kilómetros por litro consumido." ;
   cout << "\n    ·"  << lit_100km << " litros consumidos a los 100km." ;
   cout << "\n    ·" << km_rest << " kilómetros de autonomía restantes." "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
