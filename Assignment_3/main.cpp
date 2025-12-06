#include <ctime>
#include <iostream>
#include "pq.h"

class buy_order {
private:
    int buy_price;
    std::string buy_name;
public:
    buy_order(const int price, std::string& name) : buy_price(price), buy_name(std::move(name)) {}
    [[nodiscard]] int get_price() const { return buy_price; }
    [[nodiscard]] std::string get_name() const { return buy_name; }
};

class sell_order {
private:
    int sell_price;
    std::string sell_name;
public:
    sell_order(const int price, std::string& name) : sell_price(price), sell_name(std::move(name)) {}
    [[nodiscard]] int get_price() const { return sell_price; }
    [[nodiscard]] std::string get_name() const { return sell_name; }
};

void make_buy_orders(std::vector<buy_order>& vec, std::string name) {
    std::srand(std::time(nullptr));

    for (int i = 0; i <= 7; i++) {
        int price = rand() % (30 - 15 + 1) + 15;
        vec.emplace_back(price, name);
    }
}

void make_sell_orders(std::vector<sell_order>& vec, std::string name) {
    std::srand(std::time(nullptr));

    for (int i = 0; i <= 7; i++) {
        int price = rand() % (30 - 15 + 1) + 15;
        vec.emplace_back(price, name);
    }
}

int main(){

    std::vector<buy_order> buy_orders;

    make_buy_orders(buy_orders, "Erik Pendel");
    make_buy_orders(buy_orders, "Jarl Wallenburg");
    make_buy_orders(buy_orders, "Joakim von Anka");

    auto buy_comp = [] (const buy_order& a, const buy_order& b) {
        return a.get_price() < b.get_price();
    };

    pq<buy_order, decltype(buy_comp)> pq_buy_orders(buy_orders.begin(), buy_orders.end(), buy_comp);

    std::vector<sell_order> sell_orders;

    make_sell_orders(sell_orders, "Erik Pendel");
    make_sell_orders(sell_orders, "Jarl Wallenburg");
    make_sell_orders(sell_orders, "Joakim von Anka");

    auto sell_comp = [] (const sell_order& a, const sell_order& b) {
      return a.get_price() < b.get_price();
    };

    pq<sell_order, decltype(sell_comp)> pq_sell_orders(sell_orders.begin(), sell_orders.end(), sell_comp);

    while (!pq_buy_orders.empty() && !pq_sell_orders.empty()) {
        const auto& sell_top = pq_sell_orders.top();
        const auto& buy_top  = pq_buy_orders.top();

        if (sell_top.get_price() <= buy_top.get_price()) {
            std::cout << sell_top.get_name() << " säljer för "
                      << sell_top.get_price() << " kr till "
                      << buy_top.get_name()  << " som köper för "
                      << buy_top.get_price() << " kr\n";
            pq_sell_orders.pop();
            pq_buy_orders.pop();
        } else {
            pq_sell_orders.pop();
        }
    }

    return 0;
}