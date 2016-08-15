#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


double Shell_Insertion_Sort_Seq1(long Array[], int Size, double N_Comp, double N_Move, char*Seqfilename);
double Shell_Insertion_Sort_Seq2(long Array[], int Size, double N_Comp, double N_Move, char*Seqfilename);
double Shell_Bubble_Sort_Seq1(long Array[], int Size, double N_Comp, double N_Move, char*Seqfilename);
double Shell_Bubble_Sort_Seq2(long Array[], int Size, double N_Comp, double N_Move, char*Seqfilename);

long *Load_File(char *Filename, int *Size);

void Save_File(char *Filename, long *Array, int Size);

int main(int argc, char*argv[])
{

	clock_t start_cl, end_cl;
	double diff_cl;

	start_cl = clock();
	int size;
	long *array;

	array = Load_File(argv[3], &size);
        if(array == NULL){free(array);
		return EXIT_FAILURE;
        }
	/*
	   FILE *ptr;
	   int size;
	   ptr = fopen(argv[3], "r");
	   if(ptr == NULL){
	   return EXIT_FAILURE;
	   }

	   char str[12];
	   fgets(str,11,ptr);


	   size = atoi(str);

	   long array[size+1];
	   int i = 0;

	   while(fgets(str,12,ptr)){

	   array[i] = atol(str); 
	   i++;
	   } 

	   fclose(ptr); 
	   */
	// printf("first number %ld\n",array[1]);
	double N_Comp = 0;
	double N_Move = 0;
	double rettime;
	if(argc == 6){
		if((strcmp("1", argv[1]) == 0) && (strcmp("i", argv[2]) == 0)){ //printf("Here1");
			rettime = Shell_Insertion_Sort_Seq1(array, size, N_Comp, N_Move, argv[4]);}
		else if ((strcmp("2", argv[1]) == 0) && (strcmp("i", argv[2]) == 0)){//printf("Here2");
			rettime = Shell_Insertion_Sort_Seq2(array, size, N_Comp, N_Move, argv[4]);}
		else if((strcmp("1", argv[1]) == 0) && (strcmp("b", argv[2]) == 0)){//printf("Here3");
			rettime = Shell_Bubble_Sort_Seq1(array, size, N_Comp, N_Move, argv[4]);}
		else if((strcmp("2", argv[1]) == 0) && (strcmp("b", argv[2]) == 0)){//printf("Here4");
			rettime = Shell_Bubble_Sort_Seq2(array, size, N_Comp, N_Move, argv[4]);}
		else{
			 free(array);
                         return EXIT_FAILURE;}
                         
		Save_File(argv[5], array, size);
		end_cl = clock();

		diff_cl = (double)(end_cl - start_cl)/ CLOCKS_PER_SEC;

		printf("I/O time [sec]: %le\n",diff_cl-rettime); 
		printf("Sorting time [sec]: %le\n\n",rettime); 

		free(array);
		return EXIT_SUCCESS;
	}
	else 
		return EXIT_FAILURE;

}
