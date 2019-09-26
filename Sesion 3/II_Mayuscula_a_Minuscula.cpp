/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01 - 03
         Problema n�mero 7:
            Pasar una letra may�scula a min�scula sin usar toupper
            ni tolower.
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   char letra_original;
   char letra_convertida;
   char diferencia;
   
	//Entrada de datos.
	
	cout << "\nIntroduzca la letra: ";
	cin >> letra_original;
	
	
	//C�lculos.
	
	/*
	Si la letra introducida esta dentro de los valores en la tabla ASCII
	de las may�sculas, restamos la diferencia hasta las min�sculas
	y mostramos un mensaje con la respectiva min�scula.
	*/
	
	diferencia = 'A' - 'a';
	
	if (letra_original >= 'A' and letra_original <= 'Z'){
		
		letra_convertida = letra_original - diferencia;
		
	   cout << "\nLa min�scula de " << letra_original << " ser�a: "
	   << letra_convertida << "\n";
	   
	}
	
	/*Si la letra se encuentra entre los valores de las min�sculas,
	se muestra un mensaje diciendo que ya era min�scula.
	*/
	
	if (letra_original >= 'a' and letra_original <= 'z') {
		
		letra_convertida = letra_original;
		
		 cout << "\nLa letra introducida ya es min�scula: "
		 << letra_convertida << "\n";
		 
	}

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
