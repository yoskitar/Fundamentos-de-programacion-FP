/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-06.
         Problema n�mero 28:
            Introducir unos valores para unos elementos de una sucesi�n
            num�rica y hallar dicha sucesi�n num�rcica en funci�n de 
            dichos valores. En un primer caso utilizando potencias
            y en un segundo, aprovechando los computos relizados en la 
            iteraci�n anterior.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.

using namespace std; 


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   double numero_double;          //Valor de ai double.
   double constante_double;       //Valor de r doule.
   double tope_double;            //Valor de k double.
   
	int tope_inverso;    //Inicio del contador.
   int valor;           //Valor a pintar en la sucesi�n.
   int numero;          //Valor de 'ai' entero.
   int constante;       //Valor de 'r' entero.
   int tope;            //Valor de 'k' entero.
   int sumatorio;       //Valor del sumatorio de la secuencia.
   int valor_inicio;    //Variables para guardar valores
   int numero_inicio;   //modificados en cada ciclo.
   
   bool valores_correctos_numero;      //Condiciones para los filtros
   bool valores_correctos_constante;  //de los valores introducidos.
   bool valores_correctos_tope;
      
   //Entrada de datos.
   
   //Filtros para la entrada de datos en caso de que se introduzca
   //un valor negativo o racional.
   
   do{
		
	cout << "\nIntroduzca el elemento 'ai' de la serie: ";              
	cin >> numero_double;
	
	numero = numero_double;
	
	valores_correctos_numero = ( numero > 0 ) && 
	(numero_double - numero == 0);
	
	}while(!valores_correctos_numero);
	
	 do{
		
	cout << "\nIntroduzca la constante 'r' de la serie: ";              
	cin >> constante_double;
	
	constante = constante_double;
	
	valores_correctos_constante = ( constante > 0 ) && 
	(constante_double - constante == 0);
	
	}while(!valores_correctos_constante);
	
	do{
		
	cout << "\nIntroduzca el tope 'k' de la serie: ";              
	cin >> tope_double;
	
	tope = tope_double;
	
	valores_correctos_tope = ( tope > 0 ) && 
	(tope_double - tope == 0);
	
	}while(!valores_correctos_tope);
	
	
   
	//C�lculos y resultados.
	
	cout << "\nEl sumatorio de la serie numerica quedaria:" ;

	cout << "\n\nPrimer caso:" << "\n\n\t";
	
	/*
	Ciclo for que se repetir� mientras el contador no llege al valor
	del tope introducido, sumando cada uno de los valores de la
	scuencia obtenidos en cada vuelta del ciclo for.
	
	En el segundo caso, el valor viene dado como el producto del
	elemento 'ai' por la constante 'r', donde el valor de 'n�mero_inicio'
	se va actualizando por el resultado del producto anterior.
	Cada elemento de la secuencia obtenido se va a�adiendo
	al sumatorio en cada vuelta del ciclo for.
	*/
	
	valor_inicio = 0;
	
	for(tope_inverso = 0; tope_inverso < tope ; tope_inverso++){
		
		valor = ( numero * pow(constante, tope_inverso) );
		
		sumatorio = valor_inicio + valor;
		valor_inicio = sumatorio;
		
	}
	
	cout << sumatorio << ", ";  //Salida de resultados 1er. caso.
	
	cout << "\n\nSegundo caso:" << "\n\n\t";
	
	valor_inicio = numero;
	numero_inicio = numero;
	valor = 0;
	
	for(tope_inverso = 0; tope_inverso < tope ; tope_inverso++){
		
		
		sumatorio = valor_inicio + valor;
		valor = numero_inicio * constante;
		
		valor_inicio = sumatorio;
		numero_inicio = valor;
		
		
	}
	
	cout << sumatorio << ", ";   //Salida de resultados 2� caso.
	 
	cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
