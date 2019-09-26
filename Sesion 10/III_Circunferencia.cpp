/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-010.
         Problema n�mero 34:
            Crear un struct para inicializar el centro de una circunferencia
            y dado un radio, hallar la longuitud de la circunferencia,
            y el �rea del c�rculo. Comprobar adem�s si un punto dado
            se encuentra dentro de la circunferencia.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Struct para las coordenadas del punto central de la circunferencia.
struct CoordenadasPunto2D {
	
	int eje_x;
	int eje_y;
	
};


//Declaraci�n de la clase Circunferencia.
class Circunferencia{
	
	//Datos miembros privados de la clase.
	private:
	
	static const double PI;
	
	const double ABSCISA;
   const double ORDENADA;
	const double RADIO;
	
	double longuitud;
	double area;
	
	bool punto_interior;
	
	
	//M�todos y constructor p�blicos de la clase.	
	public:

		Circunferencia(double valor_x, double valor_y, double el_radio)
		:ABSCISA (valor_x),
		ORDENADA (valor_y),
		RADIO (el_radio)
		{
	   }
		
		
		//Funci�n para hallar la longuitud de una circunferencia de radio dado.
		//salida: Longuitud de la circunferencia.
		double Longuitud(){
			
			longuitud = 2 * PI * RADIO;
			
			return longuitud;
			
		}

		//Funci�n para hallar el �rea de un c�rculo de radio dado.
		//salida: �rea de un c�rculo.
		double Area(){
			
			area = 2 * PI * pow(RADIO, 2);
			
			return area;
			
		}
		
		//Funci�n para comprobar si un punto pertenece a una circunferencia..
		//salida: Valor l�gico para saber si el punto es interno.
		bool PuntoInterior(double x, double y){
			
			punto_interior = (pow( (ABSCISA - ORDENADA), 2) + 
			pow( ( x - y ), 2) ) <= ( pow(RADIO, 2) );
			
			return punto_interior;
	
		}

};

//Asignaci�n del valor de PI.
const double Circunferencia::PI = 3.141592653; 


//Filtro para introducir una valor positivo.
//Entrada:Mensaje a mostrar.
//Salida:Valor pedido.
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


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   double punto_interior_x;  //Abscisa del punto a comprobar.
	double punto_interior_y;  //Ordenda del punto a comprobar.
   double radio_circ;        //Radio de la circunferencia dada.
  
  
   //Entrada de datos mediante struct.
   
   radio_circ = Filtro("\nIntroduzca el radio de la circunferencia: ");
   cout << "\nIntroduzca la abscisa del punto interior a comprobar: ";
	cin >> punto_interior_x;
	cout << "\nIntroduzca la ordeanada del punto interior a comprobar: ";
   cin >> punto_interior_y;
   
   
   //Struct.
   CoordenadasPunto2D centro = {0, 0};
   
   
	//C�lculos.
	
	//Uso del constructor.
	Circunferencia una_circunferencia(centro.eje_x, centro.eje_y, radio_circ); 
	
	
	//Resultados.
	
	cout << "\nEl area de la circunferencia es: " 
	<< una_circunferencia.Area();
	cout << "\nLa longuitud de la circunferencia es: "
	<< una_circunferencia.Longuitud();
	if (una_circunferencia.PuntoInterior(punto_interior_x, punto_interior_y)){
		
		cout << "\nEl punto dado pertenece a la circunferencia.";
		
	}
	else{
		
		cout << "\nEl punto dado no pertenece a la circunferencia.";
		
	}
	
	return (0);
	
}
