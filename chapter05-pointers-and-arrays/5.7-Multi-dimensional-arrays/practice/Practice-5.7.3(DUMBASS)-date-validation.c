/*
Practice 5.7.3 — Add Error Checking to Date Functions
[FROM K&R Exercise 5-8]

K&R's day_of_year() and month_day() have no error checking.

Add validation:
- day_of_year(year, month, day) — validate month (1-12) and day (1-31)
- month_day(year, yearday, *pmonth, *pday) — validate yearday (1-365/366)

Return -1 if validation fails, otherwise return 0 (success).

Leap year logic:
  leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

Test with:
  - Valid dates (e.g., March 1, 2024)
  - Invalid dates (e.g., month 13, day 32)
  - Edge cases (Feb 29 in leap vs non-leap years)

Print success/failure for each test.

Key: Use the daytab[2][13] for days per month (define it).
DSA: Data validation, conditional logic on 2D arrays.
Complexity: O(1) time per validation.
*/

#include <stdio.h>
/*
Define daytab[2][13] with:
Row 0 — non-leap year: days per month (0, 31, 28, 31, 30, ...)
Row 1 — leap year: days per month (0, 31, 29, 31, 30, ...)
*/

static int daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },  /* non-leap */     // - not is_leap
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }   /* leap */         // - is_leap
};

int day_of_year(int year, int month, int day);
int month_day(int year, int year_day, int *pmonth, int *pday);

int main(){
  
    int doy, m, d;

    /* Example test 1:
    Test 1: March 1, 2024 (valid)

      Write:

      Call day_of_year(2024, 3, 1) and store result in doy
      Print whether it’s valid or invalid (check if doy == -1)
      If valid (doy != -1), call month_day() and print the month/day
    */
    
    // Test 1: March 1, 2024 (valid)
    // Call day_of_year(2024, 3, 1)
    // Print result
    // If valid, call month_day() and print
    doy = day_of_year(2024, 3, 1);
    if(doy == -1) {
        printf("Test 1: Invalid\n");
    } else {
        printf("Test 1: Valid\n");
        month_day(2024, doy, &m, &d);
        printf("  Day %d = %d/%d\n\n", doy, m, d);
    }
    
    // Test 2: Feb 29, 2024 (valid, leap)
    // Call day_of_year(2024, 2, 29)
    // Print result
    // If valid, call month_day() and print
    
    // Test 3: Feb 29, 2023 (invalid, non-leap)
    // Call day_of_year(2023, 2, 29)
    // Print result
    // If valid, call month_day() and print
    
    // Test 4: month 13 (invalid)
    // Call day_of_year(2024, 13, 1)
    // Print result
    // If valid, call month_day() and print
    
    // Test 5: day 32 in January (invalid)
    // Call day_of_year(2024, 1, 32)
    // Print result
    // If valid, call month_day() and print
    
    // Test 6: day 31 in April (invalid)
    // Call day_of_year(2024, 4, 31)
    // Print result
    // If valid, call month_day() and print
    
    return 0;
}

/*
day_of_year() - takes month/day and returns day-of-year number (1-365/366).
              - validates month and day (is the date real?)

day_of_year(year, month, day):
    Step 1: Calculate is_leap
    Step 2: Validate month (1-12), return -1 if invalid
    Step 3: Validate day (1 to daytab[is_leap][month]), return -1 if invalid
    Step 4: If valid, calculate day-of-year (sum days from month 1 to month-1, then add day)
    Step 5: Return the day number
*/
/*
Leap year rule{
  Condition 1
    - Every 4 years -> leap year ( Feb has 29 days )
    ```
      year % 4 == 0 — divisible by 4
    ```
    Ex:
    - 2024 — divisible by 4, not by 100 → leap year (Feb 29)
    - 2023 — not divisible by 4 → regular year (Feb 28)
  Condition 2
    - EXCEPT every 100 years = None leap year ( Feb has 28 days )
    ```
      year % 100 != 0 — NOT divisible by 100
    ```
    Ex:
    - 1900 — divisible by 100, not by 400 → regular year (Feb 28)
  Condition 3
    - EXCEPT every 400 years →  leap year (Feb has 29)
    ```
      year % 400 == 0 — divisible by 400
    ```
    Ex:
    - 2000 — divisible by 400 → leap year (Feb 29)

  Read it as:
  - (Condition 1 AND Condition 2) OR Condition 3 to be leap year , Both Condition 1 AND Condition 2 must be true. If either one fails, this part is false.
  - (divisible by 4 AND NOT by 100) OR (divisible by 400) to be leap year
  ```
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
  ```
}
*/

int day_of_year(int year, int month, int day){
  // Step 1: Calculate is_leap
  int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  // Step 2: Validate month (1-12), return -1 if invalid
  if((month < 1) || (month > 12)){
    return -1;
  }

  // Step 3: Validate day (1 to daytab[is_leap][month]), return -1 if invalid
  if((day < 1) || (day > daytab[is_leap][month])){
    return -1;
  }

  // Step 4: If valid, calculate day-of-year (sum days from month 1 to month-1, then add day)
  // If we get past Step 3 without returning -1, that means month and day are both valid. So Step 4 & 5 calculate and return the day-of-year number.
  // the day_tab's element represent each month but the value of each element represent the date of that month. So adding up element is adding all the date from Jan to that month/date.
  int day_num = 0;
  /*

  
  Day-of-Year = (sum of full months) + (current day)

  Example: March 20 (month=3, day=20)
    Full months: Jan + Feb(month-1) = 31 + 28/29 = 59/60
    Current day: 20
    Total: 59/60 + 20 = 79/80
    where jan = index 1 not index 0 on the array day_tab
          feb = index 2 not index 0 on the array day_tab
      so index 1 + index 2 + day because we dont need full day of the month at index 3.
  */
  for(int i = 1; i < month; i++){
    day_num = day_num + daytab[is_leap][i];
  }
  day_num = day_num + day; // orday_num += day;
  // Step 5: Return the day number
  return day_num;
}

/*
month_day() - takes day-of-year number and returns month/day.
            - validates yearday (is the day-of-year in range 1-365/366?).
Ex: Given 256 out of 365 or 366, what is MM/DD

month_day(year, yearday, *pmonth, *pday):
    Step 1: Calculate is_leap
        is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
    
    Step 2: Validate yearday
        if leap: yearday must be 1-366
        if not leap: yearday must be 1-365
        if invalid, return -1
    
    Step 3: Loop through months
        for month = 1 to 12:
            if yearday <= daytab[is_leap][month]:
                found it! break
            else:
                yearday -= daytab[is_leap][month]
    
    Step 4: Fill pointers
        *pmonth = month
        *pday = yearday
    
    Step 5: Return 0
*/

int month_day(int year, int year_day, int *pmonth, int *pday){
  /*parameter
  year — to calculate if leap
  yearday — the input day-of-year (user provides this)
  *pmonth — pointer to fill with result (month)
  *pday — pointer to fill with result (day)
  */

  // Step 1: Calculate is_leap
  int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  // Step 2: Validate yearday , Check if yearday is in the valid range.
  /*If leap year: 1-366 are valid. Anything else returns -1.
  If not leap: 1-365 are valid. Anything else returns -1.*/
  // If it's leap year
  if(is_leap){
    if((year_day < 1) || (year_day > 366)) return -1;
  } else {
    if (year_day < 1 || year_day > 365) return -1;
  }
  /* Better way to code step 2
  max_yearday = is_leap ? 366 : 365
  if (yearday < 1 or yearday > max_yearday) return -1
  */

  // Step 3: Loop through month
  int i;
  for(i = 1; i <= 12; i++){
    if(year_day <= daytab[is_leap][i]){
      break;
    } else { 
      year_day = year_day - daytab[is_leap][i]; //if the year day 245 out of 365 is noit smaller then this month noth fit
                                                // got 245 - this month = next yearday to compare untill it smaler than 40 or amount of date in that month,
                                                // the month where the # after supptrack is smaller than # of year of that month is the right month to land on.
    }
  }
  // Step 4: Fill pointers
  *pmonth = i; // step 3 i represent the month
  *pday = year_day; // after minus, result in # less than a month worth of date , that is how much date left start from that month.

  // Step 5: Return 0
  return 0;
}