
#include <stdio.h>


void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);
int changePin(int currentPin);

int main() {

  
    int pin = 1234;
    int enteredPin;
    int attempts = 0;
    int choice;

    double balance = 5000.00;

   
    printf("\n====================================\n");
    printf("          WELCOME TO ATM            \n");
    printf("====================================\n");

    // PIN verification
    while (attempts < 3) {

        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {

            printf("\nPIN accepted successfully!\n");
            break;

        } else {

            attempts++;

            printf("\nIncorrect PIN!\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
    }

    if (attempts == 3) {

        printf("\n====================================\n");
        printf("       ACCOUNT TEMPORARILY LOCKED   \n");
        printf("====================================\n");

        return 0;
    }

   
    do {

        printf("\n====================================\n");
        printf("             ATM MENU               \n");
        printf("====================================\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");

        printf("====================================\n");

        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                checkBalance(balance);

                break;

            case 2:

                balance = depositMoney(balance);

                break;

            case 3:

                balance = withdrawMoney(balance);

                break;

            case 4:

                pin = changePin(pin);

                break;

            case 5:

                printf("\nThank you for banking with us!\n");
                printf("Have a wonderful day!\n");

                break;

            default:

                printf("\nInvalid option! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}



void checkBalance(double balance) {

    printf("\n====================================\n");
    printf("          ACCOUNT BALANCE           \n");
    printf("====================================\n");

    printf("Available balance: N$%.2f\n", balance);

}



double depositMoney(double balance) {

    double amount;

    printf("\n====================================\n");
    printf("             DEPOSIT                \n");
    printf("====================================\n");

    printf("Enter amount to deposit: N$");
    scanf("%lf", &amount);

    if (amount > 0) {

        balance += amount;

        printf("\nDeposit successful!\n");
        printf("Deposited amount: N$%.2f\n", amount);
        printf("New balance: N$%.2f\n", balance);

    } else {

        printf("\nInvalid deposit amount!\n");
    }

    return balance;
}




double withdrawMoney(double balance) {

    double amount;

    printf("\n====================================\n");
    printf("             WITHDRAW               \n");
    printf("====================================\n");

    printf("Enter amount to withdraw: N$");
    scanf("%lf", &amount);

    if (amount <= 0) {

        printf("\nInvalid withdrawal amount!\n");

    } else if (amount > balance) {

        printf("\nInsufficient funds!\n");
        printf("Your balance is N$%.2f\n", balance);

    } else {

        balance -= amount;

        printf("\nWithdrawal successful!\n");
        printf("Withdrawn amount: N$%.2f\n", amount);
        printf("Remaining balance: N$%.2f\n", balance);
    }

    return balance;
}


// ====================================
// FUNCTION 4: CHANGE PIN
// ====================================

int changePin(int currentPin) {

    int oldPin;
    int newPin;
    int confirmPin;

    printf("\n====================================\n");
    printf("              CHANGE PIN            \n");
    printf("====================================\n");

    printf("Enter your current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != currentPin) {

        printf("\nIncorrect current PIN!\n");

        return currentPin;
    }

    printf("Enter your new 4-digit PIN: ");
    scanf("%d", &newPin);

    if (newPin < 1000 || newPin > 9999) {

        printf("\nPIN must contain exactly 4 digits!\n");

        return currentPin;
    }

    printf("Confirm your new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin == confirmPin) {

        printf("\nPIN changed successfully!\n");

        return newPin;

    } else {

        printf("\nPIN confirmation does not match!\n");

        return currentPin;
    }
}
