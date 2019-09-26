/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
                  Problema n�mero 12 :
                     Programa simple para calcular el capital total 
					      obtenido al cabo de un a�o en funci�n del capital
					      ingresado y el inter�s aplicado.
*/  
/*********************************************************************/


#include <iostream>              //Inclusi�n de recursos de E/S
#include <cstdlib>              // Inclusi�n de llamadas al sistema.

using namespace std;

int main()                    //Programa principal.
{                        
	              
	         system ("chcp 1252");        //Caracteres latinos.
	                   
	// Declara variables para guardar.   
	               
	double capital;                   //Declaraci�n de variables.
	double interes;                  //El capital ingresado,
	double total;                   //inter�s aplicado y capital total al a�o.
	
	//Entrada de datos.
	
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital;
	cout << "Introduzca el inter�s de su plazo fijo anual: ";              
	cin >> interes;
	
	//C�lculos.
	
   //Total de capital obtenido al cabo del a�o con el inter�s aplicado.	
	total =  capital+capital*(interes/100);   
	
	//Resultados.
	
	cout << "\nEl capital total al a�o ser� de: " << total << " �" "\n";  
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
