#include <stdio.h>


// Function that converts the floor from char format to an integer format.
int number_of_floor(char floor){
    if (floor == 'G'){
        return 0;
    }
    else if (floor == '1'){
        return 1;
    }
    else if (floor == '2'){
        return 2;
    }
    else if (floor == '3'){
        return 3;
    }
    else if (floor == '4'){
        return 4;
    }
    else if (floor == '5'){
        return 5;
    }
    else{
        return -4;
    }
}


//Function that returns floor number always in correct format.
char function_floor;
int function_num;
char correct_floor(){
    //Creating and assigning two new variables, which represent floor in both formats.
    printf("Type the floor:\n");
    getchar();
    scanf("%c", &function_floor);

    function_num = number_of_floor(function_floor);

    //Check if format is correct.
    if (function_num == -4){
        printf("Please, type the floor in the correct format(G, 1, 2, 3, 4, 5)\n");
        //Calling function recursively.
        correct_floor();
    }

    return function_floor;
}


char floor1 = 'G';
int num1 = 0;
char general_answer;
int main() {

    //Ask if user wants to proceed.
    printf("Do you want to proceed(Type Y for yes and N for no):\n");
    scanf("%c", &general_answer);

    //Assigning two variables, which represents the floor where lift is now.
    char floor0 = floor1;
    int num0 = number_of_floor(floor0);

    while (general_answer == 'Y') {
        //Assigning two variables, which represents the floor where lift needs to get.
        floor1 = correct_floor();
        num1 = number_of_floor(floor1);

        //Depending on type we have two possibilities.
        char answer;
        if (num0 >= num1) {
            for (int i = num0 - 1; i >= num1; i--) {

                if (i == 0) {
                    printf("This is a ground floor. Bye!\n");
                    num0 = 0;
                    break;
                }
                if (i == num1){
                    printf("This is your floor number: %i. Bye!\n", num1);
                    num0 = i;
                    break;
                }

                printf("This is a floor number: %i\n", i);

                printf("Do you want to leave(Y, N):\n");
                getchar();
                scanf("%c", &answer);

                if (answer == 'Y') {
                    printf("Have a nice day, bye!\n");
                    num0 = i;
                    break;
                }

                else if (answer == 'N') {
                    continue;
                }
            }
        }
        else if (num0 <= num1){
            for (int i = num0 + 1; i <= num1; i++) {

                if (i == 5) {
                    printf("This is the last floor. Bye!\n");
                    num0 = 5;
                    break;
                }
                if (i == num1){
                    printf("This is your floor number: %i. Bye!\n", num1);
                    num0 = i;
                    break;
                }

                printf("This is a floor number: %i\n", i);

                getchar();
                printf("Do you want to leave(Y, N):\n");
                scanf("%c", &answer);

                if (answer == 'Y') {
                    printf("Have a nice day, bye!\n");
                    num0 = i;
                    break;
                }
                else if (answer == 'N') {
                    continue;
                }
            }
        }
        printf("\n");
        printf("Do you want to proceed(Type Y for yes and N for no):\n");
        getchar();
        scanf("%c", &general_answer);
    }
    printf("\n");
    printf("Thank you, bye!\n");
    return 0;
}
