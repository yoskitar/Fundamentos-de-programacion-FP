/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
// 
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
// 
// 
/* 
         Sesi�n 01-08.
         Problema n�mero 15:
          C�lculo de apariciones de una cifra introducida en cada uno de los
          valores dentro de un intervalo cerrado introducido, mediante
          la implementacion de funciones.
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cctype>      //Inclusi�n de recursos de car�cter.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 

//Funci�n para hallar el n�mero de apariciones de la cifra en el intervalo
//introducido.

int Apariciones(int digito, int maximo, int minimo){
	
	//Declaraci�nn de variables.
	
	int repet_total;
   int num;
	int repet_num; 
	int valor_num;
	 
	 //N�mero de repeticiones de la cifra en el intervalo.
	repet_total = 0;
	 
	/*
	Ciclo for para comprobar en cada uno de los valores
	del intrvalo el n�mero de apariciones de la cifra.
	Si al descomponer el valor, alguna de sus cifras
	coincide con el digito a buscar, el ciclo if
	aumenta en uno el n�mero de apariciones y se
	suma al n�mero de apariciones total en el intervalo,
	antes de ser reinicializado a cero y volver a repetir
	el proceso del ciclo for hasta llegar al valor del 
	maximo introducido.
	*/

   for (num = minimo ; num <= maximo ; num++) {

      valor_num = num;
      repet_num = 0;

      while (valor_num != 0) {

         if (valor_num % 10 == digito){
            	
               repet_num++;
                
            }

            valor_num = valor_num / 10;
            
      }

      repet_total += repet_num; 
        
   }
    
    return repet_total;

}

	
int main(){

   //Declaraci�n de variables;
   
   int cifra;         //Digito a buscar.
   int maximo;        //M�ximo del intervalo.
   int minimo;        //M�nimo del intervalo.
   int apariciones;   //Apariciones del d�gito en el intervalo.
   
   bool valores_correctos_cifra;    //Condicionales para controlar
   bool valores_correctos_maximo;   //los filtros.
   bool valores_correctos_minimo;

   
   //Entrada de datos mediante filtros.
   
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
   	   << " un maximo. Introduzca un valor mayor que el minimo.\n";
	   
	   }
	   
   }while(!valores_correctos_maximo);

	
	
	//C�lculos mediante la funci�n anteriormente definida.
	
	apariciones = Apariciones(cifra, maximo, minimo);
	
	
	//Salida de resultados.
	
	cout << "\nEl digito " << cifra <<" aparece un total de " << apariciones
	<< " veces en el intevalo [" << minimo << "," << maximo << "]";
	
	
	return(0);
}
