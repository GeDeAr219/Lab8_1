#include <iostream>
#include <algorithm>
using namespace std;
int eliminateCandidates(int list[4][5]) {
	int sumlist[4];
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += list[i][j];

		}
		sumlist[i] = sum;

	}
	int eliminated = sumlist[0];
	for (int x = 0; x < 4; x++)
	{
		if (sumlist[x] < eliminated) {
			eliminated = sumlist[x];
		}


	}
	int size = sizeof(sumlist) / sizeof(sumlist[0]);


	auto iter = find(begin(sumlist), end(sumlist), eliminated);

	int index = distance(begin(sumlist), iter);
	cout << "candidate " << (index + 1) << " is eliminated" << endl;
	return index + 1;
}

int main() {
	int list[4][5];


	for (int i = 0; i < 4; i++) {
		std::cout << "Enter scores for candidates " << i + 1 << " (5 scores): ";
		for (int j = 0; j < 5; j++) {
			std::cin >> list[i][j];
		}
	}

	eliminateCandidates(list);

	return 0;
}