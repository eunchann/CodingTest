#include <iostream>
#include <queue>

struct POS {
	int ry, rx, by, bx;
	int count;
};

int N, M, answer;

bool visit[10][10][10][10];
char map[10][10];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

using namespace std;

void bfs(POS start) {

	queue<POS> q;
	q.push(start);
	visit[start.ry][start.rx][start.by][start.bx] = true;

	while (!q.empty()) {
		POS cur = q.front(); q.pop();

		if (cur.count > 10) {
			answer = -1;
			return;
		}

		if (map[cur.ry][cur.rx] == 'O') {
			answer = cur.count;
			return;
		}

		for (int dir = 0; dir < 4; dir++) {
			POS next = cur;
			next.count = cur.count + 1;
			int r_dist = 0;
			int b_dist = 0;

			// red moves
			while (1) {
				next.ry += dy[dir];
				next.rx += dx[dir];
				r_dist++;

				if (map[next.ry][next.rx] == '#' || map[next.ry][next.rx] == 'O') {
					if (map[next.ry][next.rx] == '#') {
						next.ry -= dy[dir];
						next.rx -= dx[dir];
						r_dist--;
					}
					break;
				}
			}

			// blue moves
			while (1) {
				next.by += dy[dir];
				next.bx += dx[dir];
				b_dist++;

				if (map[next.by][next.bx] == '#' || map[next.by][next.bx] == 'O') {
					if (map[next.by][next.bx] == '#') {
						next.by -= dy[dir];
						next.bx -= dx[dir];
						b_dist--;
					}
					break;
				}
			}
			
			// if blue escapes
			if (map[next.by][next.bx] == 'O') {
				continue;
			}

			// if position of red ball and blue ball is same
			if (next.ry == next.by && next.rx == next.bx) {
				if (r_dist > b_dist) {
					next.ry -= dy[dir];
					next.rx -= dx[dir];
				}
				else {
					next.by -= dy[dir];
					next.bx -= dx[dir];
				}
			}

			if (visit[next.ry][next.rx][next.by][next.bx] == false) {
				visit[next.ry][next.rx][next.by][next.bx] = true;

				q.push(next);
			}
		}
	}

	// no solution
	answer = -1;
	return;
}

int main() {
	cin >> N >> M;

	POS start;
	start.count = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];

			if (map[y][x] == 'R') {
				start.ry = y;
				start.rx = x;
			}
			else if (map[y][x] == 'B') {
				start.by = y;
				start.bx = x;
			}
		}
	}

	bfs(start);

	cout << answer;

	return 0;
}