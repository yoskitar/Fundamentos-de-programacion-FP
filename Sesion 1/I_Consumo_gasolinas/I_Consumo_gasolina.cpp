/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 7 :
            Programa que calcule el consumo de gasolina, pidiendonos
            la distancia recorrida en kms, los litros de gasolina
            consumidos y los litros de gasolina que quedan en el dep�sito.
            Nos informar� de tal modo del consumo en km/litro, 
            litros/100km, y cuantos km de autonom�a le quedan con ese
            nivel de conbustible restante en el dep�sito.
                 
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
   
   
   double distan_re;
	double litros_cons;             //Variables para calcular los 
	double litros_dep;             //km/l recorridos, los l/100km consumidos,
   double km_lit;                //y el n�mero de kms de autonom�a con un
   double lit_100km;            //determinado nivel de gasolina restante.
   double km_rest;
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca los siguientes datos de la traves�a... ";
   
   cout << "\n" "\nN�mero de kms recorridos: ";
   cin >> distan_re;
   
   cout << "Litros de gasolina consumidos: ";
   cin >> litros_cons;
   
   cout << "Litros de gasolina restantes en el dep�sito: ";
   cin >> litros_dep;
   
   
   
	// C�lculos.
	
//Distancia recorrida entre litros consumidos.
  km_lit = distan_re/litros_cons;  
//Litros consumidos a los 100 km.     
  lit_100km = 100*litros_cons/distan_re;
//kms de autonom�a restantes con el consumo anterior.
  km_rest = litros_dep*100/lit_100km;
   
  
   //Resultados.
    
     
	cout << "\nDatos sobre el consumo de su veh�culo:";
	cout << "\n" "\n    �"  << km_lit << " kil�metros por litro consumido." ;
   cout << "\n    �"  << lit_100km << " litros consumidos a los 100km." ;
   cout << "\n    �" << km_rest << " kil�metros de autonom�a restantes." "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
