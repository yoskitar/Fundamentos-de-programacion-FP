/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01 - 03
         Problema número 3 :
             Introducir dos valores y decir si se dividen o no.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cctype>      // Inclusión de datos lógicos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   int num_1;
   int num_2;
   
   bool cond_1;
   bool cond_2;

   
   //Entrada de datos.
	
	cout << "\nIntroduzca el primer numero: ";
	cin >> num_1;
	
	cout << "\nIntroduzca el segundo numero: ";
	cin >> num_2;
	
		

	//Cálculos y resultados.
	
	/*
	Si el primer número es divisible por el segundo, el resto de la division
	será cero, y en ese caso mostrará que es divisible por dicho número.
	Si no se da la condición mostrará que no es divisible.
	Con el segundo condicionante ocurre lo mismo solo que comprobando
	si ese segundo número es divisible por el primero introducido.
	*/
	
	
	cond_1 = num_1 % num_2;
	cond_2 = num_2 % num_1;
	
	if (cond_1 == 0) {
		
		cout<< "\nEl numero " << num_1 << " es divisible por " << num_2;
		
	}
		else {
			
		  cout<< "\nEl numero " << num_1 << " no es divisible por " << num_2;
		  
	}
	
	
		if (cond_2 == 0) {
		
		cout<< "\nEl numero " << num_2 << " es divisible por " << num_1;
		
	}
		else {
			
		  cout<< "\nEl numero " << num_2 << " no es divisible por " << num_1;
		  
	}
		
		 
	cout << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
