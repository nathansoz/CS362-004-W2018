#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define LOWER_CHAR 32 //SPACE
#define UPPER_CHAR 126 //~

char *buffer = 0; // store our memory here so we don't leak

char myChars[4] = { 'e', 'r', 's', 't' };
#define LOWER_STRING_CHAR 0 // e
#define UPPER_STRING_CHAR 3 // t

void freeBuffer()
{
    if(buffer != 0)
    {
        free(buffer);
    }
}

// looked this up:
//    https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
int getRand(int lower, int upper)
{
    return rand() % (upper + 1 - lower) + lower;
}

char inputChar()
{
    return (char)(getRand(LOWER_CHAR, UPPER_CHAR));
}

char *inputString()
{
    freeBuffer();

    buffer = (char*)malloc(6);
    
    int i;
    for(i = 0; i < 5; i++)
    {
        buffer[i] = myChars[getRand(LOWER_STRING_CHAR, UPPER_STRING_CHAR)];
    }

    buffer[5] = '\0';

    return buffer;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
