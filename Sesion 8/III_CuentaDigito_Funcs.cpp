/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
// 
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
// 
// 
/* 
         Sesión 01-08.
         Problema número 15:
          Cálculo de apariciones de una cifra introducida en cada uno de los
          valores dentro de un intervalo cerrado introducido, mediante
          la implementacion de funciones.
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cctype>      //Inclusión de recursos de carácter.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Función para hallar el número de apariciones de la cifra en el intervalo
//introducido.

int Apariciones(int digito, int maximo, int minimo){
	
	//Declaraciónn de variables.
	
	int repet_total;
   int num;
	int repet_num; 
	int valor_num;
	 
	 //Número de repeticiones de la cifra en el intervalo.
	repet_total = 0;
	 
	/*
	Ciclo for para comprobar en cada uno de los valores
	del intrvalo el número de apariciones de la cifra.
	Si al descomponer el valor, alguna de sus cifras
	coincide con el digito a buscar, el ciclo if
	aumenta en uno el número de apariciones y se
	suma al número de apariciones total en el intervalo,
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

   //Declaración de variables;
   
   int cifra;         //Digito a buscar.
   int maximo;        //Máximo del intervalo.
   int minimo;        //Mínimo del intervalo.
   int apariciones;   //Apariciones del dígito en el intervalo.
   
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

	
	
	//Cálculos mediante la función anteriormente definida.
	
	apariciones = Apariciones(cifra, maximo, minimo);
	
	
	//Salida de resultados.
	
	cout << "\nEl digito " << cifra <<" aparece un total de " << apariciones
	<< " veces en el intevalo [" << minimo << "," << maximo << "]";
	
	
	return(0);
}
