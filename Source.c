#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SALE struct sales_of_products
#define max_product_code 10
#define max_sales 50

SALE
{
	char product_code[max_product_code];
	int year;
	float revenue;
};

void input_from_keyb(SALE* sale, int products)
{
	for (int i = 0; i < products; i++)
	{
		puts("\nEnter the product code: ");
		scanf("%s", &sale[i].product_code);  //можно но лень со знаками ,.\ и тд проверку сделать
		puts("Enter the year of sale: ");
		scanf("%d", &sale[i].year);
		/*if (sale[i].year >= 2024)  //если докопается поч можно ввести 1000000 год
		{
			puts("It has not happened yet. Try again");
			puts("Enter the year of sale: ");
			scanf("%d", &sale[i].year);
		}*/
		puts("Enter the revenue for the products sold: ");
		scanf("%f", &sale[i].revenue);
	}
}
void input_from_file(SALE* sale, int products)
{
	FILE* f1 = fopen("f1.txt", "r");
	if (f1 != NULL)
	{
		for (int i = 0; i < products; i++)
		{
			fscanf(f1, "%s", &sale[i].product_code);
			fscanf(f1, "%d", &sale[i].year);
			fscanf(f1, "%f", &sale[i].revenue);

		}
	}
	else
	{
		puts("No file");
		return -1;
	}
	fclose(f1);
}

void output_to_the_screen(SALE* sale, int products, float sold)
{
	printf("\nSold products with higher revenue than %.2f", sold);
	for (int i = 0; i < products; i++)
	{
		if (sale[i].revenue > sold)
		{
			printf("\nThe %d product", i);
			printf("\nThe product code: %s", sale[i].product_code);
			printf("\nThe year of sale: %d", sale[i].year);
			printf("\nThe revenue of the sold product: %.2f", sale[i].revenue);

		}
		else
		{
			puts("\nNo products with higher revenue");
		}
	}
}

void output_to_a_file(SALE* sale, int products, float sold)
{
	///
}

int main()
{
	int products;
	float sold;
	puts("\nHow many products do you want to enter?");
	scanf("%d", &products);
	printf("You have entered %d products", products);
	SALE sale[max_sales];
	puts("\nEnter the revenue for the sold products you want");
	scanf("%f", &sold);
	printf("\nYou have entered the revenue: %.2f\n", sold);
	int num1, num2;
	puts("\nEnter 1 - input from keyboard; \nEnter 2 - input from a file;");
	scanf("%d", &num1);
	printf("You have chosen: %d", num1);

	switch (num1)
	{
	case 1:
		input_from_keyb(sale, products);
		break;
	case 2:
		for (int i = 0; i < products; i++)
		{
			
			break;
		}
	default:
		puts("wrong number");
		break;
	}
	puts("\nEnter 1 - output to the screen; \nEnter 2 - output to a file;");
	scanf("%d", &num2);
	printf("\nYou have chosen: %d", num2);

	switch (num2)
	{
	case 1:
		output_to_the_screen(sale, products, sold);
		break;
	case 2:
		for (int i = 0; i < products; i++)
		{
			
			break;
		}
	default:
		puts("wrong number");
		break;
	}
	
	
}


