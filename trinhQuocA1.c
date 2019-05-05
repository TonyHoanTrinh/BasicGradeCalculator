/************************trinhQuocA1.c **************
 Student Name: Quoc (Tony) Trinh 			Email Id: trinhq@uoguelph.ca
 Date: October 5th, 2018					Course Name: CIS 1500
 I have exclusive control over this submission via my password.
 By including this statement in this header comment, I certify that:
 1) I have read and understood the University policy on academic integrity;
 2) I have completed the Computing with Integrity Tutorial on Moodle; and
 3) I have achieved at least 80% in the Computing with Integrity Self Test.
 I assert that this work is my own. I have appropriately acknowledged any and all material (data, images, ideas or words) that I have used,
 whether directly quoted or paraphrased.
 Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ***********************************************************/


/**********************************************************
   Compiling the program
 *********************************************************
 The program should be compiled using the following flags:
 -std=c99
 -Wall
 compiling: gcc trinhQuocA1.c -std=c99 -Wall -o trinhQuocA1
 **********************************************************
 Running the Program
 **********************************************************
 running: ./trinhQuocA1
 The user is prompted for 11 different inputs before the output is generated.
 **********************************************************/

// Used for printf
#include <stdio.h>

int main() 
{
    // Declaring Double variables to hold the user's inputs for their grades
    double weekLab, dailyPract, labExam1, labExam2, assign1, assign2, assign3, moss1, moss2, moss3, desiredGrade;
    // Input Print and Scan Statements
    printf("Enter the following marks (each out of 100):\n\n");
    printf("Weekly Labs:");
    scanf("%lf", &weekLab);
    printf("Daily Practice:");
    scanf("%lf", &dailyPract);
    printf("Lab Exam I:");
    scanf("%lf", &labExam1);
    printf("Lab Exam II:");
    scanf("%lf", &labExam2);
    printf("Assignment1:");
    scanf("%lf", &assign1);
    printf("MOSS output for A1 (0 / 1):");
    scanf("%lf", &moss1);
    printf("Assignment2:");
    scanf("%lf", &assign2);
    printf("MOSS output for A2 (0 / 1):");
    scanf("%lf", &moss2);
    printf("Assignment3:");
    scanf("%lf", &assign3);
    printf("MOSS output for A3 (0 / 1):");
    scanf("%lf", &moss3);

	// Asks user for their desired overall course grade and gets the user's input
    printf("\n\nHow much do you desire as an overall course grade:");
    scanf("%lf", &desiredGrade);

    printf("\n\n");

    /* Checks the value of MOSS to determine if the corresponding assignment marks will be changed to 0 or cannot
       If the moss value for the assignment is 0 that means the corresponding assignment will be changed to 0 */
    if (moss1 == 0) 
    {
        assign1 = 0;
    }
    if (moss2 == 0) 
    {
        assign2 = 0;
    }

    if (moss3 == 0) 
    {
        assign3 = 0;
    }

    // Makes a new variable for bonus mark
    int bonusMark;

    // If the moss values for the 3 assignments are 0, then it will print this statement
    if ((moss1 == 0) && (moss2 == 0) && (moss3 == 0)) 
    {
        printf("**************************************************\n");
        printf("You cannot pass the course - try harder next time.\n");
        printf("**************************************************\n");
    } 
    else 
    {
        // Output for if the moss values for the 3 assignments are not all equal to 0

        // If the student got a perfect on both lab exams it will print give them a bonus mark of 3 to the overall grade
        if ((labExam1 == 100.00) && (labExam2 == 100.00)) 
        {
            bonusMark = 3;
        } 
        else 
        {
            // If they do not get perfect on both lab exams, it will just set bonusMark as 0
            bonusMark = 0;
        }

		// Outputs the table to display theirs marks
        printf("********************************************************\n");
        printf("Assessment \t Weight \t Marks \n");
        printf("________________________________________________________\n");
        printf("Weekly Labs \t 10 \t\t %.2lf \n", weekLab);
        printf("Daily Practice \t 10 \t\t %.2lf \n", dailyPract);
        printf("Lab Exam I \t 10 \t\t %.2lf \n", labExam1);
        printf("Lab Exam II \t 10 \t\t %.2lf \n", labExam2);
        printf("Bonus from last exams: \t\t %d \n", bonusMark);
        printf("Assignment 1 \t 5 \t\t %.2lf \n", assign1);
        printf("Assignment 2 \t 10 \t\t %.2lf \n", assign2);
        printf("Assignment 3 \t 10 \t\t %.2lf \n", assign3);
        printf("Final Exam \t 35 \t    To be determined \n\n\n");

        // Creates a variable to represent the student's current grade before the final exam
        double currGrade;

        // Calculates the student's current grade using the marks they entered and the weighted values of the corresponding assignments and labs
        currGrade = (weekLab * 0.1) + (dailyPract * 0.1) + (labExam1 * 0.1) + (labExam2 * 0.1) + (assign1 * 0.05) + (assign2 * 0.1) + (assign3 * 0.1) + bonusMark;

        // Creates a variable to hold the mark they need on the final exam to get their desired mark
        double neededFinalExamMark;

        // The needed final exam mark is the desired mark minus their current grade
        neededFinalExamMark = desiredGrade - currGrade;

        // Creates a variable to hold the mark in terms of a percentage
        double neededFinalExamMarkPercent;

        /* The neede final exam mark in terms of percentage is just the mark divided by how much the final exam is out of which is 35.
           Because it's a percentage we then have to multiply it by 100 */
		neededFinalExamMarkPercent = (neededFinalExamMark / 35.00) * 100;

		// Outputs their current course mark, how much they need on the final exam to reach their goal and the final mark in terms of percentage
        printf("********************************************************\n\n");
        printf("Current course mark = %.2lf / 65.00\n", currGrade);
        printf("You need %.2lf/ 35.00 to reach your goal (%.0lf)\n", neededFinalExamMark, desiredGrade);
        printf("In percentage, you need %.0lf %% to reach your goal (%.0lf)\n", neededFinalExamMarkPercent, desiredGrade);
        printf("********************************************************\n");
    }

    return 0;
}
