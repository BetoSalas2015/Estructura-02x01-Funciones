#include <stdio.h>
#include <stdlib.h>

// Prototipos
void conversion_horas(int hora, int minuto);
float calcula_salario(int horas);
void domingo_pascua(int year);
void segundos_a_horas(int segundos);


void conversion_horas(int hora, int minuto)
{
	int horas;
	if(hora == 0 || hora == 12) 
		horas = 12;
	else
		horas = hora % 12;
	if(hora >= 12)
		printf("%d:%d PM\n\n", horas, minuto);
	else
		printf("%d:%d AM\n\n", horas, minuto);
}

float calcula_salario(int horas)
{
	int extras = horas - 40;
	if(horas <= 40)
		return horas * 200;
	else
		return extras * (200 * 1.5) + 8000;
}

void domingo_pascua(int year)
{
	int A, B, C, D, E, N;
	A = year % 19;
	B = year % 4;
	C = year % 7;
	D = (19 * A + 24) % 30;
	E = (2 * B + 4 * C + 6 * D + 5) % 7;
	N = (22 + D + E);
	if((D + E) < 10)
		printf("El domingo de pascua en %d es el %d de marzo.\n",year, N);
	else
	{
		if((D + E - 9) == 26) 
		{
			printf("El domingo de pascua en %d es el 19 de abril.\n",year);
			return;
		}
		if((D + E - 9) == 25 && D == 28 && E == 6 && A > 10)
		{
			printf("El domingo de pascua en %d es el 19 de abril.\n",year);
			return;
		}
		printf("El domingo de pascua en %d es el %d de abril.\n",year, (D + E - 9));
	}
		

}

void segundos_a_horas(int segundos)
{
	int horas, minutos, segs = segundos;
	horas = segundos / 3600;
	segundos -= ( horas * 3600);
	minutos = segundos / 60;
	segundos -= (minutos * 60);
	printf("Hay %2d horas, %2d minutos y %2d segundos en %5d Segundos\n\n", horas, minutos, segundos, segs);
}

int main()
{
	int horas, minutos, segundos, year;
	
	// Ejercicio 1.1
	printf("Introduce la hora en formato 24 horas: ");
	scanf("%d:%d", &horas, &minutos);
	conversion_horas(horas, minutos);

	// Ejercicio 1.2
	printf("Introduce horas trabajadas del empleado: ");
	scanf("%d", &horas);
	printf("El salario del empleado es: %8.2f\n\n", calcula_salario(horas) );

	// Ejercicio 1.3
	printf("Introduce el año para determinar el domingo de Pascua: ");
	scanf("%d", &year);
	domingo_pascua(year);

	// Ejercicio 1.4
	printf("Introduce el numero de segundos: ");
	scanf("%d", &segundos);
	segundos_a_horas(segundos);

	system("pause");
	return 0;
}


