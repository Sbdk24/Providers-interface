#include <stdio.h>
#define MAX_PROV 5
#define MAX_LENGTH 40

int main(void)
{
   //user interface
    printf("\n");
    printf("These are the products on sale in our company\n");
    printf("_____________________________________________\n\n");
    printf("        Laptops             Smartphones      \n");

    int choice;
    char names_provider[MAX_PROV][MAX_LENGTH], location_provider[MAX_PROV][MAX_LENGTH];
    char new_provider[MAX_LENGTH];
    int prod_items[MAX_PROV][2];
    int counter_prov = 0, provider_length, j = 0, num, exit;

    do
    {   
        printf("_____________________________________________\n\n");
        printf("            PROVIDERS MANAGEMENT             \n\n");
        printf("Menu:\n 1. Add provider \n 2. Delete provider \n 3. Print provider \n\n");
        printf("Please, enter the option you want to select \n");
        printf("If work is done, please prompt 0 to exit: \n");
        //Check if the choice could be selected
        do
        {
            scanf("%i", &choice);
                if (choice < 0 || choice > 3)
            {
                printf("The number you chose is not between the options on the menu\n");
                printf("Please, enter the option again: ");
            }
        } while (choice < 0 || choice > 3);
        
        
        switch (choice) //The program starts here
        {
            //add provider
            case 1: 
                                            /* 1. Provider's name*/
                j = 0;
                printf("Prompt the name of our new provider (Just one word): ");
                //shield for strings
                do
                {
                    scanf("%s", new_provider);
                    for (provider_length = 0; new_provider[provider_length] != '\0'; provider_length++);

                    if (provider_length > 40)
                    {
                        printf("Name must've to contain a maximum of 40 characters.\n");
                        printf("please prompt it again: ");
                    }
                } while(provider_length > 40);
                
                for(int i = 0; i < provider_length + 1; i++) //adding to names_array
                    names_provider[counter_prov][i] = new_provider[i];
               
                                            /* 2. Providers location*/
                printf("Prompt the city our new provider is located (Just one word): ");
                //shield for strings
                do
                {
                    scanf("%s", new_provider);
                    for (provider_length = 0; new_provider[provider_length] != '\0'; provider_length++);

                    if (provider_length > 40)
                    {
                        printf("City must've to contain a maximum of 40 characters.\n");
                        printf("please prompt it again: ");
                    }
                } while(provider_length > 40);
                
                for(int i = 0; i < provider_length + 1; i++) //adding to locations array
                    location_provider[counter_prov][i] = new_provider[i];
                                            /*3. Product & items sold */
                printf("What does he/she sells?: \n");
                printf("Laptops = 1\tSmartphones = 2\n");
                //shield for user options
                do
                {
                    scanf("%i", &prod_items[counter_prov][j]);

                    if (prod_items[counter_prov][j] != 1 && prod_items[counter_prov][j] != 2) 
                    {
                        printf("The number selected is not found in our options\n");
                        printf("Please, prompt it again: ");
                    }
                } while (prod_items[counter_prov][j] != 1 && prod_items[counter_prov][j] != 2);
                
                printf("How many products has he/she sold?: ");
                scanf("%i", &prod_items[counter_prov][j+1]);
                
                counter_prov++;                
                j++;
                break;

            //Delete a provider    
            case 2:
                char delet_array[MAX_LENGTH] = {"---------------------------------------"};
                do
                {
                                                /*1.Check if there're providers registered */
                    if(counter_prov == 0)
                    {
                        printf("There's no providers registered yet.\n");
                        printf("Please, add at least one provider to continue\n");
                        break;
                    }
                                                /*2. Check if the provider exists*/
                    printf("Which provider would you like to delete?: ");
                    do
                    {
                        scanf("%i", &num);
                        if ((num < 1) || (num > counter_prov))
                        {
                            printf("Sorry, but this provider isn't registered yet or the number is not between the options.\n");
                            printf("Please, prompt it again. (Total of providers registered: %i)\n", counter_prov);
                        }
                    } while ((num < 1) || (num > counter_prov));

                                                /*3. Deleting */
                    //Delete provider's name
                    for (provider_length = 0; names_provider[num-1][provider_length] != '\0'; provider_length++);  /*How many '-' it has to rewirte*/

                    for (int i = 0; i < provider_length; i++)
                        names_provider[num-1][i] = delet_array[i];

                    //Delete provider's city                
                    for (provider_length = 0; location_provider[num-1][provider_length] != '\0'; provider_length++);

                    for (int i = 0; i < provider_length; i++)
                        location_provider[num-1][i] = delet_array[i];

                    //Delete provider's product & number of items sold
                    prod_items[num-1][0] = 0;
                    prod_items[num-1][1] = -1;

                    printf("Elimination has been done succesfully.\n");
                    printf("Would you like to delete another provider? \n");
                    printf("Press any number.\n");
                    printf("Go back: 0\n");
                    scanf("%i", &exit);
                } while (exit != 0);
                break;  
            //Print providers in window
            case 3:
                do
                {                               /*1.Check if there're providers registered */
                    if(counter_prov == 0)
                    {
                        printf("There's no providers registered yet.\n");
                        printf("Please, add at least one provider to continue\n");
                        break;
                    }
                                                /*2. Check if the provider exists*/
                    printf("Which provider would you like to review?: ");
                    do
                    {
                        scanf("%i", &num);
                        if ((num < 1) || (num > counter_prov))
                        {
                            printf("Sorry, but this provider isn't registered yet or the number is not between the options.\n");
                            printf("Please, prompt it again. (Total of providers registered: %i)\n", counter_prov);
                        }
                    } while ((num < 1) || (num > counter_prov));
                    
                                                /*3. Printing in terminal window*/
                    printf("%s\n", names_provider[num-1]);
                    printf("%s\n", location_provider[num-1]);
                    
                    //Indicate which product the provider sells
                    if (prod_items[num-1][0] == 1)
                        printf("Laptops       ");
                    else if (prod_items[num-1][0] == 2)
                        printf("Smartphones   ");
                    else
                        printf("-----\n");
                    //number of items sold
                    if (prod_items[num-1][1] == -1)
                        printf("-----\n");
                    else
                        printf("%i\n", prod_items[num-1][1]);

                    printf("Would you like to review another provider? \n");
                    printf("Press any number.\n");
                    printf("Go back: 0\n");
                    scanf("%i", &exit);
                } while(exit != 0);                     
                break;

            default:
                break;          
        }

    }while (choice != 0);
    return 0;
    
}