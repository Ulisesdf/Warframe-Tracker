#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>
#include <iostream>
#include <fstream>
#include "Warframe.cpp"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
static int Completed_frames = 0;
// Imports Warframe data from the text file and counts the amount of completed Warframes
void Import_frames(ifstream& file,map<string,Warframe>& a){
    Warframe warframe;
    while(file >> warframe){
        a.insert({warframe.Get_warframe_name(),warframe});

    };
    file.close();
    for(auto& pair:a){
        if(pair.second.Is_done()){
            Completed_frames++;
        }
    };
};
void Export_frames(ofstream& file,const map<string,Warframe>& a){
    int count = 0;
    int size = a.size();
    for(auto& pair:a){
        file << pair.second << endl;
    };

    file.close();
};
// Displays a list of the complete Warframes and Incomplte Warframes
void Display_warframes(const map<string,Warframe>& f){
    cout << "Completed Warframes: ";
    int size = f.size();
    int count = 0;
    for(auto& pair:f){
        if(pair.second.Is_done()){
            cout << pair.first;
            if(count < Completed_frames - 1){
                cout << ", ";
            }
            count++;
        }
        
    }
    count = 0;
    cout << endl << endl << "Incomplete Warframes: ";
    for(auto& pair:f){
        if(!pair.second.Is_done()){
            cout << pair.first;
            if(count < (size - Completed_frames) - 1){
                cout << ", ";
            }
            count++;
        }
    }          
};


int main(){
    cout << "Current directory: " << fs::current_path() << endl;
    map<string,Warframe> Frames;
    // opens the file to read from
    ifstream inputFile("C:/Users/14086/Desktop/WarframeTracker/WarframeData.txt");

    // If file cannot be opened
    if(!inputFile){
        cout <<"Error the input file could not be opened." << endl;
        return 1;
    }
    Import_frames(inputFile,Frames);

    

    
    bool keep_going = true;

    while(keep_going){
        int choice;
        cout << endl << "(1) To add a new Warframe" << endl << "(2) To check Warframe status" << endl << "(3) To edit a Warframe" << endl << "(4) To display the list of Warframes" << endl
         << "(0) To Exit" << endl;
        cout << "choice: ";
        cin >> choice;
        cout << endl;

        //Stops the loop
        if(choice == 0){
            keep_going = false;
        // Adds a new Warframe to the map for later use
        }else if(choice == 1){
            string name;
            cout << "Enter a Warframe you want to add: ";
            cin >> name;
            Frames.insert({name,Warframe(name)});
            // Prints the list of added Warframes          
        }
        // Checks to see if the Warframe is done or what parts are missing   
        else if(choice == 2){
            string choice;
            cout << "Which Warframe do you want to check: ";
            cin >> choice;

            Frames.at(choice).status();
        }
        // Updates the status of any of the components to them being built
        else if(choice == 3){
            int o_choice;
            string name;
            cout << "Enter the Warframe you want to edit: ";
            cin >> name;
            cout << endl << "(1) To change Blueprint status" << endl << "(2) To change Nueroptics status" << endl << "(3) To change Chasis status" << endl << "(4) To change Systems status"<< endl << "(5) To set the whole Waframe to built"<< endl << "(0) To go back" << endl;
            cout << "Choice: ";
            cin >> o_choice;
            if(o_choice == 1){
                Frames.at(name).Get_blueprint().Set_built();
            }
            if(o_choice == 2){
                Frames.at(name).Get_nueroptics().Set_built();
            }
            if(o_choice == 3){
                Frames.at(name).Get_chasis().Set_built();
            }
            if(o_choice == 4){
                Frames.at(name).Get_systems().Set_built();
            }
            if(o_choice == 5){
                Frames.at(name).Set_whole_built();
                cout << name << " is complete." << endl;
            }
        }
        else if(choice == 4){
            Display_warframes(Frames);
        }

    };
    ofstream outputFile("C:/Users/14086/Desktop/WarframeTracker/WarframeData.txt");
    Export_frames(outputFile,Frames);



   return 0;
};
