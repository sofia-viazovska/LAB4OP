#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

int sum1(vector<int> args) {
    int sum=0;
    for (auto i=0; i<args.size(); i++) {
        sum+=args[i];
    }
    return sum;
}

int sum2(vector<int> args) {
    int sum=0;
    for (int i : args) {
        sum+=i;
    }
    return sum;
}
int sum3(vector<int> args) {
    int sum=0, i=0;
    while (i<args.size()) {
        sum+=args[i];
        i++;
    }
    return sum;
}
int sum4(vector<int> args) {
    int sum=0, i=0;
    if (args.size()==0) {
        return 0;
    }
    do {
        sum+=args[i];
        i++;
    } while (i<=args.size());
    return sum;
}

int sum5(vector<int> args) {
    return accumulate(args.begin(), args.end(), 0);
}

int max(vector<vector<int>>& arr){
    int mx=0;
    for (const auto& row : arr) {
        for (int val : row) {
            if (val > mx) {
                mx = val;
            }
        }
    }
    return mx;
}

unordered_map<string, int> ages(const map<string, pair<int, int>>& persons) {
    unordered_map<string, int> result;
    for (const auto& person : persons) {
        const string& name = person.first;
        int born = person.second.first;
        int died = person.second.second;
        result[name] = died - born;
    }
    return result;
}


int main() {
    //Завдання 1
    cout<<"Варіант 1"<<endl;
    cout<<sum1({1, 2, 3})<<endl; // 6
    cout<<sum1({0})<<endl;       // 0
    cout<<sum1({})<<endl;        // 0
    cout<<sum1({1, -1, 1})<<endl; // 1
    cout<<sum1({10, -1, -1, -1})<<endl; // 7

    //Завдання 2
    cout<<"Варіант 2"<<endl;
    cout<<sum2({1, 2, 3})<<endl; // 6
    cout<<sum2({0})<<endl;       // 0
    cout<<sum2({})<<endl;        // 0
    cout<<sum2({1, -1, 1})<<endl; // 1
    cout<<sum2({10, -1, -1, -1})<<endl; // 7

    //Завдання 3
    cout<<"Варіант 3"<<endl;
    cout<<sum3({1, 2, 3})<<endl; // 6
    cout<<sum3({0})<<endl;       // 0
    cout<<sum3({})<<endl;        // 0
    cout<<sum3({1, -1, 1})<<endl; // 1
    cout<<sum3({10, -1, -1, -1})<<endl; // 7

    //Завдання 4
    cout<<"Варіант 4"<<endl;
    cout<<sum4({1, 2, 3})<<endl; // 6
    cout<<sum4({0})<<endl;       // 0
    cout<<sum4({})<<endl;        // 0
    cout<<sum4({1, -1, 1})<<endl; // 1
    cout<<sum4({10, -1, -1, -1})<<endl; // 7

    //Завдання 5
    cout<<"Варіант 5"<<endl;
    cout<<sum5({1, 2, 3})<<endl; // 6
    cout<<sum5({0})<<endl;       // 0
    cout<<sum5({})<<endl;        // 0
    cout<<sum5({1, -1, 1})<<endl; // 1
    cout<<sum5({10, -1, -1, -1})<<endl; // 7

    //Завдання 6
    vector<vector<int>> arr = {{1, 2, 3}, {37, 5, 6}, {7, 8, 0}};
    int m = max(arr);
    cout<<"\nЗавдання 6: "<<m<<endl;

    //Завдання 7
    map<string, pair<int, int>> persons = {
        {"lenin", {1870, 1924}},
        {"mao", {1893, 1976}},
        {"gandhi", {1869, 1948}},
        {"hirohito", {1901, 1989}}
    };

    unordered_map<string, int> result = ages(persons);

    cout<<"\nЗавдання 7"<<endl;
    for (const auto& person : result) {
        cout << person.first << ": " << person.second << endl;
    }

}

