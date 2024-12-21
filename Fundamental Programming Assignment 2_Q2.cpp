#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>
#include <functional>
#include <iomanip> 
using namespace std;


void getInput(vector<vector<string>>& intake); //read inputs from an input file name 'input.txt' (Task 1)
void calTotal(vector<vector<string>>& intake,int &total); //calculates the sum of elements of an array (Task 2)
pair<string, string> getLowest(vector<vector<string>>& intake, string a); //finds the index with the lowest value in an array (Task 3)
pair<string, string> getHighest(vector<vector<string>>& intake, string a); //finds the index with the highest value in an array (Task 4)
void Output(vector<vector<string>>& intake,string TotalInt,string TotalEnr,string TotalOut,string LowestInt,string HighestInt,string LowestEnr,string HighestEnr,string LowestOut,string HighestOut,string AvgInt,string AvgEnr,string AvgOut,int IntRange,int EnrRange,int OutRange); //read inputs from the input file and print it into the output file named “output.txt” (Task 5)
pair<string, string> SumNAvg(vector<vector<string>>& intake, string a); //calculates the total and average of students' intake, enrolment, and output (Task 6)
pair<string, string> LowHighest(vector<vector<string>>& intake, string a, function<pair<string, string>(vector<vector<string>>&, string)> func); // finds the highest and lowest number of the student's intake, enrolment, and output


void getInput(vector<vector<string>>& intake) {
    string line;
    try {
        ifstream file("input1.txt");
        if (!file) {
            throw runtime_error("Sorry, input file does not exist! \nPress any key to continue . . .");
        }
        while (getline(file, line)) {
            vector<string> Row;
            istringstream SeperateValue(line);
            string value;
            while (SeperateValue >> value) {
                Row.push_back(value);
            }
            if (!Row.empty()) {
                intake.push_back(Row);
            }
        }
        file.close();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void calTotal(vector<vector<string>>& intake,int &total) {
    for (const auto& row : intake) {
        for (const auto& val : row) {
            total++;
        }
    }
    cout << "Total: " << total << endl;
}

pair<string, string> getLowest(vector<vector<string>>& intake, string a) {
    int Lowest = numeric_limits<int>::max();
    string record;
    if (a == "Lowest Intake"){
        int index = 1;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (num < Lowest) {
                        Lowest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Lowest)){
                record = intake[i][0];
            }
        }
    }

    if (a == "Lowest Enrolment"){
        int index = 2;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (num < Lowest) {
                        Lowest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Lowest)){
                record = intake[i][0];
            }
        }
    }

    if (a == "Lowest Output"){
        int index = 3;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (num < Lowest) {
                        Lowest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Lowest)){
                record = intake[i][0];
            }
        }
    }
   
   record =  to_string(Lowest) + " " + '(' + record + ')';
   return make_pair(record,to_string(Lowest));   
 
   
} 

pair<string, string> getHighest(vector<vector<string>>& intake, string a) {
    int Highest = numeric_limits<int>::min();
    string record;
    if (a == "Highest Intake"){
        int index = 1;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (Highest < num) {
                        Highest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Highest)){
                record = intake[i][0];
            }
        }
    }

    if (a == "Highest Enrolment"){
        int index = 2;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (Highest < num) {
                        Highest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Highest)){
                record = intake[i][0];
            }
        }
    }

    if (a == "Highest Output"){
        int index = 3;
        for (const auto& row : intake) {
            if (row.size() > index) { 
                try {
                    int num = stoi(row[index]); 
                    if (Highest < num) {
                        Highest = num;
                    }
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
        for (int i = 0; i < intake.size(); i++){
            if (intake[i][index]==to_string(Highest)){
                record = intake[i][0];
            }
        }
    }
   
   record =  to_string(Highest) + " " + '(' + record + ')';
   return make_pair(record,to_string(Highest));   
} 

pair<string, string> LowHighest(vector<vector<string>>& intake, string a, function<pair<string, string>(vector<vector<string>>&, string)> func) {
    return func(intake, a);
}

pair<string, string> SumNAvg(vector<vector<string>>& intake, string a) {
    int final = 0;
    double avg = 0.0;
    int count = 0;

    if (a == "Total n Avg Intake") {
        int index = 1;
        for (const auto& row : intake) {
            if (row.size() > index) {
                try {
                    final += stoi(row[index]);
                    count++;
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
    }

    if (a == "Total n Avg Enrolment") {
        int index = 2;
        for (const auto& row : intake) {
            if (row.size() > index) {
                try {
                    final += stoi(row[index]);
                    count++;
                } catch (const invalid_argument& e) {
                    
                }
            }
        }
    }

    if (a == "Total n Avg Output") {
        int index = 3;
        for (const auto& row : intake) {
            if (row.size() > index) {
                try {
                    final += stoi(row[index]);
                    count++;
                } catch (const invalid_argument& e) {

                }
            }
        }
    }

    if (count > 0) {
        avg = static_cast<double>(final) / count;
    }

    ostringstream Avg;
    Avg << fixed << setprecision(2) << avg;

    return make_pair(to_string(final), Avg.str());
}

void Output(vector<vector<string>>& intake, string TotalInt, string TotalEnr, string TotalOut, string LowestInt, string HighestInt, string LowestEnr, string HighestEnr, string LowestOut, string HighestOut, string AvgInt, string AvgEnr, string AvgOut, int IntRange, int EnrRange, int OutRange) {
    
    ofstream file1("output.txt");
    if (!file1) {
        throw runtime_error("Sorry, output file does not exist! \nPress any key to continue . . .");
    }
    file1 << setw(56) << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
    file1 << setw(46) << "IN PUBLIC UNIVERSITIES (2015)" << endl;
    file1 << '\n';
    file1 << string(65, '-') << endl;
    file1 << setw(15) << "University" << setw(15) << "Intake" << setw(15) << "Enrolment" << setw(15) << "Output" << endl;
    file1 << string(65, '-') << endl;
    for (const auto& row : intake) {
        for (const auto& val : row) {
            file1 << setw(15) << val;
        }
        file1 << endl;
    }
    
    file1 << string(65, '-') << endl;
    file1 << setw(15) << "TOTAL" << setw(15) << TotalInt << setw(15) << TotalEnr << setw(15) << TotalOut << endl;
    file1 << setw(15) << "AVERAGE" << setw(15) << AvgInt << setw(15) << AvgEnr << setw(15) << AvgOut << endl;
    file1 << string(65, '-') << endl;

    file1 << '\n';
    file1 << "THE LOWEST NUMBER OF STUDENTS' INTAKE " << setw(5) << "= " << LowestInt << endl;
    file1 << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT " << setw(2) << "= " << LowestEnr << endl;
    file1 << "THE LOWEST NUMBER OF STUDENTS' OUTPUT " << setw(5) << "= " << LowestOut << endl;
    file1 << '\n';
    file1 << "THE HIGHEST NUMBER OF STUDENTS' INTAKE " << setw(5) << "= " << HighestInt << endl;
    file1 << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT " << setw(2) << "= " << HighestEnr << endl;
    file1 << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT " << setw(5) << "= " << HighestOut << endl;
    file1 << '\n';
    file1 << "THE RANGE OF STUDENTS' INTAKE " << setw(5) << "= " << IntRange << endl;
    file1 << "THE RANGE OF STUDENTS' ENROLMENT " << setw(2) << "= " << EnrRange << endl;
    file1 << "THE RANGE OF STUDENTS' OUTPUT " << setw(5) << "= "  << OutRange << endl;
    file1 << '\n';
    file1 << string(65, '-') << endl;

    file1.close();
}


int main() {
    vector<vector<string>> intake;
    int total = 0;
    string LowestInt,HighestInt,LowestOut,HighestOut,LowestEnr,HighestEnr,TotalInt,AvgInt,TotalEnr,AvgEnr,TotalOut,AvgOut;
    int HighIntForRan,LowIntForRan,HighEnrForRan,LowEnrForRan,HighOutForRan,LowOutForRan,IntRange,EnrRange,OutRange;

    getInput(intake);


    pair<string, string> result = LowHighest(intake, "Lowest Enrolment", getLowest);
    LowestEnr = result.first;
    LowEnrForRan = stoi(result.second);
    result = LowHighest(intake, "Highest Enrolment", getHighest);
    HighestEnr = result.first;
    HighEnrForRan = stoi(result.second);
    result = LowHighest(intake, "Lowest Intake", getLowest);
    LowestInt = result.first;
    LowIntForRan = stoi(result.second);
    result = LowHighest(intake, "Highest Intake", getHighest);
    HighestInt = result.first;
    HighIntForRan = stoi(result.second);
    result = LowHighest(intake, "Lowest Output", getLowest);
    LowestOut = result.first;
    LowOutForRan = stoi(result.second);
    result = LowHighest(intake, "Highest Output", getHighest);
    HighestOut = result.first;
    HighOutForRan = stoi(result.second);
    result = SumNAvg(intake, "Total n Avg Intake");
    TotalInt = result.first;
    AvgInt = result.second;
    result = SumNAvg(intake, "Total n Avg Enrolment");
    TotalEnr = result.first;
    AvgEnr = result.second;
    result = SumNAvg(intake, "Total n Avg Output");
    TotalOut = result.first;
    AvgOut = result.second;
    IntRange = HighIntForRan - LowIntForRan;
    EnrRange = HighEnrForRan - LowEnrForRan;
    OutRange = HighOutForRan - LowOutForRan;
    Output(intake,TotalInt,TotalEnr,TotalOut,LowestInt,HighestInt,LowestEnr,HighestEnr,LowestOut,HighestOut,AvgInt,AvgEnr,AvgOut,IntRange,EnrRange,OutRange);
    cout << "Output file has been created successfully!" << endl;
    return 0;
}