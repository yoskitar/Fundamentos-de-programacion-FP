/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*      
         Sesi�n 01-04.
         Problema n�mero 10:
            Subid salario a una persona si es mayor de 65 o menor de 35 a�os
            un 4%, junto a una subida adicional del 3% en caso de cobrar
            menos de 300�.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.

using namespace std; 


int main(){ // Programa Principal.             
      
            
   // Declara variables para guardar.
   
   const double INTERES3 = 0.03;       //Inter�s del 3%.
   const double INTERES4 = 0.04;      //Inter�s del 4%.
   
   int edad;                 //Edad de la persona.
   double salario;          //Salario inicial o final con el 7% aplicado.
   double salario1;        //Salario con el 4% aplicado.
   
   
   //Entrada de datos.
	
	cout << "\nIntroduzca su edad: ";
	cin >> edad;
	
	cout << "\nIntroduzca su salario: ";
	cin >> salario;
	
		
	//C�lculos y resultados.
	
	/*
	Estructura condicional anidada en la que si la presona es mayor de 65 a�os
	o menor de 35 a�os, se le aplica una subida de un 4% a su salario. 
	Si adem�s cobra menos de 300 se le suma un 3% de inter�s adicional.
	En el caso de no ser ni menor de 35 ni mayor de 65 a�os, el salario
	se mantiene igual, sin ninguna subida aplicada.
	En todo caso sale por pantalla el salario final con el inter�s de subida
	aplicado.
	*/
	
	if (edad > 65 || edad < 35){
	
		salario1 = salario + (salario * INTERES4);
		
		if (salario < 300){
			
			salario = salario + (salario*(INTERES3 + INTERES4));
			
				cout << "\nSu salario final aplicado el 7% es de: "
				<< salario <<" euros." ;
			
		}
		
		else{
		
		cout << "\nSu salario final aplicado el 4% es de: "
				<< salario1 <<" euros.";
				
	  }
		
	}
	
	else{
	
		cout << "\nSu salario final sigue siendo: "
				<< salario <<" euros." ;

	}
			 
	cout << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
