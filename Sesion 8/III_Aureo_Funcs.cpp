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
         Problema número 18:
         Programa para hallar el valor de n en la secuencia de Fibonacci
         que cumple que la diferencia entre an y el número aureo sea
         menor a fi, mediante la implementación de funciones, donde an
         es el cociente de la secuencia de Fibonacci de orden 'n+1' entre 
			la de orden 'n'.
          
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <string>     //Inclusión de recursos de tipo string.
#include <cmath>    //Inclusión de recursos matemáticos.

using namespace std; 

//Función para filtrar los valores de fi.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero;
	
	valores_correctos = ( numero >= 0 );
	
	}while(!valores_correctos);
	
	return numero;
	
}

//Función para el cálculo del valor de la sucesión en un punto determinado.
//Si el valor de 'n' es 1 ó 2, la función valdrá 1.
//En caso de ser un valor mayor, encontramos un ciclo for que va sumando 
//y actualizando los valores de las variables hasta llegar al valor de
//'n' introducido.
double Fibonacci(int n){
	
	//Declaración de variables.

   const int F1 = 1;
   const int F2 = 2;
   
   int fa;
   int fb;
   int fc;
	int fn;
   int inicio_n;
   
   
   //Cálculos.
   
   fa = F1;
   fb = F1;
   fc = F1;
   
   if( (n == F1) || (n == F2) ){
   	
   	fn = F1;
	
	}
	
	else{
		
		for(inicio_n=3 ; inicio_n<=n ; inicio_n++){
			
			fn = fa+fb;
			fa = fn;
			fb = fc;
			fc = fa;
			
		}
		
	}
	
	return fn;
	
}


//Función para hallar el valor de 'n' que cumple que 'an' difiere en menos de
//un valor introducido 'fi' del número aureo.
int Diferencia(double fi){
	
	//Declaración de variables.
	
	double aureo;          //Número aureo.
	double an;             // ( fn+1 / fn )
	double dif_aur_fib;    //Diferencia de (an - aureo).
	
	int n;         //Valor de n el la secuencia de Fibonacci.
	
	
	//Cálculos.
	
	//Hallamos el pimer valor de la diferencia.
	
	n = 1;
	an = (Fibonacci(n+1) / Fibonacci(n));
	aureo = ( (1.0 + sqrt(5.0) ) / 2.0 );	
	dif_aur_fib = abs(an - aureo);
	
	/*
	Mediante un ciclo while vamos comparando si la diferencia difiere
	en menos del valor de 'fi' y va probando así con los valores de 'n'
	hasta llegar al que cumple la condición.
	*/
	
   while (fi < dif_aur_fib){
		
		n++;
		an = (Fibonacci(n+1.0) / Fibonacci(n));
		aureo = ( (1.0 + sqrt(5.0) ) / 2.0 );
		
		dif_aur_fib = abs(an - aureo);
		
	}
	
	return n;	
	
}



int main(){
	
	//Declaración de variables.
	
	double fi;     //Valor de fi.
	int n;         //Valor 'n' en la secuencia de Fibonacci.
	
	
	//Entrada de datos.
	
	fi = Filtro( "\nIntroduzca un valor para 'fi': " );
	
	
	//Cálculos.
	
	n = Diferencia(fi);
	
	
	//Resultados.
	
	cout << "\nEl menor valor de 'n' para que la diferencia sea menor a " << fi 
	<< " es " << n;

 
	return(0);
}
