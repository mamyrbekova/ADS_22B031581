#include <iostream>
#include <vector>
using namespace std;

struct Heap {
	vector<int> heap;

	long long parent(long long i) {
		return (i - 1) / 2;
	}
	long long left(long long i) {
		return 2 * i + 1;
	}
	long long right(long long i) {
		return 2 * i + 2;
	}
	void insert(long long value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	 void print(){
        for(long long i = 0; i < heap.size(); i++){
            cout << heap[i] << ' ';
        }
        cout << endl;
    }
	long long extractMin() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			long long root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(long long i) {
		long long l = this->left(i);
		long long r = this->right(i);
		int smllst = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[i]);
			smllst = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smllst])
			smllst = r;
		if (smllst != i) {
			swap(this->heap[i], this->heap[smllst]);
			this->heapify(smllst);
		}
	}
	// int answer(int m) {
    //     int answer = 0;
    //     while (heap.size() > 1) {   

    //         int d1 = extractMin();
    //         int d2 = extractMin();       

    //         if(d1 >= m) {
    //             return answer;
    //         }
    //         int d = d1 + (2 * d2);
    //         answer += 1;
    //         insert(d);
    //     }
    //     return -1;
    // }
};

int main() {
	// Heap heap;
	// int n, m;
	// cin >> n >> m;
	// for(int i = 0; i < n; i++) {
	// 	int x;
	// 	cin >> x;
	// 	heap.insert(x);
	// }
	// cout << heap.answer(m);
	// return 0;

	Heap h;
	int n, m;
	cin >> n >> m;
	while(n--) {
		int x;
		cin >> x;
		h.insert(x);
	}

	long long answer = 0;
	while(h.size() > 1) {
		long long a, b;
		a = h.extractMin();
		b = h.extractMin();
		if(a >= m) {
			return answer;
		}

		long long c = a + (2*b);
		answer += 1;
		h.insert(c);
		return -1;
	}
	cout << answer;
}