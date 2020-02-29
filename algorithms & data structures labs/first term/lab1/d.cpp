#include<bits/stdc++.h>

using  namespace std;

const int N = 100100;
int n;
int heap[N];
int cur_size = 0;
void sift_up(int pos) {
	while (pos != 0 && heap[pos] > heap[(pos - 1) / 2]) {
		swap(heap[pos], heap[(pos - 1) / 2]);
		pos = (pos - 1) / 2;
	}
	return;
}

void insert(int x) {
	heap[cur_size] = x;
	sift_up(cur_size);
	cur_size++;
	return;
}

int get_max() {
	return heap[0];
}

void sift_down(int pos) {
	while (2 * pos + 1 < cur_size) {
		//cout << "here\n";
		bool flag = false;
		if (2 * pos + 2 < cur_size && max(heap[pos * 2 + 1], heap[pos * 2 + 2]) > heap[pos]) {
			if (heap[2 * pos + 1] > heap[2 * pos + 2]) {
				swap(heap[2 * pos + 1], heap[pos]);
				pos = pos * 2 + 1; flag = true;
			}
			else {
				swap(heap[2 * pos + 2], heap[pos]);
				pos = 2 * pos + 2; flag = true;
			}
		}
		else if(heap[pos] < heap[2 * pos + 1]) {
			swap(heap[pos], heap[pos * 2 + 1]);
			pos = pos * 2 + 1; flag = true;
		}
		if (!flag) {
			break;
		}
	}
	return;
}

void delete_max() {
	swap(heap[0], heap[cur_size - 1]);
	cur_size--;
	sift_down(0);
	return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, x;
		cin >> t;
		if (t == 0) {
            cin >> x;
            insert(x);
		} else {
            cout << get_max() << "\n";
            delete_max();
		}
	}
	return 0;
}

