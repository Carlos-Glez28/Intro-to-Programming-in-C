#include <stdio.h>

int isLeapYear(int year);
int calculateDayOfYear(int day, int month, int year);
int calculateDayOfYear1(int day, int month, int year);
int within_x_percent(double ref, double data, double percent);
void classifySubstance(double data);

int main(){
  int day, month, year, dayOfYear;
  double data;
  printf("CALCULATE DAY OF YEAR\n");
  printf("Enter a date: ");
  scanf("%d %d %d", &month, &day, &year);
  dayOfYear = calculateDayOfYear1(day, month, year);
  printf("\nIt is the %dth day of the year\n", dayOfYear);

  printf("FIND SUBSTANCE FOR BOILING POINT\n");
  printf("Enter a temperature: ");
  scanf("%lf", &data);
  classifySubstance(data);
  return 0;
}

int isLeapYear(int year){
  //year is a leap year if it is divisible by 4 and divisible by 400 but not 100
  if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
    return 1;
  }
  return 0;
}
//Uses arrays and for loop
//The for loop and array method uses concepts not covered at the point of lab 4 submission
//This is an interesting approach that some people attempted to use
int calculateDayOfYear(int day, int month, int year){
  //array that holds all the days in each month
  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  //Changes the number of days in february if it is a leap year
  if(isLeapYear(year)){
    months[1] = 29;
  }
  //If the month is january then just return whatever day was inputted
  if(month == 1){
    return day;
  }
  //Calculates the day of the year by iterating through the array but stopping a month before the chosen month
  //Then adding the day of the month to the sum after the for loop.
  int sum = 0;
  for(int i = 0; i < month - 1; i++){
    sum += months[i];
  }
  sum += day;
  return sum;
}

//Uses a bunch of if statements
int calculateDayOfYear1(int day, int month, int year){
  int jan = 31, feb = 28, mar = 31, april = 30, may = 31, june = 30, july = 31, aug = 31, sept = 30, oct = 31, nov = 30;
  if(isLeapYear(year)){
    feb = 29;
  }
  //this way checks what month it is and the calculations are
  int sum = 0;
  if(month == 1){
    return day;
  }else if(month == 2){
    sum = jan + day;
  }else if(month == 3){
    sum = jan + feb + day;
  }else if(month == 4){
    sum = jan + feb + mar + day;
  }else if(month == 5){
    sum = jan + feb + mar + april + day;
  }else if(month == 6){
    sum = jan + feb + mar + april + may + day;
  }else if(month == 7){
    sum = jan + feb + mar + april + may + june + day;
  }else if(month == 8){
    sum = jan + feb + mar + april + may + june + july + day;
  }else if(month == 9){
    sum = jan + feb + mar + april + may + june + july + aug + day;
  }else if(month == 10){
    sum = jan + feb + mar + april + may + june + july + aug + sept + day;
  }else if(month == 11){
    sum = jan + feb + mar + april + may + june + july + aug + sept + oct + day;
  }else{
    sum = jan + feb + mar + april + may + june + july + aug + sept + oct + nov + day;
  }
  return sum;
}

int within_x_percent(double ref, double data, double percent){
  //Checks if the given data is in the given bounds
  if(data >= ref - (ref * percent) && data <= ref + (ref * percent)){
    return 1;
  }
  return 0;
}
//Classifies a substance using a given data, specific boiling point of a substance
//and a percentage that allows classification to be within a specific error bound
void classifySubstance(double data){
  double water = 100.0, mercury = 357.0, copper = 1187.0, silver = 2193.0, gold = 2660.0;
  double percent = 0.05;
  if(within_x_percent(water, data, percent)){
    printf("The substance is Water\n");
  }else if(within_x_percent(mercury, data, percent)){
    printf("The substance is Mercury\n");
  }else if(within_x_percent(copper, data, percent)){
    printf("The substance is Copper\n");
  }else if(within_x_percent(silver, data, percent)){
    printf("The substance is Silver\n");
  }else if(within_x_percent(gold, data, percent)){
    printf("The substance is Gold\n");
  }else{
    printf("Unknown substance\n");
  }
}
