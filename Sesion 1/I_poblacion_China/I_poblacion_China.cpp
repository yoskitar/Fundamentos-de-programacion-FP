/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 5 :
            Programa que calcule la población china dentro de dos años 
            considerando unos datos previos de población actual,
            naciminetos, muertes y emigraciones.
           
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
		   
	const double POBLAC_ACTUAL = 1375570814;    //Constantes para poder 
   const double NACIM_S = 1.87;               //modificar su valor más
	const double MUERT_S = 3.27;              //facilmente si fuese necesario.
   const double EMIGRAC_S = 71.9;
   const double YEARS = 2;
   
	double nacimientos;            //Variables para calcular el número
	double muertes;               //de nacimientos, muertes, emigraciones.
	double emigraciones;
	double poblacion;                //Variable de la pobl. total en 2 años.
   double tiempo_year_seg;         //Variable para conversión de años a seg.
	
   
	// Cálculos
	
   //Factor de Conversión (años a segundos)	
   tiempo_year_seg = YEARS*365*24*60*60;    

   /* Cálculo del número de nacimientos, muertes y emigraciones en funcion  
   de la variable (AÑOS(2)). */
   nacimientos = tiempo_year_seg/NACIM_S;           
   muertes = tiempo_year_seg/MUERT_S;             
   emigraciones = tiempo_year_seg/EMIGRAC_S;      
   
   //Población transcurrido el tiempo indicado por la variable (AÑOS(2)).
   poblacion = POBLAC_ACTUAL + nacimientos - muertes - emigraciones;  

   //Resultados
   
	cout << "\nLa población de china en " << YEARS << " años será: " 
	<< poblacion << "\n";
   
   //Pausa del programa.
	  
   system("pause");
   
	return (0);
}
