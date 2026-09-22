#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<climits>
#include<numeric>

using namespace std;
//abstract  main product class
class Burger{
    public:
    virtual void prepare()=0;
    ~Burger(){}
};

//concrete products
class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout<<"This is a basic burger"<<endl;
    }
};

class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout<<"This is a Standard burger"<<endl;
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"This is a premium burger"<<endl;
    }
};

//factory class
class BurgerFactory{
    public:
    Burger*createBurger(string& type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
       else  if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid choice"<<endl;
            return nullptr;

        }

    }
};
int main(){
    string type="standard";

    BurgerFactory*myBurgerFactory=new BurgerFactory();

    Burger*Burger=myBurgerFactory->createBurger(type);

    Burger->prepare();
    


    return 0;
}