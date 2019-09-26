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
         Problema n�mero 15 :
            Dadas unas horas,  minutos y segundos, expresarlos en su 
            rango correspondiente.
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

   const int FACT = 60;      //Factor entre horas<->min ; min<->seg.
   const int FACT_2 = 24;   //Factor entre horas<->dias ; dias<->horas.
   
	int horas, minutos, segundos, horas_1, min_1, seg_1, dias;
	int min_1_1;
	
   //Entrada de datos .
   
   cout <<"\nIntroduzca las horas: " ;
   cin >> horas_1;
   
   cout << "Introduzca los minutos: ";
   cin >> min_1;
   
   cout << "Introduzca los segundos: ";
   cin >> seg_1;
   
   
	//C�lculos.
	  /*
	  Vamos calculando el n�mero de horas, minutos y segundos dentro
	  de su rango medianto los operadores "%" y "/" y las constantes 
	  (FACT=60) Y (FACT_2=24) para ir agrupando las horas, minutos 
	  y segundos dentro de su rango correspondiente.
	  Con el caso del problema: 10h 119min 280seg las operaciones nos
	  hir�an quedando tal que as�:
	  */
	  
     segundos = seg_1 % FACT; //40
     min_1_1 = (seg_1 / FACT) + (min_1 % FACT); //4+59=63
     minutos = min_1_1 % FACT; //3
     horas = horas_1 + (min_1 / FACT) + (min_1_1 / FACT); //10+1+1=12 	
	  dias = horas / FACT_2; // 12/24=0.5 => Al ser int, = 0
	  horas = horas % FACT_2; 
	
   //Resultados.
   
	cout << "\nEl resultado ser�an: " <<"\n";
	
	cout << "\n\t�" << segundos <<" segundos.";
	cout << "\n\t�" << minutos <<" minutos.";
	cout << "\n\t�" << horas <<" horas.";
	cout << "\n\t�" << dias <<" dias." "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
