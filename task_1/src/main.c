#include <stdio.h>
#include <stdlib.h>

typedef struct Matrixes {
  int size;
  int *first_matrix_values;
  int *second_matrix_values;
  int *result_matrix_values;
} Matrixes;

void ResultOutput(Matrixes *matrixes) {
  int size = matrixes->size;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      printf("%d ", matrixes->result_matrix_values[i * size + j]);
    }
    printf("\n");
  }
}

int *ReadValueLine(int input_values_amount) {
  int *values = malloc(input_values_amount * sizeof(int));
  if (values == NULL) {
    return NULL;
  }
  for (int i = 0; i < input_values_amount; ++i) {
    scanf("%d", &values[i]);
  }
  return values;
}

void ReadInput(Matrixes *input_matrixes) {
  scanf("%d", &input_matrixes->size);

  if (input_matrixes->size < 0) {
    printf("n/a");
    return;
  }

  int input_values_amount = input_matrixes->size * input_matrixes->size;
  input_matrixes->first_matrix_values = ReadValueLine(input_values_amount);
  input_matrixes->second_matrix_values = ReadValueLine(input_values_amount);
}

void MatrixMultiplication(Matrixes *matrixes) {
  int *result = matrixes->result_matrix_values;
  int *first_matrix = matrixes->first_matrix_values;
  int *second_matrix = matrixes->second_matrix_values;
  int size = matrixes->size;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      result[i * size + j] = 0;
      for (int k = 0; k < size; ++k) {
        result[i * size + j] +=
            first_matrix[i * size + k] * second_matrix[k * size + j];
      }
    }
  }
}

void FreeMemory(Matrixes *matrixes) {
  if (matrixes->first_matrix_values != NULL)
    free(matrixes->first_matrix_values);
  if (matrixes->second_matrix_values != NULL)
    free(matrixes->second_matrix_values);
  if (matrixes->result_matrix_values != NULL)
    free(matrixes->result_matrix_values);
}

int main() {
  Matrixes matrixes = {};

  ReadInput(&matrixes);

  if (matrixes.size == 0) {
    printf("0");
    return 0;
  }

  matrixes.result_matrix_values =
      malloc(matrixes.size * matrixes.size * sizeof(int));

  if (matrixes.first_matrix_values == NULL ||
      matrixes.second_matrix_values == NULL ||
      matrixes.result_matrix_values == NULL) {
    FreeMemory(&matrixes);
    printf("n/a");
    return 0;
  }

  MatrixMultiplication(&matrixes);

  ResultOutput(&matrixes);

  FreeMemory(&matrixes);
}
