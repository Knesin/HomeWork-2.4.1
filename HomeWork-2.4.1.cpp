#include <iostream>
#include <fstream>
#include <string>


class Address {
public:
    void set_city(const std::string &str) { city_ = str; }
    void set_street(const std::string &str) { street_ = str; }
    void set_home(const int &number) { home_ = number; }
    void set_apartment(const int &number) { apartment_ = number; }
    std::string get_city() { return city_; }
    std::string get_street() { return street_; }
    int get_home() { return home_; }
    int get_apartment() { return apartment_; }
private:
    std::string city_;
    std::string street_;
    int home_;
    int apartment_;
};

int main()
{
    std::ifstream in_f("in.txt");
    std::ofstream out_f("out.txt");
    int count = 0;
    Address *adres;

    setlocale(LC_ALL, "Russian");
    if (!in_f.is_open()) {
        std::cout << "Не удолось открыть файл" << std::endl;
        return 1;
    }
    in_f >> count;
    adres = new Address[count];
    for (int i = 0; i < count; ++i) {
        std::string str_tmp;
        int int_tmp;
        in_f >> str_tmp;
        adres[i].set_city(str_tmp);
        in_f >> str_tmp;
        adres[i].set_street(str_tmp);
        in_f >> int_tmp;
        adres[i].set_home(int_tmp);
        in_f >> int_tmp;
        adres[i].set_apartment(int_tmp);
    }

    out_f << count << std::endl;
    for (int i = count - 1; i >= 0; i--) {
        out_f   << adres[i].get_city() << ", "
                << adres[i].get_street() << ", "
                << adres[i].get_home() << ", "
                << adres[i].get_apartment();
        if (i > 0)
            out_f << std::endl;
    }
    delete [] adres;
    in_f.close();
    out_f.close();
}  