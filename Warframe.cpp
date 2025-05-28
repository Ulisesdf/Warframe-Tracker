#include <string>
#include <iostream>
#include <map>
#include "Component.cpp"
using namespace std;
class Warframe{
    private:
        string Warframe_name;
        Component blueprint;
        Component nueroptics;
        Component chasis;
        Component systems;
    public:
        void Set_warframe_name(string n);
        string Get_warframe_name();
        void point();
        void status();
        // Constructors
        Warframe(string name);
        Warframe();
        void Print_component_name();
        //Gets the components so we can edit it
        Component& Get_blueprint();
        Component& Get_nueroptics();
        Component& Get_chasis();
        Component& Get_systems();
        void Print_missing();
        void Set_whole_built();
        bool Is_done() const;
        /*
            Outputs the Warframe name and the component satus by overriding the << operator
            Warframe name,Blueprint,Nueroptics,Chasis,Systems
        */
       friend ostream& operator<<(ostream& os,const Warframe& frame){
            os << frame.Warframe_name <<' '<< frame.blueprint <<' '<< frame.nueroptics <<' '<< frame.chasis << ' '<< frame.systems << endl;
            return os;
       };
       // Grabs the frame data by overriding the >> data
       friend istream& operator>>(istream& is, Warframe& frame){
            is >> frame.Warframe_name >> frame.blueprint >> frame.nueroptics >> frame.chasis >> frame.systems;
            return is;
       };
        

};
void Warframe::Set_warframe_name(string n){
    Warframe_name = n;
};
string Warframe::Get_warframe_name(){
    return Warframe_name;
}
void Warframe::point(){
    cout << Warframe_name  << endl;
};
void Warframe::status(){
    if(blueprint.Get_built() && nueroptics.Get_built() && chasis.Get_built() && systems.Get_built()){
        cout << Warframe_name << " is fully built." << endl;
        
    }else{
        cout << Warframe_name << " is not fully built." << endl;
        Print_missing();

        
    };
// Constructor
}
Warframe::Warframe(string name){
    Warframe_name = name;
    blueprint = Component("Blueprint");
    nueroptics = Component("Nueroptics");
    chasis = Component("Chasis");
    systems = Component("Systems");
};
Warframe::Warframe(){
    Warframe_name="N/A";
    blueprint = Component("Blueprint");
    nueroptics = Component("Nueroptics");
    chasis = Component("Chasis");
    systems = Component("Systems");
};
//Prints the component name
void Warframe::Print_component_name(){
    cout << blueprint.Get_name() << endl;
};
//returns blueprint component
Component& Warframe::Get_blueprint(){
    return blueprint;
};
//returns nueroptics component
Component& Warframe::Get_nueroptics(){
    return nueroptics;
};
//returns chasis component
Component& Warframe::Get_chasis(){
    return chasis;
};
//returns systems component
Component& Warframe::Get_systems(){
    return systems;
};
//Prints the list of missing components
void Warframe::Print_missing(){
    map<string,Component> Parts = {{"Blueprint",blueprint},{"Nueroptics",nueroptics},{"Chasis",chasis},{"Systems",systems}};
    cout << "Components missing: ";
    int size = Parts.size();
    int count = 0;
    for(auto& pair:Parts){
        if(!pair.second.Get_built()){
            cout << pair.first;
            if(count < size-1){
                cout << ", ";
            }
        }
        count++;
    }
};
// Sets the whole warframe to be built
void Warframe::Set_whole_built(){
    blueprint.Set_built();
    nueroptics.Set_built();
    chasis.Set_built();
    systems.Set_built();
};

 bool Warframe::Is_done() const {
    return(blueprint.Get_built() && nueroptics.Get_built() && chasis.Get_built() && systems.Get_built());
};

 



