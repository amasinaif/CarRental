#include<stdio.h>
#include<string.h>
#define SIZE 30
#define PHONE_SIZE 12

void searchCustomer(char search[], int type);//it is function

int main() {
    int selection;//variable definition
    char customer_name[SIZE], phone[PHONE_SIZE], id[SIZE], make[SIZE], search[SIZE], model_name[SIZE], model_year[SIZE], plate_num[SIZE], new_id[SIZE];//Define variables
    int repeat = 1;
    FILE* fPtr, * rPtr, * wPtr;
    do {
        printf("Car Rental Application\n\n");
        printf("1-Customer\n");//search number 1
        printf("2-Vehicles \n");//search number 2
        printf("3-Exit\n"); //search number 3
        printf(">>>Please enter your choice:");//Enter you choice
        scanf_s("%d", &selection); // you choice
        switch (selection) {
        case 1:
            printf("\n1-Register -->add new customers\n");//If you choose number 1, the properties of consumers will appear
            printf("2-Search customer \n");//If you choose number 2, the properties of Search customer will appear
            printf("3-Back\n"); //If you choose number 3,It is going to exit of the loop
            printf(">>>Please enter your choice:");//Enter your choice
            scanf_s("%d", &selection);// you choice
            switch (selection)
            {
            case 1:
                fopen_s(&fPtr, "Customer.txt", "w");//Open file
                printf("\nPlease enter customer ID:\n");//Enter customer ID
                scanf_s("%s", id, SIZE - 1);//customer id
                printf("Enter customer name :\n");// Enter customer name 
                scanf_s("%s", customer_name, SIZE - 1);//customer name 
                printf("Enter phone number:\n");//Enter Phone number
                scanf_s("%s", phone, PHONE_SIZE - 1);//Phone number
                fprintf(fPtr, "%s%25s%20s\n", id, customer_name, phone);//print string with writing inside the file

                fclose(fPtr);
                break;
            case 2:
                printf("\n1-Search by ID\n");//choice 1-->Search by ID
                printf("2-Search by Name \n");//choice 2-->Search by Name
                printf("3-Search by phone\n");//choice 3-->Search by phone
                printf("4-Back\n");//choice 4--> you can back to case
                printf(">>>Please enter your choice:");//enter your choice
                scanf_s("%d", &selection);// you choice
                switch (selection)
                {
                case 1:

                    printf("\nPlease enter ID to serach:");
                    scanf_s("%s", &search, SIZE);

                    searchCustomer(search, 1);//function --> calling

                    break;
                case 2:

                    printf("\nPlease enter customer name to serach:");//if your choice number 2-->enter customer name
                    scanf_s("%s", &search, SIZE);//enter customer name
                    searchCustomer(search, 2);//function --> calling
                    break;
                case 3:

                    printf("\nPlease enter phone to serach:");//if your choice number 2-->enter phone 
                    scanf_s("%s", search, SIZE);// enter phone
                    searchCustomer(search, 3);//function --> calling

                    break;
                case 4:
                    break;
                default:
                    break;

                }
                break;
            default:
                break;
            }
            break;

        case 2: //Vehicle section will start if customer enters 2
            printf("\n1- Add a new vehicle\n");
            printf("2- Delete vehicle\n");
            printf("3- Rent a vehicle to a customer\n");
            printf("4- Receive rented vehicle back from customer\n");
            printf("5- Search vehicle\n");
            printf("6- Back\n");
            //promt message for the customer to choose
            printf(">>Enter your selection:");
            scanf_s("%d", &selection);
            //read the customers selection
            switch (selection){//start switch 
            case 1:
                fopen_s(&fPtr, "vehicle.txt", "w");
                //open file to write
                printf("\nEnter model year: \n");
                scanf_s("%s", model_year, SIZE);
                printf("Enter make: \n");
                scanf_s("%s", make, SIZE);
                printf("Enter model name: \n");
                scanf_s("%s", model_name, SIZE);
                printf("Enter plate number: \n");
                scanf_s("%s", plate_num, SIZE);
                printf("Enter customer ID number: \n");
                scanf_s("%s", id, SIZE);
                //collect information from the customer
                fprintf(fPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print the data vehicle in the file 
                fclose(fPtr);//close the file
                break;
            case 2:
                fopen_s(&rPtr, "vehicle.txt", "r");//open vehicle file to read from
                fopen_s(&wPtr, "temp.txt", "w");//open temp file to write on
                printf("\nPlease enter car plate number to delete:");
                scanf_s("%s", search, SIZE);
                //Ask and take car plate number
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from file
                    if (memcmp(plate_num, search, strlen(search))){ 
                        fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);
                    }
                } 
                fclose(rPtr);
                fclose(wPtr);
                //close files
                fopen_s(&wPtr, "vehicle.txt", "w");//open vehicle file to write on
                fopen_s(&rPtr, "temp.txt", "r");//open temp file to read from
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from temp file
                    fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print in vehicle file
                }
                fclose(rPtr);
                fclose(wPtr);
                //close files
                break;
            case 3:
                fopen_s(&rPtr, "vehicle.txt", "r");//open vehicle file to read from
                fopen_s(&wPtr, "temp.txt", "w");//open temp file to write on
                printf("\nPlease enter car plate number :");
                scanf_s("%s", search, SIZE);
                printf("Please enter customer number :");
                scanf_s("%s", new_id, SIZE);
                //collect information from the customer
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from vehicle file
                    if (memcmp(plate_num, search, strlen(search))) {
                        fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print in temp file
                    }
                    else {
                        fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, new_id);//print in temp file
                    }
                }
                fclose(rPtr);
                fclose(wPtr);
                //close files
                fopen_s(&wPtr, "vehicle.txt", "w");//open vehicle file to write on
                fopen_s(&rPtr, "temp.txt", "r");//open temp file to read from
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from temp file
                    fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print in vehicle file
                }
                fclose(rPtr);
                fclose(wPtr);
                //close files
                break;
            case 4:
                fopen_s(&rPtr, "vehicle.txt", "r");//open vehicle file to read from
                fopen_s(&wPtr, "temp.txt", "w");//open temp file to write on
                printf("\nPlease enter car plate number :");
                scanf_s("%s", search, SIZE);
                //Ask and take car plate number
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from vehicle file
                    if (memcmp(plate_num, search, strlen(search))){
                        fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print in temp file
                    }
                    else {
                        fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, "0");//print in temp file
                    }
                }
                fclose(rPtr);
                fclose(wPtr);
                //close files
                fopen_s(&wPtr, "vehicle.txt", "w");//open vehicle file to write on
                fopen_s(&rPtr, "temp.txt", "r");//open temp file to read from
                while (!feof(rPtr)){//enter while loop if we didn't reach the end of the file
                    fscanf_s(rPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from temp file
                    fprintf(wPtr, "%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);//print in vehicle file
                }
                fclose(rPtr);
                fclose(wPtr);
                //close files
                break;
            case 5:
                printf("\n1- Search by Model year + Make + Model name\n");
                printf("2- Search by License plate number \n");
                printf("3- Search for renting vehicle\n");
                printf("4- Back\n");
                printf(">>Enter your choice:");
                scanf_s("%d", &selection);
                switch (selection){//start switch 
                case 1:
                    char model_search[SIZE], make_search[SIZE], model_name_search[SIZE];
                    printf("\nPlease enter Model year , Make and  Model name to serach:");
                    scanf_s("%s", &model_search, SIZE);
                    scanf_s("%s", &make_search, SIZE);
                    scanf_s("%s", &model_name_search, SIZE);
                    fopen_s(&fPtr, "vehicle.txt", "r");//open vehicle file to read from
                    while (!feof(fPtr)){//enter while loop if we didn't reach the end of the file
                        fscanf_s(fPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from file
                        if ((!memcmp(model_year, model_search, strlen(model_search))) && (!memcmp(make, make_search, strlen(make_search))) && (!memcmp(model_name, model_name_search, strlen(model_name_search)))){
                            printf("%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);
                        }
                    }
                    fclose(fPtr);//close file
                    break;
                case 2:
                    printf("\nPlease enter License plate number  to serach:");
                    scanf_s("%s", &search, SIZE);
                    fopen_s(&fPtr, "vehicle.txt", "r");//open vehicle file to read from
                    while (!feof(fPtr)){//enter while loop if we didn't reach the end of the file
                        fscanf_s(fPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from file
                        if ((!memcmp(plate_num, search, strlen(search)))){
                            printf("%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);
                        }
                    }
                    fclose(fPtr);//close file
                    break;
                case 3:
                    fopen_s(&fPtr, "vehicle.txt", "r");//open vehicle file to read from
                    while (!feof(fPtr)){//enter while loop if we didn't reach the end of the file
                        fscanf_s(fPtr, "%s%s%s%s%s\n", model_year, SIZE, make, SIZE, model_name, SIZE, plate_num, SIZE, id, SIZE);//read from file
                        if ((!memcmp(id, "0", strlen("0")))){
                            printf("%s%10s%10s%10s%10s\n", model_year, make, model_name, plate_num, id);
                        }
                    }
                    fclose(fPtr);//close file
                    break;
                case 4:
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    } while (repeat);
}


void searchCustomer(char search[], int type) {
    char id[SIZE], customer_name[SIZE], phone[PHONE_SIZE];//Define variables
    FILE* fPtr;
    fopen_s(&fPtr, "Customer.txt", "r");//open file

    while (!feof(fPtr))//ptr still working until he arrives to EOF
    {
        fscanf_s(fPtr, "%s%s%s", id, SIZE, customer_name, SIZE, phone, PHONE_SIZE);//Receive string

        if (type == 1 && !memcmp(id, search, strlen(search)))//condition
        {
            printf("%s%13s%13s\n", id, customer_name, phone);//Print string
        }
        else if (type == 2 && !memcmp(customer_name, search, strlen(search)))//condition
        {
            printf("%s%13s%13s\n", id, customer_name, phone);//Print string
        }
        else if (type == 3 && !memcmp(phone, search, strlen(search)))//condition
        {
            printf("%s%13s%13s\n", id, customer_name, phone);//Print string
        }
    }
    fclose(fPtr);//Close the file
}