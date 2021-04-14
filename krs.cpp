#include <iostream>
#include "krs.hpp"

Academics::Academics(std::string name, std::string major, std::string faculty)
    : name(name), major(major), faculty(faculty)
{
}

std::string Academics::get_name()
{
    return name;
}

CollegeStudent::CollegeStudent(std::string nrp, std::string name,
    std::string major, std::string faculty, Krs krs)
    : nrp(nrp), Academics(name, major, faculty), krs(krs)
{
}

std::string CollegeStudent::get_nrp()
{
    return nrp;
}

void CollegeStudent::print_krs()
{
    std::cout << "NRP      : " << nrp       << std::endl;
    std::cout << "Name     : " << name      << std::endl;
    std::cout << "Major    : " << major     << std::endl;
    std::cout << "Faculty  : " << faculty   << std::endl;
    std::cout << "Courses  : "              << std::endl;

    auto course_list = krs.get_course_list();
    for (auto course : course_list)
    {
        course.print_course();
    }
}

Lecturer::Lecturer(std::string nidn, std::string name,
    std::string major, std::string faculty)
    : nidn(nidn), Academics(name, major, faculty)
{
}

Course::Course(std::string course_code, std::string course_name,
    int credit, Lecturer lecturer)
    : course_code(course_code), course_name(course_name), credit(credit),
        lecturer(lecturer)
{   
}

int Course::get_credit()
{
    return credit;
}

void Course::print_course()
{
    std::cout << "  *" << course_code << "-" << course_name << "-" << lecturer.get_name() << std::endl;
}

Krs::Krs()
{
}

void Krs::add_course(Course course)
{
    total_course += course.get_credit();

    if (total_credit <= 24) {
        total_course++;

        course_list.push_back(course);
        std::cout << "Info   : Course added successfully" << std::endl;
    }
    else {
        std::cout << "Info   : You reached credit limit" << std::endl;
    }
}

std::vector<Course> Krs::get_course_list()
{
    return course_list;
}