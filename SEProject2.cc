#include <stdio.h>
#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

using namespace tinyxml2;
using namespace std;


//Error check with Tinyxml2
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult)         \
    if (a_eResult != XML_SUCCESS)         \
    {                                     \
        printf("Error: %i\n", a_eResult); \
        return NULL;                      \
    }
#endif

int c = 1;

//created class 
class TakenClass
{
public:
    string courseCode = "";
    string title = "";
    string grade = "";

public:
    TakenClass(string courseC, string t, string g)
    {
        courseCode = courseC;
        title = t;
        grade = g;
    }

    string toString()
    {
        //cout<<"CourseCode: " << courseCode << "; title: " << title << "; grade: " << grade << endl;
       return "Course: "+ courseCode + "; Title: "+ title +"; Grade: "+ grade;
       //return NULL;
    }
    string getCode()
    {
        return courseCode;
    }
    string getTitle()
    {
        return title;
    }
    string getGrade()
    {
        return grade;
    }
};

//Method to load curriculum file
list<TakenClass> loadCurriculumFile(string filename)
{
    list<TakenClass> curriculum = list<TakenClass>();
    // Load XML file
    XMLDocument doc;

    XMLError err = doc.LoadFile(filename.c_str());

    if (err != XML_SUCCESS)
    {
        cout << "Error " << err << " Loading File\n";
        return curriculum;
    }

    XMLNode *root = doc.FirstChildElement("Curriculum");
    if (root == NULL)
    {
        cout << "Failed to Load Curriculum File" << endl;
        return curriculum;
    }

    XMLNode *term = root->FirstChild();
    if (term == NULL)
    {
        cout << "Failed to Find Term Element" << endl;
        return curriculum;
    }

    // create list of schedule to return
    // Populate all courses in class list for each term
    if (term != NULL)
    {
        do
        {
            XMLElement *courses = term->FirstChildElement()->NextSiblingElement();
            if (courses != NULL)
            {
                XMLElement *curClass = courses->FirstChildElement("class");
                // Populate all courses listed in a term
                if (curClass != NULL)
                {
                    do
                    {
                        TakenClass tmpClass(curClass->FirstChildElement("courseCode")->GetText(),
                                            curClass->FirstChildElement("title")->GetText(),
                                            curClass->FirstChildElement("grade")->GetText());
                        curriculum.push_back(tmpClass);
                        curClass = curClass->NextSiblingElement("class");
                    } while (curClass != NULL);
                }
            }
            term = term->NextSiblingElement();
        } while (term != NULL);
    }
    return curriculum;
}

//Method to load transcript file
list<TakenClass> loadTranscriptFile(string filename)
{
    list<TakenClass> classes = list<TakenClass>();
    // Load XML file
    XMLDocument doc;

    XMLError err = doc.LoadFile(filename.c_str());

    if (err != XML_SUCCESS)
    {
        cout << "Error " << err << " Loading File";
        return classes;
    }

    XMLNode *root = doc.FirstChildElement("Transcript");
    if (root == NULL)
    {
        cout << "Failed to Load Transcript File" << endl;
        return classes;
    }

    XMLNode *term = root->FirstChild();
    if (term == NULL)
    {
        cout << "Failed to Find Term Element" << endl;
        return classes;
    }

    // create list of classes to return
    // Populate all courses in class list for each term
    if (term != NULL)
    {
        do
        {
            XMLElement *courses = term->FirstChildElement()->NextSiblingElement();
            if (courses != NULL)
            {
                XMLElement *curClass = courses->FirstChildElement("class");
                // Populate all courses listed in a term
                
                 if (curClass != NULL)
                    {
                     do
                        {
                         TakenClass tmpClass(curClass->FirstChildElement("courseCode")->GetText(),
                                            curClass->FirstChildElement("title")->GetText(),
                                            curClass->FirstChildElement("grade")->GetText());
                         classes.push_back(tmpClass);
                         curClass = curClass->NextSiblingElement("class");
                        } while (curClass != NULL);
                    }
            }
            term = term->NextSiblingElement();
        } while (term != NULL);
    }
    return classes;
}


list<TakenClass> loadScheduleFile(string filename)
{
    list<TakenClass> schedule = list<TakenClass>();
    // Load XML file
    XMLDocument doc;

    XMLError err = doc.LoadFile(filename.c_str());

    if (err != XML_SUCCESS)
    {
        cout << "Error " << err << " Loading File";
        return schedule;
    }

    XMLNode *root = doc.FirstChildElement("Schedule");
    if (root == NULL)
    {
        cout << "Failed to Load Transcript File" << endl;
        return schedule;
    }

    XMLNode *term = root->FirstChild();
    if (term == NULL)
    {
        cout << "Failed to Find Term Element" << endl;
        return schedule;
    }
    // create list of classes to return
    // Populate all courses in class list for each term
    if (term != NULL)
    {
        do
        {
            XMLElement *courses = term->FirstChildElement()->NextSiblingElement();
            if (courses != NULL)
            {
                XMLElement *curClass = courses->FirstChildElement("class");
                // Populate all courses listed in a term
                if (curClass != NULL)
                {
                    do
                    {
                        TakenClass tmpClass(curClass->FirstChildElement("courseCode")->GetText(),
                                            curClass->FirstChildElement("title")->GetText(),
                                            curClass->FirstChildElement("grade")->GetText());
                        schedule.push_back(tmpClass);
                        curClass = curClass->NextSiblingElement("class");
                    } while (curClass != NULL);
                }
            }
            term = term->NextSiblingElement();
        } while (term != NULL);
    }
    return schedule;
}

list<TakenClass> loadHumanFile(string filename,string tag)
{
    list<TakenClass> humanities = list<TakenClass>();
    // Load XML file
    XMLDocument doc;

    XMLError err = doc.LoadFile(filename.c_str());

    if (err != XML_SUCCESS)
    {
        cout << "Error " << err << " Loading File";
        return humanities;
    }

    XMLNode *root = doc.FirstChildElement(tag.c_str());
    if (root == NULL)
    {
        cout << "Failed to Load Humanities File" << endl;
        return humanities;
    }

    XMLNode *term = root->FirstChild();
    if (term == NULL)
    {
        cout << "Failed to Find Term Element" << endl;
        return humanities;
    }

    // create list of classes to return
    // Populate all courses in class list for each term
    if (term != NULL)
    {
        do
        {
            XMLElement *courses = term->FirstChildElement()->NextSiblingElement();
            if (courses != NULL)
            {
                XMLElement *curClass = courses->FirstChildElement("class");
                // Populate all courses listed in a term
                if (curClass != NULL)
                {
                    do
                    {
                        TakenClass tmpClass(curClass->FirstChildElement("courseCode")->GetText(),
                                            curClass->FirstChildElement("title")->GetText(),
                                            curClass->FirstChildElement("grade")->GetText());
                        humanities.push_back(tmpClass);
                        curClass = curClass->NextSiblingElement("class");
                    } while (curClass != NULL);
                }
            }
            term = term->NextSiblingElement();
        } while (term != NULL);
    }
    return humanities;
}

//populates schedule for next term
list<TakenClass> makeFutureSchedule(list<TakenClass> transcript,list<TakenClass> curriculum)
{
    list<TakenClass> humanities = loadHumanFile("SEhumanities.xml","humanities");
    list<TakenClass> socialsci = loadHumanFile("SEsocialsci.xml","socialsci");
    list<TakenClass> history = loadHumanFile("SEhistory.xml","history");
    list<TakenClass> natsci = loadHumanFile("SEnatsci.xml","natsci");
    list<TakenClass> math = loadHumanFile("SEmath.xml","math");
    list<TakenClass> newSchedule;
    list<TakenClass> humanitiesList;
    list<TakenClass> humanitiesList2;
    list<TakenClass> socialsciList;
    list<TakenClass> socialsciList2;
    list<TakenClass> schedpart;
    list<TakenClass> schedpart2;
    list<TakenClass> nextSchedule = curriculum;
    TakenClass tmpSchedule(" "," "," ");
    int num=1;

    //compares transcript with curriculum
    for (list<TakenClass>::iterator it = curriculum.begin();
         it != curriculum.end(); ++it)
    {   //traverses transcript and makes an object of classes found
        for (list<TakenClass>::iterator it2 = transcript.begin();
             it2 != transcript.end(); ++it2)
        {
            string g = it->getGrade();
            char grade[g.size()+1];
            string g2 = it2->getGrade();
            char grade2[g2.size()+1];
            char* x = strcpy(grade,g.c_str());
            char* y = strcpy(grade2,g2.c_str());
             
           if (it->getCode() == it2->getCode() && x >= y)
            {   
                //cout<<num<<" "<<"courses taken: "<<it2->getCode()<<endl;
                tmpSchedule.courseCode = it2->getCode();
                tmpSchedule.title = it2->getTitle();
                tmpSchedule.grade = it2->getGrade();
                num++;
                break;
                //num++;
            }
        }
        //makes new linked list of curriculum without found objects
       if(it->getCode() == tmpSchedule.courseCode)
       {
           continue;
       }
       else{
           TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
            newSchedule.push_back(tmpS);
            //cout<<tmpSchedule.courseCode<<"  "<<it->getCode()<<" "<<endl;
       }
    }
    int count = 0;
    for (list<TakenClass>::iterator it = humanities.begin();
         it != humanities.end(); ++it)
    {   //traverses transcript and makes an object of classes found
        for (list<TakenClass>::iterator it2 = transcript.begin();
             it2 != transcript.end(); ++it2)
        {
            string g = it->getGrade();
            char grade[g.size()+1];
            string g2 = it2->getGrade();
            char grade2[g2.size()+1];
            char* x = strcpy(grade,g.c_str());
            char* y = strcpy(grade2,g2.c_str());

            if (it->getTitle() == it2->getTitle() || it->getCode() == it2->getCode() && x >= y)
            {
                tmpSchedule.courseCode = it2->getCode();
                tmpSchedule.title = it2->getTitle();
                tmpSchedule.grade = it2->getGrade();
                break;
            }
        }
         if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title)
        {
           count++;
            TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
            humanitiesList2.push_back(tmpS);
        }
    }
    if(count >= 3)
    {
               for (list<TakenClass>::iterator it = newSchedule.begin();
                it != newSchedule.end(); ++it)
                {   //traverses transcript and makes an object of classes found
                    for (list<TakenClass>::iterator it2 = humanitiesList2.begin();
                     it2 != humanitiesList2.end(); ++it2)
                    {
                        if(it->getCode() == it2->getCode() || it->getTitle() == it2->getTitle())
                        {
                        tmpSchedule.courseCode = it2->getCode();
                        tmpSchedule.title = it2->getTitle();
                        tmpSchedule.grade = it2->getGrade();
                        break;  
                        }
                    }
                    if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title ||
                        tmpSchedule.title == "Humanities Elective")
                    {
                         continue;
                    }
                    else{
                         TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                         humanitiesList.push_back(tmpS);
                        //cout<<tmpSchedule.courseCode<<"  "<<it->getCode()<<" "<<endl;
                    }
                }
                newSchedule = humanitiesList;
    }

    if(count == 2)
    {
        int count1 = 0;
        int newHum = 0;
       
        for (list<TakenClass>::iterator it = humanitiesList2.begin();
                it != humanitiesList2.end(); ++it)
        {   //traverses transcript and makes an object of classes found
            for (list<TakenClass>::iterator it2 = newSchedule.begin();
                it2 != newSchedule.end(); ++it2)
            {
                if(it->getCode() == it2->getCode() || it->getTitle() == it2->getTitle())
                {
                tmpSchedule.courseCode = it2->getCode();
                tmpSchedule.title = it2->getTitle();
                tmpSchedule.grade = it2->getGrade();
                break;
                }
            }
               if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title)
                {
                    continue;
                }
                else{
                    TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                    humanitiesList.push_back(tmpS);
                }
        } 
        for (list<TakenClass>::iterator it = humanitiesList.begin();
                it != humanitiesList.end(); ++it)
        {
            cout << count1++ << " " << it->toString() << " " << endl;
        }
         cout<<"You need to choose another humanities course. Choose from above: "<<endl;
        cin>>newHum;
        count = 1;
        for (list<TakenClass>::iterator it = humanitiesList.begin();
            it != humanitiesList.end(); ++it)  
            {
                count1++;
               
               if(count1 == newHum) 
                {
                    TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                    newSchedule.push_back(tmpS);
                    break;
                }
            } 
    }
    if(count == 1)
    {
        int newHum = 0;
        int newHum2 = 0;
        int count2 = 1;
        num = 1;
        for (list<TakenClass>::iterator it = humanities.begin();
                it != humanities.end(); ++it)
        {   //traverses transcript and makes an object of classes found
            for (list<TakenClass>::iterator it2 = newSchedule.begin();
                it2 != newSchedule.end(); ++it2)
            {
               if(it->getCode() == it2->getCode() || it->getTitle() == it2->getTitle())
                {   
                cout<<num<<" "<<"courses taken: "<<it2->getCode()<<endl;
                    tmpSchedule.courseCode = it2->getCode();
                    tmpSchedule.title = it2->getTitle();
                    tmpSchedule.grade = it2->getGrade();
                    break;
                num++;
                }  
            }
            if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title)
                {
                    continue;
                }
                else{
                    TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                    humanitiesList.push_back(tmpS);
                }
        }
        for (list<TakenClass>::iterator it2 = newSchedule.begin();
                it2 != newSchedule.end(); ++it2)
            {
            if(it2->getCode() == tmpSchedule.courseCode || it2->getTitle()== tmpSchedule.title || 
                it2->getTitle() == "Humanities Elective")
                {
                    continue;
                }
                else{
                    TakenClass tmpS(it2->getCode(), it2->getTitle(), it2->getGrade());
                   schedpart.push_back(tmpS);
                }
            }newSchedule = schedpart;   
        for (list<TakenClass>::iterator it = humanitiesList.begin();
                it != humanitiesList.end(); ++it)
        {
            cout << count2++ << " " << it->toString() << " " << endl;
        }
        
         cout<<"You need 2 more humanities courses to satisfy 9 hours. Choose 2 from above: "<<endl;
        cin>>newHum>>newHum2;
        count2=0;
        for (list<TakenClass>::iterator it = humanitiesList.begin();
            it != humanitiesList.end(); ++it)  
        {
            count2++;
           
           if(count2 == newHum) 
            {
                TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                newSchedule.push_back(tmpS);
                break;
            }
        } 
        int count3 = 0;
        for (list<TakenClass>::iterator it = humanitiesList.begin();
            it != humanitiesList.end(); ++it)  
        {
            count3++;
          
           if(count3 == newHum2) 
           {
                TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                newSchedule.push_back(tmpS);
               break;
           }
        } 
    }

    for (list<TakenClass>::iterator it = socialsci.begin();
         it != socialsci.end(); ++it)
    {   //traverses transcript and makes an object of classes found
        for (list<TakenClass>::iterator it2 = transcript.begin();
             it2 != transcript.end(); ++it2)
        {
            string g = it->getGrade();
            char grade[g.size()+1];
            string g2 = it2->getGrade();
            char grade2[g2.size()+1];
            char* x = strcpy(grade,g.c_str());
            char* y = strcpy(grade2,g2.c_str());

            if (it->getTitle() == it2->getTitle() || it->getCode() == it2->getCode() && x >= y)
            {
                tmpSchedule.courseCode = it2->getCode();
                tmpSchedule.title = it2->getTitle();
                tmpSchedule.grade = it2->getGrade();
                break;
            }
        }
         if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title)
        {
           count++;
          cout << count++ << " " << it->toString() << " " << endl;
            TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
            socialsciList2.push_back(tmpS);
        }
    }
    if(count >= 2)
    {
               for (list<TakenClass>::iterator it = newSchedule.begin();
                it != newSchedule.end(); ++it)
                {   //traverses transcript and makes an object of classes found
                    for (list<TakenClass>::iterator it2 = socialsciList2.begin();
                     it2 != socialsciList2.end(); ++it2)
                    {
                        if(it->getCode() == it2->getCode() || it->getTitle() == it2->getTitle())
                        {
                        tmpSchedule.courseCode = it2->getCode();
                        tmpSchedule.title = it2->getTitle();
                        tmpSchedule.grade = it2->getGrade();
                        break;  
                        }
                    }
                    if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title ||
                        tmpSchedule.title == "Social Science Elective")
                    {
                         continue;
                    }
                    else{
                         TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                         socialsciList.push_back(tmpS);
                        //cout<<tmpSchedule.courseCode<<"  "<<it->getCode()<<" "<<endl;
                    }
                }
                newSchedule = socialsciList;
                cout<<"All Social Science Taken.\n";
    }


    if(count == 1)
    {
        int newHum = 0;
        int newHum2 = 0;
        int count2 = 1;
        num = 1;
        for (list<TakenClass>::iterator it = socialsci.begin();
                it != socialsci.end(); ++it)
        {   //traverses transcript and makes an object of classes found
            for (list<TakenClass>::iterator it2 = newSchedule.begin();
                it2 != newSchedule.end(); ++it2)
            {
               if(it->getCode() == it2->getCode() || it->getTitle() == it2->getTitle())
                {   
                cout<<num<<" "<<"courses taken: "<<it2->getCode()<<endl;
                    tmpSchedule.courseCode = it2->getCode();
                    tmpSchedule.title = it2->getTitle();
                    tmpSchedule.grade = it2->getGrade();
                    break;
                num++;
                }  
            }
            if(it->getCode() == tmpSchedule.courseCode || it->getTitle() == tmpSchedule.title)
                {
                    continue;
                }
                else{
                    TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                    socialsciList.push_back(tmpS);
                }
        }
        for (list<TakenClass>::iterator it2 = newSchedule.begin();
                it2 != newSchedule.end(); ++it2)
            {
            if(it2->getCode() == tmpSchedule.courseCode || it2->getTitle()== tmpSchedule.title || 
                it2->getTitle() == "Social Science Elective")
                {
                    continue;
                }
                else{
                    TakenClass tmpS(it2->getCode(), it2->getTitle(), it2->getGrade());
                   schedpart2.push_back(tmpS);
                }
            }newSchedule = schedpart2;   
        for (list<TakenClass>::iterator it = socialsciList.begin();
                it != socialsciList.end(); ++it)
        {
            cout << count2++ << " " << it->toString() << " " << endl;
        }
        
         cout<<"You need 2 more social science courses to satisfy 6 hours. Choose 2 from above: "<<endl;
        cin>>newHum>>newHum2;
        count2=0;
        for (list<TakenClass>::iterator it = socialsciList.begin();
            it != socialsciList.end(); ++it)  
        {
            count2++;
           
           if(count2 == newHum) 
            {
                TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                newSchedule.push_back(tmpS);
                break;
            }
        } 
        int count3 = 0;
        for (list<TakenClass>::iterator it = socialsciList.begin();
            it != socialsciList.end(); ++it)  
        {
            count3++;
          
           if(count3 == newHum2) 
           {
                TakenClass tmpS(it->getCode(), it->getTitle(), it->getGrade());
                newSchedule.push_back(tmpS);
               break;
           }
        } 
    }


    int x = 1;

    //prints out the next 7 classes new schedule
    cout<<"Courses Left to take: "<<endl; 
    for (list<TakenClass>::iterator it = newSchedule.begin();
         it !=newSchedule.end(); ++it)
    {
        //if(x<7 && it->getCode()!="No Code")    
        //{
        cout << it->toString() << " " << endl;
        x++;
        //} 
        //else 
        //{
            //continue;
        //}
    }
    x = 1;
    cout<<"Courses for next semester: "<<endl; 
    for (list<TakenClass>::iterator it = newSchedule.begin();
         it !=newSchedule.end(); ++it)
    {
        if(x<7)    
        {
        cout << it->toString() << " " << endl;
        x++;
        } 
        else 
        {
            continue;
        }
    }

    // makes xml document with tags for new schedule
    XMLDocument scheduleFile;
    XMLNode *root = scheduleFile.NewElement("Schedule");
    scheduleFile.InsertFirstChild(root);
    XMLElement *nextTerm = scheduleFile.NewElement("term");
    XMLElement *nextSem = scheduleFile.NewElement("semester");
    XMLElement *nextCourse = scheduleFile.NewElement("courses");
    
    root->InsertFirstChild(nextTerm); 
        nextSem->SetText("Next Semester");
        nextTerm->InsertFirstChild(nextSem);
        nextTerm->InsertEndChild(nextCourse);
    for (list<TakenClass>::iterator it = newSchedule.begin();
         it != newSchedule.end(); ++it)
        {  
        XMLElement *nextClass = scheduleFile.NewElement("class");
        XMLElement *nextCode = scheduleFile.NewElement("courseCode");
        XMLElement *nextTitle = scheduleFile.NewElement("title");
        XMLElement *nextGrade = scheduleFile.NewElement("grade");
        nextCourse->InsertFirstChild(nextClass); 
        nextClass->InsertFirstChild(nextCode);    
        nextClass->InsertFirstChild(nextGrade);
        nextClass->InsertFirstChild(nextTitle);
        nextClass->InsertFirstChild(nextCode);
        string c = it->getCode();
        char code[c.size()+1];
       // strcpy(code,c.c_str());
        string t = it->getTitle();
         char title[t.size()+1];
       // strcpy(title,t.c_str());
       string g = it->getGrade();
        char grade[g.size()+1];
        nextCode->SetText(strcpy(code,c.c_str()));
        nextTitle->SetText(strcpy(title,t.c_str()));
        nextGrade->SetText(strcpy(grade,g.c_str()));
        }
    scheduleFile.SaveFile("scheddoc.xml");
    return newSchedule;
}


int main(int argc, char *argv[])
{
    cout<< "You have entered " << argc << " arguments\n";
    if (argc == 3)
    {
        printf("running...\n");
    string transcriptFile /*= "SEtranscript.xml"*/, curriculumFile /*= "SEcurriculum.xml"*/;
    //cout<<"Name of transcript file: "<<endl;
    transcriptFile = argv[1];
    //cout<< "Name of curriculum file: "<<endl;
    curriculumFile = argv[2];

    list<TakenClass> takenClasses = loadTranscriptFile(transcriptFile);
    list<TakenClass> majorSchedule = loadCurriculumFile(curriculumFile);
    /*ofstream tfile("transdoc.xml");
    ofstream cfile("currdoc.xml");

    for (list<TakenClass>::iterator it = takenClasses.begin();
         it != takenClasses.end(); ++it)
    {
        tfile << c << " " << it->toString() << " " << endl;
        c++;
    }
    c = 1;
    for (list<TakenClass>::iterator it = majorSchedule.begin();
         it != majorSchedule.end(); ++it)
    {
        cfile << c << " " << it->toString() << " " << endl;
        c++;
    }
    tfile.close();
    cfile.close();
    */
    makeFutureSchedule(takenClasses,majorSchedule);

    cout << "Ran to end\n";

    } else if (argc > 3){
        printf("too many files.");


    } else {
        printf("another file needed.");
    }

    return 0;
}
