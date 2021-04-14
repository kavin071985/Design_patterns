#include <vector>
#include <iostream>
#include <string>

class Payment
{
    // enum 
    //private double amount;
    //private String paymode;
    //private boolean status;
public:
    virtual ~Payment() = default;
    virtual void pay(double amount) {}

};

class PayPalPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "PayPalPayment. Amount = " << amount;
    }
};

class CreditCardPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "CreditCardPayment. Amount = " << amount;
    }
};

class UPIPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "UPIPayment. Amount = " << amount;
    }
};

class CartItem
{
private:
    std::string description, orderDate, deliveryDate;
    double cost;

public:
    void setCost(double c)
    {
        cost = c;
    }

    double getCost()
    {
        return cost;
    }
};

class Customer
{
private:
    std::string name, address;
};

// ShoppingStrategy class represents the cart 
class ShoppingStrategy
{
    //Payment paymentMethod; // composition
private: std::vector<CartItem> listItems;

       double getTotalCost()
       {
           double total = 0.0;
           for (CartItem item : listItems)
           {
               total += item.getCost();
           }
           return total;
       }
public:
    void addItem(CartItem& item)
    {
        listItems.push_back(item);
    }
    void checkout(Payment& p)
    {
        p.pay(this->getTotalCost()); // strategy
    }
};

int main()
{
    CartItem soap;
    soap.setCost(100);

    CartItem shampoo;
    shampoo.setCost(50);

    CartItem conditioner;
    conditioner.setCost(25);

    ShoppingStrategy cart;
    cart.addItem(soap);
    cart.addItem(soap);
    cart.addItem(shampoo);
    cart.addItem(conditioner);
    cart.addItem(conditioner);
    cart.addItem(conditioner);

    //Payment paypal = new PayPalPayment();
    UPIPayment upi;
    
    cart.checkout(upi);

    return 0;
}
