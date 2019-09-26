/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
                  Problema número 12 :
                     Programa simple para calcular el capital total 
					      obtenido al cabo de un año en función del capital
					      ingresado y el interés aplicado.
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.

using namespace std;

int main()                    //Programa principal.
{                        
	              
	         system ("chcp 1252");        //Caracteres latinos.
	                   
	// Declara variables para guardar.   
	               
	double capital;                   //Declaración de variables.
	double interes;                  //El capital ingresado,
	double total;                   //interés aplicado y capital total al año.
	
	//Entrada de datos.
	
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital;
	cout << "Introduzca el interés de su plazo fijo anual: ";              
	cin >> interes;
	
	//Cálculos.
	
   //Total de capital obtenido al cabo del año con el interés aplicado.	
	total =  capital+capital*(interes/100);   
	
	//Resultados.
	
	cout << "\nEl capital total al año será de: " << total << " €" "\n";  
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
