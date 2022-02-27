//Preprocessor Directives
#include <stdio.h>
#include <math.h>
//Function Prototypes
/*Function prototypes must be before main because it tells the compiler about the functions return types,
how many arguments a function will have and the data types of the arguments*/
double calculateMonthlyPayment(double interestRate, double principal, double numOfPayments);
double approximateFactorials(double num);
int main(){
  //asks user for data and prints out result
  double principal, interestRate, numOfPayments;
  printf("CALCULATE PAYMENT\n");
  printf("Enter principal: ");
  scanf("%lf", &principal);
  printf("\nEnter annual interest rate: ");
  scanf("%lf", &interestRate);
  printf("\nEnter number of payments: ");
  scanf("%lf", &numOfPayments);
  double monthlyPayment = calculateMonthlyPayment(interestRate, principal, numOfPayments);
  printf("\nYour monthly payment is: %.2lf", monthlyPayment);

  //asks user for data and prints out result
  double number;
  printf("\nEnter a number: ");
  scanf("%lf", &number);
  double approximation = approximateFactorials(number);
  printf("%.lf! equals approximately %lf", number, approximation);
}

double calculateMonthlyPayment(double interestRate, double principal, double numOfPayments){
  //it always best to split up calculations because it will be easier to debug if you run into an issue
  /*Since we are given the annual rate as a percentage it is our job to turn that into a decimal
  and find the monthly interest rate. This is easily done by dividing the interest rate by 1,200
  in other word divides monthly paymeny by 100.0 * 12.0*/
  double monthlyInterest = interestRate / (100.0 * 12.0);
  /*We follow the given formula of
  (monthlyInterest * principal) / (1 - (1 + monthlyInterest)^(-numOfPayments))*/
  double numerator = monthlyInterest * principal;
  double denominator = 1 - pow(1 + monthlyInterest, -1.0 * numOfPayments);
  double result = numerator / denominator;
  return result;
}

double approximateFactorials(double num){
  /*We approximate the factorial using gosper's formula given as
  n^n * e^(-n) * square_root((2n + 1/3)*pi)*/
  /*To calculate square root I used the sqrt function in the math.h library
  another way of doing this is pow((2*n+1.0./3.0) * pi, .5)
  The pow function is also in the math.h library and is simply the function used to take some number
  to the power of another number
  I also used the M_PI constant given by the math.h library but one could define their own
  value of pi. The exp function is  simply e^x*/
  double squareRoot = sqrt((2 * num + 1.0 / 3.0) * M_PI);
  double product = pow(num, num) * exp(-1 * num);
  double result = squareRoot * product;
  return result;
}
