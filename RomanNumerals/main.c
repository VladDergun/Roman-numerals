#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

roman(  unsigned int year,  unsigned short int min, char letter1);
roman_special( unsigned int year,  unsigned int min, char letter1, char letter2 );


main(){

    unsigned int year; //since there will be no negative numbers, the unsigned int option was chosen
    char buffer[6];


    while (1){ //a simple check algorithm

        printf("Welcome to romanizer! Please, enter a year you would like to romanize (input must be between 0 and 10000):");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%u", &year);

        if(year <= 0 || year > 9999){
            printf("\nUnfortunately, you entered a number OR a symbol that cannot be converted. Please, press any button and try again.\n");
            fflush(stdin);
            getch();

        }
        else{
            break; //Exit from the algorithm

        }
    }



    printf("Your romanized year is ");
    year = roman(year, 1000, 'M');
    year = roman_special(year, 900, 'C', 'M');
    year = roman(year, 500, 'D');
    year = roman_special(year, 400, 'C', 'D');
    year = roman(year, 100, 'C');
    year = roman_special(year, 90, 'X', 'C');
    year = roman(year, 50, 'L');
    year = roman_special(year, 40, 'X', 'L');
    year = roman(year, 10, 'X');
    year = roman_special(year, 9, 'I', 'X');
    year = roman(year, 5, 'V');
    year = roman_special(year, 4, 'I', 'V');
    year = roman(year, 1, 'I');

    getch();
    return 0;

}

roman(  unsigned int year, unsigned short int min, char letter1){
    while(year >= min){
        putchar(letter1);
        year = year- min;
    }
    return year;
}
roman_special( unsigned int year, unsigned int min, char letter1, char letter2 ){ //This function is used to process numbers that give two signs as output.
    while(year >= min){
        putchar(letter1);
        putchar(letter2);
        year = year - min;
    }
    return year;
}


