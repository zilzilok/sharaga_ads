class Student;
class Ski
{
    friend int compare(const Student& stud, const Ski& ski);
    friend class ReadWriter;
private:
    int length;

public:
    int id;
};

class Student
{
    friend int compare(const Student& stud, const Ski& ski);
    friend class ReadWriter;
private:
    int height;

public:
    int id;
};

/*
Compare student's height and ski's length
Return:
1 if Ski is longer then Student need
0 if Ski is enough length for this Student
-1 if Ski is shorter then Student need
*/
int compare(const Student& stud, const Ski& ski)
{
    int result = 0;

    if (ski.length > stud.height + 5)
        result = 1;

    if (ski.length < stud.height + 5)
        result = -1;

    return result;
}
