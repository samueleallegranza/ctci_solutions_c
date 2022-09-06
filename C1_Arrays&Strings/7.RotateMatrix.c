#include <stdio.h>
#define SIZE 3

void matrix_rotate(int in[][SIZE], int out[][SIZE], int);
void print_matrix(int matrix[][SIZE], int size);
void matrix_rotate_inplace(int matrix[][SIZE], int size);

int main(void) {
    int input[SIZE][SIZE] = {
        {1,2,3}, {4,5,6}, {7,8,9}
    };
    int output[SIZE][SIZE];

    matrix_rotate(input, output, SIZE);

    print_matrix(input, SIZE);
    print_matrix(output, SIZE);

    matrix_rotate_inplace(input, SIZE);
    print_matrix(output, SIZE);

    return 0;
}

void matrix_rotate(int in[][SIZE], int out[][SIZE], int size){
    int i,j;
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            //printf("(%d,%d) -> (%d,%d)\n", i,j,j,size-i-1);
            out[j][size-i-1] = in[i][j];
        }
    }
}

void print_matrix(int matrix[][SIZE], int size) {
    int row, column=0;
    for (row=0; row<size; row++) {
        for(column=0; column<size; column++) {
                printf("%d     ", matrix[row][column]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void matrix_rotate_inplace(int matrix[][SIZE], int size){
    int layers, quantity, offset, cache_top;
    int l, i;
    layers = size/2;

    for(l=0; l<layers; l++) {
        quantity = size - l - 1;
        for(i=l; i<quantity; i++) {
            offset = i-l;
            // top saved temporarly for switch
            cache_top = matrix[l][i];
            // left -> top
            matrix[l][i] = matrix[l-offset][l];
            // bottom -> left
            matrix[quantity-offset][l] = matrix[quantity][quantity-offset];
            // right -> bottom
            matrix[quantity][quantity-offset] = matrix[i][quantity];
            // top -> right
            matrix[i][quantity] = cache_top;
        }
    }

}
