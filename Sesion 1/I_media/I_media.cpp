/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 10 :
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

	double al_1;              //Variables a las que le asignaremos un 
	double al_2;             //valor como dato de cada una de las 3 
   double al_3;            //alturas.
   double med;               //Variables con las que calcularemos la
   double desv;              //media y la desviaci�n est�ndar.
   
   //Entrada de datos
   
   cout << "\nIntroduzca la altura de la 1� persona (metros): ";
   cin >> al_1;
   
    cout << "Introduzca la altura de la 1� persona (metros): ";
   cin >> al_2;
   
    cout << "Introduzca la altura de la 1� persona (metros): ";
   cin >> al_3;
   
	// C�lculos
	
	/* Calculamos la media como el sumatorio de cada una de las tres alturas
	dividido entre el numero de alturas que tenemos (3).
	Calculamos la desviaci�n est�ndar como la ra�z del sumatorio 
	de los valores de cada una de las alturas menos la media artim�tica al 
	cuadrado, dividido entre el numero de datos que tengamos (3).*/ 
   

	med = (al_1 + al_2 + al_3)/3;
   desv = sqrt((pow(al_1 - med,2) + pow(al_2 - med,2) + pow(al_3 - med,2))/3);
  
   //Resultados
   
   /*Saca por consola los valores resultantes de la media y la desviaci�n estandar
	en funci�n de los valores de las alturas introducidos.*/
	
	cout << "\nEl valor de la media es: " << med << " metros" "\n";
	cout << "El valor de la desviaci�n es: " << desv << " metros" "\n";
   
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
