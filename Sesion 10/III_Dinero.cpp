/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-10.
         Problema número 29:
           Introducidos unos datos monetarios, recalcular las cantidades
           para que si los centimos exceden la cantidad de 100, se reagrupen
           y se sumen a los euros en la cantidad correspondiente.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Declaración de la clase Dinero.
//PRE: los valores recibidos por la clase deben ser como mínimo cero,
//ya que no puedes decir que tienes - 3 euros. En ese caso no tienes,
//sino que los debes.
class Dinero{
	
	//Datos miembros privados de la clase.
	private:
		
		int euros = 0;
		int centimos = 0;
		
	
	//Métodos y constructor públicos de la clase.	
	public:
		
		//Constructor de la clase para asignar los valores ya filtrados
		//a los datos miembro privados de la clase.
		//Recibe la cantidad entera de euros y centimos y los asigna 
		//a las respectivas variables privadas.
		Dinero(int cantidad_euros, int cantidad_centimos):
			euros (cantidad_euros), centimos (cantidad_centimos){
			}
			
		//Función de la clase para recalcular el total de euros y centimos
		//en el formato correcto (si los centimos sobrepasan la cantidad
		//de 99, se agruparán y se sumarán al total de los euros).
		void RecalculacionMonetaria(){
			
			//Declaración de variales.
			int resto_cent;
			
			
			//Cálculos.
			if(centimos >= 100){
				
				resto_cent = centimos / 100;
				centimos = (centimos % 100);
		   	euros = euros + resto_cent;
				
		   	
		   }
		
		}
		
		//Funciones para leer el total de cada una de las cantidades.
		double GetCentimos(){
			
			return centimos;
			
		}
		
		double GetEuros(){
			
			return euros;
			
		}

};


//Filtro para introducir una valor entero positivo.
//Entrada:Mensaje a mostrar.
//Salida:Valor pedido.
int Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	int numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;
	
	numero = numero_double;
	
	valores_correctos = ( numero >= 0 ) && 
	(numero_double - numero == 0);
	
	}while(!valores_correctos);
	
	return numero;
	
}


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   int los_euros;      //Cantidad de euros.
   int los_centimos;   //Cantidad de céntimos.

  
   //Entrada de datos mediante filtros definidos en las funiones.
   
   los_euros = Filtro("Introduzca una cantidad entera positiva"
	" para el total de euros: ");
	los_centimos = Filtro("Introduzca una cantidad entera positiva"
	" para el total de centimos: ");
	
	
	//Cálculos.
	
	Dinero una_cantidad(los_euros, los_centimos); //Uso del constructor.
	
	//Recalculación correcta de las cantidades introducidas.
	una_cantidad.RecalculacionMonetaria();    
	
	
	//Resultados.
	
	cout << "\nLa cantidad total sería: " << una_cantidad.GetEuros() 
	<<" euros con " << una_cantidad.GetCentimos() << " centimos"
	<< "\n";
 
	return (0);
	
}
