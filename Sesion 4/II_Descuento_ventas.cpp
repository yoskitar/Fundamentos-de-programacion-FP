/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*       Sesion 01-04.
         Problema número 9:
            Aplicar un 3% de descuento si el número de unidades vendidas 
				es superior a 100 y en este caso, si la venta supera los 700€
				se le aplicará otro descuento acumulable de un 2%.
            
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>     // Inclusión de llamadas al sistema.


using namespace std; 

enum class Descuentos{nulo, medio, maximo};

int main(){ // Programa Principal.
            
            
   // Declara variables para guardar.
   
   Descuentos descuento;        //Declaración de la clase.
   
   const double INTERES3 = 0.03;     //Interés del 3%.
   const double INTERES2 = 0.02;    //Interés del 2%.
   
	int unidades;              //Número de unidades vendidas.
   double precio;            //Precio con el 5% o sin interés aplicado.
   double precio_3;         //Precio con el 3% aplicado.
   
   //Entrada de datos.
	
	cout << "\nIntroduzca la cantidad de unidades vendidas: ";
	cin >> unidades;
	
	cout << "\nIntroduzca el precio de la compra: ";
	cin >> precio;
	
		
	//Cálculos y resultados.
	
	/*
	Estructura condicional para controlar el descuento que debe ser aplicado
	en cada una de las condiciones. Si la cantidad supera las 100 unidades,
	al precio de venta se le aplica un 3% de descuento. En caso de que el 
	precio inicial de compra supere los 700€ se le aplicará un 5% resultante
	del 3% anterior más un 2% por cumplir esta nueva condición.
	Si no cumple la primera condición, el precio se mantiene sin decuentos.
	En cada caso muestra por consola el descuento aplicado y el precio final.
	*/
	

	
	if (unidades > 100 ){
	
	precio_3 = ( precio - (precio * INTERES3) );  
	  
	  if (precio > 700 ){
	  	
	  	precio = (precio - (precio * (INTERES3 + INTERES2)));
	  	
	  	descuento = Descuentos::maximo;
	  
	  }	
	  	
	  	else {
	  		
	  		descuento = Descuentos::medio;
		  	
	  	}
	  
	}
	else {
		
		descuento = Descuentos::nulo;
	  	
	}	
	
	switch(descuento){
		case Descuentos::maximo:
			cout<< "\nEl precio tiene un descuento del 5%,"
	  	   <<" su precio ahora es de: " << precio <<" euros." ;
	  	   break;
	  	   
	  	case Descuentos::medio:
			cout<< "\nEl precio tiene un descuento del 3%,"
	  	   <<" su precio ahora es de: " << precio_3 <<" euros." ;
	  	   break;
	  	   
	  	case Descuentos::nulo:
			cout<< "\nEl precio no tiene descuento,"
	  	   <<" sigue costando: " << precio <<" euros.";
	  	   break;
			
	}
		 
	cout << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
