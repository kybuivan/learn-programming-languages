// https://en.cppreference.com/w/cpp/utility/tuple

#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>

std::tuple<double, char, std::string> get_student(int id)
{
    switch (id)
    {
    case 0:
        return {3.8, 'A', "Lisa Simpson"};
    case 1:
        return {2.9, 'C', "Milhouse Van Houten"};
    case 2:
        return {1.7, 'D', "Ralph Wiggum"};
    case 3:
        return {0.6, 'F', "Bart Simpson"};
    }

    throw std::invalid_argument("id");
}

int main()
{
    const auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';

    double gpa2;
    char grade2;
    std::string name2;
    std::tie(gpa2, grade2, name2) = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';

    return 0;
}
