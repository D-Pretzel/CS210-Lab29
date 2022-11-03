/** vector.c
* ================================================================
* Name: CS210
* Section: n/a
* Project: Lab29 - Vector ADT
* =================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

// Task 1:  Write Your getNumLines Function Here
int getNumLines(char filename[]) {
   FILE* fp = fopen(filename, "r");
   int count = 0;
   char line[100];
   while (fgets(line, 100, fp) != NULL) {
      count++;
   }
   fclose(fp);
   return count;
}

// Task 3:  Write your readFile Function Here
void readFile(char filename[], vector* v, int numLines) {
   FILE* fp = fopen(filename, "r");
   int count = 0;
   char line[1024];
   while (fgets(line, 1024, fp) != NULL) {
      vector_set(v, count, atoi(line));
      count++;
   }
   fclose(fp);
}


int main(void)
{
   // Task 2
   //  With the functions provided in the Vector ADT, ceate a correctly sized vector to read-in all data from the lab29Data.csv file
   int numLines = getNumLines("lab29Data.csv");

   //Declare a vector and use the vector_create function to initalize it
   vector v;
   vector_create(&v, numLines);

   //FIXME:
   // printf("Vector Size: %d\n", v.size);

   // Task 4
   //  Utilize your readFile() function
   //  to populate the vector -- you will need to make changes
   //  for this function to perform correctly
   readFile("lab29Data.csv", &v, numLines);

   // Task 5
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 6
   //  With the functions provided in the Vector ADT,
   //  insert a 12 at index 139
   vector_insert(&v, 139, 12);

   // Task 7
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 8
   //  With the functions provided in the Vector ADT,
   //  print the element at index 999
   printf("Element at index 999: %d\n", *vector_at(&v, 999));

   // Task 9
   //  With the functions provided in the Vector ADT,
   //  erase the element at index 999
   vector_erase(&v, 999);

   // Task 10
   //  With the functions provided in the Vector ADT,
   //  print the element at index 999
   printf("After Erase element at index 999: %d\n", *vector_at(&v, 999));

   // Task 11
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 12
   //  Using the Vector ADT provided function
   //  vector_push_back to insert the integer 222
   //  at the end of the vector
   vector_push_back(&v, 222);

   // Task 13
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 14
   //  With the functions provided in the Vector ADT,
   //  destroy the vector
   vector_destroy(&v);

}