//Object Oriented Programming With Class And Object
#include<iostream>
using namespace std;
class product
{
private:
    int id;
    string name;
    string brandName;
    string type;
    int price;
    int quantity;

public:
    product() {}
    product(int id, string name, string brandName, string type, int price, int quantity)
    {
        this->id = id;
        this->name = name;
        this->brandName = brandName;
        this->type = type;
        this->price = price;
        this->quantity = quantity;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setBrandName(string brandName)
    {
        this->brandName = brandName;
    }
    void setType(string type)
    {
        this->type = type;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    int getPrice() {
        return price;
    }
    string getName() {
        return name;
    }
    void display() {
        cout << "product name: " << name << endl << "product price: " << price << endl;
    }

};
int main()
{
    cout << "Enter how many product" << endl;
    int num;
    cin >> num;
    product p[100];
    for (int i = 0; i < num; i++)
    {

        int id, price, quantity;
        string name, brandName, type;
        product pr;
        cout << "Enter your product id" << endl;
        cin >> id;
        pr.setId(id);
        cout << "Enter your product name" << endl;
        cin >> name;
        pr.setName(name);
        cout << "Enter your product brand name" << endl;
        cin >> brandName;
        pr.setBrandName(brandName);
        cout << "Enter your product type" << endl;
        cin >> type;
        pr.setType(type);
        cout << "Enter your product price" << endl;
        cin >> price;
        pr.setPrice(price);
        cout << "Enter your product quantity" << endl;
        cin >> quantity;
        pr.setQuantity(quantity);
        p[i] = pr;
    }
    for (int i = 0; i < num; i++)
    {
        if (p[i].getPrice() > 40)
            p[i].display();
    }
}

