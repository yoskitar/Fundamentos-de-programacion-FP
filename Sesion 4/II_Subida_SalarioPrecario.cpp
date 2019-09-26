/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*      
         Sesión 01-04.
         Problema número 10:
            Subid salario a una persona si es mayor de 65 o menor de 35 años
            un 4%, junto a una subida adicional del 3% en caso de cobrar
            menos de 300€.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>     // Inclusión de llamadas al sistema.

using namespace std; 


int main(){ // Programa Principal.             
      
            
   // Declara variables para guardar.
   
   const double INTERES3 = 0.03;       //Interés del 3%.
   const double INTERES4 = 0.04;      //Interés del 4%.
   
   int edad;                 //Edad de la persona.
   double salario;          //Salario inicial o final con el 7% aplicado.
   double salario1;        //Salario con el 4% aplicado.
   
   
   //Entrada de datos.
	
	cout << "\nIntroduzca su edad: ";
	cin >> edad;
	
	cout << "\nIntroduzca su salario: ";
	cin >> salario;
	
		
	//Cálculos y resultados.
	
	/*
	Estructura condicional anidada en la que si la presona es mayor de 65 años
	o menor de 35 años, se le aplica una subida de un 4% a su salario. 
	Si además cobra menos de 300 se le suma un 3% de interés adicional.
	En el caso de no ser ni menor de 35 ni mayor de 65 años, el salario
	se mantiene igual, sin ninguna subida aplicada.
	En todo caso sale por pantalla el salario final con el interés de subida
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
