/*
UNIVERSIDAD MARIANO GÁLVEZ DE GUATEMALA
INGENIERA EN SISTEMAS PLAN DOMINGO
---------------------PROYECTO DE ALGEBRA LINEAL-------------------------------
INTEGRANTES:
KENNET JORSHOA ORTEGA QUIROZ - 6691-21-8308
EDUARDO DE JESUS REYES MORALES
BRYAN EMMANUEL MOLLINEDO CHINCHILLA
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

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
int o;

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
	getch();
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
void operacionesMatrices()
{
	int opcion;
	do
	{
		system("CLS");
		encabezadoMatrices();
		cout<<"Elija la operacion que desea realizar: "<<endl;
		cout<<"1.Producto de matrices\n2.Suma de matrices\n3.Resta de matrices\n4.Determinante de una matriz\n5.Exit"<<endl;
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
				//SALIR
			break;
			
			default:
				cout<<"Ingrese una opcion valida"<<endl;
				getch();
			break;
		}
	}while(opcion!= 4);
	
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
