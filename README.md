# Ichiro - OOP implementation
This project was created to fulfill Ichiro's first internship assignment - Object Oriented Programming (OOP) Implementation.

## Indentity
Name    : Jayanti Totti Andhina

NRP     : 5025201037

Major   : Informatics Engineering

## OOP Implementation : Mini Integra

## General Explanation
First of all, I called this program **Mini Integra** because this program works the same as **ITS's Integra System**, or more precisely **SI Akademik**. This program could be used to take credit semester before beginning of new semester. Program **Mini Integra** consists of 3 program files: `krs.hpp`, `krs.cpp`, and `main.cpp`. This program uses 6 classes: `Academics`, `Lecturer`, `Course`, `Krs`, `CollegeStudent`, and `Campus`.

### What are the features of **Mini Integra**?
In this program, you could:
1. Add lecturer 
2. Add course
3. Add student
4. Take course
5. Print credit semester card of student

The input is either from user or program.

## Specific Explanation
### class Academics
`class Academics` is a class to store academics's personal data, consists of:
1. **Contructer** (public access specifier) to allocate new object with parameters: `name`, `major`, and `faculty`. Those parameters use `std::string` data type.
2. **Method** `get_name()` (public access specifier) with `std::string` return type, to get variable `name` from protected access specifier.
3. **Variables** `name`, `major`, and `faculty` (protected access specifier) with `std::string` data type, to store academics's name, major, and faculty.

### class Lecturer
`class Lecturer` is a class to store lecturer's personal data. This class inherits from `class Academics` to access variable `name`, `major`, and `faculty`. This class consist of:
1. **Constructor** (public access specifier) to allocate new object with parameters: `nidn`, `name`, `major`, and `faculty`. Those parameters use `std::string` data type.
2. **Method** `print_lecturer()` (public access specifier) without return type (`void`), to print Lecturer's objects with variable: `nidn`, `name`, `major`, and `faculty`.
3. **Variable** `nidn` (private access specifier) with `string` data type, to store lecturer's NIDN.

### class Course
`class Course` is a class to store courses that will be taken by student. This class consists of:
1. **Constructor** (public access specifier) to allocate new object with parameters: `std::string course_code`, `std::string course_name`, `int credit`, and `Lecturer *lecturer`.
2. **Method** `get_credit()` (public access specifier) with `int` return type, to get variable `credit` from private access specifier.
3. **Method** `print_course()` (public access specifier) without return type (`void`), to print Course's object with variable: `course_code`, `course_name`, `credit`, and `lecturer` (lecturer's name).
4. **Variables** `course_code` and `course_name` with `std::string` data type to store course's code and name. `credit` with `int` data type to store credit of course. `lecturer` to store lecturer who teach that course. All of those variables are from private access specifier.

### class Krs
`class Krs` is a class to store credit semester card of student, that contains student's personal data and courses taken. This class consists of:
1. **Constructor** (public access specifier) to allocate new object.
2. **Method** `take_course(Course *course)` (public access specifier) without return type (`void`), to take a course and then stored in Krs object.
3. **Method** `get_course_taken()` (public access specifier) with object data type `<Course *>`, to return array of Course object that taken.
4. **Method** `course_taken()` (private access specifier) with object data type `<Course *>`, to store array of Course object that taken.
5. **Variables** `total_course` and `total_credit` (private access specifier) with `int` data type (Private access specifier).

### class CollegeStudent
`class CollegeStudent` is a class to store student's personal data and sync it with credit semester card. This class consist of:
1. **Constructor** (public access specifier) to allocate new object with parameters: `nrp`, `name`, `major`, and `faculty`. Those parameters use `std::string` data type.
2. **Method** `print_student()` (public access specifier) without return type (`void`), to print Student object with variable: `nrp`, `name`, `major`, and `faculty`.
3. **Method** `take_course(Course *course)` (public access specifier) without return type (`void`), to pass Course object that will be taken to `take_course(Course *course)` in `class Krs`.
4. **Method** `print_krs()` (public access specifier) without return type (`void`), to print credit semester card of student.
5. **Method** `get_nrp()` (public access specifier) with `std::string` return type, to get variable `nrp` from pivate access specifier.
6. **Variables** `nrp` with `std::string` data type and `*krs` with `Krs` object data type (private access specifier).

### class Campus
`class Campus` is a class to store array of object: academics's data (student and lecturer) and course. This class consist of:
1. **Constructer** (public access specifier) to allocate new object.
2. **Method** `add_lecturer(Lecturer *lecturer)`, `add_course(Course *course)`, and `add_student(CollegeStudent *student)` to add new array of object with parameter pointer object data type  (public access specifier). Those three methods are `void` (without return type).
3. **Method** `get_list_of_lecturer()`, `get_list_of_course()`, and `get_list_of_student()` to get array of object (public access specifier). Those three methods have return type `std::vector` with object data types.
4. **Variables** `list_of_lecturer`, `list_of_course`, and `list_of_student` to store array of object with object data types.

## Program Flow (In General)
At first, this program will display "WELCOME TO MINI INTEGRA" and next line is "Choose what you want to do" with 4 choices (A. Input, B. TakeCourse, C. GetOutput, D. FINISH). You should choose 1 of those 4 choices with input 'A'/'B'/'C'/'D'.

If you input 'A' (it means that you want to input data to program) there will be display 3 choices (1. Lecturer, 2. Course, 3. Student)

1. if you input 1, you should fill `nidn`, `name`, `major`, and `faculty` of lecturer. After that, the program will display the list of lecturer.
2. if you input 2, you should fill `course_code`, `course_name`, `sks`, and `index_lecturer` of course. After that, the program will display the list of course.
3. if you input 3, you should fill `nrp`, `name`, `major`, and `faculty` of student. After that, the program will display the list of student.
4. if you input the other character, program will print "Your input is incorrect! Please try again!". And then you should input again correctly.

if you input 'B' (it means that you want to take course), you should input the index_student and index_name. Be sure before you take course, you know the index of student and course. You also could check it in **C. GetOutput**.

If you input 'C' (it means that you want to input data to program) there will be display 3 choices (1. Lecturer, 2. Course, 3. Student)

1. if you input 1, the program will display the list of lecturer.
2. if you input 2, the program will display the list of course.
3. if you input 3, the program will display the list of student.
4. if you input 4, you should input the index of student who wants to be printed. And then, the program will display the credit semester card of the student based of index that you input.
5. if you input the other character, program will print "Your input is incorrect! Please try again!". And then you should input again correctly.

if you input the other character, program will print "Your input is incorrect! Please try again!". And then you should input again correctly.