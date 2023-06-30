#define GLOBAL_N 10
int arr2D[3000][500]; // 3000 row by 500 col array

int main() {
	for(int row = 0; row < 3000; row++){
		for(int col = 0; col < 500; col++){
			arr2D[row][col] = row + col;
		}
	}
return 0;
}
