/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 13 :
            Dos programas que me permitan hacer un factor de conversión
            entre velocidad y ritmo. El primero leerá el ritmo y mostrará 
            la velocidad; mientras que el segunda leerá la velocidad y 
            mostrará el ritmo.
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

   const double FACT = 60;      //Factor entre horas<->min ; min<->seg.
   
	double rit_min;             //Variables para calcular la conversión de 
	double rit_seg;            //ritmo a velocidad.
	double rit_min_hor;
	double rit_seg_hor;
	double hor_1;
	double ritmo_velo;      
	
	int min;                  //Variables para calcular la conversión de 
	int seg;                 //velocidad a ritmo.
	double min_seg;
	double velo;
	double fact_2;
	double vel_hor_min;
	
   
   //Entrada de datos 1.
   
   cout <<"\nIntroduzca su ritmo..." "\n";
   
   cout << "\nIntroduzca los minutos: ";
   cin >> rit_min;
   
   cout << "Introduzca los segundos: ";
   cin >> rit_seg;
   
   
	//Cálculos ritmo a velocidad.
     
   rit_min_hor = rit_min/FACT;             //Conversión de los min. a horas.
   rit_seg_hor = rit_seg/(FACT*FACT);     //Conversión de los seg. a horas.
   hor_1 = rit_min_hor + rit_seg_hor;    //Total de tiempo en recorrer 1km.
   ritmo_velo = 1/hor_1;                  //Velocidad a partir de la 
                                         //expresón matemática de ésta (x/t).
   
	
	 //Resultados ritmo a velocidad.
   
	cout << "\nLa velocidad sería de: " << ritmo_velo << " km/h" "\n";
	
  
  //Separación entre programas.
  
  cout << "\n""\n""\n";
  
  //Entrada de datos 2.
  
  cout << "Introduzca su velocidad..." "\n";
  
  cout << "\nIntroduzca su velocidad en km/h: ";
  cin >> velo;
  
  //Cálculos velocidad a ritmo.

//Calculo cuanto tardo en recorrer 1km a una velocidad(velo).
  fact_2 = 1/velo; 
//Paso ese tiempo en horas a minutos.  
  vel_hor_min = fact_2*60;    
//Asigno a una variable int el valor de la variable anterior.    
  min = vel_hor_min; 
//Resto al total de minutos su parte entera.                
  min_seg = vel_hor_min - min;  
//La parte decimal los multiplico por 60 para hallar los seg.   
  seg = min_seg*FACT;                
  
  
   //Resultados velocidad a ritmo.
   
	cout << "\nEl ritmo sería de: " << min; 
	cout << " min" " y " << seg << " seg" "\n";

   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
