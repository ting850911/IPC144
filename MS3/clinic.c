/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Nina Wang
Student ID#: 148817232
Email      : ytwang4@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, recordsFound = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            recordsFound = 1;
        }
    }

    if (!recordsFound)
    {
        printf("*** No records found ***\n");
    }

    printf("\n");
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int choice;

    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        choice = inputIntRange(0, 2);
        printf("\n");

        switch (choice)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (choice);
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int patientIdx;

    patientIdx = findPatientIndexByPatientNum(0, patient, max);
    if (patientIdx != -1)
    {
        patient[patientIdx].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[patientIdx]);
        printf("*** New patient record added ***\n\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientNum, patientIdx;

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    printf("\n");

    patientIdx = findPatientIndexByPatientNum(patientNum, patient, max);
    if (patientIdx != -1)
    {
        menuPatientEdit(&patient[patientIdx]);
    }
    else
    {
        printf("\n\nERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientNum, patientIdx;
    char confirm;

    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    printf("\n");

    patientIdx = findPatientIndexByPatientNum(patientNum, patient, max);
    if (patientIdx != -1)
    {
        displayPatientData(&patient[patientIdx], 1);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        confirm = inputCharOption("yn");

        if (confirm == 'y')
        {
            patient[patientIdx].patientNumber = 0;
            printf("Patient record has been removed!");
        }
        else
        {
            printf("Operation aborted.");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!");
    }

    printf("\n\n");
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Sorts an array of appointments using the bubble sort algorithm.
void bubbleSort(struct Appointment appointments[], int max)
{
    int i, j;

    // Loop through all appointments to convert their time to total minutes since the start of the year
    for (i = 0; i < max; i++)
    {
        appointments[i].time.min = (appointments[i].date.year * MINUTES_PER_YEAR) +
                                   (appointments[i].date.month * MINUTES_PER_MONTH) +
                                   (appointments[i].date.day * MINUTES_PER_DAY) +
                                   (appointments[i].time.hour * MINUTES_PER_HOUR) +
                                   appointments[i].time.min;
    }
    // Bubble sort
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appointments[j].time.min > appointments[j + 1].time.min)
            {
                // Swap the appointments if they are out of order
                struct Appointment temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
    // Loop through all appointments to revert the total minutes back to the original time format
    for (i = 0; i < max; i++)
    {
        appointments[i].time.min -= (appointments[i].date.year * MINUTES_PER_YEAR) +
                                    (appointments[i].date.month * MINUTES_PER_MONTH) +
                                    (appointments[i].date.day * MINUTES_PER_DAY) +
                                    (appointments[i].time.hour * MINUTES_PER_HOUR);
    }
}

int compareDateAndTime(struct Date *d1, struct Time *t1, struct Date *d2, struct Time *t2)
{
    int result;
    if (t1 == NULL || t2 == NULL)
    {
        result = (d1->year == d2->year &&
                  d1->month == d2->month &&
                  d1->day == d2->day);
    }
    else
    {
        result = (d1->year == d2->year &&
                  d1->month == d2->month &&
                  d1->day == d2->day &&
                  t1->hour == t2->hour &&
                  t1->min == t2->min);
    }
    return result;
}

// Get an appointment index from appointment list by date and time
int getAppointmentIndexByTime(struct Appointment *appointments,
                              int maxAppointments, struct Date *date, struct Time *time)
{
    int i, isBooked = -1;

    for (i = 0; i < maxAppointments && isBooked == -1; i++)
    {
        if (appointments[i].patientNumber > 0 &&
            compareDateAndTime(&appointments[i].date, &appointments[i].time, date, time))
        {
            isBooked = i;
        }
    }

    return isBooked;
}

// Get an appointment index from appointment list by date
int getAppointmentIndexByDate(struct Appointment *appointments, int patientNum,
                              int maxAppointments, struct Date *date)
{
    int i, isBooked = -1; // Flag to store the index if a match is found

    for (i = 0; i < maxAppointments && isBooked == -1; i++)
    {
        if (appointments[i].patientNumber == patientNum &&
            compareDateAndTime(&appointments[i].date, &appointments[i].time, date, NULL))
        {
            isBooked = i; // Set the flag to the current index
        }
    }

    return isBooked; // Return the index of the appointment or -1 if not found
}

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;
    bubbleSort(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(NULL, 1);

    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {

            // To get more appointment information from patient data
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber &&
                data->appointments[i].patientNumber != 0)
            {
                displayScheduleData(&data->patients[j], &data->appointments[i], 1);
            }
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData *data)
{
    int i, patientIdx;
    struct Date date;

    inputDate(&date);
    putchar('\n');

    bubbleSort(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].patientNumber > 0 &&
            data->appointments[i].date.year == date.year &&
            data->appointments[i].date.month == date.month &&
            data->appointments[i].date.day == date.day)
        {
            patientIdx = findPatientIndexByPatientNum(data->appointments[i].patientNumber,
                                                      data->patients, data->maxPatient);
            if (patientIdx != -1)
            {
                displayScheduleData(&data->patients[patientIdx], &data->appointments[i], 0);
            }
        }
    }

    putchar('\n');
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment *appointments, int maxAppointments,
                    struct Patient *patients, int maxPatient)
{
    int i, foundEmpty, appointmentIndex;
    int patientNum, patientIdx, isValid, isValidTime;
    struct Appointment newAppointment;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientIdx = findPatientIndexByPatientNum(patientNum, patients, maxPatient);
    if (patientIdx != -1)
    {
        do
        {
            isValid = 1;
            inputDate(&newAppointment.date);

            do
            {
                isValidTime = 1;
                inputTime(&newAppointment.time);

                if ((newAppointment.time.hour < START_HOUR || newAppointment.time.hour > END_HOUR) ||
                    (newAppointment.time.hour == END_HOUR && newAppointment.time.min != 0) ||
                    (newAppointment.time.min % APPOINTMENT_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n",
                           START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
                    isValidTime = 0;
                }
            } while (!isValidTime);

            appointmentIndex = getAppointmentIndexByTime(appointments, maxAppointments,
                                                         &newAppointment.date, &newAppointment.time);

            if (appointmentIndex != -1)
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
                isValid = 1;
            }
            else
            {
                // NOTE: You need to find an "empty" element in the appointments array...
                // do this by looking for the first element where patientNumber is 0
                // - Should make a function for this...
                // If you don't update the appointmentIndex variable to 0 or more, it crashes
                // (this was your problem)... you were referencing: appointments[-1] since appointmentIndex was -1!

                for (i = 0; i < maxAppointments && appointmentIndex < 0; i++)
                {
                    if (appointments[i].patientNumber < 1)
                    {
                        appointmentIndex = i; // update to the index where there's room to add it!
                    }
                }
                // Found an empty element, now assign new appointment...
                if (appointmentIndex > -1)
                {
                    appointments[appointmentIndex] = newAppointment; // <--- now this will work! appointmentIndex will not be -1!
                    printf("\n*** Appointment scheduled! ***\n\n");
                    isValid = 0;
                }
                else
                {
                    // Appointments array is full... show error...
                    printf("\nERROR: Appointment listing is FULL!\n");
                    isValid = 1;
                }
            }

        } while (isValid);
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment *appointments,
                       int maxAppointments, struct Patient *patients, int maxPatients)
{
    printf("maxAppointments: %d\n", maxAppointments);

    int patientNum, patientIdx, appointmentIndex;
    struct Date date;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientIdx = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
    if (patientIdx != -1)
    {
        inputDate(&date);
        appointmentIndex = getAppointmentIndexByDate(appointments, patientNum, maxAppointments, &date);
        printf("appointmentIndex: %d\n", appointmentIndex);
        if (appointmentIndex != -1)
        {
            printf("\n");
            displayPatientData(&patients[patientIdx], FMT_FORM);

            printf("Are you sure you want to remove this appointment (y,n): ");
            if (inputCharOption("yn") == 'y')
            {
                appointments[appointmentIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
        }
        else
        {
            printf("ERROR: No appointment found for this date!\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum, patientIdx;

    printf("Search by patient number: ");
    patientNum = inputIntPositive();
    printf("\n");

    patientIdx = findPatientIndexByPatientNum(patientNum, patient, max);
    if (patientIdx != -1)
    {
        displayPatientData(&patient[patientIdx], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }

    printf("\n");
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNum[PHONE_LEN + 1];
    int i, isFound = 0;

    printf("Search by phone number: ");
    inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            isFound = 1;
        }
    }

    if (!isFound)
    {
        printf("\n*** No records found ***\n");
    }

    printf("\n");
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, highestPatientNum = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > highestPatientNum)
        {
            highestPatientNum = patient[i].patientNumber;
        }
    }

    return highestPatientNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
    int i, patientIdx = -1;

    for (i = 0; i < max && patientIdx == -1; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            patientIdx = i;
        }
    }

    return patientIdx;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone)
{
    int choice;
    char phoneNumber[PHONE_LEN + 1];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    choice = inputIntRange(1, 4);
    printf("\n");

    switch (choice)
    {
    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        break;
    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        phone->number[0] = '\0';
        return;
    }

    printf("Contact: %s\n", phone->description);
    printf("Number : ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    strncpy(phone->number, phoneNumber, PHONE_LEN);
    phone->number[PHONE_LEN] = '\0';
    printf("\n");
}

// Get user input for date struct
void inputDate(struct Date *date)
{
    printf("Year        : ");
    date->year = inputIntPositive();
    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);

    switch (date->month)
    {
    case 2:
        if ((date->year % 4 == 0 && date->year % 100 != 0) ||
            date->year % 400 == 0)
        {
            printf("Day (1-29)  : ");
            date->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            date->day = inputIntRange(1, 28);
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Day (1-30)  : ");
        date->day = inputIntRange(1, 30);
        break;
    default:
        printf("Day (1-31)  : ");
        date->day = inputIntRange(1, 31);
        break;
    }
}

// Get user input for time struct
void inputTime(struct Time *time)
{
    printf("Hour (0-23)  : ");
    time->hour = inputIntRange(0, 23);
    printf("Minute (0-59): ");
    time->min = inputIntRange(0, 59);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    FILE *fp;
    int count = 0;

    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (count < max && fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                                     &patients[count].patientNumber,
                                     patients[count].name,
                                     patients[count].phone.description,
                                     patients[count].phone.number) != EOF)
        //&& count < max) // <=== NO YOU NEED TO TEST THIS FIRST OR IT WILL ATTEMPT TO READ BEYOND ARRAY BOUNDS!
        {
            count++;
        }

        // 用for loop更直觀
        // int done = 0;
        // for (count = 0; count < max && !done; count++)
        // {
        //     if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
        //                &patients[count].patientNumber,
        //                patients[count].name,
        //                patients[count].phone.description,
        //                patients[count].phone.number) == EOF)
        //     {
        //         done = 1;
        //     }
        // }
        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }

    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    int i, count = 0;
    FILE *fp = NULL;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        for (i = 0; i < max; i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d\n",
                   &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month,
                   &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF;

            // To get the last patient number, and count the total patient
            if (appoints[i].patientNumber != 0)
            {
                count++;
            }
        }
        fclose(fp);
    }
    return count;
}