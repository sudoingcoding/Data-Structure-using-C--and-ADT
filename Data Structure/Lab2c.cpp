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
    int getQuantity() {
        return quantity;
    }
    string getName() {
        return name;
    }
    string getBrandName() {
        return brandName;
    }
    string getType() {
        return type;
    }
    void display() {
        cout << "Product id: " << id << endl << "Product name: " << name << endl << "Product brand name: " << brandName << endl << "Product type: " << type << endl << "Product price: " << price << endl << "Product quantity: " << quantity << endl;
    }

};
int main()
{
    cout << "Enter your product number" << endl;
    int num;
    cin >> num;
    product* p = new product[num];
    for (int i = 0; i < num; i++)
    {

        int id, price, quantity;
        string name, brandName, type;
        cout << "Enter your product id" << endl;
        cin >> id;
        cout << "Enter your product name" << endl;
        cin >> name;
        cout << "Enter your product brand name" << endl;
        cin >> brandName;
        cout << "Enter your product type" << endl;
        cin >> type;
        cout << "Enter your product price" << endl;
        cin >> price;
        cout << "Enter your product quantity" << endl;
        cin >> quantity;
        *(p + i) = product(id, name, brandName, type, price, quantity);
    }
    
    int total = 0;
    for (int i = 0; i < num; i++)
    {
        
            total += p[i].getPrice() * p[i].getQuantity();
    }
    cout << "Total asset: " << total << endl;
    delete[] p;
}

