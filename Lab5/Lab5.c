//Preprocessor Directives
#include <stdio.h>
//Function Prototypes
int checkIfDivisibleByNine(int n);
double approximatePi(int iterations);
//Main Function
int main() {
    //Problem 1
    int num;
    printf("IS IT DIVISIBLE BY 9\n");
    printf("Enter an integer: ");
    scanf("%d", &num);
    int isItDivisible = checkIfDivisibleByNine(num);
    if(isItDivisible){
        printf("%d is divisible by 9\n", num);
    }else{
        printf("%d is not divisible by 9\n", num);
    }

    //Problem 2
    int iterations;
    printf("Estimate PI\n");
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);
    printf("Estimated PI is %lf\n", approximatePi(iterations));
    return 0;
}
//Function for coding problem 1
int checkIfDivisibleByNine(int n){
    int sum = 0;
//A while loop that seperates the variable into it's resepective digit at each iteration
//Then it adds up each digit until all digits have been added together.
    while(n % 10 != 0){
      int temp = n % 10;
      sum += temp;
      n /= 10;
    }
//Checks if the sum is divisible by 9
    if(sum % 9 == 0){
        return 1;
    }

    return 0;
}
//Function for coding problem 2
double approximatePi(int iterations){
    int sign = -1;
    double sum = 0;
    for(int i = 0; i < iterations; i++){
        if(i % 2 == 0){
            sum += 1.0 / (2.0 * i + 1.0);//2*i+1 is always odd
        }else{
            sum += (sign) * (1.0 / (2.0 * i + 1.0));
        }
    }
    return 4*sum;
}
