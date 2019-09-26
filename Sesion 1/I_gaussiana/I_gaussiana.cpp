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
              Programa simple para calcular el valor de la funcion 
				  gaussiana para un valor (x) en funcion de una esperanza 
				  y desviaci�n t�pica determinadas.
*/
/*********************************************************************/

#include <iostream>               //Inclusi�n de recursos de E/S.
#include <cmath>                 //Inclusi�n de recursos matem�ticos.
#include <cstdlib>              // Inclusi�n de llamadas al sistema.


using namespace std;

int main()                    //Programa principal.
{                              
	
	         system ("chcp 1252");        //Caracteres latinos.
	
	
	// Declara variables para guardar.
	
	const double PI = 3.1415926535897;    //Declaracion del valor de PI. 

	double esperanza;                 //Declaraci�n de variables.
	double desviacion_tipica;       //Valor de (x), esperanza y desviaci�n.
	double valor_x;                             
	double valor_y;            //Valor de la funcion. 
	double exponente;         //Declaracion de la variable exp.
	double div;
	
	//Entrada de datos.
	
	cout << "\nIntroduzca el valor de la esperanza: ";       
	cin >> esperanza;
	
	cout << "Introduzca el valor de la desviaci�n t�pica: ";   
	cin >> desviacion_tipica;
	
	cout << "Introduzca el valor de la variable X: ";       
	cin >> valor_x;
	
	//C�lculos.
	
	//C�lculo de la parte izquierda de la funci�n.
	div = 1/(desviacion_tipica*sqrt(2*PI)); 
  //C�lculo de la parte derecha de la funci�n.
	exponente = exp(pow((valor_x-esperanza)/desviacion_tipica,2)/-2);
  //C�lculo de la funci�n.	
	valor_y = div*exponente; 
	
	//Resultados.
	
	cout << "\nEl valor de la funcion en (x) ser�: " <<valor_y<< "\n";      

	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
