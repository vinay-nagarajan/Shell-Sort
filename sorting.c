#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

long h(long i){
	if(i == 1)
		return 1;
	else{
		return ((2*(h(i-1))) + 1);
	}
}
double Shell_Insertion_Sort_Seq1(long Array[], int Size, double N_Comp, double N_Move, char*Seqfilename)
{
	clock_t start_cl, end_cl;
	double diff_cl;

	int x = 1;
	long k;
	while(Size >= h(x)){
		x++;
	}

	FILE *dptr;
	dptr = fopen(Seqfilename,"w");
	int t = 0;
	for(t = 1;t<=x;t++)
		fprintf(dptr,"%ld\n",h(t));
	fclose(dptr);

	long passes = x-1;
	long pass;
	long temp;
	int i,j;
	
	start_cl = clock();
	for(pass = 1;pass<=passes;pass++){
		//  printf("%ld\n",Size);
		k = h(x-pass);

		
		for (j = k;j<=Size-1;j+=k){
			temp = Array[j];
			N_Move++;
			// printf(" temp value %ld ",temp);
			i = j;
			//printf(" i value %d ",i);
			while((i>= k) && (Array[i-k]> temp)){N_Comp++;
				//     printf("Swap performed between %ld, %ld   ",Array[i], Array[i-k]);
				Array[i] = Array[i-k];N_Move++;

				i = i-k;
				//printf("New value of i %d  ",i);
				Array[i] = temp;N_Move++;

			} //printf("\n");
		}
	}
	end_cl = clock();

	diff_cl = (double)(end_cl - start_cl)/ CLOCKS_PER_SEC;

	printf("\nNumber of comparisons: %le\n",N_Comp);
	printf("Number of moves: %le\n",N_Move);


	
	return diff_cl;
}
double Shell_Bubble_Sort_Seq1(long *Array, int Size, double N_Comp, double N_Move, char*Seqfilename)
{
	int x = 1;
	long k;
	while(Size >= h(x)){
		x++;
	}
	clock_t start_cl, end_cl;
	double diff_cl;

	FILE *dptr;
	dptr = fopen(Seqfilename,"w");
	int t = 0;
	for(t = 1;t<=x;t++)
		fprintf(dptr,"%ld\n",h(t));
	fclose(dptr);

	long passes = x-1;
	long pass;
	long temp;
	int j,m;
	start_cl = clock();
	for(pass = 1;pass<=passes;pass++){
		//  printf("%ld\n",Size);
		k = h(x-pass);
		// printf("K value %ld ",k);
		for (j = k;j<=Size;j+=k)
			for(m = j+k;m<=Size;m+=k)
				if(Array[j-1] > Array[m-1]){N_Comp++;
					temp = Array[m-1];N_Move++;
					Array[m-1] = Array[j-1];N_Move++;
					Array[j-1] = temp;N_Move++;
				}// swapping done

	} 
	end_cl = clock();

	diff_cl = (double)(end_cl - start_cl)/ CLOCKS_PER_SEC;

	printf("\nNumber of comparisons: %le\n",N_Comp);
	printf("Number of moves: %le\n",N_Move);


	return diff_cl;
}

long seq2(int i)
{ 
	if(i == 1)
		return 3;
	else
		return 3*(seq2(i-1));
}

long powervalue(int num, int pow)
{
	if(pow == 0)
		return 1;
	else if(pow == 1)
		return num;
	else
		return num*(powervalue(num,pow-1));
}

double Shell_Insertion_Sort_Seq2(long *Array, int Size, double N_Comp, double N_Move, char*Seqfilename)
{
	clock_t start_cl, end_cl;
	double diff_cl;

	int x = 0;
	long k;
	//printf("size %d\n", Size);
	do
	{ 
		x++;
	}while(seq2(x+1) < Size);

	int s;
	int seq2size = 0;

	for(s = x+1;s>=0;s--)
		seq2size+=s;

	int p,q,i;
	int count = 0;
	long seq2array[seq2size];
	//printf("power value of 3 ^ 0 %d\n",powervalue(3,0));

	for(i = 0;i<=(x);i++)
		for(p = i,q = 0;q<=i;q++,p--)
		{seq2array[count] = powervalue(2,p)*powervalue(3,q); count++;}

	FILE *dptr;
	dptr = fopen(Seqfilename,"w");

	for(i = 0;i<seq2size;i++)
		fprintf(dptr,"%ld\n",seq2array[i]);
	//printf(" value of count %d\n",count);
	fclose(dptr);

	int passes = count;
	int pass;
	long temp;
	int j;

	start_cl = clock();
	for(pass = 1;pass<=passes;pass++){
		k = seq2array[count-pass];
		// printf("K value %ld ",k);
		for (j = k;j<=Size-1;j+=k){
			temp = Array[j];N_Move++;
			// printf(" temp value %ld ",temp);
			i = j;
			//printf(" i value %d ",i);
			while((i>= k) && (Array[i-k]> temp)){N_Comp++;
				//     printf("Swap performed between %ld, %ld   ",Array[i], Array[i-k]);
				Array[i] = Array[i-k];N_Move++;

				i = i-k;
				//printf("New value of i %d  ",i);
				Array[i] = temp;N_Move++;

			} //printf("\n");
		}
	}
	end_cl = clock();

	diff_cl = (double)(end_cl - start_cl)/ CLOCKS_PER_SEC;

	printf("\nNumber of comparisons: %le\n",N_Comp);
	printf("Number of moves: %le\n",N_Move);


	return diff_cl;
}

double Shell_Bubble_Sort_Seq2(long *Array, int Size, double N_Comp, double N_Move, char*Seqfilename)
{
	clock_t start_cl, end_cl;
	double diff_cl;

	int x = 0;
	long k;
	//printf("size %d\n", Size);
	do
	{ 
		x++;
	}while(seq2(x+1) < Size);

	int s;
	int seq2size = 0;

	for(s = x+1;s>=0;s--)
		seq2size+=s;

	int p,q,i;
	int count = 0;
	long seq2array[seq2size];
	//printf("power value of 3 ^ 0 %d\n",powervalue(3,0));

	for(i = 0;i<=(x);i++)
		for(p = i,q = 0;q<=i;q++,p--)
		{seq2array[count] = powervalue(2,p)*powervalue(3,q); count++;}

	FILE *dptr;
	dptr = fopen(Seqfilename,"w");

	for(i = 0;i<seq2size;i++)
		fprintf(dptr,"%ld\n",seq2array[i]);
	//printf(" value of count %d\n",count);
	fclose(dptr);

	int passes = count;
	int pass;
	long temp;
	int j,m;

	start_cl = clock();
	for(pass = 1;pass<=passes;pass++){
		k = seq2array[count-pass]; 
		for (j = k;j<=Size;j+=k)
			for(m = j+k;m<=Size;m+=k)
				if(Array[j-1] > Array[m-1]){
					N_Comp++;
					temp = Array[m-1];N_Move++;
					Array[m-1] = Array[j-1];N_Move++;
					Array[j-1] = temp;N_Move++;
				}

	}
	end_cl = clock();

	diff_cl = (double)(end_cl - start_cl)/ CLOCKS_PER_SEC;
	// printf("Number of comparisons: %lf\n",*N_Comp);
	//  printf("Number of moves: %lf\n",N_Move);
	printf("\nNumber of comparisons: %le\n",N_Comp);
	printf("Number of moves: %le\n",N_Move);



	return diff_cl;
}

long *Load_File(char *Filename, int *size)
{
	FILE *ptr;


	ptr = fopen(Filename, "r");
	if(ptr == NULL){
		return NULL;
	}

	char str[12];
	fgets(str,11,ptr);


	*size = atoi(str);

	long *array = malloc(sizeof(long)*((*size)+1));
	int i = 0;

	while(fgets(str,12,ptr)){

		array[i] = atol(str); 
		i++;

	}  
	fclose(ptr); 
	return array;
}


void Save_File(char *Filename, long *Array, int Size)
{
	FILE *fptr;
	fptr = fopen(Filename, "w");
	int i = 0;
	while(i<Size){
		fprintf(fptr,"%ld\n",Array[i]);
		i++;
	} 
	fclose(fptr);
}


