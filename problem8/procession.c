#include <stdio.h>
#include <stdlib.h>

void randomProcession(int **r, int row, int col){ //rand함수를 이용한 랜덤 값 생성
	for(int i=0; i<row;i++){
		for(int j=0; j<col;j++){
			r[i][j]=rand() %10;
		}
	}
}

void procession(int **r, int row, int col){ //만들어진 행렬 출력
	printf("ㅡㅡㅡ행렬ㅡㅡㅡ");
	for(int i=0; i<row;i++){
		printf("\n");
		for(int j=0; j<col;j++){
			printf("%d ", r[i][j]);
		}
	}
	printf("\n");
}

void sum(int **a, int **b, int row, int col){ //행렬의 합 출력
	printf("ㅡㅡㅡ행렬의 합ㅡㅡㅡ");
	for(int i=0; i<row;i++){
		printf("\n");
		for(int j=0; j<col;j++){
			printf("%d ",a[i][j]+b[i][j]);
		}
	}
	printf("\n");
}

int main(void){
	int row,row2,col,col2;
	printf("첫 번째 행의 크기를 입력하세요 : ");
	scanf("%d", &row);
	printf("첫 번째 열의 크기를 입력하세요 : ");
	scanf("%d", &col);
	printf("두 번째 행의 크기를 입력하세요 : ");
	scanf("%d", &row2);
	printf("두 번째 열의 크기를 입력하세요 : ");
	scanf("%d", &col2);
	
	if(row==row2&col==col2){
		int **arr=malloc(sizeof(int *) * row); //메모리 공간 할당. 2차원 포인터
		int **arr2=malloc(sizeof(int *) * row); //메모리 공간 할당. 2차원 포인터
		
		for(int i=0; i<row;i++){
			arr[i]=malloc(sizeof(int)*col); //메모리 공간 할당
		}
		for(int i=0; i<row2;i++){
			arr2[i]=malloc(sizeof(int)*col2); //메모리 공간 할당
		}
		
		randomProcession(arr, row, col);
		randomProcession(arr2, row2, col2);
		procession(arr, row, col);
		procession(arr2, row2, col2);
		sum(arr,arr2,row,col);
		
		for(int i=0; i<row;i++){
			free(arr[i]); //할당받은 메모리 공간 해제
			free(arr2[i]); //할당받은 메모리 공간 해제
		}
		free(arr);//할당받은 메모리 공간 해제
		free(arr2);//할당받은 메모리 공간 해제
	}
	else{
		printf("두 행렬의 행과 열의 크기는 같아야 합니다.\n");
	}
	return 0;
}
