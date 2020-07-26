#include <iostream>
#include <vector>

template <class T>
class heap {
   private:
    vector<T> h_obj;

   public:
    bool insert(T ele) {
        h_obj.push_back(ele);
        repair(h_obj.size() - 1);
    }

    void repair(vector<T>::size_type num) {
        T lchild, rchild, mx;
        if ((2 * num + 1) < h_obj.size()) {
            lchild = h_obj[2 * num];
            rchild = h_obj[2 * num + 1];
			mx = maz(lchild, rchild);
			if()
        } else if (2 * num < h_obj.size()) {
            lchild = h_obj[2 * num];
			
        }
    }
};

using namespace std;

int main() {
    int n;
    cin >> n;
}