#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct link_node {
	link_node* next;
	int _data;
};

/*class list {
public:
	void insert(int data) {
		link_node* temp = new link_node;
		temp->_data = data;
		temp->next = nullptr;
		if (ptr != nullptr) {
			link_node* p = ptr;
			while (p->next != NULL)
				p = p->next;

			p->next = temp;
		}
		else
			ptr = temp;
	}
	void output() {
		link_node* p = ptr;
		while (p != nullptr) {
			cout << p->_data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void secondQ() {
		link_node* p = ptr;
		while (p != nullptr) {
			int ans = 0;
			if (p->next != NULL) {
				link_node* pNext = p->next;
				while (pNext != NULL) {
					if (pNext->_data > p->_data&& pNext->_data > ans)
						ans = pNext->_data;
					pNext = pNext->next;
				}
			}
			cout << ans << " ";
			p = p->next;
		}
	}
private:
	link_node* ptr = nullptr;
};*/

int main() {
	list<int> list1;
	vector<int> odd, even;
	int num;
	/*while (cin >> num, num) { //第一題
		if (num % 2)
			odd.push_back(num);
		else
			even.push_back(num);
	}
	for (int i = 0; i < odd.size(); i++)
		list1.insert(odd[i]);
	for (int i = 0; i < even.size(); i++)
		list1.insert(even[i]);
	list1.output();*/

	while (cin >> num, num) { //第二題
		//list1.insert(num);
		list1.push_back(num);
	}
	cout << *list1.begin() << " " << list1.front() << endl;
	//list1.secondQ();
}