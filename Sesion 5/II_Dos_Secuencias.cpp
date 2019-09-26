/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
       Sesión 01-05.
       Problema número 22:
           Leer dos secuencias de enteros y decir si todos los valores
           de la primera secuencia son mayores que todos los de la segunda.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	int dato;     //Valores de los enteros introducidos.
	int minim;    //Mínimo valor de la primera secuencia.
	int maxim;    //Máximo valor de la segunda secuencia.
	
	bool superior;     //Condición para que la primera secuencia,
	bool inferior;    //y en caso de no serlo, se daría esta segunda.

	
	//Entrada de datos.
	//Primera secuencia.
	
	cout << "\nIntroduzca la primera secuencia de enteros: "
	<< "\n";
	cin >> dato;
	
	//Cálculos.
	
	/*
	Hallamos el mínimo valor de la primera secuencia
	para compararlo con el máximo de la segunda.
	Si este mínimo valor es superior al máximo valor
	de la segunda se puede decir que todos los valores
	de la primera secuencia son mayores que los de la segunda.
	Para ello introducimos un condicional que modifica el valor
	de una variable, que es el mínimo valor de la secuencia,
	en caso de que el nuevo valor introducido sea inferior
	al anterior mínimo.
	Viceversa en el caso para hallar el máximo, con la diferencia
	de que en el condicional el dato debe de ser mayor para
	modificar dicho máximo.
	*/
	
	
	minim = dato;
	while (dato != 0){
		
		if (minim>=dato){
			
			minim = dato;
		  
		}
		
	   cin >> dato;

	}
	
	
	//Segunda secuencia.
	
	cout << "\nIntroduzca la segunda secuencia de enteros: "
	<< "\n"; 
	cin >> dato;
	
	maxim = dato;
	while (dato != 0){
		
		if (maxim<=dato){
			
			maxim = dato;
		  
		}
		
	   cin >> dato;

	}
	
	superior = (minim > maxim);
	inferior = (minim < maxim);
	
	
	//Resultados.
	
	if(superior){
	
		cout << "\nTodos los valores de la primera secuencia son"
	   << " mayores que todos los de la segunda secuencia.";
	}
	else{
		
		if(inferior){
			
		cout << "\nTodos los valores de la primera secuencia no son"
	   << " mayores que todos los de la segunda secuencia.";
	   
	   }
		else{
					
		cout << "\nEl minimo valor de la primera secuencia es"
		<< " igual al maximo valor de la segunda secuencia.";
		
		}
		
	}
	
	cout << "\n\n";



	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
