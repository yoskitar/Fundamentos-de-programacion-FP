/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
// 
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
// 
// 
/* 
         Sesión 01-08.
         Problema número 19:
         Programa para calcular la distribución acumulada en un punto
         mediante la implementación de funciones.
          
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <string>     //Inclusión de recursos de tipo string.
#include <cmath>    //Inclusión de recursos matemáticos.

using namespace std; 


//Filtro para introducir un real positivo.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;

	valores_correctos = ( numero_double > 0);
	
	}while(!valores_correctos);
	
	return numero_double;
}


//Función para calcular la parte derecha de la función (exponente).
double Exponente( double valor_x, double desviacion, double esperanza ){
	
	double exponente;         //Declaracion de la variable exp.
	
   //Cálculo de la parte derecha de la función.
	exponente = exp (pow( (valor_x - esperanza) / desviacion , 2 ) / -2);

	return exponente;
}


//Función para calcular la parte izqda. de la función (división).
double Division( double desviacion ){
	
	const double PI = 3.1415926535897;    //Declaracion del valor de PI. 
      
	double div;
   
	div = 1/(desviacion*sqrt(2*PI)); 
	
	return div;
}


//Cálculo de la función introduciendo los 3 parámetros.
double Gaussiana(double valor_x, double esperanza, double desviacion){
                    
	double valor_y;            //Valor de la funcion. 
	double exponente;        
	double div;
	
	//Cálculo de la parte izquierda de la función.
	div = Division(desviacion);
	
   //Cálculo de la parte derecha de la función.
	exponente = Exponente(valor_x, desviacion, esperanza);
	
   //Cálculo de la función.	
	valor_y = div * exponente; 
	
	return valor_y;

}




double Valor_T(double x){
	
	//Declaración de variables.
	
	const double B0 = 0.2316419;
	double t;
	
	//Cálculo del valor de la variable 't'.
	
	t = (1.0 / ( 1.0 + (B0 * x) ) );
	
	
	return t;
}


//Función para calcular la secuencia de 't' cuya expresión viene indicada en 
//los apuntes.
double Sucesion_T(double t){
	
	//Declaración de variables.
	
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;
   
   double sucesion_t;
   
   
   //Cálculos.   
   
	sucesion_t = ( B1 * t ) + ( B2 * (pow(t,2)) ) + ( B3 * (pow(t,3)) ) + 
	( B4 * (pow(t,4)) )	+ ( B5 * (pow(t,5)) ) ;
	
	return sucesion_t;
}

//Función para el cálculo de CDF(x) a partir de su expresión y de los
//valores para la gaussiaa y de la sucesion de 't' ya calculados en 
//funciones anteriores.
double DistribucionAcumulada(double sucesion_t, double gaussiana){
	
	double cdf;
	
	cdf = 1.0 - (gaussiana * sucesion_t);
	
	return cdf;
}



int main(){ // Programa Principal.


   //Declaración de variables.
    
	double esperanza;      //Valor de (x), esperanza y desviación.        
	double desviacion;     
	double valor_x;                              
	double valor_y;        //Valor de la funcion. 
	double var_t;
	double sucesion_t;
	double cdf;
	
	//Entrada de datos, cálculos y salida de resultados mediante las funciones
   //definidas anteriormente.
	
   //Enrada de datos 1.
   
	cout << "\nFuncion con tres parametros: \n";  
   
   esperanza = Filtro("\nIntroduzca el valor de la esperanza: ");
	desviacion = Filtro("Introduzca el valor de la desviacion tipica: ");   
	valor_x = Filtro("Introduzca el valor de la variable 'X': ");
	
	
	//Cálculos de la gausiana en (x) mediante su función.
	valor_y = Gaussiana(valor_x, esperanza, desviacion);
	
	//Cálculo del valor de 't' mediante su función.
	var_t = Valor_T(valor_x);
	
	//Cálculo de la suecsión en 't' mediante su función.
	sucesion_t = Sucesion_T(var_t);
	
	//Cálculos del CDF(x) atendiendo a la función.
	cdf = DistribucionAcumulada(sucesion_t, valor_y);  
	
	
	//Resultados.
	
	cout << "\nEl valor de la distribución acumulada en 'x' (CDF(x)) valdra: "
	<< cdf;
	
	
	return(0);
}
