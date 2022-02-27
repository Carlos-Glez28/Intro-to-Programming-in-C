#include <stdio.h>

int main(){
  /*1. Write code that calculates mileage reimbursement for a salesperson at
  a rate of $.48 per mile. Your program should get the mileage from the user */
  double rate = 0.48;
  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  double beginning;
  printf("Enter beginning odometer reading: ");
  scanf("%lf", &beginning);
  double ending;
  printf("\nEnter ending odometer reading: ");
  scanf("%lf", &ending);
  //Calculates the change in the odomerter reading
  double distanceTraveled = ending - beginning;
  //Calculates result which is given as the formula (ending - beginning) * rate;
  double result = distanceTraveled * rate;
  printf("\nYou traveled %.2lf miles. At $%.2lf per mile, your reimbursement is $%.2lf", distanceTraveled, rate, result);

  /*2. Write code to convert a temperature in degrees Fahrenheit to degrees
    Celsius. Your program should get the temperature Fahrenheit from the user and
    print the result */
  double fahrenheit;
  printf("FAHRENHEIT TO CELSIUS CALCULATOR\n");
  printf("Enter temperature Fahrenheit: ");
  scanf("%lf", &fahrenheit);
  //Calculates fahrenheit
  //Since this is arithmetic using doubles then (5/9) would result in getting a reuslt of 0
  //So we have to use (5.0/9.0) so we can use double division
  double celsius = (fahrenheit - 32) * (5.0/9.0);
  printf("\n%.2lf degrees Fahrenheit is %.2lf degrees Celsius", fahrenheit, celsius);
  retun 0;
}
