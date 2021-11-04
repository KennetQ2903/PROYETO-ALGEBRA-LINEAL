/*
UNIVERSIDAD MARIANO GÁLVEZ DE GUATEMALA
INGENIERA EN SISTEMAS PLAN DOMINGO
---------------------PROYECTO DE ALGEBRA LINEAL-------------------------------
INTEGRANTES:
KENNET JORSHOA ORTEGA QUIROZ 
EDUARDO DE JESUS REYES MORALES
BRYAN EMMANUEL MOLLINEDO CHINCHILLA
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

//ENCABEZADOS

void encabezadoMenu(){
	cout<<"---------------------------------------[ MENU ] ------------------------------------------"<<endl;
}

void encabezadoConjuntos(){
	cout<<"------------------------------------[ CONJUNTOS ] ------------------------------------------"<<endl;
}
void encabezadoMatrices(){
	cout<<"------------------------------------[ Matrices ] ------------------------------------------"<<endl;
}

void encabezadoMatricesGauss(){
	cout<<"------------------------------------[ METODO GAUSS ] ------------------------------------------"<<endl;
}
void encabezadoMatricesGaussJordan(){
	cout<<"------------------------------------[ METODO GAUSS JORDAN ] ------------------------------------------"<<endl;
}
void encabezadoInversa(){
	cout<<"------------------------------------[MATRIZ INVERSA] ------------------------------------------"<<endl;
}
//-------------------------VOID GOTO XY-----------------------------------------------
void gotoxy(int x,int y){  
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos; 
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}



//--------------------------APARTADO FASE 1 (OPERACIONES CON CONJUNTOS Y OPERACIONES CON MATRICES/DETERMINANTES)---------------------------------------

//variable gloabal de menu
int o,z;

//conjuntos
int Universo[999];
int conj1[999];
int conj2[999];
int conj3[999];
int resultC[999];

//matrices
float matr22A[2][2];
float matr22B[2][2];
float matr22C[2][2];


float matr33A[3][3];
float matr33B[3][3];
float matr33C[3][3];
float matr33D[3][3];

float matrR22[2][2];
float matrR33[3][3];


bool yesNo;

//-------------------------------------------------- APARTADO CONJUNTOS --------------------------------------------------------------------
bool isValid(int num, int array[], int counter)
{
	int count = 0;
	
	
	for(int y = 0; y < counter; y++)
	{
		if(array[y] == num)
		{
			count++;
		}
	}
	
	
	if(count > 0)
	{
		return false;
	}
	if(count == 0)
	{
		count = 0;
		return true;
	}
	
	return false;
 }



void unionC()
{
	int index1, index2, num1, countV = 0, indexR;
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto A: "<<endl;
	cin>>index1;
	for(int a = 0; a < index1; a++)
	{
		cout<<"Ingrese los numeros del conjunto A "<<endl;
		cin>>conj1[a];
	}
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto B: "<<endl;
	cin>>index2;
	for(int a = index1; a < index1+index2; a++)
	{
		cout<<"Ingrese los numeros del conjunto B "<<endl;
		cin>>conj1[a];
	}
	
	indexR = index1 + index2;
	for(int i = 0; i < indexR; i++)
	{
		system("CLS");
		num1 = conj1[i];
		yesNo = isValid(num1, conj2, indexR);
		if(yesNo == true)
		{
			conj2[countV] = num1;
			countV++;
		}
	}
	//MOSTRAR
	cout<<"La union de ambos conjuntos es: "<<endl;
	cout<<"= [ ";
	for(int r = 0; r  < countV; r++)
	{
		cout<<conj2[r];
		if(r != countV-1)
		{
			cout<<", ";
		}
	}
	cout<<" ]";
	getch();
}

void interseccion()
{
	int index1, index2, num1, num2, countV = 0, indexR;
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto A: "<<endl;
	cin>>index1;
	for(int a = 0; a < index1; a++)
	{
		cout<<"Ingrese los numeros del conjunto A "<<endl;
		cin>>conj1[a];
	}
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto B: "<<endl;
	cin>>index2;
	for(int a = 0; a < index2; a++)
	{
		cout<<"Ingrese los numeros del conjunto B "<<endl;
		cin>>conj2[a];
	}
	//COMPARACION DE AMBOS ARRAYS
	indexR = index1+index2;
	for(int x = 0; x < index1; x++)
	{
		system("CLS");
		num1 = conj1[x];
		for(int y = 0; y < index2; y++)
		{
			num2 = conj2[y];
			if(num1 == num2)
			{
				yesNo = isValid(num1, conj2, index2);
				if(yesNo == false)
				{
					resultC[countV] = num1;
					countV++;
				}
			}
		}
	}
	
	//MOSTRAR
	cout<<"La interseccion de ambos conjuntos es: "<<endl;
	cout<<"= [ ";
	for(int r = 0; r  < countV; r++)
	{
		cout<<resultC[r];
		if(r != countV-1)
		{
			cout<<", ";
		}
	}
	cout<<" ]";
	getch();
}

void diferencia()
{
	system("CLS");
	int index1, index2, num1, num2, countV = 0, indexR;
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto A: "<<endl;
	cin>>index1;
	for(int a = 0; a < index1; a++)
	{
		cout<<"Ingrese los numeros del conjunto A "<<endl;
		cin>>conj1[a];
	}
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto B: "<<endl;
	cin>>index2;
	for(int a = 0; a < index2; a++)
	{
		cout<<"Ingrese los numeros del conjunto B "<<endl;
		cin>>conj2[a];
	}
	//COMPARACION DE AMBOS ARRAYS
	indexR = index1+index2;
	for(int x = 0; x < index1; x++)
	{
		system("CLS");
		num1 = conj1[x];
		for(int y = 0; y < index2; y++)
		{
			num2 = conj2[y];
			if(num1 == num2)
			{
				yesNo = isValid(num1, conj2, index2);
				if(yesNo == false)
				{
					conj3[countV] = num1;
					countV++;
				}
			}
		}
	}
	
	int countX = 0;
	for(int x = 0; x < index1; x++)
	{
		system("CLS");
		num1 = conj1[x];
		for(int y = 0; y < countV; y++)
		{
			num2 = conj3[y];
			if(num1 != num2)
			{
				yesNo = isValid(num1, conj3, index1-countV);
				if(yesNo == true)
				{
					conj2[countX] = num1;
					countX++;
				}	
			}
		}
		
	}
	countV = 0;
	for(int i = 0; i < countX; i++)
	{
		system("CLS");
		num1 = conj2[i];
		yesNo = isValid(num1, resultC, countX);
		if(yesNo == true)
		{
			resultC[countV] = num1;
			countV++;
		}
	}
	//MOSTRAR
	cout<<"La diferencia entre en conjunto A y B (A - B): "<<endl;
	cout<<"= [ ";
	for(int x = 0; x < countV; x++)
	{
		cout<<resultC[x];
		if(x != countV-1)
		{
			cout<<", ";
		}
	}
	cout<<" ]";
	getch();
}

void complemento()
{
	system("CLS");
	int index1, index2, num1, num2, countV = 0, indexR;
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto Universo: "<<endl;
	cin>>index1;
	for(int a = 0; a < index1; a++)
	{
		cout<<"Ingrese los numeros del conjunto Universo "<<endl;
		cin>>conj1[a];
	}
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto A: "<<endl;
	cin>>index2;
	for(int a = 0; a < index2; a++)
	{
		cout<<"Ingrese los numeros del conjunto A "<<endl;
		cin>>conj2[a];
	}
	//COMPARACION DE AMBOS ARRAYS
	indexR = index1+index2;
	for(int x = 0; x < index1; x++)
	{
		system("CLS");
		num1 = conj1[x];
		for(int y = 0; y < index2; y++)
		{
			num2 = conj2[y];
			if(num1 != num2)
			{
				yesNo = isValid(num1, conj2, index2);
				if(yesNo == true)
				{
					yesNo = isValid(num1, conj3, countV);
					if(yesNo == true)
					{
						conj3[countV] = num1;
						countV++;
					}
				}
			}
		}
	}
	
	//MOSTRAR
	cout<<"El complemento del conjunto A referente al universo es: "<<endl;
	cout<<"= [ ";
	for(int x = 0; x < countV; x++)
	{
		cout<<conj3[x];
		if(x != countV-1)
		{
			cout<<", ";
		}
	}
	cout<<" ]";
	getch();
	
}

void producto()
{
	int index1, index2, num1, num2, countV = 0, indexR;
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto A: "<<endl;
	cin>>index1;
	for(int a = 0; a < index1; a++)
	{
		cout<<"Ingrese los numeros del conjunto A "<<endl;
		cin>>conj1[a];
	}
	system("CLS");
	cout<<"Cuantos numeros desea ingresar al conjunto B: "<<endl;
	cin>>index2;
	for(int a = 0; a < index2; a++)
	{
		cout<<"Ingrese los numeros del conjunto B "<<endl;
		cin>>conj2[a];
	}
	cout<<"Existe un total de parejas de: "<<index1*index2<<endl;
	cout<<"Las parejas del producto de A y B son: "<<endl;
	cout<<" = [ ";
	for(int x = 0; x < index1; x++)
	{
		num1 = conj1[x];
		for(int y = 0; y < index2; y++)
		{
			num2 = conj2[y];
			cout<<"( ";
			cout<<num1;
			if(y != index2)
			{
				cout<<", ";
			}
			cout<<num2;
			cout<<" )";
			if(x != index1 && y != index2)
			{
				cout<<", ";
			}
		}
	}
	cout<<" ]"<<endl;
	getch();
}


void operacionesConjuntos()
{
	int opcion;
	
	do
	{
		system("CLS");
		encabezadoConjuntos();
		cout<<"NOTA: Para las operaciones  con conjuntos solo se tiene disponible 2 conjuntos de elementos y un conjunto unverso.\n"<<endl;
		cout<<"Elija la operacion que desea realizar: \n"<<endl;
		cout<<"1.union de conjuntos\n2.interseccion de conjuntos\n3.Diferencia de conjuntos\n4.Complemento\n5.Producto cartesiano\n6.Exit"<<endl;
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				unionC();
			break;
				
			case 2:
				interseccion();
			break;
				
			case 3:
				diferencia();
			break;
			
			case 4:
				complemento();
			break;
			
			case 5:
				producto();
			break;
			
			case 6:
				//SALIR
			break;
			
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				getch();
			break;
		}
	}while(opcion != 6);
	
}

//-------------------------------------------------- APARTADO MATRICES --------------------------------------------------------------------
	void cambiarcolor(int X)
	{ 
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
	} 
	void pin(int x,int c){
           cambiarcolor (c);
           int i;
           for(i=1;i<=x;i++){
           cout<<char(219)<<char(219);
           }
           }
	void sin(int o){
           
           int j;
           for(j=1;j<=o;j++){
           cout<<char(255)<<char(255);
           }
           }
	
	void charmander(){
		 system ("color f3");
 cout<<"\n";
 int n=240,r=244,a=252,am=254;
 cout<<"\n\t";
 sin(4);
 pin(4,n);
 sin(9);
 pin(1,n);
 
 cout<<"\n\t";
 sin(3);pin(1,n);pin(1,r);pin(2,a);pin(1,r);pin(1,n);sin(7);pin(1,n);pin(1,r);pin(1,n);
 cout<<"\n\t";
 sin(2);pin(1,n);pin(1,r);pin(4,a);pin(1,r);pin(1,n); sin(6);pin(1,n);pin(2,r);pin(1,n);  
 cout<<"\n\t";
 sin(2);pin(1,n); pin(6,a); pin(1,n); sin(6);pin(1,n);pin(2,r);pin(1,n);   
 cout<<"\n\t";
 sin(1);pin(1,n);pin(7,a);pin(1,r);pin(1,n);sin(4);pin(1,n);pin(1,r);pin(1,am);pin(2,r);pin(1,n);
 cout<<"\n\t";
 pin(1,n);pin(4,a);sin(1);pin(1,n);pin(2,a);pin(1,r);pin(1,n);sin(4);pin(1,n);pin(1,r);pin(2,am);pin(1,r);pin(1,n);
 cout<<"\n\t";
 pin(1,n);pin(4,a);pin(2,n);pin(1,a);pin(3,r);pin(1,n);sin(3);pin(1,n);pin(1,r);pin(1,am);pin(2,r);pin(1,n);
 cout<<"\n\t";
 pin(1,n);pin(4,a);pin(2,n);pin(1,a);pin(3,r);pin(1,n);sin(4);pin(1,n);pin(1,a);pin(2,n);
 cout<<"\n\t";
 sin(1);pin(1,n);pin(1,r);pin(5,a);pin(4,r);pin(1,n);sin(3);pin(1,n);pin(1,a);pin(1,n);
 cout<<"\n\t";
 sin(2);pin(2,n);pin(9,r);pin(1,n);sin(1);pin(1,n);pin(2,a);pin(1,n);
 cout<<"\n\t";
 sin(4);pin(3,n);pin(2,r);pin(1,n);pin(3,r);pin(2,n);pin(1,r);pin(1,a);pin(1,n);
 cout<<"\n\t";
 sin(5);pin(1,n);pin(2,am);pin(1,n);pin(5,r);pin(1,n);pin(2,r);pin(1,n);
 cout<<"\n\t";
 sin(5);pin(1,n);pin(3,am);pin(2,n);pin(3,r);pin(1,n);pin(1,r);pin(1,n);
 cout<<"\n\t";
 sin(4);pin(1,n);sin(1);pin(1,n);pin(3,am);pin(4,r);pin(2,n);
 cout<<"\n\t";
 sin(5);pin(3,n);sin(2);pin(3,r);pin(2,n);
 cout<<"\n\t";
 sin(8);pin(3,n);pin(1,r);pin(2,n);
 cout<<"\n\t";
 sin(9);pin(1,n);sin(1);pin(1,r);sin(1);pin(1,n);
 cout<<"\n\t";
 sin(10);pin(3,n);
getch ();
	}
	
	void dibujito(){
		   int a, b, line = 12;
		   cout<<"\n\n\n";
   for (a = line/2; a <= line; a = a+2) { //Para la parte superior del corazon
      for (b = 1; b < line-a; b = b+2) //crear espacio antes de la primera prominencia
         printf(" ");
      for (b = 1; b <= a; b++) //imprimir la primera prominencia
         printf("*");
      for (b = 1; b <= line-a; b++) //crear espacio antes de la segunda prominencia
         printf(" ");
      for (b = 1; b <= a-1; b++) //imprimir la segunda prominencia
         printf("*");
      printf("\n");
   }
   for (a = line; a >= 0; a--) { //la base del corazon es un triangulo invertido
      for (b = a; b < line; b++) //generar espacio antes del triangulo
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) //imprimir el triangulo
         printf("*");
      printf("\n");
   }

	}
void productoMatr22()
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22B[x][y];
		}
	}
	//MULTIPLICAMOS:
	matrR22[0][0] = (matr22A[0][0] * matr22B[0][0]) + (matr22A[0][1] * matr22B[1][0]);
	matrR22[0][1] = (matr22A[0][0] * matr22B[0][1]) + (matr22A[0][1] * matr22B[1][1]);
	matrR22[1][0] = (matr22A[1][0] * matr22B[0][0]) + (matr22A[1][1] * matr22B[1][0]);
	matrR22[1][1] = (matr22A[1][0] * matr22B[0][1]) + (matr22A[1][1] * matr22B[1][1]);
	
	system("CLS");
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matrR22[x][y];
		}
	}
}

void productoMatr33()
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33B[x][y];
		}
	}
	
	//MULTIPLICAMOS
	matrR33[0][0] = (matr33A[0][0] * matr33B[0][0]) + (matr33A[0][1] * matr33B[1][0]) + (matr33A[0][2] * matr33B[2][0]);
	matrR33[0][1] = (matr33A[0][0] * matr33B[0][1]) + (matr33A[0][1] * matr33B[1][1]) + (matr33A[0][2] * matr33B[2][1]);
	matrR33[0][2] = (matr33A[0][0] * matr33B[0][2]) + (matr33A[0][1] * matr33B[1][2]) + (matr33A[0][2] * matr33B[2][2]);
	
	matrR33[1][0] = (matr33A[1][0] * matr33B[0][0]) + (matr33A[1][1] * matr33B[1][0]) + (matr33A[1][2] * matr33B[2][0]);
	matrR33[1][1] = (matr33A[1][0] * matr33B[0][1]) + (matr33A[1][1] * matr33B[1][1]) + (matr33A[1][2] * matr33B[2][1]);
	matrR33[1][2] = (matr33A[1][0] * matr33B[0][2]) + (matr33A[1][1] * matr33B[1][2]) + (matr33A[1][2] * matr33B[2][2]);
	
	matrR33[2][0] = (matr33A[2][0] * matr33B[0][0]) + (matr33A[2][1] * matr33B[1][0]) + (matr33A[2][2] * matr33B[2][0]);
	matrR33[2][1] = (matr33A[2][0] * matr33B[0][1]) + (matr33A[2][1] * matr33B[1][1]) + (matr33A[2][2] * matr33B[2][1]);
	matrR33[2][2] = (matr33A[2][0] * matr33B[0][2]) + (matr33A[2][1] * matr33B[1][2]) + (matr33A[2][2] * matr33B[2][2]);
	
	system("CLS");
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matrR33[x][y];
		}
	}
	getch();
}

void productoMatr()
{
	int opcion;
	system("CLS");
	cout<<"De que tamaño es su matriz: "<<endl;
	cout<<"1.2X2\n2.3X3"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
			productoMatr22();
		break;
		
		case 2:
			productoMatr33();
		break;
		
		default: 
			cout<<"Elija una opcion valida!"<<endl;
		break;
	}
}
//INICIO SUMA DE MATRICES 22

void SumaMatr22()
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22B[x][y];
		}
	}
	//SUMAMOS:
	matrR22[0][0] = (matr22A[0][0] + matr22B[0][0]) ;
	matrR22[0][1] = (matr22A[0][1] + matr22B[0][1]) ;
	matrR22[1][0] = (matr22A[1][0] + matr22B[1][0]) ;
	matrR22[1][1] = (matr22A[1][1] + matr22B[1][1]) ;
	
	system("CLS");
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matrR22[x][y];
		}
	}
	getch();
	
}

//Inicio Suma de matrices 33
void SumaMatr33()
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33B[x][y];
		}
	}
	
	//MULTIPLICAMOS
	matrR33[0][0] = (matr33A[0][0] + matr33B[0][0]) ;
	matrR33[0][1] = (matr33A[0][1] + matr33B[0][1]) ;
	matrR33[0][2] = (matr33A[0][2] + matr33B[0][2]) ;
	
	matrR33[1][0] = (matr33A[1][0] + matr33B[1][0]) ;
	matrR33[1][1] = (matr33A[1][1] + matr33B[1][1]) ;
	matrR33[1][2] = (matr33A[1][2] + matr33B[1][2]) ;
	
	matrR33[2][0] = (matr33A[2][0] + matr33B[2][0]) ;
	matrR33[2][1] = (matr33A[2][1] + matr33B[2][1]) ;
	matrR33[2][2] = (matr33A[2][2] + matr33B[2][2]) ;
	
	system("CLS");
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matrR33[x][y];
		}
	}
	getch();
}


void SumaMatr(){
	int opcion;
	system("CLS");
	cout<<"De que tamaño es su matriz: "<<endl;
	cout<<"1.2X2\n2.3X3"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
			SumaMatr22();
		break;
		
		case 2:
			SumaMatr33();
		break;
		
		default: 
			cout<<"Elija una opcion valida!"<<endl;
		break;
		}
}
//Fin de Suma de Matrices

void restaMatr22()				//Resta de 2x2 en Matrices
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22B[x][y];
		}
	}
									//En esta parte sumo ambas matrices
	system("cls");

	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			matr22C[x][y]=matr22A[x][y] - matr22B[x][y];			
		}
	}
	
	system("cls");
	cout<<"La Matriz Resultante es: ";
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matr22C[x][y];
			
		}
	}
	getch();
}

void restaMatr33()				//Resta de 3x3 en Matrices
{
	system("CLS");
	cout<<"Ingrese los numeros de la matriz A: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33A[x][y];
		}
	}
	system("cls");
	cout<<"Ingrese los numeros de la matriz B: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33B[x][y];
		}
	}
								//En esta parte sumo ambas matrices
	system("cls");

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33C[x][y]=matr33A[x][y] - matr33B[x][y];			
		}
	}
	
	system("cls");
	cout<<"La Matriz Resultante es: ";
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matr33C[x][y];
			
		}
	}
	getch();
}

void restaMatr()
{
	int opcion;
	system("CLS");
	cout<<"De que tamano es su matriz: "<<endl;
	cout<<"1.2X2\n2.3X3"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
			restaMatr22();
		break;
			
		case 2:
			restaMatr33();
		break;
		
		default: 
			cout<<"Elija una opcion valida!"<<endl;
		break;
	}	
}
void deter22()
{
	system("cls");
	cout<<"Ingrese los datos de la matriz: "<<endl;
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr22A[x][y];
		}
	}
	
	//MULTIPLICAMOS
	float result;
	result = (matr22A[0][0] * matr22A[1][1]) -(matr22A[0][1] * matr22A[1][0]);
	
	system("cls");
	cout<<"La derminante de la Matriz: ";
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matr22A[x][y];
			
		}
	}
	cout<<"\n\n\nDeterminante: "<<result<<endl;
	getch();
}
void deter33()
{
	system("cls");
	cout<<"Ingrese los datos de la matriz: "<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			cout<<"Ingrese los numeros de la posicion x: "<<x+1<<" y: "<<y+1<<endl;
			cin>>matr33A[x][y];
		}
	}
	
	float result;
	//MULTIPLICAMOS
	
	result = ((matr33A[0][0]*matr33A[1][1]*matr33A[2][2])+(matr33A[0][1]*matr33A[1][2]*matr33A[2][0])+(matr33A[0][2]*matr33A[1][0]*matr33A[2][1]))-((matr33A[0][1]*matr33A[1][0]*matr33A[2][2])+(matr33A[0][0]*matr33A[1][2]*matr33A[2][1])+(matr33A[0][2]*matr33A[1][1]*matr33A[2][0]));
	
	system("CLS");	
	cout<<"La derminante de la Matriz: ";
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(x+3+x*4, y+3+y*4);
			cout<<matr33A[x][y];
			
		}
	}
	cout<<"\n\n\nDeterminante: "<<result<<endl;
	getch();
}
void determinante()
{
	int opcion;
	system("cls");
	cout<<"Elija el tamaño de su matriz:"<<endl;
	cout<<"1.2X2\n2.3x3\n3.Exit"<<endl;
	cin>>opcion;
	switch(opcion)
	{
		case 1:
			deter22();
		break;
		
		case 2:
			deter33();
		break;
		
		case 3: break;
		
		default: cout<<"Elija una opcion valida"<<endl;
		getch();
		break;
	}while(opcion != 3);
}

bool whatOperation(long double n)
{
	if(n > 0)
	{
		return false; //SE SUMA
	}
	return true; //SE RESTA
}

void gauss()
{
	long double F1, F2, F3; //FILAS
	long double N1, N2; //FACTORES
	long double ID; //FILA IDENTIDAD
	long double I[3]; //VARIABLES INDEPENDIENTES
	bool negPos; //BOOL PARA DECIDIR SUMA O RESTA
	long double X, Y, Z; //RESPUESTAS
	//USANDO LA MATRIZ matr33A
	system("CLS");
	encabezadoMatricesGauss();
	cout<<"\nNota: Este metodo utiliza matrices 3x3\n"<<endl;
	for(int x = 0; x < 3; x++)
	{
		if(x == 0)
		{
			cout<<"Introduzca los numeros de la matriz en la fila #1, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		if(x == 1)
		{
			system("CLS");
			encabezadoMatricesGauss();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #2, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		if(x == 2)
		{
			system("CLS");
			encabezadoMatricesGauss();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #3, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		for(int y = 0; y < 3; y++)
		{
			if(y == 0)
			{
				cout<<"X: ";
			}
			if(y == 1)
			{
				cout<<"Y: ";
			}
			if(y == 2)
			{
				cout<<"Z: ";
			}
			cin>>matr33A[x][y];
		}
		cout<<"Variable independiente fila #"<<x+1<<" : ";
		cin>>I[x];
	}
	
	system("CLS");
	cout<<"Su matriz quedaria de la siguiente forma: "<<endl;
	//MOSTRAMOS LA MATRIZ QUE INTRODUCIMOS
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33A[x][y];
		}
		gotoxy(18, x+3+x*4);
		cout<<" =  "<<I[x];
	}
	
	gotoxy(3, 24);
	cout<<"Presiona una tecla para seguir con el procedimiento..."<<endl;
	getch();
	
	//MULTIPLICAMOS POR EL METODO PIVOT
	
	//CONVERTIMOS LA ESQUINA MEDIA IZQUIERDA 0 EN DADO CASO SEA DIFERENTE DE 0
	if(matr33A[1][0] != 0)
	{
		N1 = matr33A[1][0];
		N2 = matr33A[0][0];
		float r = (N1 * N2) - (N2 * N1);
		negPos = whatOperation(r);
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //RESTA
			{
				//        F2   =  N1      *     F1  +-  N2    *   F2	  
				matr33A[1][y] = (N1 * matr33A[0][y])-(N2 * matr33A[1][y]);
				I[1] = (N1 * I[0]) - (N2 * I[1]);
			}
			else //SUMA
			{
				matr33A[1][y] = (N1 * matr33A[0][y])+(N2 * matr33A[1][y]);
				I[1] = (N1 * I[0]) + (N2 * I[1]);
			}
		}
	}
	
	//Convertir a 0 esquina inferior izquierda en dado caso sea diferente de 0
	//FORMULA: F3 = N1*F1 +- N2*F3
	if(matr33A[2][0] != 0)
	{
		N1 = matr33A[2][0];
		N2 = matr33A[0][0];
		float r = (N1 * N2) - (N2 * N1);
	
		negPos = whatOperation(r); //SE USA SUMA O SE RESTA
		
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //SE USA RESTA COMO OPERACION PRINCIPAL
			{
				//       F3   =  N1    *     F1     +-  N2    *     F3
				matr33A[2][y] = (N1 * matr33A[0][y]) - (N2 * matr33A[2][y]);
				I[2] = (N1 * I[0]) - (N2 * I[2]);
			}
			else //SE USA SUMA COMO OPERACION PRINCIPAL
			{
				matr33A[2][y] = (N1 * matr33A[0][y]) + (N2 * matr33A[2][y]);
				I[2] = (N1 * I[0]) + (N2 * I[2]);
			}
		}
	}
	
	//AHORA COMPROBAMOS SI FALTA ALGUNA FILA IDENTIDAD CONVERTIR A 1
	ID = matr33A[0][0];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[0][y] = matr33A[0][y]/ID;
		}
		I[0] = I[0]/ID;
	}
	ID = matr33A[1][1];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[1][y] = matr33A[1][y]/ID;
		}
		I[1] = I[1]/ID;
	}
	ID = matr33A[2][2];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[2][y] = matr33A[2][y]/ID;
		}
		I[2] = I[2]/ID;
	}
	
	//COMPROBAMOS QUE Z SEA DISTINTO DE 0
	if(matr33A[2][2] != 0 && matr33A[1][1] != 0)
	{
		
		Z = I[2]; // en dado caso z sea 1 al final, se le asigna el valor de la independiente como respuesta
		matr33A[1][2] = matr33A[1][2] * Z; //Reemplazamos Z
		if(matr33A[1][2] < 0) //significa que es negativo
		{
			Y = I[1] + (-1 * matr33A[1][2]);
		}
		else //significa que es positivo por lo que pasa a restar
		{
			Y = I[1] - matr33A[1][2];
		}
		//ahora reemplazamos Y y Z
		matr33A[0][1] = matr33A[0][1] * Y; //reemplazamos Y
		matr33A[0][2] = matr33A[0][2] * Z; //reemplazamos Z
		//despejamos X
		if(matr33A[0][1] < 0)//pasamos Y a sumar
		{
			I[0] = I[0] + (-1 * matr33A[0][1]);
		}
		else // pasa a restar
		{
			I[0] = I[0] - matr33A[0][1];
		}
		if(matr33A[0][2] < 0)//pasamos Z a sumar
		{
			I[0] = I[0] + (-1 * matr33A[0][2]);
		}
		else
		{
			I[0] = I[0] - matr33A[0][2];
		}
		X = I[0]; //X despejada
		
		//MOSTRAMOS LAS SOLUCIONES
		
		system("CLS");
		cout<<"Las soluciones para el sistema de ecuaciones es la siguiente: \n"<<endl;
		cout<<"Para X: "<<X<<endl;
		cout<<"Para Y: "<<Y<<endl;
		cout<<"Para Z: "<<Z<<endl;
	}
	else
	{
		cout<<"El sistema posee infinitas soluciones"<<endl;
		getch();
	}
	
	 getch();
}


void gaussJordan()
{
	long double F1, F2, F3; //FILAS
	long double N1, N2; //FACTORES
	long double ID; //FILA IDENTIDAD
	long double I[3]; //VARIABLES INDEPENDIENTES
	bool negPos; //BOOL PARA DECIDIR SUMA O RESTA
	long double X, Y, Z; //RESPUESTAS
	//USANDO LA MATRIZ matr33A
	system("CLS");
	encabezadoMatricesGauss();
	cout<<"\nNota: Este metodo utiliza matrices 3x3\n"<<endl;
	for(int x = 0; x < 3; x++)
	{
		if(x == 0)
		{
			cout<<"Introduzca los numeros de la matriz en la fila #1, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		if(x == 1)
		{
			system("CLS");
			encabezadoMatricesGauss();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #2, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		if(x == 2)
		{
			system("CLS");
			encabezadoMatricesGauss();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #3, usando el siguiente orden: (x)(y)(z)(I)\n"<<endl;
		}
		for(int y = 0; y < 3; y++)
		{
			if(y == 0)
			{
				cout<<"X: ";
			}
			if(y == 1)
			{
				cout<<"Y: ";
			}
			if(y == 2)
			{
				cout<<"Z: ";
			}
			cin>>matr33A[x][y];
		}
		cout<<"Variable independiente fila #"<<x+1<<" : ";
		cin>>I[x];
	}
	
	system("CLS");
	cout<<"Su matriz quedaria de la siguiente forma: "<<endl;
	//MOSTRAMOS LA MATRIZ QUE INTRODUCIMOS
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33A[x][y];
		}
		gotoxy(18, x+3+x*4);
		cout<<" =  "<<I[x];
	}
	
	gotoxy(3, 24);
	cout<<"Presiona una tecla para seguir con el procedimiento..."<<endl;
	getch();
	
	//MULTIPLICAMOS POR EL METODO PIVOT
	
	//CONVERTIMOS LA ESQUINA MEDIA IZQUIERDA 0 EN DADO CASO SEA DIFERENTE DE 0
	if(matr33A[1][0] != 0)
	{
		N1 = matr33A[1][0];
		N2 = matr33A[0][0];
		float r = (N1 * N2) - (N2 * N1);
		negPos = whatOperation(r);
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //RESTA
			{
				//        F2   =  N1      *     F1  +-  N2    *   F2	  
				matr33A[1][y] = (N1 * matr33A[0][y])-(N2 * matr33A[1][y]);
				I[1] = (N1 * I[0]) - (N2 * I[1]);
			}
			else //SUMA
			{
				matr33A[1][y] = (N1 * matr33A[0][y])+(N2 * matr33A[1][y]);
				I[1] = (N1 * I[0]) + (N2 * I[1]);
			}
		}
	}
	
	//Convertir a 0 esquina inferior izquierda en dado caso sea diferente de 0
	//FORMULA: F3 = N1*F1 +- N2*F3
	if(matr33A[2][0] != 0)
	{
		N1 = matr33A[2][0];
		N2 = matr33A[0][0];
		float r = (N1 * N2) - (N2 * N1);
	
		negPos = whatOperation(r); //SE USA SUMA O SE RESTA
		
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //SE USA RESTA COMO OPERACION PRINCIPAL
			{
				//       F3   =  N1    *     F1     +-  N2    *     F3
				matr33A[2][y] = (N1 * matr33A[0][y]) - (N2 * matr33A[2][y]);
				I[2] = (N1 * I[0]) - (N2 * I[2]);
			}
			else //SE USA SUMA COMO OPERACION PRINCIPAL
			{
				matr33A[2][y] = (N1 * matr33A[0][y]) + (N2 * matr33A[2][y]);
				I[2] = (N1 * I[0]) + (N2 * I[2]);
			}
		}
	}
	
	
	//Convertir a 0 esquina superior derecha en dado caso sea diferente de 0
	//FORMULA: F1 = N1*F3 +- N2*F1
	if(matr33A[0][2] != 0)
	{
		N1 = matr33A[0][2];
		N2 = matr33A[2][2];
		float r = (N1 * N2) - (N2 * N1);
		
		negPos = whatOperation(r); //SE USA SUMA O SE RESTA
		
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //SE USA RESTA COMO OPERACION PRINCIPAL
			{
				//       F1   =  N1    *     F3     +-  N2    *     F1
				matr33A[0][y] = (N1 * matr33A[2][y]) - (N2 * matr33A[0][y]);
				I[0] = (N1 * I[2]) - (N2 * I[0]);
			}
			else //SE USA SUMA COMO OPERACION PRINCIPAL
			{
				matr33A[0][y] = (N1 * matr33A[2][y]) + (N2 * matr33A[0][y]);
				I[0] = (N1 * I[2]) + (N2 * I[0]);
			}
		}
	}
	

	
	//Convertir a 0 esquina media derecha en dado caso sea diferente de 0
	//FORMULA: F2 = N1*F3 +- N2*F2
	if(matr33A[1][2] != 0)
	{
		N1 = matr33A[1][2];
		N2 = matr33A[2][2];
		float r = (N1 * N2) - (N2 * N1);
		
		negPos = whatOperation(r); //SE USA SUMA O SE RESTA
		
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //SE USA RESTA COMO OPERACION PRINCIPAL
			{
				//       F2   =  N1    *     F3     +-  N2    *     F2
				matr33A[1][y] = (N1 * matr33A[2][y]) - (N2 * matr33A[1][y]);
				I[1] = (N1 * I[2]) - (N2 * I[1]);
			}
			else //SE USA SUMA COMO OPERACION PRINCIPAL
			{
				matr33A[1][y] = (N1 * matr33A[2][y]) + (N2 * matr33A[1][y]);
				I[1] = (N1 * I[2]) + (N2 * I[1]);
			}
		}
	}
	

	
	
	//Convertir a 0 fila media superior en dado caso sea diferente de 0
	//FORMULA: F1 = N1*F2 +- N2*F1
	if(matr33A[0][1] != 0)
	{
		N1 = matr33A[0][1];
		N2 = matr33A[1][1];
		float r = (N1 * N2) - (N2 * N1);
		
		negPos = whatOperation(r); //SE USA SUMA O SE RESTA
		
		
		for(int y = 0; y < 3; y++)
		{
			if(negPos == true) //SE USA RESTA COMO OPERACION PRINCIPAL
			{
				//       F1   =  N1    *     F2     +-  N2    *     F1
				matr33A[0][y] = (N1 * matr33A[1][y]) - (N2 * matr33A[0][y]);
				I[0] = (N1 * I[1]) - (N2 * I[0]);
			}
			else //SE USA SUMA COMO OPERACION PRINCIPAL
			{
				matr33A[0][y] = (N1 * matr33A[1][y]) + (N2 * matr33A[0][y]);
				I[0] = (N1 * I[1]) + (N2 * I[0]);
			}
		}
	}
	
	
	
	
	//AHORA COMPROBAMOS SI FALTA ALGUNA FILA IDENTIDAD CONVERTIR A 1
	ID = matr33A[0][0];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[0][y] = matr33A[0][y]/ID;
		}
		I[0] = I[0]/ID;
	}
	ID = matr33A[1][1];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[1][y] = matr33A[1][y]/ID;
		}
		I[1] = I[1]/ID;
	}
	ID = matr33A[2][2];
	if(ID != 1)
	{
		for(int y = 0; y < 3; y++)
		{
			matr33A[2][y] = matr33A[2][y]/ID;
		}
		I[2] = I[2]/ID;
	}
	
	
	system("CLS");
	cout<<"Su matriz quedaria de la siguiente forma: "<<endl;
	//MOSTRAMOS LA MATRIZ QUE INTRODUCIMOS
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33A[x][y];
		}
		gotoxy(18, x+3+x*4);
		cout<<" =  "<<I[x];
	}
	getch();
	
	system("CLS");
	if(matr33A[2][2] != 0 && matr33A[1][1] != 0)
	{
		
		//MOSTRAMOS LAS SOLUCIONES
		
		X = I[0];
		Y = I[1];
		Z = I[2];
		
		system("CLS");
		cout<<"Las soluciones para el sistema de ecuaciones es la siguiente: \n"<<endl;
		cout<<"Para X: "<<X<<endl;
		cout<<"Para Y: "<<Y<<endl;
		cout<<"Para Z: "<<Z<<endl;
	}
	else
	{
		cout<<"El sistema posee infinitas soluciones"<<endl;
		getch();
	}
	
	 getch();
}	 
	 
void inversa(){
	long double F1, F2, F3; //FILAS
	long double N1, N2; //FACTORES
	bool negPos; //BOOL PARA DECIDIR SUMA O RESTA
	long double X, Y, Z; //RESPUESTAS
	//USANDO LA MATRIZ matr33A
	system("CLS");
	encabezadoInversa();
	cout<<"\nNota: Este metodo utiliza matrices 3x3\n"<<endl;
	for(int x = 0; x < 3; x++)
	{
		if(x == 0)
		{
			cout<<"Introduzca los numeros de la matriz en la fila #1, usando el siguiente orden: (x)(y)(z)\n"<<endl;
		}
		if(x == 1)
		{
			system("CLS");
			encabezadoInversa();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #2, usando el siguiente orden: (x)(y)(z)\n"<<endl;
		}
		if(x == 2)
		{
			system("CLS");
			encabezadoInversa();
			cout<<"\nIntroduzca los numeros de la matriz en la fila #3, usando el siguiente orden: (x)(y)(z)\n"<<endl;
		}
		for(int y = 0; y < 3; y++)
		{
			if(y == 0)
			{
				cout<<"X: ";
			}
			if(y == 1)
			{
				cout<<"Y: ";
			}
			if(y == 2)
			{
				cout<<"Z: ";
			}
			cin>>matr33A[x][y];
			matr33B[y][x]=matr33A[x][y];
		}
	}
	
	system("CLS");
	cout<<"Su matriz quedaria de la siguiente forma: "<<endl;
	//MOSTRAMOS LA MATRIZ QUE INTRODUCIMOS
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33A[x][y];
		}

	}
	
	gotoxy(3, 24);
	cout<<"Presiona una tecla para seguir con el procedimiento..."<<endl;
	getch();
	
//Primero encontrar la determinante
	float result;
	//MULTIPLICAMOS
	
	result = ((matr33A[0][0]*matr33A[1][1]*matr33A[2][2])+(matr33A[0][1]*matr33A[1][2]*matr33A[2][0])+(matr33A[0][2]*matr33A[1][0]*matr33A[2][1]))-((matr33A[0][1]*matr33A[1][0]*matr33A[2][2])+(matr33A[0][0]*matr33A[1][2]*matr33A[2][1])+(matr33A[0][2]*matr33A[1][1]*matr33A[2][0]));
	
	system("CLS");	
	cout<<"La derminante de la Matriz: ";
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33A[x][y];
			
		}
	}
	cout<<"\n\n\nDeterminante: "<<result<<endl;
	getch();
	
	if(result==0){
	cout<<"Si la Determinante de la matriz 3x3 es igual a 0 entonces la matriz no tiene INVERSA...";
	getch();		
	}
	else{
		//Segundo la traspuesta
	cout<<"MATRIZ TRASPUESTA"<<endl;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+18+x*4);
			cout<<matr33B[x][y];
		}

	}
		gotoxy(3, 30);
	getch();
	
	//Matriz Adjunta
	
	//MULTIPLICAMOS
	matr33C[0][0] = (matr33B[1][1] * matr33B[2][2]) -(matr33B[2][1] * matr33B[1][2]);
	matr33C[1][0] = -((matr33B[0][1] * matr33B[2][2])-(matr33B[2][1] * matr33B[0][2]));
	matr33C[2][0] = (matr33B[0][1] * matr33B[1][2]) -(matr33B[1][1] * matr33B[0][2]);
	matr33C[0][1] = -((matr33B[1][0] * matr33B[2][2]) -(matr33B[2][0] * matr33B[1][2]));
	matr33C[1][1] = (matr33B[0][0] * matr33B[2][2]) -(matr33B[2][0] * matr33B[0][2]);
	matr33C[2][1] = -((matr33B[0][0] * matr33B[1][2]) -(matr33B[1][0] * matr33B[0][2]));
	matr33C[0][2] = (matr33B[1][0] * matr33B[2][1]) -(matr33B[2][0] * matr33B[1][1]);
	matr33C[1][2] = -((matr33B[0][0] * matr33B[2][1]) -(matr33B[2][0] * matr33B[0][1]));
	matr33C[2][2] = (matr33B[0][0] * matr33B[1][1]) -(matr33B[1][0] * matr33B[0][1]);
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{	
			matr33D[x][y]=matr33C[x][y];
			
			if(matr33C[x][y]==0||matr33C[x][y]==-0){
				matr33D[x][y]=0;
				}
		}

	}	
	system("cls");
	cout<<"ESTA ES LA MATRIZ ADJUNTA DE LA MATRIZ TRASPUESTA";
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matr33D[x][y];
		}

	}
		gotoxy(3,18);
	getch();
	system("CLS");
	//DIVIDIMOS LA MATRIZ ADJUNTA POR LA DETERMINANTE
		for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			matrR33[x][y]=matr33D[x][y]/result;
			if(matrR33[x][y]==0||matrR33[x][y]==-0){
			matrR33[x][y]=0;
			}
			gotoxy(y+3+y*4, x+3+x*4);
			cout<<matrR33[x][y];
		}

	}
	getch();
	cout<<"\nDesea imprimir un corazon? 1";
	cout<<"\nDesea imprimir un charmander? 2\n";
	cin>>z;
	if(z==1){
		dibujito();
		getch();
	}
	if(z==2){
	
		charmander();
	}
	 system ("color 0");
	}

	



}	 
 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
void operacionesMatrices()
{
	int opcion;
	do
	{
		system("CLS");
		encabezadoMatrices();
		cout<<"Elija la operacion que desea realizar: "<<endl;
		cout<<"1.Producto de matrices\n2.Suma de matrices\n3.Resta de matrices\n4.Determinante de una matriz\n5.Metodo Gauss\n6.Metodon Gauss Jordan\n7.Matriz inversa\n8.Exit"<<endl;
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				productoMatr();
			break;
			
			case 2:
				SumaMatr();
			break;
			
			case 3:
				restaMatr();
			break;
			
			case 4:
				determinante();
			break;
			
			
			case 5:
				//GAUSS
				gauss();
			break;
			
			case 6:
				//GAUSS JORDAN
				gaussJordan();
			break;
			
			case 7:
				inversa();
				//INVERSA
			break;
			case 8:
				//Salir
			break;
				
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				getch();
			break;
		}
	}while(opcion!= 8);
	
}














//--------------------------------------------- APARTADO MENU PRINCIPAL ------------------------------------------------------------------

void menu()
{
	do
	{
		system("CLS");
		encabezadoMenu();
		cout<<"\n";
		cout<<"Elija la operacion que desea realizar: "<<endl;
		cout<<"1.Operaciones con conjuntos\n2.Operaciones con matrices\n3.Exit"<<endl;
		cin>>o;
		switch(o)
		{
			case 1: 
				operacionesConjuntos();
			break;
			
			case 2:
				operacionesMatrices();
			break;
			
			case 3:
				
			break;
			
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				getch();
			break;	
		}
	}while(o != 3);
}

main()
{
	system("CLS");
	menu();	
	system("CLS");
	cout<<"Nos vemos!"<<endl;
	getch();
}
