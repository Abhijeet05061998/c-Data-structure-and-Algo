#include <iostream>
using namespace std;

int MissingNumber(int arr[], int size){
int sum=0;
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
    }
    int a=size;
    int Nnumber=((a-2)*(a-1))/2;
    int sub=sum-Nnumber;
    return sub;
}
int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];
	cout << MissingNumber(input, size);
	delete [] input;
	return 0;
}

