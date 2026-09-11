#include <iostream>
#include <string>

using namespace std;

template <typename arr_type>
class StaticArray {
    private:
        arr_type* arr;
        int length = 0;

    public:
        StaticArray(int n) : length(n) {
            arr = new arr_type[n];
        }
        ~StaticArray()  {
            delete arr;
        }

        arr_type get_at(int i) const {
           if ((i >= 0) && (i < length)) return arr{i};
        }

        void set_at(int i, arr_type x) {
            if ((i >= 0) && (i < length)) arr[i] = x;
            return;
        }
};


struct Student {
    string name;
    unsigned int day;
    unsigned int month;
    unsigned int year;
};


/**
 * Apenas repetindo o exemplo das anotacoes
 */
Student main() {

    int n = 0; cin >> n;
    StaticArray<Student>* array = new StaticArray<Student>(n);

    for (int i = 0; i < n; i++) {
        string name_student = ""; int d, m, y;
        cin >> name_student >> d >> m >> y;

        Student alumni;
        alumni.name = name_student;
        alumni.day = d;
        alumni.month = m;
        alumni.year = y;
        
        array->set_at(i, alumni);

        for (int j = 0; j < i; j++) {
            
            if ((array->get_at(j).name == name_student) && (array->get_at(j).day == d) 
            && (array->get_at(j).month == m) && (array->get_at(j).year == y)) {
                return array->get_at(j);
            }
        }
        
    }

    return Student{};
}