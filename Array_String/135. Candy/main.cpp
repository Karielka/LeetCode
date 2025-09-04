#include <iostream>
#include <vector>
#include <algorithm>

static void print_vec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]";
}

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int len = ratings.size();
        if (len < 2) return 1;
        if (len == 2) {
            if (ratings[0] == ratings[1]) return 2;
            else return 3;
        }
        int candys_count = 0;
        std::vector <int> candys(len, 1); // Массив конфет (отображает только конфеты при росте) + сохраняет пиковую точку рейтинга

        // Рост в начале, в противном случае ничего не делаем (оставляем 1)
        if ((ratings[0] < ratings[1]) && (ratings[1] < ratings[2])) {
            candys[1] =  2;
        }

        int spad_len = 1; // Длина убывающей последовательности
        int spad_count = 0; // Сумма ариф. прогрессии длины span_len с a1 = 1, d = 1
        bool decrement = false; // Наличие пика
        int decrement_val = 0; // Значение конфет в пике (candys[i])

        for (int i = 1; i < len; i++) {
            // print_vec(candys);
            // std::cout << "i = " << i << " ratings[i] = " << ratings[i] << std::endl;
            if ((ratings[i - 1] > ratings[i])) {
                // Спад (считаем длину спада)
                spad_len += 1;
            } 
            else {
                // Рост (обработка спада + накопление)
                if (spad_len > 1) {
                    spad_count = ((1 + spad_len) * spad_len / 2 - spad_len);
                    // std::cout << "spad_len = " << spad_len << " " << "spad_count = " << spad_count << std::endl;
                    candys_count += spad_count;
                    // Пик снимается и в росте и в убывании (убираем лишнее с меньшего склона)
                    if (decrement) {
                        candys_count -= std::min(spad_len - 1, decrement_val - 1);
                        decrement = false;
                    }
                }
                spad_len = 1;
                if (ratings[i - 1] < ratings[i]) {
                    // std::cout << "Кладём конфеты: " <<  candys[i - 1] << std::endl;
                    candys[i] = candys[i - 1] + 1;
                }
            }  
            // Проверка на пик
            if (i + 1 < len)
                if ((ratings[i - 1] < ratings[i]) && (ratings[i] > ratings[i + 1])) {
                    decrement = true;
                    decrement_val = candys[i];
                }
        }
        // Обработка конца последовательности
        candys_count += ((1 + spad_len) * spad_len / 2 - spad_len);
        if (decrement) {
            candys_count -= std::min(spad_len - 1, decrement_val - 1);
            decrement = false;
        }
        
        for (const auto& t: candys) {
            candys_count += t;
        }
        return candys_count;
    }
};


int main() {
    Solution pass;
    std::vector<int> vect;
    // vect = {1, 0, 2}; // 5
    // vect = {1,3,2,2,1}; // 7
    // vect = {1,2,2}; // 4
    // vect = {7, 7, 6, 5, 4, 3}; // 16
    // vect = {1,2,3,1,0}; // 9
    // vect = {1,3,4,5,2}; // 11
    // vect = {1,6,10,8,7,3,2}; // 18
    vect = {10,10,10,10,10,10}; // 6

    std::cout << pass.candy(vect);
}