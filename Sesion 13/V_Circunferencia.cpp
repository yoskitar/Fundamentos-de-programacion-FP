/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C)Jos� Cortijo Bon (class circunferencia)
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-013.
         Problema n�mero 3:
            Crear una clase para inicializar el centro de una circunferencia
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


// Clase Punto2D para los puntos 2D.

class Punto2D{
	
	//Datos privados de la clase.
	private:
		
		double x;
		double y;
		
	//Datos publicos de la clase.
	public:
		
		//Constructor de la clase sin par�metros..
		Punto2D(){
			
			x=0;
			y=0;

		}
		
		//Metodo para introducir las coordenadas del centro.
		//Recibe el valor de la abscisa y la ordenada.
		void SetCentro(double px, double py){
			
			x = px;
			y = py;

		}
      
      //Metodo para devolver el valor de la abscisa.
      //Salida: valor de la abscisa.
		double GetAbsc(){
			
			return x;
			
		}
     
     //M�todo para devolver el valor de la ordenada.
     //Devuelve el valor de la ordenada.
		double GetAOrdn(){
			
			return y;
			
		}
			
};

/////////////////////////////////////////////////////////////////////////////
// La clase "Circunferencia" representa circunferencias:
// objetos geom�tricos que verifican la propiedad de que los puntos (x,y)
// que la forman est�n a la misma distancia de otro punto -centro-.

class Circunferencia
{

private:

	// La constante "PI" es com�n a todos los objetos de la clase.
	// Como no es int no puede iniciarse junto a su declaraci�n. 
	// Se inicializa al finalizar la definici�n de la clase.
	static const double PI;		
	
	// Centro de la circunferencia
	Punto2D centro;	
	
	// Longitud del radio
	// PRE: radio >= 0
	double radio;
	
	
public:
	
	
	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		el_centro, un struct con las coordenadas del centro
	//		radio, el valor del radio
	// PRE: radio >= 0

	Circunferencia (Punto2D el_centro , double el_radio)
	{
		centro = el_centro; // Asignaci�n entre dos struct
		radio  = el_radio; 
	}

	/***********************************************************************/
	// M�todos Get
	
	Punto2D GetCentro (void)
	{
		return (centro);
	}

	double GetRadio (void)
	{
		return (radio);
	}
	
	void GetCentroCircunferencia(){
		
		cout << "\n\tEl centro de la circunferencia es (" << centro.GetAbsc() 
		<< " , " << centro.GetAOrdn() << ")" << endl;

	}
	
	double GetDiametro(){
		
		return radio*2.0;
	
	}

	/***********************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud (void)
	{
		return (2.0 * PI * radio);
	}

	/***********************************************************************/
	// Calcula el �rea del c�rculo
	
	double Area (void)
	{
		return (PI * radio * radio);
	}

	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado.
	/*
		Un punto (p_x, p_y) est� dentro de una circunferencia con centro 
		(c_x, c_y) y radio r si se verifica que:

		(p_x - c_x)^2 + (p_y - c_y)^2  <=  r^2
	*/

	bool Contiene (Punto2D un_punto)
	{
		double dif_x_cuadrado = pow (centro.GetAbsc() - un_punto.GetAbsc(), 2);
		double dif_y_cuadrado = pow (centro.GetAOrdn() - un_punto.GetAOrdn(), 2);

		return (dif_x_cuadrado + dif_y_cuadrado <= radio*radio);
	}

	/***********************************************************************/

};

// Inicializaci�n de la constante est�tica PI

const double Circunferencia::PI = 3.1415926;


int main()//Programa principal
{	

   //Declaraci�n de variables.
   
	double abscisa_centro;
	double ordenada_centro;
	double radio;
	
	char respuesta;


	// Entrada de datos.


	cout << "Introduzca la coordenada x del centro: ";
	cin >> abscisa_centro; 

	cout << "\nIntroduzca la coordenada y del centro: ";
	cin >> ordenada_centro; 


	// Lectura del radio y filtro para asegurar la precondici�n

	do {
		
		cout << "\nIntroduzca el radio de la circunferencia: ";
		cin >> radio; 
		
	} while (radio < 0);


	Punto2D un_centro;
	un_centro.SetCentro(abscisa_centro, ordenada_centro);


	// Creaci�n de un objeto Circunferencia --> constructor

	Circunferencia una_circunferencia(un_centro, radio);


	// Uso de los m�todos de c�lculo sencillos

	cout << "\nLa longuitud de la circunferencia de centro ("   
	<< un_centro.GetAbsc() << "," << un_centro.GetAOrdn() << ") "
	<< "y radio " << una_circunferencia.GetRadio()
	<< " es: "<< una_circunferencia.Longitud() << endl;
	
	cout << "\nEl area del circulo sera: " << una_circunferencia.Area()
	<< endl;
	
	cout << "\nObteniendo valor del centro...";
	una_circunferencia.GetCentroCircunferencia();
	cout << "Obteniendo valor del diametro..." << endl;
	cout << "\tDiametro = " <<una_circunferencia.GetDiametro();

	// C�lculo de la pertenencia (o no) de una serie de puntos.
	
	bool sigo = true; 

	while (sigo) {
	
		double punto_x, punto_y;
		Punto2D un_punto;
		
		cout << endl;
		cout << "\nIntroduzca las coordenadas del punto." << endl;
		
		cout << "\tCoordenada X del punto = ";
		cin >> punto_x; 
		cout << "\tCoordenada Y del punto = ";
		cin >> punto_y; 

		// Crea un dato CoordenadasPunto2D y rellena los campos del struct 
		// con los valores leidos, para poder pasarlo al m�todo Contiene()

		un_punto.SetCentro(punto_x, punto_y);
		if (una_circunferencia.Contiene(un_punto)){
			
			cout << "\n\tEl punto si se encuentra contenido en la circunferencia."
			<< endl;
			
		}
		else{
			
			cout << "\n\tEl punto no se encuentra contenido en la circunferencia." 
			<< endl;
			
		}
		
		// Preparando una nueva comprobaci�n

		cout << "\nPulse (s) para realizar una nueva comprobaci�n "; 
		cin >> respuesta; 
		
		if (toupper(respuesta) != 'S'){
			
			sigo = false;
			
		}
	
	} // while (sigo)
	
	return (0);
}
