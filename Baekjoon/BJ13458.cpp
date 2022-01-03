#include <iostream>

int N;
int A[1000000];
int B, C;
long long answer;

using namespace std;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		answer++;

		if (A[i] <= B) {
			continue;
		}

		if ((A[i] - B) % C == 0) {
			answer += (A[i] - B) / C;
		}
		else {
			answer += (A[i] - B) / C + 1;
		}
	}

	cout << answer;

	return 0;
}