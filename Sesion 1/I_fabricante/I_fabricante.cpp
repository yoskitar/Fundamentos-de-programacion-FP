/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 8 :
            Programa que pida la ganancia total de la empresa y 
            la parte de esa ganacia que le corresponde a cada uno
            de los integrantes de la empresa.
           
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

	double gan_dise;             //Variables para calcular la parte
	double gan_fab;             //de las ganancias que le corresponder�a
   double gan_empresa;        //a cada uno de las partes.

   //Entrada de datos
   
   cout << "\nIntroduzca la ganacia total de la empresa ";
   cout << "en euros: ";
   cin >> gan_empresa;
   
	// C�lculos

	gan_dise = 40*gan_empresa/100 ;     //Al dise�ador le corresponder�a el 40%
   gan_fab = 20*gan_empresa/100 ;     //y a cada fabricante un 20% de los 
                                     //beneficios.
   
  
   //Resultados
   
	cout << "\nEl dise�ador cobrar�: " << gan_dise << " euros" "\n";
	cout << "Cada fabricante cobrar�: " << gan_fab << " euros" "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
