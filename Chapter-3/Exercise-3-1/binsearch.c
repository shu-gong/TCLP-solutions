#include<stdio.h>
/* Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.*/
int binsearch(int x, int v[], int n);

main() {
	int var[] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d", binsearch(12, var, 10));

}

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low < high) {
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid ;
		else
			low = mid + 1;
	}
	if (x == v[low])
		return low;
	else
		return -1;
}
