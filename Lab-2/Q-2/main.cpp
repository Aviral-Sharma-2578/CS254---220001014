#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b, int m, int n) {
	for (int i = n - 1; i >= 0; i--) {
		int j, last = a[m - 1];
		for (j = m - 2; j >= 0 && a[j] > b[i]; j--) a[j + 1] = a[j];
        if (last > b[i]) a[j + 1] = b[i], b[i] = last;
	}
}

int main() {
    int x; vector<int> a, b;

    ifstream array_a("../array_a.txt");
    while(array_a >> x) a.push_back(x);
    sort(a.begin(), a.end());
    array_a.close();
   
    ifstream array_b("../array_b.txt");
    while(array_b >> x) b.push_back(x);
    sort(b.begin(), b.end());
    array_b.close();

	int n = a.size(), m = b.size();
	merge(a, b, m, n);

    ofstream outputFile("output.txt");
	for(int y : a) outputFile << y << " ";
	for(int y : b) outputFile << y << " ";
    outputFile.close();
	return 0;
}
