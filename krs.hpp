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
    int credit;
    std::string course_code;
    std::string course_name;
    Lecturer lecturer;
};

class Krs
{
public:
    Krs();
    void take_course(Course *course);
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
    void print_krs();
    std::string get_nrp();

private:
    std::string nrp;
    Krs *krs;
};

class Campus
{
public:
    Campus();
    void add_lecturer(Lecturer *lecturer);
    void add_course(Course *course);
    void add_student(CollegeStudent *student);

    std::vector<Lecturer *> get_list_of_lecturer();
    std::vector<Course *> get_list_of_course();
    std::vector<CollegeStudent *> get_list_of_student();

private:
    std::vector<Lecturer *> list_of_lecturer;
    std::vector<Course *> list_of_course;
    std::vector<CollegeStudent *> list_of_student;
};