#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)
//define Book prices
#define A 69.00
#define B 70.00
#define C 55.50
#define D 26.37
#define E 44.50
#define F 67.00
#define G 75.00
#define H 60.00
#define I 83.00

void logoHeading()
{
	printf("==\t==   ==      ==   ==========\t\t\t_______________/\n");
	printf("==\t==   ====  ====       ==    \t\t______________________/\n");
	printf("==\t==   ==  ==  ==       ==    \t_____________________________/\n");
	printf(" ========    ==  ==  ==       ==   _________________________________/\n");
	printf("\n\t\t\t   <WELCOME TO UMT POS SYSTEM>\n");
	printf("\t\t\t    [Please Select An Option]\n");
}
	void menu() //This function is for viewing the first 3 option 
	{
		int viewMenu = 0, fieldView = 0;
		while (viewMenu != 3)
		{
			viewMenu = 0;
			fieldView = 0;
			do
			{
				printf("\t\t    ___________________________________________ \n\t\t    |1= View Menu, 2= Select Order, 3= Exit > "); //if press something other than 1,2,3 display invalid input
				scanf_s("%d", &viewMenu);
				switch (viewMenu)
				{
				case 1: //field menu
					do {
						printf("\n\t\t\t    ===========================================\n\t\t\t    | Select a field to view:\t\t      |\n\t\t\t    ===========================================\n\t\t\t    1 = Software Development Programming\n\t\t\t    2 = Web Programming\n\t\t\t    3 = Video Game Design\n\tInput: ");
						scanf_s("%d", &fieldView);

						switch (fieldView)
						{
						case 1:
							printf("\t\t\t    Software Development Programming Books:\n\t\t\t   ******************************************************\n\t\t\t    A= Programming Concept and Design\t\t RM69.00\n");
							printf("\t\t\t    B= Visual Studio Guide Book \t\t RM70.00\n\t\t\t    C= Python Programming \t\t\t RM55.50\n\t\t\t   ******************************************************\n\n");
							break;
						case 2:
							printf("\t\t\t    Web programming:\n\t\t\t   ******************************************************\n\t\t\t    D= Sams Teach youselfs \t\t\t RM26.37\n");
							printf("\t\t\t    E= HTML & CSS QuickStart Guide \t\t RM44.50\n\t\t\t    F= Java Scripts Fundementals \t\t RM67.00\n\t\t\t   ******************************************************\n\n");
							break;
						case 3:
							printf("\t\t\t    Video game design:\n\t\t\t   ******************************************************\n\t\t\t    G= Fundementals of Video Games design \t RM75.00\n");
							printf("\t\t\t    H= Basics for Unity & #C \t\t\t RM60.00\n\t\t\t    I= The Art Of Game Design \t\t\t RM83.00\n\t\t\t   ******************************************************\n\n");
							break;
						default:
							printf("\n\n\t\t    Invalid Input\n");
							rewind(stdin);
							break;
						}
					} while (fieldView < 1 || fieldView > 3);
					break;
				case 2: //case 2 calls selectOrder function to ordering books
					selectOrder();
					break;
				case 3://end the program
					printf("\n\t\t\t\tGoodbye :)\n");
					exit();
				default:
					printf("\n\n\t\t\t    Invalid Input\n");
					rewind(stdin);
				}
			} while (viewMenu <= 0 || viewMenu > 3);
		}
	}
	int selectOrder()
	{
		int  x, order = 1, qtyBook[9] = { 0 } /*qtyBook is for storing daily summary of the books ordered*/, finalqtySold = 0; //total quantity of book sold for daily summary
		double totalbook[9] = { 0 }/*total price for each book type for daily summary*/, price = 0, total = 0, discount = 0, finalSold = 0; //total price of book sold for daily summary
		char yesno, selectbook, yesno2;
		do
		{
			int orderbook = 0, quantity = 0; 
			printf("\nSales Order No :%d\n\n", order);
			do
			{
				printf("Amount of book type wants to order > "); //how many type of books the user wants to buy
				scanf("%d", &orderbook);
				if (orderbook <= 0 || orderbook >= 10)
					printf("\nInvalid Input (There are only 9 book type available)\n");
					rewind(stdin);
			} while (orderbook < 1 || orderbook > 9);

			int receipttotal[9] = { 0 };//use for printing out quantity of book ordered per book type for receipt 
			double receiptbook[9] = { 0 } /*use for printing out total price per book for receipt*/, totalbooks = 0, subtotal = 0;
			for (x = 1; x <= orderbook; ++x)
			{
				do {
					rewind(stdin);
					printf("\nBook A, B, C, D, E, F, G, H, I (X=Exit):  ");
					scanf("%c", &selectbook);
					selectbook = toupper(selectbook);
					if (selectbook != 'A' && selectbook != 'B' && selectbook != 'C' && selectbook != 'D' && selectbook != 'E' && selectbook != 'F' && selectbook != 'G' && selectbook != 'H' && selectbook != 'I' && selectbook != 'X')//for validating input
						printf("Invalid Input\n");
				} while (selectbook != 'A' && selectbook != 'B' && selectbook != 'C' && selectbook != 'D' && selectbook != 'E' && selectbook != 'F' && selectbook != 'G' && selectbook != 'H' && selectbook != 'I' && selectbook != 'X');
				if (selectbook == 'X')
					return total;
				do {
					printf("Quantity > ");
					scanf("%d", &quantity);
					if (quantity < 1)
					{
						printf("\nInvalid Input\n");
						quantity = 0;
						rewind(stdin);
					}
				} while (quantity < 1);
				switch (selectbook)
				{
				case 'A':
					price = A;
					qtyBook[0] += quantity;
					receipttotal[0] =+ quantity;
					totalbook[0] = totalbook[0] + (price * quantity);
					receiptbook[0] = (price * quantity);
					break;
				case 'B':
					price = B;
					qtyBook[1] += quantity;
					receipttotal[1] =+ quantity;
					totalbook[1] = totalbook[1] + (price * quantity);
					receiptbook[1] = (price * quantity);
					break;
				case 'C':
					price = C;
					qtyBook[2] += quantity;
					receipttotal[2] =+ quantity;
					totalbook[2] = totalbook[2] + (price * quantity);
					receiptbook[2] = (price * quantity);
					break;
				case 'D':
					price = D;
					qtyBook[3] += quantity;
					receipttotal[3] =+ quantity;
					totalbook[3] = totalbook[3] + (price * quantity);
					receiptbook[3] = (price * quantity);
					break;
				case 'E':
					price = E;
					qtyBook[4] += quantity;
					receipttotal[4] =+ quantity;
					totalbook[4] = totalbook[4] + (price * quantity);
					receiptbook[4] = (price * quantity);
					break;
				case 'F':
					price = F;
					qtyBook[5] += quantity;
					receipttotal[5] =+ quantity;
					totalbook[5] = totalbook[5] + (price * quantity);
					receiptbook[5] = (price * quantity);
					break;
				case 'G':
					price = G;
					qtyBook[6] += quantity;
					receipttotal[6] =+ quantity;
					totalbook[6] = totalbook[6] + (price * quantity);
					receiptbook[6] = (price * quantity);
					break;
				case 'H':
					price = H;
					qtyBook[7] += quantity;
					receipttotal[7] =+ quantity;
					totalbook[7] = totalbook[7] + (price * quantity);
					receiptbook[7] = (price * quantity);
					break;
				case 'I':
					price = I;
					qtyBook[8] += quantity;
					receipttotal[8] = +quantity;
					totalbook[8] = totalbook[8] + (price * quantity);
					receiptbook[8] = (price * quantity);
					break;
				}//everything up there loop depends on the amount of type of books user wants to order
				totalbooks = (double)price * quantity;
				subtotal = (double)subtotal + totalbooks;//everything sum together
				quantity = 0;
			}
			do {
				rewind(stdin);
				printf("Confirm the order? (Y= Yes, N= No) > "); //comfirm order to print out receipt, if not return to menu
				scanf("%c", &yesno);
				yesno = toupper(yesno);
				switch (yesno)
				{
				case 'Y':
					printf("\n\t\t\t    ##======================================##\n\t\t\t    || \t\t UMT Pos System \t    ||\n\t\t\t    ##======================================##");
					if (receipttotal[0] != 0)
						printf("\n\t\t\t    || Book A: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[0], price = A, receiptbook[0]);
					if (receipttotal[1] != 0)
						printf("\n\t\t\t    || Book B: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[1], price = B, receiptbook[1]);
					if (receipttotal[2] != 0)
						printf("\n\t\t\t    || Book C: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[2], price = C, receiptbook[2]);
					if (receipttotal[3] != 0)
						printf("\n\t\t\t    || Book D: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[3], price = D, receiptbook[3]);
					if (receipttotal[4] != 0)
						printf("\n\t\t\t    || Book E: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[4], price = E, receiptbook[4]);
					if (receipttotal[5] != 0)
						printf("\n\t\t\t    || Book F: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[5], price = F, receiptbook[5]);
					if (receipttotal[6] != 0)
						printf("\n\t\t\t    || Book G: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[6], price = G, receiptbook[6]);
					if (receipttotal[7] != 0)
						printf("\n\t\t\t    || Book H: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[7], price = H, receiptbook[7]);
					if (receipttotal[8] != 0)
						printf("\n\t\t\t    || Book I: %d @ RM%.2f \t> RM%7.2f ||", receipttotal[8], price = I, receiptbook[8]);

					printf("\n\t\t\t    || Subtotal \t\t> RM%7.2f ||", subtotal);
					if (subtotal > 500)
					{
						discount = subtotal * 0.15;
					}
					else if (subtotal > 300)
					{
						discount = subtotal * 0.1;
					}
					else if (subtotal > 200)
					{
						discount = subtotal * 0.05;
					}
					else if (subtotal < 200)
					{
						discount = 0.00;
					}
					total = subtotal - discount;
					printf("\n\t\t\t    || Discount \t\t> RM%7.2f ||\n\t\t\t    ||======================================||\n\t\t\t    || Total    \t\t> RM%7.2f ||\n\t\t\t    ##======================================##", discount, total);
					printf("\n\t\t\t       >_< THANK YOU HAVE A NICE DAY! ! uwu\t\n\n");
					finalqtySold = qtyBook[0] + qtyBook[1] + qtyBook[2] + qtyBook[3] + qtyBook[4] + qtyBook[5] + qtyBook[6] + qtyBook[7] + qtyBook[8];
					finalSold = totalbook[0] + totalbook[1] + totalbook[2] + totalbook[3] + totalbook[4] + totalbook[5] + totalbook[6] + totalbook[7] + totalbook[8];
					break;
				case 'N': //substract the all the book ordered in this order from the daily summary report
					totalbook[0] -= receiptbook[0];
					totalbook[1] -= receiptbook[1];
					totalbook[2] -= receiptbook[2];
					totalbook[3] -= receiptbook[3];
					totalbook[4] -= receiptbook[4];
					totalbook[5] -= receiptbook[5];
					totalbook[6] -= receiptbook[6];
					totalbook[7] -= receiptbook[7];
					totalbook[8] -= receiptbook[8];
					qtyBook[0] -= receipttotal[0];
					qtyBook[1] -= receipttotal[1];
					qtyBook[2] -= receipttotal[2];
					qtyBook[3] -= receipttotal[3];
					qtyBook[4] -= receipttotal[4];
					qtyBook[5] -= receipttotal[5];
					qtyBook[6] -= receipttotal[6];
					qtyBook[7] -= receipttotal[7];
					qtyBook[8] -= receipttotal[8];
					--order;
					break;
				default:
					printf("\n\tInvalid Input\n\n");
				}
			} while (yesno != 'Y' && yesno != 'N');
			do {
				rewind(stdin);
				printf("Next Order? (Y= Yes, N= No) > ");
				scanf("%c", &yesno2);
				yesno2 = toupper(yesno2);
				if (yesno2 == 'Y')
					++order;
				else if (yesno2 == 'N')
				{
					printf("\n\t\t\t   ______________________________________________________\n");
					printf("\t\t\t   |\t      DAILY SALES ORDER SUMMARY REPORT\t\t|\n");
					printf("\t\t\t   |\t       Total number of Sales Order = %d\t\t|\n", order);
					printf("\t\t\t   | Book\t Quantity Sold Sales\t\t Amount |\n");
					printf("\t\t\t   | A \t\t %12d \t\t\t %6.2f |\n", qtyBook[0], totalbook[0]);
					printf("\t\t\t   | B \t\t %12d \t\t\t %6.2f |\n", qtyBook[1], totalbook[1]);
					printf("\t\t\t   | C \t\t %12d \t\t\t %6.2f |\n", qtyBook[2], totalbook[2]);
					printf("\t\t\t   | D \t\t %12d \t\t\t %6.2f |\n", qtyBook[3], totalbook[3]);
					printf("\t\t\t   | E \t\t %12d \t\t\t %6.2f |\n", qtyBook[4], totalbook[4]);
					printf("\t\t\t   | F \t\t %12d \t\t\t %6.2f |\n", qtyBook[5], totalbook[5]);
					printf("\t\t\t   | G \t\t %12d \t\t\t %6.2f |\n", qtyBook[6], totalbook[6]);
					printf("\t\t\t   | H \t\t %12d \t\t\t %6.2f |\n", qtyBook[7], totalbook[7]);
					printf("\t\t\t   | I \t\t %12d \t\t\t %6.2f |\n", qtyBook[8], totalbook[8]);
					printf("  \t\t\t   |  \t\t\t =====\t\t\t======= |\n");
					printf("\t\t\t   | TOTAL\t %12d \t\t\t %6.2f |\n", finalqtySold, finalSold);
					printf("\t\t\t   ______________________________________________________\n");
					printf("\n\t\t\t\t\t   <HAVE A NICE DAY !!!>\n");
					exit();
				}
				else
					printf("\n\tInvalid Input\n\n");
			} while (yesno2 != 'Y' && yesno2 != 'N');
		} while (yesno2 == 'Y'); //next order
		
		}
int main()
{
	logoHeading();
	menu(); //the main body for everything
	return 0;
}

