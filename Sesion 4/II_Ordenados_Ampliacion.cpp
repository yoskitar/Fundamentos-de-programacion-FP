/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 13:
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cctype>      // Inclusión de datos lógicos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std;
 


enum class Tipo {ascendente, descendente, aleatorio};


int main(){ // Programa Principal.              
         
            
   // Declara variables para guardar.
   
   Tipo tipo_orden;
   
   int num_1;
   int num_2;
   int num_3;
   
   bool asc;
   bool desc;
   
   
   //Entrada de datos.
	
	cout << "\nIntroduzca el primer numero: ";
	cin >> num_1;
	
	cout << "Introduzca el segundo numero: ";
	cin >> num_2;
	
		cout << "Introduzca el tercer numero: ";
	cin >> num_3;
	
		

	//Cálculos.
	
	/*
	Establecemos cuando cada una de las variables booleanas serán
	ciertas, utilizando una estructura condicional para indicar en 
	resultados el mensaje a mostrar en consola dependiendo del
	orden dado.
	*/
	
	asc = num_1 < num_2 and num_2 < num_3;
	desc = num_1 > num_2 and num_2 > num_3;
	
	if (asc){
		
		tipo_orden = Tipo::ascendente;
		
	}
	
	else{
	
	  if(desc){
	  	
		tipo_orden = Tipo::descendente;
		
	}
	  else{
	  	
		tipo_orden = Tipo::aleatorio;
		
	}
 }
	
	//Resultados.
	
	/*
	En caso de darse la primera condición el orden es ascendente.
	Si no lo es, puede ser descendente o aleatorio, en caso de no
	ser descendente, solo queda el caso de aleatorio, mostrandose 
	los respectivos mensajes por consola.
	*/
	
	switch (tipo_orden){
		
		case Tipo::ascendente:
			cout << "\nEl orden de los valores " << num_1 << ", " 
			<< num_2 << ", " << num_3 <<" es ascendente.";
			break;
			
		case Tipo::descendente:
			cout << "\nEl orden de los valores " << num_1 << ", " 
			<< num_2 << ", " << num_3 <<" es decendente.";
			break;
			
		case Tipo::aleatorio:
			cout << "\nLos valores " << num_1 << ", " 
			<< num_2 << ", " << num_3 <<" no estan ordenados.";
			break;
		}
		
		cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
