#include <iostream>

int N;

int answer = 0;

using namespace std;

void rotate(int map[][20]) {
	int temp[20][20];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			temp[y][x] = map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = temp[x][N - y - 1];
		}
	}
}

void map2copy(int copyMap[][20], int map[][20]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			copyMap[y][x] = map[y][x];
		}
	}
}

void maxMap(int map[][20]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (answer < map[y][x]) {
				answer = map[y][x];
			}
		}
	}
}

void up(int map[][20]) {
	int temp[20][20] = { 0, };

	for (int x = 0; x < N; x++) {
		int ny = -1;
		bool flag = false;

		for (int y = 0; y < N; y++) {
			if (map[y][x] == 0) {
				continue;
			}

			if (flag == true && temp[ny][x] == map[y][x]) {
				temp[ny][x] *= 2;
				flag = false;
			}
			else {
				temp[++ny][x] = map[y][x];
				flag = true;
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = temp[y][x];
		}
	}
}

void dfs(int depth, int map[][20]) {
	if (depth >= 5) {
		maxMap(map);

		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int temp[20][20] = { 0, };

		map2copy(temp, map);
		up(temp);
		dfs(depth + 1, temp);
		rotate(map);
	}
}

int main() {
	cin >> N;

	int map[20][20];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	dfs(0, map);

	cout << answer;

	return 0;
}