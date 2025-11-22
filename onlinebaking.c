#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "bank_accounts.dat"
#define CURRENCY "ZMW"

// Structure to hold account details
typedef struct {
    char name[50];
    char accountNumber[20];
    char password[20];
    float balance;
} Account;

// Function prototypes
void registerAccount();
int login(char *acc, char *pass);
void depositMoney();
void withdrawMoney();
void transferMoney();
void changePassword();
void displayAccount();

// Utility function prototypes for file operations
void saveAccount(Account acc);
int findAccount(char *acc, Account *result);
void updateAccount(Account acc);

int main() {
    int choice;

    printf("=========================================\n");
    printf("        ONLINE BANKING SYSTEM\n");
    printf("        Student Number: 2025558414\n");
    printf("=========================================\n");

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Register Account\n");
        printf("2. Login & Deposit\n");
        printf("3. Login & Withdraw\n");
        printf("4. Login & Transfer\n");
        printf("5. Login & Change Password\n");
        printf("6. Login & Display Account\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        // Use a temporary variable to capture input and check for errors
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer to prevent infinite loop
            while (getchar() != '\n');
            continue;
        }
        
        // Clear input buffer for safe string/char reads later
        while (getchar() != '\n');

        switch (choice) {
            case 1: registerAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: transferMoney(); break;
            case 5: changePassword(); break;
            case 6: displayAccount(); break;
            case 7: 
                printf("Thank you for using Online Banking System!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// --- Utility Functions (File I/O) ---

// Save a new account to the file
void saveAccount(Account acc) {
    // "ab" mode: append in binary mode
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error: Could not open file for saving account.\n");
        return;
    }
    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
}

// Find an account by account number and store details in result
int findAccount(char *accNum, Account *result) {
    // "rb" mode: read in binary mode
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0; // File doesn't exist or cannot be opened

    Account temp;
    while (fread(&temp, sizeof(Account), 1, fp)) {
        if (strcmp(temp.accountNumber, accNum) == 0) {
            *result = temp;
            fclose(fp);
            return 1; // Found
        }
    }
    fclose(fp);
    return 0; // Not found
}

// Update an existing account record in the file
void updateAccount(Account acc) {
    // "rb+" mode: read and write, starting at the beginning
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("Error: Could not open file for updating account.\n");
        return;
    }
    
    Account temp;
    // Iterate through all records
    while (fread(&temp, sizeof(Account), 1, fp)) {
        if (strcmp(temp.accountNumber, acc.accountNumber) == 0) {
            // Found the record. Go back by the size of one Account structure
            fseek(fp, -sizeof(Account), SEEK_CUR);
            // Overwrite the old record with the new one
            fwrite(&acc, sizeof(Account), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
}

// Login verification
int login(char *acc, char *pass) {
    Account temp;
    // Check if account exists
    if (!findAccount(acc, &temp))
        return 0; // Account not found

    // Check if password matches
    if (strcmp(temp.password, pass) == 0)
        return 1; // Success

    return 0; // Incorrect password
}

// --- Core Bank Operations ---

void registerAccount() {
    Account acc;
    char buffer[20]; // Buffer for scanf inputs

    printf("\n===== REGISTER NEW ACCOUNT =====\n");
    printf("Enter Full Name: ");
    // Fix: Use fgets for names to handle spaces, then remove newline
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;

    // Loop to ensure account number is unique
    do {
        printf("Enter Account Number (max 19 chars): ");
        if (scanf("%19s", acc.accountNumber) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // Clear buffer
        
        if (findAccount(acc.accountNumber, &acc)) {
            printf("Error: Account number already exists. Please choose another.\n");
        } else {
            break; // Account number is unique
        }
    } while (1);


    printf("Create Password (max 19 chars): ");
    scanf("%19s", acc.password);
    while (getchar() != '\n'); // Clear buffer

    printf("Enter Initial Deposit (%s): ", CURRENCY);
    if (scanf("%f", &acc.balance) != 1 || acc.balance < 0) {
         printf("Invalid or negative deposit amount. Setting balance to 0.00 %s.\n", CURRENCY);
         acc.balance = 0.00;
    }
    while (getchar() != '\n'); // Clear buffer

    saveAccount(acc);

    printf("\nAccount successfully created! Welcome, %s.\n", acc.name);
}

void depositMoney() {
    char accNum[20], pass[20];
    Account acc;
    float amt;

    printf("\n===== LOGIN (Deposit) =====\n");
    printf("Account Number: ");
    scanf("%s", accNum);

    printf("Password: ");
    scanf("%s", pass);
    while (getchar() != '\n'); // Clear buffer

    if (!login(accNum, pass)) {
        printf("Invalid account or password!\n");
        return;
    }

    // Retrieve account details again after successful login
    findAccount(accNum, &acc);

    printf("Enter deposit amount (%s): ", CURRENCY);
    if (scanf("%f", &amt) != 1 || amt <= 0) {
        printf("Invalid or zero/negative deposit amount.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // Clear buffer


    acc.balance += amt;
    updateAccount(acc);

    printf("Deposit successful! New balance: %.2f %s\n", acc.balance, CURRENCY);
}

void withdrawMoney() {
    char accNum[20], pass[20];
    Account acc;
    float amt;

    printf("\n===== LOGIN (Withdraw) =====\n");
    printf("Account Number: ");
    scanf("%s", accNum);

    printf("Password: ");
    scanf("%s", pass);
    while (getchar() != '\n'); // Clear buffer

    if (!login(accNum, pass)) {
        printf("Invalid account or password!\n");
        return;
    }

    // Retrieve account details again after successful login
    findAccount(accNum, &acc);

    printf("Enter amount to withdraw (%s): ", CURRENCY);
    if (scanf("%f", &amt) != 1 || amt <= 0) {
        printf("Invalid or zero/negative withdrawal amount.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    if (amt > acc.balance) {
        printf("Insufficient funds! Current balance: %.2f %s\n", acc.balance, CURRENCY);
        return;
    }

    acc.balance -= amt;
    updateAccount(acc);

    printf("Withdrawal successful! New balance: %.2f %s\n", acc.balance, CURRENCY);
}

void transferMoney() {
    char senderAcc[20], receiverAcc[20], pass[20];
    Account sender, receiver;
    float amt;

    printf("\n===== LOGIN (Transfer) =====\n");
    printf("Sender Account Number: ");
    scanf("%s", senderAcc);

    printf("Password: ");
    scanf("%s", pass);
    while (getchar() != '\n'); // Clear buffer

    if (!login(senderAcc, pass)) {
        printf("Invalid sender credentials!\n");
        return;
    }

    // Retrieve sender account details
    findAccount(senderAcc, &sender);

    printf("Receiver Account Number: ");
    scanf("%s", receiverAcc);
    while (getchar() != '\n'); // Clear buffer

    if (strcmp(senderAcc, receiverAcc) == 0) {
        printf("Error: Cannot transfer to the same account.\n");
        return;
    }

    // Find receiver account
    if (!findAccount(receiverAcc, &receiver)) {
        printf("Receiver account not found!\n");
        return;
    }
    
    printf("Enter amount to transfer (%s): ", CURRENCY);
    if (scanf("%f", &amt) != 1 || amt <= 0) {
        printf("Invalid or zero/negative transfer amount.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // Clear buffer

    // Check sender balance
    if (amt > sender.balance) {
        printf("Insufficient funds! Sender balance: %.2f %s\n", sender.balance, CURRENCY);
        return;
    }

    // Perform transaction
    sender.balance -= amt;
    receiver.balance += amt;

    // Update both accounts
    updateAccount(sender);
    updateAccount(receiver);

    printf("\nTransfer of %.2f %s to account %s (%s) successful!\n", 
           amt, CURRENCY, receiver.accountNumber, receiver.name);
    printf("Your new balance: %.2f %s\n", sender.balance, CURRENCY);
}

void changePassword() {
    char accNum[20], oldPass[20], newPass[20], confirmPass[20];
    Account acc;

    printf("\n===== LOGIN (Change Password) =====\n");
    printf("Account Number: ");
    scanf("%s", accNum);

    printf("Current Password: ");
    scanf("%s", oldPass);
    while (getchar() != '\n'); // Clear buffer

    if (!login(accNum, oldPass)) {
        printf("Invalid account or current password!\n");
        return;
    }

    // Retrieve account details
    findAccount(accNum, &acc);

    printf("Enter New Password (max 19 chars): ");
    scanf("%19s", newPass);
    while (getchar() != '\n'); // Clear buffer
    
    printf("Confirm New Password: ");
    scanf("%19s", confirmPass);
    while (getchar() != '\n'); // Clear buffer


    if (strcmp(newPass, confirmPass) != 0) {
        printf("New passwords do not match. Password change failed.\n");
        return;
    }
    
    if (strcmp(newPass, oldPass) == 0) {
        printf("New password cannot be the same as the old password.\n");
        return;
    }

    // Update the password in the structure
    strcpy(acc.password, newPass);
    updateAccount(acc);

    printf("Password successfully changed for account %s.\n", accNum);
}

void displayAccount() {
    char accNum[20], pass[20];
    Account acc;

    printf("\n===== LOGIN (Display Account) =====\n");
    printf("Account Number: ");
    scanf("%s", accNum);

    printf("Password: ");
    scanf("%s", pass);
    while (getchar() != '\n'); // Clear buffer

    if (!login(accNum, pass)) {
        printf("Invalid account or password!\n");
        return;
    }

    // Retrieve account details
    findAccount(accNum, &acc);

    printf("\n===== ACCOUNT DETAILS =====\n");
    printf("Account Holder: %s\n", acc.name);
    printf("Account Number: %s\n", acc.accountNumber);
    printf("Current Balance: %.2f %s\n", acc.balance, CURRENCY);
    printf("===========================\n");
}