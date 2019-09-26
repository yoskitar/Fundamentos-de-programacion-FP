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
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 

//Filtro para introducir una valor entero positivo.
int Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	int numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;
	
	numero = numero_double;
	
	valores_correctos = ( numero > 0 ) && 
	(numero_double - numero == 0);
	
	}while(!valores_correctos);
	
	return numero;
	
}

//Filtro para introducir un real positivo.
double FiltroDouble(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;

	
	valores_correctos = ( numero_double > 0);
	
	}while(!valores_correctos);
	
	return numero_double;
	
}

//Filtro para introducir un real entre [0.1).
double Filtro2(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;
	
	valores_correctos = ( numero_double >= 0 && numero_double <1 );
	
	}while(!valores_correctos);
	
	return numero_double;
	
}

/*int SumaHasta(int numero, int constante, int tope){
	
	int tope_inverso;    //Inicio del contador.
   int valor;           //Valor a pintar en la sucesi�n.
   int sumatorio;       //Valor del sumatorio de la secuencia.
   int valor_inicio;    //Variables para guardar valores
   int numero_inicio;   //modificados en cada ciclo.
	
	
	valor_inicio = numero;
	numero_inicio = numero;
	valor = 0;
	
	for(tope_inverso = 0; tope_inverso < tope ; tope_inverso++){
		
		sumatorio = valor_inicio + valor;
		valor = numero_inicio * constante;
		
		valor_inicio = sumatorio;
		numero_inicio = valor;
		
		
	}
	
	return sumatorio;

}*/


//Funci�n para hallar el sumatorio hasta un tope introducido,
//con tan solo 5 operaciones matem�ticas.
int SumaHasta(int numero, int constante, int tope){
	
	int sumatorio;
	
   sumatorio = ( ( (pow(constante, tope) - 1) / ( constante - 1 ) )
	 * numero );
	
	return sumatorio;

}

//Funci�n para hallar la suma hasta infinito, atendiendo a la expresi�n
//matem�tica que la define.
double SumaHastaInfinito(double numero, double constante){
	
	double sumatorio_hasta_infinito;
	double divisor;
	
	divisor = 1.0 - constante;
	
	sumatorio_hasta_infinito = ( numero / divisor );
   
   return sumatorio_hasta_infinito;

}


//Funci�n para calcular la multiplicaci�n de los valores hasta un tope,
//de acuerdo con la expresi�n matem�tica que la define.
double MultiplicaHasta(int numero, int constante, int tope){
	
	int base;
	double producto;
	
	base = ( SumaHasta(numero, constante, tope) * numero );
	producto = sqrt( pow(base, tope) );
	
	return producto;
	
}


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   int numero;                  //Valor de 'ai' entero.
   int constante;               //Valor de 'r' entero.
   int tope;                    //Valor de 'k' entero.
   int sumatorio;               //Valor del sumatorio de la secuencia.
   
   double sumatorio_infinito;   //Valor del sumatorio hasta infinito.
   double num_double;           //Valor de 'ai' real.
   double constante_double;     //Valor de 'r' real.
   double producto;             //Valor del producto de los primero k valores.
      
  
   //Entrada de datos.
   
   //Filtros para la entrada de datos en caso de que se introduzca
   //un valor negativo o racional.
 
	cout << "\nSumatorio hasta k... " ;	
	numero = Filtro("\n\nIntroduzca el elemento 'ai' de la serie: ");
	constante = Filtro("\nIntroduzca la constante 'r' de la serie: "); 
	tope = Filtro("\nIntroduzca el tope 'k' de la serie: ");             
	
	
   //Aplicaci�n de las funciones correspondientes para calcular cada uno
   //de los valores pedidos.
	//C�lculos y resultados 1.
	
	sumatorio = SumaHasta(numero, constante, tope);
	
	cout << "\n\tEl sumatorio de la serie numerica seria: " ;
	
	cout << sumatorio;
	
	
	
	
	//C�lculos y resultados 2.
	
	cout << "\n\nSumatorio hasta infinito... " ;
	
	num_double = FiltroDouble("\n\nIntroduzca un valor real para 'ai': ");
	constante_double = Filtro2("\nIntroduzca un valor >=0 o <1 para 'r': ");
	
	sumatorio_infinito = SumaHastaInfinito(num_double, constante_double);
	
	cout << "\n\tEl sumatorio de la serie numerica hasta infinito seria: " 
	<< sumatorio_infinito;
	
	
	
	
	//C�lculos y resultados 3.
	
	cout << "\n\nProducto hasta k...";
	
	numero = Filtro("\n\nIntroduzca el elemento 'ai' de la serie: ");
	constante = Filtro("\nIntroduzca la constante 'r' de la serie: "); 
	tope = Filtro("\nIntroduzca el tope 'k' de la serie: ");  
	
	producto = MultiplicaHasta(numero, constante, tope);
	
	cout << "\n\tEl producto hasta k seria: " << producto;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
	cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
