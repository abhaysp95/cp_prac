#include <bits/stdc++.h>

using namespace std;

int min_exercises_done(const vector<int>& exercises, int E) {
	vector<pair<int, short>> ex(exercises.size(), pair<int, short>{});

	for (size_t i{}; i < exercises.size(); i++) {
		ex[i].first = exercises[i];
		ex[i].second = 2;
	}

	sort(ex.begin(), ex.end(), [&](auto& x, auto& y) {
			return x.first > y.first;
			});

	for (size_t i{}; i < ex.size(); i++) {
		printf("(%d, %d) ", ex[i].first, ex[i].second);
	}
	printf("\n");

	size_t idx{0};
	size_t count{};
	while (idx < ex.size() && E > 0) {
		// printf("(before) E: %d, count: %d, idx: %zu\n", E, ex[idx].second, idx);
		if (E >= ex[idx].first && ex[idx].second != 0) {
			E -= ex[idx].first;
			ex[idx].second--;
			count++;
		} else {
			idx++;
		}
		// printf("E: %d, count: %d, idx: %zu\n", E, ex[idx].second, idx);
	}

	if (E > 0) return -1;

	return count;
}

int main(void) {

	int E{};
	int N{};
	cin >> E >> N;

	vector<int> exercises(N, 0);
	for (size_t i = 0; i < N; i++) {
		cin >> exercises[i];
	}

	cout << min_exercises_done(exercises, E) << endl;
}
