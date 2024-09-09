#include <stdio.h>
#include <ctype.h>

// quiz game

// question struct contain some variables
typedef struct
{
    char question[120];
    char decisions[4][25];
    char answer;

} Question;

int main()
{
    printf("Wellcome to the quiz every correct answer will give you 1 point");
    printf(" and every mistake will take out 1 point GOOD LUCK!\n");
    printf("-----------------------------\n");
    
    Question question1 = {"What color is sky? : ",
                          {"A.light blue", "B.blue", "C.brown", "D.black"},
                          'A'};
    Question question2 = {"Which Programming language does Unity Engine Use? : ",
                          {"A.gdscript", "B.c", "C.c#", "D.swift"},
                          'C'};
    Question question3 = {"When was Arab-Israeli War?: ",
                          {"A.1967", "B.1948", "C.1955", "D.2023"},
                          'B'};

    // list of questions
    Question questions[] = {question1, question2, question3};
    int questionsLength = sizeof(questions) / sizeof(questions[0]); //length of questions array

    int correct_answers = 0; // correct answers counter
    for (int i = 0; i < questionsLength; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("\n%s", questions[i].decisions[j]);
        }
        printf("\n%s", questions[i].question);

        char _answer;
        scanf(" %c",&_answer);
        _answer = toupper(_answer);

        if (_answer == questions[i].answer)
        {
            printf("You are Correct! \'%c\' is the correct answer\n",_answer);
            correct_answers++;
        } else 
        {
            printf("You are Wrong! \'%c\' is the not correct answer\n",questions[i].answer);
            correct_answers--;
        }
        
    }
    printf("You've got %d out of ",correct_answers);
    printf("%d ",questionsLength);
    return 0;
}

//Im proud of this project im really did it in 1hour but i think im now in new level in c