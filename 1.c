#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Day
{
	char *name;
	int date;
	char *description;
};
struct Day* create() // it creates calendar structure for 7 days 
{
	struct Day *calendar;
	// dynamic allocation for calendar
	calendar = (struct Day*)malloc(sizeof(struct Day)*7);
	return calendar;
}
void read(struct Day *calendar)
{
	// Local Variable to store string elements 
	char name[10];
	char description[25];
	int i, date;
	for(i = 0; i<7; i++)
	{
		printf("Enter the day name : ");
		scanf("%s",name);
		calendar[i].name = (char *)malloc(strlen(name)+1); // dynamically allocated memory for day name
		strcpy(calendar[i].name, name); // copy name from local variable to heap 
		printf("Enter the date : ");
		scanf("%d",&date);
		calendar[i].date = date;
		getchar();
		printf("Enter description of the activity : "); 
		scanf("%[^\n]s",description);
		// dynamically allocate memory for activity description 
		calendar[i].description = (char *)malloc(strlen(description)+1); 
		strcpy(calendar[i].description, description); // copy activity from local variable to heap 
	}
}
void display(struct Day *calendar)
{
	int i;
	printf("\n\nYour calendar\n");
	printf("Weekly Activity Details:\n");
	//Display the calendar 
	for(i = 0; i<7; i++)
	{
		printf("Day %d: Name: %s, Date: %d, Description: %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].description);
	}
}
void main()
{
	struct Day *calendar; // create structure variable of type pointer 
	calendar=create(); //call create function 
	read(calendar); // read function to read all inputs 
	display(calendar); // Function to print calendar 
	free(calendar); // Release the memory allocated dynamically 
}
