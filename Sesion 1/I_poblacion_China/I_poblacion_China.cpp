/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 5 :
            Programa que calcule la poblaci�n china dentro de dos a�os 
            considerando unos datos previos de poblaci�n actual,
            naciminetos, muertes y emigraciones.
           
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
		   
	const double POBLAC_ACTUAL = 1375570814;    //Constantes para poder 
   const double NACIM_S = 1.87;               //modificar su valor m�s
	const double MUERT_S = 3.27;              //facilmente si fuese necesario.
   const double EMIGRAC_S = 71.9;
   const double YEARS = 2;
   
	double nacimientos;            //Variables para calcular el n�mero
	double muertes;               //de nacimientos, muertes, emigraciones.
	double emigraciones;
	double poblacion;                //Variable de la pobl. total en 2 a�os.
   double tiempo_year_seg;         //Variable para conversi�n de a�os a seg.
	
   
	// C�lculos
	
   //Factor de Conversi�n (a�os a segundos)	
   tiempo_year_seg = YEARS*365*24*60*60;    

   /* C�lculo del n�mero de nacimientos, muertes y emigraciones en funcion  
   de la variable (A�OS(2)). */
   nacimientos = tiempo_year_seg/NACIM_S;           
   muertes = tiempo_year_seg/MUERT_S;             
   emigraciones = tiempo_year_seg/EMIGRAC_S;      
   
   //Poblaci�n transcurrido el tiempo indicado por la variable (A�OS(2)).
   poblacion = POBLAC_ACTUAL + nacimientos - muertes - emigraciones;  

   //Resultados
   
	cout << "\nLa poblaci�n de china en " << YEARS << " a�os ser�: " 
	<< poblacion << "\n";
   
   //Pausa del programa.
	  
   system("pause");
   
	return (0);
}
