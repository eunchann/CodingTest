#include <iostream>
#include <queue>

int N, K, L, answer;

int map[100][100];

int snake_y[10000];
int snake_x[10000];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct COMMAND {
	int time;
	char C;
};

using namespace std;

int main() {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y - 1][x - 1] = 2;
	}

	cin >> L;

	queue<COMMAND> q;

	for (int i = 0; i < L; i++) {
		COMMAND command;
		cin >> command.time >> command.C;
		q.push(command);
	}

	int head_y = 0;
	int head_x = 0;
	int tail_y = 0;
	int tail_x = 0;
	
	int time = 0;
	int dir = 0;
	int tail_idx = 0;

	snake_y[0] = 0;
	snake_x[0] = 0;
	map[head_y][head_x] = 1;

	while (1) {
		time++;

		head_y += dy[dir];
		head_x += dx[dir];

		if (head_y < 0 || head_y >= N || head_x < 0 || head_x >= N || map[head_y][head_x] == 1) {
			break;
		}

		snake_y[time] = head_y;
		snake_x[time] = head_x;

		if (map[head_y][head_x] == 0) {
			tail_y = snake_y[tail_idx];
			tail_x = snake_x[tail_idx];
			map[tail_y][tail_x] = 0;
			tail_idx++;
		}

		map[head_y][head_x] = 1;

		if (!q.empty()) {
			COMMAND cur = q.front();

			if (cur.time == time) {
				if (cur.C == 'D') {
					dir = (dir + 1) % 4;
				}
				else {
					dir = (dir + 3) % 4;
				}
				q.pop();
			}
		}
	}

	cout << time;

	return 0;
}