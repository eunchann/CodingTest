#include <iostream>

int N, M, K;

int map[20][20];

using namespace std;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

struct DICE {
	int top, back, right, left, front, bot;

	void rotate(int dir) {
		dir = dir + 1;
		if (dir == 1) {
			int temp = bot;
			bot = right;
			right = top;
			top = left;
			left = temp;
		}
		else if (dir == 2) {
			int temp = bot;
			bot = left;
			left = top;
			top = right;
			right = temp;
		}
		else if (dir == 3) {
			int temp = bot;
			bot = back;
			back = top;
			top = front;
			front = temp;
		}
		else {
			int temp = bot;
			bot = front;
			front = top;
			top = back;
			back = temp;
		}
	}


};

int main() {
	int start_y, start_x;

	cin >> N >> M >> start_y >> start_x >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	DICE dice;
	dice.top = 0;
	dice.back = 0;
	dice.right = 0;
	dice.left = 0;
	dice.front = 0;
	dice.bot = 0;

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		dir--;
		start_y += dy[dir];
		start_x += dx[dir];

		if (start_y < 0 || start_y >= N || start_x < 0 || start_x >= M) {
			start_y -= dy[dir];
			start_x -= dx[dir];
			continue;
		}

		dice.rotate(dir);

		if (map[start_y][start_x] == 0) {
			map[start_y][start_x] = dice.bot;
		}
		else {
			dice.bot = map[start_y][start_x];
			map[start_y][start_x] = 0;
		}

		cout << dice.top << "\n";
	}

	return 0;
}