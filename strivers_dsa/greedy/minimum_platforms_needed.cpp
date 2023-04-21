#include <bits/stdc++.h>

using namespace std;

#define SZ 6

using p2s = pair<size_t, size_t>;

size_t get_max_stations_needed(p2s* train_details) {
	// size of this vector will tell the stations needed
	vector<size_t> stations{};  // stations will store train's index

	// sort according to arrival time
	// confirm with the question whether the details given are already in
	// sorted order or not (if yes, then no need to do this)
	sort(train_details, train_details + SZ, [&](p2s x, p2s y) {
			return x.first < y.first;
	});

	stations.push_back(0);  // first train will need one station
	for (size_t i{1}; i < SZ; i++) {
		bool new_station_needed{true};
		for (size_t j{}; j < stations.size(); j++) {
			if (train_details[stations[j]].second < train_details[i].first) {
				new_station_needed = false;
				stations[j] = i;
				break;
			}
		}

		if (new_station_needed) {
			stations.push_back(i);
		}
	}

	return stations.size();
}

int main(void) {
	p2s train_details[6] {{900, 910}, {940, 1200}, {950, 1120}, {1100, 1130}, {1500, 1900}, {1800, 2000}};

	printf("stations count: %zu\n", get_max_stations_needed(train_details));

	return 0;
}
