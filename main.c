#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

   struct matrix *d, *m, *w;
    d = new_matrix(4,4);
    m = new_matrix(4,8);
    w = new_matrix(4,4);

    printf("Matrix 1\n");

    int i, j;
    int n = 0;

    for (i = 0; i < m->rows; i++){
        for (j = 0; j < m->cols; j++){
            m->m[i][j] = j+i;

        }

    }
	m->lastcol=m->cols;
    print_matrix(m);

    printf("\n");

    printf("Scalar Multiplication\n");
    scalar_mult(2,m);
    print_matrix(m);

    printf("\n");

	printf("Identity Matrix: \n");
    ident(d);
    print_matrix(d);

    printf("\n");
    printf("Multiply by Identity Matrix\n");
    matrix_mult(d,m);
    print_matrix(m);

    printf("\n");
	
	printf("Matrix  2 \n");
    for (i = 0; i < w->rows; i++){

        for (j = 0; j < w->cols; j++){
            w->m[i][j] = j;
        }

    }
	w->lastcol=w->cols;
    print_matrix(w);


    printf("\n");

    printf("Multiply by Non-Identity Matrix (Matrix 2)* (Matrix 1)\n");
    matrix_mult(w,m);
    print_matrix(m);
	
	
	
	screen s;
  clear_screen(s);
  color c;
  
  struct matrix *image;
  image= new_matrix(4, 4);
  c.red = 255;
  c.green = 255;
  c.blue = 255;
  
  add_edge(image, 100, 100, 0, 200, 100, 0);
  add_edge(image, 100, 100, 0, 100, 200, 0);
  add_edge(image, 200, 100, 0, 200, 200, 0);
  add_edge(image, 200, 200, 0, 100, 200, 0);

  printf("\n\nImage\n");
  print_matrix(image);
  draw_lines(image, s, c);
  
  display(s);
  save_extension(s, "lines.png");

  free_matrix( image );

}  
