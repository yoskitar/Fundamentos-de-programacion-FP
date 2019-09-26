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
              Programa simple para calcular el valor de la funcion 
				  gaussiana para un valor (x) en funcion de una esperanza 
				  y desviación típica determinadas.
*/
/*********************************************************************/

#include <iostream>               //Inclusión de recursos de E/S.
#include <cmath>                 //Inclusión de recursos matemáticos.
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main()                    //Programa principal.
{                              
	
	         system ("chcp 1252");        //Caracteres latinos.
	
	
	// Declara variables para guardar.
	
	const double PI = 3.1415926535897;    //Declaracion del valor de PI. 

	double esperanza;                 //Declaración de variables.
	double desviacion_tipica;       //Valor de (x), esperanza y desviación.
	double valor_x;                             
	double valor_y;            //Valor de la funcion. 
	double exponente;         //Declaracion de la variable exp.
	double div;
	
	//Entrada de datos.
	
	cout << "\nIntroduzca el valor de la esperanza: ";       
	cin >> esperanza;
	
	cout << "Introduzca el valor de la desviación típica: ";   
	cin >> desviacion_tipica;
	
	cout << "Introduzca el valor de la variable X: ";       
	cin >> valor_x;
	
	//Cálculos.
	
	//Cálculo de la parte izquierda de la función.
	div = 1/(desviacion_tipica*sqrt(2*PI)); 
  //Cálculo de la parte derecha de la función.
	exponente = exp(pow((valor_x-esperanza)/desviacion_tipica,2)/-2);
  //Cálculo de la función.	
	valor_y = div*exponente; 
	
	//Resultados.
	
	cout << "\nEl valor de la funcion en (x) será: " <<valor_y<< "\n";      

	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
