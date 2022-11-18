#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

struct Node {
	Node(int a) {
		data = a;
	}
	int d;
	int low;
	vector<Node*> adj;
	int data;
};

int time; stack<Node*> stac; set<Node*> Set; int coun = 0;

void SC(Node* u) {
	time++;
	u->d = u->low = time;
	Set.insert(u);
	stac.push(u);
	for (int i = 0; i < u->adj.size(); i++) {
		if (u->adj[i]->d == 0)
		{
			SC(u->adj[i]);
			u->low = min(u->low, u->adj[i]->low);
		}
		else if (Set.count(u->adj[i]))
			u->low = min(u->low, u->adj[i]->d);
	}
	if (u->low == u->d) {
		cout << ++coun << ": ";
		Node* w;
		do
		{
			w = stac.top();
			Set.erase(w);
			stac.pop();
			cout << w->data << " ";
		} while (w != u);
		cout << endl;
	}
}

void dfs(vector<Node>& map) {
	for (int i = 1; i < map.size(); i++)
		map[i].d = 0;
	time = 0;
	while (!stac.empty())
		stac.pop();
	Set.clear();
	for (int i = 1; i < map.size(); i++)
		if (map[i].d == 0)
			SC(&map[i]);
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
	}
	dfs(map);
}