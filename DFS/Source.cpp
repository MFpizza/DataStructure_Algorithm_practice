#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int time;
struct Node {
	string color;
	Node(int a) {
		data = a;
		color = "white";
	}
	int d;
	int low;
	bool cut;
	bool bridge;
	int bridgeNext;
	vector<Node*> adj;
	Node* parent;
	int numChidren;
	int data;
};

void cutPoint(Node* u) {
	time++;
	u->d = u->low = time;
	for (int i = 0; i < u->adj.size(); i++) {
		Node* v = u->adj[i];
		if (v->d == 0) {
			u->numChidren++; //add
			v->parent = u;
			cutPoint(v);
			u->low = min(u->low, v->low);
			if (u->parent != NULL) {//add
				if (v->low >= u->d)
					u->cut = true;
			}
		}
		else if (v != u->parent) 
			u->low = min(u->low, v->d); //modify
	}
	u->color = "black";
	time++;
}

void bridge(Node* u) {
	time++;
	u->d = u->low = time;
	for (int i = 0; i < u->adj.size(); i++) {
		Node* v = u->adj[i];
		if (v->d==0) {
			v->parent = u;
			bridge(v);
			u->low = min(u->low, v->low);
			if (v->low == v->d) {
				cout << "There is a bridge between " << u->data << " and " << v->data << endl;
			}
		}
		else if (v != u->parent)
			u->low = min(v->d, u->low);//modify
	}
}

void dfs(vector<Node>& map) {
	while (1) {
		cout << "1:cutPoint\n2.bridge\n3.End\n";
		int cas;
		cin >> cas;
		time = 0;
		if (cas == 1) {
			cout << "cutPoint is: ";
			for (int i = 1; i < map.size(); i++) {
				map[i].cut = false;
				map[i].d = 0;
				map[i].parent = NULL;
				map[i].numChidren = 0;
			}
			for (int i = 1; i < map.size(); i++)
				if (map[i].d == 0) {
					cutPoint(&map[i]);
					if (map[i].numChidren > 1)
						map[i].cut = true;

				}
			for (int i = 1; i < map.size(); i++) {
				if (map[i].cut)
					cout << map[i].d << " ";
			}
			cout << endl;
		}
		else if (cas == 2) {
			for (int i = 1; i < map.size(); i++) {
				map[i].d = 0;
				map[i].parent = NULL;
			}
			for (int i = 1; i < map.size(); i++)
				if (map[i].d==0) {
					bridge(&map[i]);
				}
		}
		else
			break;
	}
}

int main() {
	int a, b;
	vector<Node> map;
	int Nodenum;
	cin >> Nodenum;
	for (int i = 0; i < Nodenum + 1; i++) {
		Node newN(i);
		map.push_back(newN);
	}
	while (cin >> a >> b) {
		if (a == -1 && b == -1) break;
		map[a].adj.push_back(&map[b]);
		map[b].adj.push_back(&map[a]);
	}
	dfs(map);
}