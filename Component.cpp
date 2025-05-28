#include <string>
#include <iostream>
using namespace std;
class Component{
    private:

        bool built;
        string Component_name;
    public:
        void Set_built();
        bool Get_built() const;

        void Set_name(string n);
        string Get_name();
        Component(string n);
        Component();
        Component(string n,bool b);
        //Overrides the << operator to output the class into the file
        friend ostream& operator<<(ostream& os, const Component& comp){
            os << (comp.built ? "Yes" : "No");
            return os;

        };
        //Overrides the >> operator to grab component status
        friend istream& operator>>(istream& is,Component& comp){
            string buildStatus;
            is >> buildStatus;
            if(buildStatus == "Yes"){
                comp.built = true;
            }else{
                comp.built = false;
            }
            return is;
        };
};
void Component::Set_built(){
    if(!built){
        built = true;
        cout << Component_name <<" is now built" << endl;
    }
};
bool Component::Get_built() const{
    return built;
};
void Component::Set_name(string n){
    Component_name = n;
};
string Component::Get_name(){
    return Component_name;
};
Component::Component(string n){
    Component_name = n;
    built = false;

};
Component::Component(){
    Component_name = "N/A";
    built = false;

};
Component::Component(string n, bool b){
    Component_name = n;
    built=b;
}


