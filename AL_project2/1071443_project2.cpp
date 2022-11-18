#include <iostream>
#include <vector>
#include <vector>
#include <climits>
#include <set>
using namespace std;

int gcd(int a, int b) {
	int t = 1;
	while (t != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}


void SpecialSort() {
	int N, M, tem;
	cin >> N >> M;
	int* arrA = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arrA[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arrA[j] % M > arrA[j + 1] % M) {
				tem = arrA[j];
				arrA[j] = arrA[j + 1];
				arrA[j + 1] = tem;
			}
			else if (arrA[j] % M == arrA[j + 1] % M) {
				if (arrA[j] % 2 == 1 && arrA[j + 1] % 2 == 1 && arrA[j] < arrA[j + 1]) {
					tem = arrA[j];
					arrA[j] = arrA[j + 1];
					arrA[j + 1] = tem;
				}
				else if (arrA[j] % 2 == 0 && arrA[j + 1] % 2 == 0 && arrA[j] > arrA[j + 1]) {
					tem = arrA[j];
					arrA[j] = arrA[j + 1];
					arrA[j + 1] = tem;
				}
				else if (arrA[j] % 2 == 0 && arrA[j + 1] % 2 == 1) {
					tem = arrA[j];
					arrA[j] = arrA[j + 1];
					arrA[j + 1] = tem;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << arrA[i] << " ";

	cout << endl;
}

int findMiniMum(vector<int>key, set<int> allNode) {
	int min = INT_MAX, temp = 0;
	for (int i = 0; i < key.size(); i++) {
		if (min > key[i] && allNode.count(i)) {
			min = key[i];
			temp = i;
		}

	}
	return temp;
}

void MinimumSpanningTree_Prim() {
	int N, M, T, X; //N���q�����ƶq,M���i�سy�ǰe�����զX�`��,T���]�k�]�ƪ����ŤW��,X�����Ť@�]�k�]�Ƥ�����
	cin >> N >> M >> T >> X;
	vector<vector<int>>adj(N + 1);
	set<int> allNode;
	vector<int>key(N + 1, INT_MAX);
	vector<int>parent(N + 1, -1);
	for (int i = 0; i < N + 1; i++) {
		adj[i].resize(N + 1);
		allNode.insert(i);
	}
	allNode.erase(0);
	int a, b, weight;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> weight;
		adj[a][b] = weight;
		adj[b][a] = weight;
	}
	//start algorithm
	key[1] = 0;
	while (!allNode.empty()) {
		int u = findMiniMum(key, allNode);
		allNode.erase(u);
		for (int i = 0; i < adj[u].size(); i++) {
			if (adj[u][i] && allNode.count(i) && key[i] > adj[u][i]) {
				key[i] = adj[u][i];
				parent[i] = u;
			}
		}
	}
	if (M < N - 1) {
		cout << "�S���������ǰe����سy\n";
		return;
	}
	int total = 0, siz = 0;
	for (int i = 0; i < N + 1; i++) {
		if (parent[i] != -1) {
			total += adj[parent[i]][i];
			siz++;
		}
	}
	double tem = 1 / sqrt(double(X) / double(total));
	if (tem > T) {
		cout << "�̤p�n�Ψ�󰪵��Ū��ǰe��\n";
		return;
	}
	cout << (int)tem << endl;
	cout << siz << endl;
	for (int i = 0; i < N + 1; i++) {
		if (parent[i] != -1) {
			cout << parent[i] << " " << i << endl;
		}
	}
}

struct node {
	vector<node*>adj;
	bool used;
	bool visit;
	int data;
};
#include <queue>
int bfs(node* u, vector<node*>map) {
	for (int i = 0; i < map.size(); i++) {
		map[i]->used = false;
		map[i]->visit = false;
	}
	u->visit = true;
	u->used = true;
	int siz = 0;
	queue<node*> q;
	q.push(u);
	while (!q.empty()) {
		node* front = q.front();
		q.pop();
		bool notInSet = true; //�S�Aset�̭�
		for (int i = 0; i < front->adj.size(); i++) {
			if (front->adj[i]->used == true)
				notInSet = false;
			if (front->adj[i]->visit == false) {
				front->adj[i]->visit = true;
				q.push(front->adj[i]);
			}
		}
		if (notInSet) {
			siz++;
			front->used = true;
		}
	}
	return siz;
}

void independentSet() {
	int nodeNum, edgeNum;
	cin >> nodeNum >> edgeNum;
	vector<node*> map;
	for (int i = 0; i < nodeNum; i++) {
		node* nN = new node;
		nN->used = false;
		nN->data = i;
		map.push_back(nN);
	}
	int a, b;
	for (int i = 0; i < edgeNum; i++) {
		cin >> a >> b;
		map[a]->adj.push_back(map[b]);
		map[b]->adj.push_back(map[a]);
	}
	int max = 0;
	for (int i = 0; i < map.size(); i++) {
		int tem = bfs(map[i], map);
		if (tem > max)
			max = tem;
	}
	cout << max << endl;
}

int main() {
	int cas;
	cout << "1.Euclidean algorithm\n2.Special sort\n3.���F�s�q���ǰe��\n4.Independent Set\n5.��������\nProblem ?: ";
	while (cin >> cas)
	{
		switch (cas) {
		case 1:
			int a, b;
			cin >> a >> b;
			cout << gcd(a, b) << endl;
			break;
		case 2:
			SpecialSort();
			break;
		case 3:
			MinimumSpanningTree_Prim();
			break;
		case 4:
			independentSet();
			break;
		case 5:
			return 0;
		default:
			break;
		}
		cout << "1.Euclidean algorithm\n2.Special sort\n3.���F�s�q���ǰe��\n4.Independent Set\n5.��������\nProblem ?: ";
	}
}