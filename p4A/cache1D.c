#define GLOBAL_N 10
int arr[100000];// 100,000 int array stored in the data segment

int  main(){
	for (int i = 0; i< 100000; i++){
		arr[i] = i; // iterates over the array
	}
	return 0;
}
