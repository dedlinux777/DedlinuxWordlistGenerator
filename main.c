#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "system.h"
// Function prototypes
void intro();
void getInputs(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords);
void displayMenu();
void generateActivePattern(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords);
void generatePermutations(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords);
void capitalizeFirstLetter(char *str);
void applyCapitalizeFirstLetter(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords);
void applyAllLowerCase(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords);
void applyCamelCase(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords);
void writeToFile(const char *filename, const char *data);

int main() {
    char firstName[50], lastName[50], dob[20], aliases[100], usernames[100], keywords[100];
    int choice;
    
    intro();
    // Step 1: Collect inputs
    getInputs(firstName, lastName, dob, aliases, usernames, keywords);

    // Step 2: Display menu and get user's choice
    displayMenu();
    printf(">> ");
    scanf("%d", &choice);

    // Step 3: Based on the user's choice, apply the selected pattern
    switch (choice) {
        case 1:  // Active Pattern
            generateActivePattern(firstName, lastName, dob, aliases, usernames, keywords);
            break;
        case 2:  // Permutations
            generatePermutations(firstName, lastName, dob, aliases, usernames, keywords);
            break;
        case 3:  // Capitalize First Letter
            applyCapitalizeFirstLetter(firstName, lastName, aliases, usernames, keywords);
            break;
        case 4:  // All Lowercase
            applyAllLowerCase(firstName, lastName, aliases, usernames, keywords);
            break;
        case 5:  // CamelCase
            applyCamelCase(firstName, lastName, aliases, usernames, keywords);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }

    printf("Wordlist generated successfully. Check 'wordlist.txt'.\n");
    return 0;
}

void intro() {
    fprintf(stdout, "Welcome to the Wordlist Generator!\n"
                    
    .___         .___.__  .__                                              .___.__  .__          __                                               __                
  __| _/____   __| _/|  | |__| ____  __ _____  ___ __  _  _____________  __| _/|  | |__| _______/  |_     ____   ____   ____   ________________ _/  |_  ___________ 
 / __ |/ __ \ / __ | |  | |  |/    \|  |  \  \/  / \ \/ \/ /  _ \_  __ \/ __ | |  | |  |/  ___/\   __\   / ___\_/ __ \ /    \_/ __ \_  __ \__  \\   __\/  _ \_  __ \
/ /_/ \  ___// /_/ | |  |_|  |   |  \  |  />    <   \     (  <_> )  | \/ /_/ | |  |_|  |\___ \  |  |    / /_/  >  ___/|   |  \  ___/|  | \// __ \|  | (  <_> )  | \/
\____ |\___  >____ | |____/__|___|  /____//__/\_ \   \/\_/ \____/|__|  \____ | |____/__/____  > |__|    \___  / \___  >___|  /\___  >__|  (____  /__|  \____/|__|   
     \/    \/     \/              \/            \/                          \/              \/         /_____/      \/     \/     \/           \/                   

.\n\n");
}

// Function to collect user inputs
void getInputs(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords) {
    printf("Enter First Name: ");
    scanf("%s", firstName);
    printf("Enter Last Name: ");
    scanf("%s", lastName);
    printf("Enter Date of Birth (DDMMYYYY): ");
    scanf("%s", dob);
    printf("Enter Aliases (comma-separated): ");
    scanf(" %[^\n]", aliases);
    printf("Enter Usernames (comma-separated): ");
    scanf(" %[^\n]", usernames);
    printf("Enter Keywords (comma-separated): ");
    scanf(" %[^\n]", keywords);
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Wordlist Generator Menu ---\n");
    printf("1. Active Pattern\n");
    printf("2. Permutations\n");
    printf("3. Capitalize First Letter\n");
    printf("4. All Lowercase\n");
    printf("5. CamelCase\n");
}

// Function to generate active pattern
void generateActivePattern(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords) {
    char pattern[100];
    printf("Enter the pattern (use placeholders like {FirstName}, {LastName}, {DOB}, etc.): ");
    scanf(" %[^\n]", pattern);

    char result[200];
    snprintf(result, sizeof(result), "%s_%s_%s", firstName, lastName, dob);
    writeToFile("wordlist.txt", result);
}

// Function to generate permutations
void generatePermutations(char *firstName, char *lastName, char *dob, char *aliases, char *usernames, char *keywords) {
    char result[500];
    snprintf(result, sizeof(result), "%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s",
             firstName, lastName, lastName, firstName, firstName, dob, lastName, dob, firstName, usernames, lastName, usernames);
    writeToFile("wordlist.txt", result);
}

// Function to capitalize the first letter of a string
void capitalizeFirstLetter(char *str) {
    if (strlen(str) > 0) {
        str[0] = toupper(str[0]);
    }
}

// Function to apply CapitalizeFirstLetter to all inputs
void applyCapitalizeFirstLetter(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords) {
    capitalizeFirstLetter(firstName);
    capitalizeFirstLetter(lastName);
    capitalizeFirstLetter(aliases);
    capitalizeFirstLetter(usernames);
    capitalizeFirstLetter(keywords);

    char result[500];
    snprintf(result, sizeof(result), "%s\n%s\n%s\n%s\n%s", firstName, lastName, aliases, usernames, keywords);
    writeToFile("wordlist.txt", result);
}

// Function to convert all inputs to lowercase
void applyAllLowerCase(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords) {
    for (int i = 0; firstName[i]; i++) firstName[i] = tolower(firstName[i]);
    for (int i = 0; lastName[i]; i++) lastName[i] = tolower(lastName[i]);
    for (int i = 0; aliases[i]; i++) aliases[i] = tolower(aliases[i]);
    for (int i = 0; usernames[i]; i++) usernames[i] = tolower(usernames[i]);
    for (int i = 0; keywords[i]; i++) keywords[i] = tolower(keywords[i]);

    char result[500];
    snprintf(result, sizeof(result), "%s\n%s\n%s\n%s\n%s", firstName, lastName, aliases, usernames, keywords);
    writeToFile("wordlist.txt", result);
}

// Function to apply CamelCase to inputs
void applyCamelCase(char *firstName, char *lastName, char *aliases, char *usernames, char *keywords) {
    capitalizeFirstLetter(firstName);
    capitalizeFirstLetter(lastName);
    capitalizeFirstLetter(aliases);
    capitalizeFirstLetter(usernames);
    capitalizeFirstLetter(keywords);

    char result[500];
    snprintf(result, sizeof(result), "%s%s\n%s%s\n%s%s\n%s%s\n%s%s", firstName, lastName, firstName, aliases, firstName, usernames, lastName, usernames, firstName, keywords);
    writeToFile("wordlist.txt", result);
}

// Function to write data to a file
void writeToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}
