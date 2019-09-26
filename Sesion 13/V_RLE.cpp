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
         Problema número 1:
          Cread la clase RLE para codificar y descodificar una secuencia de 
          enteros creada por la clase SecuenciaEnteros y comprobar 
          si dos secuencias son iguales.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Declaracaion de la clase enteros.

//PRE: Los valores introducidos deben ser enteros positivos, o -1
//para finalizar la secuencia.
class SecuenciaEnteros{
	
	//Datos privados de la clase.
	private:
		
		static const int MAX = 50;
		int vector_secuencia[MAX];
		int total_enteros;
		
	//Datos publicos de la clase.
	public:
		
		//Contrusctor sin argumentos de la clase.
		SecuenciaEnteros(){
			
			total_enteros = 0;
			
		}
		
		//Metodo para borrar la secuencia.
		void BorrarSecuencia(){
			
			total_enteros = 0;
			
		}
		
		//Metodo para añadir un nuevo elemento al vector secuencia.
		//Entrada: valor a introducir en el vector.
		void Aniade(int a){
			
			vector_secuencia[total_enteros] = a;
			total_enteros++;
			
		}
		
		
		//Metodo para devolver el total de elementos del vector.
		//Salida: total de enteros
		int TotalEnteros(){
			
			return total_enteros;	
			
		}
		
		
		//Muestra un elemento concreto del vector.
		//Entrada: posicion del vector de la que queremos ver el elemento.
		int Elemento(int a){
			
			return vector_secuencia[a];	
		}
		
		
		//Metodo para saber si dos secuencias son iguales.
		//Entrada: secuencia a comparar.
		void EsIgualA(SecuenciaEnteros otro){
			
			bool es_igual, igual_tamanio;
			int enteros_otro;
				
			es_igual = true;
				
			enteros_otro = otro.TotalEnteros();
				
			igual_tamanio = ( enteros_otro == total_enteros );
				
			if( igual_tamanio ){
					
				for(int a; a < total_enteros; a++){
				
					es_igual = ( otro.Elemento(a) == vector_secuencia[a] );
						
					if(!es_igual){
							
						a = total_enteros;
						es_igual = false;
							
						cout << "\n\tLas secuencias no son iguales." << endl;
					
					}
						
				}
					
				if (es_igual){
						
					cout << "\n\tLas secuencias son iguales." << endl;

				}
					
			}

		}
		
		//Metodo para mostrar por pantalla los elementos del vector.
		void MostrarVector(){
			
			for(int a = 0; a < total_enteros; a++){
				
				cout << vector_secuencia[a] << " ";
				
			}
			
			cout << endl;
			
		}
		
};


//Declaracion de la clase RLE.
class RLE{
	
	//Datos privados de la clase.
	private:
		
		static const int MAX = 50;
		int vector_codificado[MAX];
		int vector_descodificado[MAX];

	//Datos públicos de la clase.
	public:
		
		
		//Función para codificar la secuencia.
		//Recibe: Secuencia descodificada;
		//Compara el valor que le ocupa con el siguiente y si
		//es diferente se introduce el que le ocupa en el vector
		//precedido del valor de una variable que lleva el numero de
		//reoeticiones del ciclo for, que se corresponde con el numero,
		//de apariciones del igito.
		void Codifica(SecuenciaEnteros secuencia_descodificada){
			
			int apariciones = 1;
			int total_codificado = 0;
			int anterior, nuevo;
			
			for(int a = 1 ; a < secuencia_descodificada.TotalEnteros()+1; a++){
				
				anterior = secuencia_descodificada.Elemento(a-1);
				nuevo = secuencia_descodificada.Elemento(a);
				
				if (nuevo == anterior){
					
					apariciones++;
					
				}else{
					
					vector_codificado[total_codificado] = apariciones;
					total_codificado++;
					vector_codificado[total_codificado] = anterior;
					total_codificado++;
					apariciones = 1;
					
				}

			}
			
			for(int c = 0; c < total_codificado; c++){
				
				cout << "codifica ";
				cout << vector_codificado[c] << endl;
				
			}
			cout << "terminado " << endl;
							
			secuencia_descodificada.BorrarSecuencia();
			
			for(int b = 0; b < total_codificado; b++){
				
				secuencia_descodificada.Aniade(vector_codificado[b]);
				
			}
			
		}
		
		
		//Función para descodificar la secuncia.
		//Entrada:Secuencia codificada.
		//Introduce en el vector descodificado las posiciones impares
		//del vector codificado, tantas veces como el valor de 
		//la posición par indique mediante ciclos for.
		void Descodifica(SecuenciaEnteros secuencia_codificada){
			
			int total_descodificado = 0;
			
			for(int a = 0 ; a < secuencia_codificada.TotalEnteros() ; a = a + 2){
				
				for (int b = 0; b > secuencia_codificada.Elemento(a); b--)
				
					vector_descodificado[total_descodificado] = 
					secuencia_codificada.Elemento(a+1);
					total_descodificado++;
				
			}
			
			secuencia_codificada.BorrarSecuencia();
			
			for(int b = 0; b < total_descodificado; b++){
				
				secuencia_codificada.Aniade(vector_descodificado[b]);
				
			}
			
		}


};


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   bool introducir = true;
   int valor;
   
   SecuenciaEnteros una_secuencia, otra_secuencia;
   RLE cod_descod;
   
   
   //Entrada de datos.
	while(introducir){
		
		//Filtro para cumplir la pre-condición.
		do{
		cout << "\nIntroduzca un entero (-1 para terminar): ";
		cin >> valor;
	   }while(valor < -1 );
		
		//Si el valor entero es distinto de -1, se introduce en la secuencia.
		//En caso contrario, finaliza el bucle.
		if(valor != -1 ){
			
			una_secuencia.Aniade(valor);
			
		}
		else{
			
			introducir = false;
			
		}
		
	}
	
	//Resultados, mediante los metodos de la clase.
	otra_secuencia = una_secuencia;
	cout << "\nSecuencia introducida:" << endl;
	una_secuencia.MostrarVector();
	cod_descod.Codifica(una_secuencia);
	cout << "\nSecuencia codificada:" << endl;
	una_secuencia.MostrarVector();
	cod_descod.Descodifica(una_secuencia);
	cout << "\nSecuencia descodificada:" << endl;
	una_secuencia.MostrarVector();
	una_secuencia.EsIgualA(otra_secuencia);
	

	return (0);
	
}
