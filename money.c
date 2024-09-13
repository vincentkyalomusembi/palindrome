#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for the account
typedef struct {
    char name[100];
    char account_number[20];
    float balance;
    char password[20];
} Account;

// Function prototypes
bool login(Account *account);
void saveAccount(const Account *account);
bool loadAccount(Account *account, const char *account_number);

// Function to create a new account
void createAccount(Account *account) {
    printf("Enter the account holder's name: ");
    scanf("%99s", account->name);
    printf("Enter the account number: ");
    scanf("%19s", account->account_number);
    printf("Enter a password for the account: ");
    scanf("%19s", account->password);
    account->balance = 0.0f; // Initial balance set to 0
    saveAccount(account);
}

// Function to save account to file
void saveAccount(const Account *account) {
    FILE *file = fopen("accounts.dat", "ab");
    if (file != NULL) {
        fwrite(account, sizeof(Account), 1, file);
        fclose(file);
    } else {
        printf("Error opening accounts file for writing.\n");
    }
}

// Function to load an account from file
bool loadAccount(Account *account, const char *account_number) {
    FILE *file = fopen("accounts.dat", "rb");
    if (file != NULL) {
        while (fread(account, sizeof(Account), 1, file)) {
            if (strcmp(account->account_number, account_number) == 0) {
                fclose(file);
                return true;
            }
        }
        fclose(file);
    } else {
        printf("Error opening accounts file for reading.\n");
    }
    return false;
}

// Function to login to an account
bool login(Account *account) {
    char entered_account_number[20];
    char entered_password[20];

    printf("Enter account number: ");
    scanf("%19s", entered_account_number);
    printf("Enter password: ");
    scanf("%19s", entered_password);

    if (loadAccount(account, entered_account_number)) {
        if (strcmp(account->password, entered_password) == 0) {
            return true;
        } else {
            printf("Incorrect password.\n");
        }
    } else {
        printf("Account not found.\n");
    }
    return false;
}

// Main function
int main() {
    Account myAccount;
    int option;
    float amount;

    printf("1. Create new account\n");
    printf("2. Login to existing account\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            createAccount(&myAccount);
            break;
        case 2:
            if (login(&myAccount)) {
                printf("Login successful!\n");
                // Add more options for deposit, withdraw, etc.
            }
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}
