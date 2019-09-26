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
         Problema número 17:
         Programa para calcular si un número es feliz en el orden
         k dado por el usuario.
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <string>     //Inclusión de recursos de tipo string.
#include <cmath>    //Inclusión de recursos matemáticos.

using namespace std; 

//Función para filtrar que el valor introducido sea un entero positivo.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_d;
	int num_1;
	
	do{
		
	cout << mensaje;            
	cin >> numero_d;
	
	num_1 = numero_d;
	
	valores_correctos = ( num_1 > 0 ) && 
	(numero_d - num_1 == 0);
	
	}while(!valores_correctos);
	
	return num_1;
	
}

/*
Función que halla el número de dígitos que componen un entero mediante
un ciclo for que se repetirá mientras el número dividido entre 10 de 
distinto de cero como cociente.En verdad no da el número de dígitos
total, sino uno menos.
*/
int Digitos(int num_1){
	
	int num_digitos;
	
	
	for( num_digitos = 0 ; (num_1/10) != 0; num_digitos++){
		   
			num_1 = (num_1/10);

	}
	
	return num_digitos;	
}


/*
Función que halla la suma de las potencias de los dígitos
que componen un número. Mediante un ciclo for va descomponiendo
el entero dado y elevandolo al número de dígitos del entero.
A su vez, va sumando el resultado de cada una de esas operaciones,
dando como resultado la suma de todas las potencias de los dígitos
del entero dado.
*/
int SumaPotencias(int num_digitos, int num_1_restos){
	
	//Declaración de variables.
	int potencia_diez;
	int suma;
	int digito;
	
	
	//Cálculos.
	suma = 0;
		
	for(; num_digitos >= 0 ; num_digitos--){
	
	   potencia_diez = pow(10*1.0, num_digitos);	
		digito = num_1_restos / potencia_diez;
	   num_1_restos = num_1_restos % potencia_diez;
	     
	   suma = suma + pow(digito*1.0, 2);
		 
	}
   
	return suma;	
}


/*
Función para calcular si un número es feliz en un orden dado.
Si el numero es 1, directamente se salta todos los cálculos, ya 
que va a ser un número feliz.
En caso de ser distino de 1, encontramos un ciclo for, que se repetirá
hasta que la suma de los cuadrados de los dígitos del número sea
menor que 10.
Dentro encontramos una estructura condicional en la que si la suma
final tiene de resultado 1, el número se dice que es feliz, en el orden
de k.
Si el k dado por el usuario es menor al k calculado por el programa,
se muestra el mensaje de que no es feliz en ese grado de k dado.
*/
string Feliz(int num, int k_dado){
	
	//Declaración de variables.
	int suma;                    //Sumatorio de las potencias n-ésimas.
   int num_digitos;             //Número de dígitos -1 del valor dado.  
   int i;                       //Valor inicio del contador.
   int k;
   int num_original;
   
	string feliz;            //Mensaje devuelto.
	
	//Cálculos.	
	
	num_original = num;
	
	if (num != 1){
		
	   for( (i = num) ; (i >= 10 ) ; (i = suma) ){
		
	      num_digitos = Digitos(num);
	      suma = SumaPotencias(num_digitos, num);
		   num = suma;
		   k++;
	   }
	
	
	   if (suma == 1 && k_dado >= k) {
			
		   feliz = ( "\nEl numero introducido " + to_string(num_original)
		   + " es feliz en grado mayor o igual a " + "(" + to_string(k) 
		   + ")" + " por lo que lo es de grado " + "(" + to_string(k_dado) + ")" );
		
	   }
	
      else{
			
		   feliz = ( "\nEl numero introducido " + to_string(num_original)
		   + " no es feliz en grado " + "(" + to_string(k_dado) + ")" );
		
   	}
   	
   }
	else{
		
		feliz = ( "\nEl numero introducido " + to_string(num_original)
		   + " es feliz en grado mayor o igual a (1)" 
			+ " por lo que lo es de grado " + "(" + to_string(k_dado) + ")" );
	
	}

	//Salida.	
	return feliz;

}



int main(){ // Programa Principal.
                      
   // Declara variables para guardar.
   
   int num_1;                   //Número introducido.
   int k_dado; 
   string feliz;                //Resultado.
   
	//Entrada de datos.
   num_1 = Filtro("Introduzca un numero entero positivo: ");		
	k_dado = Filtro( "\nIntroduce un valor para 'k': " );	
	
	//Cálculos mediante función anteriormente definida.
	feliz = Feliz(num_1, k_dado);
	
	
	//Resultados.
	cout << feliz;
	
	return(0);
}
