/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
       Sesi�n 01-05.
       Problema n�mero 22:
           Leer dos secuencias de enteros y decir si todos los valores
           de la primera secuencia son mayores que todos los de la segunda.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusi�n de recursos de E/S
#include <cstdlib>              // Inclusi�n de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	int dato;     //Valores de los enteros introducidos.
	int minim;    //M�nimo valor de la primera secuencia.
	int maxim;    //M�ximo valor de la segunda secuencia.
	
	bool superior;     //Condici�n para que la primera secuencia,
	bool inferior;    //y en caso de no serlo, se dar�a esta segunda.

	
	//Entrada de datos.
	//Primera secuencia.
	
	cout << "\nIntroduzca la primera secuencia de enteros: "
	<< "\n";
	cin >> dato;
	
	//C�lculos.
	
	/*
	Hallamos el m�nimo valor de la primera secuencia
	para compararlo con el m�ximo de la segunda.
	Si este m�nimo valor es superior al m�ximo valor
	de la segunda se puede decir que todos los valores
	de la primera secuencia son mayores que los de la segunda.
	Para ello introducimos un condicional que modifica el valor
	de una variable, que es el m�nimo valor de la secuencia,
	en caso de que el nuevo valor introducido sea inferior
	al anterior m�nimo.
	Viceversa en el caso para hallar el m�ximo, con la diferencia
	de que en el condicional el dato debe de ser mayor para
	modificar dicho m�ximo.
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
