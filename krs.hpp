#include <iostream>
#include <vector>

class Academics {
public:
    std::string name;
    std::string major;
    std::string faculty;
};

class CollegeStudent : public Academics {
public:
    CollegeStudent(std::string nrp, std::string name, std::string major, std::string faculty);
    void get_college_student(std::string nrp);

private:
    std::string nrp;
};

class Lecturer : public Academics {
public:
    Lecturer(std::string nidn, std::string name, std::string major, std::string faculty);

private:
    std::string nidn;
};

class LecturerList {
public:
    LecturerList();
    void add_lecturer(Lecturer lecturer);
    void list_lecturer();

private:
    std::vector<Lecturer> lecturers_list;
};

class Course {
public:
    Course();
    Course(std::string course_code, std::string course_name, int sks, Lecturer lecturer);

private:
    int sks;
    std::string course_code;
    std::string course_name;
    Lecturer lecturer;
};

class CourseList {
public:
    CourseList();
    void add_course(Course course);

private:
    std::vector<Course> courses_list;
};

class Krs {
public:
    Krs();
    void check_krs(CollegeStudent student, Course course);

private:
    int total_course, total_sks;
};

class KrsList {
public:
    KrsList();
    void add_krs(Course course);

private:
    std::vector<Course> course;
};