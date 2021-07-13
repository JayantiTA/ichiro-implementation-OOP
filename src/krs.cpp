#include <iostream>
#include "krs.hpp"

Campus::Campus()
{
}

Academics::Academics(std::string name, std::string major, std::string faculty)
    : name(name), major(major), faculty(faculty)
{
}

std::string Academics::get_name()
{
    return name;
}

CollegeStudent::CollegeStudent(std::string nrp, std::string name,
    std::string major, std::string faculty)
    : nrp(nrp), Academics(name, major, faculty), krs(new Krs())
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

    auto course_taken = krs->get_course_taken();
    for (auto course : course_taken)
    {
        std::cout << "* ";
        course->print_course();
    }
}

void CollegeStudent::take_course(Course *course)
{
    krs->take_course(course); 
}

void CollegeStudent::remove_course(int index_to_remove)
{
    krs->remove_course(index_to_remove); 
}

void CollegeStudent::print_student()
{
    std::cout << nrp << " - " << name << " - " << major << " - " << faculty << std::endl;
}

Lecturer::Lecturer(std::string nidn, std::string name,
    std::string major, std::string faculty)
    : nidn(nidn), Academics(name, major, faculty)
{
}

void Lecturer::print_lecturer()
{
    std::cout << nidn << " - " << name << " - " << major << " - " << faculty << std::endl;
}

Course::Course(std::string course_code, std::string course_name,
    int credit, Lecturer *lecturer)
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
    std::cout << course_code << " - " << course_name << " - " << lecturer->get_name() << std::endl;
}

void Campus::add_lecturer(Lecturer *lecturer)
{
    list_of_lecturers.push_back(lecturer);
}

void Campus::add_course(Course *course)
{
    list_of_courses.push_back(course);
}

void Campus::add_student(CollegeStudent *student)
{
    list_of_students.push_back(student);
}

Krs::Krs()
    : total_course(0), total_credit(0)
{
}

void Krs::take_course(Course *course)
{
    total_credit += course->get_credit();

    if (total_credit <= 24)
    {
        total_course++;

        course_taken.push_back(course);
        std::cout << "Info   : Course added successfully" << std::endl;
    }
    else
    {
        std::cout << "Info   : You reached the credit limit" << std::endl;
    }
}

void Krs::remove_course(int index_to_remove)
{
    course_taken.erase(course_taken.begin() + index_to_remove);
}

std::vector<Course *> Krs::get_course_taken()
{
    return course_taken;
}

std::vector<Lecturer *> Campus::get_list_of_lecturers()
{
    return list_of_lecturers;
}

std::vector<Course *> Campus::get_list_of_courses()
{
    return list_of_courses;
}

std::vector<CollegeStudent *> Campus::get_list_of_students()
{
    return list_of_students;
}