#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define SZ 6

using pi2 = pair<int, int>;  // {start, end}
using p2i3 = pair<pair<int, int>, size_t>;  // {{start, end}, index}

void max_meeting_in_one_room(const pi2* mdetails) {
	p2i3 updated_mdetails[SZ];

	for (size_t i{}; i < SZ; i++) {
		updated_mdetails[i] = {{mdetails[i].first, mdetails[i].second}, i + 1};
	}

	// sort the meetings based on their end time
	sort(updated_mdetails, updated_mdetails + SZ, [&](p2i3 x, p2i3 y) {
				return x.first.second < y.first.second;
			});

	/* for (size_t i{}; i < SZ; i++) {
		printf("%d, %d\n", updated_mdetails[i].first.first, updated_mdetails[i].first.second);
	} */

	// print the meetings perfomed
	// printf("%d, %d\n", updated_mdetails[0].first.first, updated_mdetails[0].first.second);
	printf("%zu ", updated_mdetails[0].second);
	size_t last_selected_meeting{};
	for (size_t i{1}; i < SZ; i++) {
		int pend = updated_mdetails[last_selected_meeting].first.second;
		int nstart = updated_mdetails[i].first.first;
		if (pend < nstart) {
			// printf("%d, %d\n", nstart, updated_mdetails[i].first.second);
			printf("%zu ", updated_mdetails[i].second);
			last_selected_meeting = i;
		}
	}
	putchar('\n');

}

int main() {
	pi2 meet_details[SZ] = {{1, 2}, {0, 6}, {3, 4}, {8, 9}, {5, 7}, {8, 9}};

	printf("res: \n");

	max_meeting_in_one_room(meet_details);

	return 0;
}
