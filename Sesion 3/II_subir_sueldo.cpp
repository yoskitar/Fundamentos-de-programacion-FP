/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01 - 03
         Problema n�mero 2 :
             Programa que lea una edad y un sueldo y aplique un aumento
             del 5% en caso de ser mayor de 55 a�os o cobrar menos de
             750�.
             Si no es posible mostrar un mensaje diciendolo.
         
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cctype>      // Inclusi�n de datos l�gicos.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   const double INTERES = 0.05;
   const double YEAR = 55;
   const double SAL_ACTUAL = 750;
   
   int edad;
   double salario;
   bool condicion_1;
   double salario_final;

   
   //Entrada de datos.
	
	cout << "\nIntroduzca la edad: ";
	cin >> edad;
	
		cout << "Introduzca su salario: ";
	cin >> salario;


	//C�lculos y resultados.
	 
	 /*
	 Establezco la condici�n que ser� verdadera en caso de ser menor
	 de 55 a�os y cobrar menos de 750�.
	 Si la condici�n es verdadera, se aplicar� la subida del sueldo
	 del 5%. Si es falsa y no se da esa condici�n, aparecer� por pantalla
	 un mensaje que diga que no es aplicable dicha subida.
	 */
	 
	 condicion_1 = edad>YEAR and salario<SAL_ACTUAL;
	 
	    if (condicion_1){
	    	
	    	salario_final=  (salario + (salario * INTERES));
	    	
	    	cout<< "\nSu salario final es de: " << salario_final <<" euros.";
	    	
	    }	
	    	  else{ 
				
				cout<< "\nNo es aplicable la subida.";
				cout<< "\nEl salario sigue siendo: " << salario << " euros.";
				 
			
				
				}

		 
	cout<< "\n";	 
		 
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
