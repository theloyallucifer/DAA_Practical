//18/02/25
#include <stdio.h>
#include <stdlib.h>

int main(){
	int m, n, p, q, i, j, k;

	printf("\n Matrix1\n");

	printf("Enter the no. of Rows: ");
	scanf("%d", &m);
	printf("Enter the no. of Columns: ");
	scanf("%d", &n);

	printf("\n Matrix2\n");

	printf("Enter the no. of Rows: ");
	scanf("%d", &p);
	printf("Enter the no. of Columns: ");
	scanf("%d", &q);

	if (n != p){
		printf("Multiplication not Possible");
		exit(1);
	}

	int matr1[m][n], matr2[p][q], res[m][q];

	printf("\nEnter Elements of Matrix1: ");
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &matr1[i][j]);
		}
	}
	printf("\nEnter Elements of Matrix2: ");
	for (i = 0; i < p; i++){
		for (j = 0; j < q; j++){
			scanf("%d", &matr2[i][j]);
		}
	}

	for (i = 0; i < m; i++){
		for (j = 0; j < q; j++){
			res[i][j] = 0;
			for (k = 0; k < n; k++){
				res[i][j] += matr1[i][k] * matr2[k][j];
			}
		}
	}

	printf("\nMultiplication \n");

	for (i = 0; i < m; i++){
		for (j = 0; j < q; j++){
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}
