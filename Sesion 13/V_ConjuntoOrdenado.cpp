/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-13.
         Problema número 8:
           Clae conjunto ordenado para introducir una secuencia de valores
           enteros ordenadamente y sin repetidos.
           Calcular además la union de dicho conjunto con otro dado.
           Calcular también la interseccion de ambos.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Declaración de la clase ConjuntoOrdenado.
class ConjuntoOrdenado{
	
	//datos privados de la clase.
	private:
		
		static const int MAX = 100;
		int conjunto[MAX]={0};
		int total_enteros;


		
	//datos públicos de la clase.
	public:
		
		//declaración del constructor sin argumentos.
		ConjuntoOrdenado(){

			total_enteros = 0;
			
		}
		
		
		//método para añadir un valor al conjunto de manera ordenada
		//y sin repetidos.
		/*
		Se comprueba si el nuevo valor a introducir ya esta en el conjunto
		mediante un recorrido por el vector con un ciclo for.
		Si resulta ser un valor nuevo, para introducirse de manera ordenada
		entramos a una serie de condicionales en los que, si es menor
		que el menor de l conjunto, se colocará el primero y los demás serán 
		desplazados a la derecha.
		Si mayor que el mayor de todos, se colocará simplemente al final del
		conjunto.
		Si se encuentra en media de la secuencia, se comprueba en que posición 
		debe introducirse comprobando si es mayor que el que le antepone y 
		menor que el que le precede, se desplaza la secuencia desde esa posición
		a la derecha y se introduce el nuevo valor.
		*/
		//PRE: el vector no esté ya lleno.
		//entrada: valor entero a añadir.
		void Aniade(int entero){
			
			bool nuevo_entero = true;
			int vueltas = 0;
			
			if (total_enteros < MAX){
				
				for (int a = 0; a<=total_enteros ; a++){
					
					if (conjunto[a] == entero){
							
						nuevo_entero = false;
						
				   }
				
				}
		      
		      if (nuevo_entero){
		      	
		      	bool mayor_ant, menor_pos, primero, ultimo;
		      	
		      	primero = entero < conjunto[0];
		      	ultimo = entero > conjunto[total_enteros-1] 
					&& total_enteros >= 1;
		      	
					if(primero || total_enteros == 0){
						
		      			for(int b = total_enteros-1; conjunto[b] > entero; b--){
		      				
		      				for(int s = b+1; s > b ; s--){
		      					
		      					conjunto[s] = conjunto[b];
		      				
		      			   }
		      			   
		      			   vueltas++;
		      		
		      			}
						
						conjunto[0] = entero;
						total_enteros++;
						
					 }
					 else{
					 	
					 	if(ultimo){
					 		
					 		conjunto[total_enteros] = entero;
					 		total_enteros++;
					 		
					 		
					 	}
					 	else{
		      	
		      			for (int c=0; c < total_enteros; c++){
		      		
		      				mayor_ant = conjunto[c] < entero;
		      				menor_pos = conjunto[c+1] >= entero;
		      				ultimo = true;
		      		
		      		
		      			if(mayor_ant && menor_pos){
		      			
		      			for(int b = total_enteros-1; conjunto[b] > entero; b--){
		      				
		      				for(int s = b+1; s > b ; s--){
		      					
		      					conjunto[s] = conjunto[b];
		      				
		      			   }
		      			   
		      			   vueltas++;
		      		
		      			}
		      			
		      		   conjunto[total_enteros-vueltas] = entero;
		      		   total_enteros++;

		      		
		      			}    		
		      	
		      			}

						}
	      
					}
			
				}
				
			}
			
		}
		
		
		//Funcion para devolver el total de enteros de la secuencia.
		//Salida:total de enteros de la secuencia.
		int TotalUtilizados(){
			
			return total_enteros;
			
		}
		
		
		//Función void para mostrar los elementos del conjunto.
		void MostrarSecuencia(){
			
			for(int a = 0; a < total_enteros; a++){
				
				cout << conjunto[a] << " ";
				
			}
				
		}
		
		//Función para devolver un elemento del conjunto.
		//Entrada: posición del vector a devolver.
		//Salida: Valor del vector de la posición dada.
		int ElementoDelVector(int a){
			
			return conjunto[a];
			
		}
		
		
		//Función void para hallar la unión de dos conjuntos.
		/*
		En un nuevo conjunto se añaden los valores de ambas secuencias
		mediante la llamada a la anterior función aniade, por lo que
		solo se introducen valores no repetidos y de forma ordenada. 
		*/
		//Entrada: Conjuntos a hallar su unión.
		
		void Union(ConjuntoOrdenado conj_1, ConjuntoOrdenado conj_2){
			
			ConjuntoOrdenado conjunto_union;
			
			for(int a = 0; (a < conj_1.total_enteros) || 
			(a < conj_2.total_enteros) ; a++){
				
				conjunto_union.Aniade(conj_1.ElementoDelVector(a));
				conjunto_union.Aniade(conj_2.ElementoDelVector(a));

			}
			
			cout << "\nPrimera secuencia: "; conj_1.MostrarSecuencia();
			cout << "\nSegunda secuencia: "; conj_2.MostrarSecuencia();
			cout << "\n\tConjunto union: "; conjunto_union.MostrarSecuencia();
			cout << endl;
	
		}


		//Función void para hallar la intersección de dos conjuntos.
		/*
		En un nuevo conjunto se añaden los valores que se encuentren en 
		ambas secuencias. Para ello usamos dos ciclos for para ir compa-
		rando los elementos d abas secuencias y en caso de coincidir,
		se introducen en el conjunto intersecion.
		*/
		//Entrada: Conjuntos a hallar su intersección.
		void Interseccion(ConjuntoOrdenado c1, ConjuntoOrdenado c2){
			
			ConjuntoOrdenado conjunto_interseccion;
			bool coinciden;
			 
			
			for(int a = 0; ( a < c1.total_enteros ) ; a++){
				
				for(int b = 0; ( b < c2.total_enteros ) ; b++){
					
					coinciden = ( c1.ElementoDelVector(a) )
					== ( c2.ElementoDelVector(b) );
					
					if(coinciden){
						
						conjunto_interseccion.Aniade(c2.ElementoDelVector(b));
						
					}
					
				}
				
			}
			
			
			cout << "\nPrimera secuencia: "; c1.MostrarSecuencia();
			cout << "\nSegunda secuencia: "; c2.MostrarSecuencia();
			cout << "\n\tConjunto interseccion: "; 
			conjunto_interseccion.MostrarSecuencia();
	
		}
		
};



int main(){ // Programa Principal.


	//Declaración de datos.
	int valor_enter;
	
	ConjuntoOrdenado un_conjunto, otro_conjunto;
	
	bool sigue = true;
	
	cout << "\nIntroduzca los valores de la primera secuencia..."<< endl;

	
	//Entrada de datos.
	while(sigue){
		
   	cout << "\nIntroduce un valor entero: ";
		cin >> valor_enter;
		
		if (valor_enter >= 0){
	
			un_conjunto.Aniade(valor_enter);
			
	   }
		else{
		
			sigue = false;
		
		}
	
	}

	sigue = true;
	
	cout << "\nIntroduzca los valores de la segunda secuencia..."<< endl;
	
	while(sigue){
		
   	cout << "\nIntroduce un valor entero: ";
		cin >> valor_enter;
		
		if (valor_enter >= 0){
	
			otro_conjunto.Aniade(valor_enter);
			
	   }
		else{
		
			sigue = false;
		
		}
	
	}

	//Cálculos y resultados.
	un_conjunto.Union(un_conjunto, otro_conjunto);
	un_conjunto.Interseccion(un_conjunto, otro_conjunto);


	return (0);
	
}
