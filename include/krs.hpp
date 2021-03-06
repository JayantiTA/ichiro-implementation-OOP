#include <iostream>
#include <vector>

class Academics
{
public:
    Academics(std::string name, std::string major, std::string faculty);
    std::string get_name();

protected:
    std::string name;
    std::string major;
    std::string faculty;
};

class Lecturer : public Academics
{
public:
    Lecturer(std::string nidn, std::string name, std::string major, std::string faculty);
    void print_lecturer();

private:
    std::string nidn;
};

class Course
{
public:
    Course(std::string course_code, std::string course_name, int credit, Lecturer *lecturer);
    int get_credit();
    void print_course();

private:
    std::string course_code;
    std::string course_name;
    int credit;
    Lecturer *lecturer;
};

class Krs
{
public:
    Krs();
    void take_course(Course *course);
    void remove_course(int index_to_course);
    std::vector<Course *> get_course_taken();

private:
    std::vector<Course *> course_taken;
    int total_course, total_credit;
};

class CollegeStudent : public Academics
{
public:
    CollegeStudent(std::string nrp, std::string name,
        std::string major, std::string faculty);

    void print_student();
    void take_course(Course *course);
    void remove_course(int index_to_remove);
    void print_krs();
    std::string get_nrp();

private:
    std::string nrp;
    int index_to_remove;
    Krs *krs;
};

class Campus
{
public:
    Campus();
    void add_lecturer(Lecturer *lecturer);
    void add_course(Course *course);
    void add_student(CollegeStudent *student);

    std::vector<Lecturer *> get_list_of_lecturers();
    std::vector<Course *> get_list_of_courses();
    std::vector<CollegeStudent *> get_list_of_students();

private:
    std::vector<Lecturer *> list_of_lecturers;
    std::vector<Course *> list_of_courses;
    std::vector<CollegeStudent *> list_of_students;
};