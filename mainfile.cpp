#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

// =====================================
// 1. VIEW SAVED STUDY PLANNER
// =====================================

void viewStudyPlanner()
{
    ifstream readFile("study_planner.txt");

    if (!readFile.is_open())
    {
        cout << "\nStudy Planner File Not Found!\n";
        return;
    }

    string line;

    cout << "\n===== SAVED STUDY PLANNER =====\n";

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();
}

// =====================================
// 2. STUDY PLANNER
// =====================================

void studyPlanner()
{
    string tasks[5];
    int status[5];
    int totalTasks;
    int completed = 0;

    cout << "\n===== DAILY STUDY PLANNER =====\n";

    cout << "How Many Tasks Do You Want To Add? ";

    if (!(cin >> totalTasks))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid Input!\n";
        return;
    }

    if (totalTasks < 1 || totalTasks > 5)
    {
        cout << "\nPlease Enter 1 To 5 Tasks Only!\n";
        return;
    }

    for (int i = 0; i < totalTasks; i++)
    {
        cout << "\nEnter Task " << i + 1 << ": ";
        getline(cin >> ws, tasks[i]);
    }

    for (int i = 0; i < totalTasks; i++)
    {
        cout << "\nTask: " << tasks[i];
        cout << "\nEnter 1 for Complete or 0 for Pending: ";

        if (!(cin >> status[i]) ||
            (status[i] != 0 && status[i] != 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Status! Please Try Again.\n";
            return;
        }

        if (status[i] == 1)
        {
            completed++;
        }
    }

    double progress =
        (completed / (double)totalTasks) * 100;

    cout << "\n===== YOUR STUDY PROGRESS =====\n";

    for (int i = 0; i < totalTasks; i++)
    {
        cout << "\n"
             << tasks[i];

        if (status[i] == 1)
            cout << " - Completed";
        else
            cout << " - Pending";
    }

    cout << "\n\nTotal Tasks: " << totalTasks;
    cout << "\nCompleted Tasks: " << completed;
    cout << "\nPending Tasks: " << totalTasks - completed;
    cout << "\nStudy Progress: " << progress << "%\n";

    ofstream plannerFile("study_planner.txt");

    if (!plannerFile.is_open())
    {
        cout << "\nFile Open Failed!\n";
        return;
    }

    plannerFile << "===== DAILY STUDY PLANNER =====\n";

    for (int i = 0; i < totalTasks; i++)
    {
        plannerFile << "Task: " << tasks[i];

        if (status[i] == 1)
            plannerFile << " - Completed\n";
        else
            plannerFile << " - Pending\n";
    }

    plannerFile << "\nTotal Tasks: " << totalTasks;
    plannerFile << "\nCompleted Tasks: " << completed;
    plannerFile << "\nPending Tasks: " << totalTasks - completed;
    plannerFile << "\nStudy Progress: " << progress << "%";

    plannerFile.close();

    if (plannerFile.fail())
        cout << "\nFile Saving Failed!\n";
    else
        cout << "\nStudy Planner Successfully Saved!\n";
}

// =====================================
// 3. VIEW SAVED STUDENT REPORT
// =====================================

void viewStudentReport()
{
    ifstream readFile("student_report.txt");

    if (!readFile.is_open())
    {
        cout << "\nStudent Report File Not Found!\n";
        return;
    }

    string line;

    cout << "\n===== SAVED STUDENT REPORT =====\n";

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();
}

// =====================================
// 4. STUDENT REPORT
// =====================================

void studentReport()
{
    string studentName;
    string subject[5];
    int marks[5];
    int total = 0;

    cout << "\n===== STUDENT PROFILE & REPORT =====\n";

    cout << "Enter Your Name: ";
    getline(cin >> ws, studentName);

    cout << "\nENTER YOUR 5 SUBJECTS AND MARKS:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter Subject Name: ";
        getline(cin >> ws, subject[i]);

        cout << "Enter Your Marks (0-100): ";

        if (!(cin >> marks[i]) ||
            marks[i] < 0 || marks[i] > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Marks! Please Try Again.\n";
            return;
        }

        total += marks[i];
    }

    double percentage = (total / 500.0) * 100;

    string grade;

    if (percentage >= 90)
        grade = "A+";
    else if (percentage >= 80)
        grade = "A";
    else if (percentage >= 70)
        grade = "B";
    else if (percentage >= 60)
        grade = "C";
    else if (percentage >= 40)
        grade = "D";
    else
        grade = "F";

    bool passed = true;

    for (int i = 0; i < 5; i++)
    {
        if (marks[i] < 33)
            passed = false;
    }

    cout << "\n===== STUDENT REPORT =====\n";

    cout << "Name: " << studentName << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << subject[i] << ": " << marks[i] << endl;
    }

    cout << "Total Marks: " << total << "/500" << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;

    if (passed)
        cout << "Result: Pass\n";
    else
        cout << "Result: Fail\n";

    ofstream saveFile("student_report.txt");

    if (!saveFile.is_open())
    {
        cout << "\nFile Open Failed!\n";
        return;
    }

    saveFile << "===== STUDENT REPORT =====\n";
    saveFile << "Name: " << studentName << endl;

    for (int i = 0; i < 5; i++)
    {
        saveFile << subject[i] << ": " << marks[i] << endl;
    }

    saveFile << "Total Marks: " << total << "/500\n";
    saveFile << "Percentage: " << percentage << "%\n";
    saveFile << "Grade: " << grade << endl;

    if (passed)
        saveFile << "Result: Pass\n";
    else
        saveFile << "Result: Fail\n";

    saveFile.close();

    if (saveFile.fail())
        cout << "\nStudent Report Saving Failed!\n";
    else
        cout << "\nStudent Report Successfully Saved!\n";
}

// =====================================
// 5. STUDY TIMETABLE
// =====================================

void studyTimetable()
{
    int totalSubjects;
    string subject[5];
    string startTime[5];
    int duration[5];

    cout << "\n===== STUDY TIMETABLE =====\n";

    cout << "How Many Subjects Do You Want To Study? ";

    if (!(cin >> totalSubjects))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid Input!\n";
        return;
    }

    if (totalSubjects < 1 || totalSubjects > 5)
    {
        cout << "\nPlease Enter 1 To 5 Only!\n";
        return;
    }

    for (int i = 0; i < totalSubjects; i++)
    {
        cout << "\nEnter Subject Name: ";
        getline(cin >> ws, subject[i]);

        cout << "Enter Study Start Time: ";
        getline(cin >> ws, startTime[i]);

        cout << "Enter Study Duration (Hours): ";

        if (!(cin >> duration[i]) || duration[i] <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Duration!\n";
            return;
        }
    }

    cout << "\n===== YOUR STUDY TIMETABLE =====\n";

    for (int i = 0; i < totalSubjects; i++)
    {
        cout << "\nSubject: " << subject[i];
        cout << "\nStart Time: " << startTime[i];
        cout << "\nDuration: " << duration[i] << " hours\n";
    }

    // Saving Timetable

    ofstream timetableFile("study_timetable.txt");

    if (!timetableFile.is_open())
    {
        cout << "\nTimetable File Open Failed!\n";
        return;
    }

    timetableFile << "===== MY STUDY TIMETABLE =====\n";

    for (int i = 0; i < totalSubjects; i++)
    {
        timetableFile << "\nSubject: " << subject[i];
        timetableFile << "\nStart Time: " << startTime[i];
        timetableFile << "\nDuration: " << duration[i] << " hours\n";
    }

    timetableFile.close();

    if (timetableFile.fail())
        cout << "\nTimetable Saving Failed!\n";
    else
        cout << "\nTimetable Successfully Saved!\n";
}

// =====================================
// 6. VIEW SAVED STUDY TIMETABLE
// =====================================

void viewStudyTimetable()
{
    ifstream readFile("study_timetable.txt");

    if (!readFile.is_open())
    {
        cout << "\nTimetable File Not Found!\n";
        return;
    }

    string line;

    cout << "\n===== SAVED STUDY TIMETABLE =====\n";

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();
}

// =====================================
// 7. AI QUESTION ASSISTANT
// =====================================

void aiQuestionAssistant()
{
    string question;

    cout << "\n===== AI QUESTION ASSISTANT =====\n";
    cout << "ASK YOUR QUESTION (TYPE EXIT TO STOP)\n";

    while (true)
    {
        cout << "\nYou: ";
        getline(cin >> ws, question);

        if (question == "exit")
        {
            cout << "\nAI: THANK YOU! KEEP LEARNING.\n";
            break;
        }

        if (question.find("c++") != string::npos)
        {
            cout << "AI: C++ Is A Programming Language.\n";
        }
        else if (question.find("python") != string::npos)
        {
            cout << "AI: Python Is A Programming Language.\n";
        }
        else if (question.find("html") != string::npos)
        {
            cout << "AI: HTML Creates The Structure Of Web Pages.\n";
        }
        else if (question.find("css") != string::npos)
        {
            cout << "AI: CSS Is Used To Design Web Pages.\n";
        }
        else if (question.find("javascript") != string::npos)
        {
            cout << "AI: JavaScript Makes Web Pages Interactive.\n";
        }
        else if (question.find("ai") != string::npos)
        {
            cout << "AI: AI Stands For Artificial Intelligence.\n";
        }
        else
        {
            cout << "AI: Sorry, I Don't Know This Answer Yet.\n";
        }
    }
}

// =====================================
// 8. MAIN FUNCTION
// =====================================

int main()
{
    int choice = 0;

    do
    {
        cout << "\n================================\n";
        cout << "      AI STUDENT ASSISTANT\n";
        cout << "================================\n";

        cout << "1. Student Profile & Report\n";
        cout << "2. Study Timetable\n";
        cout << "3. AI Questions Assistant\n";
        cout << "4. Study Planner\n";
        cout << "5. View Saved Study Planner\n";
        cout << "6. View Saved Student Report\n";
        cout << "7. View Saved Study Timetable\n";
        cout << "8. Exit\n";

        cout << "\nEnter Your Choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nPlease Enter Numbers Only!\n";
            continue;
        }

        if (choice == 1)
        {
            studentReport();
        }
        else if (choice == 2)
        {
            studyTimetable();
        }
        else if (choice == 3)
        {
            aiQuestionAssistant();
        }
        else if (choice == 4)
        {
            studyPlanner();
        }
        else if (choice == 5)
        {
            viewStudyPlanner();
        }
        else if (choice == 6)
        {
            viewStudentReport();
        }
        else if (choice == 7)
        {
            viewStudyTimetable();
        }
        else if (choice == 8)
        {
            cout << "\nThank You! Have A Great Day.\n";
        }
        else
        {
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 8);

    return 0;
}