/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-12.
         Problema número 25:
           Introducir un numero de sucursales y las ventas de cada una y 
           mostrar por pantalla la sucursal que mas halla vendido junto con
           un listado de todas las que hallan vendido algo.Ampliacion mediante
           una matriz que contenga el numero de productos vendidos de 
           cada uno de los tipos.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//struct para cada sucursal con el identificador y el número de unidades
//vendidas.
struct Sucursal {
	
	int identificador;
	int ventas = 0;

	
};

struct Producto {
	
	char letra;
	int unidades = 0;
	
	
};

//Declaración de la clase banco.
class Banco{
	
	//datos privados de la clase.
	private:
		
		static const int MAX = 100;
		static const  int MAX_COLUMNAS = 107;
		static const int MAX_FILAS = 100;
		static const int MAX_P = 10;
		
		double ventas_sucursal[MAX_FILAS];
		double ventas_producto[MAX_COLUMNAS];
		Sucursal sucursales[MAX];
		Sucursal sucursales_mayor[MAX];
		Producto total_producto[MAX];
		int tipos_producto[MAX_P];
		
		int total_sucursales;
		int inicio = 0;
		int productos = 0;
		int total_uds_vendidas = 0;
		
		int tabla[MAX_FILAS][MAX_COLUMNAS];
		
	//datos públicos de la clase.
	public:
		
		//declaración del constructor sin argumentos.
		Banco(){
			
			sucursales[0].identificador = 0;
			sucursales[0].ventas = 0;
			total_sucursales = 0;
			tabla[MAX_FILAS][MAX_COLUMNAS] = {0};
			
			
			
		}
		
		//método para devolver el total de sucursales.
		int NumeroSucursales(){
			
			return total_sucursales;
		
		}
		
		//método para añadir el identficador de una sucursal y su
		//numero de ventas. entrada: identificador y ventas.
		void Aniade(int id_sucursal, int unidades, char producto){
			
			bool nueva_sucursal = true;
			bool nuevo_producto = true;
			
			if (total_sucursales < MAX){
				
				for (int a = 0; a<=total_sucursales ; a++){
					
					if (sucursales[a].identificador == id_sucursal){
						
						tabla[id_sucursal-1][producto-0] = 
						tabla[id_sucursal-1][producto-0] + unidades;
						sucursales[a].ventas = sucursales[a].ventas + unidades;
						nueva_sucursal = false;

				   }
				   
				   for (int c=0; c<=10 ; c++){
				   	
				      if (tipos_producto[c] == producto){
				   	
				   	   nuevo_producto = false;
				   	
				      }
				   }
				   		
				}
				
		      
		      if (nueva_sucursal){
		      	
               sucursales[total_sucursales].ventas = unidades;
               sucursales[total_sucursales].identificador = id_sucursal;
               tabla[id_sucursal-1][producto-0] = unidades;
			      total_sucursales++;
			   
				}
				
				if (nuevo_producto){
					
					tipos_producto[productos] = producto;
					productos++;
					
				}
				
         }
					
		}
		
		
		
		//Función para hallar el total de unidades vendidas de cada uno de los 
		//productos.
		void TotalUdsProducto(){
			
			int total = 0;
			
			for(char i = 'a'-0 ; i <= 'j' ; i++){
				
				total = 0;
				for(int b = 0; b < total_sucursales ; b++){
					
					total = tabla[b][i-0] + total;
					
				}
				
				cout << endl << "Letra: " << i << " ---> Uds: " << total
				<< endl;
		   
			}
			
		}
		
	//Función para hallar el total de unidades vendidas, por todas
	//las sucursales de todos los productos.	
	void TotalesUdsVendidas(){
			
			int total;
			for(char i = 'a'-0 ; i <= 'j' ; i++){
				
				for(int b = 0; b < total_sucursales ; b++){
					
					total = tabla[b][i-0] + total;
					
				}

		   }
		   
		   cout << "Unidades totales vendidas: " << total;
	
	}
			
		
		//Funciones para leer el valor del total de tipos de productos.
		//Tipos de productos vendidos.	
		int GetTiposProducto(){
			
			return productos;
			
		}
		
		
		//Función para hallar cual es el producto más vendido.
		//Salida:void
		void ProductoMasVendido(){
			
			int uds_mayor = 0;
			char producto_mayor;
			
			
			int total = 0;
			
			for(char i = 'a'-0 ; i <= 'j' ; i++){
				
				total = 0;
				for(int b = 0; b < total_sucursales ; b++){
					
					total = tabla[b][i-0] + total;
					
				}
				if (total > uds_mayor){
					
					producto_mayor = i;
					uds_mayor = total;
				}
				
			}
			
			cout << "\nProducto mas vendido: " << producto_mayor << " ----> "
			<< uds_mayor << " uds." << endl;
					
		}
			
							
		
		//metodo para mostrar la sucursal con el mayor numero de ventas.
		//Variable que en caso de que el número de ventas nuevo sea mayor
		//al que ya haía, se actualiza y este nuevo pasa a ser el mayor.
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
				<< sucursales_mayor[a].ventas << endl;

			}
		
		}
		
		//metodo para mostrar el listado de todas las sucursales recorriendo
		//todas las componentes del vector.
		void ListadoSucursales(){
			
         cout << "\n\nListado de sucursales: \n";
			for(int a = 0; a < total_sucursales; a++){
				
				cout << "\nIdentificador de sucursal: "
				<< sucursales[a].identificador << " ----->Numero de ventas: " 
				<< sucursales[a].ventas << endl;

			}  			

		}

};

//Función que recibe un mensaje y devuelve un valor filtrado.
double Filtro (string msg){
	
	double valor;
	
	do{
		
	cout << msg;
	cin >> valor;
	
   }while( valor < 0);
   
   return valor;
	
}

//Función que recibe un mensaje y devuelve un valor filtrado.
double Filtrocaracter (string msg){
	
	char valor;
	
	do{
		
	cout << msg;
	cin >> valor;
	
   }while( valor < 97 || valor > 106);
   
   return valor;
	
}

int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   Banco un_banco;
   const int MAX_SUCURSALES = 100;
   const int TERMINADOR = -1;
   int unidades;
   int identificador;
   char cod_producto;
   
   
   // Cálculos  y entrada de datos.
   
   for ( int i = 0 ; i < MAX_SUCURSALES ; i++){  
	
	   cout << "\nIntroduzca el identificador de la sucursal: ";
	   cin >> identificador;
		
		if (identificador == TERMINADOR ){
			
			i = MAX_SUCURSALES + 1;
			
		}
		else{
		   
		   cod_producto = Filtrocaracter("\nIntroduzca el producto: ");
		   unidades = Filtro("\nNumero de unidades vendidas: ");
		   un_banco.Aniade(identificador, unidades, cod_producto);

      }
      
   }
   

   
   //Resultados.
   
   cout << endl;
	un_banco.SucursalConMayorVentas(); 
	un_banco.ListadoSucursales(); 
	cout << endl << endl;
   un_banco.TotalUdsProducto();
   un_banco.ProductoMasVendido();
   cout << "Total de tipos de productos vendidos: "
	<< un_banco.GetTiposProducto() << endl;
   un_banco.TotalesUdsVendidas();


	return (0);
	
}
