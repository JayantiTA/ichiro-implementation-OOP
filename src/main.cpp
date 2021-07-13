#include <iostream>
#include "krs.hpp"

int main() 
{
    Campus *campus = new Campus();
    campus->add_lecturer(new Lecturer("123", "PakArun", "Informatika", "FTEIC"));
    campus->add_lecturer(new Lecturer("133", "PakMunif", "Informatika", "FTEIC"));
    campus->add_course(new Course("27487", "Strukdat", 3, campus->get_list_of_lecturers()[0]));
    campus->add_course(new Course("27487", "Strukdat", 3, campus->get_list_of_lecturers()[1]));
    campus->add_course(new Course("27447", "Dasprog", 4, campus->get_list_of_lecturers()[1]));
    campus->add_student(new CollegeStudent("781427", "Jayanti", "Informatika", "FTEIC"));
    campus->add_student(new CollegeStudent("781477", "Andhina", "Informatika", "FTEIC"));

    std::cout << "WELCOME TO MINI INTEGRA\n" << std::endl;
    std::cout << "Choose what you want to do?" << std::endl;
    std::cout << "  A. Input" << std::endl;
    std::cout << "  B. TakeCourse" << std::endl;
    std::cout << "  C. RemoveCourse" << std::endl;
    std::cout << "  D. GetOutput" << std::endl;
    std::cout << "  E. FINISH" << std::endl;

    std::string do_something;

    while (std::cin >> do_something)
    {
        if (do_something == "A")
        {
            std::cout << "\nChoose object:" << std::endl;
            std::cout << "  1. Lecturer" << std::endl;
            std::cout << "  2. Course" << std::endl;
            std::cout << "  3. Student" << std::endl;
            
            std::string input;

            while (std::cin >> input)
            {
                if (input == "1")
                {
                    std::string nidn, name, major, faculty;
                    std::cout << "Please input data correctly" << std::endl;
                    std::cout << "NIDN: ";
                    std::cin >> nidn; 
                    std::cout << "Name: ";
                    std::cin >> name;
                    std::cout << "Major: ";
                    std::cin >> major;
                    std::cout << "Faculty: ";
                    std::cin >> faculty;

                    campus->add_lecturer(new Lecturer(nidn, name, major, faculty));

                    int index_lecturer = 0;
                    std::cout << "----------------------------------------" << std::endl;
                    for (auto lecturer : campus->get_list_of_lecturers()) 
                    {
                        std::cout << index_lecturer << ". ";
                        index_lecturer++;
                        lecturer->print_lecturer();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else if (input == "2")
                {
                    int index_lecturer, index_course = 0;
                    std::string course_code, course_name;
                    int sks;

                    std::cout << "Please input data correctly" << std::endl;
                    std::cout << "Course code: ";
                    std::cin >> course_code;
                    std::cout << "Course name: ";
                    std::cin >> course_name;
                    std::cout << "Sks: ";
                    std::cin >> sks;
                    std::cout << "Index of lecturer: ";
                    std::cin >> index_lecturer;

                    campus->add_course(new Course(course_code, course_name, sks,
                        campus->get_list_of_lecturers()[index_lecturer]));
                    
                    std::cout << "----------------------------------------" << std::endl;
                    for (auto course : campus->get_list_of_courses())
                    {
                        std::cout << index_course << ". ";
                        index_course++;
                        course->print_course();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else if (input == "3")
                {
                    int index_student = 0;
                    std::string nrp, name, major, faculty;
                    std::cout << "Please input data correctly" << std::endl;
                    std::cout << "NRP: ";
                    std::cin >> nrp; 
                    std::cout << "Name: ";
                    std::cin >> name;
                    std::cout << "Major: ";
                    std::cin >> major;
                    std::cout << "Faculty: ";
                    std::cin >> faculty;

                    campus->add_student(new CollegeStudent(nrp, name, major, faculty));

                    std::cout << "----------------------------------------" << std::endl;
                    for (auto student : campus->get_list_of_students())
                    {
                        std::cout << index_student << ". ";
                        index_student++;
                        student->print_student();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else
                {
                    std::cout << "\nYour input is incorrect! Please try again!" << std::endl;
                    std::cout << "\nChoose object:" << std::endl;
                    std::cout << "  1. Lecturer" << std::endl;
                    std::cout << "  2. Course" << std::endl;
                    std::cout << "  3. Student" << std::endl;
                }
            }
        }
        else if (do_something == "B")
        {
            int index_student = 0, index_course = 0;
            
            std::cout << "List of students: " << std::endl;
            for (auto student : campus->get_list_of_students())
            {
                std::cout << index_student << ". ";
                index_student++;
                student->print_student();
            }
            std::cout << "Input index of student: ";
            std::cin >> index_student;

            std::cout << "List of courses available: " << std::endl;
            for (auto course : campus->get_list_of_courses())
            {
                std::cout << index_course << ". ";
                index_course++;
                course->print_course();
            }
            std::cout << "Input index of course: ";
            std::cin >> index_course;
            
            std::cout << "----------------------------------------" << std::endl;
            campus->get_list_of_students()[index_student]->take_course(campus->get_list_of_courses()[index_course]);
            std::cout << "----------------------------------------" << std::endl;
        }
        else if (do_something == "C")
        {
            int index_student = 0, index_course = 0;
            
            std::cout << "List of students: " << std::endl;
            for (auto student : campus->get_list_of_students())
            {
                std::cout << index_student << ". ";
                index_student++;
                student->print_student();
            }
            std::cout << "Input index of student: ";
            std::cin >> index_student;

            std::cout << "List of courses in your credit semester: " << std::endl;
            campus->get_list_of_students()[index_student]->print_krs();
        
            std::cout << "Input index of course: ";
            std::cin >> index_course;

            campus->get_list_of_students()[index_student]->remove_course(index_course);

            std::cout << "----------------------------------------" << std::endl;
            std::cout << "List of courses now in your credit semester: " << std::endl;
            campus->get_list_of_students()[index_student]->print_krs();
            std::cout << "----------------------------------------" << std::endl;
        }
        else if (do_something ==  "D")
        {
            std::cout << "\nChoose object to print:" << std::endl;
            std::cout << "  1. Lecturer" << std::endl;
            std::cout << "  2. Course" << std::endl;
            std::cout << "  3. Student" << std::endl;
            std::cout << "  4. Krs" << std::endl;
            
            std::string input;
            while (std::cin >> input)
            {
                if (input == "1")
                {
                    int index_lecturer = 1;
                    std::cout << "----------------------------------------" << std::endl;
                    for (auto lecturer : campus->get_list_of_lecturers()) 
                    {
                        std::cout << index_lecturer << ". ";
                        index_lecturer++;
                        lecturer->print_lecturer();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else if (input == "2")
                {
                    int index_course = 1;
                    std::cout << "----------------------------------------" << std::endl;
                    for (auto course : campus->get_list_of_courses())
                    {
                        std::cout << index_course << ". ";
                        index_course++;
                        course->print_course();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else if (input == "3")
                {
                    int index_student = 1;
                    std::cout << "----------------------------------------" << std::endl;
                    for (auto student : campus->get_list_of_students())
                    {
                        std::cout << index_student << ". ";
                        index_student++;
                        student->print_student();
                    }
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else if (input == "4")
                {
                    int index_student = 0;
                
                    std::cout << "List of students: " << std::endl;
                    for (auto student : campus->get_list_of_students())
                    {
                        std::cout << index_student << ". ";
                        index_student++;
                        student->print_student();
                    }

                    std::cout << "Input index of student: ";
                    std::cin >> index_student;

                    std::cout << "----------------------------------------" << std::endl;
                    campus->get_list_of_students()[index_student]->print_krs();
                    std::cout << "----------------------------------------" << std::endl;

                    break;
                }
                else
                {
                    std::cout << "\nYour input is incorrect! Please try again!" << std::endl;
                    std::cout << "\nChoose object:" << std::endl;
                    std::cout << "  1. Lecturer" << std::endl;
                    std::cout << "  2. Course" << std::endl;
                    std::cout << "  3. Student" << std::endl;
                    std::cout << "  4. Krs" << std::endl;
                }
            }
        }
        else if (do_something == "E")
        {
            return 0;
        }
        else
        {
            std::cout << "\nYour input is incorrect! Please try again!" << std::endl;
        }

        std::cout << "\nChoose what you want to do?" << std::endl;
        std::cout << "  A. Input" << std::endl;
        std::cout << "  B. TakeCourse" << std::endl;
        std::cout << "  C. RemoveCourse" << std::endl;
        std::cout << "  D. GetOutput" << std::endl;
        std::cout << "  E. FINISH" << std::endl;
    }

    return 0;
}