## You Get an A (C++)
# A code-based console printer gradebook (for csc122)

## How to use
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

# How to make a gradebook
    gradebook myGradebookName;
    don't forget to add students that you make to it with,
    myGradebookName.addStudent(studentObj);

# How to make a student
    student student_object_name("Full Student Name", "ID number string");

# How to make an assignment
    assignment assignment_object_name("Full Assignment Name", int total points);

# A note on IDs
    you can use the included class "ID_maker" to generate an ID.
    simply delclare it like ID_maker maker. 
    Then call it in the construction of a student object.
    like so, 
    student student_obj("full name", maker.generateID);
    Do note, you can still just define your own ID's per student.

# How to grade an assignment
    grading an assignment is currently scoped to the student class, you can do it two ways.
    student_obj.grade_assignment(assignment_obj, int points earned);
    or you can add the assignment to the student like this
    student_obj.addAssignment(assignment_obj);  then grade it either like this again,
    student_obj.grade_assignment(assignment_obj, int points earned);

# Printing report cards
    A report card can be printed two ways. You can call the method directly...
    std::cout << my_gradebook.displayGrades() << std::endl;
    or, you can just print the gradebook, as the class has the << operator overloaded!
    std::cout << my_gradebook << std::endl;

# Changing the ways it sorts the report cards
    You can change the way student are sorted and printed by using the 
    sort_by_XXXXX functions before printing the report cards.
    The following are the methods, and a brief description of what they do.
    my_gradebook.sort_by_lastName();
        this sorts the students by thier last name.
    my_gradebook.sort_by_Score();
        this sorts the students by thier current grade in the class.
    my_gradebook.sort_byID();
        this sorts the students by thier IDs.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 