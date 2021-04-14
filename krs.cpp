#include <iostream>
#include "krs.hpp"

CollegeStudent::CollegeStudent(std::string w, std::string x, std::string y, std::string z) {
    nrp     = w;
    name    = x;
    major   = y;
    faculty = z;
}

void CollegeStudent::get_college_student(std::string nrp) {
    std::cout << "NRP      : " << nrp       << std::endl;
    std::cout << "Name     : " << name      << std::endl;
    std::cout << "Major    : " << major     << std::endl;
    std::cout << "Faculty  : " << faculty   << std::endl;
    std::cout << "Courses  : "              << std::endl;
}

Lecturer::Lecturer(std::string nidn, std::string name, std::string major, std::string faculty) {
    this->nidn      = nidn;
    this->name      = name;
    this->major     = major;
    this->faculty   = faculty;
}

void LecturerList::add_lecturer(Lecturer lecturer) {
    this->lecturers_list.push_back(lecturer);
}

Course::Course(std::string course_code, std::string course_name, int sks, Lecturer lecturer) {
    this->course_code = course_code;
    this->course_name = course_name;
    this->sks         = sks;
    this->lecturer    = lecturer;   
}

void CourseList::add_course(Course course) {
    this->courses_list.push_back(course);
}

// void Krs::add_krs(Course c) {
//     total_course += c.sks;

//     if (total_sks <= 24) {
//         total_course++;

//         std::cout << "Info " << nrp << "\t: Course addes successfully" << std::endl;
//     }
//     else {
//         std::cout << "Info " << nrp << "\t: You reached credit limit" << std::endl;
//     }
// }