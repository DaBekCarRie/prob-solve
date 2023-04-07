#include<bits/stdc++.h>
using namespace std;

struct Order {
    int type; // 1 for buy, 2 for sell
    int price;
    int quantity;
};

struct BuyOrderCompare {
    bool operator()(const Order& o1, const Order& o2) const {
        return o1.price < o2.price;
    }
};

struct SellOrderCompare {
    bool operator()(const Order& o1, const Order& o2) const {
        return o1.price > o2.price;
    }
};

priority_queue<Order, vector<Order>, BuyOrderCompare> buy;
priority_queue<Order, vector<Order>, SellOrderCompare> sell;

int main(){
    int n, result = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        int type, price, quantity;
        cin >> type >> price >> quantity;
        if (type == 1){ // buy
            while (!sell.empty()){
                Order sell_now = sell.top();
                if (price >= sell_now.price){
                    if (sell_now.quantity > quantity){
                        result += price * quantity;
                        sell_now.quantity -= quantity;
                        quantity = 0;
                        sell.pop();
                        sell.push(sell_now);
                        break;
                    } else {
                        result += price * sell_now.quantity;
                        quantity -= sell_now.quantity;
                        sell.pop();
                    }
                } else {
                    break;
                }
            }
            if (quantity > 0){
                buy.push({type, price, quantity});
            }
        } else if (type == 2){ // sell
            while (!buy.empty()){
                Order buy_now = buy.top();
                if (buy_now.price >= price){
                    if (quantity < buy_now.quantity){
                        result += price * quantity;
                        buy_now.quantity -= quantity;
                        quantity = 0;
                        buy.pop();
                        buy.push(buy_now);
                        break;
                    } else {
                        result += price * buy_now.quantity;
                        quantity -= buy_now.quantity;
                        buy.pop();
                    }
                } else {
                    break;
                }
            }
            if (quantity > 0){
                sell.push({type, price, quantity});
            }
        }
    }
    cout << result << endl;
}