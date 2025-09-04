#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
    std::vector<int> data;                    // элементы
    std::unordered_map<int,int> pos;          // val -> индекс в data
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = (int)data.size();
        data.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) return false;
        int idx = it->second;          // индекс удаляемого
        int lastVal = data.back();     // последний элемент

        // Переносим последний на место удаляемого
        data[idx] = lastVal;
        pos[lastVal] = idx;

        data.pop_back();
        pos.erase(it);
        return true;
    }

    int getRandom() {
        int idx = std::rand() % data.size();
        return data[idx];
    }
};
