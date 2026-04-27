#include<stdio.h>

int main() {
  int p, c, count = 0, i, j;
  int alc[5][3], max[5][3], need[5][3];
  int safe[5], available[3], done[5], terminate;

  printf("Enter the number of process and resources: ");
  scanf("%d %d", &p, &c);

  printf("enter allocation of resource of all process %dx%d matrix:\n", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", &alc[i][j]);
    }
  }

  printf("enter the max resource process required %dx%d matrix:\n", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", &max[i][j]);

      if (max[i][j] < alc[i][j]) {
        printf("Invalid input: Max < Allocation at P%d\n", i);
        return 0;
      }
    }
  }

  printf("enter the available resource:\n");
  for (i = 0; i < c; i++)
    scanf("%d", &available[i]);

  printf("\nneed resources matrix are\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < p; i++) {
    done[i] = 0;
  }

  while (count < p) {
    terminate = 0;

    for (i = 0; i < p; i++) {
      if (done[i] == 0) {
        for (j = 0; j < c; j++) {
          if (need[i][j] > available[j])
            break;
        }

        if (j == c) {
          safe[count] = i;
          done[i] = 1;

          for (j = 0; j < c; j++) {
            available[j] += alc[i][j];
          }

          count++;
        } else {
          terminate++;
        }
      }
    }

    // ✅ FINAL CORRECTION HERE
    if (terminate == p) {
      printf("safe sequence does not exist\n");
      return 0;
    }
  }

  printf("\navailable resource after completion\n");
  for (i = 0; i < c; i++) {
    printf("%d\t", available[i]);
  }

  printf("\nsafe sequence are\n");
  for (i = 0; i < p; i++) {
    printf("P%d\t", safe[i]);
  }

  return 0;
}
