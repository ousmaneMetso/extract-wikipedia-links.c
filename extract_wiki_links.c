#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
   FILE *file = fopen(argv[1] , "r");

    fseek (file, 0, SEEK_END);
    int x = ftell(file);
    rewind(file);

    char array [x+1];
    fread(array, 1, x+1, file);

    int arrPosition = 0;
    char *temp = array;

    while (arrPosition <= x) {
        char *pt1 = strstr(temp, "<a href=\"/wiki/"); 
        if (pt1 == NULL) {
            break;
        }
        char *pt2 = strstr(pt1, "title=");
        char *pt3 = strstr(pt1, "</a>");

        temp = pt3;
         if (pt1 < pt2 && pt2 < pt3) {
             pt1 = pt1 + 15;
             while (*pt1 != '\"'){

                 printf ("%c" , *pt1);
                 pt1++;
             }
             printf("\n");
            
         }
            arrPosition++;
             }
             return 0;
}