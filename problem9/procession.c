#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> input(int row, int col) {
	vector<vector<int>> matrix(row, vector<int>(col));
	for (vector<int>& v : matrix) {
		for (int& elem : v)
			elem = rand() % 10;
	}
	return matrix;
}

void print_vec(vector<vector<int>> v) {
	for (vector<int>& v1 : v) {
		for (int& elem : v1){
			cout << setw(6) << elem;
		}
		printf("\n");
	}
	printf("\n");
}

vector<vector<int>> multiply(vector<vector<int>>A, vector<vector<int>>B) {
	int row1 = A.size(), col1 = A[0].size();
	int row2 = B.size(), col2 = B[0].size();
	vector<vector<int>> matrix(row1,vector<int>(col2));

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++){
			matrix[i][j] += A[i][j] + B[i][j];
		}
	}
	return matrix;
}

int main() {
	int row1, row2, col1, col2;
	printf("첫 번째 행의 크기를 입력하세요 : ");
	scanf("%d", &row1);
	printf("첫 번째 열의 크기를 입력하세요 : ");
	scanf("%d", &col1);
	printf("두 번째 행의 크기를 입력하세요 : ");
	scanf("%d", &row2);
	printf("두 번째 열의 크기를 입력하세요 : ");
	scanf("%d", &col2);
	if(row1==row2&col1==col2){
	    	vector<vector<int>> A = input(row1, col1);
	    	vector<vector<int>> B = input(row2, col2);
	    	printf("ㅡㅡㅡ행렬ㅡㅡㅡ\n");
	    	print_vec(A);
	    	printf("ㅡㅡㅡ행렬ㅡㅡㅡ\n");
	    	print_vec(B);
	    	vector<vector<int>> AB = multiply(A, B);
		printf("ㅡㅡㅡ행렬의 합ㅡㅡㅡ\n");
	    	print_vec(AB);
    	}
    	else{
		printf("두 행렬의 행과 열의 크기는 같아야 합니다.\n");
	}
}
