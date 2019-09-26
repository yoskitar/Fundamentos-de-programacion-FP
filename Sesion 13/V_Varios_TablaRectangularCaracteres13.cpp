/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-13.
         Problema n�mero 13:
           Crear la clase TablaRectangularCaracteres e implementar 
           m�todos para comprobar si una matriz es igual a otra
           y obtener la traspuesta de una dada.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 

//Declaraci�n de la clase SecuecniaCaracteres.
class SecuenciaCaracteres {
	
	//Datos privados de la clase.
	private:
		
		int numero_caracteres;
		static const int MAX = 50;
		char vector_secuencia[MAX]={0};
		
	//Datos publicos de la clase.
	public:
		
		//Constructos sin argumentos de la clase.
		SecuenciaCaracteres(){
			
			numero_caracteres = 0;
			
		}
		
		//Funci�n para a�adir un nuevo caracter a la secuencia.
		//Entrada: Un nuevo caracter.
		void Aniade(char un_caracter){
			
			vector_secuencia[numero_caracteres] = un_caracter;
			numero_caracteres++;
			
		}
		
		//Funci�n para devolver un carcacter de la secuencia.
		//Entrada: Posicion a devolver.
		//Salida: Caracter contenido en la posici�n dada del vector.
		char ElementoDelVector(int a){
			
			return vector_secuencia[a];
			
		}
		
		
		//Funci�n para devolver el total de caracteres de la secuencia.
		//Salida: Total de caracteres de la secuencia.
		int TotalCaracteres(){
			
			return numero_caracteres;

		}
		
		//Funci�n para borrar la secuencia.
		void BorraSecuencia(){
			
			numero_caracteres = 0;
			
		}

};

//Declaraci�n de la clase TablaRectangularCaracteres.
class TablaRectangularCaracteres {
	
	//Dtos privados de la clase.	
	private:
		
		static const int MAX = 50;
		int TablaCaracteres[MAX][MAX];
		char tabla_aux[MAX][MAX];
		int total_filas;
		int total_columnas;
		int filas_trasp;
		int columnas_trasp;
		

	//Datos publicos de la clase.	   
	public:
		
		TablaRectangularCaracteres(){
			
			total_filas = 0;
			total_columnas = 0;
			
		}
		
		
		//Funci�n para a�adir una nueva fila a la tabla.
		//Recibe: Fila de secuencia de caracteres.
		//Salida:void		
		void Aniade(SecuenciaCaracteres fila_nueva){
			
			total_columnas = fila_nueva.TotalCaracteres();
			
			for(int a=0; a < total_columnas ; a++){
				
				TablaCaracteres[total_filas][a] = fila_nueva.ElementoDelVector(a);
				
			}
			
			total_filas++;
			
		}
		
		//Funci�n para devolver un elemento de la tabla.
		//Entrada:Fila y columna del elemento a devovler.
		//Salida: Valor de la tabla dado la fila y la columna.
		char ElementodelaTabla(int fila, int columna){
			

			return TablaCaracteres[fila][columna];
			
		}
		
		//Funci�n para borrar la tabla.
		void EliminaTodos(){
			
			total_filas = 0;
			total_columnas = 0;
		
		}
		
		
		//Funci�n para comprobar si na tabla est� o no vac�a.
		void EstaVacia(){
			
			bool vacia = ( (total_filas == 0) && (total_columnas == 0) );
			
			if (vacia){
				
				cout << "\n\tLa tabla esta vacia." << endl;
		   }
		   else{
		   	
		   	cout << "\n\tLa tabla no esta vacia." << endl;
		   	
		   }
		   
		}
		
		
		//Funci�n para hallar la traspuesta de una matriz.
		//En una nueva tabla va introduciendo las filas de la
		//tabla dada en las columnas de una tabla nueva creada.
		void Traspuesta(){
			

			for (int f = 0 ; f < total_filas ; f++){
				
				for (int c = 0 ; c < total_columnas ; c++){
					
					tabla_aux[c][f] = TablaCaracteres[f][c];
				
				}
			
			}
			
			filas_trasp = total_columnas;
			columnas_trasp = total_filas;
			
			for (int f = 0 ; f < filas_trasp ; f++){
				
				for (int c = 0 ; c < columnas_trasp ; c++){
					
					 TablaCaracteres[f][c] = tabla_aux[f][c];

				
				}
				
			}
			
			total_columnas = columnas_trasp;
		   total_filas = filas_trasp;
		
		}
		
		
		
      //Funci�n para comprobar si dos tablas son iguales.
      //Entrada: Tabla a comparar. 
		void EsIgualA(TablaRectangularCaracteres otra_tabla){
			
			bool es_igual;
			
			es_igual = true;
			
	      for (int f = 0 ; f < total_filas ; f++){
				
				for (int c = 0 ; c < total_columnas ; c++){
					
					if(TablaCaracteres[f][c] != otra_tabla.ElementodelaTabla(f,c)){
						
						c = total_columnas;
						f = total_filas;
						
						es_igual = false;
					}
				
				}
				
			}
			
			
			if(es_igual){
				
				cout << "\n\tLas matrices son iguales.";
				
			}
			else{
				
				cout << "\n\tLas matrices no son iguales.";
				
			}
			
		}
		
		
};


int main(){ // Programa Principal.


	//Declaraci�n de datos.
	SecuenciaCaracteres una_secuencia;
	
	TablaRectangularCaracteres una_tabla, otra_tabla;
	
	char caracter, respuesta;
	bool sigue, nueva_secuencia;
	
	sigue = true;
	nueva_secuencia = true;
	
	una_tabla.EstaVacia();
	
	cout << "\nTabla 1... " << endl;
	
	//Entrada de datos.
	while(nueva_secuencia){
		
			while(sigue){
		
			cout << "\nIntroduzca un caracter (* para terminar): ";
			cin >> caracter;
		
			if(caracter != '*'){
			
				una_secuencia.Aniade(caracter);
			
			}
			else{
			
				sigue = false;
			
			}

		}
		
		una_tabla.Aniade(una_secuencia);
		una_secuencia.BorraSecuencia();
	
		cout << "\n\t�Desea intoducir una nueva secuencia (s=si)?";
		cin >> respuesta;
	
		if(respuesta != 's'){ 
	
			nueva_secuencia = false;
		
		}else{
			
			sigue = true;
			
		}
	
   }
   
   nueva_secuencia = true;
   sigue = true;
   
   cout << "\nTabla 2...." << endl;
   
	while(nueva_secuencia){
		
			while(sigue){
		
			cout << "\nIntroduzca un caracter (* para terminar): ";
			cin >> caracter;
		
			if(caracter != '*'){
			
				una_secuencia.Aniade(caracter);
			
			}
			else{
			
				sigue = false;
			
			}

		}
		
		otra_tabla.Aniade(una_secuencia);
		una_secuencia.BorraSecuencia();
	
		cout << "\n\t�Desea intoducir una nueva secuencia (s=si)?";
		cin >> respuesta;
	
		if(respuesta != 's'){ 
	
			nueva_secuencia = false;
		
		}else{
			
			sigue = true;
			
		}
	
   }
   
   
   //C�lculos y resultados.
   una_tabla.Traspuesta();
   una_tabla.EsIgualA(otra_tabla);
   
              
              
	return (0);
	
}
