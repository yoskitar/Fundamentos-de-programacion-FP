/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
       Sesi�n 01-06.
       Problema n�mero 33:
          Dados un intervalo y un entero, decir cuantas veces
          se repite el d�gito (el entero) entre los valores
          de dicho intervalo.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusi�n de recursos de E/S
#include <cstdlib>              // Inclusi�n de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	int cifra;               //D�gito que se repite.
	int minimo;              //M�nimo del intervalo.
	int maximo;              //M�ximo del intervalo.
	int minimo_original;     //M�nimo guardado.
   int repeticiones;        //Contador de apariciones del d�gito.
   int decenas_1;           //Valor de las decenas productos de 10.
	int decenas;             //Valor de las decenas.
   int unidades;            //Valor de las unidades.
   int cifra_1;             //Valor de cifra + 1 en cada ciclo.
   int minimo_1;
   
   bool valores_correctos_cifra;    //Condicionales para controlar
   bool valores_correctos_maximo;   //los filtros.
   bool valores_correctos_minimo;
	                           
	
	
	//Entrada de datos.
	
	/*
	Filtro para controlar que los valores del capital e inter�s
	intoducidos son correctos.
	*/
	

	do{
		
	cout << "\nIntroduzca el digito que desee comprobar el numero de"
	<< " repeticiones (1 al 9): ";
	cin >> cifra;
	
	valores_correctos_cifra = ( ( cifra > 0 ) && (cifra < 10) );
	
	}while(!valores_correctos_cifra);
	
	do{
		
	cout << "Introduzca el valor minimo del intervalo cerrado: ";              
	cin >> minimo;
	
	valores_correctos_minimo = ( minimo > 0) ;
	
	}while(!valores_correctos_minimo);
	
	do{
		
	cout << "Introduzca el valor maximo del intervalo cerrado: ";              
	cin >> maximo;
	
	valores_correctos_maximo = ( maximo > minimo);

     if (!valores_correctos_maximo){
   	
      	cout << "\nEl valor introducido para el maximo no es"
   	   << " un maximo. Introduzca un valor mayor que el minimo.";
	   
	   }
	   
   }while(!valores_correctos_maximo);
   
   
	
	//C�lculos.
	
	/*
	Ciclo while para encontrar la primera vez que se repite
	el d�gito. Una vez encontrada, se repetir� en un intervalo
	de diez d�gitos. 
	Por ello encontramos un ciclo for que va sumando 10 
	a ese primer valor encontrado hasta que se supera el
	m�ximo del intervalo itroducido, y dentro de este una estructura
	condcional para comprobar si la cifra de las decenas o de las unidades
	se corresponde con dicho d�gito a comprobar, y un tercer condicionante
	que resta la cifra ya que puede darse que el valor pedido sea
	2, y al llegar a 12, si le sumamos 22, estamos obviando el 20,
	por lo que tambien debemos comprobarlo, restandole el valor 
	introducido : 22-2 = 20.
	Si la cifra se corresponde con el valor de las unidades o de 
	las decenas, el n�mero de repeticiones se incrementa en uno.
	
	*/
	
	
   minimo_original = minimo;
	cifra_1 = cifra;
	decenas = minimo/10;
	unidades = minimo%10;
	minimo_1 = minimo;
		
   while( cifra_1 != unidades && cifra_1 != decenas) {
   	
		minimo_1++;	
		decenas = minimo_1/10;
   	unidades = minimo_1%10;
   	
   }
   
   
   minimo_original = minimo;
	repeticiones = 0;
      
	for(; minimo_1 <= maximo ; minimo_1 = minimo_1 +10 ){
	  	
	   decenas_1 = (minimo_1 - cifra )/10;
	   decenas = minimo_1/10;
	   unidades = minimo_1%10;
		
	
     if(decenas == cifra){
	
	     repeticiones++; 
	   
	  }
	 
	  if(decenas_1 == cifra){
	 	
	     repeticiones++; 
	   	
	  }
	 
     if(unidades == cifra){
	 	
	  	  repeticiones++;
	 	
	  }
	
	}
	  
   //Resultados.
   
	cout << "\nLa cifra " << cifra << " aparece un total de " <<repeticiones
	<< " en el intervalo [ " << minimo_original <<" , " << maximo <<" ]" << "\n\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
