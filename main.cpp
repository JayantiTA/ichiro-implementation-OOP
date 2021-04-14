#include <iostream>
#include "krs.hpp"

int main() {
    Lecturer *lecturer1 = new Lecturer("12345", "Pak Arun", "Informatics", "FTEIC");
    Course *course1 = new Course("SDG123", "PBO", 5, *lecturer1);
    Course *course2 = new Course("SDG234", "Strukdat", 3, *lecturer1);
    Krs *krs = new Krs();
    krs->add_course(*course1);
    krs->add_course(*course2);
    CollegeStudent *student = new CollegeStudent("1326423", "Jayanti", "Informatics", "FTEIC", *krs);
    student->print_krs();

    return 0;
}