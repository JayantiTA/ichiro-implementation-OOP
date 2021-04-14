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

class CollegeStudent : public Academics
{
public:
    CollegeStudent(std::string nrp, std::string name,
        std::string major, std::string faculty, Krs krs);

    void print_krs();
    std::string get_nrp();

private:
    std::string nrp;
    Krs krs;
};

class Lecturer : public Academics
{
public:
    Lecturer(std::string nidn, std::string name, std::string major, std::string faculty);

private:
    std::string nidn;
};

class LecturerList
{
public:
    LecturerList();
    void add_lecturer(Lecturer lecturer);
    void list_lecturer();

private:
    std::vector<Lecturer> lecturer_list;
};

class Course
{
public:
    Course(std::string course_code, std::string course_name, int credit, Lecturer lecturer);
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
    void add_course(Course course);
    std::vector<Course> get_course_list();

private:
    std::vector<Course> course_list;
    int total_course, total_credit;
};