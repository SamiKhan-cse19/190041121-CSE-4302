#include <iostream>
#include <string>
using namespace std;

void drawLine(int, char);

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bedSize;
public:
    Bed() : Furniture(0.0f, 0.0f, Material::Wood){
    }
    Bed(double p, double d, Material m, BedSize bs) : Furniture(p, d, m), bedSize(bs) {

    }
    void setBedSize(BedSize bSize) {
        bedSize = bSize;
    }
    string getBedSize()
    {
        if(bedSize==BedSize::Double)
            return string("Double");
        else if(bedSize==BedSize::Single)
            return string("Single");
        else if(bedSize==BedSize::SemiDouble)
            return string("Semi-Double");
        else
            return string("");
    }
    void productDetails()
    {
        drawLine(50, '-');
        cout<<"RegularPrice: "<<price<<endl;
        cout<<"Discounted Price: "<<price - price*discount*0.01<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Bed Size: "<<getBedSize()<<endl;
        drawLine(50, '#');
    }
};

enum class SofaSize {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    Furniture *f;
    SofaSize sofaSize;

public:
    Sofa() : Furniture(0.0f, 0.0f, Material::Wood) {
    }
    Sofa(double p,double d,Material m, SofaSize sn) : Furniture(p, d, m), sofaSize(sn) {

    }
    void setSofaSize(SofaSize s) {
        sofaSize = s;
    }
    string getSofaSize()
    {
        if(sofaSize==SofaSize::Five)
            return string("Five");
        else if(sofaSize==SofaSize::Four)
            return string("Four");
        else if(sofaSize==SofaSize::Three)
            return string("Three");
        else if(sofaSize==SofaSize::Two)
            return string("Two");
        else if(sofaSize==SofaSize::One)
            return string("One");
        else
            return string("");
    }
    void a()
    {
        f = new Bed();
    }
    void productDetails()
    {
        drawLine(50, '-');
        cout<<"RegularPrice: "<<price<<endl;
        cout<<"Discounted Price: "<<price - price*discount*0.01<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Sofa Seats: "<<getSofaSize()<<endl;
        drawLine(50, '#');
    }
    ~Sofa ()
    {
        delete f;
    }
};

enum class AlmirahSize {Two, Three, Four};
class Almirah:public Furniture
{
private:
    AlmirahSize almirahSize;
public:
    Almirah() : Furniture(0.0f, 0.0f, Material::Wood) {
    }
    Almirah(double p,double d,Material m, AlmirahSize dr) : Furniture(p, d, m), almirahSize(dr) {

    }
    void setAlmirahSize(AlmirahSize d) {
        almirahSize = d;
    }
    string getAlmirahSize()
    {
        if(almirahSize==AlmirahSize::Two)
            return string("Two");
        else if(almirahSize==AlmirahSize::Three)
            return string("Three");
        else if(almirahSize==AlmirahSize::Four)
            return string("Four");
        else
            return string("");
    }
    void productDetails()
    {
        drawLine(50, '-');
        cout<<"RegularPrice: "<<price<<endl;
        cout<<"Discounted Price: "<<price - price*discount*0.01<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Door: "<<getAlmirahSize()<<endl;
        drawLine(50, '#');
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures);


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

//    /**
////        task 2
////        So that following lines can be executed without error
////
////        task 3 (Modify productDetails)
////    */
//    f_list[2]->setDiscountPercentage(30);
//    for(int i=0; i<4; i++)
//    {
//        f_list[i]->productDetails();
//    }
//
//    /**task 2 ends here*/
//    /**task 3 ends here*/
//
//    /**task 4
//    So that following lines can be executed without error
//    */
//    sort_furniture_discount(f_list,4);
//    for(int i=0; i<4; i++)
//    {
//        f_list[i]->productDetails();
//    }
//    /**task 4 ends here*/

    for(int i=0; i<4; i++) delete f_list[i];
}

void drawLine(int n, char c) {
    for(int i=0; i<n; i++) cout<<c;
    cout<<endl;
}

