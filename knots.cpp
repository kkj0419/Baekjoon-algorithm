#include <iostream>
#include <vector>
#include <algorithm>
#define Maxsize 100010
using namespace std;
vector<pair<long long, long long> >vec;

int compare(pair<long long, long long>a, pair<long long, long long> b) {
	return a.first < b.first;
}

int binary(long long distance) {
	long long knots[Maxsize] = { 0, };		//initial set
	int i;
	knots[0] = vec[0].first;	//첫 knot 
	for (i = 1; i < vec.size(); i++) {
		if (knots[i - 1] + distance > vec[i].first + vec[i].second) {	//다음 line을 뛰어넘음 
			return 0;
		}
		else {
			knots[i] = max(vec[i].first, knots[i - 1] + distance);
		}
	}
	return 1;
}

int main() {

	int number;
	scanf("%d", &number);
	int i;
	long long a, b;

	for (i = 0; i < number; i++) {
		scanf("%d %d", &a, &b);
		vec.push_back({ a,b });		//starting point, length
	}
	sort(vec.begin(), vec.end(), compare);
	long long min_size;
	long long left = 0, right = 2000000000; 	//range 
	while (left <= right) {
		long long mid = (left + right) / 2;		//initial set
		if (binary(mid) == 1) {	//value up
			min_size = mid;
			left = mid + 1;
		}
		else {		//value down 
			right = mid - 1;
		}
	}
	printf("%d", min_size);

	return 0;
}