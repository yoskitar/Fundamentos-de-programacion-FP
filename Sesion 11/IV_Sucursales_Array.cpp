/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-11.
         Problema n�mero 1:
           Introducir un numero de sucursales y las ventas de cada una y 
           mostrar por pantalla la sucursal que mas halla vendido junto con
           un listado de todas las que hallan vendido algo.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//struct para cada sucursal con el identificador y el n�mero de unidades
//vendidas.
struct Sucursal{
	
	int identificador;
	int ventas;
	
};

//Declaraci�n de la clase banco.
class Banco{
	
	//datos privados de la clase.
	private:
		
		static const int MAX = 100;
		Sucursal sucursales[MAX];
		int total_sucursales;
		Sucursal sucursales_mayor[MAX];
		int inicio = 0;
		
	//datos p�blicos de la clase.
	public:
		
		//declaraci�n del constructor sin argumentos.
		Banco(){
			
			sucursales[0].identificador = 0;
			sucursales[0].ventas = 0;
			total_sucursales = 0;
			
			
			
		}
		
		//m�todo para devolver el total de sucursales.
		int NumeroSucursales(){
			
			return total_sucursales;
		
		}
		
		//m�todo para a�adir el identficador de una sucursal y su
		//numero de ventas. entrada: identificador y ventas.
		void Aniade(int id_sucursal, int unidades){
			
			bool nueva_sucursal = true;
			
			if (total_sucursales < MAX){
				
				for (int a = 0; a<=total_sucursales ; a++){
					
					if (sucursales[a].identificador == id_sucursal){
						
						sucursales[a].ventas = sucursales[a].ventas + unidades;
						nueva_sucursal = false;
						
				   }
				
				}
		      
		      if (nueva_sucursal){
		      	
               sucursales[total_sucursales].ventas = unidades;
               sucursales[total_sucursales].identificador = id_sucursal;
			      total_sucursales++;
			   
				}
	      
			}
			
		}
		
		
		//metodo para mostrar la sucursal con el mayor numero de ventas.
		//Variable que en caso de que el n�mero de ventas nuevo sea mayor
		//al que ya ha�a, se actualiza y este nuevo pasa a ser el mayor.
		void SucursalConMayorVentas(){
			
			int unidades_mayor = 0;
			int unidades;
			int id_mayor;
			
			for(int i=0; i < total_sucursales; i++){
				
				unidades = sucursales[i].ventas;
				id_mayor = sucursales[i].identificador;
	
	
				if (unidades_mayor == unidades){
					
					inicio++;
					sucursales_mayor[inicio].identificador = id_mayor;
					sucursales_mayor[inicio].ventas = unidades;
					unidades_mayor = unidades;

			   }
			   
			   if (unidades > unidades_mayor){
					
					inicio = 0;
					sucursales_mayor[inicio].identificador = id_mayor;
					sucursales_mayor[inicio].ventas = unidades;
					unidades_mayor = unidades;
					
				}
			   
			   
	
			}
			
			cout << "\nSucursales con mayores ventas: \n";
			for(int a = 0; a <= inicio; a++){
				
				cout << "\nIdentificador de sucursal: "
				<< sucursales_mayor[a].identificador << " ----->Numero de ventas: " 
				<< sucursales_mayor[a].ventas;

			}
		
		}
		
		//metodo para mostrar el listado de todas las sucursales recorriendo
		//todas las componentes del vector.
		void ListadoSucursales(){
			
         cout << "\n\nListado de sucursales: \n";
			for(int a = 0; a < total_sucursales; a++){
				
				cout << "\nIdentificador de sucursal: "
				<< sucursales[a].identificador << " ----->Numero de ventas: " 
				<< sucursales[a].ventas;

			}  			

		}

};

//Funci�n que recibe un mensaje y devuelve un valor filtrado.
double Filtro (string msg){
	
	double valor;
	
	do{
		
	cout << msg;
	cin >> valor;
	
   }while( valor < 0);
   
   return valor;
	
}

int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   Banco un_banco;
   const int MAX_SUCURSALES = 100;
   const int TERMINADOR = -1;
   int unidades;
   int identificador;
   
   
   // C�lculos  y entrada de datos.
   
   for ( int i = 0 ; i < MAX_SUCURSALES ; i++){  
	
	   cout << "\nIntroduzca el identificador de la sucursal: ";
	   cin >> identificador;
		
		if (identificador == TERMINADOR ){
			
			i = MAX_SUCURSALES + 1;
			
		}
		else{
		
		   unidades = Filtro("\nNumero de unidades vendidas: ");
		   un_banco.Aniade(identificador, unidades);

      }
      
   }
   
   //Resultados.
	un_banco.SucursalConMayorVentas(); 
	un_banco.ListadoSucursales(); 


	return (0);
	
}
