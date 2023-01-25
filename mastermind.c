#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define ANSI_VERDE "\x1b[32m"
#define ANSI_ROSSO "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define CIFRE 4


void print_titolo()
{

	char *t1 = ANSI_VERDE ".___  ___.      ___           _______.___________. _______ .______      .___  ___.  __  .__   __.  _______\n" ANSI_RESET;
	char *t2 = ANSI_VERDE "|   \\/   |     /   \\         /       |           ||   ____||   _  \\     |   \\/   | |  | |  \\ |  | |       \\\n" ANSI_RESET;
	char *t3 = ANSI_VERDE "|  \\  /  |    /  ^  \\       |   (----`---|  |----`|  |__   |  |_)  |    |  \\  /  | |  | |   \\|  | |  .--.  |\n" ANSI_RESET;
	char *t4 = ANSI_VERDE "|  |\\/|  |   /  /_\\  \\       \\   \\       |  |     |   __|  |      /     |  |\\/|  | |  | |  . `  | |  |  |\n" ANSI_RESET;
	char *t5 = ANSI_VERDE "|  |  |  |  /  _____  \\  .----)   |      |  |     |  |____ |  |\\  \\----.|  |  |  | |  | |  |\\   | |  '--'  |\n" ANSI_RESET;
	char *t6 = ANSI_VERDE "|__|  |__| /__/     \\__\\ |_______/       |__|     |_______|| _| `._____||__|  |__| |__| |__| \\__| |_______/" ANSI_RESET;
	system("clear");
	printf("%s%s%s%s%s%s\n\n\n", t1, t2, t3, t4, t5, t6);

}

void print_cogratulazioni()
{

	char *t1 = ANSI_VERDE "  ____  ______ _   _   ______   _______ _______       _ \n" ANSI_RESET;
	char *t2 = ANSI_VERDE " |  _ \\  ____|\\ | | | |  ____/\\|__   __|__   __|/\\   | |\n" ANSI_RESET;
	char *t3 = ANSI_VERDE " | |_) | |__  |  \\| | | |__ /  \\  | |     | |  /  \\  | |	\n" ANSI_RESET;
	char *t4 = ANSI_VERDE " |  _ <|  __| | . ` | |  __/ /\\ \\ | |     | | / /\\ \\ | |\n" ANSI_RESET;
	char *t5 = ANSI_VERDE " | |_) | |____| |\\  | | | / ____ \\| |     | |/ ____ \\|_|\n" ANSI_RESET;
	char *t6 = ANSI_VERDE " |____/|______|_| \\_| |_|/_/    \\_\\_|     |_/_/    \\_(_)" ANSI_RESET;
	system("clear");
	printf("%s%s%s%s%s%s\n\n\n", t1, t2, t3, t4, t5, t6);

}

void print_perso()
{

	char *t1 = ANSI_ROSSO "  _    _          _____   _____  ______ _____   _____  ____         \n" ANSI_RESET;
	char *t2 = ANSI_ROSSO " | |  | |   /\\   |_   _| |  __ \\|  ____|  __ \\ / ____|/ __ \\        \n" ANSI_RESET;
	char *t3 = ANSI_ROSSO " | |__| |  /  \\    | |   | |__) | |__  | |__) | (___ | |  | |       \n" ANSI_RESET;
	char *t4 = ANSI_ROSSO " |  __  | / /\\ \\   | |   |  ___/|  __| |  _  / \\___ \\| |  | |       \n" ANSI_RESET;
	char *t5 = ANSI_ROSSO " | |  | |/ ____ \\ _| |_  | |    | |____| | \\ \\ ____) | |__| | _ _ _ \n" ANSI_RESET;
	char *t6 = ANSI_ROSSO " |_|  |_/_/    \\_\\_____| |_|    |______|_|  \\_\\_____/ \\____(_|_|_|_)" ANSI_RESET;
	system("clear");
	printf("%s%s%s%s%s%s\n\n\n", t1, t2, t3, t4, t5, t6);

}

// Inizializza griglia di 10 righe e 9 colonne con valori a 0
void init_griglia(int griglia [10][9])
{
	
	int righe,colonne; 
	for (righe=0;righe<=9;righe++) 
	{
		for (colonne=0;colonne<=8;colonne++) 
		{
			griglia[righe][colonne]=0;
			
		}
	}
}		

//Stampa griglia di 10 righe e 9 colonne
void print_griglia(int griglia[10][9]) 
{
	int righe,colonne;
	for (righe=0;righe<=9;righe++) 
	{
		for (colonne=0;colonne<=8;colonne++) 
		{
			if (colonne > 4) 
			{
				if (griglia[righe][colonne] == 2) printf("X | "); // == 2 stampa X se cifra presente e in posizione corretta
				else if (griglia[righe][colonne] == 1) printf("Y | "); // == 1 stampa Y se cifra presente ma in posizione errata
				else printf("  | ");
			}
			else printf(" %d | ",griglia[righe][colonne]);
		}
		printf("\n");

	}
}			

// Generazione di una cifra casuale compresa tra il minimo e il massimo dichiarati
int cifra_casuale(int min, int max) 
{
	return (rand() % (max - min + 1)) + min;
}

// Inserimento numero scelto dal giocatore
void inserimento(int numero_giocatore[CIFRE]) 
{ 
	for(int i=0 ; i < CIFRE; i++)
	{
		numero_giocatore[i]=0; //iniazilizzo valori array a 0
	}
	
	int combinazione = 0;


	while ((numero_giocatore[0]<1 || numero_giocatore[0]>6)||(numero_giocatore[1]<1 || numero_giocatore[1]>6)||(numero_giocatore [2]<1 || numero_giocatore[2]>6)||(numero_giocatore [3]<1 || numero_giocatore[3]>6))
	{
		printf ("\nInserisci una combinazione di 4 cifre tra 1 e 6\nVerrà visualizzata una X per cifra presente in posizione corretta e Y per cifra presente ma in posizione errata\nP.S. Le cifre possono essere usate più di una volta\n\n");
		scanf("%d", &combinazione);	
		fflush(stdin);
		system("clear");
		print_titolo();

		//Assegnazione valori inseriti dall'utente all'array numero_giocatore attraverso un calcolo matematico
		numero_giocatore[0]=combinazione/1000;
		numero_giocatore[1]=(combinazione-(numero_giocatore[0]*1000))/100;
		numero_giocatore[2]=(combinazione-(numero_giocatore[0]*1000)-(numero_giocatore[1]*100))/10;
		numero_giocatore[3]=(combinazione-(numero_giocatore[0]*1000)- (numero_giocatore[1]*100)-numero_giocatore[2]*10);
		
		if ((numero_giocatore[0]<1 || numero_giocatore[0]>6)||(numero_giocatore[1]<1 || numero_giocatore[1]>6)||(numero_giocatore [2]<1 || numero_giocatore[2]>6)||(numero_giocatore [3]<1 || numero_giocatore[3]>6))
		{
			printf("Combinazione non accettata! Ricorda: 4 cifre tra 1 e 6.\n");
		}
	}
}


int main() 
{
	 // Inizializzo variabili
	int griglia[10][9];
	int numero_tentativi=0, estrazione=0, i, j, k;
	int numero_segreto[CIFRE], numero_giocatore[CIFRE], numero_temporaneo[CIFRE];
	
	print_titolo();
	init_griglia(griglia);
	print_griglia(griglia);
	
	// Generazione cifre casuali, srand(time(NULL)) ci permette di avere un numero diverso ogni volta che eseguiamo il programma	
	srand(time(NULL));
	for (i = 0; i < 4; i++) 
	{
		estrazione=cifra_casuale(1,6);
		numero_segreto[i]=estrazione;
	}

	while(numero_tentativi < 10) 
	{
		inserimento(numero_giocatore);
		// Copia del numero segreto in un numero temporaneo
		for (i = 0; i < 4 ; i++)
		{
			numero_temporaneo[i] = numero_segreto[i];
		}

		// Inserimento nella griglia del numero dei tentativi e del numero scelto dal giocatore
		griglia[numero_tentativi][0]=numero_tentativi+1;

		for (i = 1; i < 5; i++)
		{
			griglia[numero_tentativi][i]=numero_giocatore[i-1];
		}

		// Valutazione numero presente in posizione corretta
		for(j = 1; j < 5; j++) 
		{
			if (griglia[numero_tentativi][j] == numero_temporaneo[j-1])
			{
				numero_temporaneo[j-1] = -1; // gli assegnamo un valore negativo, in modo che una volta trovato non venga più considerato
				griglia[numero_tentativi][j+4] = 2; // ricordiamo che 2 stamperà X
			}
		}
		
		// Valutazione numero presente ma in posizione errata: 
		for(j = 1; j < 5; j++)
		{
			for(k = 0; k < 4; k++)
			{
				if(griglia[numero_tentativi][j] == numero_temporaneo[k] && griglia[numero_tentativi][j+4] != 2 && griglia[numero_tentativi][j+4] != 1)
				{
					numero_temporaneo[k] = -1;
					griglia[numero_tentativi][j+4] = 1;
				}
			}
		}
		
		// Combinazione azzeccata
		if (griglia[numero_tentativi][5]==2 && griglia[numero_tentativi][6]==2 && griglia[numero_tentativi][7]==2 && griglia[numero_tentativi][8]==2) 
		{
			print_griglia(griglia);
			print_cogratulazioni();
			break;
		}
		
		// Nessuna delle precedenti
		else
		{	numero_tentativi++;
			print_griglia(griglia);
		}

		if (numero_tentativi==10) 
		{
			print_perso();
		}	
		
	}
	return 0;
}
