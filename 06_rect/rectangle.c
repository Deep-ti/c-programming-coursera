#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
struct rect_tag{
  int x;
  int y;
  int width;
  int height;
};
typedef struct rect_tag rectangle;

rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTION
  if (r.height <0){
    r.height = abs(r.height);
    r.y = r.y - r.height;
  }
  if (r.width <0){
    r.width = abs(r.height);
    r.x = r.x - r.width;
  }
  return r;
}

rectangle intersection(rectangle r1, rectangle r2) {
  //WRITE THIS FUNCTION
  rectangle r_intersect_ans;
  //Find the left side
  r_intersect_ans.x = max(r1.x, r2.x);
  //Find the bottom
  r_intersect_ans.y = max(r1.y, r2.y);
  //Check if they don't intersect
  if ((r2.y > (r1.y + r1.height)) || ((r2.y + r2.height) < r1.y)){
    //R2 is completely above or completely below R1
  r_intersect_ans.height = 0;
  r_intersect_ans.width = 0;
  return r_intersect_ans;
  }
  if ((r2.x > (r1.x + r1.width)) || ((r2.x + r2.width < r1.x))){
    //R2 is completely to the left or right of R1
  r_intersect_ans.width = 0;
  r_intersect_ans.height = 0;
    return r_intersect_ans;
  }

  //Find the right side
  int right = min(r1.x + r1.width, r2.x + r2.width);
    r_intersect_ans.width = right -   r_intersect_ans.x;
  //Find the top
  int top = min(r1.y + r1.height, r2.y + r2.height);
    r_intersect_ans.height = top -  r_intersect_ans.y;

  //NOTE: add case when rectangles don't overlap
  return r_intersect_ans;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y,
    r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = -1; //4;
  r2.y = -2; //5;
  r2.width = 5; //-5;
  r2.height = 7; //-7;
  printf("r2 is ");
  printRectangle(r2);

  r3.x = -2;
  r3.y = -3; //7;
  r3.width = 7;
  r3.height = 10; //-10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = -4; //0;
  r4.y = 7;
  r4.width = 4; //-4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);

  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);

  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);

  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);

  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
