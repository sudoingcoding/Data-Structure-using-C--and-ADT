#include <iostream>
using namespace std;
class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle(){}
    Rectangle(double height, double width) {
        this->height = height;
        this->width = width;
    }
    void setHeight(double height) {
        this->height = height;
    }
    void setWidth(double width) {
        this->width = width;
    }
    double getHeight() {
        return height;
    }
    double getWidth() {
        return width;
    }
    void displayArea() {
        double area = height * width;
        cout << "Area: " << area<<endl;
    }
};
int main()
{
    
    double height, width;
    cout << "Enter height:" << endl;
    cin >> height;
    cout << "Enter width:" << endl;
    cin >> width;
    Rectangle r;
    r.setHeight(height);
    r.setWidth(width);
    r.displayArea();

    Rectangle* pR = new Rectangle;
    cout << "Enter height:" << endl;
    cin >> height;
    cout << "Enter width:" << endl;
    cin >> width;
    pR->setHeight(height);
    pR->setWidth(width);
    pR->displayArea();
    delete pR;

    Rectangle arrayR[100];
    int length;
    cout << "Enter array length:" << endl;
    cin>> length;
    for (int i = 0; i < length; i++) {
        cout << "Enter height:" << endl;
        cin >> height;
        arrayR[i].setHeight(height);
        cout << "Enter width:" << endl;
        cin >> width;
        arrayR[i].setWidth(width);
    }

    for (int i = 0; i < length; i++) { 
        cout << "Area for rectangle " << i + 1 << endl;
        arrayR[i].displayArea();
    }

    cout << "Enter array length:" << endl;
    cin >> length;
    Rectangle* pArrayR = new Rectangle[length];
    for (int i = 0; i < length; i++) {
        cout << "Enter height:" << endl;
        cin >> height;
        (pArrayR+i)->setHeight(height);
        cout << "Enter width:" << endl;
        cin >> width;
        (pArrayR + i)->setWidth(width);
    }
    for (int i = 0; i < length; i++) {
        cout << "Area for rectangle " << i + 1 << endl;
        (pArrayR + i)->displayArea();
    }
    delete[] pArrayR;
}
