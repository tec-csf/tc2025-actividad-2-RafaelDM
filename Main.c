/*
Rafael Díaz Medina
A01024592
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* titulo;
	int paginas;
} Libro;

/* Tipos de funciones */
typedef void (*opciones);
typedef void* (*t_pos)(void*, int);
typedef void* (*t_next)(void*);
typedef void (*t_print)(void*);
typedef void (*t_sort)(void *, size_t, int, t_next, t_pos, t_next, t_next, t_print);

/* Funciones genéricas */
void Recorre(t_sort, void *, size_t , int, t_next, t_pos, t_next, t_next, t_print);
void forwardIterator(void*, size_t, int, t_next begin, t_pos end, t_next next, t_next prev, t_print print);
void reverseIterator(void*, size_t, int, t_next begin, t_pos end, t_next next, t_next prev, t_print print);
void* begin(void*);

/* Funciones callback */
/*-----------Int---------*/
void* endInt(void*, int);
void* nextInt(void*);
void* prevInt(void*);
void printInt(void*);
/*----------Libro--------*/
void* endLibro(void*, int);
void* nextLibro(void*);
void* prevLibro(void*);
void printLibro(void*);

int main(int argc, const char * argv[]) {
	int s=0;
	int maxArray;
	int nOpc=3;
    int opcion=0;
	char *Titulos[]={"1974 - Carrie","1975 - El misterio de Salem's Lot (Salem's Lot)","1977 - El resplandor (The Shining)","1977 - Rabia (Rage), como Richard Bachman","1978 - La danza de la muerte (The Stand)","1979 - La larga marcha (The Long Walk), como Richard Bachman","1979 - La zona muerta (The Dead Zone)","1980 - Ojos de fuego (Firestarter)","1981 - Carretera maldita (Roadwork), como Richard Bachman","1981 - Cujo","1982 - El fugitivo (The Running Man), como Richard Bachman","1982 - La Torre Oscura I: La hierba del diablo (The Gunslinger) (Reeditado en 2003 como El pistolero)","1983 - Christine","1983 - Cementerio de animales (Pet Sematary)","1983 - El ciclo del hombre lobo (Cycle of the Werewolf)","1984 - El talismán (The Talisman), con Peter Straub","1984 - Los ojos del dragón (The Eyes of the Dragon)","1984 - Maleficio (Thinner), como Richard Bachman","1986 - Eso (It)","1987 - La Torre Oscura II: La invocación (The Drawing of the Three) (Reeditado en 2003 como La llegada de los tres)","1987 - Misery","1987 - Los Tommyknockers (The Tommyknockers)","1989 - La mitad oscura (The Dark Half)","1990 - Apocalipsis (1990) (The Stand: The Complete & Uncut Edition), versión sin cortes de La danza de la muerte.","1991 - La Torre Oscura III: Las Tierras Baldías (The Wastelands)","1991 - La tienda (Needful Things)","1992 - El juego de Gerald (Gerald's Game)","1993 - Dolores Claiborne","1994 - Insomnia","1995 - El retrato de Rose Madder (Rose Madder)","1996 - La milla verde (The Green Mile) (Publicada originalmente en seis entregas periódicas; en España, con el título de El pasillo de la muerte)","1996 - Desesperación (Desperation)","1996 - Posesión (The Regulators), como Richard Bachman","1997 - La Torre Oscura IV: La bola de cristal (Wizard and Glass) (Reeditado como Mago y Cristal)","1998 - Un saco de huesos (Bag of bones)","2000 - La chica que amaba a Tom Gordon (The girl who loved Tom Gordon)","2001 - El cazador de sueños (Dreamcatcher)","2001 - Casa Negra (Black House, con Peter Straub)","2002 - Buick 8: un coche perverso (From a Buick 8)","2003 - La Torre Oscura V: Lobos del Calla (Wolves of the Calla)","2004 - La Torre Oscura VI: Canción de Susannah (Song of Susannah)","2004 - La Torre Oscura VII: La Torre Oscura (The Dark Tower)","2005 - Colorado Kid","2006 - Cell","2006 - La historia de Lisey (Lisey Story)","2007 - Blaze, como Richard Bachman","2008 - Duma Key","2009 - La Cúpula (Under The Dome)","2011 - 22/11/63","2012 - La Torre Oscura: El viento por la cerradura (como parte de la serie de La Torre Oscura, es el octavo libro, pero cronológicamente se ubica entre los volúmenes cuatro y cinco)","2013 - Joyland","2013 - Doctor sueño (Doctor Sleep)","2014 - Mr. Mercedes (primer libro de la trilogía de Bill Hodges)","2014 - Revival","2015 - Quien pierde paga (Finders Keepers) (segundo libro de la trilogía Bill Hodges)","2016 - Fin de guardia (End of Watch) (tercer libro de la trilogía de Bill Hodges)","2017 - La caja de botones de Gwendy (Gwendy's Button Box, con Richard Chizmar)","2017 - Bellas durmientes (Sleeping Beauties, con Owen King)","2018 - El visitante (The Outsider)","2018 - Elevación (Elevation)","2019 - El instituto (The Institute)","2021 - Later"};
	printf("Tamaño del array\n");
	scanf("%d", &maxArray);
	int* arreglo = (int*) malloc(maxArray * sizeof(int));
	
	Libro* libros;
    libros = (Libro*)malloc(maxArray* sizeof(Libro));
	
	opciones* menu = (opciones*) malloc(nOpc* sizeof(opciones));
    *menu = Recorre;
    *(menu+1) = Recorre;
    *(menu+2) = Recorre;

    for (int *p= arreglo; *p <maxArray; p++){
        *p = rand() % 1000+101;
		(libros+s)->paginas=*p;
		int l = rand() % 61;
		(libros+s)->titulo=Titulos[l];
		s++;
	}

 while (opcion!=4){
        printf("\n---Iteradores--- \
        \n1-Forward Iterator \
        \n2-Reverse Iterator \
        \n3-Bidirectional Iterator \
        \n4-Salir \
        \nElige tu Opción: ");
        scanf("%d", &opcion);
        if(opcion > 0 && opcion <4){
			if(opcion==1){
				printf("\nForward en Int\n");
				Recorre(&forwardIterator,arreglo,sizeof(int), maxArray, begin, endInt, nextInt, prevInt, printInt);
				printf("\n");
				printf("\nForward en Libro\n");
				Recorre(&forwardIterator,libros,sizeof(int), maxArray, begin, endLibro, nextLibro, prevLibro, printLibro);
				printf("\n");
			}
			else if(opcion==2){
				printf("\nReverse en Int\n");
				Recorre(&reverseIterator,arreglo,sizeof(int), maxArray, begin, endInt, nextInt, prevInt, printInt);
				printf("\n");
				printf("\nRevers en Libro\n");
				Recorre(&reverseIterator,libros,sizeof(int), maxArray, begin, endLibro, nextLibro, prevLibro, printLibro);
				printf("\n");
			}
			else if(opcion==3){
				printf("\nBidirectional en Int\n");
				Recorre(&forwardIterator,arreglo,sizeof(int), maxArray, begin, endInt, nextInt, prevInt, printInt);
				Recorre(&reverseIterator,arreglo,sizeof(int), maxArray, begin, endInt, nextInt, prevInt, printInt);
				printf("\n");
				printf("\nBidirectional en Libro\n");
				Recorre(&forwardIterator,libros,sizeof(int), maxArray, begin, endLibro, nextLibro, prevLibro, printLibro);
				Recorre(&reverseIterator,libros,sizeof(int), maxArray, begin, endLibro, nextLibro, prevLibro, printLibro);
				printf("\n");
			}
			
        (*(menu+opcion-1));   
        }
    }
    
	free(arreglo);
	arreglo=NULL;
	free(libros);
	libros=NULL;
	
}

void Recorre(t_sort iterator, void * p, size_t size, int total, t_next begin, t_pos end, t_next next, t_next prev, t_print print)
{
    (*iterator)(p, size, total, begin, end, next, prev, print);
}

void forwardIterator(void* a, size_t size, int total, t_next begin, t_pos end, t_next next, t_next prev, t_print print) 
{
	void* inicio = begin(a);
	void* fin = end(a, total);
	while (inicio <= fin) {
		print(inicio);
		inicio = next(inicio);
	} 
}

void reverseIterator(void* a, size_t size, int total, t_next begin, t_pos end, t_next next, t_next prev, t_print print)
{
	void* inicio = end(a, total);
	void* fin = begin(a);
	while (inicio >= fin) {
		print(inicio);
		inicio = prev(inicio);
	} 
}

void* begin(void* p) 
{
	return p;
}

void* endInt(void* p, int total) 
{
	return (int*) p + total - 1;
}

void* nextInt(void* p) 
{
	return (int*) p + 1;
}

void* prevInt(void* p) 
{
	return (int*) p - 1;
}

void* endLibro(void* p, int total) 
{
	return (Libro*) p + total - 1;
}

void* nextLibro(void* p) 
{
	return (Libro*) p + 1;
}

void* prevLibro(void* p) 
{
	return (Libro*) p - 1;
}

void printInt(void* p) 
{
	printf("%d ", *(int*) p);
}

void printLibro(void* p) 
{
	printf("%d Páginas - Titulo %s\n", ((Libro*) p)->paginas, ((Libro*) p)->titulo);
}
